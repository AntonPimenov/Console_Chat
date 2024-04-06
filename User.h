#pragma once
#include <iostream>
#include <string>

#define MAX_USERNAME 30
#define MAX_PASSWORD 12

using std::string;
using std::cout;
using std::endl;

class User
{
    public:       
        //конструкторы
        User();
        User(string username, string password);
        //деструктор    
        ~User();

        void set_username(string new_name);     //функция изменения логина 
        void set_password(string new_pass);     //функция изменения пароля
        void print_user();                      //функция вывода имени пользователя
        void show_message(string message);      //функция вывода сообщения
        string get_username() const;
        string get_pass() const;

    
        string username_;    //переменная для логина пользователя
        string password_;    //переменная для пароля пользователя


};
