#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <vector>
#include "person.cpp"
using namespace std;

void readData(vector<Person> &empVect)
{
	ifstream theFile;
	theFile.open("input.txt");
	string inLine;

	string fName, lName;
	float pRate, wHours;
	while (theFile)
	{
		theFile >> fName >> lName >> wHours >> pRate;
		if (!theFile)
			break;
		empVect.emplace_back(fName, lName, pRate, wHours);
	}
	theFile.close();
}

void writeData (vector<Person> &empVect)
{
	ofstream theFile;
	theFile.open("output.txt");
	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < empVect.size(); i++)
	{
		theFile << empVect.at(i).fullName() << " " << empVect.at(i).totalPay() << endl;
	}
	theFile.close();
}

int main()
{
	vector<Person> employees;
	readData(employees);
	writeData(employees);
	return 0;
}
