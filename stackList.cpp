/*
 * stackList.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: Patrick
 */
#include "stackList.h"

DelimiterStack::~DelimiterStack(){
	delimiterNode *nodePtr;
	delimiterNode *nextNode;

	nodePtr = top;							//pointing at the start of the list
	while(nodePtr != nullptr){
		nextNode = nodePtr->next;			//pointing at the next node for reference
		delete nodePtr;						//deleting the current node
		nodePtr = nextNode;					//moving current node to the next
	}
}

void DelimiterStack::push(char input, int lineNum, int charNum){
	delimiterNode *newNode = nullptr;
	newNode = new delimiterNode;
	newNode->character = input;
	newNode->lineNumber = lineNum;
	newNode->charCount = charNum;

	if(!top){												//if the stack is empty push the node down from the top
		top = newNode;
		newNode->next = nullptr;
	}
	else{														//inserting node to be the top node
		newNode->next = top;
		top = newNode;
	}

	testOutput();
}

void DelimiterStack::popDelimiter(char &input, int &lineNum, int &charNum){
	delimiterNode *nodePtr = top;

	if(isEmpty()){
		throw EmptyStack(input, lineNum, charNum);
	}
	else if((input != '}' &&
	    input != ']' &&
	    input != ')')						//the case where we have a stack of left delimiter and no right delimiter
	    && !isEmpty()){

		cout << "left delimiter " << nodePtr->character << " at line " << nodePtr->lineNumber << ", "
			 << " char " << nodePtr->charCount << " had no right delimiter." << endl;
		if(nodePtr != nullptr){
			top = nodePtr->next;
			delete nodePtr;
		}
	}
	else if(nodePtr->character == '{' && input != '}' ){
		throw Mismatch(nodePtr->character, nodePtr->lineNumber, nodePtr->charCount);
	}
	else if(nodePtr->character == '[' && input != ']' ){
		throw Mismatch(nodePtr->character, nodePtr->lineNumber, nodePtr->charCount);
	}
	else if(nodePtr->character == '(' && input != ')' ){
		throw Mismatch(nodePtr->character, nodePtr->lineNumber, nodePtr->charCount);
	}
	else if((nodePtr->character == '(' && input == ')') ||
			(nodePtr->character == '{' && input == '}') ||
			(nodePtr->character == '[' && input == ']')){	//the case where the left delimiter matches the right delimiter
		top = nodePtr->next;
		delete nodePtr;

	}
	testOutput();
}

bool DelimiterStack::isEmpty(){
	if(!top)
		return true;
	else
		return false;
}

void DelimiterStack::deleteStack(){
	delimiterNode *nodePtr;
	nodePtr = top;
	top = nodePtr->next;
	delete nodePtr;
	nodePtr = nullptr;
}

void DelimiterStack::testOutput(){
	//test output
	delimiterNode *nodePtr = top;					//pointing head of the list
	cout << "stack: ";
	cout << "top ";
	while(nodePtr){									//as long as nodePtr is pointing, it will output and traverse
		cout << "->" << nodePtr->character;
		nodePtr = nodePtr->next;
	}
	cout << endl;
}
