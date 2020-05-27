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

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

int recur(int n,int steps){
    if(n < 10) return steps;

    int temp = 0;

    while(n){
        temp += (n % 10);
        n /= 10;
    }

    recur(temp,steps + 1);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string input;
    while(cin >> input){
        if(input == "0") break;
        int sum = 0;
        for(int i = 0 ; i < input.size() ; i++){
            sum += (input[i] - '0');
        }
        if(sum % 9 == 0){
            int ans = recur(sum,1);
            cout << input << " is a multiple of 9 and has 9-degree " << ans << ".";
        }
        else cout << input << " is not a multiple of 9.";
        printf("\n");
    }
    return 0;
}

