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

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

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

const int MAXN = 25;
char prince[MAXN][MAXN];
bool visit[MAXN][MAXN];
int r,c;

int bfs(pii a){
    mm(visit,0);
    visit[a.ff][a.ss] = 1;
    queue<pii>q;
    q.push(a);
    int ans = 1;
    while(!q.empty()){
        int u = q.front().ff;
        int w = q.front().ss;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int x = u + dx[i];
            int y = w + dy[i];
            if(x >= 0 && x < r && y >= 0 && y < c && prince[x][y]!= '#'){
                if(!visit[x][y]){
                    visit[x][y] = 1;
                    q.push(mp(x,y));
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main(){
    int T, k = 0;
    sfi(T);
    while(T--)
    {
        sfii(c,r);
        pii x;
        for(int i = 0 ; i < r ; i++){
            sf("%s",prince[i]);
            for(int j = 0 ; j < c ; j++) if(prince[i][j] == '@') x.ff = i, x.ss = j;
        }
        int ans = bfs(x);
        pf("Case %d: %d\n",++k,ans);
    }

    return 0;
}
