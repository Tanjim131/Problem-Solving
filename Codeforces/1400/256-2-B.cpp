#include <iostream>
#include <vector>

using namespace std;

bool is_subsequence(const string &s, const string &t){
    int index = 0;
    for(int i = 0 ; i < s.length() && index < t.length() ; ++i){
        if(s[i] == t[index]){
            ++index;
        }
    }
    return index == t.length();
}

int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s >> t;
    vector <int> sf(26, 0), tf(26, 0);
    for(int i = 0 ; i < s.length() ; ++i) ++sf[s[i] - 'a'];
    for(int i = 0 ; i < t.length() ; ++i) ++tf[t[i] - 'a'];
    bool tree = false;
    bool array = true;
    for(int i = 0 ; i < 26 ; ++i){
        if(tf[i] > sf[i]){
            tree = true;
            break;
        } else if(tf[i] != sf[i]){
            array = false;
        }
    }
    if(tree){
        cout << "need tree\n";
        return 0;
    }
    if(is_subsequence(s, t)){
        cout << "automaton\n";
    } else if(array){
        cout << "array\n";
    } else{
        cout << "both\n";
    }
    return 0;
}
