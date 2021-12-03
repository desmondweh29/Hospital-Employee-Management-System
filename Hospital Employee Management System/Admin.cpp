#include "Admin.h"
#include "Other functions.h"

std::vector <Admin::Notification> Admin::password_notification;
std::vector <Admin::Notification> Admin::update_notification;
std::vector <Admin::Notification> Admin::register_notification;

Admin::Admin()
{
	a_username = "";
	a_password = "";
	created_day = 0;
	created_month = 0;
	created_year = 0;
}

Admin::Admin(std::string username, std::string password)
{
	a_username = username;
	a_password = password;
	created_day = currentDate("DAY");
	created_month = currentDate("MONTH");
	created_year = currentDate("YEAR");
}

Admin::Admin(const Admin& a)
{
    a_username = a.a_username;
    a_password = a.a_password;
    created_day = a.created_day;
    created_month = a.created_month;
    created_year = a.created_year;
}

Admin::~Admin() {}

void Admin::set_a_username(std::string username) 
{
    a_username = username;
}

void Admin::set_a_password(std::string password)
{
    a_password = password;
}

std::string Admin::get_a_username() const
{
	return a_username;
}

std::string Admin::get_a_password() const
{
	return a_password;
}

int Admin::get_created_day() const
{
	return created_day;
}

int Admin::get_created_month() const
{
	return created_month;
}

int Admin::get_created_year() const
{
	return created_year;
}

std::string Admin::get_notification_id(int index)
{
    return password_notification[index - 1].id;
}

int Admin::get_unread_password()
{
    int notificationUnread = 0;
    for (unsigned int i = 0; i < password_notification.size(); i++)
    {
        if (password_notification[i].password_reset == "-")
        {
            notificationUnread++;
        }
    }
    return notificationUnread;
}

void Admin::displayList(std::vector <Admin> record)
{
	std::cout << "\t\t\t\t    No" << std::setw(20) << "Admin username\t" << std::setw(18) << "Date created" << std::endl;
	for (unsigned int i = 0; i < record.size(); i++)
	{
		std::cout << "\t\t\t\t    [" << std::setw(2) << i + 1 << "]" << std::setw(20) << record[i].get_a_username() << "\t" << std::setw(10) << record[i].get_created_day() << "/" << record[i].get_created_month() << "/" << record[i].get_created_year() << std::endl;
	} return;
}

void Admin::addNotification(std::string id)
{
    Notification notice;
    notice.id = id;
    notice.password_reset = "-";
    password_notification.push_back(notice);
}

void Admin::addNotification(std::string id, std::string updatedItem)
{
    Notification notice;
    notice.id = id;
    notice.updatedItem = updatedItem;
    update_notification.push_back(notice);
}

void Admin::addNotification(std::string id, int day, int month, int year, int hour, int min, int sec)
{
    Notification notice;
    notice.id = id;
    notice.day = day;
    notice.month = month;
    notice.year = year;
    notice.hour = hour;
    notice.min = min;
    notice.sec = sec;
    register_notification.push_back(notice);
}

void Admin::notificationList_password() 
{
    std::cout << "\t\t\t\t     ";
    std::cout << "No" << std::setw(20) << "Employee ID" << "\t" << std::setw(15) << "Reset password" << std::endl;
    for (unsigned int i = 0; i < password_notification.size(); i++)
    {
        std::cout << "\t\t\t\t     ";
        std::cout << "[" << std::setw(2) << i + 1 << "]" << std::setw(15) << password_notification[i].id << "\t" << std::setw(15) << password_notification[i].password_reset << std::endl;
    } return;
}

void Admin::notificationList_update() 
{
    std::cout << "\t\t\t\t     ";
    std::cout << "No" << std::setw(20) << "Employee ID" << std::setw(20) << "Updated field" << std::endl;
    for (unsigned int i = 0; i < update_notification.size(); i++)
    {
        std::cout << "\t\t\t\t     ";
        std::cout << "[" << std::setw(2) << i + 1 << "]" << std::setw(15) << update_notification[i].id << "\t  " << std::setw(20) << update_notification[i].updatedItem << std::endl;
    } return;
}

void Admin::notificationList_register() 
{
    std::cout << "\t\t\t\t     ";
    std::cout << "No" << std::setw(20) << "Employee ID" << std::setw(24) << "Register date & time" << std::endl;
    for (unsigned int i = 0; i < register_notification.size(); i++)
    {
        std::cout << "\t\t\t\t     ";
        std::cout << "[" << std::setw(2) << i + 1 << "]" << std::setw(15) << register_notification[i].id <<"\t   ";
        std::cout << register_notification[i].day << "/" << register_notification[i].month << "/" << register_notification[i].year;
        std::cout << std::setw(4) << register_notification[i].hour << ":" << register_notification[i].min << ":" << register_notification[i].sec << std::endl;
    } return;
}

void Admin::removeNotification(std::string id) 
{
    for (unsigned int i = 0; i < password_notification.size(); i++)
    {
        if (id == password_notification[i].id) {
            password_notification.erase(password_notification.begin() + i);
        }
    }

    int vecsize = update_notification.size();
    for (unsigned int i = 0; i < vecsize; i++)
    {
        if (id == update_notification[i].id) {
            update_notification.erase(update_notification.begin() + i);
            i = 0;
            vecsize = update_notification.size();
        }
    }

    for (unsigned int i = 0; i < register_notification.size(); i++)
    {
        if (id == register_notification[i].id) {
            register_notification.erase(register_notification.begin() + i);
        }
    }
}

void Admin::removeNotification_password(std::string id)
{
    for (unsigned int i = 0; i < password_notification.size(); i++)
    {
        if (id == password_notification[i].id && password_notification[i].password_reset != "-") {
            password_notification.erase(password_notification.begin() + i);
            return;
        }
    }
}

void Admin::removeNotification_update(int index)
{
    update_notification.erase(update_notification.begin() + (index - 1));
}

void Admin::removeNotification_register(int index)
{
    register_notification.erase(register_notification.begin() + (index - 1));
}

bool Admin::check_password_reset_availability(int index)
{
    return (password_notification[index - 1].password_reset == "-");
}

void Admin::resetPassword(int index, std::vector <Employee>& record)
{
    password_notification[index - 1].password_reset = generate_password();
    sort_by_id_asc(record, 0, record.size() - 1);
    int actual_index = search_by_id(record, (password_notification[index - 1].id));

    try
    {
        record.at(actual_index).set_e_password(password_notification[index - 1].password_reset);
    }
    catch (const std::out_of_range& oor)
    {
        password_notification[index - 1].password_reset = "-";
        std::cerr << "Vector out of range error: " << oor.what() << std::endl;
        std::cout << "Failed to reset password." << std::endl;
        return;
    }
}