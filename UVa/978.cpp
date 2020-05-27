#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int b , sg , sb;
        scanf("%d %d %d",&b,&sg,&sb);

        priority_queue < int > pqg;
        priority_queue < int > pqb;

        for(int i = 0 ; i < sg ; i++){
            int xg; scanf("%d",&xg);
            pqg.push(xg);
        }

        for(int i = 0 ; i < sb ; i++){
            int xb; scanf("%d",&xb);
            pqb.push(xb);
        }

        int mn = min(b,min(sg,sb));

        while(!pqg.empty() && !pqb.empty()){
            vector < int > green;
            vector < int > blue;

            int i = 0;

            while(i < mn){
                green.push_back(pqg.top());
                pqg.pop();
                blue.push_back(pqb.top());
                pqb.pop();
                i++;
            }

            for(int j = 0 ; j < green.size() ; j++){
                if(green[j] > blue[j]){
                    pqg.push(green[j] - blue[j]);
                }
                else if(green[j] < blue[j]){
                    pqb.push(blue[j] - green[j]);
                }
            }

            sg = pqg.size();
            sb = pqb.size();

            mn = min(b,min(sg,sb));
        }

        if(pqg.empty() && pqb.empty()) printf("green and blue died\n");
        else if(pqg.empty() && !pqb.empty()){
            printf("blue wins\n");
            while(!pqb.empty()){
                printf("%d\n",pqb.top());
                pqb.pop();
            }
        }
        else if(!pqg.empty() && pqb.empty()){
            printf("green wins\n");
            while(!pqg.empty()){
                printf("%d\n",pqg.top());
                pqg.pop();
            }
        }

        if(T) printf("\n");
    }
    return 0;
}
