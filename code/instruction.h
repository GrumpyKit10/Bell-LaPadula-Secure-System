/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			3-2-22
* Description:	Header file for declaring instruction class.
*/

#include <string>
using namespace std;

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class Instruction{
	public:
			//constructor
			Instruction(string, string, string, string);
			
			//setters
			void SetOp(string);
			void SetArg1(string);
			void SetArg2(string);
			void SetVal(string);
		//	void SetCheck(string);
			
			//getters
			string GetOp();
			string GetArg1();
			string GetArg2();
			string GetVal();
		//	string GetCheck();
	
	private:
			//variables
			string op, arg1, arg2, val;
		//	int val;
			
};

#endif

