#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;
    long long answer = 0;
    int countW = 0;
    for(auto it = S.rbegin() ; it != S.rend() ; ++it){
        if(*it == 'W'){
            ++countW;
        } else{
            answer += countW;
        }
    }
    cout << answer << '\n';
    return 0;
}
