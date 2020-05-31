#include<cstdio>
 
using namespace std;
 
#define LL long long
#define MAXN 100005
 
struct info{
    LL prop,sum;
}tree[MAXN * 4];
 
void init(int node,int b,int e){
    if(b == e){
        tree[node].sum = 0;
        tree[node].prop = 0;
        return ;
    }
 
    LL left = node * 2;
    LL right = node * 2 + 1;
    LL mid = (b + e)/2;
 
    init(left,b,mid);
    init(right,mid + 1,e);
 
    tree[node].sum = 0;
    tree[node].prop = 0;
}
 
void update(int node,int b,int e,int i,int j,LL x){
    if(i > e || j < b) return ;
 
    if(b >= i && e <= j){ /// relevant node
        tree[node].sum += (e - b + 1) * x;
        tree[node].prop += x;
        return ;
    }
 
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;
 
    update(left,b,mid,i,j,x);
    update(right,mid + 1,e,i,j,x);
 
    tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}
 
LL query(int node,int b,int e,int i,int j,LL carry = 0){
    if(i > e || j < b) return 0;
 
    if(b >= i && e <= j) return tree[node].sum + carry * (e - b + 1);
 
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;
 
    LL p1 = query(left,b,mid,i,j,carry + tree[node].prop);
    LL p2 = query(right,mid + 1,e,i,j,carry + tree[node].prop);
 
    return p1 + p2;
}
 
int main(){
    //freopen("in.txt","r",stdin);
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        int n,q; scanf("%d %d",&n,&q);
 
        init(1,1,n);
 
        printf("Case %d:\n",++k);
 
        while(q--){
            int a; scanf("%d",&a);
 
            if(a == 0){
                int x,y;LL v; scanf("%d %d %lld",&x,&y,&v);
                update(1,1,n,x + 1,y + 1,v);
            }
            else if(a == 1){
                int x,y; scanf("%d %d",&x,&y);
                printf("%lld\n",query(1,1,n,x + 1,y + 1));
            }
        }
    }
 
    return 0;
}
 