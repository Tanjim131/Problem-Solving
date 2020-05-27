#include <cstdio>
#include <set>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m,n;
    while(scanf("%d %d",&m,&n) != EOF){
        if(m == 0 && n == 0) break;

        set < int > ss;

        int tot = m + n;

        for(int i = 0 ; i < tot ; i++){
            int x ; scanf("%d",&x);
            ss.insert(x);
        }

        printf("%d\n", tot - ss.size());
    }

    return 0;
}
