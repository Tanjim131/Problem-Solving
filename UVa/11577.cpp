#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

#define pic pair <char,int>

bool cmp(pic a,pic b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else return a.second > b.second;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    string input;
    getchar();
    while(T--){
        vector < pic > vpq;
        for(int i = 0 ; i < 26 ; i++){
            vpq.push_back(make_pair('a' + i,0));
        }
        getline(cin,input);
        for(int i = 0 ; i < input.size() ; i++){
            input[i] = tolower(input[i]);
            if(input[i] >= 'a' && input[i] <= 'z') vpq[input[i] - 'a'].second++;
        }
        /* Looks like after all we don't need map :p*/
        // mapping the values to keep track
        // as we can't sort map directly , we are copying the map into a random access container like vector
        // now with the help of compare function , we can sort easily
        //vector < pair <char,int> > vpq;
        //map <char,int> :: iterator it = mp.begin();
        //while(it != mp.end()){
        //    vpq.push_back(*it);
        //    it++;
        //}
        // copying done
        sort(vpq.begin(),vpq.end(),cmp);
        //sorting done
        int freq = vpq[0].second;
        printf("%c",vpq[0].first);
        for(int i = 1 ; vpq[i].second == freq ; i++){
            printf("%c",vpq[i].first);
        }
        printf("\n");
    }
    return 0;
}
