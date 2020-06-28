#include <iostream>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        std::string sequence;
        std::cin >> sequence;
        int left = 0, right = 0;
        int answer = 0;
        for(int i = 0 ; i < sequence.length() ; ++i){
            if(sequence[i] == '(') ++left;
            else ++right;
            if(left < right){
                sequence.erase(sequence.begin() + i);
                sequence.push_back(')');
                ++answer;
                --right;
                --i;
            }
        }
        std::cout << answer << '\n';
    }
    return 0;
}
