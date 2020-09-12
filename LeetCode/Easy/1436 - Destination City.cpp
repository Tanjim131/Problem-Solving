class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map <string, int> outdegree;
        unordered_set <string> cities;
        for(int i = 0 ; i < paths.size() ; ++i){
            string cA = paths[i][0], cB = paths[i][1];
            if(cities.find(cA) == cities.end()){
                cities.insert(cA);
            }
            if(cities.find(cB) == cities.end()){
                cities.insert(cB);
            }
            ++outdegree[cA];
        }
        string answer;
        for(const auto &it : cities){
            if(outdegree[it] == 0){
                answer = it;
                break;
            }
        }
        return answer;
    }
};