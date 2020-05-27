#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const double eps = 0.0001;
const double eps1 = 0.00001;

double p,q,r,s,t,u;
bool f = false;

bool check(double val){
    double qq = p * exp(-val) + q * sin(val) + r * cos(val) + s * tan(val) + t * val * val + u;
    //double rr = abs(qq - eps);
    cout << "qq " << qq << endl;
    cout << "statement " << (qq < 0.0) << endl;
    if(qq < 0.0) return false;
    if(abs(qq) < eps) return true;
    return false;
}

double binary(){
    double low = 0.0 , high = 1.0;
    double id = -1.0;
    while((high - low) > eps){
        double mid = (low + high) / 2.0;
        cout << "low " << low << " high " << high << " mid " << mid << endl;
        if(check(mid)){
            id = mid;
            high = mid;
            f = true;
        }
        else low = mid;
        cout << "low " << low << " high " << high << " mid " << mid << endl;
    }
    return id;
}

int main(){
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u) != EOF){
        double counter = binary();
        if(!f) printf("No solution\n");
        else printf("0.4f\n",counter);
    }

    return 0;
}


