class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char, int> uc;
        vector <int> uc_index;
        uc_index.reserve(pattern.length());
        for(int i = 0, uc_i = 0 ; i < pattern.length() ; ++i){
            if(uc.find(pattern[i]) == uc.end()){
                uc[pattern[i]] = ++uc_i;
            }
            uc_index.emplace_back(uc[pattern[i]]);
        }
        unordered_map <string, int> uw;
        vector <int> uw_index; 
        uw_index.reserve(s.length());
        {
            istringstream iss(s);
            string word;
            int uw_i = 0;
            while(iss >> word){
                if(uw.find(word) == uw.end()){
                    uw[word] = ++uw_i;
                }
                uw_index.emplace_back(uw[word]);
            }
        }
        return uc_index == uw_index;
    }
};

// ===============================================================================

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector <string> words; 
        words.reserve(s.length());
        {
            istringstream iss(s);
            for(string word ; iss >> word ; ){
                words.emplace_back(word);
            }
        }
        if(pattern.length() != words.size()) return false;
        unordered_map <char, string> ctw;
        unordered_map <string, char> wtc;
        for(int i = 0 ; i < pattern.length() ; ++i){
            if(ctw.find(pattern[i]) == ctw.end()){
                if(wtc.find(words[i]) != wtc.end()) return false;
                ctw[pattern[i]] = words[i];
                wtc[words[i]] = pattern[i];
            } else if(ctw[pattern[i]] != words[i]){
                return false;
            }
        }
        return true;
    }
};