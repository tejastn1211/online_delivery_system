#ifndef shopkeeper_cpp
#define shopkeeper_cpp

#include "shop.cpp" 
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream> 
#include <cstring>

using namespace std;

typedef unsigned long long ulli;

class Shopkeeper : public User 
{
public:

    char shop_name[51];
    char shop_category[51];
    ulli account_name;
    char IFSC_code[51];
    ulli holiday_list[366];
    ulli pending_amount;
    ulli shop_id;

    bool login(string password)
    {
        char string_password[51];
        strncpy(string_password, password.c_str(), sizeof(string_password) - 1);
        string_password[sizeof(string_password) - 1] = '\0';

        Utilities::encrypt(string_password);
        return strcmp(string_password, Shopkeeper::password) == 0;
    }

    void set_password(string password)
    {
        strncpy(Shopkeeper::password, password.c_str(), sizeof(Shopkeeper::password) - 1);
        Shopkeeper::password[sizeof(Shopkeeper::password) - 1] = '\0';
        Utilities::encrypt(Shopkeeper::password);
    }

    Shopkeeper(ulli id = 0)
    {
        pending_amount = 0;
        shop_id = id;
    }

    int get_details(string email)
    {
        Utilities::convert(email, Shopkeeper::email);

        cout << "> Enter your name :: ";
        string name;
        getline(cin >> ws, name);
        if (name.empty())
            return -1;
        Utilities::convert(name, Shopkeeper::name);

        cout << "> Enter shop name :: ";
        string shp_nme;
        getline(cin, shp_nme);
        Utilities::convert(shp_nme, Shopkeeper::shop_name);

        cout << "> Enter shop category :: ";
        string shop_category;
        getline(cin, shop_category);
        Utilities::convert(shop_category, Shopkeeper::shop_category);

        cout << "> Enter the password for your account\n";
        cout << "> It must contain at least 1 number, capital letter, small letter and a special character. Length of password must also be >= 8\n";
        cout << "> Password :: ";

        string password = Terminal::get_password(8);
        if (password.length() < 8)
            return -1;
        set_password(password);

        cout << "> Enter your Account Number (must be a number) :: ";
        cin >> account_name;

        string ifsc;
        cout << "> Enter the IFSC code of your bank :: ";
        getline(cin >> ws, ifsc);
        Utilities::convert(ifsc, Shopkeeper::IFSC_code);

        // Moved phone input to end
        cout << "> Enter your phone number (without country code) :: ";
        string phone_number;
        getline(cin, phone_number);

        phone_number = Utilities::all_digits(phone_number);

        if (phone_number.length() != 10) {
            cout << "> Invalid phone number. It must be exactly 10 digits.\n";
            return -1;
        }

        phone_number = "+91" + phone_number;
        Utilities::convert(phone_number, Shopkeeper::contact_number);

        return 0;
    }
};

#endif
