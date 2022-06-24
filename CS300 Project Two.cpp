// CS300 Project Two.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <list>
#include <vector>
#include <cstring>
#include <cstdlib>
#include<algorithm>



using namespace std;

unsigned int tableSize = 0;


class Course 
{ 

public:
	string courseNumber;
	string courseName;
	vector<string> preRequisites;

	public:
	Course() {}

	string getCourseNumber(){ return courseNumber; }
	string getCourseName() { return courseName; }

};

list<Course> alphaSort;


int getTableSize(list<Course> listofCourses)
{
	return listofCourses.size();

}



int getHashKey(string courseNumber) 
{	
	int key = 0;
	for(int i = 0; i < courseNumber.size(); i++) 
	{
		key += courseNumber[i]; // Generates hash key for hashing purposes.
	
	}

	return key;

}

void getSortedList(list<Course> sortedList) 
{
	cout << "Here is a sample schedule:" << "\n" << "\n";

	for (auto it = sortedList.begin(); it != sortedList.end(); ++it)
	{
		cout << it->courseNumber << "," << " " << it->courseName << "\n";
		
	}

	cout << "\n";

}

class HashTable
{
	list<Course>* courses;

	int total_elements;

public:
	HashTable(int tableSize);

	void insertItem(int key, Course course);

	void deleteItem(int key);

	void searchTable(string courseNumber);

	int hashFunction(int key)
	{
		return(key % total_elements);
	}

	void displayHashTable();

	int getHashSize();

	HashTable() {}

};

HashTable::HashTable(int tableSize) 
{ 
	total_elements = tableSize;

	courses = new list<Course>[total_elements];

}

void HashTable::insertItem(int key, Course course) 
{
	int index = hashFunction(key);
	courses[index].push_back(course);

}

int  HashTable::getHashSize() 
{
	return total_elements; // returns size of hash 
}

void HashTable::displayHashTable() 
{
	for(int i =0; i < total_elements; i++) // Loops through hash table elements and displays values with their hierarchies.
	{
		cout << i << endl;

		for(auto x: courses[i]) 
		{
			cout << "-->" << x.courseName << " " << x.courseNumber << " " << x.preRequisites.size() << endl;
		}
	}

}

void HashTable::searchTable(string courseNumberInput) 
{
	transform(courseNumberInput.begin(), courseNumberInput.end(), courseNumberInput.begin(), ::toupper); // converts user input to uppercase string

	int lookupKey = getHashKey(courseNumberInput); // Take course number input and convert to integer value for hashing

	int hashKey = hashFunction(lookupKey); // Plug in key value to get hash value

	bool courseFound = false; 

	for(auto i = courses[hashKey].begin(); i!= courses[hashKey].end();i++) 
	{
		

		if (i->courseNumber == courseNumberInput) // Loop through entire hash table, if the course is found generate this response, otherwise generate course not found message and return to caller.
		{
			cout << "\n" << "Course found" << "\n" << "\n";
			cout << "Course Number:" << " " << i->courseNumber << endl;
			cout << "Course Name:" << " " << i->courseName << endl;
			if (i->preRequisites.size() > 0)
			{
				cout << "Course Prerequisites:" << " ";

				

				for (unsigned j = 0; j<i->preRequisites.size(); j++)
				{
					cout << i->preRequisites.at(j) << " ";
				} 

				cout << endl;
			}

			cout << "\n";

			courseFound = true;

		}

		 else if (i == courses[hashKey].end() && i->courseNumber == " ")
		 {
			courseFound = false;
		 }

	}

	if (!courseFound) { cout << "Course not found" << "\n"; }

	
}

void naturalSort(list<Course> coursesToSort)
{
	string currentWord, nextWord;  //Used to compare current course name with next course name

	string cwSub, nwSub; // These are the subwords that aren't numbers from the course number

	int cwSubInt, nwSubInt; // These are the number portions of the courses.
		

	bool isSorted = false; // Determines how many times while loop executes while program performs swaps

	while (!isSorted) 
	{
		isSorted = true; // isSorted is initially set to true in this loop. If any swaps need to happen this value changes to false. If the entire list is iterated over and this value remains unchanged, the list must be sorted to break out of loop.

	

		for (list<Course>::iterator it1 = coursesToSort.begin(), it2 = ++coursesToSort.begin(), it3 = coursesToSort.end(); it2 != coursesToSort.end(); ++it1, ++it2)
		{
			if(it1->courseNumber > it2->courseNumber) // if the current element's course number is greater than the next element's course number a swap must happen so it isn't sorted.
			{
				isSorted = false;
			}

			currentWord = it1->courseNumber;
			cwSub = currentWord.substr(0, 4); // Represents the text portion of the current word
			cwSubInt = stoi(currentWord.substr(4, currentWord.length() - 1)); // Represents the numbered section of the current word
			nextWord = it2->courseNumber;
			nwSub = nextWord.substr(0, 4); // Represents text portion of next word
			nwSubInt = stoi(nextWord.substr(4, nextWord.length() - 1)); // Represents numbers portion of next word


			if(cwSub > nwSub)  // If current word is greater than next word, swap the two
			{
				{ swap(*it1, *it2); }
			}

			if (cwSub == nwSub) // If both words are the same, compare number values. If current number is greater than next number, swap the two.
			{

				if (cwSubInt > nwSubInt) { swap(*it1, *it2); }

			}

	
			alphaSort = coursesToSort; // Assign the values from sorted list to new list that can be read alphanumerically.

		}
	}

} 

HashTable loadDataFile(string fileName)
{ 
	
	ifstream fileReader; // used to read data from the file 

	fileReader.open(fileName, ios::in); // opens file to read

	string linePlaceholder; // used to store the contents of the file line by line
	char separator = ',';

	list<Course> listOfCourses;
	
	if (fileReader.eof()) { cout << "FILE IS EMPTY"; } // if text file is empty display this message

	if (fileReader.is_open()) // if the file reader is reading the text document, scan it line by line
	{


		while(std::getline(fileReader,linePlaceholder))
		{	
			Course courseToAdd;
			stringstream s_stream(linePlaceholder); // Used to further subdivide the line of text into Course object attributes

			while (s_stream.good()) 
			{
				string substring;
				getline(s_stream, substring, ','); // If the current Course object course Number is empty, assign current substring value to it. Else if current course object course name is empty, assign current substring value to it. If those have values but preRequisites is empty and end of line hasn't been reached, add those values to course preRequisites attribute.
				if (courseToAdd.courseNumber == "") { courseToAdd.courseNumber = substring; }
				else if (courseToAdd.courseName == "") { courseToAdd.courseName = substring; }

				else { courseToAdd.preRequisites.push_back(substring); }

				
			}


			listOfCourses.push_back(courseToAdd);
			cout << "\n";

			if (fileReader.eof()) { cout << "\n" <<"Courses have been added" << "\n" << "End of file reached." << "\n"; fileReader.close(); }

		}


	}

	naturalSort(listOfCourses);

	HashTable courseList(listOfCourses.size() * 2); // Sets number of hash table buckets to twice the size of the list


	for(auto it = listOfCourses.begin(); it!= listOfCourses.end(); ++it)
	{
		courseList.insertItem(getHashKey(it->courseNumber), *it);
	}



	courseList.displayHashTable();



	return courseList;

}



void displayMenu()
{
	char userSelection = '-1';

	HashTable courseList;


	string searchValue;

	string dataFile;

	while (userSelection != 4) 
	
	{

	cout << "Please enter a selection:" << endl;
	"\n";
	cout << "1. Load data file" << endl;
	cout << "2. Print Course List" << endl;
	cout << "3. Print Course" << endl;
	cout << "4. Exit Program" << endl;

	cin >> userSelection; // Generates ASCII value of input
	int userChoice = userSelection - '0'; // Takes ASCII input and subtracts that from the ASCII value of 0. This results in a numerical value that can be passed into the switch statement.
		switch (userChoice) 
	
			{
		case 1:
			dataFile = "CS300ProjectOneFile.csv";
			courseList = loadDataFile(dataFile);
			break;

		case 2:
			getSortedList(alphaSort);
			break;

		case 3:
			cout << "Please enter a course number to search for" << endl;
			cin >> searchValue;

			courseList.searchTable(searchValue);

			break;

		case 4:
			cout << "\n";
			cout << "Thank you for using the course planner!";
			cout << "\n";
			exit(0);

			}

    }

}

int main()
{
	displayMenu();
}


