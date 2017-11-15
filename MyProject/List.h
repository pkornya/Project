#pragma once
#ifndef _LIST_
#define _LIST_
#include <conio.h>
#include <string>
#include "Employee.h"

using MyEmployee::Employee;

namespace MyList {
	class List
	{
	private:
		Employee a;
		List *next;																
	public:
		List() { next = NULL; }
		static void init(List **begin, const Employee obj[], int size);			// Fills list with array of Employee
		static void print(List *begin);											// Shows information about List
		static void addBegin(List **begin, const Employee &ElementToAdd);		// Adds an element to the top of the list
		static void addEnd(List **begin, const Employee &ElementToAdd);			// Adds an element to the end of the list
		static void insert(List **begin, const Employee &ElementToAdd);			// Adds according to sorting
		static void deleteElement(List **begin, const string NameToDelete);		// Erases an element from the list
		static void freeMemory(List **begin);									// Releases the memory						
		static void	fileoutput(ostream &obj, List *begin);						// Writes information to a file
		friend ostream &operator<<(ostream &stream, List *obj);
		static void showListMenu();												
	};
}
#endif  _LIST_
