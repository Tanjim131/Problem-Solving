#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> parents(n + 1);
    vector <bool> is_non_leaf_node(n + 1, false);
    is_non_leaf_node[1] = true;
    for(int i = 2 ; i <= n ; ++i){
        int parent; cin >> parent;
        parents[i] = parent;
        is_non_leaf_node[parent] = true;
    }
    vector <int> children_count(n + 1, 0);
    for(int i = 2 ; i <= n ; ++i){
        if(!is_non_leaf_node[i]){
            ++children_count[parents[i]];
        }
    }
    bool spruce = true;
    for(int i = 1 ; i <= n ; ++i){
        if(is_non_leaf_node[i] && children_count[i] < 3){
            spruce = false;
            break;
        }
    }
    cout << (spruce ? "Yes" : "No") << '\n';
    return 0;
}
