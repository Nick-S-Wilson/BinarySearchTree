//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "BinarySearchTree.h"  // ADT binary tree operations
#include <memory>
#include <iostream>
#include <string>
#include <fstream>
//#include <ctime>
//#include <cstdio>

using namespace std;

void display(std::string& anItem)
{
	std::cout << "Displaying item - " << anItem << std::endl;
}  // end display

void check(bool success)
{
	if (success)
		std::cout << "Done." << std::endl;
	else
		std::cout << " Entry not in tree." << std::endl;
}  // end check

int main()
{

	//clock_t start;
	//double diff;
	//start = clock();


	std::unique_ptr<BinarySearchTree<std::string>> RatTree = std::make_unique<BinarySearchTree<std::string>>();

	std::unique_ptr<BinarySearchTree<std::string>> RatTree2 = std::make_unique<BinarySearchTree<std::string>>();

	ifstream InData, InData2, InNMR;
	ofstream OutReport;

	int NMRId;
	string NMRRFID;
	string rfidArray[149];
	int r = 0;

	int valid = 0;
	int invalid = 0;

	int valid2 = 0;
	int invalid2 = 0;

	// Open Files
	InNMR.open("G:\NMRIdsCSC326V1.txt"); // rfids
	InData.open("G:\NMRCSC326V1AverageCase.txt"); //avg case data
	InData2.open("G:\NMRCSC326V1WorstCase.txt"); //worst case data
	OutReport.open("G:\NMRreportV1.txt"); // report to write to


	// Read in RFIDs
	while (!InNMR.eof())
	{
		InNMR >> NMRId >> NMRRFID; // reads in rfid
		rfidArray[r] = NMRRFID; //stores rfid inside array
		r++; // increments array
	}

	// // // // // // // // // // //
	//			Avg Case		  //
	// // // // // // // // // // //

	cout << "Checking Valid RFID's, With Avg Case Data" << endl << endl;
	system("pause");

	int comparisonCount = 0;

	// Read Observations
	while (!InData.eof())
	{

		string tempRFID;
		string tempDate;
		string tempTime;
		string tempReader;

		InData >> tempRFID >> tempDate >> tempTime >> tempReader; // Reads in data into the new node

		for (int i = 0; i < 149; i++)
		{
			comparisonCount++;
			if (tempRFID.compare(rfidArray[i]) == 0)
			{
				RatTree->add(tempRFID); //creates the tree for rfids.
				valid++;
				break;
			}
			else
			{
				if (i == 148)
				{
					cout << "invalid RFID: " << tempRFID << endl;
					invalid++;
					break;
				}
			}
		}


	}

	cout << endl << endl << "Displaying Preorder Traversal" << endl << endl;
	system("pause");
	RatTree->preorderTraverse(display);

	cout << endl << endl << "Displaying Inorder Traversal" << endl << endl;
	system("pause");
	RatTree->inorderTraverse(display);

	cout << endl << endl << "Displaying Postorder Traversal" << endl << endl;
	system("pause");
	RatTree->postorderTraverse(display);

	cout << endl << endl << "Average Case Results" << endl << endl;
	cout << "Successes: " << valid << endl;
	cout << "Failures: " << invalid << endl;
	cout << "Total Observations: " << valid + invalid << endl;
	cout << "Rat Tree height: " << RatTree->getHeight() << endl;

	cout << "Number of comparisons made in Rat Tree: " << comparisonCount << endl;

	OutReport << "Average Case Results" << endl << endl;
	OutReport << "Successes: " << valid << endl;
	OutReport << "Failures: " << invalid << endl;
	OutReport << "Total Observations: " << valid + invalid << endl << endl;
	OutReport << "Rat Tree height: " << RatTree->getHeight() << endl;
	OutReport << "Rat Tree is Complete and Balanced, Not Full." << endl << endl << endl << endl;


	// Close Data 1
	InData.close();

	// // // // // // // // // // //
	//			Worst Case		  //
	// // // // // // // // // // //

	cout << "Checking Valid RFID's, With Worst Case Data" << endl << endl;
	system("pause");

	int comparisonCount2 = 0;
	// Read Observations
	while (!InData2.eof())
	{

		string tempRFID;
		string tempDate;
		string tempTime;
		int tempReader;

		InData2 >> tempRFID >> tempDate >> tempTime >> tempReader; // Reads in data into the new node

		for (int i = 0; i < 149; i++)
		{
			comparisonCount2++;
			if (tempRFID.compare(rfidArray[i]) == 0)
			{
				RatTree2->add(tempRFID); //creates the tree for rfids.
				valid2++;
				break;
			}
			else
			{
				if (i == 148)
				{
					cout << "invalid RFID: " << tempRFID << endl;
					invalid2++;
					break;
				}
			}
		}
		

	}


	cout << endl << endl << "Displaying Preorder Traversal" << endl << endl;
	system("pause");
	RatTree2->preorderTraverse(display);

	cout << endl << endl << "Displaying Inorder Traversal" << endl << endl;
	system("pause");
	RatTree2->inorderTraverse(display);

	cout << endl << endl << "Displaying Postorder Traversal" << endl << endl;
	system("pause");
	RatTree2->postorderTraverse(display);

	cout << endl << endl << "Worst Case Results" << endl << endl;
	cout << "Successes: " << valid2 << endl;
	cout << "Failures: " << invalid2 << endl;
	cout << "Total Observations: " << valid2 + invalid2 << endl;
	cout << "Rat Tree 2 height: " << RatTree2->getHeight() << endl;

	cout << "Number of comparisons made in Rat Tree 2: " << comparisonCount2 << endl;

	OutReport << "Worst Case Results" << endl << endl;
	OutReport << "Successes: " << valid2 << endl;
	OutReport << "Failures: " << invalid2 << endl;
	OutReport << "Total Observations: " << valid2 + invalid2 << endl << endl;
	OutReport << "Rat Tree 2 height: " << RatTree2->getHeight() << endl;
	OutReport << "Rat Tree 2 is Empty." << endl << endl << endl << endl;

	cout << "Total number of comparisons made: " << comparisonCount + comparisonCount2 << endl;

	// Close Data2, nmr, and report
	InData2.close();
	InNMR.close();
	OutReport.close();


	//diff = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	//cout << "printf: " << diff << '\n';

	system("pause");

}
	