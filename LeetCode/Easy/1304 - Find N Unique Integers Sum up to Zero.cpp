class Solution {
public:
    vector<int> sumZero(int n) {
        vector <int> v; 
        v.reserve(n);
        if(n & 1) {
            v.emplace_back(0);
            --n;
        }
        n >>= 1; 
        for(int i = -n ; i <= n ; ++i){
            if(i == 0) continue;
            v.emplace_back(i);
        }
        return v;
    }
};