#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

const double eps = 1e-9;
vector < string > vs;

bool check(double val){
    double tot = val;
    int leak = 0;
    double rate = 0.0;
    double prev = 0.0;
    int diff = 0;
    for(int i = 0 ; i < vs.size() ; i++){
        //cout << "tot here " << tot << endl;
        if(tot < 0.0) return false;
        stringstream ss(vs[i]);
        int dis ; string temp;
        ss >> dis >> temp;
        if(temp == "Fuel"){
            int fu; ss >> temp >> fu;
            diff = dis - diff;
            tot -= diff * rate;
            rate -= (prev * 1.0)/100;
            rate += (fu * 1.0)/100.0;
            //cout << "tot " << tot << " Rate " << rate << endl;
            prev = fu;
            diff = dis;
        }
        else if(temp == "Leak"){
            //cout << "diff " << diff << " dis " << dis << endl;
            diff = dis - diff;
            tot -= diff * rate;
            //cout << "tot " << tot << " Rate " << rate << endl;
            leak++; rate += 1;
            diff = dis;
        }
        else if(temp == "Gas"){
            diff = dis - diff;
            tot -= diff * rate;
            if(tot < 0.0) return false;
            //cout << "tot " << tot << " Rate " << rate << endl;
            tot = val;
            //cout << "tot " << tot << endl;
            diff = dis;
        }
        else if(temp == "Mechanic"){
            diff = dis - diff;
            tot -= diff * rate;
            rate -= leak;
            //cout << "tot " << tot << " Rate " << rate << endl;
            leak = 0;
            diff = dis;
        }
        else if(temp == "Goal"){
            //cout << "diff " << diff << " dis " << dis << " Rate " << rate << endl;
            diff = dis - diff;
            //cout << "diff 2 " << diff << endl;
            tot -= diff * rate ;
            //cout << "tot " << tot << endl;
        }
    }
    return tot > 0 || abs(tot - 0.0) < eps;
}

double binary(){
    double low = 0.0;
    double high = 100000.0;
    double ans = -1.0;

    while((high - low) > eps){
        double mid = (low + high)/2.0;

        if(check(mid)){
            ans = mid;
            high = mid;
        }
        else low = mid;
    }
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string input;
    while(getline(cin,input)){
        if(input == "0 Fuel consumption 0") break;
        vs.push_back(input);
        while(getline(cin,input)){
            stringstream ss(input);
            int cc ; string temp;
            ss >> cc >> temp;
            vs.push_back(input);
            if(temp == "Goal") break;
        }
        printf("%0.3f\n",binary());
        vs.clear();
    }
    return 0;
}
