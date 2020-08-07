#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    // O(n + m) solution using prefix sum
    vector <int> contains(m + 2, 0);
    for(int i = 0 ; i < n ; ++i){
        int L,R; cin >> L >> R;
        ++contains[L];
        --contains[R + 1];
    }
    for(int i = 1 ; i <= m ; ++i){
        contains[i] += contains[i - 1];   
    }
    vector <int> points; points.reserve(m);
    for(int i = 1 ; i <= m ; ++i){
        if(!contains[i]){
            points.emplace_back(i);
        } 
    }
    cout << points.size() << '\n';
    for(auto point : points){
        cout << point << " ";
    }
    cout << '\n';

    // O(n * m) solution
    // vector <pair<int,int>> segments(n);
    // for(int i = 0 ; i < n ; ++i){
    //     cin >> segments[i].first >> segments[i].second;
    // }
    // vector <int> points; points.reserve(m);
    // for(int i = 1 ; i <= m ; ++i){
    //     bool inside = false; 
    //     for(int j = 0 ; j < n ; ++j){
    //         if(i >= segments[j].first && i <= segments[j].second){
    //             inside = true;
    //             break;
    //         }
    //     }
    //     if(!inside){
    //         points.emplace_back(i);
    //     }
    // }
    // cout << points.size() << '\n';
    // for(auto point : points){
    //     cout << point << " ";
    // }
    // cout << '\n';
    return 0;
}
