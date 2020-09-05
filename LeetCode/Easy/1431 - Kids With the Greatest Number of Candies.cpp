class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum = *max_element(candies.begin(), candies.end());
        vector <bool> output(candies.size());
        for(int i = 0 ; i < candies.size() ; ++i){
            if(candies[i] + extraCandies >= maximum){
                output[i] = true;
            } else{
                output[i] = false;
            }
        }
        return output;
    }
};