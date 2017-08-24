
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//prototype functions
int distanceToClosest(int [], const int, int);

int main()
{

const int SIZE = 5;										//size of the array
int numbers[SIZE] = {200, 400, 600, 800, 1000};			//the correct numbers
int input = 0;											//user input
int closestNum = 0;
int distanceValue = 0;
int distanceNew = 0;
bool found = 0;											//the flag variable

	do
	{
		cout << "Pick a number (1-1000): ";
		cin >> input;

		if (input < 1 || input > 1000)
			cout << "invalid number. input = "<< input << endl;
		else
			found = 1;
	} while (found != 1);
	
	if (input == numbers[0] || input == numbers[1] ||						//if input equals to any of the numbers in the array.
		input == numbers[2] || input == numbers[3] ||
		input == numbers[4])
	{
		cout << "correct!" << endl;
	}
	else																	//guessing game happens if the guess isn't correct
	{
		closestNum = distanceToClosest(numbers, SIZE, input);				//finds the closest number for input
		cout << "closestNum: " << closestNum << endl;						//test statement for closestNum
		distanceValue = (closestNum - input);								//gives user a hint to go big or small
		if (distanceValue > 0)
			cout << "try a bigger number." << endl;
		else
			cout << "try a smaller number." << endl;
		distanceValue = abs(closestNum - input);
		found = 0;
		
		do
		{
			cout << "pick a number (1-1000): ";
			cin >> input;
			distanceNew = abs(closestNum - input);
			
			if (input < 1 || input > 1000)
			{
				cout << "invalid number. input = "<< input << endl;
			}
			else if (distanceNew == 0)
			{
				cout << "correct!" << endl;
				found = 1;
			}
			else if (distanceValue == distanceNew)
			{
				cout << "lukewarm right now..." << endl;
			}
			else if (distanceValue > distanceNew)
			{
				cout << "getting warmer..." << endl;
				distanceValue = distanceNew;
			}
			else
			{
				cout << "getting colder..." << endl;
				distanceValue = distanceNew;
			}
		} while (found != 1);
	}
	
return 0;

}

int distanceToClosest(int solutions [], const int SIZE, int guess)			//this will find the closest number
{
	int closestNumber = solutions[0];
	int differenceA = abs(solutions[0] - guess);							//initializing with default compare value
	int differenceB = 0;
		for(int i = 0; i < SIZE; i++)
		{
			differenceB = abs(solutions[i] - guess);
			if(differenceB < differenceA)									//if anytime the new value is less, that number will be the closest
			{
				differenceA = differenceB;
				closestNumber = solutions[i];
			}
		}
	return closestNumber;
}
