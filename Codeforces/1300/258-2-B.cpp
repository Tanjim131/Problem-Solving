#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];  
    }
    // O(nlogn) solution
    vector <int> sorted(a.begin(), a.end());
    sort(sorted.begin(), sorted.end());
    int index = 0;
    while(index < n){
        if(a[index] != sorted[index]) break;
        ++index;
    }
    if(index == n){
        // no mismatch
        cout << "yes\n";
        cout << "1 1\n";
        return 0;
    }
    int start = ++index;
    while(index < n){
        if(a[index - 1] < a[index]){
            break;
        }
        ++index;
    }
    bool possible = true;
    for(int i = index ; i < n ; ++i){
        if(a[i] != sorted[i]){
            possible = false;
            break;
        }
    }
    if(possible){
        cout << "yes\n";
        cout << start << " " << index  << '\n';
    } else{
        cout << "no\n";
    }
    return 0;
}
