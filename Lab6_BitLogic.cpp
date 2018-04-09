// ===========================================================
//
// Lab6_BitLogic.cpp  
// Description: Bit Logic
// Name: <team member names here>
// Date: <today's date here>
// Class: CMPE-110
// Section: <Lab: section, day, and time here>
//
// ===========================================================

#include "stdio.h"

int main() {
	unsigned char A=0x33;
	unsigned char B=0x4F;
	unsigned char result;

	//Initial value A, B
	printf("A= 0x%X, B= 0x%X \n", A, B);

	// calculate ~A and then print it
	result = ~A;
	printf("~A= 0x%X,\n", result);

	//continue with the rest of the equations in the exercise
	//(i.e. calculate result and print it, for A&B, then A|B, etc.

	return 0;
}
