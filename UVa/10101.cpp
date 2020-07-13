#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Unit{
    public:
        int denomination;
        std::string name;

        Unit(){}
        Unit(int _d, const std::string &_n): denomination(_d), name(_n){}
};

std::string  process(int number, const std::vector <Unit> &units){
    std::string ret;

    bool first = true;
    for(int i = 0 ; i < units.size() ; ++i){
        int value = number / units[i].denomination;
        if(value != 0){
            if(!first) ret += " ";
            ret += std::to_string(value) + " " + units[i].name;
            first = false;
        } 
        number -= value * units[i].denomination;
    }

    if(number){
        if(!first) ret += " ";
        ret += std::to_string(number);
    }

    return ret.empty() ? "0" : ret;
}

std::string recurse(long long number, const std::vector <Unit> &units, int crore = 10000000){
    if(number >= crore){
        int a = number / crore;
        std::string ret = recurse(a, units) + " kuti";
        int remaining = number - a * crore;
        if(remaining){
            ret += " " + process(number - a * crore, units);
        }
        return ret;
    } 
    return process(number, units);    
}

int main(int argc, char const *argv[])
{
    const std::vector <Unit> units{
        {100000, "lakh"},
        {1000, "hajar"},
        {100, "shata"}, 
    };

    int k = 0;
    long long number = 4001001;
    while(std::cin >> number){
        std::string answer = recurse(number, units);
        std::cout << std::setw(4) << ++k << ". " << answer << '\n';
    }
    return 0;
}
