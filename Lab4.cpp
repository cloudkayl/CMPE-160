// ===========================================================
//
// Lab4.cpp  
// Description: <This program takes two inputs from users, Resistance and Current to calculate the voltage and print/display the result>
// Name: <Ayush Rout, >
// Date: <09/21/2017>
// Class: CMPE-110
// Section: <Lab: 3, Thursday, and time here>
//
// ===========================================================



#include "stdafx.h"
#include <iostream>
#define getch(); system("pause");
#define clrscr(); system("cls");
using std::cout;
using std::cin;

//calcVoltage function returns the product of the two arguments
float calcVoltage(float r, float i)
{
	return r*i;                                                       //returns the product
}

//main() function starts here
int main() {
	clrscr();
	float R, I;
	cout << "Enter a value for Current:\n";
	cin >> I;                                             //takes input for current from the user
	cout << "Enter a value for Resistance:\n";
	cin >> R;                                           //takes input for resistance from the user
	cout << "Voltage = " << calcVoltage(R, I) << '\n';    //Displays the voltage calculated from the calcVoltage() function governed by the working formula V=IR (Ohm's law)
	getch();
	return 0;
}
