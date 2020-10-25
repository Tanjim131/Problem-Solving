#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class DSU{
    vector <int> parent, rank, minimum;
    
    public:
        DSU(int n, const vector <int> &costs){
            parent.resize(n + 1);
            minimum.resize(n + 1);
            rank.assign(n + 1, 0);
            initialize(n, costs);
        }

        void initialize(int n, const vector <int> &costs){
            for(int i = 1 ; i <= n ; ++i){
                parent[i] = i;
                minimum[i] = costs[i];
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
                minimum[pa] = min(minimum[pa], minimum[pb]);
            } else{
                parent[pa] = pb;
                minimum[pb] = min(minimum[pa], minimum[pb]);
            }
        }

        int getMin(int v){
            return minimum[find_parent(v)];
        }
};

int main(int argc, char const *argv[])
{
    int n, k, m;
    cin >> n >> k >> m;
    int identifier = 0;
    unordered_map <string, int> words;
    for(int i = 0 ; i < n ; ++i){
        string word; cin >> word;
        if(words.find(word) == words.end()){
            words[word] = ++identifier;
        }
    }
    vector <int> costs(n + 1);
    for(int i = 1 ; i <= n ; ++i){
        cin >> costs[i];
    }
    DSU dsu(n, costs);
    for(int i = 0 ; i < k ; ++i){
        int x; cin >> x;
        int first; cin >> first;
        for(int i = 1 ; i < x ; ++i){
            int member; cin >> member;
            dsu.union_by_rank(first, member);
        }
    }
    long long cost = 0;
    for(int i = 0 ; i < m ; ++i){
        string word; cin >> word;
        int id = words[word];
        cost += dsu.getMin(id);
    }
    cout << cost << '\n';
    return 0;
}

