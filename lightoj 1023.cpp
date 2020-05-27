#include<bits/stdc++.h>

using namespace std;

int main()

{
    int T,i=0;
    cin>>T;

    while(T--)
    {
        int N,K;

        cin>>N>>K;

        vector<char>myvector;

        for(int j=0;j<N;j++) myvector.push_back('A'+j);

        printf("Case %d:\n",++i);

        int counter=0;

        do
        {
            for(int j=0;j<N;j++) cout << myvector.at(j);

            counter++;

            cout << "\n";

        } while(next_permutation(myvector.begin(),myvector.end()) && counter<K);

    }

    return 0;
}
