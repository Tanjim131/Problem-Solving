#include<bits/stdc++.h>

using namespace std;

int main()

{
    int T;
    cin>>T;

    while(T--)
    {
        int i;
        cin>>i;

        int N;
        cin>>N;

        cout << i << " " <<  (N*(N+1))/2 << " " << N*N << " " << N*(N+1) << endl;

    }

    return 0;
}
