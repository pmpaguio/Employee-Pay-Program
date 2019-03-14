#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "person.cpp"
using namespace std;

void readData(Person empArr[20], int &arrSize)
{
	ifstream theFile;
	theFile.open("input.txt");
	string inLine;

	int N = 0;
	string fName, lName;
	float pRate, wHours;
	while (theFile)
	{
		theFile >> fName >> lName >> wHours >> pRate;
		empArr[N].setFirstName(fName);
		empArr[N].setLastName(lName);
		empArr[N].setPayRate(pRate);
		empArr[N].setHoursWorked(wHours);
		N++;
	}
	arrSize = N-1;
	theFile.close();
}

void writeData (Person empArr[20], int &arrSize)
{
	ofstream theFile;
	theFile.open("output.txt");
	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < arrSize; i++)
	{
		theFile << empArr[i].fullName() << " " << empArr[i].totalPay() << endl;
	}
	theFile.close();
}

int main()
{
	int arrSize = 0;
	Person employees[20];
	readData(employees, arrSize);
	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < arrSize; i++)
	{
		cout << employees[i].getFirstName() << " " << employees[i].getLastName() << " " <<
			employees[i].getPayRate() << " " <<  employees[i].getHoursWorked() << endl;
	}
	writeData(employees, arrSize);

	return 0;
}
