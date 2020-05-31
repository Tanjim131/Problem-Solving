#include<iostream>
#include<cstdio>
#include<cstring>
 
using namespace std;
 
#define MAXN 100005
#define LL long long
 
int arr[MAXN];
LL tree[3 * MAXN],lazy[3 * MAXN];
 
void build(int node,int a,int b){
    if(a == b){
        tree[node] = arr[a];
        return ;
    }
 
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (a + b)/2;
 
    build(left,a,mid);
    build(right,mid + 1,b);
 
    tree[node] = tree[left] + tree[right];
}
 
void update(int node,int a,int b,int i,int j,int value){
 
    if(lazy[node] != -1){ /* this node needs to be updated */
        tree[node] = lazy[node] * (b - a + 1); /* updating node from previous operation */
 
        if(a != b){ /* not leaf node */
            lazy[2 * node] = lazy[node]; // mark left child as lazy
            lazy[2 * node + 1] = lazy[node]; // mark right child as lazy
        }
 
        lazy[node] = -1; /* reset node */
    }
 
    if(i > b || j < a) return ;
 
    if(a >= i && b <= j){ // relevant node
        tree[node] = value * (b - a + 1);
 
        if(a != b){
            lazy[2 * node] = value;
            lazy[2 * node + 1] = value;
        }
        return ;
    }
 
    int left = 2 * node,right = 2 * node + 1, mid = (a + b)/2;
 
    update(left,a,mid,i,j,value);
    update(right,mid + 1,b,i,j,value);
 
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
 
LL query(int node,int a,int b,int i,int j){
 
    if(lazy[node] != -1){ /* this node needs to be updated */
        tree[node] = lazy[node] * (b - a + 1); /* updating node from previous operation */
 
        if(a != b){ /* not leaf node */
            lazy[2 * node] = lazy[node]; // mark left child as lazy
            lazy[2 * node + 1] = lazy[node]; // mark right child as lazy
        }
 
        lazy[node] = -1; /* reset node */
    }
 
    if(i > b || j < a) return 0;
 
    if(a >= i && b <= j){ // relevant node
        return tree[node];
    }
 
    int left = 2 * node,right = 2 * node + 1, mid = (a + b)/2;
 
    LL q1 = query(left,a,mid,i,j);
    LL q2 = query(right,mid + 1,b,i,j);
 
    return q1 + q2;
}
 
LL gcd(LL a,LL b){
    if(b == 0) return a;
    return gcd(b,a % b);
}
 
int main(){
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        int n,q; scanf("%d %d",&n,&q);
 
        for(int i = 1 ; i <= n ; i++) arr[i] = 0;
 
        build(1,1,n);
        memset(lazy,-1,sizeof(lazy));
 
        printf("Case %d:\n",++k);
 
        while(q--){
            int a; scanf("%d",&a);
 
            if(a == 1){
                int i,j,v; scanf("%d %d %d",&i,&j,&v);
                update(1,1,n,i + 1,j + 1,v);
            }
            else{
                int i,j; scanf("%d %d",&i,&j);
                LL ans = query(1,1,n,i + 1,j + 1);
                int len = j - i + 1;
 
 
                    LL g = gcd(ans,len);
                    if(g == 0) printf("0\n");
                    else if(g == 1) printf("%lld/%lld\n",ans,len);
                    else{
                        ans /= g , len /= g;
                        if(len == 1) printf("%lld\n",ans);
                        else printf("%lld/%lld\n",ans,len);
                    }
                }
            }
        }
 
    return 0;
}
 