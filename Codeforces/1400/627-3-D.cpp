#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_greater(const vector <int> &c, int start, int key){
    int low = start, high = c.size() - 1;
    int count = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        if(c[mid] < key){
            count = mid - start + 1;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < n ; ++i) cin >> b[i];
    vector <int> c(n);
    for(int i = 0 ; i < n ; ++i){
        c[i] = b[i] - a[i];
    }
    sort(c.begin(), c.end());
    long long total = 0;
    for(int i = 0 ; i < n - 1 ; ++i){
        //int count = count_greater(c, i + 1, -c[i]);
        int count = lower_bound(c.begin() + i + 1, c.end(), -c[i]) - (c.begin() + i + 1);
        total += count;
    }
    cout << total << '\n';
    return 0;
}
