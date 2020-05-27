#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define PII pair < int , int >
#define infile(f) freopen(f,"r",stdin)
#define outfile(f) freopen(f,"w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

int page[10000 + 5];
int counter[1000000 + 5];

bool check(int n){
    int i = 0; // starting at 0th index of array
    // at any given moment we have (n - 1 - i) elements on the right
    // and i elements on the left of the array
    while(i < n){
        int right = n - 1 - i;
        int left = i;

        // checking for right
        if(counter[right]){
            counter[right]--;
            i++;
        }
        else{
            // checking for left
            if(counter[left]){
                counter[left]--;
                i++;
            }
            else return false ;
        }
    }
    return true;
}

int main(){
    //infile("in.txt");
    //outfile("out.txt");
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        memset(counter,0,sizeof(counter));
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&page[i]);
            counter[page[i]]++;
        }
        if(check(n)) printf("Case %d: yes\n",++kase);
        else printf("Case %d: no\n",++kase);
    }
    return 0;
}

