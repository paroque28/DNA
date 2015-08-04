# Instituto Tecnológico de Costa Rica

# Students:
- Pablo Rodriguez
- Josafat Vargas

# **Investigation Project: Sequence Alignment**
# Introduction: 
The algorithm of Needleman-Wunsch, used in bioinformatics finds the best alignment of two characters chains. It is implemented in C Programming Language and it consists on doing a matrix of scores. We start at (0,0) with a score of 0 and then we calculate three scores:

* The S(i-1,j-1) + F(char a,char b)
* The S(i-1,j) + gap penalty
* The S(i,j-1) + gap penalty

_Where S is the score of that place and F is the function that describes the similarity of two characters._
With that results you should get the maximum value of the three results and that'll be your socore. Note: You need to save the direction you got the maximum value.

After the matrix is done you should start the **TraceBack** where you start looking at the directions and building the chain resultant.

# **Development**
# Development Environment:

_Clion 1.0.5_

A "powerful IDE helps you develop in C and C++ on Linux, OS X and Windows, enhancing your productivity with a smart editor, code quality assurance, automated refactorings, and deep integration with CMake build system."

_Github_

Is a "Online project hosting using Git. Includes source-code browser, in-line editing, wikis, and ticketing."

_MarkDown_

Markdown is a text-to-HTML conversion tool for web writers. Markdown allows you to write using an easy-to-read, easy-to-write plain text format, then convert it to structurally valid XHTML (or HTML).

_Dillinger_

Is an online cloud based HTML5 filled Markdown Editor. Sync with Dropbox, Github and Google Drive.

# Data Structures and libraries

array int[][]:  C programming language provides a data structure called the array, which can store a fixed-size sequential collection of elements of the same type. An array is used to store a collection of data, but it is often more useful to think of an array as a collection of variables of the same type.

#include <stdio.h>
The standard input and output header defines three variable types, several macros, and various functions for performing input and output.

#include <stdlib.h>
The standard library header defines four variable types, several macros, and various functions for performing general functions. In our case mostly file management.

#include <string.h>
The string header defines one variable type, one macro, and various functions for manipulating arrays of characters.

#include <pwd.h>
The password structure header provides a definition for struct passwd, which helps with finding the initial working directory.

#include <unistd.h>
The standard symbolic constants and types header defines miscellaneous symbolic constants and types, and declares miscellaneous functions.

#include <time.h>
The time types header defines four variable types, two macro and various functions for manipulating date and time.

# Programs

_DNA Sequence Generator_

The program runs a random algorithm implemented with a C library that uses a time seed to generate numbers. The numbers are hen asigne to characters that represent the genes. The characters are then stored in a file.

To create the algorithm we studied the random generation in the random library and the file management and used a for-loop to create the specified amount of genes. The C library function <int rand(void)> returns a pseudo-random number in the range of 0 to a constant whose default value may vary between implementations but it is granted to be at least 32767. For this program we reduced it to 4, which allows us to associate numbers to each of our gens.

Test cases:
* 7, seqa
* 9, seqb
* 1 000 000, million
* 1 000 001, millionandone
* 1 000 100, millionplus
* a; output: An empty .dna file named "a.dna".

Note: Expected result were no error or output noted. Tests made with the terminal interface.

_DNA Sequence Aligner_

The program analyses two strings of characters that represent the gene sequences and aligns them in the best way -the one with more matches- using the Neeldeman-Wunsch algorithm.

Test cases:
* Weird character needlemanWunsch("GCATGCU",7,"GATTACA",7); output: Error: char not recognized : 'U' or corrupted char stream

* One gen in common (same size, same position) needlemanWunsch("GGTGGGGG",8,"AATAAAAA",8);

* One gen in common (same size, different position) needlemanWunsch("GGTGGGGG",8,"AAAAATAA",8);

* One gen in common (odd sizes, same position) needlemanWunsch("GGTGGGGG",8,"AATAAAA",7);

* One gen in common (odd sizes, different position) needlemanWunsch("GGTGGGGG",8,"AAAATAA",7);

* The amount of characters are different from specified needlemanWunsch("GGTGGGGG",8,"AAAATAA",8); output: Error: char not recognized : ' ' or corrupted char stream

* Comparison with empty file needlemanWunsch("",0,"AAAATAA",8); output: No error, empty comparison, ie, zero matches

Note: Expected result were no error or output noted. Tests made directly into the comparison function, since reading the files was succesfull.


_File manager_

In order to load the sequences for the program we use a file. "A file is a collection of bytes stored on a secondary storage device, which is generally a disk of some kind.  A text file can be thought of as a stream of characters that can be processed sequentially." Both the DNA sequence creator and the DNA aligner manage .dna files, this collection of bytes are interpreted as char pointers. This means that the files are stored without extra interpretation by the program. Since underneath characteres are interpreted as integers by C, the file is stored in a very fast way. The only way to speed up this process and save resources is managing the genes as 2-bit types that are interpreted by the program with the help of masks.

The only way to speed up this process and save resources is managing the genes as 2-bit types that are interpreted by the program with the help of masks. This will cause the .dna file to be unreadable for the user with text editors.

# Project's Final Status

# User's Manual

_DNA Sequence Generator_
When executing a problem a terminal window opens an indicates the user to input the length of the gene sequence. After this the program will ask for the name of file where the sequence will be stored. The file's extension is not required since the program automatically adds the ".dna" suffix. The file is then stored in the desktop.

_DNA Sequence Aligner_
The pograms displays a terminal window and asks for the two files that contain the dna sequences to be aligned. Both files must be in the desktop folder. The terminals the runs the algorithm and presents to the user the table that was created from analyzing the sequences together and the best alignment, matches included, of the two sequences.

# Conclusions and Recomendations

* Opening a large .dna file can take a while, changing the implementation to 2-bit code would make smaller but unreadable to text editors.
* Calling the random generation seed at the begining of the problem solves problems that cause the seed to be the same every run.


# References:

* Needleman Wunsch Algorithm in C#. (n.d.). Retrieved August 1, 2015, from http://www.codeproject.com/Tips/638377/Needleman-Wunsch-Algorithm-in-Csharp 
* Coghlan, Dr Avril. "The Needleman Wunsch Algorithm." Sanger Institute, 1 Aug. 2013. Web. 1 Aug. 2015. <http://www.slideshare.net/avrilcoghlan/the-needleman-wunsch-algorithm>.
* Roy, Darbeshwar. Bioinformatics. Oxford, U.K.: Alpha Science International, 2009. Print. 
* Counting unknown numbers of chars from a file in C. (2010, April 20). Retrieved August 2, 2015.
* C library function - rand(). Retrieved August 1, 2015 from <http://www.tutorialspoint.com/c_standard_library/c_function_rand.htm>
* C - Arrays. Retrieved August 4, 2015 from <http://www.tutorialspoint.com/cprogramming/c_arrays.htm>
* M. Campbell "File Management in C". Retrieved August 1, 2015 from 
<http://www.prog2impress.com/downloads/file%20management%20in%20c.pdf>
* J. Gruber "Markdown"Dec 17th, 2004 Retrieved August 3, 2015 from <http://daringfireball.net/projects/markdown/>
* JetBrains main page. Retrieved August 3, 23015 from <https://www.jetbrains.com/clion/>
* Github main page. Retrieved August 3, 2015 from <https://github.com/>
