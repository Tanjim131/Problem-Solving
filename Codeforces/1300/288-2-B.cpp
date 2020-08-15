#include <iostream>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string c;
    cin >> c;
    bool found = false;
    for(int i = 0 ; i < c.length() - 1 ; ++i){
        int a = c[i] - '0';
        int b = c.back() - '0';
        if(a % 2 == 0 && a < b){
            swap(c[i], c.back());
            found = true;
            break;
        }
    }
    if(found){
        cout << c << '\n';
    } else{
        for(int i = c.length() - 1 ; i >= 0 ; --i){
            int a = c[i] - '0';
            int b = c.back() - '0';
            if(a % 2 == 0){
                swap(c[i], c.back());
                found = true;
                break;
            }
        }
        if(found){
            cout << c << '\n';
        } else{
            cout << "-1\n";
        }
    }
    return 0;
}
