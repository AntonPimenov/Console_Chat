#include "Chat.h"


Chat::Chat(string chat_name)
{
    if (chat_name.size() <= MAX_CHATNAME_SIZE)
    {
        chat_name_ = chat_name;
    }
}
void Chat::set_chat_name(string new_name_chat)
{
    chat_name_ = new_name_chat;
}

void Chat::menu()
{
    cout << "---==" << chat_name_ << "==---" << endl << endl;
    //cout << "Для авторизации: \n" << endl;
    unsigned short punkt = 0;
    User* current_user = Chat::authorization();
    

    if (current_user)
    {
        
        while(punkt != 5)
        {
            cout << "Выберите, что надо сделать: \n";
            cout << "1 - просмотр списка активных пользователей\n";
            cout << "2 - написать конкретному пользователю\n";
            cout << "3 - написать всем\n";
            cout << "4 - регистрация нового пользователя\n";
            cout << "5 - выход\n\n";
            cin >> punkt;
            
            switch (punkt)
            {
            case 1:
                Chat::show_users();
                break;
            case 2:
                Chat::send_message_to_you(current_user);
                break;
            case 3:
                Chat::send_message_all(current_user);
                break;
            case 4:
                Chat::registration();
                break;        
            case 5: 
                cout << "Выход из чата!";
                break;
           
            }
        } 
        
    }
    
}

User* Chat::authorization()
{
    User* temp;
    string input;
    while (input != "q")
    {
        cout << "---АВТОРИЗАЦИЯ---\n\n";
        cout << "Введите логин или введите q для выхода: \n";
        cin >> input;
        if (input == "q") return 0; 
        //проверка наличие пользавателя в базе

        temp = user_array_.getUserByName(input);
        if (temp)
        {
            cout << "Введите пароль: \n";
            for (int i = 0; i < 3; ++i)
            {
                cin >> input;
                if (temp->password_ == input)
                {
                    cout << "Авторизация успешна!\n";
                    return temp;
                }
                cout << "Пароль неверный, осталось " << 2 - i << " попыток.\n";
            }
            cout << "Пароль неверный!\n";
            return 0;
        }
        //если не прошли авторизацию, предлогаем зарегистрироваться
        cout << "Такого пользователя нет!\n";
        cout << "Для регистрации введите 'yes', для выхода любую клавишу\n";
        cin >> input;
        if (input == "yes") Chat::registration();
        else return 0;
    }
    return 0;
}
//регистрация пользователя
void Chat::registration()
{
    cout << "---Регистрация---\n\n";
    //
    string name, password; 
    while (name != "q")
    {
        cout << "Придумайте логин: \n";
        //cout << "---Для выхода введите q---\n";
        cin >> name;
        if (user_array_.getUserByName(name))
        {
            cout << "Такой пользователь есть!\n";
        }
        else break;
    } 
    cout << "Придумайте пароль: \n";
    cin >> password;
    User* new_user = new User(name, password);
    user_array_.add(new_user);
}
//добавление нового пользователя в чат
void Chat::add_user(User* new_user)
{
	for (int i = 0; i < Chat::user_array_.getLength(); i++)
	{
		if (Chat::user_array_ [i] == new_user) return;
	}
	user_array_.add(new_user);
}
//вывод списка пользователей
void Chat::show_users()
{
    cout << "Текущие пользователи: \n";
    for (int i = 0; i < user_array_.getLength(); ++i)
    {
        cout << Chat::user_array_[i]->username_ << endl;
    }
    cout << endl;
    return;
}
//отправка сообщения всем пользователям
void Chat::send_message_all(User* current_user)
{
    cout << "Введите сообщение: \n\n";
    string message;
    cin >> message;
    int size = user_array_.getLength();
    if (message.size() <= MAX_MESSAGE_SIZE)
    {
        cout << endl;
        for (int i = 0; i < size; ++i)
        {
            if (Chat::user_array_[i] != current_user)
            {
                Chat::user_array_[i]->show_message(message);
            }

        }
    }
    else
    {
        cout << "Длина сообщения не должна превышать " << MAX_MESSAGE_SIZE << " знаков!\n\n";
    }
    return;
}

//отправка сообщения конкретному пользователю
void Chat::send_message_to_you(User* current_user)
{
    string second_user_name;
    cout << "Для выхода нажмите q.\n\n";
    while(second_user_name != "q")
    {
        cout << "Введите имя пользователя: ";
        cin >> second_user_name;
        if (current_user->username_ != second_user_name)
        {
            User* second_user = user_array_.getUserByName(second_user_name);
            if (second_user)
            {
                cout << "Введите сообщение для пользователя: \n";
                string message;
                cin >> message;
                if(message.size() <= MAX_MESSAGE_SIZE)
                {
                    second_user->show_message(message);
                }
                else
                {
                    cout << "Длина не должна превышать " << MAX_MESSAGE_SIZE << " знаков!\n\n";
                }
            }
            else
            {
                cout << "Пользователь отсутствет в чате\n\n";
            }
            return;
        }
    }
}


