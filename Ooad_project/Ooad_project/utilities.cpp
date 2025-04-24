#ifndef utilities_cpp
#define utilities_cpp

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>
#include <random>
#include <cstring>

using namespace std;

typedef unsigned long long int ulli;

namespace Utilities {

    struct my_exception {
        string message;
        my_exception(string error) : message(error) {};
        string what() {
            return message;
        }
    };

    bool check_email_gmail(char input[]) {
        char* ptr = strstr(input, "@gmail.com");  // check for Gmail domain
        return (ptr != nullptr);
    }

    bool verify_email(char input[]) {
        if (!check_email_gmail(input)) {
            cout << "> This email is not a valid Gmail address!\n";
            return false;
        }
        return true;
    }

    string get_email() {
        string email;
        getline(cin, email);

        char input[100];
        copy(email.begin(), email.end(), input);
        input[email.length()] = '\0';

        string first_part;
        int second_part_length = 0;
        int count_at = 0, count_dot = 0;

        for (char temp : email) {
            if (temp == '@') count_at++;
            if (count_at == 0) first_part.push_back(temp);
            if (count_at != 0) {
                second_part_length++;
                if (temp == '.') count_dot++;
            }
        }

        if (second_part_length > 29 || count_dot == 0 || count_at != 1) {
            cout << "> Not a valid email\n";
            return "";
        }

        if (!verify_email(input)) {
            return "";
        }

        return first_part;
    }

    // ✅ FIXED: Now returns void to avoid crash
    void encrypt(char str[]) {
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = str[i] - 27;
        }
    }

    void convert(string str, char data[]) {
        copy(str.begin(), str.end(), data);
        data[str.size()] = '\0';
    }

    string valid_phone_size(string phone_number) {
        if (phone_number.size() != 10) {
            cout << "> Phone number must be exactly 10 digits\n";
            return "";
        }
        return phone_number;
    }

    string all_digits(string phone_number) {
        for (char ch : phone_number) {
            if (!(ch >= '0' && ch <= '9')) {
                cout << "> It must only contain digits.\n";
                return "";
            }
        }
        return phone_number;
    }

    string ulli_to_string(ulli number) {
        if (number == 0) return "0";

        string answer;
        while (number > 0) {
            answer.insert(answer.begin(), (number % 10) + '0');
            number /= 10;
        }
        return answer;
    }

    void loading(int x) {
        for (int i = 0; i <= 100; i += 2) {
            cout << "\r> Loading";
            for (int j = 0; j <= 100; j += 4) {
                cout << (j <= i ? " ." : "  ");
            }
            cout << " " << i << "%";
            for (int j = 0; j < x * 1000000; j++);
            cout.flush();
        }
        cout << "\n";
    }

    void logging_out(int x) {
        for (int i = 0; i <= 100; i += 2) {
            cout << "\r> Logging out";
            for (int j = 0; j <= 100; j += 4) {
                cout << (j <= i ? " ." : "  ");
            }
            cout << " " << i << "%";
            for (int j = 0; j < x * 1000000; j++);
            cout.flush();
        }
        cout << "\n";
    }

    string generate_otp() {
        random_device rd;
        mt19937 engine(rd());
        uniform_int_distribution<int> dist(0, 9);
        string otp;
        for (int i = 0; i < 6; i++) {
            otp.push_back(dist(engine) + '0');
        }
        return otp;
    }

}; // namespace Utilities

#endif
