/* The goal of this is to write a function that will implement each Fibonacci number with the help of an
 * int array of size 100 ( the elements will be used to store the digits in this array )
 * When the function is calld to find Fn, it will calculate all Fibonacci from F(2) to F(N) using fibonacci formula
 * write a program that will calculate Fibonacci numbers containing up to 100 digits
 *
 * Display the largest Fibonacci number that has less than 100 digits. Make sure that your program will display
 * an error message when the total has 100 digits or more.
 */

#include<iostream>
using namespace std;

int main(){
int N = 0, SIZE = 100, digits = 1, index = 0, temp = 0;

//making arrays that will be used and initializing everything in the array to 0
int FN[SIZE] = { 0 }, Fn1[SIZE] = { 0 }, Fn2[SIZE] = { 0 };

Fn1[ SIZE - 1 ] = 1;				//priming the variables.

/*The intention is to add two arrays that correspond to Fn-1 and Fn-2
 * It will convert the the number into array form
 * It will count the digits in the fibonacci number to be implemented.
 *
*/

	//cout << "What Fibonacci sequence number would you like to see: ";
	//cin >> N;

for( int i = 2 ; digits <= 100 ; i++ ){
		/*
		 * This will store numbers in an array form.
		 * It will consist of three forms
		 * Iteratively Fibonacci goes in 3 parts:
		 * FN = Fn1 + Fn2
		 * Fn2 = Fn1
		 * Fn1 = FN
		 * It will break into three parts in order to make the adding digit by digit
		 */
		/*if(digits <= 100){
			//this is if the conditions needs to stop it which should wind the sequence back 1 since
			//it didn't do anything for this run through
			N = i - 1;
			cout << "\nerror: digits about to exceed 100!" << endl;
			cout << "Fibonacci sequence is at: " << N << endl;
			break;
		}*/


		index = SIZE - 1;
		/*cout << "\n\nN: " << i;
		cout << "\nFN: " << FN[index] << " Fn1:" << Fn1[index] << " Fn2: " << Fn2[index];
		cout << "\nFN[index -1]: " << FN[index-1] << " Fn1[index - 1]:" << Fn1[index-1] << " Fn2[index - 1]: " << Fn2[index-1];
		*/
		for( int d = 0; d < digits ; d++ ){
			//this will add the numbers from the current digit.

			//debug output
			//cout << "\ndigit operation: " << d << endl;
			//cout << "\nFn1 + Fn2 = FN : " << Fn1[index-d] << " + " << Fn2[index-d];

			FN[index-d] = Fn1[index-d] + Fn2[index-d] + temp;

			//resetting temp
			temp = 0;

			//debug output of FN and digits
			//cout << " = " << FN[index - d] << endl;
			//cout << "\nDigits: " << digits;

			if( (Fn1[index-d] + Fn2[index-d]) > 9 ){

				//moving up digit counter and adding next digit 1 when the index needs to expand.
				if( d + 1 == digits ){
					digits++;
				}

				//assigning value to temp so it will carry over
				temp = FN[index - d] / 10;

				//This will get rid of any extra digits for FN
				FN[index - d] = FN[index - d] % 10;

				/*
				//debugging output
				cout << " \nFn1[index - 1]: " << Fn1[index - d - 1];
				cout << " FN[index - 1]: " << FN[index - d - 1];
				cout << " Fn2[index - 1]: " << Fn2[index - d - 1];
				 */
			}
		}//end of the adding for loop

		//start of the transfer loop
		for(int d = 0; d < digits; d++){
			//transferring the numbers of Fn1 to Fn2
			Fn2[index - d] = Fn1[index - d];
		}//end of thetransfer loop for Fn1 to Fn2

		for(int d = 0; d < digits; d++){
			//transferring the numbers of FN to Fn1
			Fn1[index - d] = FN[index - d];
		}//end of the transfer loop for FN to Fn1

		if(digits == 99 && (Fn1[SIZE - digits] + Fn2[SIZE - digits]) > 9){
				//this is if the conditions needs to stop it which should wind the sequence back 1 since
				//it didn't do anything for this run through
				N = i;
				cout << "\nerror: digits about to exceed 99!" << endl;
				cout << "Fibonacci sequence is at: " << i << endl;
				break;
			}


		/*//debugging output
		index = SIZE - digits;
		cout << "\n";
		for( int b = index; b < SIZE; b++){
			cout << FN[b];
		}
		cout << " ";*/

}

cout << "\nThe number for the fibonacci sequence of " << N << " is: ";
index = SIZE - digits;
for(int p = index; p < SIZE; p++){
	cout << FN[p];
}
//debugging output
cout << "\ndigits " << digits;


return 0;

}
