#include <iostream>
#include <cstdio>
#include <sstream>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string input,ans;
    getchar();
    while(getline(cin,input)){
        stringstream ss(input);
        string temp;
        while(ss >> temp){
            if(temp == "E-N-D") break;
            string ret;
            for(int i = 0 ; i < temp.size() ; i++){
                temp[i] = tolower(temp[i]);
                if(temp[i] == '-' || (temp[i] >= 'a' && temp[i] <= 'z')) ret += temp[i];
            }
            if(ans.size() < ret.size()) ans = ret;
        }
    }
    cout << ans << "\n";
    return 0;
}
