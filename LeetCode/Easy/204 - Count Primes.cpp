class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        vector <char> status(n + 1, '1');
        for(int i = 3 ; i * i <= n ; i += 2){
            if(status[i] == '1'){
                for(int j = i * i ; j <= n ; j += i + i){
                    status[j] = '0';
                }
            }
        }
        int counter = 1;
        for(int i = 3 ; i < n ; i += 2){
            if(status[i] == '1') ++counter;
        }
        return counter;
    }
};