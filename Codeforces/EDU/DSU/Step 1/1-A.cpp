#include <iostream>
#include <vector>

using namespace std;

class DSU{
    vector <int> parent, rank;
    
    public:
        DSU(int n){
            parent.resize(n + 1);
            rank.assign(n + 1, 0);
            initialize_parent(n);
        }

        void initialize_parent(int n){
            for(int i = 1 ; i <= n ; ++i){
                parent[i] = i;
            }
        }

        int find_parent(int element){
            if(parent[element] == element) return element;
            return parent[element] = find_parent(parent[element]);
        }
        
        void union_by_rank(int a, int b){
            int pa = find_parent(a);
            int pb = find_parent(b);
            if(pa == pb) return;
            if(rank[pa] == rank[pb]) ++rank[pa];
            if(rank[pa] > rank[pb]){
                parent[pb] = pa;
            } else{
                parent[pa] = pb;
            }
        }
};

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for(int i = 0 ; i < m ; ++i){
        string q;
        int u,v;
        cin >> q >> u >> v;
        if(q == "union"){
            dsu.union_by_rank(u, v);
        } else{
            cout << (dsu.find_parent(u) == dsu.find_parent(v) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
