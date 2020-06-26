#include <iostream>
#include <vector>
 
using namespace std;
 
long long dp[25];
vector<long long> number;
long long fact(int a){
    if(a == 0) return 1;
    if(dp[a] != -1) return dp[a];
    else dp[a] = a * fact(a - 1);
    return dp[a];
}
 
int main(){
    for(int i = 0 ; i < 25 ; i++) dp[i] = -1;
    for(int i = 0 ; i <= 19 ; i++){
        long long ans = fact(i);
        number.emplace_back(ans);
    }
    int T, k = 0;
    cin >> T;
    while(T--)
    {
        long long n;
        cin >> n;
        if(n == 0){
            printf("Case %d: impossible\n",++k);
            return 0;
        }
        vector<int> ret;
        for(int i = 19 ; i >= 0 ; i--){
            if(n >= number[i]){
                ret.emplace_back(i);
                n -= number[i];
                if(!n) break;
            }
        }
        if(n > 0) printf("Case %d: impossible\n",++k);
        else{
            printf("Case %d: ",++k);
            for(int i = ret.size() - 1 ; i >= 0 ; i--){
                cout << ret[i];
                cout << "!";
                if(i != 0) cout << "+";
            }
            cout << endl;
        }
    }
    return 0;
}