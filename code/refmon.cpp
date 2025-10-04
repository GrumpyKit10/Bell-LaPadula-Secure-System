/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			3-2-22
* Description:	Program for defining reference monitor class.
*/

#include "refmon.h"

Refmon::Refmon(string fname, vector<Instruction*>& list){// parameters: file name, instruction list(reference)
	ifstream fin;//file input
	fin.open(fname);//opens file
	
	//Checks if file was opened successfully and gives appropriate error
	if(!fin){
		cout << "Unable to open " << fname << " file. Terminating..." << endl;
		
		exit(0);
	}
	
	//temp strings for instruction parts
	string line, op = " ", arg1 = " ", arg2 = " ", val = " ";
	//whitespace counter
	int wcount;
	
	//loops until end of file is reached
	while(getline(fin, line)){
		//resets variables
		op = " ";
		arg1 = " ";
		arg2 = " ";
	//	check = " ";
		val = " ";
		wcount = 0;
		
		//adds white space at end of line so string stream works properly
		line = line + " ";
		
		//string stream for line
		stringstream ss(line);
		
		//counts white spaces
		for(long unsigned int i = 0; i < line.length(); i++){
			if(line[i] == ' '){
				wcount++;
			}
		}
		
		//switch case for number of whitespaces
		switch (wcount){
			//only one whitespace (status)
			case 1:
				ss >> op;
				
				break;
			//3 whitespaces (read, addsub, addobj)
			case 3:
				ss >> op >> arg1 >> arg2;
				
				break;
			
			//4 whitespaces (write)
			case 4:
				ss >> op >> arg1 >> arg2 >> val;
				
			//	cout << val << "\t";
				
				break;
			
			//Bad Instruction
			default:
				op = line;
		}
		
	//	cout << val << "\t";
		
		//temp Instruction pointer with parsed strings
		Instruction* temp = new Instruction(op, arg1, arg2, val);
		//val not properly set by constructor for some reason so used setter
		temp->SetVal(val);
		
	//	cout << temp->GetVal() << endl;
		
		//push back temp to instruction list
		list.push_back(temp);
	}
	
	fin.close();
}

void Refmon::addsub(string user, string level){//username, security level
	//create temp subject pointer
	Subject *temp = new Subject(user);
	
	//push back subject and security level at same index in each vector
	subjects.push_back(temp);
	subSec.push_back(level);
}

void Refmon::addobj(string name, string level){//username, security level
	//create temp object pointer
	Object *temp = new Object(name);
	
	//push back object and security level at same index in each vector
	objects.push_back(temp);
	objSec.push_back(level);
}

void Refmon::status(){
	//format for current status
	cout << "+--------current state--------+" << endl;
	cout << "|-subject-|--level--|--value--|" << endl;
	
	//format for each subject
	for(unsigned long int i = 0; i < subjects.size(); i++){
		cout << "| " << subjects[i]->GetName() << " |" << right 
		<< setw(8) << subSec[i] << " |" << right << setw(8) 
		<< subjects[i]->GetValue() << " |" << endl;
	}
	
	cout << "|--object-|--level--|--value--|" << endl;
	
	//format for each object
	for(unsigned long int i = 0; i < objects.size(); i++){
		cout << "| " << objects[i]->GetName() << " |" << right 
		<< setw(8) << objSec[i] << " |" << right << setw(8) 
		<< objects[i]->GetValue() << " |" << endl;
	}
	
	cout << "+-----------------------------+" << endl;
}

int Refmon::CheckAccess(string subname, string objname, int mode){//subject name, object name, mode (read/write)
	//security levels
	string sublevel, objlevel;
	
	//get subject level
	for(unsigned long int i = 0; i < subjects.size(); i++){
		if(subname == subjects[i]->GetName()){
			sublevel = subSec[i];
		}
	}
	
	//get object level
	for(unsigned long int i = 0; i < objects.size(); i++){
		if(objname == objects[i]->GetName()){
			objlevel = objSec[i];
		}
	}
	
	//switch for mode
	switch (mode){
		//Read mode (no read up, subjects can only read objects of same or lower level)
		case 0:
			if(objlevel == "LOW" && (sublevel == "HIGH" || sublevel == "MEDIUM" || sublevel == "LOW")){
				return 1;
			}
		
			else if(objlevel == "MEDIUM" && (sublevel == "MEDIUM" || sublevel == "HIGH")){
				return 1;
			}
		
			else if(objlevel == "HIGH" && sublevel == "HIGH")
			{
				return 1;
			}
		
			break;
		
		//Write mode (no write down, subjects can only write to objects of same or higher level)
		case 1:
			if(objlevel == "HIGH" && (sublevel == "HIGH" || sublevel == "MEDIUM" || sublevel == "LOW")){
				return 1;
			}
		
			else if(objlevel == "MEDIUM" && (sublevel == "MEDIUM" || sublevel == "LOW")){
				return 1;
			}
		
			else if(objlevel == "LOW" && sublevel == "LOW")
			{
				return 1;
			}
			
			break;
	}//returns 1 if access granted
	
	return 0;//returns 0 if access denied
}

int Refmon::read(string subname, string objname){//subject name, object name
	//result to return
	int code = 0;
	
	//temp subject pointer
	Subject* temp0;
	//temp object pointer
	Object* temp1;
	
	//checks if subject with matching name exists
	for(unsigned long int i = 0; i < subjects.size(); i++){
		if(subname == subjects[i]->GetName()){
			code = 1;// Bad Instruction
			
			temp0 = subjects[i];
		}
	}
	
	//if subject exists
	if(code == 1){
		//check if object exists
		for(unsigned long int j = 0; j < objects.size(); j++){
			if(objname == objects[j]->GetName()){				
				code = 2; // Access Denied
				
				temp1 = objects[j];
			}
		}
	}
	
	//if subject and object exist and access granted
	if(code == 2 && CheckAccess(subname, objname, 0) == 1){
		
	//	cout << subname << "\t";
		
	//	cout << temp0->GetName();
		
		//set subject value to object value
		temp0->SetValue(temp1->GetValue());
		
		code = 3;// Access Granted
	}
	
	//return result code of read
	return code;
}

int Refmon::write(string subname, string objname, string value){//subject name, object name, value
	int code = 0;// Bad Instruction
	int alphaCount = 0;// counter for letters
	
	//temp object pointer
	Object* temp;
	
	//counts letters in value string
	for(unsigned long int i = 0; i < value.length(); i++){
		if(isalpha(value[i]) != 0){
			alphaCount++;
		}
	}
	
//	cout << alphaCount << endl;
	
	//search for subject
	for(unsigned long int i = 0; i < subjects.size(); i++){
		//if subject with name is found and value isn't blank and has no letters
		if(subname == subjects[i]->GetName() && value != " " && alphaCount == 0){
			code = 1;// Bad Instruction
		}
	}
	
	//if subject found and correct value
	if(code == 1){
		//search for object
		for(unsigned long int j = 0; j < objects.size(); j++){
			//if object with name is found
			if(objname == objects[j]->GetName()){
				code = 2; // Access Denied
				
				temp = objects[j];
			}
		}
	}
	
	//if subject and object are found and correct value and access granted
	if(code == 2 && CheckAccess(subname, objname, 1) == 1){
	//	cout << value << "\t";
		
		//set object value
		temp->SetValue(value);
		
	//	cout << temp->GetValue() << endl;
		
		code = 3;// Access Granted
	}
	
	//return result code for write
	return code;
}

void Refmon::finalstatus(){
	//format for final status
	cout << "+---------final state---------+" << endl;
	cout << "|-subject-|--level--|--value--|" << endl;
	
	//format for each subject
	for(unsigned long int i = 0; i < subjects.size(); i++){
		cout << "| " << subjects[i]->GetName() << " |" << right 
		<< setw(8) << subSec[i] << " |" << right << setw(8) 
		<< subjects[i]->GetValue() << " |" << endl;
	}
	
	cout << "|--object-|--level--|--value--|" << endl;
	
	//format for each object
	for(unsigned long int i = 0; i < objects.size(); i++){
		cout << "| " << objects[i]->GetName() << " |" << right 
		<< setw(8) << objSec[i] << " |" << right << setw(8) 
		<< objects[i]->GetValue() << " |" << endl;
	}
	
	cout << "+-----------------------------+" << endl;
}

