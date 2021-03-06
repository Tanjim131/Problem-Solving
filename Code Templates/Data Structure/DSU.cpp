class DSU{
    vector <int> parent, rank, minimum, maximum, total_elements;
    
    public:
        DSU(int n){
            parent.resize(n + 1);
            minimum.resize(n + 1);
            maximum.resize(n + 1);
            total_elements.assign(n + 1, 1);
            rank.assign(n + 1, 0);
            initialize(n);
        }

        void initialize(int n){
            for(int i = 1 ; i <= n ; ++i){
                parent[i] = i;
                minimum[i] = i;
                maximum[i] = i;
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
                total_elements[pa] += total_elements[pb];
                minimum[pa] = min(minimum[pa], minimum[pb]);
                maximum[pa] = max(maximum[pa], maximum[pb]);
            } else{
                parent[pa] = pb;
                total_elements[pb] += total_elements[pa];
                minimum[pb] = min(minimum[pa], minimum[pb]);
                maximum[pb] = max(maximum[pa], maximum[pb]);
            }
        }

        int getSize(int v){
            return total_elements[find_parent(v)];
        }

        int getMin(int v){
            return minimum[find_parent(v)];
        }

        int getMax(int v){
            return maximum[find_parent(v)];
        }
};
