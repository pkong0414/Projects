/*
 * stackList.h
 *
 *  Created on: Mar 22, 2018
 *      Author: Patrick
 */

#ifndef STACKLIST_H_
#define STACKLIST_H_

#include<iostream>
using namespace std;

class DelimiterStack{
private:
	struct delimiterNode{
		char character;
		int lineNumber;
		int charCount;
		struct delimiterNode *next; 				//pointer to the next node
	};

public:
	delimiterNode *top;								//top of the stack

	//exception classes
	class EmptyStack{
	  private:
	    char character;
	    int lineNumber;
	    int charCount;
	  public:
	    EmptyStack(char input, int lineNum, int charIndex){
	    	character = input;
	    	lineNumber = lineNum;
	    	charCount = charIndex;
	    }
	    char getCharacter() const{
	    	return character;
	    }
	    int getLineNumber() const{
	    	return lineNumber;
	    }
	    int getCharCount() const{
	    	return charCount;
	    }
	 };

	class Mismatch{
	  private:
		char character;
		int lineNumber;
		int charCount;
	  public:
		Mismatch(char input, int lineNum, int charIndex){
			character = input;
			lineNumber = lineNum;
			charCount = charIndex;
		}
		char getCharacter() const{
			return character;
		}
		int getLineNumber() const{
			return lineNumber;
		}
		int getCharCount() const{
			return charCount;
		}
	 };


	DelimiterStack()								//constructor
	{ top = nullptr; }

	~DelimiterStack();
	void push(char, int, int);
	void popDelimiter(char &, int &, int &);
	bool isEmpty();
	void deleteStack();
	void testOutput();
};



#endif /* STACKLIST_H_ */
