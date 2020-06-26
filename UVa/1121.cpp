#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 7;
long long inp[MAXN] , S;
int n ;

int main()
{
    while(cin >> n >> S)
    {
        int low = 0, high = 0, ans = n + 1 ;
        int i ;
        for ( i = 0 ; i < n ; i++ ) cin >> inp[i];
        long long sum = inp[0];
        while( high < n )
        {
            if( sum >= S )
            {
                ans = min(ans, high - low + 1);
            }
            if( sum >= S )
            {
                sum -= inp[low];
                low++;
            }
            else
            {
                high++;
                sum += inp[high];
            }
        }
        if( ans == n + 1 ) ans = 0 ;
        cout << ans << '\n';
    }
    return 0;
}
