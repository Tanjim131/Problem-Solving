#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n) != EOF){
        if(!n) break;
        string in;
        getchar();
        unordered_map < string , int > ump;
        for(int i = 0 ; i < n ; i++){
            string a,b,c,d,e;
            cin >> a >> b >> c >> d >> e;
            vector < string > vs;
            vs.push_back(a);
            vs.push_back(b);
            vs.push_back(c);
            vs.push_back(d);
            vs.push_back(e);
            sort(vs.begin(),vs.end());
            string temp = vs[0] + vs[1] + vs[2] + vs[3] + vs[4];
            if(ump.find(temp) == ump.end()) ump[temp] = 1;
            else ump[temp]++;
        }
        auto it = ump.begin();
        int mx = -1;
        while(it != ump.end()){
            mx = max(mx,it -> second);
            it++;
        }
        //cout << "mx " << mx << endl;
        it = ump.begin();
        int counter = 0;
        while(it != ump.end()){
            if(it -> second == mx) counter += mx;
            it++;
        }
        printf("%d\n",counter);
    }

    return 0;
}
