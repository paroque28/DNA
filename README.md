# Instituto Tecnologico de Costa Rica

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

# References:

* Needleman Wunsch Algorithm in C#. (n.d.). Retrieved August 1, 2015, from http://www.codeproject.com/Tips/638377/Needleman-Wunsch-Algorithm-in-Csharp 
* Coghlan, Dr Avril. "The Needleman Wunsch Algorithm." Sanger Institute, 1 Aug. 2013. Web. 1 Aug. 2015. <http://www.slideshare.net/avrilcoghlan/the-needleman-wunsch-algorithm>.
* Roy, Darbeshwar. Bioinformatics. Oxford, U.K.: Alpha Science International, 2009. Print. 


