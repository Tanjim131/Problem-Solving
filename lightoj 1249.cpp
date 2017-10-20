#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define pis pair < int , string >
#define pb push_back
#define mp make_pair

bool cmp(pis a,pis b){
    return a.first < b.first;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        vector < pis > vv;
        for(int i = 0 ; i < n ; i++){
            string a; int l,w,h;
            cin >> a; scanf("%d %d %d",&l,&w,&h);
            int ret = l * w * h;
            vv.pb(mp(ret,a));
        }
        sort(vv.begin(),vv.end(),cmp);
        int len = vv.size() - 1;
        if(vv[0].first == vv[len].first){
            printf("Case %d: no thief\n",++k);
        }
        else{
            cout << "Case " << ++k << ": " << vv[len].second << " took chocolate from " << vv[0].second << "\n";
        }
    }
    return 0;
}
