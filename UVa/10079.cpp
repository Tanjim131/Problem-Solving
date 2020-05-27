#include<bits/stdc++.h>

using namespace std;

int main()

{
    long long int N;

    while(cin>>N)
    {
        if(N<0) break;

        else
        {
            cout << (N*(N+1))/2 +1 << endl;
        }
    }

    return 0;
}
