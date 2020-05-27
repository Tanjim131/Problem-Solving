#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int binder;
    string input;
    while(scanf("%d",&binder) != EOF){
        getchar();
        for(int k = 0 ; k < binder ; k++){
            getline(cin,input);
            int m,n,b;
            scanf("%d %d %d",&m,&n,&b);
            unordered_map < string , int > ump;
            int cost;
            string ingredient;
            for(int i = 0 ; i < m ; i++){
                cin >> ingredient >> cost;
                if(ump.find(ingredient) == ump.end()) ump.insert(mp(ingredient,cost));
            }

            vector < pair < int , string > > vv;
            string name;

            getchar();
            for(int i = 0 ; i < n ; i++){
                getline(cin,name);
                int qq;
                scanf("%d",&qq);
                string require;
                int x;
                int tot = 0;
                while(qq--){
                    cin >> require >> x;
                    tot += ump[require] * x;
                }
                if(b >= tot){
                    vv.pb(mp(tot,name));
                }
                getchar();
            }
            sort(vv.begin(),vv.end());
            for(int kk = 0 ; kk < input.size() ; kk++){
                input[kk] = toupper(input[kk]);
            }
            cout << input <<  "\n";
            if(vv.size() == 0) { printf("Too expensive!\n\n"); continue; }
            auto it = vv.begin();
            while(it != vv.end()){
                cout << it -> second << "\n";
                it++;
            }
            cout << "\n";
        }
    }
    return 0;
}
