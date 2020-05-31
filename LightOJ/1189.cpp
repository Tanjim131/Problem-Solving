#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define mm(a,b) memset(a,b,sizeof(a))
#define max3(a,b,c) max((max((a),(b))),(c))
#define min3(a,b,c) min((min((a),(b))),(c))
#define endl '\n'
#define pii pair<int,int>
#define pll pair<LL,LL>
#define VI vector<int>
#define VL vector<LL>
#define Vpii vector<pii>
#define FOR(i,a,b) for(i = (a) ; i < (b) ; i++)
#define REP(i,n) FOR(i,0,n)
#define PI (2.0)*acos(0.0)
#define sf scanf
#define pf printf
#define sfi(a) scanf("%d",&a)
#define sfii(a,b) scanf("%d %d",&a,&b)
#define sfiii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pfi(n) printf("%d\n",n)
#define sfl(n) scanf("%lld",&n)
#define sfll(n,m) scanf("%lld %lld",&n,&m)
#define sflll(n,m,p) scanf("%lld %lld %lld",&n,&m,&p)
#define pfl(n) printf("%lld\n",n)
#define get(a,n) for(int i = 0; i < n ; i++) {int j; sfi(j); a.pb(j);}
#define show(a) for(auto val:a) {cout << val << ' ';}
#define debug(x) cout << x << endl
#define debug2(x,y) cout << x << ' ' << y << endl
#define debug3(x,y,z) cout << x << ' ' << y << ' ' << z << endl
#define test cout << "<--Robur-->" << endl
#define mod 1000000007
 
LL gcd(LL a,LL b){
    if(b == 0) return a;
    return gcd(b , a % b);
}
 
LL bigmod(LL base , LL power){
    if(power == 0) return 1;
    LL ret = bigmod(base,power/2);
    ret = (ret * ret) % mod;
    if(power & 1) ret = (ret * base) % mod;
    return ret;
}
 
LL modInverse(LL n){
    return (bigmod(n , mod - 2) % mod);
}
 
/***** Code Starts Here *****/
 
LL dp[25];
VL number;
LL fact(int a){
    if(a == 0) return 1;
    if(dp[a] != -1) return dp[a];
    else dp[a] = a * fact(a - 1);
    return dp[a];
}
 
int main(){
    for(int i = 0 ; i < 25 ; i++) dp[i] = -1;
    for(int i = 0 ; i <= 19 ; i++){
        LL ans = fact(i);
        number.pb(ans);
    }
    int T, k = 0;
    sfi(T);
    while(T--)
    {
        LL n;
        sfl(n);
        if(n == 0){
            pf("Case %d: impossible\n",++k);
            return 0;
        }
        VI ret;
        for(int i = 19 ; i >= 0 ; i--){
            if(n >= number[i]){
                ret.pb(i);
                n -= number[i];
                if(!n) break;
            }
        }
        if(n > 0) pf("Case %d: impossible\n",++k);
        else{
            pf("Case %d: ",++k);
            for(int i = ret.size() - 1 ; i >= 0 ; i--){
                cout << ret[i];
                cout << "!";
                if(i != 0) cout << "+";
            }
            cout << endl;
        }
    }
    return 0;
}