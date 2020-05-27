#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,kk = 0;
    scanf("%d",&T);
    while(T--){
        int f;
        scanf("%d",&f);
        vector < set < int > > vv;
        for(int i = 0 ; i < f ; i++){
            int n;
            scanf("%d",&n);
            set < int > s;
            for(int j = 0 ; j < n ; j++){
                int x; scanf("%d",&x);
                if(s.find(x) == s.end()){
                    s.insert(x);
                }
            }
            vv.push_back(s);
        }

        vector < int > uniq;
        int tot = 0;
        for(int i = 0 ; i < f ; i++){
            int counter = 0;
            auto it = vv[i].begin();
            while(it != vv[i].end()){
                bool ff = true;
                for(int k = 0 ; k < f ; k++){
                    if(k == i) continue;
                    auto ret = vv[k].find(*it);
                    if(ret == vv[k].end()) continue;
                    else{
                        ff = false;
                        break;
                    }
                }
                if(ff) counter++;
                it++;
            }
            tot += counter;
            uniq.push_back(counter);
        }

        if(!tot) printf("Case %d: \n",++kk);
        else{
            printf("Case %d: ",++kk);
            for(int i = 0 ; i < uniq.size() ; i++){
                double kop = ((uniq[i] * 1.0)/tot) * 100.0;
                printf("%0.6f%%",kop);
                if(i != uniq.size() - 1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
