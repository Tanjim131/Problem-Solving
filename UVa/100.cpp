#include <iostream>
#include <algorithm>

using namespace std;

int main()

{
    int i,j,k,p,temp;

    int l,m=0;

    while(cin>>i>>j)
    {
        if(i>j)
        {
            std::swap(i,j);
        }
        for(k=i;k<=j;k++)
        {
            l=1;
            p=k;
            while(p!=1)
            {
                l++;

                if(p%2)
                    p=3*p+1;
                else
                    p/=2;
            }

            if(m<l) m=l;
        }

        cout << i << " " << j << " " << m << endl;
    }

    return 0;
}
