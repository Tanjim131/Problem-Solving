#include <iostream>
#include <algorithm>
#include <vector>

// this function adds an edge to adjacency matrix
// we use this function to build the graph
void addEdgeToGraph(std::vector<std::vector<int>> &graph, int a, int b){
    graph[a].emplace_back(b); 
    graph[b].emplace_back(a); // undirected graph
}

// returns true if the edge between a and b has already been used
bool isEdgeUsed(int a, int b, const std::vector<std::vector<char>> &edges){
    return edges[a][b] == '1' || edges[b][a] == '1'; // undirected graph, (a,b) and (b,a) are both valid edges
}

// this function incrementally marks edges when "dfs" routine is called recursively
void markEdgeAsUsed(int a, int b, std::vector<std::vector<char>> &edges){
    edges[a][b] = '1';
    edges[b][a] = '1'; // order doesn't matter, the edge can be taken in any order [(a,b) or (b,a)]
}

// this function removes edge when a node has processed all its neighbors
// this lets us to reuse this edge in the future to find newer (and perhaps longer) paths
void unmarkEdge(int a, int b, std::vector<std::vector<char>> &edges){
    edges[a][b] = '0';
    edges[b][a] = '0';
}

int dfs(const std::vector<std::vector<int>> &graph, std::vector<std::vector<char>> &edges, int current_node, int current_length = 0){
    int pathLength = -1;
    for(int i = 0 ; i < graph[current_node].size() ; ++i){
        int neighbor = graph[current_node][i];
        if(!isEdgeUsed(current_node, neighbor, edges)){
            markEdgeAsUsed(current_node, neighbor, edges);
            int ret = dfs(graph, edges, neighbor, current_length + 1);
            pathLength = std::max(pathLength, ret);
            unmarkEdge(current_node, neighbor, edges); 
        }     
    }
    return std::max(pathLength, current_length);
}

int dfsFull(const std::vector<std::vector<int>> &graph){
    int longest_path = -1;
    for(int node = 0 ; node < graph.size() ; ++node){
        std::vector<std::vector<char>> edges(graph.size(), std::vector<char>(graph.size(), '0'));
        int pathLength = dfs(graph, edges, node);
        longest_path = std::max(longest_path, pathLength);
    }
    return longest_path;
}

int main(int argc, char const *argv[])
{
    int n,m;
    while(std::cin >> n >> m){
        if(!n && !m) break;
        std::vector<std::vector<int>> graph(n);
        for(int i = 0 ; i < m ; ++i){
            int a,b;
            std::cin >> a >> b;
            addEdgeToGraph(graph, a, b);
        }
        std::cout << dfsFull(graph) << '\n';
    }
    return 0;
}
