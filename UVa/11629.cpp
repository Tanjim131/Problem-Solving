#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;

bool process(int val,int check,string comp){
    //val = round(val);

    if(comp == "="){
        if(val == check) return true;
        return false;
    }
    else if(comp == ">"){
        if(val > check) return true;
        return false;
    }
    else if(comp == ">="){
        if(val >= check) return true;
        return false;
    }
    else if(comp == "<"){
        if(val < check) return true;
        return false;
    }
    else if(comp == "<="){
        if(val <= check) return true;
        return false;
    }
}

/**

Only important thing in this problem
is floating point comparison. So to
avoid that, we devise a grand plan. :p
because input in given only one one place
after the decimal place, rather than taking
the input as double, we take input as integer
the whole part and fractional part namely.

so, our number will be = 10 * whole part + fractional part
and upon checking we just multiply our checking value
by an order of 10.

the rest is trivial.

**/

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m,n;
    while(scanf("%d %d",&m,&n) != EOF){
        unordered_map < string , double > ump;
        string in;
        int a,b;

        for(int i = 0 ; i < m ; i++){
            cin >> in;
            scanf("%d.%d",&a,&b);
            if(ump.find(in) == ump.end()){
                ump.insert(make_pair(in,10 * a + b));
            }
        }

        vector < string > vv;
        getchar();
        int tot = 0;

        for(int i = 0 ; i < n ; i++){
            getline(cin,in);
            stringstream ss(in);

            while(ss >> in){
                if(in == "+") tot++;
                else vv.push_back(in);
            }

            int len = vv.size();
            double predict = 0;
            for(int i = 0 ; i < tot + 1 ; i++){
                predict += ump[vv[i]];
            }

            int check = atoi(vv[len - 1].c_str());
            string comp = vv[len - 2];

            //cout << "predict " << predict * 1000000 << " check " << check * 1000000 << " comp " << comp << endl;

            bool ret = process(predict,10 * check,comp);

            if(ret) printf("Guess #%d was correct.\n",i + 1);
            else printf("Guess #%d was incorrect.\n",i + 1);

            vv.clear();
            tot = 0;
        }
    }
    return 0;
}
