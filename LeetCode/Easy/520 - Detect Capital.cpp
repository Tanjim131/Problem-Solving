class Solution {
public:
    bool is_capital(unsigned char c){
        return c >= 'A' && c <= 'Z';
    }
    
    bool detectCapitalUse(string word) {
        if(!is_capital(word[0])){
            for(int i = 1 ; i < word.length() ; ++i){
                if(is_capital(word[i])) return false;
            }
            return true;
        }             
        bool capital = false, small = false;
        for(int i = 1 ; i < word.length() ; ++i){
            if(is_capital(word[i])){
                capital = true;
            } else{
                small = true;
            }
            if(capital && small) return false;
        }
        return true;
    }
};