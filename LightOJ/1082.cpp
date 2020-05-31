#include<iostream>
#include<cstdio>
 
using namespace std;
 
#define MAX 100005
#define INTMAX 100005
 
int arr[MAX];
int tree[MAX * 4];
 
inline int min(int a,int b) { return (a < b) ? a : b; }
 
void init(int node,int b,int e){
    if(b == e){
        tree[node] = arr[b];
        return ;
    }
 
    int left = 2 * node;
    int right = 2 * node + 1;
 
    int mid = (b + e)/2;
 
    init(left,b,mid);
    init(right,mid + 1,e);
 
    tree[node] = min(tree[left],tree[right]);
}
 
int query(int node,int b,int e,int i,int j){
    if(i > e || j < b) return INTMAX; /// out of range
 
    if(b >= i && e <= j) return tree[node]; /// relevant node
 
    int left = node * 2;
    int right = 2 * node + 1;
    int mid = (b + e)/2;
 
    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid + 1,e,i,j);
 
    return min(p1,p2);
}
 
int main(){
    int T, k = 0;
    scanf("%d",&T);
 
    while(T--){
        int n,q; scanf("%d %d",&n,&q);
 
        for(int i = 1 ; i <= n ; i++) scanf("%d",&arr[i]);
 
        init(1,1,n);
 
        printf("Case %d:\n",++k);
 
        while(q--){
            int a,b; scanf("%d %d",&a,&b);
            printf("%d\n",query(1,1,n,a,b));
        }
    }
 
    return 0;
}