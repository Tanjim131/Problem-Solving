#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    // O(26 * N) solution instead of naive O(N^2)
    vector <vector<int>> count(26, vector <int>(N + 1, 0));
    for(int i = 1 ; i <= N ; ++i){
        ++count[S[i - 1] - 'a'][i];
        for(int j = 0 ; j < 26 ; ++j){
            count[j][i] += count[j][i - 1];
        }
    }
    int maximum = 0;
    for(int i = 1 ; i < N ; ++i){
        // cut at position i
        // X - [1...i], Y - [i + 1...N]
        int counter = 0;
        for(int j = 0; j < 26 ; ++j){
            int left = count[j][i];
            int right = count[j][N] - left;
            if(left > 0 && right > 0){
                ++counter;
            }
        }
        maximum = max(maximum, counter);
    }
    cout << maximum << '\n';
    return 0;
}
