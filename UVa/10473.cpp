#include <iostream>
#include <string>

int convertToDec(const std::string &input){
    int number = 0;
    for(int i = input.length() - 1, power = 1 ; i > 1 ; --i, power *= 16){
        if(input[i] >= 'A' && input[i] <= 'F'){
            number += (input[i] - 'A' + 10) * power;
        } else{
            number += (input[i] - '0') * power;
        }
    }
    return number;
}

void convertToHex(int number, int base = 16){
    if(!number){
        std::cout << "0x";
        return;
    }
    convertToHex(number / base);
    int rem = number % base;
    if(rem > 9){
        std::cout << char(rem - 10 + 'A');
    } else{
        std::cout << rem;
    }
}

int main(int argc, char const *argv[])
{
    std::string input;
    while(std::cin >> input){
        if(input[0] == '-') break;
        if(input[0] == '0' && input[1] == 'x'){
            // hex number
            std::cout << convertToDec(input) << '\n';
        } else{
            // decimal number
            int number = std::stoi(input);
            if(!number){
                std::cout << "0x0";
            } else{
                convertToHex(number);
            }
            std::cout << '\n';
        }
    }
    return 0;
}
