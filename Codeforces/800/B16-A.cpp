#include <iostream>
#include <vector>

using std::cin;
using std::cout;

bool isISOCompliant(const std::vector <std::vector <char>> &flag){
    std::vector <int> colors; 
    colors.reserve(flag.size());
    bool compliant = true;
    for(int i = 0 ; i < flag.size() ; ++i){
        for(int j = 0 ; j < flag[i].size() - 1; ++j){
            if(flag[i][j] != flag[i][j + 1]){
                compliant = false;
                break;
            }
        }
        if(!compliant) break;
        colors.emplace_back(flag[i][0]);
    }
    if(!compliant) return false;
    for(int i = 0 ; i < colors.size() - 1 ; ++i){
        if(colors[i] == colors[i + 1]) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    std::vector <std::vector <char>> flag(n, std::vector <char>(m));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            cin >> flag[i][j];
        }
    }
    if(isISOCompliant(flag)){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
    return 0;
}
