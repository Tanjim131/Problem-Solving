#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
    	cin >> a[a_i];
    }
    // Write Your Code Here
    int numOfSwaps = 0;
    for(int i = 0 ; i < n - 1 ; ++i){
        for(int j = 0 ; j < n - i - 1 ; ++j){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                ++numOfSwaps;
            }
        }
    }
    cout << "Array is sorted in " << numOfSwaps << " swaps.\n";
    cout << "First Element: " << a[0] << '\n';
    cout << "Last Element: " << a[n - 1] << '\n';
    return 0;
}
