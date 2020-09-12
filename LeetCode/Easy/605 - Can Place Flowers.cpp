class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0 ; i < flowerbed.size() && count < n ; ){
            if(!flowerbed[i]){ // Greedily place flowers
                bool leftOk = i == 0 || i > 0 && flowerbed[i - 1] == 0;
                bool rightOk = i == flowerbed.size() - 1 || i < flowerbed.size() - 1 && flowerbed[i + 1] == 0;
                if(leftOk && rightOk){
                    flowerbed[i] = 1;
                    ++count;
                    i += 2; // cannot place flower in the next position
                    continue;
                }
            } 
            ++i;
        }
        return count == n;
    }
};