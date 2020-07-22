#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int bits = static_cast<int>(log2(n)) + 1;
    int maximum = -1, current = 0;
    for(int i = 0 ; i < bits ; ++i){
        if(n & (1 << i)){
            ++current;
            maximum = max(maximum, current);
        } else{
            current = 0;
        }
    }
    cout << maximum << '\n';
    return 0;
}
