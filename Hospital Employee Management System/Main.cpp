#include <windows.h>
#include "Other functions.h"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::vector <Employee> record;
	std::vector <Admin> record_adm;
	std::string anyKey;
	bool load_start = true;

	main_menu:

	while (true) //to ensure the system never quit unless it's user's intention
	{

		if (load_start) 
		{
			load_file(record, record_adm, "Data.txt");
			load_start = false;
		}

		if (record_adm.empty()) 
		{
			Admin defaultAdmin("hemsadmin", "Password777!");
			record_adm.push_back(defaultAdmin);
		}
	
		std::string mainKey;
		mainKey = "0";
		displayTitle("Hospital Employee Management System");

		std::cout << "\n\n\t\t\t\t              1. Admin Login          " << std::endl;
		std::cout << "\t\t\t\t              2. Employee Login       " << std::endl;
		std::cout << "\t\t\t\t              3. Employee Registration" << std::endl;
		std::cout << "\t\t\t\t              4. Save and Exit                 " << std::endl;

		std::cout << "\n\t\t\t\t              Enter a number: ";
		getline(std::cin, mainKey);

		if (mainKey.size() > 1)
		{
			goto mainMenuError;
		}

		if (check_number_only(mainKey) && stoi(mainKey) >= 1 && stoi(mainKey) <=4) 
		{
			if (mainKey == "1")
			{
			admin_login:
				//Admin Login
				displayTitle("Admin Login");
				std::string a_username;
				std::string a_password;

				std::cout << "\n\n\t\t\t               Enter admin username : ";
				getline(std::cin, a_username);

				std::cout << "\n\t\t\t               Enter password	    : ";
				a_password = maskPassword();

				if (check_admin_login(a_username, a_password, record_adm))
				{
				//Admin Menu
				admin_menu:
					std::string adminKey;
					displayTitle("Admin Menu\t\t  ");

					std::cout << "\n\n\t\t\t\t           1. List of employee records	" << std::endl;
					std::cout << "\t\t\t\t           2. Update employee record		" << std::endl;
					std::cout << "\t\t\t\t           3. Delete employee record		" << std::endl;
					std::cout << "\t\t\t\t           4. Notification list			" << std::endl;
					std::cout << "\t\t\t\t           5. Salary list					" << std::endl;
					std::cout << "\t\t\t\t           6. Admin account				" << std::endl;
					std::cout << "\t\t\t\t           0. Exit						" << std::endl;
					std::cout << "\n\t\t\t\t           Enter a number: ";
					getline(std::cin, adminKey);

					if (adminKey == "0")
					{
						goto main_menu;
					}
					else if (adminKey == "1")
					{
					admin_listemp:
						std::string adminEmpKey;
						Queue result_queue;
						Stack result_stack;

						std::vector <Employee> sort_result;

						sort_by_id_asc(record, 0, record.size() - 1);

						displayTitle("List of Employee Record");
						std::cout << "\n";
						Employee::displayList(record);

						std::cout << "\n\n\t\t\t\t     Press 'S' to sort, Press 'F' to find." << std::endl;
						std::cout << "\t\t\t\t     Enter an index number for more details." << std::endl;
						std::cout << "\t\t\t\t       Enter '0' to go back to admin menu." << std::endl;
						std::cout << "\n\t\t\t\t            Enter a number: ";

						getline(std::cin, adminEmpKey);

						if (adminEmpKey.size () > 3)
						{
							std::cout << "\n\t\t\t\t           ";
							print_invalid();
							print_retry();
							goto admin_menu;
						}


						if (adminEmpKey == "0")
						{
							goto admin_menu;
						}

						else if (check_number_only(adminEmpKey) && stoi(adminEmpKey) >= 1 && stoi(adminEmpKey) <= record.size())
						{
						admin_listemp_update:
							displayTitle("View Employee Record");
							std::cout << "\n";

							std::string indexKey;
							int numIndexKey;
							int current_emp_index = stoi(adminEmpKey) - 1;
							record[current_emp_index].displayDetails();

							std::cout << "\n\t\t\t\t     Enter an index number to update detail." << std::endl;
							std::cout << "\t\t\t\t     Enter '0' to go back to List of Employee Record." << std::endl;
							std::cout << "\n\t\t\t\t            Enter a number: ";
							getline(std::cin, indexKey);
							std::stringstream(indexKey) >> numIndexKey;

							if (check_number_only(indexKey) && numIndexKey >= 0 && numIndexKey <= 13)
							{
								if (numIndexKey == 0)
								{
									goto admin_listemp;
								}
								update_employeeDetails(record, current_emp_index, numIndexKey);

								std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
								std::cout << "\t\t\t\t     ";
								getline(std::cin, anyKey);
								goto admin_listemp_update;
							}
							else
							{
								std::cout << "\n\t\t\t\t           ";
								print_invalid();
								std::cout << "\t\t\t\t           Enter correct numbers.";
								print_retry();
								goto admin_listemp_update;
							}
						}

						else if (adminEmpKey == "s" || adminEmpKey == "S")
						{
						admin_sort1:
							std::string response1, response2;
							displayTitle("Sort List");
							std::cout << "\n";
							Employee::displayList(record);

							std::cout << "\n\n\t\t\t\t     [A] Employee ID" << std::endl;
							std::cout << "\t\t\t\t     [B] Employee Name" << std::endl;
							std::cout << "\t\t\t\t     [C] Employee Age" << std::endl;
							std::cout << "\t\t\t\t     [D] Employee Gender" << std::endl;
							std::cout << "\t\t\t\t     [E] Employee Hire Year" << std::endl;
							std::cout << "\t\t\t\t     [F] Employee Position" << std::endl;
							std::cout << "\t\t\t\t     [G] Employee Status" << std::endl;
							std::cout << "\n\t\t\t          Sort by: ";
							getline(std::cin, response1);

							if (response1 == "D" || response1 == "d")
							{
								std::cout << "\n\t\t\t\t     [M] Male" << std::endl;
								std::cout << "\t\t\t\t     [F] Female" << std::endl;
							}
							else
							{
								std::cout << "\n\t\t\t\t     [A] Ascending order" << std::endl;
								std::cout << "\t\t\t\t     [D] Descending order" << std::endl;
							}		
							std::cout << "\n\t\t\t          Sort by: ";
							getline(std::cin, response2);

							if (check_alphabet_space_only(response1) && check_alphabet_space_only(response2))
							{
								if ((response1 == "A" || response1 == "a") && (response2 == "A" || response2 == "a"))
								{
									sort_by_id_asc(record, 0, record.size() - 1);
									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList(record);
									sort_result = record;
								}
								else if ((response1 == "A" || response1 == "a") && (response2 == "D" || response2 == "d"))
								{
									sort_by_id_dsc(record, 0, record.size() - 1, result_stack);
									while (!result_stack.isEmpty())
									{
										sort_result.push_back(record[result_stack.getTop()]);
										result_stack.pop();
									}
									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList(sort_result);
								}
								else if ((response1 == "B" || response1 == "b") && (response2 == "A" || response2 == "a"))
								{
									sort_by_name(record, 0, record.size() - 1, result_queue, result_stack);

									while (!result_queue.isEmpty())
									{
										sort_result.push_back(record[result_queue.getFront()]);
										result_queue.dequeue();
									}

									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList(sort_result);
								}
								else if ((response1 == "B" || response1 == "b") && (response2 == "D" || response2 == "d"))
								{
									sort_by_name(record, 0, record.size() - 1, result_queue, result_stack);

									while (!result_stack.isEmpty())
									{
										sort_result.push_back(record[result_stack.getTop()]);
										result_stack.pop();
									}

									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList(sort_result);
								}
								else if ((response1 == "C" || response1 == "c") && (response2 == "A" || response2 == "a"))
								{
									sort_by_age(record, result_queue, result_stack);

									while (!result_queue.isEmpty())
									{
										sort_result.push_back(record[result_queue.getFront()]);
										result_queue.dequeue();
									}

									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList_age(sort_result);
								}
								else if ((response1 == "C" || response1 == "c") && (response2 == "D" || response2 == "d"))
								{
									sort_by_age(record, result_queue, result_stack);

									while (!result_stack.isEmpty())
									{
										sort_result.push_back(record[result_stack.getTop()]);
										result_stack.pop();
									}

									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList_age(sort_result);
								
								}
								else if ((response1 == "D" || response1 == "d") && (response2 == "M" || response2 == "m"))
								{
									sort_by_gender(record, 0, record.size() - 1, result_queue, result_stack);

									while (!result_stack.isEmpty())
									{
										sort_result.push_back(record[result_stack.getTop()]);
										result_stack.pop();
									}

									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList_gender(sort_result);					
								}
								else if ((response1 == "D" || response1 == "d") && (response2 == "F" || response2 == "f"))
								{
									sort_by_gender(record, 0, record.size() - 1, result_queue, result_stack);

									while (!result_queue.isEmpty())
									{
										sort_result.push_back(record[result_queue.getFront()]);
										result_queue.dequeue();
									}

									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList_gender(sort_result);
								
								}
								else if ((response1 == "E" || response1 == "e") && (response2 == "A" || response2 == "a"))
								{
									sort_by_hire_year(record, result_queue, result_stack);
									while (!result_queue.isEmpty())
									{
										sort_result.push_back(record[result_queue.getFront()]);
										result_queue.dequeue();
										result_stack.pop();
									}
									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList_hireDate(sort_result);
								}
								else if ((response1 == "E" || response1 == "e") && (response2 == "D" || response2 == "d"))
								{
									sort_by_hire_year(record, result_queue, result_stack);
									while (!result_stack.isEmpty())
									{
										sort_result.push_back(record[result_stack.getTop()]);
										result_stack.pop();
										result_queue.dequeue();
									}
									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList_hireDate(sort_result);
								}
								else if ((response1 == "F" || response1 == "f") && (response2 == "A" || response2 == "a"))
								{
									sort_by_position(record, 0, record.size() - 1, result_queue, result_stack);

									while (!result_stack.isEmpty())
									{
										sort_result.push_back(record[result_stack.getTop()]);
										result_stack.pop();
										result_queue.dequeue();
									}

									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList(sort_result);
								}
								else if ((response1 == "F" || response1 == "f") && (response2 == "D" || response2 == "d"))
								{
									sort_by_position(record, 0, record.size() - 1, result_queue, result_stack);

									while (!result_queue.isEmpty())
									{
										sort_result.push_back(record[result_queue.getFront()]);
										result_stack.pop();
										result_queue.dequeue();
									}

									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList(sort_result);
								}
								else if((response1 == "G" || response1 == "g") && (response2 == "A" || response2 == "a"))
								{
									sort_by_status(record, 0, record.size() - 1, result_queue, result_stack);

									while (!result_queue.isEmpty())
									{
										sort_result.push_back(record[result_queue.getFront()]);
										result_stack.pop();
										result_queue.dequeue();
									}

									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList_status(sort_result);
								}
								else if ((response1 == "G" || response1 == "g") && (response2 == "D" || response2 == "d"))
								{
									sort_by_status(record, 0, record.size() - 1, result_queue, result_stack);

									while (!result_stack.isEmpty())
									{
										sort_result.push_back(record[result_stack.getTop()]);
										result_stack.pop();
										result_queue.dequeue();
									}
									displayTitle("Sort List");
									std::cout << "\n";
									Employee::displayList_status(sort_result);
								}
								else
								{
									std::cout << "\n\t\t\t\t           ";
									print_invalid();
									print_retry();
									goto admin_sort1;
								}

								std::string adminEmpKey;
								std::cout << "\n\n\t\t\t\t     Enter an index number for more details." << std::endl;
								std::cout << "\t\t\t\t     Enter '0' to back to List of Employee Record." << std::endl;
								std::cout << "\n\t\t\t\t            Enter a number: ";
								getline(std::cin, adminEmpKey);

								if (adminEmpKey.size() > 3)
								{
									std::cout << "\n\t\t\t\t           ";
									print_invalid();
									print_retry();
									sort_result.clear();
									goto admin_sort1;
								}


								if (adminEmpKey == "0")
								{
									sort_result.clear();
									goto admin_listemp;
								}
								else if (check_number_only(adminEmpKey) && stoi(adminEmpKey) >= 1 && stoi(adminEmpKey) <= sort_result.size())
								{
								admin_sort_update:
									displayTitle("View Employee Record");
									std::cout << "\n";

									std::string indexKey;
									int numIndexKey;
									int current_emp_index = stoi(adminEmpKey) - 1;

									sort_result[current_emp_index].displayDetails();

									std::cout << "\n\t\t\t\t     Enter an index number to update detail." << std::endl;
									std::cout << "\t\t\t\t     Enter '0' to go back to List of Employee Record." << std::endl;
									std::cout << "\n\t\t\t\t            Enter a number: ";
									getline(std::cin, indexKey);
									std::stringstream(indexKey) >> numIndexKey;

									if (check_number_only(indexKey) && numIndexKey >= 0 && numIndexKey <= 13)
									{
										if (numIndexKey == 0)
										{
											sort_result.clear();
											goto admin_listemp;
										}
										sort_by_id_asc(record, 0, record.size() - 1);
										current_emp_index = search_by_id(record, sort_result[current_emp_index].get_id());
										update_employeeDetails(record, current_emp_index, numIndexKey);

										sort_result.clear();
										std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
										std::cout << "\t\t\t\t     ";
										getline(std::cin, anyKey);
										goto admin_listemp;
									}
									else
									{
										std::cout << "\n\n\t\t\t             Invalid input.";
										std::cout << "\n\t\t\t             Enter correct numbers.";
										std::cout << "\n\t\t\t             Enter any key to re-enter index number.";
										std::cout << "\n\t\t\t             ";
										getline(std::cin, anyKey);
										goto admin_sort_update;
									}
								}
								else
								{
									std::cout << "\n\t\t\t\t           ";
									print_invalid();
									print_return();
									sort_result.clear();
									goto admin_sort1;
								}
							}
							else
							{
								std::cout << "\n\t\t\t\t           ";
								print_invalid();
								print_retry();
								sort_result.clear();
								goto admin_sort1;
							}
						}

						else if (adminEmpKey == "F" || adminEmpKey == "f")
						{
						admin_search:

							std::string response, id;
							displayTitle("Find Employee Record");
							std::cout << "\n\t\t\t\t           1. Find by Employee ID	" << std::endl;
							std::cout << "\t\t\t\t           2. Find by Name" << std::endl;
							std::cout << "\t\t\t\t           3. Find by Gender " << std::endl;
							std::cout << "\t\t\t\t           4. Find by Date Of Birth" << std::endl;
							std::cout << "\t\t\t\t           5. Find by Date of Hire" << std::endl;
							std::cout << "\t\t\t\t           6. Find by Position" << std::endl;
							std::cout << "\t\t\t\t           0. Exit						" << std::endl;
							std::cout << "\n\n\t\t\t\t            Enter a number: ";

							getline(std::cin, response);

							if (response.size() > 1)
							{
								std::cout << "\n\t\t\t\t           ";
								print_invalid();
								print_retry();
								goto admin_search;
							}

							if (check_number_only(response) && stoi(response) >= 0 && stoi(response) <= 6) 
							{
								std::vector<Employee> search_result;

								if (response == "0")
								{
									goto admin_listemp;
								}
								else if (response == "1")
								{
								search_id:
									std::string id;
									displayTitle("Find by ID");
									std::cout << "\n\t\t\t\t           Enter employee ID: ";
									getline(std::cin, id);

									if (!check_id_availability(id, record))
									{
										print_no_existing_record();
										getline(std::cin, anyKey);
										if (anyKey == "0") {
											goto admin_search;
										}
										else
										{
											goto search_id;
										}
									}
									else
									{
										displayTitle("Find by ID");
										std::cout << std::endl;
										sort_by_id_asc(record, 0, record.size() - 1);
										int current_emp_index = search_by_id(record, id);
										sort_result.push_back(record[current_emp_index]);
										Employee::displayList(sort_result);
									}
								}
								else if (response == "2")
								{
								search_name:
									std::string name;
									displayTitle("Find by Name");
									std::cout << "\n\t\t\t\t           Enter employee Name: ";
									getline(std::cin, name);

									formatCase(name);

									if (check_name(name))
									{
										search_by_name(record, name, result_queue);

										if (result_queue.isEmpty()) 
										{
											print_no_existing_record();
											getline(std::cin, anyKey);
											if (anyKey == "0") {
												goto admin_search;
											}
											else
											{
												goto search_name;
											}
										}

										while (!result_queue.isEmpty())
										{
											search_result.push_back(record[result_queue.getFront()]);
											result_queue.dequeue();
										}

										sort_by_name(search_result, 0, search_result.size() - 1, result_queue, result_stack);

										while (!result_queue.isEmpty())
										{
											sort_result.push_back(search_result[result_queue.getFront()]);
											result_queue.dequeue();
											result_stack.pop();
										}

										displayTitle("Find by Name");
										std::cout << "\n";
										Employee::displayList(sort_result);
									
									}

									else
									{
										std::cout << std::endl;
										std::cout << "\n\t\t\t\t     ";
										print_invalid();
										print_invalid_name();
										print_retry();
										goto search_name;
									}
								}
								else if (response == "3")
								{
								search_gender:
									std::string gender;
									displayTitle("Find by Gender");
									std::cout << "\n\t\t\t\t     Enter employee Gender: ";
									getline(std::cin, gender);
									formatCase(gender);

									if (check_gender(gender))
									{
										search_by_gender(record, gender, result_queue);

										if (result_queue.isEmpty())
										{
											print_no_existing_record();
											getline(std::cin, anyKey);
											if (anyKey == "0") {
												goto admin_search;
											}
											else
											{
												goto search_gender;
											}
										}

										while (!result_queue.isEmpty())
										{
											search_result.push_back(record[result_queue.getFront()]);
											result_queue.dequeue();
										}

										sort_by_gender(search_result, 0, search_result.size()-1, result_queue, result_stack);

										while (!result_queue.isEmpty())
										{
											sort_result.push_back(search_result[result_queue.getFront()]);
											result_queue.dequeue();
											result_stack.pop();
										}

										displayTitle("Find by Gender");
										std::cout << "\n";
										Employee::displayList_gender(sort_result);
									}
									else
									{
										std::cout << std::endl;
										std::cout << "\n\t\t\t\t     ";
										print_invalid();
										print_invalid_gender();
										std::cout << "\n";
										print_retry();
										goto search_gender;
									}

								}
								else if (response == "4")
								{
								search_dob:
									std::string input;
									std::string dobDayStr, dobMonthStr, dobYearStr;
									displayTitle("Find by Date Of Birth");

									std::cout << "\n\t\t\t\t     Date of birth -Day (DD)		: ";
									getline(std::cin, dobDayStr);
									std::cout << "\t\t\t\t		   -Month (MM)		: ";
									getline(std::cin, dobMonthStr);
									std::cout << "\t\t\t\t		   -Year (YYYY)		: ";
									getline(std::cin, dobYearStr);

									if (!(check_number_only(dobDayStr) && check_number_only(dobMonthStr) && check_number_only(dobYearStr)) && dobDayStr.size() <= 2 && dobMonthStr.size() <= 2 && dobYearStr.size() <= 4)
									{
										std::cout << "\n\n\t\t\t\t     ";
										print_invalid();
										print_invalid_birthDate();
										std::cout << "\n\t\t\t\t     Enter '0' to return to Find Employee Record.";
										std::cout << "\n\t\t\t\t     Enter any key to retry." << std::endl;
										std::cout << "\t\t\t\t     ";
										getline(std::cin, anyKey);
										if (anyKey == "0") {
											goto admin_search;
										}
										else
										{
											goto search_dob;
										}
									}

									int dobDay = stoi(dobDayStr);
									int dobMonth = stoi(dobMonthStr);
									int dobYear = stoi(dobYearStr);

									std::cout << "\t\t\t\t		   -EXACT, BEFORE or AFTER	: ";
									getline(std::cin, input);
									formatCase(input);
								
									if (!(check_alphabet_space_only(input) && (input == "EXACT" || input == "BEFORE" || input == "AFTER")))
									{
										std::cout << "\n\t\t\t\t     ";
										print_invalid();
										std::cout << "\t\t\t\t     Only 'EXACT', 'BEFORE' OR 'AFTER' are allowed." << std::endl;
										std::cout << "\n\t\t\t\t     Enter '0' to return to Find Employee Record.";
										std::cout << "\n\t\t\t\t     Enter any key to retry." << std::endl;
										std::cout << "\t\t\t\t     ";
										getline(std::cin, anyKey);
										if (anyKey == "0") {
											goto admin_search;
										}
										else
										{
											goto search_dob;
										}
									}

									search_by_birthDate(record, dobDay, dobMonth, dobYear, input, result_queue);

									if (result_queue.isEmpty())
									{
										print_no_existing_record();
										getline(std::cin, anyKey);
										if (anyKey == "0") {
											goto admin_search;
										}
										else
										{
											goto search_dob;
										}
									}

									while (!result_queue.isEmpty())
									{
										search_result.push_back(record[result_queue.getFront()]);
										result_queue.dequeue();
									}

									sort_by_age(search_result, result_queue, result_stack);

									if (input == "BEFORE")
									{
										while (!result_queue.isEmpty())
										{
											sort_result.push_back(search_result[result_queue.getFront()]);
											result_queue.dequeue();
											result_stack.pop();
										}
									}
									else
									{
										while (!result_stack.isEmpty())
										{
											sort_result.push_back(search_result[result_stack.getTop()]);
											result_stack.pop();
											result_queue.dequeue();
										}
									}

									displayTitle("Find by Date Of Birth");
									std::cout << "\n";
									Employee::displayList_birthDate(sort_result);
								}
								else if (response == "5")
								{
								search_doh:
									std::string input;
									std::string dohDayStr, dohMonthStr, dohYearStr;
									displayTitle("Find by Date Of Hire");

									std::cout << "\n\t\t\t\t     Date of Hire -Day (DD)		: ";
									getline(std::cin, dohDayStr);
									std::cout << "\t\t\t\t		   -Month (MM)		: ";
									getline(std::cin, dohMonthStr);
									std::cout << "\t\t\t\t		   -Year (YYYY)		: ";
									getline(std::cin, dohYearStr);

									if (!(check_number_only(dohDayStr) && check_number_only(dohMonthStr) && check_number_only(dohYearStr)) && dohDayStr.size() <= 2 && dohMonthStr.size() <= 2 && dohYearStr.size() <= 4)
									{
										std::cout << "\n\n\t\t\t\t     ";
										print_invalid();
										print_invalid_hiredDate();
										std::cout << "\n\t\t\t\t     Enter '0' to return to Find Employee Record.";
										std::cout << "\n\t\t\t\t     Enter any key to retry." << std::endl;
										std::cout << "\t\t\t\t     ";
										getline(std::cin, anyKey);
										if (anyKey == "0") {
											goto admin_search;
										}
										else
										{
											goto search_doh;
										}
									}

									int dohDay = stoi(dohDayStr);
									int dohMonth = stoi(dohMonthStr);
									int dohYear = stoi(dohYearStr);

									std::cout << "\t\t\t\t		   -EXACT, BEFORE or AFTER	: ";
									getline(std::cin, input);
									formatCase(input);

									if (!(check_alphabet_space_only(input) && (input == "EXACT" || input == "BEFORE" || input == "AFTER")))
									{
										std::cout << "\n\t\t\t\t     ";
										print_invalid();
										std::cout << "\t\t\t\t     Only 'EXACT', 'BEFORE' OR 'AFTER' are allowed." << std::endl;
										std::cout << "\n\t\t\t\t     Enter '0' to return to Find Employee Record.";
										std::cout << "\n\t\t\t\t     Enter any key to retry." << std::endl;
										std::cout << "\t\t\t\t     ";
										getline(std::cin, anyKey);
										if (anyKey == "0") {
											goto admin_search;
										}
										else
										{
											goto search_doh;
										}
									}

									search_by_hireDate(record, dohDay, dohMonth, dohYear, input, result_queue);

									if (result_queue.isEmpty())
									{
										print_no_existing_record();
										getline(std::cin, anyKey);
										if (anyKey == "0") {
											goto admin_search;
										}
										else
										{
											goto search_doh;
										}
									}

									while (!result_queue.isEmpty())
									{
										search_result.push_back(record[result_queue.getFront()]);
										result_queue.dequeue();
									}

									sort_by_hire_year(search_result, result_queue, result_stack);

									if (input == "BEFORE")
									{
										while (!result_queue.isEmpty())
										{
											sort_result.push_back(search_result[result_queue.getFront()]);
											result_queue.dequeue();
											result_stack.pop();
										}
									}
									else
									{
										while (!result_stack.isEmpty())
										{
											sort_result.push_back(search_result[result_stack.getTop()]);
											result_stack.pop();
											result_queue.dequeue();
										}
									}

									displayTitle("Find by Date Of Hire");
									std::cout << "\n";
									Employee::displayList_hireDate(sort_result);
								}
								else if (response == "6")
								{
								search_position:
									std::string position;
									displayTitle("Find by Position");
									std::cout << "\n\t\t\t\t           Enter employee Position: ";
									getline(std::cin, position);
									formatCase(position);

									if (check_position(position))
									{
										search_by_position(record, position, result_queue);

										if (result_queue.isEmpty())
										{
											print_no_existing_record();
											getline(std::cin, anyKey);
											if (anyKey == "0") {
												goto admin_search;
											}
											else
											{
												goto search_position;
											}
										}

										while (!result_queue.isEmpty())
										{
											search_result.push_back(record[result_queue.getFront()] );
											result_queue.dequeue();
										}
									
										sort_by_position(search_result, 0, search_result.size() - 1, result_queue, result_stack);

										while (!result_queue.isEmpty())
										{
											sort_result.push_back(search_result[result_queue.getFront()]);
											result_queue.dequeue();
										}

										displayTitle("Find by Position");
										std::cout << "\n";
										Employee::displayList(sort_result);	
									}

									else
									{
										std::cout << std::endl;
										std::cout << "\n\t\t\t\t     ";
										print_invalid();
										print_invalid_position();
										print_retry();
										goto search_position;
									}
								}
								else
								{
									std::cout << "\n\n\t\t\t\t            ";
									print_invalid();
									print_retry();
									goto admin_search;
								}

								std::string adminEmpKey;
								std::cout << "\n\n\t\t\t\t     Enter an index number for more details." << std::endl;
								std::cout << "\t\t\t             Enter other keys to go back to Find Employee Menu." << std::endl;
								std::cout << "\n\t\t\t\t            Enter a number: ";
								getline(std::cin, adminEmpKey);

								if (adminEmpKey.size() > 3)
								{
									std::cout << "\n\t\t\t\t           ";
									print_invalid();
									print_retry();
									sort_result.clear();
									goto admin_search;
								}

								if (check_number_only(adminEmpKey) && stoi(adminEmpKey) >= 1 && stoi(adminEmpKey) <= sort_result.size())
								{
								admin_search_detail:
									displayTitle("View Employee Record");

									std::string indexKey;
									int numIndexKey;
									int current_emp_index = stoi(adminEmpKey) - 1;
									sort_result[current_emp_index].displayDetails();

									std::cout << "\n\t\t\t\t     Enter an index number to update detail." << std::endl;
									std::cout << "\t\t\t\t     Enter '0' to go back to Find Employee Record." << std::endl;
									std::cout << "\n\t\t\t\t            Enter a number: ";
									getline(std::cin, indexKey);
									std::stringstream(indexKey) >> numIndexKey;

									if (check_number_only(indexKey) && numIndexKey >= 0 && numIndexKey <= 13)
									{
										if (numIndexKey == 0)
										{
											sort_result.clear();
											search_result.clear();
											goto admin_search;
										}
										sort_by_id_asc(record,0,record.size()-1);
										current_emp_index = search_by_id(record, sort_result[current_emp_index].get_id());
										update_employeeDetails(record, current_emp_index, numIndexKey);

										sort_result.clear();
										search_result.clear();
										print_return();
										goto admin_search;
									}
									else
									{
										std::cout << "\n\t\t\t\t            ";
										print_invalid();
										print_retry();
										goto admin_search_detail;
									}
								}
								else
								{
									sort_result.clear();
									search_result.clear();
									goto admin_search;
								}
	
							}
							else
							{
								std::cout << "\n\n\t\t\t             Invalid input.";
								std::cout << "\n\t\t\t             Enter correct numbers.";
								std::cout << "\n\t\t\t             Enter any key to re-enter index number.";
								std::cout << "\n\t\t\t             ";
								getline(std::cin, anyKey);
								goto admin_search;
							}

						}

						else
						{
							std::cout << "\n\t\t\t\t            ";
							print_invalid();
							print_retry();
							goto admin_listemp;
						}
					}

					else if (adminKey == "2")
					{
						std::string id;
						displayTitle("Update Employee Record");
						std::cout << "\n\n\t\t\t\t           Enter employee ID: ";
						getline(std::cin, id);

						if (!check_id_availability(id, record))
						{
							std::cout << "\n\n\t\t\t             Employee account not found." << std::endl;
							std::cout << "\t\t\t             Enter any key to go back to admin menu." << std::endl;
							std::cout << "\t\t\t             ";
							getline(std::cin, anyKey);
							goto admin_menu;
						}

					admin_emp:
						sort_by_id_asc(record, 0, record.size() - 1);
						int index = search_by_id(record,id);
						displayTitle("Update Employee Record");
						record.at(index).displayDetails();
					
						std::string indexKey;
						int numIndexKey;
						std::cout << "\n\t\t\t\tEnter '0' to go back to admin menu. ";
						std::cout << "\n\t\t\t\tEnter an index number to update: ";
						getline(std::cin, indexKey);
						std::stringstream(indexKey) >> numIndexKey;

						if (check_number_only(indexKey) && numIndexKey >= 0 && numIndexKey <= 13)
						{
							if (numIndexKey == 0)
							{
								goto admin_menu;
							}
							sort_by_id_asc(record, 0, record.size() - 1);
							update_employeeDetails(record, search_by_id(record,id), numIndexKey);
							id = record.at(index).get_id();

							std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
							std::cout << "\t\t\t\t     ";
							getline(std::cin, anyKey);
							goto admin_emp;
						}
						else
						{
							std::cout << "\n\n\t\t\t             Invalid input.";
							std::cout << "\n\t\t\t             Enter correct numbers.";
							std::cout << "\n\t\t\t             Enter any key to re-enter index number.";
							std::cout << "\n\t\t\t             ";
							getline(std::cin, anyKey);
							goto admin_emp;
						}
					}
				
					else if (adminKey == "3")
					{
					admin_DelEmp:
						std::string id;
						displayTitle("Delete Employee Record");
						std::cout << "\n\n\t\t\t\t           Enter employee ID: ";
						getline(std::cin, id);

						if (!check_id_availability(id, record))
						{
							std::cout << "\n\n\t\t\t             Employee account not found." << std::endl;
							std::cout << "\t\t\t             Enter any key to go back to admin menu." << std::endl;
							std::cout << "\t\t\t             ";
							getline(std::cin, anyKey);
							goto admin_menu;
						}

					admin_empR:
						sort_by_id_asc(record, 0, record.size() - 1);
						int current_emp_index = search_by_id(record, id);
						displayTitle("View Employee Record");
						record[current_emp_index].displayDetails();

						std::string response;
						std::cout << "\n\t\t\t\tAre you sure you want to delete this account? (Y/N)" << std::endl;
						std::cout << "\t\t\t\t";
						getline(std::cin, response);

						if (response == "Y" || response == "y")
						{
							record.erase(record.begin() + current_emp_index);
							Admin::removeNotification(id);
							goto admin_menu;
						}
						else if (response == "N" || response == "n")
						{
							goto admin_menu;
						}
						else
						{
							std::cout << "\n\n\t\t\t\t";
							print_invalid();
							std::cout << "\n\t\t\t\tEnter any key to retry." << std::endl;
							std::cout << "\t\t\t\t";
							getline(std::cin, anyKey);
							goto admin_empR;
						}
					}

					else if (adminKey == "4")
					{
					admin_notification:
						std::string adminNotiKey;
					
						displayTitle("Notification");
						std::cout << "\n\n\t\t\t\t     [1] Password Reset Request" << std::endl;
						if (Admin::password_notification.size() != 0)
						{
							int newNotification_password = Admin::get_unread_password();
							if (newNotification_password == Admin::password_notification.size())
							{
								std::cout << "\t\t\t\t      # " << newNotification_password << " new request" ;
							}
							else
							{
								std::cout << "\t\t\t\t      # " << newNotification_password << " new request, " << Admin::password_notification.size() - newNotification_password << " read" ;
							}
						}
					
						std::cout << "\n\n\t\t\t\t     [2] Employee Record Update" << std::endl;
						if (Admin::update_notification.size() != 0)
						{
							std::cout << "\t\t\t\t      # " << Admin::update_notification.size() << " new update" ;
						}

						std::cout << "\n\n\t\t\t\t     [3] New Employee Registration" << std::endl;
						if (Admin::register_notification.size() != 0)
						{
							std::cout << "\t\t\t\t      # " << Admin::register_notification.size() << " new registration" ;
						}

						std::cout << "\n\n\t\t\t\t     Enter an index number for more details." << std::endl;
						std::cout << "\t\t\t\t     Enter '0' to go back to admin menu." << std::endl;
						std::cout << "\n\t\t\t             Enter a number: ";
						getline(std::cin, adminNotiKey);

						if (adminNotiKey == "0")
						{
							goto admin_menu;
						}
						else if (adminNotiKey == "1")
						{
						admin_password_reset:
							sort_by_id_asc(record, 0, record.size() - 1);
							std::string adminPsrKey;
							displayTitle("Password Reset Request");
							std::cout << std::endl;
							Admin::notificationList_password();
							std::cout << "\n\n\t\t\t\t     Enter an index number for confirmation to reset." << std::endl;
							std::cout << "\t\t\t\t     Enter '0' to go back to Notification." << std::endl;
							std::cout << "\t\t\t\t     ";
							getline(std::cin, adminPsrKey);

							if (adminPsrKey.size() > 3)
							{
								std::cout << "\n\t\t\t\t           ";
								print_invalid();
								print_retry();
								goto admin_password_reset;
							}

							if (adminPsrKey == "0")
							{
								goto admin_notification;
							}
							else if (check_number_only(adminPsrKey) && (stoi(adminPsrKey) <= Admin::password_notification.size()))
							{
								if (Admin::check_password_reset_availability(stoi(adminPsrKey)))
								{
									std::string response;
									std::string PsrID = Admin::get_notification_id(stoi(adminPsrKey));
									std::cout << "\n\t\t\t\t     Do you want to reset password for " << PsrID << "? (Y/N)" << std::endl;
									std::cout << "\t\t\t\t     ";
									getline(std::cin, response);

									if (response == "Y" || response == "y")
									{
										sort_by_id_asc(record, 0, record.size() - 1);
										Admin::resetPassword(stoi(adminPsrKey), record);
										std::cout << "\n\t\t\t\t     Password reset request for " << PsrID << " reset successfully!" << std::endl;
										sort_by_id_asc(record, 0, record.size() - 1);
										std::cout << "\t\t\t\t     The following code is the reset password: " << record.at(search_by_id(record, PsrID)).get_e_password() << std::endl;
										std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
										std::cout << "\t\t\t\t     ";
										getline(std::cin, anyKey);
										goto admin_password_reset;
									}
									else if (response == "N" || response == "n")
									{
										goto admin_password_reset;
									}
									else
									{
										std::cout << "\t\t\t\t     ";
										print_invalid();
										std::cout << "\t\t\t\t     Enter any key to proceed." << std::endl;
										std::cout << "\t\t\t\t     ";
										getline(std::cin, anyKey);
										goto admin_password_reset;
									}
								}
								else
								{
									std::cout << "\n\t\t\t\t     ";
									print_invalid();
									std::cout << "\t\t\t\t     The password is already reset." << std::endl;
									std::cout << "\t\t\t\t     Enter any key to proceed." << std::endl;
									std::cout << "\t\t\t\t     ";
									getline(std::cin, anyKey);
									goto admin_password_reset;
								}
							}
							else
							{
								std::cout << "\n\t\t\t\t     ";
								print_invalid();
								std::cout << "\t\t\t\t     Enter correct number." << std::endl;
								std::cout << "\t\t\t\t     Enter any key to proceed." << std::endl;
								std::cout << "\t\t\t\t     ";
								getline(std::cin, anyKey);
								goto admin_password_reset;
							}
						}
						else if (adminNotiKey == "2")
						{
						admin_employee_update_record:
							std::string adminEurKey;
							displayTitle("Employee Update Record");
							std::cout << std::endl;
							Admin::notificationList_update();
							std::cout << "\n\n\t\t\t\t     Enter an index number to mark as read." << std::endl;
							std::cout << "\t\t\t\t     Enter '0' to go back to Notification." << std::endl;
							std::cout << "\t\t\t\t     ";
							getline(std::cin, adminEurKey);

							if (adminEurKey.size() > 3)
							{
								std::cout << "\n\t\t\t\t           ";
								print_invalid();
								print_retry();
								goto admin_employee_update_record;
							}

							if (adminEurKey == "0")
							{
								goto admin_notification;
							}
							else if (check_number_only(adminEurKey) && (stoi(adminEurKey) <= Admin::update_notification.size()))
							{
								Admin::removeNotification_update(stoi(adminEurKey));
								goto admin_employee_update_record;
							}
							else
							{
								std::cout << "\n\t\t\t\t     ";
								print_invalid();
								std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
								std::cout << "\t\t\t\t     ";
								getline(std::cin, anyKey);
								goto admin_employee_update_record;
							}
						}
						else if (adminNotiKey == "3")
						{
						admin_employee_registration_record:
							std::string adminErrKey;
							displayTitle("Employee Registration Record");
							std::cout << std::endl;
							Admin::notificationList_register();
							std::cout << "\n\n\t\t\t\t     Enter an index number to mark as read." << std::endl;
							std::cout << "\t\t\t\t     Enter '0' to go back to Notification." << std::endl;
							std::cout << "\t\t\t\t     ";
							getline(std::cin, adminErrKey);

							if (adminErrKey.size() > 3)
							{
								std::cout << "\n\t\t\t\t           ";
								print_invalid();
								print_retry();
								goto admin_employee_registration_record;
							}

							if (adminErrKey == "0")
							{
								goto admin_notification;
							}
							else if (isNumbers(adminErrKey) && (stoi(adminErrKey) <= Admin::register_notification.size()))
							{
								Admin::removeNotification_register(stoi(adminErrKey));
								goto admin_employee_registration_record;
							}
							else
							{
								std::cout << "\n\t\t\t\t     ";
								print_invalid();
								std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
								std::cout << "\t\t\t\t     ";
								getline(std::cin, anyKey);
								goto admin_employee_registration_record;
							}
						}
						else
						{
							std::cout << "\t\t\t\t     ";
							print_invalid();
							std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
							std::cout << "\t\t\t\t     ";
							getline(std::cin, anyKey);
							goto admin_notification;
						}

					}

					else if (adminKey == "5")
					{
					admin_salary:
						displayTitle("Salary List");
						std::string adminSalaryKey;
						std::cout << "\n";
						Employee::displayPositionSalaryList();
						std::cout << "\n\n";
						std::cout << "\t\t\t\t     Enter an index number to update est.salary." << std::endl;
						std::cout << "\t\t\t\t     Enter '0' to go back to admin menu." << std::endl;

						std::cout << "\n\t\t\t\t     Enter a number: ";

						getline(std::cin, adminSalaryKey);

						if (adminSalaryKey.size() > 1)
						{
							std::cout << "\n\t\t\t\t           ";
							print_invalid();
							print_retry();
							goto admin_salary;
						}

						if (check_number_only(adminSalaryKey) && stoi(adminSalaryKey) >= 1 && stoi(adminSalaryKey) <= 9)
						{
							displayTitle("Update Est Salary");
							std::cout << "\n\n";
							Employee::updateDefaultSalary(stoi(adminSalaryKey));
							std::cout << "\t\t\t\t     Press any key to go back to Salary List." << std::endl;
							std::cout << "\t\t\t\t     ";
							getline(std::cin, anyKey);
							goto admin_salary;
						}
						else if (adminSalaryKey == "0") 
						{
							goto admin_menu;
						}
						else
						{
							std::cout << "\n\t\t\t\t     ";
							print_invalid();
							std::cout << "\t\t\t\t     Press any key to go back to Salary List." << std::endl;
							std::cout << "\t\t\t\t     ";
							getline(std::cin, anyKey);
							goto admin_salary;
						}
					}

					else if (adminKey == "6")
					{
					admin_account:
						sort_by_a_username(record_adm, 0, record_adm.size() - 1);
						int current_a_index = search_by_a_username(record_adm, a_username);
						std::string adminAccKey;
						displayTitle("Admin Account");

						std::cout << "\n\n\t\t\t\t           1. List of admin records    " << std::endl;
						std::cout << "\t\t\t\t           2. Create admin			   " << std::endl;
						std::cout << "\t\t\t\t           3. Change admin login details " << std::endl;
						std::cout << "\t\t\t\t           4. Delete admin record		   " << std::endl;
						std::cout << "\t\t\t\t           0. Back					   " << std::endl;
						std::cout << "\n\t\t\t\t            Enter a number: ";
						getline(std::cin, adminAccKey);

						if (adminAccKey == "1") {
							displayTitle("List of admin account");
							std::cout << std::endl;
							Admin::displayList(record_adm);

							std::cout << "\n\n\t\t\t\t     Enter any key to go back to admin account." << std::endl;
							std::cout << "\t\t\t\t     ";
							getline(std::cin, anyKey);

							goto admin_account;
						}

						else if (adminAccKey == "2")
						{
						create_admin:
							sort_by_a_username(record_adm, 0, record_adm.size() - 1);
							int current_a_index = search_by_a_username(record_adm, a_username);
							std::string registration_username;
							std::string registration_a_password;
							displayTitle("Create Admin");

							std::cout << "\n\t\t\t\t           Enter username : ";
							getline(std::cin, registration_username);

							if (check_a_username(registration_username, record_adm))
							{
							create_admin_password:
								displayTitle("Create Admin");

								std::cout << "\n\t\t\t\t           Enter username : " << registration_username << std::endl;
								std::cout << "\n\t\t\t\t           Enter password : ";
								getline(std::cin, registration_a_password);

								if (check_password(registration_a_password))
								{
									Admin newAdmin(registration_username, registration_a_password);
									record_adm.push_back(newAdmin);
									sort_by_a_username(record_adm, 0, record_adm.size() - 1);
									std::cout << "\n\n\t\t\t\t           Successfully created. ";
									std::cout << "\n\t\t\t\t           Enter any key to go back to admin menu." << std::endl;
									std::cout << "\t\t\t\t           ";
									getline(std::cin, anyKey);
									goto admin_account;
								}
								else
								{
									std::cout << "\n\n\t\t\t\t           ";
									print_invalid();
									print_invalid_password();
									std::cout << "\n\t\t\t\t           Enter any key to proceed." << std::endl;
									getline(std::cin, anyKey);
									goto create_admin_password;
								}

							}
							else
							{
								std::cout << "\n\n\t\t\t           ";
								print_invalid();
								print_invalid_a_username();
								std::cout << "\n\t\t\t           Enter any key to proceed." << std::endl;
								std::cout << "\n\n\t\t\t           ";
								getline(std::cin, anyKey);
								goto create_admin;
							}
						}

						//change admin login details
						else if (adminAccKey == "3")
						{
						change_admin_login:
							sort_by_a_username(record_adm, 0, record_adm.size() - 1);
							int current_a_index = search_by_a_username(record_adm, a_username);
							std::string response;
							displayTitle("Change Admin Login Details");
							std::cout << "\n\t\t\t\t	1. Change admin username " << std::endl;
							std::cout << "\t\t\t\t	2. Change admin password " << std::endl;
							std::cout << "\n\t\t\t\t	Enter a number : ";
							getline(std::cin, response);

							if (response == "1")
							{
							admin_change_username:
								displayTitle("Change Admin Username");
								std::cout << "\n\t\t\t\t	Current username : " << record_adm[current_a_index].get_a_username() << std::endl;
								std::cout << "\n\t\t\t\t	New username	 : ";
								getline(std::cin, a_username);

								if (check_a_username(a_username, record_adm))
								{
									record_adm[current_a_index].set_a_username(a_username);
									sort_by_a_username(record_adm, 0, record_adm.size() - 1);
									std::cout << "\n\n\t\t\t\t	Successfully changed." << std::endl;
									std::cout << "\t\t\t\t	Enter any key to proceed." << std::endl;
									std::cout << "\t\t\t\t	";
									getline(std::cin, anyKey);
									goto admin_account;
								}
								else
								{
									std::cout << "\n\n\t\t\t\t   ";
									print_invalid();
									print_invalid_a_username();
									std::cout << "\n\t\t\t           Enter any key to enter username again." << std::endl;
									std::cout << "\t\t\t           Enter '0' to go back admin account." << std::endl;
									std::cout << "\t\t\t          ";
									getline(std::cin, anyKey);
									if (anyKey == "0")
									{
										goto admin_account;
									}
									else
									{
										goto admin_change_username;
									}
								}

							}
							else if (response == "2") 
							{
							admin_change_password:
								sort_by_a_username(record_adm, 0, record_adm.size() - 1);
								int current_a_index = search_by_a_username(record_adm, a_username);
								displayTitle("Change Admin Password");
								std::cout << "\n\t\t\t\t	Current password : ";
								a_password = maskPassword();

								if (a_password == record_adm[current_a_index].get_a_password())
								{
									std::string new_a_password;

									std::cout << "\n\t\t\t\t	New Password	 : ";
									getline(std::cin, new_a_password);

									if (check_password(new_a_password)) 
									{
										if (new_a_password == record_adm[current_a_index].get_a_password())
										{
											std::cout << "\n\n\t\t\t\t	Change password failed!" << std::endl;
											std::cout << "\t\t\t\t	New password cannot be the same with old password." << std::endl;
											std::cout << "\t\t\t\t	Enter any key to enter password again." << std::endl;
											std::cout << "\t\t\t\t	Enter '0' to go back admin account." << std::endl;
											std::cout << "\t\t\t\t	";
											getline(std::cin, anyKey);

											if (anyKey == "0")
											{
												goto admin_account;
											}
											else
											{
												goto admin_change_password;
											}
										}
										record_adm[current_a_index].set_a_password(new_a_password);
										std::cout << "\n\n\t\t\t\t	Change Successfully. " << std::endl;
										std::cout << "\t\t\t\t	Enter any key to back to admin account." << std::endl;
										std::cout << "\t\t\t\t	";
										getline(std::cin, anyKey);
										goto admin_account;
									}
									else
									{
										std::cout << "\n\n\t\t\t\t	";
										print_invalid();
										print_invalid_password();
										std::cout << "\n\t\t\t\t	Enter any key to enter password again." << std::endl;
										std::cout << "\t\t\t\t	Enter '0' to go back admin account." << std::endl;
										std::cout << "\t\t\t\t	";
										getline(std::cin, anyKey);

										if (anyKey == "0")
										{
											goto admin_account;
										}
										else
										{
											goto admin_change_password;
										}
									}
								
								}
								else
								{
									std::cout << "\n\n\n\t\t\t             Invalid password!" << std::endl;
									std::cout << "\t\t\t             Enter any key to change password again." << std::endl;
									std::cout << "\t\t\t             Enter '0' to go back admin account." << std::endl;
									std::cout << "\t\t\t             ";
									getline(std::cin, anyKey);

									if (anyKey == "0")
									{
										goto admin_account;
									}
									else
									{
										goto admin_change_password;
									}
								}

							}
							else 
							{
								std::cout << "\n\n\t\t\t\t	Enter 1 or 2 only." << std::endl;
								std::cout << "\n\n\t\t\t\t	Enter any key to proceed." << std::endl;
								std::cout << "\t\t\t\t	";
								getline(std::cin, anyKey);
								goto change_admin_login;
							}
						}
						else if (adminAccKey == "4")
						{
						delete_admin:
							sort_by_a_username(record_adm, 0, record_adm.size() - 1);
							int current_a_index = search_by_a_username(record_adm, a_username);
							std::string response;
							displayTitle("Delete admin record");

							std::cout << "\n\n\t\t\t\t	Admin username : " << record_adm[current_a_index].get_a_username() << std::endl;
							std::cout << "\n\t\t\t\tAre you sure you want to delete this account? (Y/N)" << std::endl;
							std::cout << "\t\t\t\t";
							getline(std::cin, response);

							if (response == "Y" || response == "y")
							{
								if (record_adm.size() == 1)
								{
									std::cout << "\n\n\t\t\t\t";
									print_invalid();
									std::cout << "\n\t\t\t\tYou must remain at least one admin account." << std::endl;
									std::cout << "\n\t\t\t\tEnter any key to retry." << std::endl;
									std::cout << "\t\t\t\t";
									getline(std::cin, anyKey);
									goto delete_admin;
								}
								
								record_adm.erase(record_adm.begin() + current_a_index);
								sort_by_a_username(record_adm, 0, record_adm.size() - 1);
								goto main_menu;
							}
							else if (response == "N" || response == "n") 
							{
								goto admin_account;
							}
							else 
							{
								std::cout << "\n\n\t\t\t\t";
								print_invalid();
								std::cout << "\n\t\t\t\tEnter any key to retry." << std::endl;
								std::cout << "\t\t\t\t";
								getline(std::cin, anyKey);
								goto delete_admin;
							}
						}
						else if (adminAccKey == "0")
						{
							goto admin_menu;
						}
						else 
						{
							std::cout << "\n\n\t\t\t\t           ";
							print_invalid();
							std::cout << "\n\t\t\t\t           Enter any key to retry." << std::endl;
							std::cout << "\t\t\t\t           ";
							getline(std::cin, anyKey);
							goto admin_account;
						}
					}
					else 
					{
						std::cout << "\n\t\t\t\t           ";
						print_invalid();
						print_retry();
						goto admin_menu;
					}
				}
				else
				{
					std::cout << "\n\n\t\t\t               Invalid username or password!" << std::endl;
					std::cout << "\t\t\t               Enter any key to re-enter username and password." << std::endl;
					std::cout << "\t\t\t               Enter '0' to go back to main menu." << std::endl;
					std::cout << "\t\t\t               ";
					getline(std::cin, anyKey);

					if (anyKey == "0") 
					{
						goto main_menu;
					}
					else
					{
						goto admin_login;
					}

				}
			}
			
			//Employee Login
			else if (mainKey == "2")
			{
			empLoginMain:
				displayTitle("Employee Login");

				std::string id;
				std::string password;

				std::cout << "\n\n\t\t\t               Enter employee ID : ";
				getline(std::cin, id);

				std::cout << "\n\t\t\t               Enter password	 : ";
				password = maskPassword();

				if (check_employee_login(id, password, record))
				{
					if (!check_employee_login_status(id, record))
					{
						std::cout << "\n\n\t\t\t             Suspended/Inactive account." << std::endl;
						std::cout << "\t\t\t             Kindly contact admin if you are active employee." << std::endl;
						std::cout << "\t\t\t             Enter any key to go back to main menu." << std::endl;
						std::cout << "\t\t\t             ";

						getline(std::cin, anyKey);

						goto main_menu;
					}
					//Employee Menu
				employee_menu:
					std::string empKey;
				
					sort_by_id_asc(record, 0, record.size()-1);
					int current_emp_index = search_by_id(record, id);
				
					displayTitle("Employee Menu");

					std::cout << "\n\n\t\t\t\t            1. View employee record" << std::endl;
					std::cout << "\t\t\t\t            2. Update employee record" << std::endl;
					std::cout << "\t\t\t\t            3. Change login password" << std::endl;
					std::cout << "\t\t\t\t            4. Print certificate of employment" << std::endl;
					std::cout << "\t\t\t\t            0. Exit" << std::endl;

					std::cout << "\n\t\t\t\t            Enter a number: ";
					getline(std::cin, empKey);

					if (empKey.size() > 1)
					{
						std::cout << "\n\t\t\t\t           ";
						print_invalid();
						print_retry();
						goto employee_menu;
					}

					if (check_number_only(empKey) && stoi(empKey) >= 0 && stoi(empKey) <=4)
					{

						if (empKey == "0")
						{
							goto main_menu;
						}

						//View Employee Record
						if (empKey == "1")
						{
							displayTitle("View Employee Record");
							record[current_emp_index].displayDetails();

							std::cout << "\n\n\t\t\t\t     Enter any key to go back to employee menu." << std::endl;
							std::cout << "\t\t\t\t     ";
							getline(std::cin, anyKey);

							goto employee_menu;
						}

						//Update Employee Record
						if (empKey == "2")
						{
						employee_update:
							std::string indexKey;
							int numIndexKey;

							displayTitle("Update Employee Record");
							record[current_emp_index].displayDetails();
							std::cout << "\n\t\t\t\t     Enter 0 to go back to employee menu." << std::endl;
							std::cout << "\t\t\t\t     Enter index number to update: ";
							getline(std::cin, indexKey);

							std::stringstream(indexKey) >> numIndexKey;

							if (check_number_only(indexKey) && numIndexKey >= 0 && numIndexKey <= 13)
							{
								displayTitle("Update Employee Record");
								std::cout << "\t\t\t     Employee ID: " << record[current_emp_index].get_id() << std::endl;

								if (numIndexKey == 0)
								{
									goto employee_menu;
								}
								update_employeeDetails(record, current_emp_index, numIndexKey);
								id = record[current_emp_index].get_id();

								std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
								std::cout << "\t\t\t\t     ";
								getline(std::cin, anyKey);
								goto employee_update;
							}
							else
							{
								std::cout << "\n\n\t\t\t             Invalid input.";
								std::cout << "\n\t\t\t             Enter correct numbers.";
								std::cout << "\n\t\t\t             Enter any key to re-enter index number.";
								std::cout << "\n\t\t\t             ";
								getline(std::cin, anyKey);

								goto employee_update;
							}
						}

						//change login password
						if (empKey == "3")
						{
						employee_change_password:
							std::string response;
							std::string new_password;

							displayTitle("Change Login Password");
							std::cout << "\t\t\t     Employee ID: " << record[current_emp_index].get_id() << std::endl;
							std::cout << "\n\n\t\t\t            Current Password	: ";
							password = maskPassword();

							if (password == record[current_emp_index].get_e_password())
							{
								if (check_password(password))
								{
									std::cout << "\n\t\t\t            New Password	: ";
									getline(std::cin, new_password);

									if (!check_password(new_password))
									{
										std::cout << "\n\n\t\t\t\t    ";
										print_invalid();
										print_invalid_password();
										std::cout << "\n\t\t\t\t    Enter any key to re-enter the password." << std::endl;
										std::cout << "\t\t\t\t    ";
										getline(std::cin, anyKey);
										goto employee_change_password;
									}

									if (new_password == record[current_emp_index].get_e_password())
									{
										std::cout << "\n\n\t\t\t\t     Change password failed!" << std::endl;
										std::cout << "\t\t\t	     New password cannot be the same with old password." << std::endl;
										std::cout << "\t\t\t             Enter any key to change password again." << std::endl;
										std::cout << "\t\t\t             Enter '0' to go back employee menu." << std::endl;
										std::cout << "\t\t\t             ";
										getline(std::cin, response);

										if (response == "0")
										{
											goto employee_menu;
										}
										else
										{
											goto employee_change_password;
										}
									}
									record[current_emp_index].updatePassword(new_password);
									std::cout << "\n\n\t\t\t\t    Change Successfully. " << std::endl;
									std::cout << "\t\t\t\t    Enter any key to back to employee menu." << std::endl;
									std::cout << "\t\t\t\t     ";
									getline(std::cin, anyKey);
									goto employee_menu;

								}

							}
							else
							{
								std::cout << "\n\n\n\t\t\t             Invalid password!" << std::endl;
								std::cout << "\t\t\t             Enter any key to change password again." << std::endl;
								std::cout << "\t\t\t             Enter '0' to go back employee menu." << std::endl;
								std::cout << "\t\t\t             ";
								getline(std::cin, response);

								if (response == "0")
								{
									goto employee_menu;
								}
								else 
								{
									goto employee_change_password;
								}
							}
						}

						//certificate of employment
						if (empKey == "4") {
							do
							{
								int doeMonth, doeYear;

								if (currentDate("MONTH") >= record[current_emp_index].get_hired_month())
								{
									doeMonth = currentDate("MONTH") - record[current_emp_index].get_hired_month();
									doeYear = currentDate("YEAR") - record[current_emp_index].get_hired_year();
								}
								else /*(current Month < month of hired)*/
								{
									doeMonth = currentDate("MONTH") + 12 - record[current_emp_index].get_hired_month();
									doeYear = currentDate("YEAR") - 1 - record[current_emp_index].get_hired_year();
								}

								std::string monthStr = (doeMonth <= 1) ? "month" : "months";
								std::string yearStr = (doeYear <= 1) ? "year" : "years";


								displayTitle("Certificate of Employment");

								std::cout << "\n\n\n\t\t\t\t       To whom it may concern:" << std::endl << std::endl;

								std::cout << "\t\t\t\t       This is to certify that " << record[current_emp_index].get_name() << " has been " << std::endl;
								std::cout << "\t\t\t\t       " << "employed with us as " << record[current_emp_index].get_position() << " for " << doeYear << std::endl;
								std::cout << "\t\t\t\t       " << yearStr << " and " << doeMonth << " " << monthStr << " from " << record[current_emp_index].get_hired_year() << " to " << currentDate("YEAR") << "." << std::endl << std::endl;


								std::cout << "\t\t\t\t       This certificate is being issued upon" << std::endl;
								std::cout << "\t\t\t\t       his/her request for whatever purposes" << std::endl;
								std::cout << "\t\t\t\t       it may serve." << std::endl;

								std::cout << "\n\n\n\t\t\t\t       Enter 'X' to print certificate of employment." << std::endl;
								std::cout << "\t\t\t\t       Enter '0' to go back to employee menu." << std::endl;
								std::cout << "\t\t\t\t       ";
								getline(std::cin, anyKey);

								if (anyKey == "X" || anyKey == "x")
								{
									displayTitle("Certificate of Employment");
									std::cout << "\n\n\n\t\t\t\t       Certificate of employment is printing......" << std::endl << std::endl;

									std::cout << "\t\t\t\t       Please check your printing device." << std::endl;

									std::cout << "\n\n\n\t\t\t\t       Enter any key to go back to employee menu." << std::endl;
									std::cout << "\t\t\t\t       ";
									getline(std::cin, anyKey);

									goto employee_menu;
								}
								else if (anyKey == "0")
								{
									goto employee_menu;
								}
								else
								{
									std::cout << "\n\n\n\t\t\t\t       Invalid input." << std::endl;
									std::cout << "\t\t\t\t       Enter only 'X' or '0'." << std::endl;
									std::cout << "\t\t\t\t       Enter any key to retry." << std::endl;
									std::cout << "\t\t\t\t       " << std::endl;
									getline(std::cin, anyKey);
								}
							} while (anyKey != "X" && anyKey != "x" && anyKey != "0");
						}
					}
					else
					{
						std::cout << "\n\t\t\t\t           ";
						print_invalid();
						std::cout << "\t\t\t\t           Enter correct number only.";
						print_retry();
						goto employee_menu;
					}
				}
				else
				{
					std::string response;
					std::cout << "\n\n\t\t\t             Invalid username or password!" << std::endl;
					std::cout << "\t\t\t             Enter any key to re-enter employee ID and password." << std::endl;
					std::cout << "\t\t\t             Enter 'F' if you forget your employee ID or login password." << std::endl;
					std::cout << "\t\t\t             Enter '0' to go back to main menu." << std::endl;
					std::cout << "\t\t\t             ";

					getline(std::cin, response);

					if (response == "0")
					{
						goto main_menu;
					}
					//forget ID/password
					else if (response == "F" || response == "f") 
					{
					forget_menu:
						std::string indexKey;
						displayTitle("Employee Login");
						std::cout << "\n\n\t\t\t               1. Forget Employee ID" << std::endl;
						std::cout << "\t\t\t               2. Forget Password" << std::endl;
						std::cout << "\n\t\t\t\t       Enter a number: ";
						getline(std::cin, indexKey);

						if(indexKey == "1")
						{
							forget_employee_ID:
							std::string ICnum;
							displayTitle("Forget Employee ID");
							std::cout << "\n\n\t\t\t\tEnter your Identity Card number	: ";
							getline(std::cin, ICnum);

							if (check_number_only(ICnum) && ICnum.size() == 12)
							{
								if (!check_ic(ICnum,record)) 
								{
									std::string result_EmpID = getID_byIC(ICnum, record);
									std::cout << "\n\t\t\t\tYour employee ID		: " << result_EmpID << std::endl;
									std::cout << "\n\t\t\t\tEnter any key to login again." << std::endl;
									std::cout << "\t\t\t\t";
									getline(std::cin, anyKey);
									goto empLoginMain;
								}
								else
								{
									std::cout << "\n\n\t\t\t\tThis Identity Card number does not exist." << std::endl;
									std::cout << "\t\t\t\tEnter '0' to go back to employee login." << std::endl;
									std::cout << "\t\t\t\tEnter any key to re-enter Identity Card Number." << std::endl;
									std::cout << "\t\t\t\t";
									getline(std::cin, anyKey);
									if (anyKey == "0")
									{
										goto empLoginMain;
									}
									else
									{
										goto forget_employee_ID;
									}
								}
							}
							else
							{
								std::cout << "\n\n\t\t\t\t     ";
								print_invalid();
								print_invalid_ic();
								std::cout << "\t\t\t\t     Enter '0' to go back to employee login." << std::endl;
								std::cout << "\t\t\t\t     Enter any key to re-enter Identity Card Number." << std::endl;
								std::cout << "\t\t\t\t     ";
								getline(std::cin, anyKey);
								if (anyKey == "0") 
								{
									goto empLoginMain;
								}
								else 
								{
									goto forget_employee_ID;
								}
							}
						}

						else if(indexKey == "2")
						{
						forget_login_password:
							std::string resetKey;

							displayTitle("Forget Password");
							std::cout << "\n\n\t\t\t               Enter your Employee ID	: ";
							getline(std::cin, id);

							if (!check_id_availability(id, record)) {
								std::cout << "\n\t\t\t               No existing ID." << std::endl;
								std::cout << "\t\t\t               Enter '0' to go back to employee login." << std::endl;
								std::cout << "\t\t\t               Enter any key to try again." << std::endl;
								std::cout << "\t\t\t               ";
								getline(std::cin, anyKey);
								if (anyKey == "0")
								{
									goto empLoginMain;
								}
								else
								{
									goto forget_login_password;
								}
							}

							//reset in nofication list cannot be reset again
							for (unsigned int i = 0 ; i < Admin::password_notification.size() ; i++)
							{
								if (id == Admin::password_notification[i].id)
								{
									std::cout << "\n\t\t\t               Already request for reset." << std::endl;
									std::cout << "\t\t\t               Enter '0' to go back to employee login." << std::endl;
									std::cout << "\t\t\t               Enter any key to try again." << std::endl;
									std::cout << "\t\t\t               ";
									getline(std::cin, anyKey);
									if (anyKey == "0")
									{
										goto empLoginMain;
									}
									else
									{
										goto forget_login_password;
									}
								}
									
							}

							std::cout << "\n\t\t\t               Request admin to reset password? (Y/N) " << std::endl;
							std::cout << "\t\t\t               ";
							getline(std::cin, resetKey);

							if (resetKey == "Y" || resetKey == "y")
							{
								Admin::addNotification(id);
								displayTitle("Forget Password");
								std::cout << "\n\n\t\t\t\t   Your request is success." << std::endl;
								std::cout << "\t\t\t\t   Kindly contact admin for admin reset password." << std::endl;
								std::cout << "\t\t\t\t   Enter any key to back to Main Menu." << std::endl;
								std::cout << "\t\t\t\t   ";

								getline(std::cin, anyKey);
								goto main_menu;
							}
							else if (resetKey == "N" || resetKey == "n") {
								goto empLoginMain;
							}
							else {
								goto forget_login_password;
							}

						}
						else
						{
							std::cout << "\n\t\t\t\t       ";
							print_invalid();
							std::cout << "\t\t\t\t       Enter only '1' or '2'." << std::endl;
							std::cout << "\t\t\t\t       Enter '0' to go back to employee login." << std::endl;
							std::cout << "\t\t\t\t       Enter any key to retry." << std::endl;
							std::cout << "\t\t\t\t       ";
							getline(std::cin, anyKey);
							if (anyKey == "0") 
							{
								goto empLoginMain;
							}
							else 
							{
								goto forget_menu;
							}
						}

					}
					else
					{
						goto empLoginMain;
					}
				}
			
			}
		
			//Employee Registration
			else if (mainKey == "3") 
			{
				std::string name;
				std::string gender;
				std::string dobDayStr, dobMonthStr, dobYearStr;
				int dobDay, dobMonth, dobYear;
				std::string ic;
				std::string nationality;
				std::string hp;
				std::string address;
				std::string dohDayStr, dohMonthStr, dohYearStr;
				int dohDay, dohMonth, dohYear;
				std::string position;

			register_name:
				displayTitle("Employee Registration");
				std::cout << "\n\t\t\t\t     Name				: ";
				getline(std::cin, name);
			
				if (check_name(name))
				{
				register_gender:
					formatCase(name);
					displayTitle("Employee Registration");
					std::cout << "\n\t\t\t\t     Name				: " << name << std::endl;
					std::cout << "\t\t\t\t     Gender(Male/Female)		: ";
					getline(std::cin, gender);

					if (check_gender(gender))
					{
					register_date_of_birth:
						formatCase(gender);
						displayTitle("Employee Registration");
						std::cout << "\n\t\t\t\t     Name				: " << name << std::endl;
						std::cout << "\t\t\t\t     Gender(Male/Female)		: " << gender << std::endl;
						std::cout << "\t\t\t\t     Date of birth -Day (DD)		: ";
						getline (std::cin, dobDayStr);
						std::cout << "\t\t\t\t		   -Month (MM)		: ";
						getline(std::cin, dobMonthStr);
						std::cout << "\t\t\t\t		   -Year (YYYY)		: ";
						getline(std::cin, dobYearStr);

						if (check_number_only(dobDayStr) && check_number_only(dobMonthStr) && check_number_only(dobYearStr) && dobDayStr.size() <= 2 && dobMonthStr.size() <= 2 && dobYearStr.size () <= 4 )
						{
							dobDay = stoi(dobDayStr);
							dobMonth = stoi(dobMonthStr);
							dobYear = stoi(dobYearStr);

							if (check_birthDate(dobDay, dobMonth, dobYear))
							{
							register_ic:
								displayTitle("Employee Registration");
								std::cout << "\n\t\t\t\t     Name				: " << name << std::endl;
								std::cout << "\t\t\t\t     Gender(Male/Female)		: " << gender << std::endl;
								std::cout << "\t\t\t\t     Date of birth -Day (DD)		: " << dobDay << std::endl;
								std::cout << "\t\t\t\t		   -Month (MM)		: " << dobMonth << std::endl;
								std::cout << "\t\t\t\t		   -Year (YYYY)		: " << dobYear << std::endl;
								std::cout << "\t\t\t\t     Identity Card Number		: ";
								getline(std::cin, ic);

								if (check_ic(ic, record))
								{
								register_nationality:
									displayTitle("Employee Registration");
									std::cout << "\n\t\t\t\t     Name				: " << name << std::endl;
									std::cout << "\t\t\t\t     Gender(Male/Female)		: " << gender << std::endl;
									std::cout << "\t\t\t\t     Date of birth -Day (DD)		: " << dobDay << std::endl;
									std::cout << "\t\t\t\t		   -Month (MM)		: " << dobMonth << std::endl;
									std::cout << "\t\t\t\t		   -Year (YYYY)		: " << dobYear << std::endl;
									std::cout << "\t\t\t\t     Identity Card Number		: " << ic << std::endl;
									std::cout << "\t\t\t\t     Nationality			: ";
									getline(std::cin, nationality);

									if (check_nationality(nationality))
									{
									register_hp:
										formatCase(nationality);
										displayTitle("Employee Registration");
										std::cout << "\n\t\t\t\t     Name				: " << name << std::endl;
										std::cout << "\t\t\t\t     Gender(Male/Female)		: " << gender << std::endl;
										std::cout << "\t\t\t\t     Date of birth -Day (DD)		: " << dobDay << std::endl;
										std::cout << "\t\t\t\t		   -Month (MM)		: " << dobMonth << std::endl;
										std::cout << "\t\t\t\t		   -Year (YYYY)		: " << dobYear << std::endl;
										std::cout << "\t\t\t\t     Identity Card Number		: " << ic << std::endl;
										std::cout << "\t\t\t\t     Nationality			: " << nationality << std::endl;
										std::cout << "\t\t\t\t     Telephone Number			: ";
										getline(std::cin, hp);

										if (check_hp(hp))
										{
										register_address:
											displayTitle("Employee Registration");
											std::cout << "\n\t\t\t\t     Name				: " << name << std::endl;
											std::cout << "\t\t\t\t     Gender(Male/Female)		: " << gender << std::endl;
											std::cout << "\t\t\t\t     Date of birth -Day (DD)		: " << dobDay << std::endl;
											std::cout << "\t\t\t\t		   -Month (MM)		: " << dobMonth << std::endl;
											std::cout << "\t\t\t\t		   -Year (YYYY)		: " << dobYear << std::endl;
											std::cout << "\t\t\t\t     Identity Card Number		: " << ic << std::endl;
											std::cout << "\t\t\t\t     Nationality			: " << nationality << std::endl;
											std::cout << "\t\t\t\t     Telephone Number			: " << hp << std::endl;
											std::cout << "\t\t\t\t     Address				: ";
											getline(std::cin, address);

											if (check_address(address))
											{
											register_date_of_hired:
												formatCase(address);
												displayTitle("Employee Registration");
												std::cout << "\n\t\t\t\t     Name				: " << name << std::endl;
												std::cout << "\t\t\t\t     Gender(Male/Female)		: " << gender << std::endl;
												std::cout << "\t\t\t\t     Date of birth -Day (DD)		: " << dobDay << std::endl;
												std::cout << "\t\t\t\t		   -Month (MM)		: " << dobMonth << std::endl;
												std::cout << "\t\t\t\t		   -Year (YYYY)		: " << dobYear << std::endl;
												std::cout << "\t\t\t\t     Identity Card Number		: " << ic << std::endl;
												std::cout << "\t\t\t\t     Nationality			: " << nationality << std::endl;
												std::cout << "\t\t\t\t     Telephone Number			: " << hp << std::endl;
												std::cout << "\t\t\t\t     Address				: " << address << std::endl;
												std::cout << "\t\t\t\t     Date of hire -Day (DD)		: ";
												getline(std::cin, dohDayStr);
												std::cout << "\t\t\t\t		   -Month (MM)		: ";
												getline(std::cin, dohMonthStr);
												std::cout << "\t\t\t\t		   -Year (YYYY)		: ";
												getline(std::cin, dohYearStr);

												if (check_number_only(dohDayStr) && check_number_only(dohMonthStr) && check_number_only(dohYearStr) && dohDayStr.size() <= 2 && dohMonthStr.size() <= 2 && dohYearStr.size() <=4 )
												{
													dohDay = stoi(dohDayStr);
													dohMonth = stoi(dohMonthStr);
													dohYear = stoi(dohYearStr);

													// check employee is above 18 years old
													if (check_hiredDate(dohDay,dohMonth,dohYear,dobYear))
													{
													register_position:
														displayTitle("Employee Registration");
														std::cout << "\n\t\t\t\t     Name				: " << name << std::endl;
														std::cout << "\t\t\t\t     Gender(Male/Female)		: " << gender << std::endl;
														std::cout << "\t\t\t\t     Date of birth -Day (DD)		: " << dobDay << std::endl;
														std::cout << "\t\t\t\t		   -Month (MM)		: " << dobMonth << std::endl;
														std::cout << "\t\t\t\t		   -Year (YYYY)		: " << dobYear << std::endl;
														std::cout << "\t\t\t\t     Identity Card Number		: " << ic << std::endl;
														std::cout << "\t\t\t\t     Nationality			: " << nationality << std::endl;
														std::cout << "\t\t\t\t     Telephone Number			: " << hp << std::endl;
														std::cout << "\t\t\t\t     Address				: " << address << std::endl;
														std::cout << "\t\t\t\t     Date of hire -Day (DD)		: " << dohDay << std::endl;
														std::cout << "\t\t\t\t		   -Month (MM)		: " << dohMonth << std::endl;
														std::cout << "\t\t\t\t		   -Year (YYYY)		: " << dohYear << std::endl;
														std::cout << "\t\t\t\t     Position				: ";
														getline(std::cin, position);

														if (check_position(position))
														{
															formatCase(position);
															displayTitle("Employee Registration");
															std::cout << "\n\t\t\t\t     Name				: " << name << std::endl;
															std::cout << "\t\t\t\t     Gender(Male/Female)		: " << gender << std::endl;
															std::cout << "\t\t\t\t     Date of birth -Day (DD)		: " << dobDay << std::endl;
															std::cout << "\t\t\t\t		   -Month (MM)		: " << dobMonth << std::endl;
															std::cout << "\t\t\t\t		   -Year (YYYY)		: " << dobYear << std::endl;
															std::cout << "\t\t\t\t     Identity Card Number		: " << ic << std::endl;
															std::cout << "\t\t\t\t     Nationality			: " << nationality << std::endl;
															std::cout << "\t\t\t\t     Telephone Number			: " << hp << std::endl;
															std::cout << "\t\t\t\t     Address				: " << address << std::endl;
															std::cout << "\t\t\t\t     Date of hire -Day (DD)		: " << dohDay << std::endl;
															std::cout << "\t\t\t\t		   -Month (MM)		: " << dohMonth << std::endl;
															std::cout << "\t\t\t\t		   -Year (YYYY)		: " << dohYear << std::endl;
															std::cout << "\t\t\t\t     Position				: " << position << std::endl;

															std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
															std::cout << "\t\t\t\t     ";
															getline(std::cin, anyKey);

															std::string registrationID;
															std::string registrationPassword;

															registrationID = generate_id(position, record);

															do 
															{
																displayTitle("Employee Registration");
																std::cout << "\n\t\t\t\t     Employee ID		: " << registrationID << std::endl;
																std::cout << "\n\t\t\t\t     Set your password		: ";
																getline(std::cin, registrationPassword);

																if (!check_password(registrationPassword)) 
																{
																	std::cout << "\n\n\t\t\t\t    ";
																	print_invalid();
																	print_invalid_password();
																	std::cout << "\n\t\t\t\t    Enter any key to re-enter the password." << std::endl;
																	std::cout << "\t\t\t\t     ";
																	getline(std::cin, anyKey);
																}
															
															} while (!check_password(registrationPassword));

															Employee newEmployee(name, gender, dobDay, dobMonth, dobYear, ic, nationality, hp, address, dohDay, dohMonth, dohYear, position, registrationID, registrationPassword);
															record.push_back(newEmployee);
															Admin::addNotification(registrationID, currentDate("DAY"), currentDate("MONTH"), currentDate("YEAR"), currentDate("HOUR"), currentDate("MINUTE"), currentDate("SECOND"));
															sort_by_id_asc(record, 0, record.size() - 1);

															std::cout << "\n\n\t\t\t\t     Successfully register." << std::endl;
															std::cout << "\t\t\t\t     Enter any key to proceed." << std::endl;
															std::cout << "\t\t\t\t     ";
															getline(std::cin, anyKey);
															goto main_menu;
														
														}
														//invalid position format
														else
														{
															print_invalid_position();
															std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
															std::cout << "\t\t\t\t     ";
															getline(std::cin, anyKey);
															goto register_position;
														}
													}
													//age warning
													else 
													{
														print_invalid_hiredDate();
														std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
														std::cout << "\t\t\t\t     ";
														getline(std::cin, anyKey);
														goto register_date_of_hired;
													}
												}
												//invalid hired date format
												else
												{
													print_invalid_hiredDate();
													std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
													std::cout << "\t\t\t\t     ";
													getline(std::cin, anyKey);
													goto register_date_of_hired;
												}
											}
											//invalid address format
											else
											{
												print_invalid_address();
												std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
												std::cout << "\t\t\t\t     ";
												getline(std::cin, anyKey);
												goto register_address;
											}
										}
										//invalid hp format
										else
										{
											print_invalid_hp();
											std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
											std::cout << "\t\t\t\t     ";
											getline(std::cin, anyKey);
											goto register_hp;
										}
									}
									//invalid nationality format
									else
									{
										print_invalid_nationality();
										std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
										std::cout << "\t\t\t\t     ";
										getline(std::cin, anyKey);
										goto register_nationality;
									}
								}
								// invalid Identity Card Number format
								else
								{
									print_invalid_ic();
									std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
									std::cout << "\t\t\t\t     ";
									getline(std::cin, anyKey);
									goto register_ic;
								}
							}
							//age warning
							else
							{
								print_invalid_birthDate();
								std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
								std::cout << "\t\t\t\t     ";
								getline(std::cin, anyKey);
								goto register_date_of_birth;
							}
						}
						// invalid birth date format
						else
						{
							print_invalid_birthDate();
							std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
							std::cout << "\t\t\t\t     ";
							getline(std::cin, anyKey);
							goto register_date_of_birth;
						}
					}
					// invalid gender format
					else
					{
						print_invalid_gender();
						std::cout << "\n\t\t\t\t     Enter any key to proceed." << std::endl;
						std::cout << "\t\t\t\t     ";
						getline(std::cin, anyKey);
						goto register_gender;
					}
				}
				// invalid name format
				else
				{
					print_invalid_name();
					std::cout << "\t\t\t\t     Enter any key to try again." << std::endl;
					getline(std::cin, anyKey);
					goto register_name;
				}

			}

			//Save and Exit
			else if (mainKey == "4") {
			save_and_exit:
				std::string exitKey;
				displayTitle("Save and Exit");
				std::cout << "\n\n\t\t       Do you want to save changes to Hospital Employee Management System? (Y/N)" << std::endl;
				std::cout << "\t\t       Enter 'X' to return to main menu." << std::endl;
				std::cout << "\t\t       ";
				getline(std::cin, exitKey);

				if (exitKey == "Y" || exitKey == "y") 
				{
					save_file(record, record_adm, "Data.txt");
					exit(0);
				}
				else if (exitKey == "N" || exitKey == "n")
				{
					exit(0);
				}
				else if (exitKey == "X" || exitKey == "x")
				{
					goto main_menu;
				}
				else {
					std::cout << "\n\t\t\t     ";
					print_invalid();
					std::cout << "\t\t\t     Enter any key to try again." << std::endl;
					std::cout << "\t\t\t     ";
					getline(std::cin, anyKey);
					goto save_and_exit;
				}
			}

		}
		else
		{
			mainMenuError:
			std::cout << "\n\t\t\t\t              ";
			print_invalid();
			std::cout << "\t\t\t\t              Enter any key to try again." << std::endl;
			std::cout << "\t\t\t\t              ";
			getline(std::cin, anyKey);
			goto main_menu;
		}
	}
}