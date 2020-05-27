#include <iostream>
#include <cmath>

using namespace std;

int compute(const string &a){
    if(a == "1") return 1;
    int next = a.length() ; // at first the number has exactly a.length() digits
    int prev = 0; // actually the numerical value of next, but it can't possibly fit in primitive data types
                    // handled the speical case above
    int counter = 1;
    while(next != prev){
        prev = next;
        next = log10(next) + 1; // a number has exactly log10(number) + 1 digits in base 10
        ++counter;
    }
    return counter;
}

int main(){
    string input;
    while(cin >> input){
        if(input == "END") break;
        std::cout << compute(input) << '\n';
    }

    return 0;
}
