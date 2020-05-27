#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>

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

const int MAXN = 1000 + 5;

class Elephant{
    public:
        int weight;
        int iq;
        int index;

        Elephant(){
            weight = 0;
            iq = 0;
            index = -1;
        }

        Elephant(int weight,int iq,int index){
            this -> weight = weight;
            this -> iq = iq;
            this -> index = index;
        }

        bool operator < (const Elephant &ob) const{
            return iq > ob.iq;
        }

}sequence[MAXN];

int s[MAXN],path[MAXN];

void pathPrint(int start){
    vector < int > v;

    while(start != -1){
        v.pb(sequence[start].index);
        start = path[start];
    }

    for(int i = v.size() - 1; i >= 0 ; i--){
        printf("%d\n",v[i]);
    }
}


inline void LIS(int n){
    int mx = 1 , index = 0;
    s[0] = 1,path[0] = -1;

    for(int i = 1 ; i < n ; i++){
        s[i] = 1;
        int prev = -1;
        for(int j = 0 ; j < i ; j++){
            if( (sequence[j].weight < sequence[i].weight) && (sequence[j].iq > sequence[i].iq) && (s[i] < s[j] + 1)){
                s[i] = s[j] + 1;
                prev = j;
            }
        }

        path[i] = prev;

        if(mx < s[i]){
            mx = s[i];
            index = i;
        }
    }

    printf("%d\n",mx);
    pathPrint(index);
}

int main(){
    //infile("in.txt");
    //outfile("out.txt");

    // either sort the iq in descending order and run LIS on weight or
    //sort the weight in ascending order and run LDS on iq

    int weight,iq;
    int n = 0;
    while(scanf("%d %d",&weight,&iq) != EOF){
        sequence[n] = Elephant(weight,iq,n + 1);
        n++;
    }

    sort(sequence,sequence + n);

    LIS(n);

    return 0;
}
