#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>

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

const int MAXN = 10000 + 5;
int sequence[MAXN];
int I[MAXN];
int LIS[MAXN];
int n;

const int INF = 1e8;

struct Ret{
    int index;
    int length;

    Ret(){
        index = -1;
        length = 0;
    }

    Ret(int i,int l){
        index = i;
        length = l;
    }
};

// Complexity - O(nlogk)

int bs(int key){
    int low = 0,high = n;
    while(low <= high){
        int mid = (low + high)/2;
        //printf("low %d high %d mid %d\n",low,high,mid);
        if(I[mid] == key) low = mid + 1;
        else if(I[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

Ret LongestIncreasingSubsequence(){
    I[0] = -INF;
    for(int i = 1 ; i <= n ; i++) I[i] = INF;

    Ret r;

    //initial update of array I

    for(int i = 0 ; i < n ; i++){
        int pos = bs(sequence[i]);
        // finding the position of the i-th item in sequence array that fits in I array
        I[pos] = sequence[i];
        // updating the I array
        LIS[i] = pos;

        if(r.length < LIS[i]){
            r.length = LIS[i];
            r.index = i;
        }
        // updating the LIS array
    }

    return r;
}

/*void printLIS(){
    Ret r = LongestIncreasingSubsequence();

    printf("%d\n",r.length);

    int top = r.length - 1;
    LISsequence[top--] = sequence[r.index];
    int j = r.index;

    for(int i = r.index - 1 ; i >= 0 ; i--){
        if(sequence[i] < sequence[j] && LIS[j] == LIS[i] + 1){
            j = i;
            LISsequence[top--] = sequence[i];
        }
    }

    for(int i = 0 ; i < r.length ; i++){
        printf("%d ",LISsequence[i]);
    }
}*/

int main(){
    //infile("in.txt");
    //outfile("out.txt");
    int a,kase = 0;
    bool f = false;
    while(scanf("%d",&a) != EOF){
        if(a == -1) break;
        if(f) printf("\n");
        f = true;
        int counter = 0;
        sequence[counter++] = a;
        while(scanf("%d",&a) != EOF){
            if(a == -1) break;
            sequence[counter++] = a;
        }
        n = counter;
        reverse(sequence,sequence + n);
        Ret r = LongestIncreasingSubsequence();
        printf("Test #%d:\n  maximum possible interceptions: %d\n",++kase,r.length);
    }
    return 0;
}


