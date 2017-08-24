/*
 * kongpatrick2P.cpp
 *
 *  Created on: Sep 17, 2016
 *      Author: Patrick
 */
 
/*
	This program contains 3 sections:

	1. it will create an array of 100 numbers (1-30), print the array, and find the mode of the array.
	2. it will then create array of 100 numbers (1-200), print the array, and find the 2 smallest numbers of the array.
	3. it will expand the last array by 1 slot and will assign values starting from index 1.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void mode (int [], const int);										//this is used to find the mode of the array.
void read_array (int [], const int);								//this is used to initialize the array.
void read_array (int [], const int, int);							//this is used to initialize the array with a max of 200.
void print_array (int [], const int);								//this is used to print the array in rows of 10.
void Two_smallest(int [], const int, int *, int *, int *, int *);	//this is used to find the 2 smallest numbers in the array.
void shiftArray(int [], const int);

int main()
{
const int SIZE = 100;
int array[SIZE];
int userInput = 0;
int maxValue = 200;
int smallestNum1 = 0;
int smallestNum2 = 0;
int index1 = 0;
int index2 = 0;

//The first section
read_array(array, SIZE);
print_array(array, SIZE);
mode(array, SIZE);

//The second section
do
{
	read_array(array, SIZE, maxValue);
	print_array(array, SIZE);
	Two_smallest(array, SIZE, &smallestNum1, &smallestNum2, &index1, &index2);

	cout << "\n\nThe two smallest numbers are: " << endl;
	cout << smallestNum1 << " located on the index: " << index1 << endl;
	cout << smallestNum2 << " located on the index: " << index2 << endl;

	cout << "\nWould you like to continue? (enter -1 to end): ";
	cin >> userInput;
}while(userInput != -1);															//this will loop until -1 is input.

//The third section
cout << "\nDefault Array: " << endl;
print_array(array, SIZE);
cout << "\nNew Array: " << endl;
shiftArray(array, SIZE);

return 0;
}

void mode (int array[], const int size)
{

	int modeValue = 0;
	int counter = 0;							//this is for counting for frequencies
	int highCounter = 0;						//this is to compare frequencies in case there is a tie

	for(int x = 1; x < 31; x++)					//this will look thru the array to search for the mode
	{
		counter = 0;							//this will reset the count.
		cout << endl;							//spacing for ease of reading
		for(int i = 0; i < size; i++)
		{
			if (array[i] == x)
				{
					cout << setw(4)<< x << " ";	//will print the number for every one counted
					counter++;
				}
			if (counter > highCounter)			//we need to establish a high count
			{
				highCounter = counter;
				modeValue = x;
			}
		}
	}
	cout << "\nThe mode: " << modeValue;

	for(int c = 1; c < 31; c++)					//we need to start comparing using the high count for ties
	{
		counter = 0;
		for(int z = 0; z < size; z++)
		{
			if(array[z] == c && c != modeValue)
			{
				counter++;
			}

		}

		if (counter == highCounter)				//this will only print if the current count equates to the high count.
		{
			cout << " " << c;
		}
	}
	cout << "\nFrequency of the modes: " << highCounter << endl;
	cout << "\ndone!" << endl;
}

void read_array(int array[], const int size)
{
//the numbers will random between 1-30 over an element size of 100.

	//using the system time
	unsigned seed = time(0);

	//seeding the number generator
	srand(seed);

	for(int x = 0; x < size; x++)
	{
		//initializing values from 1-30
		array[x] = (rand() % 30)+1;
	}
}

void read_array(int array[], const int size, int newMax)
{
//the numbers will random between 1-30 over an element size of 100.

	//using the system time
	unsigned seed = time(0);

	//seeding the number generator
	srand(seed);

	for(int x = 0; x < size; x++)
	{
		//initializing values from 1-30
		array[x] = (rand() % newMax)+ 1;
	}
}

void print_array(int array[], const int size)
{
	int i = 1;
		cout << endl;
		for(int x = 0; x < size; x++)			//this is for moving across the line
		{
			cout << setw(4) << array[x] << " ";
			if((i % 10) == 0)					//this is for moving down the line after 10 rows
			{
				cout << "\n";
			}
			i++;
		}
}

void Two_smallest(int array[], const int size, int *psmallestNum, int *psmallNum, int *psmallestIndex, int *psmallIndex)
{
	*psmallestNum = array[0];
	*psmallNum = array[0];

	for(int x = 0; x < size; x++)
	{
		if(*psmallestNum > array[x])						//this will detect the smaller numbers
		{
			*psmallNum = *psmallestNum;
			*psmallIndex = *psmallestIndex;
			*psmallestNum = array[x];
			*psmallestIndex = x;
		}

		if(*psmallNum > array[x] && *psmallestIndex != x)	//in case smallestNum was found the smallest number already
		{
			*psmallNum = array[x];
			*psmallIndex = x;
		}
	}

}


void shiftArray(int array[], const int size)
{
	int *pArr;
	const int newSize = 101;
	pArr = new int [newSize];								//allocating memory to pointer Array
	*(pArr) = 0;											//inserting 0 into the default pointer Array value.
	for(int i = 0; i < size; i++)							//this will take default array and assign values to pointer array starting at index 1
	{
		*(pArr+i+1) = array[i];
	}

	print_array(pArr, newSize);

}
