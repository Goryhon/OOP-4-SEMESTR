#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "logger.h"
#include "csv.h"
#include "dict.h"

using namespace std;

class Auth {
private:
    dict<string> users;
    string csv_path;
    ILogger *logger;
    csv parser;

    bool is_name_exist(const string &username);

    bool is_password_correct(const string &username, const string &password);

    void update_DB_file();

    string register_ask_username();

    string register_ask_password();

    string login_ask_username();

    string login_ask_password(const string &username);

public:

    Auth(ILogger *logger, const string &csv_path);

    void register_user();

    void log_in_user();
};


Auth createBasicAuthorizer(const string& csv_path);

string hashFunction(const string &key);

dict<string> convert_csv_to_dict(csv csv_parser);