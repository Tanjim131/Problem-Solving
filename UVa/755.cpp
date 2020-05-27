#include<iostream>
#include<string>
#include<cstdio>
#include<set>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map <char,char> ump;

void preprocess(){
    ump.clear();
    char val = '2';
    int counter = 0;
    for(char i = 'A' ; i < 'Z' ; i++){
        if(i != 'Q'){
            ump[i] = val;
            counter++;
            if(counter % 3 == 0) val++;
        }
    }
}

string process(string input){
    string ret;
    for(int i = 0 ; i < input.size() ; i++){
        if(input[i] != '-'){
            if(input[i] >= 'A' && input[i] < 'Z'){
                ret.push_back(ump[input[i]]);
            }
            else ret.push_back(input[i]);
            if(ret.size() == 3) ret.push_back('-');
            //cout << input[i] << " " << ump[(char)input[i]] << endl;
        }
    }
    return ret;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    preprocess();
    while(T--){
        int tel;
        scanf("%d",&tel);
        multiset <string> ms;
        set <string> s;
        for(int i = 0 ; i < tel ; i++){
            string in; cin >> in;
            string p = process(in);
            s.insert(p);
            ms.insert(p);
        }

        set <string> :: iterator it;
        vector < pair <string,int> > ans;

        for(it = s.begin() ; it != s.end() ; it++){
            int cc = ms.count(*it);
            if(cc > 1){
                ans.push_back(make_pair(*it,cc));
            }
        }

        if(ans.size() == 0){
            printf("No duplicates.\n");
        }
        else{
            for(auto val : ans){
                cout << val.first << " " << val.second << '\n';
            }
        }

        if(T != 0) printf("\n");
    }
    return 0;
}
