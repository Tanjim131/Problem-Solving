#include <iostream>
#include <cmath>

constexpr int MAXN = 1000;

int num[MAXN + 5];

int bigmod(int base, int power, int mod){
    if(power == 0) return 1;
    int ret = bigmod(base, power >> 1 , mod);
    ret = (ret * ret) % mod;
    if(power & 1) ret = (ret * base) % mod;
    return ret;
}

int main(int argc, char const *argv[])
{
     freopen("in.txt", "r", stdin);
     //freopen("out.txt", "w", stdout);
     int T, k = 0;
     std::cin >> T;
     while(T--){
         int n, K, MOD;
         std::cin >> n >> K >> MOD;

         int sum = 0;
         for(int i = 0 ; i < n ; ++i){
             std::cin >> num[i];
             sum = (sum + (num[i] % MOD)) % MOD;
         }

        int repeat = bigmod(n, K, MOD);
        int result = ( sum  * repeat) % MOD;;

        std::cout << "Case " << ++k << ": " << result << "\n";
    }
    return 0;
}
