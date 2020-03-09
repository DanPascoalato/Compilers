#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_math_operator(char);
bool is_decimal_symbol(char);
bool is_negative_symbol(char);
bool is_whitespace_or_eol(char);
bool is_sum_operator(char);
vector<string> parse_numbers_from(string);


bool is_sum_operator(char chr);

int main() {
    string input = "2 + 6 + 5";
    string buffer = "";
    long acc = 0;


    for(int i = 0; i<input.length(); i++){
        char chr = input.at(i);

        if(isdigit(chr)){
            buffer += chr;
        } else if(is_math_operator(chr)){
            acc += stoi(buffer);
        }
    }

}


vector<string> parse_numbers_from(string message) {
    vector<string> numbers;
    string buffer;
    bool skip_until_whitespace = false, can_read_decimal = true, can_read_negative = true;

    for (int i = 0; i <= message.length(); i++)
    {
        char chr = message[i];

        if (skip_until_whitespace) {
            if (is_whitespace_or_eol(chr)) {
                skip_until_whitespace = false;
                can_read_decimal = can_read_negative = true;
                buffer = "";
            }
            continue;
        }

        if (isdigit(chr)) {
            buffer += chr;
            can_read_negative = false;
        }
        else if (is_decimal_symbol(chr) && can_read_decimal) {
            if (buffer == "") {
                buffer = "0";
            }
            buffer += chr;
            can_read_decimal = false;
            can_read_negative = false;
        }
        else if (is_negative_symbol(chr) && can_read_negative) {
            buffer = chr;
            can_read_negative = false;
        }
        else if (is_whitespace_or_eol(chr) or is_sum_operator(chr)) {
            if (buffer != "") {
                numbers.push_back(buffer);
                buffer = "";
            }
            can_read_decimal = can_read_negative = true;
        }
        else {
            skip_until_whitespace = true;
            buffer = "";
        }
    }

    return numbers;
}

bool is_sum_operator(char chr) {
    return chr == '+';
}


bool is_decimal_symbol(char chr) {
    return chr == '.';
}

bool is_negative_symbol (char chr) {
    return chr == '-';
}

bool is_whitespace_or_eol(char chr) {
    return chr == ' ' or chr == '\0';
}

bool is_math_operator(char chr){
    return chr == '+';
}