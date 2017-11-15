#pragma once
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <iostream>

using namespace std;

typedef unsigned int uInt;

namespace MyEmployee {
	class Employee {
	protected:
		char	*Name;
		char	*Position;
		uInt 	YearOfEmployment;
		uInt 	Salary;
		uInt	LengthOfName;												
		uInt	LengthOfPosition;											
	public:
		Employee();
		Employee(char*, char* = " ", uInt = 0, uInt = 0);
		Employee(const Employee &obj);
		~Employee();

		void	setName(char *Name);
		void	setPosition(char *Position);
		void	setYearOfEmployment(uInt YearOfEmployment);
		void	setSalary(uInt Salary);
		void	setAll(char* n, char* p, uInt y, uInt s);
		char	*getName() const;
		char	*getPosition() const;
		uInt	getYearOfEmployment() const;
		uInt	getSalary() const;
		uInt	getLengthOfName() const;
		uInt	getLengthOfPosition() const;

		int		returnCurrentYear() const;
		uInt	returnBonus(uInt YearOfEmployment) const;					
		uInt	returnTax(uInt Salary) const;								

		void	consoleInput();
		void	consoleOutput() const;
		void	fileOutput(ostream &obj);
		void	fileInput(istream &obj);

		friend	ostream &operator<<(ostream &stream, Employee obj);
		friend	istream &operator >> (istream &stream, Employee &obj);
		Employee operator=(Employee obj2);

		static	void changeValues(Employee &obj1, Employee &obj2);
		static	void sort(Employee arr[], int size);

		static	void showMainMenu();
		static	void showEmployeeMenu();
		static	void showEmployeeArrayManu();
		static	void showEmployeesMenu();
	};
}
#endif _EMPLOYEE_H_
