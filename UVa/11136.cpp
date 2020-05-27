#include <cstdio>
#include <set>

using namespace std;

#define LL long long

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;

        multiset < int > ms;
        multiset < int > :: iterator it;
        LL cost = 0;

        for(int i = 0 ; i < n ; i++){
            int q ; scanf("%d",&q);

            for(int j = 0 ; j < q ; j++){
                int p ; scanf("%d",&p);
                ms.insert(p);
            }

            it = ms.begin();
            cost -= *it;
            ms.erase(it);
            it = ms.end(); // Returns an iterator referring to the past-the-end element in the multiset container.
            it--; // so here we need to decrement one position
            cost += *it;
            ms.erase(it);

        }

        printf("%lld\n",cost);
    }
    return 0;
}
