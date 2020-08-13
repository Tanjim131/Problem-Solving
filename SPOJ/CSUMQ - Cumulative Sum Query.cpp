#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector <int> v(N + 1, 0);
    for(int i = 1 ; i <= N ; ++i) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    int Q;
    cin >> Q;
    while(Q--){
        int i, j;
        cin >> i >> j;
        ++i; ++j;
        cout << v[j] - v[i - 1] << '\n';
    }
    return 0;
}
