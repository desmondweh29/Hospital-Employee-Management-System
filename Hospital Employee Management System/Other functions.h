#pragma once
#include "Admin.h"
#include "Queue.h"
#include "Stack.h"

//Check content of strings
bool isLetters(std::string input);
bool isNumbers(std::string input);
bool isSpace(std::string input);
bool isPunct(std::string input);
bool isCapital(std::string input);
bool isNonCapital(std::string input);
bool check_alphabet_space_only(std::string input);
bool check_number_only(std::string input);

//Display
void displayTitle(std::string title);
//Print error messages
void print_invalid();
void print_invalid_a_username();
void print_invalid_name();
void print_invalid_gender();
void print_invalid_birthDate();
void print_invalid_ic();
void print_invalid_nationality();
void print_invalid_hp();
void print_invalid_address();
void print_invalid_hiredDate();
void print_invalid_position();
void print_invalid_password();
void print_invalid_status();
void print_invalid_salary();
//Error message for login
void print_invalid_admin_login();
void print_invalid_employee_login();
void print_no_existing_record();
void print_return();
void print_retry();

//Format strings into all capital case letters
void formatCase(std::string& input); 

//Get real time date
int currentDate(std::string choice);  

//Determine number of days in a month
int determine_num_of_days(int month, int year);

std::string generate_id(std::string position, const std::vector <Employee> record);
std::string generate_password();

//Check employee's member variable input
bool check_a_username_availability(std::string input, const std::vector <Admin> record);
bool check_id_availability(std::string input, const std::vector <Employee> record);
bool check_a_username(std::string input, const std::vector <Admin> record);
bool check_name(std::string input);
bool check_gender(std::string input);
bool check_birthDate(int day, int month, int year);
bool check_ic(std::string input, const std::vector <Employee> record);
bool check_nationality(std::string input);
bool check_hp(std::string input);
bool check_address(std::string input);
bool check_hiredDate(int day, int month, int year, int birthYear);
bool check_position(std::string input);
bool check_password(std::string input);
bool check_status(std::string input);
bool check_salary(double input);

//Check login
bool check_admin_login(std::string username, std::string password, const std::vector <Admin> record);
bool check_employee_login(std::string id, std::string password, const std::vector <Employee> record);
bool check_employee_login_status(std::string id, const std::vector <Employee> record);

std::string getID_byIC(std::string ic, const std::vector <Employee> record);

//Search 
int search_by_a_username(const std::vector <Admin> record, std::string username);
int search_by_id(const std::vector <Employee> record, std::string id); // binary search
void search_by_name(const std::vector <Employee> record, std::string name, Queue& result_index);
void search_by_gender(const std::vector <Employee> record, std::string gender, Queue& result_index);
void search_by_birthDate(const std::vector <Employee> record, int day, int month, int year, std::string choice, Queue& result_index);
void search_by_hireDate(const std::vector <Employee> record, int day, int month, int year, std::string choice, Queue& result_index);
void search_by_position(const std::vector <Employee> record, std::string position, Queue& result_index);

//Sort

//Sort by admin username, acs = queue, dcs = stack
void sort_by_a_username(std::vector <Admin>& record, int first, int last); // quick sort
void sort_by_a_username_partition(std::vector <Admin>& record, int first, int last, int& pivotIndex); 

//Sort by ID, default sort, acs = queue, dcs = stack
void sort_by_id_asc(std::vector <Employee>& record, int first, int last); // quick sort
void sort_by_id_dsc(std::vector <Employee>& record, int first, int last, Stack& result_stack);
void sort_by_id_partition(std::vector <Employee>& record, int first, int last, int& pivotIndex); 

//Sort by name, acs = queue, dcs = stack
void sort_by_name(const std::vector <Employee> record, int first, int last, Queue& result_queue, Stack& result_stack); // quick sort
void sort_by_name_partition(const std::vector <Employee> record, int first, int last, int& pivotIndex, std::vector <int>& result);

//Sort by age, acs = queue, dcs = stack
void sort_by_age(const std::vector <Employee> record, Queue& result_queue, Stack& result_stack); // radix sort

//Sort by gender ----- male first = stack, female first = queue
void sort_by_gender(const std::vector <Employee> record, int first, int last, Queue& result_queue, Stack& result_stack); // quick sort
void sort_by_gender_partition(const std::vector <Employee> record, int first, int last, int& pivotIndex, std::vector <int>& result);

//Sort by hire year 
void sort_by_hire_year(const std::vector <Employee> record, Queue& result_queue, Stack& result_stack); // radix sort

//Sort by position ----- dean > intern = queue, intern > dean = stack
void sort_by_position(const std::vector <Employee> record, int first, int last, Queue& result_queue, Stack& result_stack); // quick sort
void sort_by_position_partition(const std::vector <Employee> record, int first, int last, int& pivotIndex, std::vector <int>& result);
int position_rank(std::string position); // to determine the ranking of the position

//Sort by status ----- active > inactive > suspended = queue,  suspended > inactive > active = stack
void sort_by_status(const std::vector <Employee> record, int first, int last, Queue& result_queue, Stack& result_stack); // quick sort
void sort_by_status_partition(const std::vector <Employee> record, int first, int last, int& pivotIndex, std::vector <int>& result);

//Swap
void swap_admin(Admin& x, Admin& y);
void swap_employee(Employee& x, Employee& y);
void swap_index(int& x, int& y);

//File handling
void save_file(const std::vector <Employee>& record_employee, const std::vector <Admin>& record_admin, std::string fileName);
void load_file(std::vector <Employee>& record_employee, std::vector <Admin>& record_admin, std::string fileName);

//Mask password with asterisk*
std::string maskPassword();

//Update employee
void update_employeeDetails(std::vector <Employee>& record, int current_emp_index, int numIndexKey);




