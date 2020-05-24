//***********************************************************************************//
// Karina Batmanishvili - 321800898.                                                 //
// Ronel David Gekhman  - 313564510.                                                 //
// This project takes an input of n numbers and gives various solutions to the       //
// problem, finding the k'th item while also counting the number of comparisons made //
// in the progress of each functions.                                                //
//                                                                                   //
// Input starts with n being the amount of items to be input, followed by items from //
// type "Person", first input is a number representing id, second input is the name  //
// and last input is k, whom you want to print all smaller items from.               // 
// Output is all the functions after they found the result for smaller than k items, //
// followed by amount of comparisons each function did.                              //
//***********************************************************************************//
#include "PrintSmallerThanKElements.h"

int main()
{
	int n; //Number of items

	cin >> n;

	PrintSmallerThanKElements print(n);
	print.readUserInput();
	srand((unsigned)time(NULL));

	print.NaivePrint();  // Naive (Try each element) algorithm
	print.BSTPrint();    // Binary search tree algorithm
	print.PrintBySort(); // BST algorithm

}