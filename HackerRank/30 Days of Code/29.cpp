#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int rightmostZeroBit(unsigned n){
    int index = 0;
    while(n != 0){
        if((n & 1) == 0) break;
        n >>= 1;
        ++index;
    }
    return index;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        int answer = 0;
        // k is a power of 2
        if(!(k & (k - 1))){
            // let k = 2^q
            int q = static_cast<int>(log2(k));
            int required = (1 << (q + 1)) - 1;
            if(required > n){
                answer = k - 2;
            } else{
                answer = k - 1;
            }
        } else{
            int index = rightmostZeroBit(k - 1);
            // try to place 1 in index
            int required = (k - 1) | (1 << index);
            if(required > n){
                answer = k - 2;
            } else{
                answer = k - 1;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
