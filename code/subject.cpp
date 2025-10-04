/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			3-2-22
* Description:	Program for defining subject class.
*/

#include "subject.h"

//initializes subject with parameter string and value at 0
Subject::Subject(string n){
	name = n;
	value = "0";
}

//setters
void Subject::SetName(string n){
	name = n;
}

void Subject::SetValue(string x){
	value = x;
}

//getters
string Subject::GetName(){
	return name;
}

string Subject::GetValue(){
	return value;
}

