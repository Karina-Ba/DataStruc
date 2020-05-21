//***********************************************************************************//
// Karina Batmanishvili - 321800898.                                                 //
// Ronel David Gekhman  - 313564510.                                                 //
// This project takes an input of n numbers and gives various solutions to the       //
// problem, finding the k'th item while also counting the number of comparisons made //
// in the progress of each functions.                                                //
//                                                                                   //
// Input starts with n being the amount of items to be input, followed by items from //
// type "Person", first input is a number representing id, second input is the name  //
// and last input is k being the k'th item you want to find.                         // 
// Output is all the functions after they found the result for k'th item, followed   //
// by amount of comparisons each function did.                                       //
//***********************************************************************************//
#include "PrintSmallerThanKElements.h"

int main()
{
	int n; //Number of items
	//Person* res;

	cin >> n;

	PrintSmallerThanKElements print(n);
	print.readUserInput();
	
	print.NaivePrint(); // Naive (Try each element) algorithm
	//cout << endl << *res << endl;
	//cout << "Naive print: " << print.getNumComparisons() << " comparisons" << endl;

	print.BSTPrint(); // Binary search tree algorithm
	//cout << endl << *res << endl;
	//cout << "Binary search tree: " << print.getNumComparisons() << " comparisons" << endl;

	print.PrintBySort(); // BST algorithm
	//cout << endl << *res << endl;
	//cout << "Quick-sort: " << print.getNumComparisons() << " comparisons" << endl;
}