// RemoveDuplicatesFromSortedArray.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{

	ifstream inputFile;
	int data;
	int number;
	inputFile.open("SortedArray.txt");

	if (!inputFile) {
		cout << "Unable to Open the File";
		/*exit(1);*/
	}
	else {

		// Read the numbers from the file and 
		// display them. 
		int arrFinal[20];
		int val;
		int x;
		cout << "A = [";
		val = 99999999999999999;
		x = 0;
		while (inputFile >> data)
		{
			
			//cout << data << endl;
			
			if (x == 0) {
				val = data;
				x++;
				arrFinal[x] = data;
				cout << arrFinal[x] << ", ";

			}else{
				
				if (val != data) {
					x++;
					val = data;
					arrFinal[x] = data;
					cout << arrFinal[x] << ", ";
				}
			}
		}
		cout << "]";
		cout << endl << "Length: " << x << "\n";
	}


	inputFile.close();

	system("Pause");
	return 0;

}
