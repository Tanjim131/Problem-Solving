class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string last;
        while(iss >> last);
        return last.length();
    }
};