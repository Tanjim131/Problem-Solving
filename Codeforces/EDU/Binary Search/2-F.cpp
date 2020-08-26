#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// is p a sub-sequence of modified
bool isSubsequence(const string &modified, const string &p){
    int index = 0;
    for(int i = 0 ; i < modified.length() && index < p.length() ; ++i){
        if(modified[i] == p[index]){
            ++index;
        }
    }
    return index == p.length();
}

bool ok(const string &t, const string &p, const vector <int> &perm, int value){
    string modified{t};
    for(int i = 0; i < value ; ++i){
        modified[perm[i] - 1] = '#'; // any dummy character
    }
    return isSubsequence(modified, p);
}

int binary_search(const string &t, const string &p, const vector <int> &perm){
    int low = 0, high = t.length() - 1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(ok(t, p, perm, mid)){
            ans = mid;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    string t, p;
    cin >> t >> p;
    vector <int> perm(t.length());
    for(int i = 0 ; i < perm.size() ; ++i){
        cin >> perm[i];
    }
    cout << binary_search(t, p, perm) << '\n';
    return 0;
}
