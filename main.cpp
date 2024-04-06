#include <iostream>
#include "User.h"
#include "Chat.h"


int main()
{
    User Anton("anton", "123");
    cout << Anton.get_username() << endl;

    Chat chat("chat");

    chat.menu();
    
}
