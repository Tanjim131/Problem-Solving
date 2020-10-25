// just counting the number of open and closed parentheses is the wrong approach
// because the parentheses can be out of order

// class Solution {
// public:
//     int minAddToMakeValid(string S) {
//         if(S.empty()) return 0;
//         stack <char> st;
//         int count = 0;
//         for(int i = 0 ; i < S.length() ; ++i){
//             if(S[i] == '('){
//                 st.push(S[i]);
//             } else{
//                 if(st.empty()) ++count;
//                 else st.pop();
//             }
//         }
//         return count + st.size();
//     }
// };

class Solution {
public:
    int minAddToMakeValid(string S) {
        if(S.empty()) return 0;
        int open_needed = 0, closed_needed = 0;
        for(int i = 0 ; i < S.length() ; ++i){
            if(S[i] == '(') ++closed_needed;
            else --closed_needed;
            
            if(closed_needed == -1){
                ++open_needed;
                ++closed_needed;
            }
        }
        return open_needed + closed_needed;
    }
};