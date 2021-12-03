#pragma once
#include "Employee.h"

class Admin
{
private:
	friend class boost::serialization::access;
	std::string a_username;
	std::string a_password;
	int created_day;
	int created_month;
	int created_year;

	struct Notification
	{
		std::string id;
		std::string password_reset;
		std::string updatedItem;
		int day, month, year;
		int hour, min, sec;

	private:
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive& a, const unsigned version)
		{
			a& id& password_reset& updatedItem&
				day& month& year& hour& min& sec;
		}
	};

	template<class Archive>
	void serialize(Archive& a, const unsigned version)
	{
		a & a_username & a_password & created_day & created_month & created_year;
	}

public:
	static std::vector <Notification> password_notification;
	static std::vector <Notification> update_notification;
	static std::vector <Notification> register_notification;

	//Default constructor
	Admin();

	//Overload constructor
	Admin(std::string username, std::string password);

	//Copy constructor
	Admin(const Admin& e);

	//Destructor
	~Admin();

	//Setters
	void set_a_username(std::string username);
	void set_a_password(std::string password); 

	//Getters
	std::string get_a_username() const;
	std::string get_a_password() const;
	int get_created_day() const;
	int get_created_month() const;
	int get_created_year() const;
	static std::string get_notification_id(int index);
	static int get_unread_password();

	//Methods
	static void displayList(std::vector <Admin> record);

	static void addNotification(std::string id);
	static void addNotification(std::string id, std::string updatedItem);
	static void addNotification(std::string id, int day, int month, int year, int hour, int min, int sec);
	static void notificationList_password();
	static void notificationList_update();
	static void notificationList_register();
	
	static void removeNotification(std::string id);
	static void removeNotification_password(std::string id);
	static void removeNotification_update(int index);
	static void removeNotification_register(int index);

	static bool check_password_reset_availability(int index);
	static void resetPassword(int index, std::vector <Employee>& record);
};





