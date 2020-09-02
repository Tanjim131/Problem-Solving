#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    // look for farthest away pairs of AB and BA. If they are non-overlapping, then solution exists.
    // complexity: O(n)
    // left AB, right BA
    {
        int left = -1;
        for(int i = 0 ; i < s.length() - 1 ; ++i){
            if(s[i] == 'A' && s[i + 1] == 'B'){
                left = i;
                break;
            }
        }
        int right = -1;
        for(int i = s.length() - 1 ; i > 0 ; --i){
            if(s[i] == 'A' && s[i - 1] == 'B'){
                right = i - 1;
                break;
            }
        }
        if(left != -1 && right != -1 && right - left > 1){
            cout << "YES\n";
            exit(0);
        }
    }
    // left BA, right AB
    {
        int left = -1;
        for(int i = 0 ; i < s.length() - 1 ; ++i){
            if(s[i] == 'B' && s[i + 1] == 'A'){
                left = i;
                break;
            }
        }
        int right = -1;
        for(int i = s.length() - 1 ; i > 0 ; --i){
            if(s[i] == 'B' && s[i - 1] == 'A'){
                right = i - 1;
                break;
            }
        }
        if(left != -1 && right != -1 && right - left > 1){
            cout << "YES\n";
            exit(0);
        }
    }
    cout << "NO\n";
    return 0;
}
