/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			3-2-22
* Description:	Program for defining object class.
*/

#include "object.h"

//initializes subject with parameter string and value at 0
Object::Object(string n){
	name = n;
	value = "0";
}

//setters
void Object::SetName(string n){
	name = n;
}

void Object::SetValue(string x){
	value = x;
}

//getters
string Object::GetName(){
	return name;
}

string Object::GetValue(){
	return value;
}

