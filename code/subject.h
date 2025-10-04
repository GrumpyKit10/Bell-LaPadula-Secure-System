/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			3-2-22
* Description:	Header file for declaring subject class.
*/

#include <string>
using namespace std;

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject{
	public:
			//constructor
			Subject(string);
			
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

