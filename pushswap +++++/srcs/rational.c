#include "../head.h"


/*VALIDATION- RR head becomes tail. A & B
	//-if b is max and a is min ...
	//-or? if a is < mean and b is > mean
			
	-SS swap a n b (first two elements)
	//-if a (1st is greater than 2nd)
	//-if b (1st is less than 2nd)

*/


/*
My RATIONAL.
if less than 3, do simple math
if less that 5, do thninking simple math
if greater that 5...
	-loop to find mean
		-less than the mean put at tail
		-if greater than mean put to b
			-check also for ll_r (rotate to head and push to b)
	-every loopMean will do until all numbers are at B, 
		-then check again for size and repeat

stackB- rational
	check to see what we can do while we are sorting
	GOAL. to put ¿smallest/bigger? number at tail (look at r & rr at the same time)
*/

/*OPERATIONS TO DO
if swap on A is true, check that swap B can happen
	-check that head ¿>? that next if so. call 

if same same... but first get the algorithm to do normal then implement it....


*/

	// int tZ[] =	{-5,2,1,10,101,200,300,400, 9, 12,
	// 	95, 92, 34, 36, 38, 22, 29, -23, -20, -50};
	// int tC[] =	{-5,2,1,10,101,-4,300,400, 9, 12, 2209, 18, -18, 99,
	// 	95, 92, 34, 36, 38, 22, 2345, 567, 3525, 66, 62, -7, 29, -23, -20, -50, 31, 2089, 208, -1, 10000, -14, 11, 55, 58, 91, 999};
	// int tA[] =	{9, 6, 2, 5, 4, 8, 3, 11};
	// int tD[] =	{5, 2, 19, 12};
	// int tB[] =	{29,2,5,0,19,1,-8,9};
