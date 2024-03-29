#include <iostream>
#include <string>


class str_oper {
private:
    std::string str; 

public:

    str_oper(std::string s) : str(s) {}

    int findLength() {
        int length = 0;
        for (char c : str) {
            length++;
        }
        return length;
    }
    
    std::string reverse() {
        std::string reverseStr;
        for (int i = str.length() - 1; i >= 0; i--) {
            reverseStr.push_back(str[i]);
        }
        return reverseStr;
    }

    std::string concatenateStrings(std::string other_String) {
        std::string concatenatedStr = str;
        for (char c : other_String) {
            concatenatedStr.push_back(c);
        }
        return concatenatedStr;
    }

    bool compareStrings(std::string other_String) {
        if (str.length() != other_String.length())
            return false;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != other_String[i])
                return false;
        }
        return true;
    }
};

int main() {
    std::string userInput;
    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);

    str_oper strOp(userInput);
    std::cout << "Length of string: " << strOp.findLength() << std::endl;
    std::cout << "Reverse of string: " << strOp.reverse() << std::endl;
    
    std::string otherString;
    std::cout << "Enter another string for concatenation: ";
    std::getline(std::cin, otherString);
    std::cout << "Concatenated string: " << strOp.concatenateStrings(otherString) << std::endl;

    std::string compareString;
    std::cout << "Enter a string for comparison: ";
    std::getline(std::cin, compareString);
    std::cout << "Comparison result: " << strOp.compareStrings(compareString) << std::endl;

    return 0;
}
