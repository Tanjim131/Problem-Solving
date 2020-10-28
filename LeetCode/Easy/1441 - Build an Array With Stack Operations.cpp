class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index = 0;
        vector <string> operations; operations.reserve(n);
        for(int i = 1 ; index < target.size() ; ++i){
            if(i == target[index]){
                operations.emplace_back("Push");
                index++;
            } else{
                operations.emplace_back("Push");
                operations.emplace_back("Pop");
            }
        }
        return operations;
    }
};