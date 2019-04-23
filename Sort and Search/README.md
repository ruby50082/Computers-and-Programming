# Sort and Search
1. At the first of the program, the user is asked if the user wants to generate a set of random integers or read a set of integers from a file.
2. (1) If the user wants to generate a set of random integers, ask the user how many integers the user wants to generate and then enter a loop to generate all random numbers one by one.
       You can set the upper bound of each random integer as 10000 for your convenient use of ‘%’ operator.
   (2) If the user wants to read integers from a file, ask the user to input the file name and then read all integers from the input file. The file format is as follows. 
       The first line is the total number of integers in this file. After this each integer is printed in one line.
3. After reading integers, perform bubble sorting to sort all integers in increasing order.   
4. Finally enter a while‐and‐switch structure to as the user which item the user wants to select: 
    (i) to print integers in increasing order in a file named as “IncSort”; 
    (d) to print integers in decreasing order in a file named as “DecSort”; 
    (q) to quit the program. 
    If the user selects the other choice, the program echoes the command choice and asks the user to input again.     
5. When the sorting is done, it is well prepared to work on the binary search. The user inputs a number and then the program identifies the array location of the number. If the number is not in the array, prompt a message. If the number is in the array, tell the user the array index of the number.
