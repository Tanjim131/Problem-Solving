#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    // the a_i's are not necessarily distinct, so if it's possible to reach state 2, it'll be possible to reach it within N steps
    // otherwise there's a cycle (pigeonhole principle)
    int N;
    cin >> N;
    vector <int> a(N + 1);
    for(int i = 1 ; i <= N ; ++i){
        cin >> a[i];
    }
    int current = 1;
    int moves = 0;
    for(int i = 1 ; i <= N && current != 2 ; ++i, ++moves){
        current = a[current];
    }
    cout << (current == 2 ? moves : -1) << '\n';
    return 0;
}