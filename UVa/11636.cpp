#include<bits/stdc++.h>

using namespace std;

int main()

{
    int a,i=0;
    int ans;

    while(cin>>a)
    {
        if(a<0) break;

        else
        {
            if(a==0) printf("Case %d: %d\n",++i,a);

            else if(!(a&(a-1)))
            {
                ans=log2(a);

                printf("Case %d: %d\n",++i,ans);
            }
            else
            {
                ans=log2(a);

                printf("Case %d: %d\n",++i,ans+1);
            }

        }
    }

    return 0;
}
