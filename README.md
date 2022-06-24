# Data-Structure-Analysis-Project

**1. What was the problem you were solving in the projects for this course?**

For this project, I had to create a program that would take a text file parse through and retrieve the desired information then store it in my chosen data structure. I then had to sort this information alphanumerically (alphabetically then numerically).

**2. How did you approach the problem? Consider why data structures are important to understand.**

I looked at how this program would be utilized and its primary purposes. Then using that information, I conducted a run time analysis to determine what would be the most efficient data structure to utilize. Given the designs of this program I chose a hash table as my chosen data structure. If a user needs to store or retrieve information this is one of the best data structures to use in terms of efficiency.

**3. How did you overcome any roadblocks you encountered while going through the activities or project?**
I had three major obstacles to this project: 

  1. I have never created a hash table from scratch before
  2. I had never done alphanumeric sort of a set of data before
  3. I had little experience using C++ language. 

While I have created other more basic data structures such as Linked Lists and arrays before, this was my first hash table I created from scratch. While I understand the theoretical structure and workings of a hash table, it is difficult to implement without prior experience. I spent much of my time building it from scratch and looking at sites such as GeeksForGeeks to get an idea of how to implement it from scratch. There were several tweaks and alterations made before it became a decent hash table. It isn't efficient or optimal but it works for the situation.

Before this project, I had never heard of alphanumeric sorting before. Basically you sort entries alphabetically then numerically. So if you have three entries MATH201, ECONN209 and ECONN198, the alphanumeric order of this set would be {ECONN198, ECONN209, MATH201}. While this process is easy for us humans, it can be tricky to properly implement with a computer, especially for large data sets. To solve this, I looked for patterns in the data and broke the entries into two sections: One for the letters and one for the numbers. So ECONN198 became ECONN   198. I had the program look throughout the file and compare each of the entries first by letters then by numbers. Letters lower in the alphabet would be placed first and entries with highter letters would be added later. If two entries had the same letters I would then compare their numbers to determine what order to use.  Ex: ECONN209 and ECONN198  both have the same letters but 198 comes before 209 so that would come first in the sorted list.

My primary coding languages before this project were Java, C# and Python. I had very little experience with C++ before this project. I quickly found out that the way I would have solved this problem in C#/Java is very different than how I solved it in C++. With C++ there are many more factors to consider such as if memory is being properly utilized in the program. With C# and Java you don't need to worry about this as the language will take care of memory allocation but this isn't the case with C++. I encountered errors I never would have generated using C# such as issues with memory or having invalid pointers. It took some getting used to and I had to look through many different sites for documentation on how to fix these issus. Google was tremendously helpful with this.

**4. How has your work on this project expanded your approach to designing software and developing programs?**
Much of this has taught me that even if you have a sound design and plan, you will run into many issues when putting these ideas into practice. Ideas I originally had for designing this program in the planning phase did not work as expected when building out the program. I had to scratch those ideas and find other alternative methods. I believe my future planning stages need to be more generalized and less specific. I also need to adapt more to that mindset of accepting that unexpected issues will crop up rather than assuming it will go as planned.

**5. How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**
When writing programs, I generally try to follow establish principles like DRY, maintain separation of concerns and have helpful names/comments. Unfortunately due to the issues I mentioned in 3, these principles were not always followed. This is not just something that only applies to me, many other developers experience these same issues. Getting a better understanding of C++ before starting this project would have helped tremendously in the development process. It would lead to better design ideas and fewer production delays.
