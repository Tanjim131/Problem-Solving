#include <iostream>
#include <vector>
#include <string>

// we have find the euler paths of a given graph
// euler path: visits every edge of the graph exactly once
// we're allowed to visit a vertex more than once (not more than twice)

void unmarkEdge(int a, int b, std::vector <std::vector<int>> &edges_status){
    edges_status[a][b] = 0;
    edges_status[b][a] = 0;
}

void markEdge( int a, int b, std::vector <std::vector<int>> &edges_status){
    edges_status[a][b] = 1;
    edges_status[b][a] = 1;
}

void backtrack(const std::vector <std::vector<int>> &graph, std::vector <std::vector<int>> &edges_status, std::string euler_path = "1", int source = 0){
    if(euler_path.length() == 9){
        // used up all 8 edges and visited all 9 vertices
        std::cout << euler_path << '\n';
        //return; // not necessary; as all edges are used nor further call to backtrack will happen from here
    }

    for(int i = 0 ; i < graph[source].size() ; ++i){
        int neighbor = graph[source][i];
        if(!edges_status[source][neighbor]){
            markEdge(source, neighbor, edges_status);
            backtrack(graph, edges_status, euler_path + std::to_string(neighbor + 1), graph[source][i]);
            unmarkEdge(source, neighbor, edges_status);
        }
    }
}

int main(int argc, char const *argv[])
{
    // no input
    // manually construct the graph
    // keep the neighbor vertices in lexicographical order
    std::vector <std::vector<int>> graph = {
        {1, 2, 4},
        {0, 2, 4},
        {0, 1, 3, 4},
        {2, 4},
        {0, 1, 2, 3}
    };
    std::vector <std::vector <int>> edges_status(5, std::vector <int>(5, 0)); // initially all edges are unused
    backtrack(graph, edges_status);
    return 0;
}
