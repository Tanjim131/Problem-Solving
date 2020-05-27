#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    getchar(); // first getchar to handle a blank line
    getchar(); // this getchar is used to handle newline character
    while(T--){
        map < string , int > mp;
        string input;
        int tot = 0;

        while(getline(cin,input) && input != ""){
            if(mp.find(input) == mp.end()) mp[input] = 1;
            else mp[input]++;
            tot++;
        }

        auto it = mp.begin();

        while(it != mp.end()){
            double rat = ((it -> second) * 100.0)/tot;
            cout << it -> first;
            printf(" %0.4f\n",rat);
            it++;
        }

        if(T) printf("\n"); // print a blank line between test cases
    }
    return 0;
}
