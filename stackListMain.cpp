/*
 * main.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: Patrick
 */

#include "stackList.h"

int main(){
	int lineNum = 0;
	int charNum = 0;
	string input = "";
	int stringIndex = 0;
	DelimiterStack stack;

	cout << "Type 'DONE' to quit." << endl;
	do{
		charNum = 0;
		stringIndex = 0;
		getline(cin, input);
		lineNum++;
		charNum = input.length();
		for(int i = 0; i <= charNum; i++){
			++stringIndex;
			if(input[i] == '{' || input[i] == '[' || input[i] == '('){
				stack.push(input[i], lineNum, stringIndex);
			}
			else if((input[i] == '}' || input[i] == ']' || input[i] == ')')){

				 try{
				    stack.popDelimiter(input[i], lineNum, stringIndex);
				  }
				  catch(DelimiterStack::Mismatch &mismatch){										//for mismatch errors
				    cout << "Mismatched delimiter " << mismatch.getCharacter() << " found at line " << mismatch.getLineNumber()
				    << " char " << mismatch.getCharCount() << " does not match " << input[i] << " at line " << lineNum
				    << " char " << stringIndex << endl;
				  }
				  catch(DelimiterStack::EmptyStack &emptyStack){
					  cout << "Right delimiter " << emptyStack.getCharacter() << " had no left delimiter found at line "
					  	   << emptyStack.getLineNumber() << " character " << emptyStack.getCharCount() << endl;
				  }
			}

		}

	}while(input != "DONE");


	while(!stack.isEmpty()){
		input = ' ';
		stack.popDelimiter(input[0], lineNum, stringIndex);
	}


	return 0;
}
