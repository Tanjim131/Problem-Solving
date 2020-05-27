#include<bits/stdc++.h>

using namespace std;

int main()

{
    int T,i=0;
    cin>>T;

    while(T--)
    {
        long long int n;

        cin>>n;

        long long int temp= sqrt(n),ans=0;

        if(n==temp*temp)
            ans= temp;
        else
            ans=temp+1;

        long long int diff= (ans*ans)-n;

        long long int low=((ans-1)*(ans-1))+1;

        if(!(ans&1))
        {
            if(diff<ans)
                cout << "Case " << ++i  << ": " << ans << " " << diff+1 << endl;

            else
                cout <<"Case " << ++i <<": " << (n-low)+1 << " " << ans << endl;

        }
        else
        {
            if(diff<ans)
                cout << "Case " << ++i << ": " << diff+1 << " " << ans << endl;

            else
                cout <<"Case " << ++i << ": " << ans << " " << (n-low)+1 << endl;
        }

    }

    return 0;
}
