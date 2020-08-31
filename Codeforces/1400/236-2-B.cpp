#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
    }
    // answer depends only on the height of the first tree (a_0, a_0 + k, a_0 + 2k, ... , a_0 + (n - 1) * k)
    // brute force the height of the first tree [1, 1000]
    int best_height = -1;
    int minimum_operations = numeric_limits<int>::max();
    for(int height = 1 ; height <= 1000 ; ++height){
        // for each height of the first tree, find the other heights (height_j = height + j * k)
        // then find the number of operations
        int operations = 0;
        for(int j = 0 ; j < n ; ++j){
            if(height + j * k != a[j]){
                ++operations;
            }
        }
        if(minimum_operations > operations){
            minimum_operations = operations;
            best_height = height;
        }
    }
    cout << minimum_operations << '\n';
    for(int i = 0 ; i < n ; ++i){
        int new_height = best_height + i * k;
        if(new_height > a[i]){
            cout << "+ " << i + 1 << " " << new_height - a[i] << '\n';
        } else if(new_height < a[i]){
            cout << "- " << i + 1 << " " << a[i] - new_height << '\n';
        }
    }
    return 0;
}
