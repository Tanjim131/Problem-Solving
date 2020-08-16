#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> v(n), sorted(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
        sorted[i] = v[i];
    }
    sort(sorted.begin(), sorted.end());
    int sorted_index = 0, index = -1;
    for(int i = 0 ; i < n - 1 ; ++i){
        if(v[i] > v[i + 1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        cout << "0\n";
        return 0;
    }
    int moves = n - index - 1;
    for(int i = index + 1 ; i < n ; ++i){
        if(v[i] == sorted[sorted_index]){
            ++sorted_index;
        } else{
            break;
        }
    }
    for(int i = 0 ; i <= index ; ++i){
        if(v[i] == sorted[sorted_index]){
            ++sorted_index;
        } else{
            break;
        }
    }

    if(sorted_index == n){
        cout << moves << '\n';
    } else{
        cout << "-1\n";
    }

    return 0;
}
