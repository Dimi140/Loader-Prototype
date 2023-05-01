#include "funcs.h"

using std::string;
using std::cin; 
using std::cout; 

string f_login(KeyAuth::api app) {
	string temp_name = "Dimi140";
	string temp_pass = "xXDimi140Xx";
	
	system("cls");
	cout << "Name: ";
	//cin >> temp_name; 
	cout << "\nPassword: ";
	//cin >> temp_pass;
	cout << "\n";
	app.login(temp_name , temp_pass);

	if (app.data.success) {
		system("cls");
		cout << "Success: " << app.data.message << "\n";
		cout << "Procceeding... \n";
		Sleep(3000);
	}
	else
	{
		system("cls");
		cout << "Failed: " << app.data.message << "\n";
		Sleep(3000);
		exit(0);
	}

		return app.data.username; 
}

string menu(string log_name) {

	system("cls");

	std::string selection = "";

	std::cout << "===========\n";
	std::cout << "LOGGED IN AS: " << log_name << "\n";
	std::cout << "===========\n";
	std::cout << "(1) - LOGIN\n";
	std::cout << "(2) - REGISTER\n";
	std::cout << "(3) - QUIT\n";
	std::cout << "===========\n";

	std::cin >> selection;

	return selection;
}

string f_register(KeyAuth::api app) {

	std::string reg_name, reg_pass, reg_key, reg_mail;

	system("cls");
	std::cout << "Name: ";
	std::cin >> reg_name;
	std::cout << "\nPassword: ";
	std::cin >> reg_pass;
	std::cout << "\nKey: ";
	std::cin >> reg_key;
	std::cout << "\n E-Mail: ";
	std::cin >> reg_mail;

	//register
	app.regstr(reg_name, reg_pass, reg_key, reg_mail);

	//response
	if (app.data.success) {
		system("cls");
		cout << "Success: " << app.data.message << "\n";
		cout << "Procceeding... \n";
		Sleep(3000);
	}
	else
	{
		system("cls");
		cout << "Failed: " << app.data.message << "\n";
		Sleep(3000);
		exit(0);
	}

	return reg_name; 

}

string f_keylogin(KeyAuth::api app) {

	return "hello";
}

void print_userdata(KeyAuth::api app) {

	system("cls");

	for (int i = 0; i < 3; i++) {

		cout << "Expires: " << tm_to_readable_time(timet_to_tm(string_to_timet(app.sub.expiry))) << "\n";

		Sleep(1000);
	}

		Sleep(100000);

}

// TIME FUNCTIONS 

std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}