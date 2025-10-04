/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			3-2-22
* Description:	Header file for declaring object class.
*/

#include <string>
using namespace std;

#ifndef OBJECT_H
#define OBJECT_H

class Object{
	public:
			//constructor
			Object(string);
			
			//setters
			void SetName(string);
			void SetValue(string);
			
			//getters
			string GetName();
			string GetValue();
			
	private:
			//variables
			string name;
			string value;
};

#endif

