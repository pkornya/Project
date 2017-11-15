#include "List.h"

namespace MyList {

	// Fills list with array of Employee
	void List::init(List **begin, const Employee obj[], int size)
	{
		*begin = new List;

		(*begin)->a.setName(obj[0].getName());
		(*begin)->a.setPosition(obj[0].getPosition());
		(*begin)->a.setSalary(obj[0].getSalary());
		(*begin)->a.setYearOfEmployment(obj[0].getYearOfEmployment());

		(*begin)->next = NULL;

		List *end = *begin;

		for (int i = 1; i < size; i++) {
			end->next = new List;
			end = end->next;
			end->a = obj[i];
			end->next = NULL;
		}
	}

	// Shows list information
	void List::print(List *begin)
	{
		if (begin == NULL) {
			cout << "\nList is empty";
			_getch();
			return;
		}

		List *pTemp = begin;


		while (pTemp) {
			cout << "Name: " << pTemp->a.getName() << endl;
			cout << "Position: " << pTemp->a.getPosition() << endl;
			cout << "Year Of Employment: " << pTemp->a.getYearOfEmployment() << endl;
			cout << "Salary: " << pTemp->a.getSalary() << endl << endl;

			pTemp = pTemp->next;
		}

	}

	// Adds an element to the top of the list
	void List::addBegin(List **begin, const Employee &ElementToAdd)
	{

		List *pInsert = new List;
		pInsert->a = ElementToAdd;
		pInsert->next = *begin;											
		*begin = pInsert;												
	}

	// Adds an element to the end of the list
	void List::addEnd(List **begin, const Employee &ElementToAdd)
	{

		List *pInsert = new List;
		pInsert->a = ElementToAdd;
		pInsert->next = NULL;

		List *pTemp = *begin;

		while (1) {
			if (!pTemp->next) {
				pTemp->next = pInsert;
				break;
			}

			pTemp = pTemp->next;
		}
	}

	// Adds according to sorting
	void List::insert(List **begin, const Employee &ElementToAdd)
	{

		List *pInsert = new List;
		pInsert->a = ElementToAdd;

		if (*begin == NULL) {											
			pInsert->next = NULL;
			*begin = pInsert;
			return;
		}

		// If 1 element

		List *pTemp1 = *begin;

		string str1 = pInsert->a.getName();
		string str2 = pTemp1->a.getName();

		if (str1 <= str2) {
			pInsert->next = pTemp1;
			*begin = pInsert;
			return;
		}

		// If 2 or more elements

		List *pTemp2 = pTemp1->next;
		string str3 = pTemp2->a.getName();

		while (pTemp2) {

			if (str1 >= str2 && str1 <= str3) {							
																		
				pTemp1->next = pInsert;
				pInsert->next = pTemp2;
				return;
			}

			
			pTemp1 = pTemp2;
			pTemp2 = pTemp2->next;

		}

		
		pTemp1->next = pInsert;
		pInsert->next = NULL;
	}

	// Erases an element from the list
	void List::deleteElement(List **begin, const string NameToDelete)
	{
		if (*begin == NULL) {
			return;
		}

		// If 1 element

		List *pTemp1 = *begin;

		string s1 = NameToDelete;
		string s2 = pTemp1->a.getName();


		if (s2 == s1) {													
			*begin = pTemp1->next;										
			delete pTemp1;												
			cout << "\nEmployee with name " << NameToDelete << " was deleted";
			_getch();
			return;
		}

		// If 2 or more elements

		List *pTemp2 = pTemp1->next;
		string s3 = pTemp2->a.getName();

		while (pTemp2) {
			if (s3 == s1) {
				pTemp1->next = pTemp2->next;
				delete pTemp2;
				cout << "\nEmployee with name " << NameToDelete << " was deleted";
				_getch();
				return;
			}
			pTemp1 = pTemp2;
			pTemp2 = pTemp2->next;
		}

		cout << "\nThere in no such name.";
		_getch();
	}

	// Releases the memory
	void List::freeMemory(List **begin)
	{
		if (*begin == NULL) {
			cout << "\nList is already empty";
			_getch();
			return;
		}

		List *p = *begin;
		List *t;

		while (p) {
			t = p;														
			p = p->next;
			delete t;
		}

		*begin = NULL;
		cout << "\nList was emptied";
		_getch();
	}

	// Writes information to a file
	void List::fileoutput(ostream &obj, List *begin)
	{
		if (begin == NULL) {
			cout << "NULL";
			return;
		}

		List *pTemp = begin;

		while (pTemp) {
			obj << pTemp->a.getName() << endl;
			obj << pTemp->a.getPosition() << endl;
			obj << pTemp->a.getYearOfEmployment() << endl;
			obj << pTemp->a.getSalary() << endl;

			pTemp = pTemp->next;
		}
	}

	ostream &operator<<(ostream &stream, List *obj)
	{

		if (!obj) {
			cout << "NULL\n";
			return stream;
		}

		List *pTemp = obj;

		while (pTemp) {
			stream << "Name: " << pTemp->a.getName() << endl;
			stream << "Position: " << pTemp->a.getPosition() << endl;
			stream << "Year Of Employment: " << pTemp->a.getYearOfEmployment() << endl;
			stream << "Salary: " << pTemp->a.getSalary() << endl << endl;
			pTemp = pTemp->next;
		}
		return stream;
	}

	
	void List::showListMenu()
	{
		cout << "1. Add array of objects\n";
		cout << "2. Add element to the begin\n";
		cout << "3. Add element to the end\n";
		cout << "4. Add element\n";
		cout << "5. Delete element\n";
		cout << "6. Free memory\n";
		cout << "7. Write information to file\n";
		cout << "8. Show information\n";
		cout << "e - to exit\n";
	}
}