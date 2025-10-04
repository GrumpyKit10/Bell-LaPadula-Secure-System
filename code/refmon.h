/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			3-2-22
* Description:	Header file for declaring reference monitor class.
*/

//#include <tuple>
#include <vector>//		vectors
#include <fstream>//	file input
#include <sstream>//	stream string
#include <iomanip>//	output manipulation
#include <ctype.h>//	isalpha()
#include <iostream>//	cin/cout
#include "subject.h"//	subject header
#include "object.h"//	object header
#include "instruction.h"//	instruction header
using namespace std;

//tuple <Subject, string> secureSub;
//tuple <Object, string> secureObj;

#ifndef REFMON_H
#define REFMON_H

class Refmon{
	public:
			//constructor
			Refmon(string, vector<Instruction*>&);
			
			//add subject
			void addsub(string, string);
			//add object
			void addobj(string, string);
			
			//display status
			void status();
			
			//Access Control Decision Function
			int CheckAccess(string, string, int);
			
			//read from object
			int read(string, string);
			//write to object
			int write(string, string, string);
			
			//display final status
			void finalstatus();
			
		//	int execute();
			
	private:	
			//vector of Subject pointers
			vector<Subject*> subjects;
			//vector of Object pointers
			vector<Object*> objects;
			
			//vector of corresponding Subjects' securities
			vector<string> subSec;
			//vector of corresponding Objects' securities
			vector<string> objSec;
			
		//	vector<Instruction*> instList;
};

#endif