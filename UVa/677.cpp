#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>> &adj_matrix, std::vector<int> &visited, int target_length, std::vector <std::string> &solutions, int current_node = 1, int current_length = 0, std::string current_path = "(1"){
    if(current_length == target_length){
        // path found
        current_path += ")";
        solutions.emplace_back(current_path);
        return;
    }
    visited[current_node] = 1; // mark current node
    for(int i = 1 ; i < adj_matrix[current_node].size() ; ++i){
        int isNeighbor = adj_matrix[current_node][i];
        int neighbor = i;
        if(neighbor != current_node && isNeighbor != 0 && !visited[neighbor]){
            dfs(adj_matrix, visited, target_length, solutions, neighbor, current_length + 1, current_path + "," + std::to_string(neighbor));
        }
    }
    visited[current_node] = 0; // unset current node for reuse
}

int main(int argc, char const *argv[])
{
    int m, k = 0;
    while(std::cin >> m){
        if(m == -9999) continue;
        int target_length;
        std::cin >> target_length;
        std::vector <std::vector<int>> adjacency_matrix(m + 1, std::vector<int>(m + 1));
        for(int i = 1 ; i <= m ; ++i){
            for(int j = 1 ; j <= m ; ++j){
                std::cin >> adjacency_matrix[i][j];
            }
        }
        std::vector<int>visited(m + 1, 0);
        if(k > 0) std::cout << '\n';
        std::vector <std::string> solutions;
        dfs(adjacency_matrix, visited, target_length, solutions);
        if(!solutions.size()){
            std::cout << "no walk of length " << target_length << '\n';
        } else{
            for(int i = 0 ; i < solutions.size() ; ++i){
                std::cout << solutions[i] << '\n';
            }
        }
        ++k;
    }
    return 0;
}