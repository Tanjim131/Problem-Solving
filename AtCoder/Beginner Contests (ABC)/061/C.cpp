#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    long long K;
    cin >> N >> K;
    map <int, long long> count; // order is necessary
    for(int i = 0 ; i < N ; ++i){
        int a, b;
        cin >> a >> b;
        count[a] += b;
    }
    long long pos = 0;
    for(const auto &elem : count){ // elem.first - value, elem.cond - frequency
        pos += elem.second;
        if(K <= pos){
            cout << elem.first << '\n';
            break;
        }
    }
    return 0;
}
