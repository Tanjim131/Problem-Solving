#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Date{
    public:
        int day, month, year;
        Date(){}
        Date(int _d, int _m, int _y) : day(_d), month(_m), year(_y){}
        friend istream& operator >> (istream &, Date &);
};

istream& operator >> (istream &in, Date &d){
    in >> d.day >> d.month >> d.year;
    return in;
}

int calculate_fees(const Date &actual, const Date &expected){
    if(actual.year < expected.year) {
        return 0;
    }
    if(actual.year > expected.year){
        return 10000;
    }
    // within same calendar year
    if(actual.month < expected.month){
        return 0;
    }
    if(actual.month > expected.month){
        return 500 * (actual.month - expected.month);
    }
    // within same month
    if(actual.day > expected.day){
        return 15 * (actual.day - expected.day);
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Date actual, expected;
    cin >> actual >> expected;
    cout << calculate_fees(actual, expected) << '\n';
    return 0;
}
