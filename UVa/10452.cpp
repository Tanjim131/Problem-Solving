#include <iostream>
#include <vector>
#include <unordered_map>

class Point{
    public:
        int x,y;
        
        Point(){}
        Point(int _x, int _y) : x(_x),y(_y){}
        
        Point operator + (const Point &point) const{
            return Point(x + point.x, y + point.y);
        }

        bool valid(const std::vector<std::vector<char>> &path) const {
            return x >= 0 && x < path.size() && y >= 0 && y < path[x].size();
        }

        bool contains(const std::vector<std::vector<char>> &path, int index, const std::string &order = "IEHOVA#") const{
            return path[x][y] == order[index];
        }
};

std::vector <Point> neighbors {{-1, 0}, {0, -1}, {0, 1}};
std::unordered_map <int,char> ump{{0, 'f'}, {1, 'l'}, {2, 'r'}};

void dfs(const Point &current_position, std::vector<std::vector<int>> &visited, const std::vector<std::vector<char>> &path, std::string &answer, int index = 0, const std::string &order = "IEHOVA#"){
    if(index == order.length()) return;
    
    if(visited[current_position.x][current_position.y]) return;
    visited[current_position.x][current_position.y] = true;
    // from this position we can go to 3 neighboring cells

    for(int i = 0 ; i < 3 ; ++i){
        Point next_position(current_position + neighbors[i]);
        if(next_position.valid(path) && next_position.contains(path, index, order)){
            answer += ump[i];
            dfs(next_position, visited, path, answer, index + 1);
        }
    }  
}

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int m,n;
        std::cin >> m >> n;
        std::vector<std::vector<char>> path(m, std::vector<char>(n));
        std::vector<std::vector<int>> visited(m, std::vector<int>(n,0));
        Point start_position;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                std::cin >> path[i][j];
                if(path[i][j] == '@'){
                    start_position.x = i;
                    start_position.y = j;
                }
            }
        }
        std::string sequence;
        dfs(start_position, visited, path, sequence);
        for(int i = 0 ; i < sequence.length() ; ++i){
            if(sequence[i] == 'f') std::cout << "forth";
            else if(sequence[i] == 'r') std::cout << "right";
            else std::cout << "left";
            if(i != sequence.length() - 1) std::cout << " ";
        }
        std::cout << '\n';
    }
    return 0;
}
