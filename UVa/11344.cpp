#include <iostream>
#include <vector>

using namespace std;

bool is_divisible(const string &number, int n){
    int rem = 0;
    for(int i = 0 ; i < number.length() ; ++i){
        rem = (rem * 10 + number[i] - '0') % n;
    }
    return !rem;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        string number;
        cin >> number;
        int N;
        cin >> N;
        vector <int> v(N);
        for(int i = 0 ; i < N ; ++i) cin >> v[i];
        bool wonderful = true;
        for(int i = 0 ; i < N ; ++i){
            if(!is_divisible(number, v[i])){
                wonderful = false;
                break;
            }
        }
        cout << number << " - " << (wonderful ? "Wonderful" : "Simple") << ".\n";
    }
    return 0;
}
