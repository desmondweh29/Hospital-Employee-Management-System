#include "Employee.h"
#include "Other functions.h"


int Employee::emp_count = 0;

const std::string Employee::AVAILABLE_POSITION [] = {"DEAN", "ADMINISTRATOR", "SPECIALIST", "DOCTOR", "NURSE", "PHYSICIAN", "ASSISTANT PHYSICIAN", "MEDICAL STUDENT", "INTERN"};
double Employee::position_salary[] = { 15000, 12500, 10000, 8000, 5000, 5500, 4000, 3500, 3500 };

Employee::Employee() //: id("")
{
	name = "";
	gender = "";
	birth_day = 0;
	birth_month = 0;
	birth_year = 0;
	age = 0;
	ic = "";
	nationality = "";
	hp = "";
	address = "";
	hired_day = 0;
	hired_month = 0;
	hired_year = 0;
	position = "";
	id = "";
	e_password = "";
	status = "ACTIVE";
	salary = 0;
	//vector_index = emp_count;
	emp_count++;
}

Employee::Employee(std::string name, std::string gender,
	int birth_day, int birth_month, int birth_year,
	std::string ic, std::string nationality, std::string hp, std::string address,
	int hired_day, int hired_month, int hired_year,
	std::string position, std::string id, std::string password)// : id(id)
{
	this->name = name;
	this->gender = gender;
	this->birth_day = birth_day;
	this->birth_month = birth_month;
	this->birth_year = birth_year;
	set_age(determineAge(birth_year, currentDate("YEAR")));
	this->ic = ic;
	this->nationality = nationality;
	this->hp = hp;
	this->address = address;
	this->hired_day = hired_day;
	this->hired_month = hired_month;
	this->hired_year = hired_year;
	this->position = position;
	this->id = id;
	e_password = password;
	set_status("ACTIVE");
	set_salary(determineSalary(position));
	//vector_index = emp_count;
	emp_count++;
}

Employee::Employee(const Employee& e) //: id (e.id)
{ 
	name = e.name;
	gender = e.gender;
	birth_day = e.birth_day;
	birth_month = e.birth_month;
	birth_year = e.birth_year;
	age = e.age;
	ic = e.ic;
	nationality = e.nationality;
	hp = e.hp;
	address = e.address;
	hired_day = e.hired_day;
	hired_month = e.hired_month;
	hired_year = e.hired_year;
	position = e.position;
	id = e.id;
	e_password = e.e_password;
	status = e.status;
	salary = e.salary;
}

Employee::~Employee() {}

void Employee::set_name(std::string name)
{
	this->name = name;
}

void Employee::set_gender(std::string gender)
{
	this->gender = gender;
}

void Employee::set_birth_day(int birth_day)
{
	this->birth_day = birth_day;
}

void Employee::set_birth_month(int birth_month)
{
	this->birth_month = birth_month;
}

void Employee::set_birth_year(int birth_year)
{
	this->birth_year = birth_year;
}

void Employee::set_age(int age)
{
	this->age = age;
}

void Employee::set_ic(std::string ic)
{
	this->ic = ic;
}

void Employee::set_nationality(std::string nationality)
{
	this->nationality = nationality;
}

void Employee::set_hp(std::string hp)
{
	this->hp = hp;
}

void Employee::set_address(std::string address)
{
	this->address = address;
}

void Employee::set_hired_day(int hired_day)
{
	this->hired_day = hired_day;
}

void Employee::set_hired_month(int hired_month)
{
	this->hired_month = hired_month;
}

void Employee::set_hired_year(int hired_year)
{
	this->hired_year = hired_year;
}

void Employee::set_id(std::string id)
{
	this->id = id;
}

void Employee::set_position(std::string position)
{
	this->position = position;
}

void Employee::set_e_password(std::string password)
{
	e_password = password;
}

void Employee::set_status(std::string status)
{
	this->status = status;
}

void Employee::set_salary(double salary)
{
	this->salary = salary;
}

std::string Employee::get_name() const
{
	return name;
}

std::string Employee::get_gender() const
{
	return gender;
}

int Employee::get_birth_day() const
{
	return birth_day;
}

int Employee::get_birth_month() const
{
	return birth_month;
}

int Employee::get_birth_year() const
{
	return birth_year;
}

int Employee::get_age() const
{
	return age;
}

std::string Employee::get_ic() const
{
	return ic;
}

std::string Employee::get_nationality() const
{
	return nationality;
}

std::string Employee::get_hp() const
{
	return hp;
}

std::string Employee::get_address() const
{
	return address;
}

int Employee::get_hired_day() const
{
	return hired_day;
}

int Employee::get_hired_month() const
{
	return hired_month;
}

int Employee::get_hired_year() const
{
	return hired_year;
}

std::string Employee::get_position() const
{
	return position;
}

std::string Employee::get_id() const
{
	return id;
}

std::string Employee::get_e_password() const
{
	return e_password;
}

std::string Employee::get_status() const
{
	return status;
}

double Employee::get_salary() const
{
	return salary;
}

int Employee::get_emp_count() 
{
	return emp_count;
}

//int Employee::get_vector_index() const
//{
//	return vector_index;
//}

int Employee::determineAge(int birth_year, int current_year)
{
	return (current_year - birth_year);
}

double Employee::determineSalary(std::string position)
{
	if (position == AVAILABLE_POSITION[0])
	{
		return position_salary[0];
	}
	else if (position == AVAILABLE_POSITION[1])
	{
		return position_salary[1];
	}
	else if (position == AVAILABLE_POSITION[2])
	{
		return position_salary[2];
	}
	else if (position == AVAILABLE_POSITION[3])
	{
		return position_salary[3];
	}
	else if (position == AVAILABLE_POSITION[4])
	{
		return position_salary[4];
	}
	else if (position == AVAILABLE_POSITION[5])
	{
		return position_salary[5];
	}
	else if (position == AVAILABLE_POSITION[6])
	{
		return position_salary[6];
	}
	else if (position == AVAILABLE_POSITION[7])
	{
		return position_salary[7];
	}
	else if (position == AVAILABLE_POSITION[8])
	{
		return position_salary[8];
	}
	else
	{
		return 0;
	}
}

void Employee::displayList(const std::vector <Employee> record)
{
	std::cout << "\t   No" << std::setw(18) << "Employee ID" << std::setw(55)<< "Employee Name" << std::setw(25) << "Position" << std::endl;
	for (unsigned int i = 0; i < record.size(); i++)
	{
		std::cout << "\t   [" << std::setw(2) << i + 1 << "]" << std::setw(15) << record[i].get_id() << std::setw(55) << record[i].get_name() << std::setw(25) << record[i].get_position() << std::endl;
	} return;
}

void Employee::displayList_birthDate(const std::vector <Employee> record)
{
	std::cout << "\t   No" << std::setw(18) << "Employee ID" << std::setw(55) << "Employee Name" << std::setw(20) << "Date of Birth" << std::endl;
	for (unsigned int i = 0; i < record.size(); i++)
	{
		std::cout << "\t   [" << std::setw(2) << i + 1 << "]" << std::setw(15) << record[i].get_id() << std::setw(55) << record[i].get_name() << std::setw(13) << record[i].get_birth_day() << "/" << record[i].get_birth_month() << "/" << record[i].get_birth_year() << std::endl;
	} return;

}

void Employee::displayList_age(const std::vector <Employee> record)
{
	std::cout << "\t   No" << std::setw(18) << "Employee ID" << std::setw(55) << "Employee Name" << std::setw(12) << "Age" << std::endl;
	for (unsigned int i = 0; i < record.size(); i++)
	{
		std::cout << "\t   [" << std::setw(2) << i + 1 << "]" << std::setw(15) << record[i].get_id() << std::setw(55) << record[i].get_name() << std::setw(12) << record[i].get_age() << std::endl;
	} return;
}

void Employee::displayList_gender(const std::vector <Employee> record)
{
	std::cout << "\t   No" << std::setw(18) << "Employee ID" << std::setw(55) << "Employee Name" << std::setw(10) << "Gender" << std::endl;
	for (unsigned int i = 0; i < record.size(); i++)
	{
		std::cout << "\t   [" << std::setw(2) << i + 1 << "]" << std::setw(15) << record[i].get_id() << std::setw(55) << record[i].get_name() << std::setw(11) << record[i].get_gender() << std::endl;
	} return;
}

void Employee::displayList_hireDate(const std::vector <Employee> record)
{
	std::cout << "\t   No" << std::setw(18) << "Employee ID" << std::setw(55) << "Employee Name" << std::setw(20) << "Date of Hire" << std::endl;
	for (unsigned int i = 0; i < record.size(); i++)
	{
		std::cout << "\t   [" << std::setw(2) << i + 1 << "]" << std::setw(15) << record[i].get_id() << std::setw(55) << record[i].get_name() << std::setw(22) << record[i].get_hired_day() << "/" << record[i].get_hired_month() << "/" << record[i].get_hired_year() << std::endl;
	} return;

}

void Employee::displayList_status(const std::vector <Employee> record)
{
	std::cout << "\t   No" << std::setw(18) << "Employee ID" << std::setw(55) << "Employee Name" << std::setw(13) << "Status" << std::endl;
	for (unsigned int i = 0; i < record.size(); i++)
	{
		std::cout << "\t   [" << std::setw(2) << i + 1 << "]" << std::setw(15) << record[i].get_id() << std::setw(55) << record[i].get_name() << std::setw(15) << record[i].get_status() << std::endl;
	} return;
}

void Employee::displayDetails() const 
{
	std::cout << "\n\t\t\t             [1]  " << "Employee ID\t\t: " << id << std::endl;
	std::cout << "\t\t\t             [2]  " << "Name\t\t\t: " << name << std::endl;
	std::cout << "\t\t\t             [3]  " << "Gender\t\t: " << gender << std::endl;
	std::cout << "\t\t\t             [4]  " << "Age\t\t\t: " << age << std::endl;
	std::cout << "\t\t\t             [5]  " << "Date of birth\t\t: " << birth_day << "/" << birth_month << "/" << birth_year << std::endl;
	std::cout << "\t\t\t             [6]  " << "Identity card number\t: " << ic << std::endl;
	std::cout << "\t\t\t             [7]  " << "Nationality\t\t: " << nationality << std::endl;
	std::cout << "\t\t\t             [8]  " << "Telephone number\t: " << hp << std::endl;
	std::cout << "\t\t\t             [9]  " << "Address\t\t: " << address << std::endl;
	std::cout << "\t\t\t             [10] " << "Date of hire\t\t: " << hired_day << "/" << hired_month << "/" << hired_year << std::endl;
	std::cout << "\t\t\t             [11] " << "Position\t\t: " << position << std::endl;
	std::cout << "\t\t\t             [12] " << "Salary\t\t: " << salary << std::endl;
	std::cout << "\t\t\t             [13] " << "Status\t\t: " << std::setprecision(2) << std::fixed << status << std::endl;
}

void Employee::updateDetails(int choice, const std::vector <Employee> record)
{
	switch (choice)
	{
		case 1:
		{
			std::cout << "\n\n\t\t\t\t     ";
			print_invalid();
			std::cout << "\n\t\t\t\t     Not allowed to change Employee ID." << std::endl;
		} 
		break;

		case 2:
		{
			std::string name;
			std::cout << "\n\t\t\t\t     Enter NEW name : ";
			getline(std::cin, name);

			if (check_name(name))
			{
				formatCase(name);
				set_name(name);
				Admin::addNotification(get_id(), "Name");
				break;
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		print_invalid_name();
		break;

		case 3:
		{
			std::string gender;
			std::cout << "\n\t\t\t\t     Enter NEW gender: ";
			getline(std::cin, gender);

			if (check_gender(gender))
			{
				formatCase(gender);
				set_gender(gender);
				Admin::addNotification(get_id(), "Gender");
				break;
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		print_invalid_gender();
		break;

		case 4:
		{
			std::cout << "\n\n\t\t\t\t     ";
			print_invalid();
			std::cout << "\n\t\t\t\t     Unable to change age as it is derived from date of birth." << std::endl;
		}
		break;

		case 5:
		{
			std::string s_day, s_month, s_year;
			std::cout << "\n\t\t\t\t     Enter NEW birth date - Day (DD)   : ";
			getline(std::cin, s_day);
			std::cout << "\t\t\t\t\t\t          - Month (MM) : ";
			getline(std::cin, s_month);
			std::cout << "\t\t\t\t\t\t          - Year (YYYY): ";
			getline(std::cin, s_year);
			
			if (check_number_only(s_day) && check_number_only(s_month) && check_number_only(s_year) && s_day.size() <= 2 && s_month.size() <= 2 && s_year.size() <= 4)
			{
				int day = stoi(s_day);
				int month = stoi(s_month);
				int year = stoi(s_year);

				if (check_birthDate(day, month, year))
				{
					set_birth_day(day);
					set_birth_month(month);
					set_birth_year(year);
					set_age(determineAge(birth_year, currentDate("YEAR")));
					Admin::addNotification(get_id(), "Age, Date of birth");
					break;
				}
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		std::cout << "\t\t\t\t     ";
		print_invalid_birthDate();
		break;

		case 6:
		{
			std::string ic;
			std::cout << "\n\t\t\t\t     Enter NEW Identity Card number: ";
			getline(std::cin, ic);

			if (check_ic(ic, record))
			{
				set_ic(ic);
				Admin::addNotification(get_id(), "Identity Card number");
				break;
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		std::cout << "\t\t\t\t     ";
		print_invalid_ic();
		break;

		case 7:
		{
			std::string nationality;
			std::cout << "\n\t\t\t\t     Enter NEW nationality: ";
			getline(std::cin, nationality);

			if (check_nationality(nationality))
			{
				formatCase(nationality);
				set_nationality(nationality);
				Admin::addNotification(get_id(), "Nationality");
				break;
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		std::cout << "\t\t\t\t     ";
		print_invalid_nationality();
		break;

		case 8:
		{
			std::string hp;
			std::cout << "\n\t\t\t\t     Enter NEW telephone number: ";
			getline(std::cin, hp);

			if (check_hp(hp))
			{
				set_hp(hp);
				Admin::addNotification(get_id(), "Telephone number");
				break;
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		print_invalid_hp();
		break;

		case 9:
		{
			std::string address;
			std::cout << "\n\t\t\t\t     Enter NEW address: ";
			getline(std::cin, address);

			if (check_address(address))
			{
				formatCase(address);
				set_address(address);
				Admin::addNotification(get_id(), "Address");
				break;
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		print_invalid_address();
		break;

		case 10:
		{
			std::string s_day, s_month, s_year;
			std::cout << "\n\t\t\t\t     Enter NEW hired date - Day (DD)   : ";
			getline(std::cin, s_day);
			std::cout << "\t\t\t\t\t\t          - Month (MM) : ";
			getline(std::cin, s_month);
			std::cout << "\t\t\t\t\t\t          - Year (YYYY): ";
			getline(std::cin, s_year);

			if (check_number_only(s_day) && check_number_only(s_month) && check_number_only(s_year) && s_day.size() <= 2 && s_month.size() <= 2 && s_year.size() <= 4)
			{
				int day = stoi(s_day);
				int month = stoi(s_month);
				int year = stoi(s_year);

				if (check_hiredDate(day, month, year, get_birth_year()))
				{
					set_hired_day(day);
					set_hired_month(month);
					set_hired_year(year);
					Admin::addNotification(get_id(), "Date of hire");
					break;
				}
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		print_invalid_hiredDate();
		break;

		case 11:
		{
			std::string position;
			std::cout << "\n\t\t\t\t     Enter NEW position: ";
			getline(std::cin, position);

			if (check_position(position))
			{
				formatCase(position);
				set_position(position);
				set_salary(determineSalary(position));
				Admin::addNotification(get_id(), "Position, Salary");
				update_id_position();
				break;
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		print_invalid_position();
		break;

		case 12:
		{
			std::string s_salary;
			std::cout << "\n\t\t\t\t     Enter NEW salary: ";
			getline(std::cin, s_salary);

			if (!isLetters(s_salary) && !isSpace(s_salary) && isNumbers(s_salary))
			{
				double salary = stod(s_salary);

				if (check_salary(salary))
				{
					set_salary(salary);
					Admin::addNotification(get_id(), "Salary");
					break;
				}
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		print_invalid_salary();
		break;

		case 13:
		{
			std::string status;
			std::cout << "\n\t\t\t\t     Enter NEW status: ";
			getline(std::cin, status);

			if (check_status(status))
			{
				formatCase(status);
				set_status(status);
				Admin::addNotification(get_id(), "Status");
				break;
			}
		}
		std::cout << std::endl;
		std::cout << "\n\t\t\t\t     ";
		print_invalid();
		print_invalid_status();
		break;

		default:
			std::cout << std::endl;
			std::cout << "\n\t\t\t\t     ";
			print_invalid();
			break;
	}
	return;
}

void Employee::updatePassword(std::string password)
{
	set_e_password(password);
	Admin::addNotification(get_id(), "Password");
	Admin::removeNotification_password(get_id());
}

void Employee::displayPositionSalaryList()
{
	std::cout << "\t\t\t\t     ";
	std::cout << "No" << std::setw(25) << "Position" << std::setw(12) << "Salary" << std::endl;
	for (unsigned int i = 0; i < POSITION_SIZE; i++)
	{
		std::cout << "\t\t\t\t     ";
		std::cout << "[" << std::setw(2) << i + 1 << "]" << std::setw(25) << AVAILABLE_POSITION[i] << std::setw(12) << std::setprecision(2) << std::fixed << position_salary[i] << std::endl;
	}
}

void Employee::updateDefaultSalary(int choice)
{
	int index = choice - 1;
	std::string s_salary;
	std::cout << "\t\t\t\t     Current salary for " << AVAILABLE_POSITION[index] << ": " << position_salary[index] << std::endl;
	std::cout << "\n\t\t\t\t     Enter NEW salary for " << AVAILABLE_POSITION[index] << ": ";
	getline(std::cin, s_salary);

	if (!isLetters(s_salary) && !isSpace(s_salary) && isNumbers(s_salary))
	{
		double salary = stod(s_salary);

		if (check_salary(salary))
		{
			position_salary[index] = salary;
			std::cout << "\n\n\t\t\t\t     Succesfully updated!" << std::endl;
		}
		else
		{
			std::cout << "\n\t\t\t\t     ";
			print_invalid();
			print_invalid_salary();
		}
	}
}

void Employee::update_id_position()
{
	std::string oldID = id; 
	id[0] = position[0];
	id[1] = position[position.size() - 1];
	set_id(id);
	
	for (unsigned int i = 0; i < Admin::password_notification.size(); i++)
	{
		if (oldID == Admin::password_notification[i].id)
		{
			Admin::password_notification[i].id = id;
		}
	}

	for (unsigned int i = 0; i < Admin::update_notification.size(); i++)
	{
		if (oldID == Admin::update_notification[i].id)
		{
			Admin::update_notification[i].id = id;
		}
	}

	for (unsigned int i = 0; i < Admin::register_notification.size(); i++)
	{
		if (oldID == Admin::register_notification[i].id)
		{
			Admin::register_notification[i].id = id;
		}
	}
}


