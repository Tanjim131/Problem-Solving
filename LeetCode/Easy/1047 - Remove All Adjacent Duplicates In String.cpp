class Solution {
public:
    string removeDuplicates(string S) {
        stack <char> st;
        for(int i = 0 ; i < S.length() ; ++i){
            if(!st.empty() && S[i] == st.top()){
                while(!st.empty() && st.top() == S[i]) st.pop();
            } else{
                st.push(S[i]);   
            }
        }
        string modified(st.size(), '0');
        int i = modified.length() - 1;
        while(!st.empty()){
            modified[i--] = st.top();
            st.pop();
        }
        return modified;
    }
};