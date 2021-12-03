#include <conio.h>
#include "Other functions.h"

bool isLetters(std::string input)
{
    for (unsigned int i = 0; i < input.size(); i++)
    {
        if (isalpha(input[i]))
        {
            return true;
        }
    } 
    return false;
} 

bool isNumbers(std::string input)
{
    for (unsigned int i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isSpace(std::string input)
{
    for (unsigned int i = 0; i < input.size(); i++)
    {
        if (isspace(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isPunct(std::string input)
{
    for (unsigned int i = 0; i < input.size(); i++)
    {
        if (ispunct(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isCapital(std::string input)
{
    for (unsigned int i = 0; i < input.size(); i++)
    {
        if (isupper(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isNonCapital(std::string input)
{
    for (unsigned int i = 0; i < input.size(); i++)
    {
        if (islower(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool check_alphabet_space_only(std::string input)
{
    if (isLetters(input) && !isNumbers(input) && !isPunct(input))
    {
        return true;
    } return false;
}

bool check_number_only(std::string input)
{
    if (isNumbers(input) && !isLetters(input) && !isPunct(input) && !isSpace(input))
    {
        return true; 
    } return false;
}

void displayTitle(std::string title) {
    system("CLS");
    std::cout << "\t\t\t   " << char(201);      for (int i = 0; i < 61; i++) { std::cout << char(205); }      std::cout << char(187) << std::endl;
    std::cout << "\t\t\t   " << char(43) << "\t\t\t                                         " << char(43) << std::endl;
    std::cout << "\t\t\t   " << char(186) << "\t\t\t                                         " << char(186) << std::endl;
    std::cout << "\t\t\t   ";

    if (title.length() >= 5)
        if (title.length() >= 10)
            if (title.length() >= 15)
                if (title.length() >= 20)
                    if (title.length() >= 25)
                        if (title.length() >= 30)
                            std::cout << "\t\t " << title << std::endl;
                        else
                            std::cout << "\t\t       " << title << std::endl;
                    else
                        std::cout << "\t\t\t" << title << std::endl;
                else
                    std::cout << "\t\t\t  " << title << std::endl;
            else
                std::cout << "\t\t\t    " << title << std::endl;
        else
            std::cout << "\t\t\t     " << title << std::endl;


    std::cout << "\t\t\t   " << char(186) << "\t\t\t                                         " << char(186) << std::endl;
    std::cout << "\t\t\t   " << char(43) << "\t\t\t                                         " << char(43) << std::endl;
    std::cout << "\t\t\t   " << char(200);      for (int i = 0; i < 61; i++) { std::cout << char(205); }      std::cout << char(188) << std::endl;
}

void print_invalid()
{
    std::cout << "Invalid input." << std::endl;
}

void print_invalid_a_username()
{
    std::cout << "\n\t\t\t           Enter letters or numbers only without punctuation and space." << std::endl;
    std::cout << "\t\t\t           Username must be at least 4 to 15 characters long." << std::endl;
}

void print_invalid_name()
{
    std::cout << "\n\t\t\t\t     Enter letters only." << std::endl;
    std::cout << "\t\t\t\t     Name must be at least 1 to 49 characters long." << std::endl;
}

void print_invalid_gender()
{
    std::cout << "\n\t\t\t\t     Enter 'MALE' or 'FEMALE' only." << std::endl;
}

void print_invalid_birthDate()
{
    std::cout << "\n\t\t\t\t     Enter numbers only." << std::endl;
    std::cout << "\t\t\t\t     Enter valid date only." << std::endl;
    std::cout << "\t\t\t\t     Employee must be at least 18 years old." << std::endl;
    std::cout << "\t\t\t\t     Maximum age allowed is 80." << std::endl;
}

void print_invalid_ic()
{
    std::cout << "\n\t\t\t\t     Enter numbers only without punctuation." << std::endl;
    std::cout << "\t\t\t\t     Identity card number must be exactly 12 digits long." << std::endl;
    std::cout << "\t\t\t\t     Each identity card can only be registered once." << std::endl;
}

void print_invalid_nationality()
{
    std::cout << "\n\t\t\t\t     Enter letters only." << std::endl;
    std::cout << "\t\t\t\t     Nationality must be at least 1 to 59 characters long." << std::endl;
}

void print_invalid_hp()
{
    std::cout << "\n\t\t\t\t     Enter numbers only without punctuation and space." << std::endl;
    std::cout << "\t\t\t\t     Telephone number must be at least 7 to 15 digits long." << std::endl;
}
void print_invalid_address()
{
    std::cout << "\t\t\t\t     Enter valid address only." << std::endl;
    std::cout << "\t\t\t\t     Address must be at least 1 to 99 characters long." << std::endl;
}

void print_invalid_hiredDate()
{
    std::cout << "\n\t\t\t\t     Enter numbers only." << std::endl;
    std::cout << "\t\t\t\t     Enter valid date only." << std::endl;
    std::cout << "\t\t\t\t     Hire date must be at least 18 years later from date of birth." << std::endl;
    std::cout << "\t\t\t\t     Hire date cannot be later than today." << std::endl;
}

void print_invalid_position()
{
    std::cout << "\n\t\t\t\t     Enter available positions only." << std::endl;
    std::cout << "\t\t\t\t     Those positions are: " << std::endl;
    for (unsigned int i = 0; i < Employee::POSITION_SIZE; i++)
    {

        if ((i + 1) % 3 == 1)
        {
            std::cout << std::endl;
            std::cout << "\t\t\t\t";
        }

        if (i == 1 || i == 4 || i == 5)
        {
            std::cout << "\t\t";
        }
        
        if (i == 2 || i == 7 || i == 8)
        {
            std::cout << "\t"; 
        }

        std::cout << "[" << i + 1 << "] " << Employee::AVAILABLE_POSITION[i];
    } std::cout << std::endl;
}

void print_invalid_password()
{
    std::cout << "\n\t\t\t\t    The following conditions must be satisfied to create a password: " << std::endl;
    std::cout << "\t\t\t\t    1. Minimum of 8 and maximum of 20 characters." << std::endl;
    std::cout << "\t\t\t\t    2. Must contain at least 1 uppercase letter." << std::endl;
    std::cout << "\t\t\t\t    3. Must contain at least 1 lowercase letter." << std::endl;
    std::cout << "\t\t\t\t    4. Must contain at least 1 number." << std::endl;
    std::cout << "\t\t\t\t    5. Must contain at least 1 punctuation." << std::endl;
}

void print_invalid_status()
{
    std::cout << "\t\t\t\t     Enter 'ACTIVE' or 'INACTIVE' or 'SUSPENDED' only." << std::endl;
}

void print_invalid_salary()
{
    std::cout << "\t\t\t\t     Enter numbers only." << std::endl;
    std::cout << "\t\t\t\t     Salary must be at least RM 1,000 and with a maximum of RM 999,999." << std::endl;
}

void print_invalid_admin_login()
{
    std::cout << "Invalid username or password." << std::endl;
}

void print_invalid_employee_login()
{
    std::cout << "Invalid employee ID or password." << std::endl;
}

void print_no_existing_record()
{
    std::cout << "\n\t\t\t\t           No existing result in the record." << std::endl;
    std::cout << "\t\t\t\t           Enter '0' to back to Find Employee Record." << std::endl;
    std::cout << "\t\t\t\t           Enter any key to retry." << std::endl;
    std::cout << "\t\t\t\t           ";
}

void print_return() 
{
    std::string anyKey;
    std::cout << "\n\t\t\t\t           Enter any key to return." << std::endl;
    std::cout << "\t\t\t\t           ";
    getline(std::cin, anyKey);
}

void print_retry()
{
    std::string anyKey;
    std::cout << "\n\t\t\t\t           Enter any key to retry." << std::endl;
    std::cout << "\t\t\t\t           ";
    getline(std::cin, anyKey);
}

void formatCase(std::string& input)
{
    for (unsigned int i = 0; i < input.size(); i++)
    {
        input[i] = toupper(input[i]);
    }
}

int currentDate(std::string choice) 
{
    struct tm newtime;
    // current date/time based on current system
    time_t now = time(0);

    localtime_s(&newtime, &now);
    // various components of tm structure

    if (choice == "YEAR")
    {
        return  (1900 + newtime.tm_year); //tm_year means years since 1900
    }
    else if (choice == "MONTH")
    {
        return (1 + newtime.tm_mon); //tm_mon means months since January
    }
    else if (choice == "DAY")
    {
        return (newtime.tm_mday); //tm_mday means day of the month
    }
    else if (choice == "HOUR")
    {
        return (newtime.tm_hour);
    }
    else if (choice == "MINUTE")
    {
        return (newtime.tm_min);
    }
    else if (choice == "SECOND")
    {
        return (newtime.tm_sec);
    }
    else
    {
        return 0;
    }    
}

int determine_num_of_days(int month, int year)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        return 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        bool leapYear;

        if (year % 4 != 0)
        {
            leapYear = false;
        }
        else if (year % 100 != 0)
        {
            leapYear = true;
        }
        else if (year % 400 != 0)
        {
            leapYear = false;
        }
        else
        {
            leapYear = true;
        }

        if (leapYear)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
}

std::string generate_id(std::string position, std::vector <Employee> record)
{
    //Note: Please insert this code below before calling this function (just once throughout the main function, preferbly top)
    //std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::stringstream id;

    do
    {
        int number = rand() % 100000;
        std::string digits = std::to_string(number);
        for (unsigned int i = digits.length(); i < 5; i++)
        {
            digits = "0" + digits;
        }   
        id << position[0] << position[position.size() - 1] << "-" << digits;
    } while (check_id_availability(id.str(), record)); //to ensure id is never repeated
   
    return id.str();
}


std::string generate_password()
{
    const char UPPER[] = "ABCDEFGHLJKLMNOPQRSTUVWXYZ";
    const char LOWER[] = "abcdefghijklmnopqrstuvwxyz";
    const char DIGIT[] = "0123456789";
    const char PUNCT[] = "!@#$%^&*()";
    const int LENGTH_UPPER_LOWER = sizeof(UPPER) - 1;
    const int LENGTH_DIGIT_PUNCT = sizeof(DIGIT) - 1;

    std::string password = "";
    for (unsigned int i = 0; i < 3; i++)
    {
        password = UPPER[rand() % LENGTH_UPPER_LOWER] + password;
        password = LOWER[rand() % LENGTH_UPPER_LOWER] + password;
        password = DIGIT[rand() % LENGTH_DIGIT_PUNCT] + password;
        password = PUNCT[rand() % LENGTH_DIGIT_PUNCT] + password;
    } return password;
}

bool check_a_username_availability(std::string input, const std::vector <Admin> record)
{
    for (unsigned int i = 0; i < record.size(); i++) 
    {
        if (input == record[i].get_a_username()) //Check whether username is registered
        {
            return true;
        }
    } return false;
}

bool check_id_availability(std::string input, const std::vector <Employee> record)
{
    for (unsigned int i = 0; i < record.size(); i++)
    {
        if (input == record[i].get_id()) //Check whether id is registered
        {
            return true;
        }
    } return false;
}

bool check_a_username(std::string input, const std::vector <Admin> record)
{
    if ((isLetters(input) || isNumbers(input)) && !isSpace(input) && !isPunct(input) && input.size() >= 4 && input.size() <= 15)
    {
        for (unsigned int i = 0; i < record.size(); i++) //Check whether username is registered
        {
            if (!check_a_username_availability(input, record))
            {
                return true;
            }
        } return false;
    } return false;
}

bool check_name(std::string input)
{
    if (check_alphabet_space_only(input) && input.size() > 0 && input.size() < 50)
    {
        return true;
    } return false;
}

bool check_gender(std::string input)
{
    formatCase(input);

    if (input == "MALE" || input == "FEMALE")
    {
        return true;
    } return false;
}

bool check_birthDate(int day, int month, int year)
{
    if (year >= (currentDate("YEAR") - 80) && year <= (currentDate("YEAR") - 18)) //Check year validity 
    {
        if (month >= 1 && month <= 12) //Check month validity
        {
            int num_of_days = determine_num_of_days(month, year);

            if (day >= 1 && day <= num_of_days) //Check day validity
            {
                return true;
            } return false;
        } return false;
    } return false;
}

bool check_ic(std::string input, const std::vector <Employee> record)
{
    if (check_number_only(input) && input.size() == 12)
    {
        for (unsigned int i = 0; i < record.size(); i++) //Check whether IC is registered
        {
            if (input == record[i].get_ic())
            {
                return false;
            }
        } return true;
    } return false;
}

bool check_nationality(std::string input)
{
    if (check_alphabet_space_only(input) && input.size() > 0 && input.size() < 60)
    {
        return true;
    } return false;
}

bool check_hp(std::string input)
{
    if (check_number_only(input) && input.size() > 6 && input.size() < 16)
    {
        return true;
    } return false;
}

bool check_address(std::string input)
{
    if (isLetters(input) && isNumbers(input) && input.size() > 0 && input.size() < 100)
    {
        return true;
    } return false;
}

bool check_hiredDate(int day, int month, int year, int birthYear)
{
    if (year >= (birthYear + 16) && year <= currentDate("YEAR")) //Check year validity 
    {
        if (year == currentDate("YEAR")) //Check if it's current year
        {
            if (month >= 1 && month <= currentDate("MONTH")) //If it's current year, then check whether the month is valid
            {
                if (month == currentDate("MONTH")) //Check if it's current month
                {
                    if (day >= 1 && day <= currentDate("DAY")) //If it's current month, then check whether the day is valid
                    {
                        return true;
                    } return false;
                }
                else
                {
                    int num_of_days = determine_num_of_days(month, year);

                    if (day >= 1 && day <= num_of_days) //Check day validity
                    {
                        return true;
                    } return false;
                }
            } return false;
        }
        else
        {
            if (month >= 1 && month <= 12) //Check month validity
            {
                int num_of_days = determine_num_of_days(month, year);

                if (day >= 1 && day <= num_of_days) //Check day validity
                {
                    return true;
                } return false;
            } return false;
        }  
    } return false;
}

bool check_position(std::string input)
{
    formatCase(input);

    for (unsigned int i = 0; i < Employee::POSITION_SIZE; i++)
    {
        if (Employee::AVAILABLE_POSITION[i] == input)
        {
            return true;
        }
    } return false;
}

bool check_password(std::string input)
{
    if (isLetters(input) && isNumbers(input) && isCapital(input) && isNonCapital(input) && isPunct(input) && input.size() > 7 && input.size() < 20)
    {
        return true;
    } return false; 
}

bool check_status(std::string input)
{
    formatCase(input);
    if (input == "ACTIVE" || input == "INACTIVE" || input == "SUSPENDED")
    {
        return true;
    } return false;
}

bool check_salary(double input)
{
    if (input >= 1000 && input <= 999999)
    {
        return true;
    } return false;
}

bool check_admin_login(std::string username, std::string password, const std::vector <Admin> record)
{
    for (unsigned int i = 0; i < record.size(); i++)
    {
        if (username == record[i].get_a_username())
        {
            if (password == record[i].get_a_password())
            {
                return true;
            } return false; //username found but wrong password
        }
    } return false; //no username match found
}

bool check_employee_login(std::string id, std::string password, const std::vector <Employee> record)
{
    for (unsigned int i = 0; i < record.size(); i++)
    {
        if (id == record[i].get_id())
        {
            if (password == record[i].get_e_password())
            {
                return true;
            } 
            return false; //id found but wrong password
        }
    } return false; //no id match found
}

bool check_employee_login_status(std::string id, const std::vector <Employee> record) {
    
    for (unsigned int i = 0; i < record.size(); i++)
    {
        if (id == record[i].get_id()) 
        {
            if (record[i].get_status() == "ACTIVE") 
            {
                return true; // active employee
            }
        }
    } return false; // suspended or inactive employee
}

std::string getID_byIC(std::string ic, const std::vector <Employee> record)
{
    for (unsigned int index = 0; index < record.size(); index++)
    {
        if (record[index].get_ic() == ic)
        {
            return record[index].get_id();
        }

    } return "";
}

int search_by_a_username(const std::vector <Admin> record, std::string username)
{
    int first = 0;
    int last = record.size() - 1;
    int middle;
    int position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (record[middle].get_a_username() == username)
        {
            found = true;
            position = middle;
        }
        else if (record[middle].get_a_username() > username)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    } return position;
}

int search_by_id(const std::vector <Employee> record, std::string id)
{
    int first = 0;
    int last = record.size() - 1;
    int middle;
    int position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (record[middle].get_id() == id)
        {
            found = true;
            position = middle;
        }
        else if (record[middle].get_id() > id)
        {
            last = middle - 1;
        }
        else
        {   
            first = middle + 1;
        }
    } return position;
}

void search_by_name(const std::vector <Employee> record, std::string name, Queue& result_index)
{
    for (unsigned int i = 0; i < record.size(); i++)
    {
        if ((record[i].get_name()).find(name) != std::string::npos)
        {
            result_index.enqueue(i);
        }
    } return;
}

void search_by_gender(const std::vector <Employee> record, std::string gender, Queue& result_index)
{
    for (unsigned int i = 0; i < record.size(); i++)
    {
        if (record[i].get_gender() == gender)
        {
            result_index.enqueue(i);
        }
    } return;
}

void search_by_birthDate(const std::vector <Employee> record, int day, int month, int year, std::string choice, Queue& result_index)
{
    if (choice == "BEFORE")
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            if (record[i].get_birth_year() > year)
            {
                continue;
            }
            else if (record[i].get_birth_year() == year && record[i].get_birth_month() > month)
            {
                continue;
            }
            else if (record[i].get_birth_year() == year && record[i].get_birth_month() == month && record[i].get_birth_day() > day)
            {
                continue;
            }
            else
            {
                result_index.enqueue(i);
            }
        }
    }
    else if (choice == "AFTER")
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            if (record[i].get_birth_year() < year)
            {
                continue;
            }
            else if (record[i].get_birth_year() == year && record[i].get_birth_month() < month)
            {
                continue;
            }
            else if (record[i].get_birth_year() == year && record[i].get_birth_month() == month && record[i].get_birth_day() < day)
            {
                continue;
            }
            else
            {
                result_index.enqueue(i);
            }
        }
    }
    else //choice == "EXACT"
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            if (record[i].get_birth_year() == year && record[i].get_birth_month() == month && record[i].get_birth_day() == day)
            {
                result_index.enqueue(i);
            }
        }
    } return;
}

void search_by_hireDate(const std::vector <Employee> record, int day, int month, int year, std::string choice, Queue& result_index)
{
    if (choice == "BEFORE")
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            if (record[i].get_hired_year() > year)
            {
                continue;
            }
            else if (record[i].get_hired_year() == year && record[i].get_hired_month() > month)
            {
                continue;
            }
            else if (record[i].get_hired_year() == year && record[i].get_hired_month() == month && record[i].get_hired_day() > day)
            {
                continue;
            }
            else
            {
                result_index.enqueue(i);
            }
        }
    }
    else if (choice == "AFTER")
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            if (record[i].get_hired_year() < year)
            {
                continue;
            }
            else if (record[i].get_hired_year() == year && record[i].get_hired_month() < month)
            {
                continue;
            }
            else if (record[i].get_hired_year() == year && record[i].get_hired_month() == month && record[i].get_hired_day() < day)
            {
                continue;
            }
            else
            {
                result_index.enqueue(i);
            }
        }
    }
    else //choice == "EXACT"
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            if (record[i].get_hired_year() == year && record[i].get_hired_month() == month && record[i].get_hired_day() == day)
            {
                result_index.enqueue(i);
            }
        }
    } return;
}

void search_by_position(const std::vector <Employee> record, std::string position, Queue& result_index)
{
    for (unsigned int i = 0; i < record.size(); i++)
    {
        if ((record[i].get_position()).find(position) != std::string::npos)
        {
            result_index.enqueue(i);
        }
    } return;
}

//Sort by admin username
void sort_by_a_username(std::vector <Admin>& record, int first, int last) //quick sort
{
    int recordSize = last - first + 1;
    int pivotIndex = first;

    if (recordSize > 1)
    {
        sort_by_a_username_partition(record, first, last, pivotIndex);
        sort_by_a_username(record, first, pivotIndex - 1);
        sort_by_a_username(record, pivotIndex + 1, last);
    }
}

void sort_by_a_username_partition(std::vector <Admin>& record, int first, int last, int& pivotIndex)
{
    pivotIndex = first;

    int last_s1 = first;
    int first_unknown = first + 1;

    while (first_unknown <= last)
    {
        if (record[pivotIndex].get_a_username() >= record[first_unknown].get_a_username())
        {
            last_s1++;
            swap_admin(record[last_s1], record[first_unknown]);
        } first_unknown++;
    }
    swap_admin(record[pivotIndex], record[last_s1]);
    pivotIndex = last_s1;
}

//Sort by ID
void sort_by_id_asc(std::vector <Employee>& record, int first, int last) //quick sort
{
    int recordSize = last - first + 1;
    int pivotIndex = first;

    if (recordSize > 1)
    {
        sort_by_id_partition(record, first, last, pivotIndex);
        sort_by_id_asc(record, first, pivotIndex - 1);
        sort_by_id_asc(record, pivotIndex + 1, last);
    }
}

void sort_by_id_dsc(std::vector <Employee>& record, int first, int last, Stack& result_stack)
{
    sort_by_id_asc(record, first, last);
    for (unsigned int i = 0; i < record.size(); i++)
    {
        result_stack.push(i);
    }
    return;
}

void sort_by_id_partition(std::vector <Employee>& record, int first, int last, int& pivotIndex)
{
    pivotIndex = first;

    int last_s1 = first;
    int first_unknown = first + 1;

    while (first_unknown <= last)
    {
        if (record[pivotIndex].get_id() >= record[first_unknown].get_id())
        {
            last_s1++;
            swap_employee(record[last_s1], record[first_unknown]);
        } first_unknown++;
    }
    swap_employee(record[pivotIndex], record[last_s1]);
    pivotIndex = last_s1;
}

//Sort by name
void sort_by_name(const std::vector <Employee> record, int first, int last, Queue& result_queue, Stack& result_stack)
{
    if (!result_queue.isEmpty() && !result_stack.isEmpty())
    {
        return;
    }

    int recordSize = last - first + 1;
    int pivotIndex = first;

    static std::vector <int> result_vector;

    if (result_vector.empty())
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            result_vector.push_back(i);
        }
    }

    bool sorted = true;

    for (unsigned int i = 0; i < record.size() - 1; i++)
    {
        if (record[result_vector[i]].get_name() > record[result_vector[i + 1]].get_name())
        {
            sorted = false;
            break;
        }
    }

    if (sorted)
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            result_queue.enqueue(result_vector[i]);
            result_stack.push(result_vector[i]);
        }
        result_vector.clear();
        return;
    }

    if (recordSize > 1)
    {
        sort_by_name_partition(record, first, last, pivotIndex, result_vector);
        sort_by_name(record, first, pivotIndex - 1, result_queue, result_stack);
        sort_by_name(record, pivotIndex + 1, last, result_queue, result_stack);
    }
}

void sort_by_name_partition(const std::vector <Employee> record, int first, int last, int& pivotIndex, std::vector <int>& result)
{
    pivotIndex = first;

    int last_s1 = first;
    int first_unknown = first + 1;

    while (first_unknown <= last)
    {
        if (record[result[pivotIndex]].get_name() >= record[result[first_unknown]].get_name())
        {
            last_s1++;
            swap_index(result[last_s1], result[first_unknown]);
        }
        first_unknown++;
    }
    swap_index(result[pivotIndex], result[last_s1]);
    pivotIndex = last_s1;
}

//Sort by age
void sort_by_age(const std::vector <Employee> record, Queue& result_queue, Stack& result_stack)
{
    std::string* ageArr = new std::string[record.size()];
    std::vector <int> result_vector;

    for (unsigned int i = 0; i < record.size(); i++)
    {
        ageArr[i] = std::to_string(record[i].get_age());
        result_vector.push_back(i);
    }

    int currentLength = 2;

    while (currentLength != 0)
    {
        int countArr[10] = { 0 };
        int (*table)[10] = new int[record.size()][10];

        for (unsigned int i = 0; i < record.size(); i++)
        {
            std::stringstream numChar;
            numChar << ageArr[i][currentLength - 1];
            int index;
            numChar >> index;
            table[countArr[index]][index] = result_vector[i];
            countArr[index]++;
        }

        int k = 0;
        for (unsigned int i = 0; i < 10; i++)
        {
            for (int j = 0; j < countArr[i]; j++)
            {
                result_vector[k] = table[j][i];
                ageArr[k] = std::to_string(record[result_vector[k]].get_age());
                k++;
            }
        }
        currentLength--;
    }

    for (unsigned int i = 0; i < record.size(); i++)
    {
        result_queue.enqueue(result_vector[i]);
        result_stack.push(result_vector[i]);
    }
    result_vector.clear();
    return;
}

//Sort by gender
void sort_by_gender(const std::vector <Employee> record, int first, int last, Queue& result_queue, Stack& result_stack)
{
    if (!result_queue.isEmpty() && !result_stack.isEmpty())
    {
        return;
    }

    int recordSize = last - first + 1;
    int pivotIndex = first;

    static std::vector <int> result_vector;

    if (result_vector.empty())
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            result_vector.push_back(i);
        }
    }

    bool sorted = true;

    for (unsigned int i = 0; i < record.size() - 1; i++)
    {
        if (record[result_vector[i]].get_gender() > record[result_vector[i + 1]].get_gender())
        {
            sorted = false;
            break;
        }
    }

    if (sorted)
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            result_queue.enqueue(result_vector[i]);
            result_stack.push(result_vector[i]);
        }
        result_vector.clear();
        return;
    }

    if (recordSize > 1)
    {
        sort_by_gender_partition(record, first, last, pivotIndex, result_vector);
        sort_by_gender(record, first, pivotIndex - 1, result_queue, result_stack);
        sort_by_gender(record, pivotIndex + 1, last, result_queue, result_stack);
    }
}

void sort_by_gender_partition(const std::vector <Employee> record, int first, int last, int& pivotIndex, std::vector <int>& result)
{
    pivotIndex = first;

    int last_s1 = first;
    int first_unknown = first + 1;

    while (first_unknown <= last)
    {
        if (record[result[pivotIndex]].get_gender() >= record[result[first_unknown]].get_gender())
        {
            last_s1++;
            swap_index(result[last_s1], result[first_unknown]);
        }
        first_unknown++;
    }
    swap_index(result[pivotIndex], result[last_s1]);
    pivotIndex = last_s1;
}

//Sort by position
void sort_by_position(const std::vector <Employee> record, int first, int last, Queue& result_queue, Stack& result_stack)
{
    if (!result_queue.isEmpty() && !result_stack.isEmpty())
    {
        return;
    }

    int recordSize = last - first + 1;
    int pivotIndex = first;

    static std::vector <int> result_vector;

    if (result_vector.empty())
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            result_vector.push_back(i);
        }
    }

    bool sorted = true;

    for (unsigned int i = 0; i < record.size() - 1; i++)
    {
        if (position_rank(record[result_vector[i]].get_position()) > position_rank(record[result_vector[i + 1]].get_position()))
        {
            sorted = false;
            break;
        }
    }

    if (sorted)
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            result_queue.enqueue(result_vector[i]);
            result_stack.push(result_vector[i]);
        }
        result_vector.clear();
        return;
    }

    if (recordSize > 1)
    {
        sort_by_position_partition(record, first, last, pivotIndex, result_vector);
        sort_by_position(record, first, pivotIndex - 1, result_queue, result_stack);
        sort_by_position(record, pivotIndex + 1, last, result_queue, result_stack);
    }
}

//Sort by hire date
void sort_by_hire_year(const std::vector <Employee> record, Queue& result_queue, Stack& result_stack)
{
    std::string* date = new std::string[record.size()];
    std::vector <int> result_vector;

    for (unsigned int i = 0; i < record.size(); i++)
    {
        date[i] = std::to_string(record[i].get_hired_year());
        result_vector.push_back(i);
    }
    int currentLength = 4;

    while (currentLength != 0)
    {
        int countArr[10] = { 0 };
        int(*table)[10] = new int[record.size()][10];

        for (unsigned int i = 0; i < record.size(); i++)
        {
            std::stringstream numChar;
            numChar << date[i][currentLength - 1];
            int index;
            numChar >> index;
            table[countArr[index]][index] = result_vector[i];
            countArr[index]++;
        }

        int k = 0;
        for (unsigned int i = 0; i < 10; i++)
        {
            for (int j = 0; j < countArr[i]; j++)
            {
                result_vector[k] = table[j][i];
                date[k] = std::to_string(record[result_vector[k]].get_hired_year());
                k++;
            }
        }
        currentLength--;
    }

    for (unsigned int i = 0; i < record.size(); i++)
    {
        result_queue.enqueue(result_vector[i]);
        result_stack.push(result_vector[i]);
    }
    return;
}

void sort_by_position_partition(const std::vector <Employee> record, int first, int last, int& pivotIndex, std::vector <int>& result)
{
    pivotIndex = first;

    int last_s1 = first;
    int first_unknown = first + 1;

    while (first_unknown <= last)
    {
        if (position_rank(record[result[pivotIndex]].get_position()) >= position_rank(record[result[first_unknown]].get_position()))
        {
            last_s1++;
            swap_index(result[last_s1], result[first_unknown]);
        }
        first_unknown++;
    }
    swap_index(result[pivotIndex], result[last_s1]);
    pivotIndex = last_s1;
}

int position_rank(std::string position)
{
    for (int rank = 0; rank < Employee::POSITION_SIZE; rank++)
    {
        if (position == Employee::AVAILABLE_POSITION[rank])
        {
            return rank;
        }
    } return -1;
}

//Sort by status
void sort_by_status(const std::vector <Employee> record, int first, int last, Queue& result_queue, Stack& result_stack)
{
    if (!result_queue.isEmpty() && !result_stack.isEmpty())
    {
        return;
    }

    int recordSize = last - first + 1;
    int pivotIndex = first;

    static std::vector <int> result_vector;

    if (result_vector.empty())
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            result_vector.push_back(i);
        }
    }

    bool sorted = true;

    for (unsigned int i = 0; i < record.size() - 1; i++)
    {
        if (record[result_vector[i]].get_status() > record[result_vector[i + 1]].get_status())
        {
            sorted = false;
            break;
        }
    }

    if (sorted)
    {
        for (unsigned int i = 0; i < record.size(); i++)
        {
            result_queue.enqueue(result_vector[i]);
            result_stack.push(result_vector[i]);
        }
        result_vector.clear();
        return;
    }

    if (recordSize > 1)
    {
        sort_by_status_partition(record, first, last, pivotIndex, result_vector);
        sort_by_status(record, first, pivotIndex - 1, result_queue, result_stack);
        sort_by_status(record, pivotIndex + 1, last, result_queue, result_stack);
    }
}

void sort_by_status_partition(const std::vector <Employee> record, int first, int last, int& pivotIndex, std::vector <int>& result)
{
    pivotIndex = first;

    int last_s1 = first;
    int first_unknown = first + 1;

    while (first_unknown <= last)
    {
        if (record[result[pivotIndex]].get_status() >= record[result[first_unknown]].get_status())
        {
            last_s1++;
            swap_index(result[last_s1], result[first_unknown]);
        }
        first_unknown++;
    }
    swap_index(result[pivotIndex], result[last_s1]);
    pivotIndex = last_s1;
}

void swap_admin(Admin& x, Admin& y)
{
    Admin temp = x;
    x = y;
    y = temp;
}

void swap_employee(Employee& x, Employee& y)
{
    Employee temp = x;
    x = y;
    y = temp;
}

void swap_index(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void save_file(const std::vector <Employee>& record_employee, const std::vector <Admin>& record_admin, std::string fileName)
{
    std::ofstream file_save(fileName, std::ofstream::binary | std::ios::out);

    if (!file_save)
    {
        std::cerr << "Failed to open " << fileName << ".Kindly try again." << std::endl;
        return;
    }

    boost::archive::binary_oarchive archive(file_save);
    archive << record_employee 
        << Employee::position_salary 
        << record_admin 
        << Admin::password_notification 
        << Admin::update_notification 
        << Admin::register_notification;

    file_save.close();
    return;
}

void load_file(std::vector <Employee>& record_employee, std::vector <Admin>& record_admin, std::string fileName)
{
    std::ifstream file_load(fileName, std::ifstream::binary | std::ios::in);

    if (!file_load)
    {
        std::cerr << "Failed to open " << fileName << ".Kindly try again." << std::endl;
        return;
    }

    boost::archive::binary_iarchive archive(file_load);
    archive >> record_employee
        >> Employee::position_salary
        >> record_admin
        >> Admin::password_notification
        >> Admin::update_notification
        >> Admin::register_notification;

    file_load.close();
    return;
}

std::string maskPassword()
{
    bool show_asterisk = true;
    const char ENTER = 13;//ASCII code for ENTER Key
    const char BACKSPACE = 8;//ASCII code for BACKSPACE Key
    const char DELETE = 127;//ASCII code for DELETE Key
    std::string password = "";//initialize string
    unsigned char c = ' ';//initialize character

    while ((c = _getch()) != ENTER)
    {
        if (c == BACKSPACE || c == DELETE)
        {
            if (password.length() != 0)
            {
                if (show_asterisk)
                    std::cout << "\b \b";
                password.resize(password.length() - 1); //resize the length of password
            }
        }
        else if ((c >= 0 && c <= 31) || (c >= 126 ))
        {
            continue;
        }
        else
        {
            password.push_back(c);
            std::cout << '*';
        }
    }
    std::cout << std::endl;
    return password;
}

void update_employeeDetails(std::vector <Employee>& record, int current_emp_index, int numIndexKey)
{
    displayTitle("Update Employee Record");
    std::cout << "\t\t\t     Employee ID: " << record[current_emp_index].get_id() << std::endl;

    switch (numIndexKey)
    {
    case 1:
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 2:
        std::cout << "\n\n\t\t\t\t     Current name : " << record[current_emp_index].get_name() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 3:
        std::cout << "\n\n\t\t\t\t     Current gender : " << record[current_emp_index].get_gender() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 4:
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 5:
        std::cout << "\n\n\t\t\t\t     Current date of birth : " << record[current_emp_index].get_birth_day() << "/" << record[current_emp_index].get_birth_month() << "/" << record[current_emp_index].get_birth_year() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 6:
        std::cout << "\n\n\t\t\t\t     Current Identity Card number : " << record[current_emp_index].get_ic() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 7:
        std::cout << "\n\n\t\t\t\t     Current nationality : " << record[current_emp_index].get_nationality() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 8:
        std::cout << "\n\n\t\t\t\t     Current telephone number : " << record[current_emp_index].get_hp() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 9:
        std::cout << "\n\n\t\t\t\t     Current address : " << record[current_emp_index].get_address() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 10:
        std::cout << "\n\n\t\t\t\t     Current date of hire : " << record[current_emp_index].get_hired_day() << "/" << record[current_emp_index].get_hired_month() << "/"
            << record[current_emp_index].get_hired_year() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 11:
        std::cout << "\n\n\t\t\t\t     Current Position : " << record[current_emp_index].get_position() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 12:
        std::cout << "\n\n\t\t\t\t     Current salary : " << record[current_emp_index].get_salary() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    case 13:
        std::cout << "\n\n\t\t\t\t     Current status : " << record[current_emp_index].get_status() << std::endl;
        record[current_emp_index].updateDetails(numIndexKey, record);
        break;

    default:
        break;
    }
}