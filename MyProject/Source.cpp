#include <iostream>
#include <fstream>
#include "Employee.h";
#include "List.h"

using namespace std;
using MyList::List;

int main()
{

	List *begin = NULL;

	// Choices of user 
	char choice1;
	char choice2;
	char choice3;
	char choice4;
	char choice5;

	// for showEmployeeMenu()
	ofstream fOut;
	ifstream fIn;
	Employee temp;													
	char fileName[40];												
	bool isFileInput = false;										
	bool isInformation = false;										

	// for showEmployeeArrayManu()
	ofstream fOut3;
	ifstream fIn2;
	char fileName2[40];
	bool isFileInput2 = false;
	bool isInformation2 = false;
	int sizeOfArray = 0;											
	Employee *Employees;
	bool isMemoryAllocated = false;									

	// for showListMenu()
	ofstream fOut4("ListInformation.txt");
	char s[40];														

	do {
		system("cls");
		Employee::showMainMenu();									
		cin >> choice1;
		switch (choice1) {

			// Employee
		case '1': do {
			int amount = 0;
			system("cls");
			Employee::showEmployeesMenu();
			cin >> choice2;
			switch (choice2) {

				// Employee for 1 worker
			case '1': do {
				system("cls");
				Employee::showEmployeeMenu();
				cin >> choice4;
				switch (choice4) {
				case '1':
					cout << "\nEnter name of file: ";
					cin >> fileName;
					fIn.open(fileName);
					if (!fIn.is_open()) {
						cout << "\nThere is no such file!";
						_getch();
						isFileInput = false;
						break;
					}
					else {
						isFileInput = true;
						cout << "\nFile is opened successfully.";
						_getch();
						break;
					}

				case '2':
					cout << "\nEnter name of file: ";
					cin >> fileName;
					fOut.open(fileName, ios::app);
					cout << "\nFile was successfully created.";
					_getch();
					break;

				case '3':

					if (!isFileInput) {								
						cout << "\nThe information wasn`t read, try again.";
						_getch();
						break;
					}
					else {
						temp.fileInput(fIn);							
						isInformation = true;
						cout << "\nThe information was read successcully.";
						_getch();
						break;
					}

				case '4':
					if (isInformation && fOut.is_open()) {				
						temp.fileOutput(fOut);
						cout << "\nInformation was written to file.";
						_getch();
						break;
					}
					else {
						cout << "\nInformation wasn`t written to file.";
						_getch();
						break;
					}

				case '5':
					cout << endl;
					temp.consoleInput();
					isInformation = true;
					cout << "\nInformation was entered.";
					_getch();
					break;

				case '6':
					if (isInformation) {
						cout << "\nInformation:\n";
						temp.consoleOutput();
						_getch();
						break;
					}
					else break;

				case '7':
					if (isInformation) {
						cout << "\nBonus: " << temp.returnBonus(temp.getYearOfEmployment()) << endl;
						_getch();
						break;
					}
					else {
						cout << "\nEnter information anout Employee!";
						_getch();
						break;
					}

				case '8':
					if (isInformation) {
						cout << "\nTax: " << temp.returnTax(temp.getSalary()) << endl;
						_getch();
						break;
					}
					else {
						cout << "\nEnter information anout Employee!";
						_getch();
						break;
					}

				}

			} while (choice4 != 'e');
			break;

			// Employee for array of workers
			case '2':
				system("cls");
				cout << "Enter amount of employees: ";
				cin >> sizeOfArray;
				Employees = new Employee[sizeOfArray];				
				isMemoryAllocated = true;
				do {
					system("cls");
					Employee::showEmployeeArrayManu();
					cin >> choice5;
					switch (choice5) {
					case '1':
						cout << "\nEnter name of file: ";
						cin >> fileName2;
						fIn2.open(fileName2);
						if (!fIn2.is_open()) {
							cout << "There is no such file!";
							_getch();
							isFileInput2 = false;
							break;
						}
						else {
							isFileInput2 = true;
							cout << "\nFile is opened successfully.";
							_getch();
							break;
						}

					case '2':
						cout << "\nEnter name of file: ";
						cin >> fileName2;
						fOut3.open(fileName2, ios::app);
						cout << "\nFile was successfully created.";
						_getch();
						break;

					case '3':
						if (!isFileInput2) {
							cout << "\nThe information wasn`t read, try again.";
							_getch();
							break;
						}
						else {
							for (int i = 0; i < sizeOfArray; i++)
								Employees[i].fileInput(fIn2);
							isInformation2 = true;
							cout << "\nThe information was read successfully.";
							_getch();
							break;
						}

					case '4':
						if (isInformation2 && fOut3.is_open()) {
							for (int i = 0; i < sizeOfArray; i++)
								Employees[i].fileOutput(fOut3);
							cout << "\nInformation was written to file.";
							_getch();
							break;
						}
						else {
							cout << "\nInformation wasn`t written to file.";
							_getch();
							break;
						}

					case '5':
						cout << endl;
						for (int i = 0; i < sizeOfArray; i++)
							Employees[i].consoleInput();
						isInformation2 = true;
						cout << "\nInformation was entered.";
						_getch();
						break;

					case '6':
						if (isInformation2) {
							cout << "\nInformation:\n";
							for (int i = 0; i < sizeOfArray; i++)
								Employees[i].consoleOutput();
							_getch();
							break;
						}
						else break;

					case '7':
						Employee::sort(Employees, sizeOfArray);
						cout << "\nSuccessfull sorting";
						_getch();
						break;

					}

				} while (choice5 != 'e');
				break;

			}
		} while (choice2 != 'e');
		break;

		// List
		case '2': do {
			system("cls");
			List::showListMenu();
			cin >> choice3;
			switch (choice3) {
			case '1':
				if (sizeOfArray == 0) {
					cout << "\nThe array is empty.\n";
					_getch();
					break;
				}
				else {
					List::init(&begin, Employees, sizeOfArray);
					cout << "\nThe array of employees was added to List.\n";
					_getch();
					break;
				}

			case '2':
				if (isInformation) {
					List::addBegin(&begin, temp);
					cout << "\nEmployee was added at the beginning.";
					_getch();
					break;
				}
				else {
					cout << "\nThere is no Employee to add.";
					_getch();
					break;
				}

			case '3':
				if (isInformation) {
					List::addEnd(&begin, temp);
					cout << "\nEmployee was added at the ending.";
					_getch();
					break;
				}
				else {
					cout << "\nThere is no Employee to add.";
					_getch();
					break;
				}

			case '4':
				if (isInformation) {
					List::insert(&begin, temp);
					cout << "\nEmployee was added.";
					_getch();
					break;
				}
				else {
					cout << "\nThere is no Employee to add.";
					_getch();
					break;
				}

			case '5':
				cin.ignore(cin.rdbuf()->in_avail());

				cout << "\nEnter employee to delete: ";
				cin.getline(s, 40);
				List::deleteElement(&begin, s);
				break;

			case '6':
				List::freeMemory(&begin);
				break;

			case '7':
				List::fileoutput(fOut4, begin);
				if (begin != NULL) {
					cout << "\nInformation was successfully written to file.";
					_getch();
					break;
				}
				else {
					cout << "\nThere in no information in the List.";
					_getch();
					break;
				}

			case '8':
				List::print(begin);
				_getch();
				break;

			}

		} while (choice3 != 'e');
		break;
		}

	} while (choice1 != 'e');

	if (isMemoryAllocated)
		delete[] Employees;

	fOut.close();
	fOut3.close();
	fOut4.close();

	fIn.close();
	fIn2.close();

	_getch();
	return 0;
}
