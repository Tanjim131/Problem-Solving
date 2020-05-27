#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

void process(string &s){
   for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '{' || s[i] == '}' || s[i] == ',' || s[i] == ':'){
            s.erase(i,1);
            if(i) s.insert(i," ");
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        string a,b;
        getline(cin,a);
        getline(cin,b);

        process(a);
        process(b);

        string pp,qq;

        map < string , string > OLD;
        map < string , string > NEW;

        vector < string > add;
        vector < string > sub;
        vector < string > mult;

        stringstream ss_old(a);
        stringstream ss_new(b);

        while(ss_old >> pp >> qq){
            if(OLD.find(pp) == OLD.end()) OLD.insert(make_pair(pp,qq));
        }
        while(ss_new >> pp >> qq){
            if(NEW.find(pp) == NEW.end()) NEW.insert(make_pair(pp,qq));
        }

        auto it = NEW.begin();
        while(it != NEW.end()){
            auto ret = OLD.find(it -> first);
            if(ret == OLD.end()){ // that means this entry is not in old but is in the new dictionary
                add.push_back(it -> first);
            }
            else{
                if(ret -> second != it -> second){
                    mult.push_back(it -> first);
                }
            }
            it++;
        }

        it = OLD.begin();
        while(it != OLD.end()){
            auto ret = NEW.find(it -> first);
            if(ret == NEW.end()) sub.push_back(it -> first);
            it++;
        }

        if(!add.size() && !sub.size() && !mult.size()){
            printf("No changes\n");
        }
        else{
            if(add.size()){
                printf("+");
                for(int i = 0 ; i < add.size() ; i++){
                    cout << add[i];
                    if(i != (add.size() - 1)) printf(",");
                }
                cout << "\n";
            }
            if(sub.size()){
                printf("-");
                for(int i = 0 ; i < sub.size() ; i++){
                    cout << sub[i];
                    if(i != (sub.size() - 1)) printf(",");
                }
                cout << "\n";
            }
            if(mult.size()){
                printf("*");
                for(int i = 0 ; i < mult.size() ; i++){
                    cout << mult[i];
                    if(i != (mult.size() - 1)) printf(",");
                }
                cout << "\n";
            }
        }

        printf("\n");
    }
    return 0;
}
