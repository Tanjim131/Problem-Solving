class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        // string shuffled(s.length(), 0);
        // for(int i = 0 ; i < s.length() ; ++i){
        //     shuffled[indices[i]] = s[i];
        // }
        // return shuffled;
        
        // cyclic sort, worst case time complexity O(N)
        // because the indices are within 0 to n - 1
        for(int i = 0 ; i < indices.size() ; i++)
        {
              while(indices[i] != i)
              {
                  swap(s[i],s[indices[i]]);
                  swap(indices[i],indices[indices[i]]);
                       
              }
        }
        return s;
    }
};