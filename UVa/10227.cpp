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
#define pii pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

set < int > s[105];

int main(){
    //infile;
    //outfile;
    int T; bool f = false;
    scanf("%d",&T);
    int p,t;
    getchar();
    while(T--){
        scanf("%d %d",&p,&t);
        for(int i = 0 ; i < 105 ; i++) s[i].clear();
        string input; int a,b;
        getchar();
        while(getline(cin,input) && input != ""){
            stringstream ss(input);
            ss >> a >> b;
            s[a].insert(b);
            //cout << a << " " << b << endl;
        }

        set < set < int > > qq;

        for(int i = 1 ; i <= p ; i++){
            qq.insert(s[i]);
        }

        printf("%d\n",qq.size());

        if(T) printf("\n");
    }
    return 0;
}


