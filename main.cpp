//I would like my extra credit to be the 20 extra points towards my quiz and exam grades.
#include <iostream>
#include <iomanip>
#include <string>
//These are the dependencies that will be utilized throughout the program
using namespace std;
//This namespace will simplify many commands throughout the program.
int conv_str_int(const char& x) {
    switch(x) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 111;
    }
// This function will read a character and return that digit if that character is a digit. Otherwise, it will return 111 as an error state.
};

double extractNumeric(const string& str) {
    int length = str.length();
    int dec_pos = -1;
    float numeric = 0;
    bool invalid = false;
    bool negative = false;
    int dec_count = 0;
//These variables will be used throughout the remainder of the function
    for (int a = 0; a < length; a++) {
        if (str[a] == '.') {
            dec_count++;
        }
//This will keep an active count of how many decimal points are in the string
        if (a == 0) {
            if (str[a] == '-') {
                negative = true;
            } else if (str[a] == '+') {
                continue;
            } else if (conv_str_int(str[a]) == 111) {
                invalid = true;
            }
//For the first index in the string, this will check if the string is positive, negative, or if the char is valid.
        } else {
            if (str[a] == '+' || str[a] == '-') {
                invalid = true;
            }
            if (conv_str_int(str[a]) == 111 && str[a] != '.') {
                invalid = true;
            }
//After the first index, the program will check for valid integers for each char.
        }
    }

    if (dec_count > 1) {
        invalid = true;
    }
//If there is more than 2 decimal points, invalid will be set to true

    if (invalid) {
        return -999999.99;
    }
//If the string contains invalid characters, the program will return -999999.99

    if (dec_count > 0) {
        for (int i = 0; i < length; i++) {
            if (str[i] == '.') {
                dec_pos = i;
                break;
            }
        }
    }
//This will find the decimal point in the string and record its location

    for (int i = (negative || str[0] == '+' ? 1 : 0); i < (dec_pos == -1 ? length : dec_pos); i++) {
        numeric = numeric * 10 + conv_str_int(str[i]);
    }
//The program will convert the string into an integer by going through each index, converting and adding that to numeric, and then multiplying numeric by 10.
//If there is a decimal point, the program will do this up until the decimal point. If there is a + or - in the first index, the program will skip that index.
    if (dec_pos != -1) {
        double pow_ten = 0.1;
        for (int i = dec_pos + 1; i < length; i++) {
            numeric += conv_str_int(str[i]) * pow_ten;
            pow_ten /= 10;
        }
    }
//The program will convert the string into an integer by going through each index, converting and adding that to numeric, and then dividinging numeric by 10.

    if (negative) {
        numeric *= -1;
//If negative if true, numeric will be multiplied by -1
    }
    return numeric;
//If Invalid is false, then the function will return numeric
}

int main() {
    string input;
//This variable will be used throughout the remainder of the main function
    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;
//This will print to the user what to do and get input from the user
        if (input == "END") {
            break;
        }
//If the user types in END, the program will end
        double number = extractNumeric(input);
//If the user types in a string other than END, this function will call and return a float.
        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
//If number is not equal to -999999.99, the program will print this statement with the number to the user
        } else {
            cout << "The input is invalid." << endl;
//If number is equal to -999999.99, the program will print that the string was invalid.
        }
    }
    return 0;
//This is the return value of the main function
}
