#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
    //Write your code here
    private:
        queue <char> q;
        stack <char> s;
    public:
        void pushCharacter(char c){
            s.push(c);
        }
        void enqueueCharacter(char c){
            q.push(c);
        }
        char popCharacter(){
            char topCharacter = s.top();
            s.pop();
            return topCharacter;
        }
        char dequeueCharacter(){
            char frontCharacter = q.front();
            q.pop();
            return frontCharacter;
        }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}