#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        std::vector <int> scores(n);
        int sum = 0;
        for(int i = 0 ; i < n ; ++i){
            cin >> scores[i];
            sum += scores[i];
        }
        int canIncrease = sum - scores[0];
        int maxScore = std::min(scores[0] + canIncrease, m);
        cout << maxScore << '\n';
    }
    return 0;
}
