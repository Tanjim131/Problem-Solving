#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    string input;
    cin >> input;
    vector <int> cards(26);
    for(int i = 0 ; i < input.length() ; ++i){
        int _id = input[i] - 'A';
        ++cards[_id];
    }
    sort(cards.begin(), cards.end(), greater<int>());
    long long answer = 0;
    for(int i = 0 ; i < 26 && k != 0 ; ++i){
        int can = min(cards[i], k);
        if(can <= cards[i]){ // if I can't take more than what cards[i] has, then double the quantity
            answer += 1LL * can * can;
        } else{ // I can take more than what cards[i] has
            answer += can;
        }
        k -= can;
    }
    cout << answer << '\n';
    return 0;
}
