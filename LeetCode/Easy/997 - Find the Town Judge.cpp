class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector <int> indegree(N + 1), outdegree(N + 1);
        for(int i = 0 ; i < trust.size() ; ++i){
            int a = trust[i][0], b = trust[i][1];
            ++indegree[b]; ++outdegree[a];
        }
        for(int i = 1; i <= N ; ++i){
            if(indegree[i] == N - 1 && outdegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};