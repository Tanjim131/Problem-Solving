#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    while(m--){
        int l, r, k;
        cin >> l >> r >> k;
        string modified{s};
        for(int i = l - 1 ; i < r; ++i){
            int start_pos = l - 1;
            int mapped_pos = i - start_pos;
            int substring_length = r - l + 1;
            int new_pos = start_pos + (mapped_pos + k) % substring_length;
            modified[new_pos] = s[i];
        }
        s = modified;
    }
    cout << s << '\n';
    return 0;
}
