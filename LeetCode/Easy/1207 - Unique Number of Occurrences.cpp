class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ump;
        for(int i = 0 ; i < arr.size() ; ++i){
            ++ump[arr[i]]; 
        }
        unordered_set<int> us;
        auto it = ump.begin();
        while(it != ump.end()){ 
            int frequency = it -> second;
            if(us.find(frequency) != us.end()){
                return false;
            }
            us.insert(frequency);
            ++it;
        }
        return true;
    }
};