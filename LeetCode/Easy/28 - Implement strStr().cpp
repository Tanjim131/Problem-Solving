class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int hl = 0, hh = 0, ni = 0; // haystack low, haystack high, needle index
        while(hl < haystack.length() && hh < haystack.length() && ni < needle.length()){
            if(haystack[hh] == needle[ni]){
                ++hh;
                ++ni;
            } else{
                ++hl;
                if(haystack[hl] == needle[0]){
                    hh = hl;
                    ni = 0;
                }
            }
        }
        return ni == needle.length() ? hl : -1;
    }
};