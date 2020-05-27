#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

template <class T>
inline string tostring (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

unsigned int a,b;
string p,q;

void clean(){
    unsigned int r = (a < b) ? a : b;
    unsigned int s = (r == a) ? b : a;
    p = tostring(r);
    q = tostring(s);
    if(p.size() != q.size()){
        int res = q.size() - p.size();
        while(res--) {p.insert(p.begin(),'0');}
    }
    p.insert(p.begin(),'0');
    q.insert(q.begin(),'0');
    //cout << "max " << q << " min " << p << endl;
}

int ret(){
    int counter = 0;
    int carry = 0;
    int len = q.size() - 1;
    //string result = "";
    for(int i = len ; i >= 0 ; i--){
        //cout << "q[i] " << q[i] << " p[i] " << p[i] << " carry " << carry << endl;
        bool f = false;
        if(i < len && carry == 1){
            //cout << "Etar moddhe" << endl;
            if(p[i] == '9') p[i] = '0' , counter++ , f = true;
            else p[i]++ , carry = 0;
        }
        //cout << "q[i] " << q[i] << " p[i] " << p[i] << " carry " << carry << endl;
        int hh = (q[i] - '0') + (p[i] - '0');
        //cout << "hh " << hh << endl;
        if(hh > 9){
            carry = 1;
            counter++;
        }
        else if(!f) carry = 0;
        //result.pb((hh % 10) + '0');
        //reverse(result.begin(),result.end());
        //cout << "Result " << result << endl;
        //reverse(result.begin(),result.end());
    }
    //reverse(result.begin(),result.end());
    //cout << "result " << result << endl;
    return counter;
}

int main(){
    //infile;outfile;
    while(scanf("%u %u",&a,&b) != EOF){
        if(!a && !b) break;
        clean();
        int counter = ret();
        if(!counter) printf("No carry operation.\n");
        else{
            if(counter < 2) printf("%d carry operation.\n",counter);
            else printf("%d carry operations.\n",counter);
        }
    }
    return 0;
}


