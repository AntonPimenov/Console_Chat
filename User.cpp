#include "User.h"

User::User() {}

User::User(string username, string password) : username_(username), password_(password){}

User::~User() {}

void User::set_username(string new_name)
{
    username_ = new_name;
}

void User::set_password(string new_pass)
{
    password_ = new_pass;
}

void User::print_user()
{
    cout << "User name: " << username_ << endl;
}

void User::show_message(string message)
{
    cout << message << endl;
}

string User::get_username() const
{
    return username_;
}

string User::get_pass() const
{
    return password_;
}

