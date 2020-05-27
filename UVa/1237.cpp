#include <cstdio>
#include <cstring>

using namespace std;

char name[10005][25];
int low[10005];
int high[10005];
char ans[30];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        memset(name,0,sizeof(name));
        memset(low,0,sizeof(low));
        memset(high,0,sizeof(high));
        int database;
        scanf("%d",&database);

        for(int i = 0 ; i < database ; i++){
            scanf("%s %d %d",name[i],&low[i],&high[i]);
        }

        int query;
        scanf("%d",&query);

        for(int i = 0 ; i < query ; i++){
            int qq; scanf("%d",&qq);

            int counter = 0;

            for(int j = 0 ; j < database ; j++){
                if(qq >= low[j] && qq <= high[j]){
                    strcpy(ans,name[j]);
                    counter++;
                }
                if(counter > 1) break;
            }

            if(counter == 1) printf("%s\n",ans);
            else printf("UNDETERMINED\n");
        }

        if(T != 0) printf("\n");
    }

    return 0;
}
