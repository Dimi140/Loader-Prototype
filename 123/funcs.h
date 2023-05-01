#pragma once
#include "auth.hpp"

using std::string;

string f_login(KeyAuth::api app);

string f_keylogin(KeyAuth::api app);

string f_register(KeyAuth::api app);

string menu(string log_name);

void print_userdata(KeyAuth::api app);

//TIME 

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);