#include<cstdio>
#include<cstring>
 
using namespace std;
 
#define MAXN 100005
 
int tree[MAXN];
 
int query(int i,int j){
    int sum = 0;
 
    while(j > 0){
        sum += tree[j];
        j -= (j & -j);
    }
 
    i--;
 
    while(i > 0){
        sum -= tree[i];
        i -= (i & -i);
    }
 
    return sum;
}
 
void update(int i,int x,int n){ // x to add, n size of array
    while(i <= n){
        tree[i] += x;
        i += (i & -i);
    }
}
 
void print(int n){
    for (int i = 1 ; i <= n ; i++) printf("%d ",tree[i]);
    printf("\n");
}
 
int main(){
    int T, k = 0; scanf("%d",&T);
 
    while(T--){
        printf("Case %d:\n",++k);
 
        memset(tree,0,sizeof(tree));
 
        int n,q; scanf("%d %d",&n,&q);
 
        for(int i = 1 ; i <= n ; i++) {
            int x;
            scanf("%d",&x);
            update(i,x,n);
        }
 
        //print(n);
 
        while(q--){
            int a; scanf("%d",&a);
 
            if(a == 1){
                //update & print
                int i; scanf("%d",&i);
                int ans = query(1,i + 1) - query(1,i);
                printf("%d\n",ans);
                update(i + 1,-ans,n);
                //print(n);
            }
            else if(a == 2){
                int i,v; scanf("%d %d",&i,&v);
                update(i + 1,v,n);
                //print(n);
            }
            else{
                int i , j; scanf("%d %d",&i,&j);
                printf("%d\n",query(i + 1,j + 1));
            }
        }
    }
}