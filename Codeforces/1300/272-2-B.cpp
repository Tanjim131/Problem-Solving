#include <iostream>
#include <iomanip>

using namespace std;

int recurse(const string &s2, int final_pos, int index = 0, int current_pos = 0){
    if(index == s2.length()){
        if(current_pos == final_pos){
            return 1;
        }
        return 0;
    }
    if(s2[index] == '?'){
        int ret_plus = recurse(s2, final_pos, index + 1, current_pos + 1);
        int ret_minus = recurse(s2, final_pos, index + 1, current_pos - 1);
        return ret_plus + ret_minus;
    } 
    int ret = recurse(s2, final_pos, index + 1, s2[index] == '+' ? current_pos + 1 : current_pos - 1);
    return ret;
}

int main(int argc, char const *argv[])
{
    string s1,s2;
    cin >> s1 >> s2;
    int final_pos = 0;
    for(int i = 0 ; i < s1.length() ; ++i){
        if(s1[i] == '+') ++final_pos;
        else --final_pos;
    }
    int total = 1;
    for(int i = 0 ; i < s2.length() ; ++i){
        if(s2[i] == '?') total *= 2;
    }
    int matched = recurse(s2, final_pos);
    double probability = matched * 1.0 / total;
    cout << fixed << setprecision(17) << probability << '\n';
    return 0;
}
