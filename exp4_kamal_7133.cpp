#include <iostream>
#include <string>

class Number{
private:
    int decimalNumber;

public:

    Number(int decimalNumber) {
        this->decimalNumber = decimalNumber;
}

    std::string toBinary() {
        int num = decimalNumber;
        std::string binary = "";
        while (num > 0) {
            binary = std::to_string(num % 2) + binary;
            num /= 2;
        }
        return binary;
    }
};

int main() {
	
    Number num(10);
    std::cout << "Binary representation of 10: " << num.toBinary() << std::endl;
    return 0;
}
