/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			3-2-22
* Description:	Program for defining instruction class.
*/

#include "instruction.h"

//initializes each string as parsed instruction pieces
Instruction::Instruction(string Op, string Arg1, string Arg2, string Val){
	op = Op;
	arg1 = Arg1;
	arg2 = Arg2;
	Val = val;
//	check = Check;
}

//setters
void Instruction::SetOp(string Op){
	op = Op;
}

void Instruction::SetArg1(string Arg1){
	arg1 = Arg1;
}

void Instruction::SetArg2(string Arg2){
	arg2 = Arg2;
}

void Instruction::SetVal(string Val){
	val = Val;
}

/*
void Instruction::SetCheck(string Check){
	check = Check;
}*/

//getters
string Instruction::GetOp(){
	return op;
}

string Instruction::GetArg1(){
	return arg1;
}

string Instruction::GetArg2(){
	return arg2;
}

string Instruction::GetVal(){
	return val;
}

/*
string Instruction::GetCheck(){
	return check;
}*/

