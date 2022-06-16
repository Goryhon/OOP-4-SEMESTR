#include "authorizer.h"

Auth::Auth(ILogger *logger, const string &csv_path) {
    this->logger = logger;
    this->csv_path = csv_path;
    this->parser = csv();
    this->parser.parse(csv_path);
    this->users = convert_csv_to_dict(this->parser);
}

bool Auth::is_name_exist(const string &username) {
    return this->users.has(username);
}

bool Auth::is_password_correct(const string &username, const string &password) {
    return this->users[username] == hashFunction(password);
}

void Auth::register_user() {
    this->logger->info("Registering a user");

    string username = register_ask_username();
    string password = register_ask_password();

    this->users[username] = hashFunction(password);
    this->update_DB_file();

    this->logger->info("Registration successful");
}

void Auth::log_in_user() {
    this->logger->info("Logging in a user");

    string username = login_ask_username();
    string password = login_ask_password(username);

    this->logger->info("Logged in successfully");

}

string hashFunction(const string &key) {
    long long N = 53245167551;
    double A = 0.6180339887;
    long long hashCode = 0;
    for (char ch: key)
        hashCode += ch;
    hashCode = N * fmod(hashCode * A, 1);
    return std::to_string(hashCode);
}

void Auth::update_DB_file() {
    string* keys = users.get_keys();
    string** table = new string*[users.length()];
    for (int i = 0; i < users.length(); i++) {
        table[i] = new string[2];
        table[i][0] = keys[i];
        table[i][1] = users[keys[i]];
    }
    this->parser.write_to_file(this->csv_path, table, users.length(), 2);
}

string Auth::register_ask_username() {
    string username;
    bool username_success = false;
    while (!username_success) {
        cout << "Enter your username:\n";
        getline(cin, username);

        if (!this->is_name_exist(username))
            username_success = true;
        else
            this->logger->error("This username is already taken");
    }
    return username;
}

string Auth::register_ask_password() {
    string password1;
    string password2;
    bool password_success = false;
    while (!password_success) {
        cout << "Password:\n";
        getline(cin, password1);
        cout << "Repeat password:\n";
        getline(cin, password2);

        if (password1 == password2)
            password_success = true;
        else
            this->logger->error("Passwords do not match");
    }
    return password1;
}

string Auth::login_ask_username() {
    string username;
    bool username_success = false;
    while (!username_success) {
        cout << "Username:\n";
        getline(cin, username);

        if (this->is_name_exist(username))
            username_success = true;
        else
            this->logger->error("This username does not exist");
    }
    return username;
}

string Auth::login_ask_password(const string &username) {
    string password;
    bool password_success = false;
    while (!password_success) {
        cout << "Password:\n";
        getline(cin, password);

        if (this->is_password_correct(username, password))
            password_success = true;
        else {
            this->logger->error("Password is incorrect");
        }
    }
    return password;
}

dict<string> convert_csv_to_dict(csv csv_parser) {
    dict<string> res;
    for (int i = 0; i < csv_parser.length(); i++) {
        res[csv_parser.arr[i][0]] = csv_parser.arr[i][1];
    }
    return res;
}

Auth createBasicAuthorizer(const string& csv_path) {
    LoggerCMDFact logger_fact;
    auto logger = logger_fact.create();
    return Auth(logger, csv_path);
}