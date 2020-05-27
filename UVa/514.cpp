#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n) != EOF){
        if(!n) break;
        int k;
        while(scanf("%d",&k) != EOF){
            if(!k) { printf("\n"); break; }
            stack < int > pp;
            for(int i = n ; i > 0 ; i--) pp.push(i);
            stack < int > qq;
            bool f = true;
            stack < int > s;
            s.push(k);
            for(int i = 0 ; i < n - 1 ; i++){
                int x;
                scanf("%d",&x);
                s.push(x); // this is my required order , but reversed
            }

            stack < int > ss;
            while(!s.empty()){
                ss.push(s.top());
                s.pop();
            }

            // now in the original order

            while(!pp.empty()){
                if(pp.top() == ss.top()){
                    pp.pop();
                    ss.pop();
                }
                else{
                    if(!qq.empty() && qq.top() == ss.top()){
                        ss.pop();
                        qq.pop();
                    }
                    else{
                        qq.push(pp.top());
                        pp.pop();
                    }
                }
            }

            if(ss.empty()) { printf("Yes\n"); continue; }
            else{
                while(!ss.empty() && ss.top() == qq.top()){
                    ss.pop();
                    qq.pop();
                }
                if(ss.empty()) printf("Yes\n");
                else printf("No\n");
            }
        }
    }
    return 0;
}
