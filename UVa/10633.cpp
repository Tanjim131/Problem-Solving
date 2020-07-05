#include <iostream>

unsigned long long computeAnswer(unsigned long long input){
    long long n = 10 * input / 9;
    return n;
}

int main(int argc, char const *argv[])
{
    unsigned long long input;
    while(std::cin >> input && input){
        if(input % 9 != 0){
            // only one answer
            std::cout << computeAnswer(input) << '\n';
        } else{
            // two answers
            unsigned long long answer = computeAnswer(input);
            std::cout << answer - 1 << " " << answer << '\n';
        }
    }
    return 0;
}
