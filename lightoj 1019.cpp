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

#define INF 1e14

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

const int MAXN = 10000;

Vpii edges[MAXN];
LL cost[MAXN],par[MAXN];
int n,m;

bool dijkstra(int s){
    mm(par,-1);
    bool ret = false;
    for(int i = 0 ; i < MAXN ; i++) cost[i] = INF;
    cost[s] = 0;
    priority_queue<pair <int,LL> >pq;
    pq.push(mp(s,cost[s]));
    while(!pq.empty()){
        LL u = pq.top().ff;
        LL w = pq.top().ss;
        pq.pop();
        if(u == n) ret = true;
        for(int i = 0 ; i < edges[u].size() ; i++){
            int v = edges[u][i].ff;
            if(w + edges[u][i].ss < cost[v]){
                cost[v] = w + edges[u][i].ss;
                par[v] = u;
                pq.push(mp(v,cost[v]));
            }
        }
    }
    return ret;
}

int main(){
    int T, k = 0;
    sfi(T);
    while(T--)
    {
        sfii(n,m);
        for(int i = 0 ; i < n ; i++) edges[i].clear();
        if(m == 0){
            pf("Case %d: Impossible\n",++k);
            return 0;
        }
        for(int i = 0 ; i < m ; i++){
            int p,q,c; sfiii(p,q,c);
            edges[p].pb(mp(q,c));
            edges[q].pb(mp(p,c));
        }
        bool ret = dijkstra(1);
        if(!ret) pf("Case %d: Impossible\n",++k);
        else pf("Case %d: %lld\n",++k,cost[n]);
    }

    return 0;
}
