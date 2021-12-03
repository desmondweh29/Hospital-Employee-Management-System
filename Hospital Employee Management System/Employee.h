#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>

class Employee
{
private: 
	friend class boost::serialization::access;
	std::string name;
	std::string gender;
	int birth_day, birth_month, birth_year;
	int age;
	std::string ic;
	std::string nationality;
	std::string hp;
	std::string address;
	int hired_day, hired_month, hired_year;
	std::string position;
	std::string id;
	std::string e_password;
	std::string status;
	double salary;
	static int emp_count; 

	template<class Archive>
	void serialize(Archive& a, const unsigned version)
	{
		a& name& gender&
		birth_day& birth_month& birth_year&
		age& ic& nationality& hp& address&
		hired_day& hired_month& hired_year&
		position& id& e_password&
		status& salary& emp_count;
	}

public:
	static const int POSITION_SIZE = 9;
	static const std::string AVAILABLE_POSITION[POSITION_SIZE];
	static double position_salary[POSITION_SIZE];
	

	//Default constructor
	Employee();

	//Overload constructor
	Employee(std::string name, std::string gender,
		int birth_day, int birth_month, int birth_year,
		std::string ic, std::string nationality, std::string hp, std::string address,
		int hired_day, int hired_month, int hired_year,
		std::string position, std::string id, std::string password);

	//Copy constructor
	Employee(const Employee& e);
	
	//Destructor
	~Employee();

	//Setters
	void set_name(std::string name);
	void set_gender(std::string gender);
	void set_birth_day(int birth_day);
	void set_birth_month(int birth_month);
	void set_birth_year(int birth_year);
	void set_age(int age);
	void set_ic(std::string ic);
	void set_nationality(std::string nationality);
	void set_hp(std::string hp);
	void set_address(std::string address);
	void set_hired_day(int hired_day);
	void set_hired_month(int hired_month);
	void set_hired_year(int hired_year);
	void set_position(std::string position);
	void set_id(std::string id);
	void set_e_password(std::string password);
	void set_status(std::string status);
	void set_salary(double salary);

	//Getters
	std::string get_name() const;
	std::string get_gender() const;
	int get_birth_day() const;
	int get_birth_month() const;
	int get_birth_year() const;
	int get_age() const;
	std::string get_ic() const;
	std::string get_nationality() const;
	std::string get_hp() const;
	std::string get_address() const;
	int get_hired_day() const;
	int get_hired_month() const;
	int get_hired_year() const;
	std::string get_position() const;
	std::string get_id() const;
	std::string get_e_password() const;
	std::string get_status() const;
	double get_salary() const;
	static int get_emp_count();

	//Methods
	int determineAge(int birth_year, int current_year);
	double determineSalary(std::string position);
	
	static void displayList(const std::vector <Employee> record); // with position, default listing
	static void displayList_birthDate(const std::vector <Employee> record);
	static void displayList_age(const std::vector <Employee> record);
	static void displayList_gender(const std::vector <Employee> record);
	static void displayList_hireDate(const std::vector <Employee> record);
	static void displayList_status(const std::vector <Employee> record);
	static void displayPositionSalaryList();
	void displayDetails() const;

	static void updateDefaultSalary(int choice);
	void updateDetails(int choice, const std::vector <Employee> record);
	void updatePassword(std::string password);
	void update_id_position();
};