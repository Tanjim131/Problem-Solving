#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int m,n;
        scanf("%d %d",&m,&n);
        multiset < int > a;
        multiset < int > b;
        set < int > all;

        for(int i = 0 ; i < m ; i++){
            int x ; scanf("%d",&x);
            a.insert(x); all.insert(x);
        }

        for(int i = 0 ; i < n ; i++){
            int x; scanf("%d",&x);
            b.insert(x); all.insert(x);
        }

        set < int > :: iterator it;
        int mn = 0;

        for(it = all.begin() ; it != all.end() ; it++){
            int count_a = a.count(*it);
            int count_b = b.count(*it);

            mn += (count_a > count_b) ? count_a - count_b : count_b - count_a;
        }

        printf("%d\n",mn);
    }
    return 0;
}
