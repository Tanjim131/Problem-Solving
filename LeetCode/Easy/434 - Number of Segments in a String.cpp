class Solution {
public:
    int countSegments(string s) {
        istringstream iss(s);
        int segments = 0;
        for(string word ; iss >> word ; ++segments);
        return segments;
    }
};