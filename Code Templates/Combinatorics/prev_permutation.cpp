#include <iostream>
#include <algorithm>

using namespace std;

/*   Function to find lexicographically previous permutations of a string. 
 *   It returns true if the string could be rearranged as a lexicographically smaller permutation
 *   Else it returns false
 */

bool prev_permutation(string &s){
    if(s.empty()) return false;
    int i = s.length() - 1;
    // Find largest (first from end) index i such that str[i - 1] > str[i]
    while(i > 0 && s[i - 1] <= s[i]) --i;
    if(!i) return false; // if i is first index of the string, that means we are already at
                        // highest possible permutation i.e. string is sorted in ascending order
    
    // if we reach here, substring str[i..n) is sorted in ascending order
	// i.e. str[i-1] > str[i] <= str[i+1] <= str[i+2] <= ... <= str[n-1]

	// Find highest (first from end) index j to the right of index i such that
	// str[j] < str[i–1]
    int j = s.length() - 1;
    while(j > i && s[i - 1] <= s[j]) --j;
    swap(s[i - 1] , s[j]);
    reverse(s.begin() + i, s.end());
    return true;
}

// Worst case time complexity: O(n! * n) [when the string contains all distinct elements]

void generate_all_permutations(string &s){
    sort(s.rbegin(), s.rend());
    do{
        cout << s << '\n';
    } while(prev_permutation(s));
}

int main(int argc, char const *argv[])
{
    string s = "abc";
    generate_all_permutations(s);
    return 0;
}
