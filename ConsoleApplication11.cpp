

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

long fibonacci(long a)
{
	if (a > 1)
		return (2*(a)+(a-1)*2);
	else return(1);
}

int main()
{
	long number;
	long number2;

	string line;
	string line2;

	ifstream myfile("Fibonacci.txt");
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			getline(myfile, line2);

			cout << line << endl;
			cout << line2 << endl;

			stringstream geek (line);
			stringstream geek2 (line2);

			geek >> number;
			geek >> number2;

			cout << "fiobonacci number is: " << fibonacci(number) <<" " <<fibonacci(number2)<<endl;
			system("pause");
		}
		myfile.close();
	}
	else cout << "unable to open file" << endl;
	system("pause");

    return 0;
}

