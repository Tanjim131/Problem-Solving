#include <iostream>
#include <algorithm>

bool isPalindrome(std::string &current_time){
    // disregard the leading zeroes;
    auto it = std::find_if( std::begin(current_time), std::end(current_time), [](char x) { return x != '0'; });
    int index = it - current_time.begin();
    std::string modified_current_time(current_time.substr(index));
    for(int i = 0 ; i < modified_current_time.length() / 2 ; ++i){
        if(modified_current_time[i] != modified_current_time[modified_current_time.length() - i - 1]) return false;
    }
    return true;
}

void increment(char &current, int mod){
    current = (current - '0' + 1) % mod + '0';
}

void increment_time(std::string &current_time){
    increment(current_time[3], 10); // increment last M
    if(current_time[3] == '0'){ // if last M becomes 0, increment first M
        increment(current_time[2], 6); 
        if(current_time[2] == '0'){ // if first M becomes 0, increase last H
            increment(current_time[1], 10);
            if(current_time[1] == '0'){ // if last H becomes 0, increase first H
                increment(current_time[0], 3);
            }
        }
    }
    if(current_time == "2400") current_time = "0000";
}

std::string next_palindrome(std::string &current_time){
    increment_time(current_time);
    while(!isPalindrome(current_time)){
        increment_time(current_time);
    }
    return current_time;
}

void remove_colon(std::string &current_time){
    current_time.erase(std::find(current_time.begin(), current_time.end(), ':'));
}

void insert_colon(std::string &current_time){
    current_time.insert(current_time.begin() + 2, ':');
}

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        std::string current_time;
        std::cin >> current_time;
        // disregard the colon
        remove_colon(current_time);
        // find the next palindromic time
        next_palindrome(current_time);
        // insert the colon again
        insert_colon(current_time);
        std::cout << current_time << '\n';
    }
    return 0;
}
