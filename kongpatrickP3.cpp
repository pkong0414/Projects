/*
 * kongpatrickP3.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Patrick
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Word
{
string english;
string piglatin;
};

Word *wordCount(string sentence, int &size);
Word *plTranslate(Word [], int);
void piglatin(Word [], int);

int main ()
{

string input;
Word *sentenceTranslate = 0;											//This structure will do the english to piglatin operation
int size;

cout << "Please type the sentence you want to see in piglatin." << endl;
getline(cin, input);														//input

sentenceTranslate = wordCount(input, size);		//counting the number of words to allocate to the the number of words.

cout << "size: " << size << endl;

sentenceTranslate = plTranslate(sentenceTranslate, size);
piglatin(sentenceTranslate, size);

delete [] sentenceTranslate;

return 0;
}


///////////////////////////////////////////////////////////////////////
//This function will count the number of words within the sentence*	 //
//then will allocate an array of the struct Word of this size*		 //
//it will then store each of the word in the english field*			 //
//the function will then return this array to the calling function 	 //
//with a return statement along with the size through a reference 	 //
//parameter. This function will make all the words lower case and not//
//have any punctuation marks except the very end period, exclamation //
//or question mark													 //
///////////////////////////////////////////////////////////////////////

Word *wordCount(string sentence, int &size)
{

Word *sPtr = 0;
int strLength = sentence.length();	//this will give me the string length to work with
int wordCounter = 0;				//this will count the number of spaces between words
int spaceCounter = 0;
char space;
int letterCount = 0;
int spacePos = 0;
string temp;

for(int i = 0; i < strLength;i++)
	{
	space = sentence.at(i);
	cout << space << endl;

	if(ispunct(sentence[i]) && i < (strLength-1))					//this takes care of any punct marks until the end character
		{
			cout << "punct detected" << endl;				//this is a test output
			temp = sentence;
			temp.erase(i,1);
			sentence = temp;
			strLength = strLength-1;
		}
	else if(ispunct(sentence[i]) && i == (strLength-1))
		{
			if(sentence[i] != '?' &&
			   sentence[i] != '.' &&
			   sentence[i] != '!')
			   {
			   		cout << "punct detected" << endl;		//this is a test output
			   		temp = sentence;
			   		temp.erase(i,1);
			   		sentence = temp;
			   		strLength = strLength-1;
			   }
		}
	if (isupper(sentence[i]))			//this is where the letters get lower cased
		sentence[i] = tolower(sentence[i]);

	if (sentence[i] == ' ')				//this is where the spaces are counted within sentence
		{
		cout << "space detected" << endl; 					//this is a test output
		wordCounter++;
		spaceCounter++;
		}
	}

	wordCounter++;
	cout << "gets there" << endl;							//this is a test output
	cout << "words counted: " << wordCounter << endl;		//this is a test output
	cout << "spaces counted: " << spaceCounter << endl;		//this is a test output

size = wordCounter;
sPtr = new Word[wordCounter];								//Word is counted and array is allocated

	cout << "memory allocated" << endl;						//this is a test output

for(int i = 0;i <= wordCounter-1; i++)			//this will break sentence into individual words and assign them to english string
	{
		letterCount = 0;
		spacePos = sentence.find(' ', 0);
	for(int c = 0; c < spacePos; c++)
		{
			if(sentence.at(c) != ' ' || sentence.at(c) != '\0')
				letterCount++;
		}
	if(i < wordCounter-1)
	{
		sPtr[i].english.assign(sentence, 0, letterCount);
		sentence.erase(0, (letterCount+ 1));				//erasing the counted letters after recording
	}
	else if(i == wordCounter-1)
		sPtr[i].english.assign(sentence);					//assigning the last word since there's no ' '
	cout << "string#" << i << " " <<sPtr[i].english << endl;	//this is test output
	}

return sPtr;											//returning the array
}


////////////////////////////////////////////////////////
//This function will translate the english to piglatin//
////////////////////////////////////////////////////////

Word *plTranslate(Word englishPig[], int size)
{
string firstCharacter;
string blank;
string lastCharacter;
int strLength;
string vowelWay = "way";
string consonAy = "ay";

cout << "\nTest output:" << endl;
for(int i = 0; i < size; i++)
	cout << englishPig[i].english << endl;					//testing output

for(int i = 0; i < size; i++)
	{
		strLength = englishPig[i].english.length();
		firstCharacter = englishPig[i].english[0];
		lastCharacter = englishPig[i].english[strLength];
		if(firstCharacter == "a" ||
		   firstCharacter == "e" ||
		   firstCharacter == "i" ||
		   firstCharacter == "o" ||
		   firstCharacter == "u")
		{
			if(ispunct(englishPig[i].english[strLength-1]))
				englishPig[i].english.insert((strLength-1),vowelWay);
			else
				englishPig[i].english.append(vowelWay);
			englishPig[i].piglatin = englishPig[i].english;
		}
		else
		{
			blank = "";
			blank.append(englishPig[i].english); 						//this performs the front and end swap op
			blank.erase(0,1);
			blank.insert(0,lastCharacter);
			if(ispunct(blank[strLength-1]))
			{
				blank.insert((strLength-1),consonAy);
				blank.insert((strLength-1),firstCharacter);
				blank.erase(0,1);
			}
			else if(!ispunct(blank[strLength-1]))
				{
					blank.append(firstCharacter);
					blank.append(consonAy);
					blank.erase(0,1);
				}
			englishPig[i].piglatin = blank;
		}
	}

return englishPig;
}

/////////////////////////////////////////////////////
//This function will print the translated piglatin.//
/////////////////////////////////////////////////////

void piglatin(Word words[], int size)
{
cout << "\nPig Latin:" << endl;
for(int i = 0; i < size ; i++)
	{
		cout << words[i].piglatin << " ";
	}
		cout << endl;
}
