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

map < char , int > m;

void precompute(){
    int qq = 2;
    char pp = 'A';
    m[pp++] = qq; m[pp++] = qq; m[pp++] = qq;
    qq++;
    m[pp++] = qq; m[pp++] = qq; m[pp++] = qq;
    qq++;
    m[pp++] = qq; m[pp++] = qq; m[pp++] = qq;
    qq++;
    m[pp++] = qq; m[pp++] = qq; m[pp++] = qq;
    qq++;
    m[pp++] = qq; m[pp++] = qq; m[pp++] = qq;
    qq++;
    m[pp++] = qq; m[pp++] = qq; m[pp++] = qq; m[pp++] = qq;
    qq++;
    m[pp++] = qq; m[pp++] = qq; m[pp++] = qq;
    qq++;
    m[pp++] = qq; m[pp++] = qq; m[pp++] = qq; m[pp] = qq;
}

int main(){
    //infile;outfile;
    string input;
    precompute();
    while(getline(cin,input)){
        for(int i = 0 ; i < input.size() ; i++){
            if(input[i] >= 'A' && input[i] <= 'Z'){
                printf("%d",m[input[i]]);
            }
            else printf("%c",input[i]);
        }
        printf("\n");
    }
    return 0;
}


