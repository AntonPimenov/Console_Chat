#pragma once
#include "UserArray.h"
#include <iostream>
#include <string>

#define MAX_CHATNAME_SIZE 20
#define MAX_MESSAGE_SIZE 30
using std::cout;
using std::cin;
using std::endl;

class Chat
{
    private:

    string chat_name_;              //название чата
    UserArray<User*> user_array_;   //массив пользователей

    public:
        Chat(string chat_name);     //конструктор чата
        void set_chat_name(string new_name_chat);   //изменение название чата
        void menu();
        User* authorization();      //авторизация пользователя
        void registration();        //регистрация пользователя
        void add_user(User* new_user);      //добавление нового пользователя в чат
        void show_users();          //вывод списка пользователей
        void send_message_all(User* current_user);  //отправка сообщения всем
        void send_message_to_you(User* current_user);   //отправка сообщения конкретному пользователю
        
};