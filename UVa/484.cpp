#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<sstream>
#include<algorithm>

using namespace std;

#define LL long long

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string in;
	set <LL> tmps;
    vector <LL> s;
    multiset <LL> ms;
    while (getline(cin,in)){
        stringstream ss(in);
        LL crt;
        while(ss >> crt){
            s.push_back(crt);
            ms.insert(crt);
        }
	}

    vector <LL> :: iterator itr , itw;

    // input order maintain and keeping unique copy
    // We are using a vector and a set
    // while traversing the vector
    // if an element of the vector is not in the set
    // we're copying the iterator value and incrementing it
    // lastly we're erasing what remains at the last with the help of iterator

    for(itr = s.begin() , itw = s.begin() ; itr != s.end() ; itr++){
        if(tmps.insert(*itr).second){
            *itw++ = *itr;
            }
    }

    s.erase(itw,s.end());

    for(vector <LL> :: iterator it = s.begin() ; it != s.end() ; it++){
        LL cc = ms.count(*it);
        printf("%lld %lld\n",*it,cc);
    }

	return 0;
}
