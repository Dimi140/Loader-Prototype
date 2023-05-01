#include <iostream>
#include <string>
#include "funcs.h"
#include <Windows.h>

using namespace KeyAuth;
#define color(x) SetConsoleTextAttribute(hConsole, x);

std::string name = "Test"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = ""; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = ""; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/";// change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);

std::string log_name = "/";

int i_selection = 0;

int main() {

	SetConsoleTitleA("CHEAT LOADER");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	color(10);

	KeyAuthApp.init();

	while (i_selection != 3) {

		i_selection = std::stoi(menu(log_name));

		if (i_selection == 1) {
			// LOGIN 
			log_name = f_login(KeyAuthApp);

		}
		else if (i_selection == 2) {
			//REGISTER
			log_name = f_register(KeyAuthApp);

		}
		else if (i_selection == 3) 
		{
			exit(0);
		}
		else if (i_selection == 4) {
			print_userdata(KeyAuthApp);
		}

	}

	return 0; 
}
