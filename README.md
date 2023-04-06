Programming Assignment #3 for CSCI 423
Robert McCurdy
Spring 2023

This program will take in a series of numbers during the command line call and return the average of those numbers, the minimum number, and the maximum number. To
accomplish this, we run each of these in different threads. After intaking the numbers from the command lines, we will calculate the average, minimum, and the maxmimum
each in their own thread calling their own functions. The threads will then wait on each other and join, and then produce the results. The function used to calculate
the average basically sums all of the numbers together and divides by the size of the array (we got this from earlier in the program while we were allocating memory for
the array). The functions for both min and max are similar in that they iterate through the array and check to see if the value is more than (for max) or less than (for
min) than the assigned value which will always be array[0] at the start.

To run this program please do the following:  

In the terminal run this code to compile the c program :  

gcc PA3.c -lpthread

^ you can add -o [insertname] if you'd like to name the program.

Then once it's compiled, run this command: 

./a.out 90 85 90 100 35 25 

It can be any set of numbers. After this is ran, the program will produce the results.
