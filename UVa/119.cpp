#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, i = 0;
    while(scanf("%d",&n) != EOF){
        if(i) printf("\n");
        i++;
        vector <string> names;
        map <string,int> mp;
        names.reserve(n);
        string input;
        getchar();
        for(int i = 0 ; i < n + 1 ; i++){
            getline(cin,input);
            stringstream ss(input);
            string qq;
            if(i == 0){
                while(ss >> qq){
                    names.push_back(qq);
                    mp.insert(make_pair(qq,0));
                }
            }
            else{
                ss >> qq;
                int amount , persons;
                ss >> amount >> persons;
                int give;
                if(persons) give = amount / persons;
                mp[qq] -= give * persons;
                while(ss >> qq) mp[qq] += give;
            }
        }

        for(auto val : names){
            cout << val << " " << mp[val] << endl;
        }
    }
    return 0;
}
