#include <iostream>

inline bool isPositive(const std::string &s){
    return s == "1" || s == "4" || s == "78";
}

inline bool isNegative(const std::string &s){
    return s.length() >= 2 && s.substr(s.length() - 2) == "35";
}

inline bool isFailed(const std::string &s){
    return s.length() >= 2 && s[0] == '9' && s[s.length() - 1] == '4';
}

inline bool isCompleted(const std::string &s){
    return !(s.length() >= 4 && s.substr(0, 3) == "190");
}

int main(int argc, char const *argv[])
{
    int T; std::cin >> T;
    while(T--){
        std::string sequence;
        std::cin >> sequence;
        if(isPositive(sequence)){
            std::cout << "+\n";
        } else if(isNegative(sequence)){
            std::cout << "-\n";
        } else if(isFailed(sequence)){
            std::cout << "*\n";
        } else if(!isCompleted(sequence)){
            std::cout << "?\n";
        }
    }
    return 0;
}
