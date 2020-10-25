#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0 ; i < n ; ++i) cin >> v[i];
        int mxe = *max_element(v.begin(), v.end());
        int index = -1;
        bool possible = any_of(v.begin(), v.end(), [&](int i){ return i != mxe; });
        if(possible){
            for(int i = 0 ; i < n ; ++i){
                if(v[i] == mxe){ // check if the max element is trapped between two more max elements
                    if(i > 0 && v[i - 1] != mxe || i < n - 1 && v[i + 1] != mxe){ // if not this can be the dominant index
                        index = i + 1;
                        break;
                    }
                }
            }
        }
        cout << index << '\n';
    }
    return 0;
}
