class Solution {
public:
    int kthFactor(int n, int k) {
        vector <int> factors; 
        factors.reserve(100);
        
        int f_i = 0, f = -1 ;
        for(int i = 1 ; i * i <= n ; ++i){
            if(n % i == 0){
                ++f_i;
                if(f_i == k) {
                    f = i;
                    break;
                }
                if(i * i != n){
                    factors.emplace_back(n / i);
                }
            }
        }
        
        if(f_i == k) return f;
        if(f_i + factors.size() < k) return -1;
        return factors[factors.size() + f_i - k];
    }
};