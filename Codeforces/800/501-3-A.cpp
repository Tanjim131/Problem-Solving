#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    vector <pair<int,int>> segments(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> segments[i].first >> segments[i].second;
    }
    vector <int> points;
    for(int i = 1 ; i <= m ; ++i){
        bool inside = false; 
        for(int j = 0 ; j < n ; ++j){
            if(i >= segments[j].first && i <= segments[j].second){
                inside = true;
                break;
            }
        }
        if(!inside){
            points.emplace_back(i);
        }
    }
    cout << points.size() << '\n';
    for(auto point : points){
        cout << point << " ";
    }
    cout << '\n';
    return 0;
}
