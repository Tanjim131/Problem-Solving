#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n) != EOF){
        priority_queue <int> pq;
        queue <int> q;
        stack <int> s;

        vector <int> out;

        bool prq = true , qq = true , ss = true;

        for(int i = 0 ; i < n ; i++){
            int a , b; scanf("%d %d",&a,&b);

            if(a == 1){
                pq.push(b);
                q.push(b);
                s.push(b);
            }
            else{
                if(pq.empty() || pq.top() != b) prq = false;
                else pq.pop();
                if(q.empty() || q.front() != b) qq = false;
                else q.pop();
                if(s.empty() || s.top() != b) ss = false;
                else s.pop();
            }
        }

        if(!prq && !qq && !ss) printf("impossible\n");
        else if(prq && !qq && !ss) printf("priority queue\n");
        else if(!prq && qq && !ss) printf("queue\n");
        else if(!prq && !qq && ss) printf("stack\n");
        else printf("not sure\n");
    }
    return 0;
}
