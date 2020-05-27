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
#define show(a) for(auto val:a) {cout << val << ' ';}'
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

int main(){

    int T, r = 0;
    sfi(T);
    while(T--){
        int n,m,k;
        sf("%d %d %d",&n,&m,&k);
        vector<string>store[n];
        vector<bool>hi[n];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < k ; j++){
                string p; cin >> p; store[i].pb(p);
            }
        }
        int p; sfi(p);
        for(int i = 0 ; i < p ; i++){
            int q; sfi(q);
            for(int i = 0 ; i < n ; i++){
                bool check = false;
                for(int j = 0 ; j < k ; j++){
                    int ret = atoi(store[i][j].c_str());
                    //cout << store[i][j][0] << ' ' << abs(ret) << ' ' << q << ' ';
                    if(store[i][j][0] == '-') {if(q != abs(ret)) check = true;}
                    else if(store[i][j][0] == '+') {if(q == ret) check = true;}

                    //cout << "bool :" << check << endl;

                    if(check){
                        hi[i].pb(true);
                        break;
                    }
                }
                if(!check) hi[i].pb(false);
            }
        }

        bool flag = true;
        for(int i = 0 ; i < n ; i++){
            if(!(hi[i][0])) flag = false;
        }
        if(!flag) pf("Case %d: No\n",++r);
        else pf("Case %d: Yes\n",++r);
    }

    return 0;
}
