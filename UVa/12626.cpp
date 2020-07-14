#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class VC{
    public:
        char c;
        int required_count;

        VC(){}
        VC(char _c, int _r_c): c(_c), required_count(_r_c){}
};

int compute_answer(const std::vector <int> &count, const std::vector <VC> &valid_chars){
    int answer = std::numeric_limits <int>::max();
    for(int i = 0 ; i < valid_chars.size() ; ++i){
        int given_count = count[valid_chars[i].c - 'A'];
        int can_be_made = given_count / valid_chars[i].required_count;
        answer = std::min(answer, can_be_made);
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    std::vector <VC> valid_chars{
        {'A', 3}, 
        {'G', 1},
        {'I', 1}, 
        {'M', 1},
        {'R', 2},
        {'T', 1}
    };

    int T;
    std::cin >> T;
    while(T--){
        std::string input;
        std::cin >> input;
        std::vector <int> count(26, 0);
        for(int i = 0 ; i < input.length() ; ++i){
            ++count[input[i] - 'A'];
        }
        int answer = compute_answer(count, valid_chars);
        std::cout << answer << '\n';
    }
    return 0;
}
