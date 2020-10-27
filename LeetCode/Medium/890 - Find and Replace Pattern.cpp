class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> answers; answers.reserve(words.size());
        for(int i = 0 ; i < words.size() ; ++i){
            vector <char> ptw(26, '0'), wtp(26, '0');
            bool valid = true;
            for(int j = 0 ; j < words[i].length() ; ++j){
                if(ptw[pattern[j] - 'a'] == '0'){
                    ptw[pattern[j] - 'a'] = words[i][j];
                } else if(ptw[pattern[j] - 'a'] != words[i][j]){
                    valid = false;
                    break;
                }
                if(wtp[words[i][j] - 'a'] == '0'){
                    wtp[words[i][j] - 'a'] = pattern[j];
                } else if(wtp[words[i][j] - 'a'] != pattern[j]){
                    valid = false;
                    break;
                }
            }
            if(valid) answers.emplace_back(words[i]);
        }
        return answers;
    }
};