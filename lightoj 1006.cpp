/* ******************************************************************************************************************************************** */
/*
/*   "The advantage you had yesterday, will be replaced by the trends of tomorrow.
/*    You dont have to do anything wrong as long as your competitors catch the wave and do it right.
/*    Those who refuse to learn & improve, will definitely one day become redundant & not relevant to the industry.
/*    They will learn the lesson in a hard & expensive way."
/*
/*
/*   "Mistakes have consequences. They can cause companies to lose customers, money and credibility.
/*    But the only thing worse than making a mistake is deciding to never put yourself in a position to make the mistake in the first place.
/*    The risk of stalling innovation & learning, and letting your competitors move faster than you is far more dangerous."
/*
/* ******************************************************************************************************************************************** */


#include<bits/stdc++.h>

using namespace std;

#define ll long long
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
#define pll pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>
#define Vpii vector<pii>
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define PI (2.0)*acos(0.0)
#define sf scanf
#define pf printf
#define sfi(n) scanf("%d",&n)
#define pfi(n) printf("%d\n",n)
#define sfl(n) scanf("%lld",&n)
#define pfl(n) printf("%lld\n",n)
#define get(a) for(int i=0;i<n;i++) {int j; sfi(j); a.pb(j);}
#define show(a) for(auto val:a) {cout << val << ' ';}

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

/***** Code Starts Here *****/

ll a, b, c, d, e, f;
ll dp[10005] = {};

const ll mod = 10000007;

ll fn( ll n ) {
    dp[0]=a;
    dp[1]=b;
    dp[2]=c;
    dp[3]=d;
    dp[4]=e;
    dp[5]=f;

    if(dp[n]!=-1) return dp[n] % mod;
    else dp[n] = ( fn(n-1) + fn(n-2)+ fn(n-3) + fn(n-4)  + fn(n-5)  + fn(n-6) ) % mod
        ;
    return dp[n];
}

int main() {
    ll n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        mm(dp,-1);
        printf("Case %lld: %lld\n", ++caseno, fn(n));
    }
    return 0;
}
