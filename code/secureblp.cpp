/*
* Name:			Matthew Wilson
* Email:		mlw0420@unt.edu
* Course:		CSCE 3550.001
* Date:			3-3-22
* Description:	Program for that implements a "secure" system using Bell-LaPadula security rules. 
*/

#include "refmon.h"
using namespace std;

int main(int argc, char* argv[]){//command line arguement counter, arguements
	//checks if 2 arguements and displays proper error
	if(argc != 2){
		cout << "usage: secureblp instructionList" << endl;
		
		exit(0);
	}
	
	//vector list of instruction pointers
	vector<Instruction*> InstructionList;
	//Reference monitor takes file name from 2nd command line arguement to populate instruction list
	Refmon ReferenceMonitor(argv[1], InstructionList);
	
	//temp strings
	string Opr, Argu1, Argu2, Value;
	
	//result for read/write
	int result = 0;
	
	//iterates through every instruction in the list
	for(long unsigned int i = 0; i < InstructionList.size(); i++){
		//gets parsed instruction
		Opr = InstructionList[i]->GetOp();
		Argu1 = InstructionList[i]->GetArg1();
		Argu2 = InstructionList[i]->GetArg2();
		Value = InstructionList[i]->GetVal();
			
	//	cout << Opr << " " << Argu1 << " " << Argu2 << " " << Value << endl;
		
		//converts operation to lowercase
		for(long unsigned int j = 0; j < Opr.length(); j++){
			Opr[j] = tolower(Opr[j]);
		}
		
		//if operator is addsub
		if(Opr == "addsub"){
		//	cout << "Yay" << endl;
			//add subject
			ReferenceMonitor.addsub(Argu1, Argu2);
			
			//formatted output
			cout << left << setw(16) << "Subject Added" << ": " << Opr << " " << Argu1 << " " << Argu2 << endl;
		}
		
		//if operator addobj
		else if(Opr == "addobj"){
			//add object
			ReferenceMonitor.addobj(Argu1, Argu2);
			
			//formatted output
			cout << left << setw(16) << "Object Added" << ": " << Opr << " " << Argu1 << " " << Argu2 << endl;
		}
		
		//if operator status
		else if(Opr == "status"){
			//display status
			ReferenceMonitor.status();
		}
		
		//if operator write
		else if(Opr == "write"){
		//	cout << Argu1 << "\t";
			
			//attempt write to object
			result = ReferenceMonitor.write(Argu1, Argu2, Value);
			
			//if result = 0 or 1
			if(result == 0 || result == 1){
				//bad instruction, write fail
				cout << left << setw(16) << "Bad Instruction" << ": " << Opr << " " << Argu1 << " " << Argu2 << " " << Value << endl;
			}
			
			//if result = 2
			else if(result == 2){
				//access denied, write fail
				cout << left << setw(16) << "Access Denied" << ": " << Opr << " " << Argu1 << " " << Argu2 << " " << Value << endl;
			}
			
			//if result = 3
			else if(result == 3){
				//access granted, write successful
				cout << left << setw(16) << "Access Granted" << ": " << Argu1 << " writes value " << Value << " to " << Argu2 << endl;
			}
		}
		
		//if operator read
		else if(Opr == "read"){
			//attempt read from object
			result = ReferenceMonitor.read(Argu1, Argu2);
			
			//if result = 0 or 1
			if(result == 0 || result == 1){
				//bad instruction, read fail
				cout << left << setw(16) << "Bad Instruction" << ": " << Opr << " " << Argu1 << " " << Argu2 << endl;
			}
			
			//if result = 2
			else if(result == 2){
				//access denied, read fail
				cout << left << setw(16) << "Access Denied" << ": " << Opr << " " << Argu1 << " " << Argu2 << endl;
			}
			
			//if result = 3
			else if(result == 3){
				//access granted, read success
				cout << left << setw(16) << "Access Granted" << ": " << Argu1 << " reads " << Argu2 << endl;
			}
		}
		
		//otherwise
		else{
			//bad instruction, instruction fail
			cout << left << setw(16) << "Bad Instruction" << ": " << Opr << " " << Argu1 << " " << Argu2 << " " << Value << endl;
		}
	}
	
	//display final status
	ReferenceMonitor.finalstatus();
	
	//end
	return 0;
}