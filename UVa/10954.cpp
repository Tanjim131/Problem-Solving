#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;

        priority_queue < int , vector<int> , greater<int> > pq;

        for(int i = 0 ; i < n ; i++){
            int x ; scanf("%d",&x);
            pq.push(x);
        }

        int cost = 0;
        while(pq.size() > 1){
            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();
            cost += one + two;
            pq.push(one + two);
        }

        printf("%d\n",cost);
    }

    return 0;
}
