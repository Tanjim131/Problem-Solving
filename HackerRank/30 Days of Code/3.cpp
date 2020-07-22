#include <bits/stdc++.h>

using namespace std;



int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(N % 2 == 1){
        cout << "Weird\n";
    } else{
        if(N >= 2 && N <= 5) cout << "Not Weird\n";
        else if(N >= 6 && N <= 20) cout << "Weird\n";
        else cout << "Not Weird\n";
    }

    return 0;
}
