#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>

bool backtrack(const std::vector<std::vector<int>> &graph, std::vector <char> &visited, int source, int destination, std::vector <int> &path){
    if(visited[source] == '1'){
        if(source == destination && path.size() == graph.size()) return true; // all nodes have been visited at this point
        return false;
    }
    
    bool cycle_found = false;
    
    for(int i = 0 ; i < graph[source].size() ; ++i){
        int neighbor = graph[source][i];
        visited[source] = '1';
        path.emplace_back(source);
        if(backtrack(graph, visited, neighbor, destination, path)){
            cycle_found = true;
            break;
        }
        path.pop_back(); // backtrack
        visited[source] = '0'; // backtrack
    }

    return cycle_found;
}

void addEdge(int u, int v, std::vector <std::vector<int>> &graph){
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

int main(int argc, char const *argv[])
{
    int nodes;
    while(std::cin >> nodes){
        std::vector <std::vector <int>> graph(nodes);
        
        std::string input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while(std::getline(std::cin, input) && input != "%"){
            std::istringstream iss(input);
            int u,v;
            iss >> u >> v;
            addEdge(--u,--v,graph); // 0-based indexing
        }


        // if the graph is disconnected or has no hamiltonian cycle it will return false
        // nodes are numbered from 1 to n
        // initially source and destination are the same (intermediate function calls have different source), we're free to choose any node as source
        std::vector <char> visited(nodes, '0');
        std::vector <int> path; path.reserve(nodes);
        bool cycle_found = backtrack(graph, visited, 0, 0, path);
        
        if(!cycle_found){
            std::cout << "N\n";
            continue;
        }
    
        for(int i = 0 ; i < path.size() ; ++i){
            std::cout << path[i] + 1 << " ";
        }
        std::cout << "1\n"; // complete cycle
    }
    return 0;
}
