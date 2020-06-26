#include <iostream>
#include <algorithm>

// two reversed numbers are given
// we have to output their reversed sum

// we just have to sum the two numbers from left to right
// no need to reverse

// note: no zeros were lost by reversing (i.e no trailing zeroes before reversing)
// the reversed number cannot have any trailing zeroes (because that would imply there were leading zeroes before reversing)

std::string add(std::string &a, std::string &b){
    int lenA = a.length();
    int lenB = b.length();

    if(lenA != lenB){
        // apply appropriate padding to the right of the smaller one
        if(lenA < lenB){
            // a is the smaller one
            int difference = lenB - lenA;
            while(difference--) a += '0';
        } else{
            int difference = lenA - lenB;
            while(difference--) b += '0';
        }
    }

    std::string sum; 
    sum.reserve(std::max(a.length(), b.length()) + 1);
    int carry = 0;
    for(int i = 0 ; i < a.length() ; ++i){ // or i < b.length(), both are same at this point
        int sum_digits = (a[i] - '0') + (b[i] - '0') + carry;
        sum.push_back(sum_digits % 10 + '0'); // % have higher precedence than +
        carry = sum_digits / 10;
    }
    if(carry) sum.push_back(carry + '0');

    // "result" cannot have any leading zeroes 
    int first_nonzero_index = std::find_if(sum.begin(), sum.end(), [](char c) { return c != '0'; }) - sum.begin();
    return sum.substr(first_nonzero_index);
}

int main(){
    int T;
    std::cin >> T;
    std::string a,b;
    while(T--){
        std::cin >> a >> b;
        std::cout << add(a, b) << '\n';
    }

    return 0;
}
