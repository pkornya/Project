#include "Employee.h"
#include <time.h>

namespace MyEmployee {

	Employee::Employee()
	{
		Name = new char[80];
		Position = new char[80];
		YearOfEmployment = 0;
		Salary = 0;
		LengthOfName = 80;
		LengthOfPosition = 80;
	}

	Employee::Employee(const Employee &obj)
	{
		LengthOfName = strlen(obj.Name);
		Name = new char[LengthOfName + 1];

		for (uInt i = 0; i < LengthOfName; i++)
			Name[i] = obj.Name[i];
		Name[LengthOfName] = '\0';

		LengthOfPosition = strlen(obj.Position);
		Position = new char[LengthOfPosition + 1];

		for (uInt i = 0; i < LengthOfPosition; i++)
			Position[i] = obj.Position[i];
		Position[LengthOfPosition] = '\0';

		Salary = obj.Salary;
		YearOfEmployment = obj.YearOfEmployment;
	}

	Employee::Employee(char *name, char *position, uInt YearOfEmployment, uInt Salary)
	{
		LengthOfName = strlen(name);
		Name = new char[LengthOfName + 1];

		for (uInt i = 0; i < LengthOfName; i++)
			Name[i] = name[i];
		Name[LengthOfName] = '\0';

		LengthOfPosition = strlen(position);
		Position = new char[LengthOfPosition + 1];

		for (uInt i = 0; i < LengthOfPosition; i++)
			Position[i] = position[i];
		Position[LengthOfPosition] = '\0';

		this->YearOfEmployment = YearOfEmployment;
		this->Salary = Salary;
	}

	Employee::~Employee()
	{
		delete[] Name;
		delete[] Position;
	}



	void Employee::setName(char *Name)
	{
		LengthOfName = strlen(Name);

		for (uInt i = 0; i < LengthOfName; i++)
			this->Name[i] = Name[i];
		this->Name[LengthOfName] = '\0';
	}

	void Employee::setPosition(char *Position)
	{
		LengthOfPosition = strlen(Position);

		for (uInt i = 0; i < LengthOfPosition; i++)
			this->Position[i] = Position[i];
		this->Position[LengthOfPosition] = '\0';
	}

	void Employee::setYearOfEmployment(uInt YearOfEmployment)
	{
		this->YearOfEmployment = YearOfEmployment;
	}

	void Employee::setSalary(uInt Salary)
	{
		this->Salary = Salary;
	}

	void Employee::setAll(char* n, char* p, uInt y, uInt s)
	{
		LengthOfName = strlen(n);

		for (uInt i = 0; i < LengthOfName; i++)
			Name[i] = n[i];
		Name[LengthOfName] = '\0';

		LengthOfPosition = strlen(p);

		for (uInt i = 0; i < LengthOfPosition; i++)
			Position[i] = p[i];
		Position[LengthOfPosition] = '\0';

		YearOfEmployment = y;
		Salary = s;
	}

	char* Employee::getName() const
	{
		return Name;
	}

	char* Employee::getPosition() const
	{
		return Position;
	}

	uInt Employee::getYearOfEmployment() const
	{
		return YearOfEmployment;
	}

	uInt Employee::getSalary() const
	{
		return Salary;
	}

	uInt Employee::getLengthOfName() const
	{
		return LengthOfName;
	}

	uInt Employee::getLengthOfPosition() const
	{
		return LengthOfPosition;
	}



	int Employee::returnCurrentYear() const
	{
		time_t		t;
		struct tm	*lt;

		time(&t);

		lt = localtime(&t);

		return lt->tm_year + 1900;
	}

	uInt Employee::returnBonus(uInt YearOfEmployment) const
	{
		if (returnCurrentYear() - YearOfEmployment < 5) {
			cout << "There in no bonus for this employee;";
			return 0;
		}
		if (returnCurrentYear() - YearOfEmployment >= 5 && returnCurrentYear() - YearOfEmployment <= 10)
			return Salary * 5 / 100;
		if (returnCurrentYear() - YearOfEmployment >= 10 && returnCurrentYear() - YearOfEmployment <= 15)
			return Salary * 10 / 100;
		if (returnCurrentYear() - YearOfEmployment >= 15)
			return Salary * 20 / 100;
	}

	uInt Employee::returnTax(uInt Salary) const
	{
		return Salary * 13 / 100;
	}

	

	void Employee::consoleInput()
	{
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Name: ";
		cin.getline(Name, LengthOfName);

		cout << "Position: ";
		cin.getline(Position, LengthOfPosition);

		cout << "Year Of Employment: ";
		cin >> YearOfEmployment;

		cout << "Salary: ";
		cin >> Salary;

		cin.ignore(cin.rdbuf()->in_avail());							

		cout << endl;
	}

	void Employee::consoleOutput() const
	{
		cout << "Name: " << Name << endl;
		cout << "Position: " << Position << endl;
		cout << "Year Of Employment: " << YearOfEmployment << endl;
		cout << "Salary: " << Salary << endl << endl;
	}

	void Employee::fileOutput(ostream &obj)
	{
		obj << Name << endl;
		obj << Position << endl;
		obj << YearOfEmployment << endl;
		obj << Salary << endl;
	}

	void Employee::fileInput(istream &obj)
	{
		obj.getline(Name, 40);
		obj.getline(Position, 40);
		obj >> YearOfEmployment;
		obj >> Salary;

		obj.ignore(numeric_limits<streamsize>::max(), '\n');			
	}



	ostream &operator<<(ostream &stream, Employee obj)
	{
		stream << "Name: " << obj.Name << endl;
		stream << "Position: " << obj.Position << endl;
		stream << "Year Of Employment: " << obj.YearOfEmployment << endl;
		stream << "Salary: " << obj.Salary << endl << endl;
		return stream;
	}

	istream &operator >> (istream &stream, Employee &obj)
	{
		cout << "Name: ";
		stream.getline(obj.Name, obj.LengthOfName);

		cout << "Position: ";
		stream.getline(obj.Position, obj.LengthOfPosition);

		cout << "Year Of Employment: ";
		stream >> obj.YearOfEmployment;

		cout << "Salary: ";
		stream >> obj.Salary;
		cin.ignore(cin.rdbuf()->in_avail());

		return stream;
	}

	Employee Employee::operator=(Employee obj2)
	{

		LengthOfName = strlen(obj2.Name);
		LengthOfPosition = strlen(obj2.Position);

		for (uInt i = 0; i < LengthOfName; i++)
			Name[i] = obj2.Name[i];
		Name[LengthOfName] = '\0';

		for (uInt i = 0; i < LengthOfPosition; i++)
			Position[i] = obj2.Position[i];
		Position[LengthOfPosition] = '\0';

		Salary = obj2.Salary;
		YearOfEmployment = obj2.YearOfEmployment;

		return *this;
	}

	

	void Employee::changeValues(Employee &obj1, Employee &obj2)
	{
		Employee temp(obj1);							
		obj1 = obj2;									
		obj2 = temp;									
	}

	void Employee::sort(Employee arr[], int size)
	{
		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
				if (strcmp(arr[i].getName(), arr[j].getName()) > 0)
					changeValues(arr[i], arr[j]);
	}



	void Employee::showMainMenu()
	{
		cout << "1. Use class Employee\n";
		cout << "2. Use class List\n";
		cout << "e - to exit\n";
	}

	void Employee::showEmployeeMenu()
	{
		cout << "1. Open file for reading\n";
		cout << "2. Create file\n";
		cout << "3. Read from file\n";
		cout << "4. Write to file\n";
		cout << "5. Enter information\n";
		cout << "6. Information\n";
		cout << "7. Get bonus\n";
		cout << "8. Get tax\n";
		cout << "e - to exit\n";
	}

	void Employee::showEmployeeArrayManu()
	{
		cout << "1. Open file for reading\n";
		cout << "2. Create file\n";
		cout << "3. Read from file\n";
		cout << "4. Write to file\n";
		cout << "5. Enter information\n";
		cout << "6. Information\n";
		cout << "7. Sort\n";
		cout << "e - to exit\n";
	}

	void Employee::showEmployeesMenu()
	{
		cout << "1. Work with 1 employee\n";
		cout << "2. Work with array of employees\n";
		cout << "e - to exit\n";
	}
}
