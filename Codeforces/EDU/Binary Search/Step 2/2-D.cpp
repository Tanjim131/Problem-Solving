#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Assistant{
    int unit, limit, rest;
};

bool ok2(int unit, int limit, int rest, int t, int b){
    return b * unit + max((static_cast<int>(ceil(b * 1.0 / limit)) - 1), 0) * rest <= t;
}

int binary_search2(int unit, int limit, int rest, int t){
    int low = 0, high = 15000;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(ok2(unit, limit, rest, t, mid)){
            ans = mid;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return ans;
}

bool ok(int m, const vector <Assistant> &assistants, int t){
    int total = 0;
    for(int i = 0 ; i < (int) assistants.size() ; ++i){
        int can = binary_search2(assistants[i].unit, assistants[i].limit, assistants[i].rest, t);
        total += can;
        if(total >= m) break;
    }
    return total >= m;
}

int binary_search(int m, const vector <Assistant> &assistants){
    int low = 0, high = 2 * 1e6;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(ok(m, assistants, mid)){
            ans = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> compute_amount(int m, int t, const vector <Assistant> &assistants){
    vector <int> amount(assistants.size());
    for(int i = 0 ; i < (int) amount.size() ; ++i){
        int can = binary_search2(assistants[i].unit, assistants[i].limit, assistants[i].rest, t);
        amount[i] = min(can, m);
        m = max(m - can, 0);
    }
    return amount;
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector <Assistant> assistants(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> assistants[i].unit >> assistants[i].limit >> assistants[i].rest;
    }
    int t = binary_search(m, assistants);
    vector <int> amount = compute_amount(m, t, assistants);
    cout << t << '\n';
    for(int i = 0 ; i < n ; ++i){
        cout << amount[i] << " \n"[i == n - 1];
    }
    return 0;
}
