#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);

        int cost;
        string in;
        map < string , int > mp;

        for(int i = 0 ; i < n ; i++){
            cin >> in >> cost;
            if(mp.find(in) == mp.end()){
                mp[in] = cost;
            }
        }

        int days;
        string sub;

        cin >> days >> sub;

        if(mp.find(sub) == mp.end()){
            printf("Case %d: Do your own homework!\n",++k);
        }
        else{
            if(mp[sub] <= days) printf("Case %d: Yesss\n",++k);
            else if(mp[sub] > days && mp[sub] <= days + 5) printf("Case %d: Late\n",++k);
            else printf("Case %d: Do your own homework!\n",++k);
        }
    }
    return 0;
}
