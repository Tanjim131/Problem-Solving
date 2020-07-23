#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits>
#include <string>

class Turtle{
    public:
        int id, position;
        Turtle(){}
        Turtle(int _id, int _pos) : id(_id), position(_pos){}
        bool operator < (const Turtle &turtle) const{
            return position < turtle.position; // max heap
        }
};

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::vector <int> actualPosition(n + 1), expectedPosition(n + 1);
        std::vector <std::string> turtles(n + 1);
        std::map <std::string, int> turtleNumbering;
         {
            int counter = 0;
            for(int i = 0 ; i < n ; ++i){
                std::string input;
                std::getline(std::cin, input);
                turtleNumbering[input] = ++counter;
                turtles[counter] = input;
                actualPosition[turtleNumbering[input]] = i;
            }
        }
        for(int i = 0 ; i < n ; ++i){
            std::string input;
            std::getline(std::cin, input);
            expectedPosition[turtleNumbering[input]] = i;
        }
        std::priority_queue <Turtle> pq;
        int sentToTop = 0;
        for(int i = actualPosition.size() - 1 ; i > 0 ; --i){
            int currentPosition = actualPosition[i] + sentToTop;
            if(currentPosition > expectedPosition[i]){
                pq.push(Turtle(i, expectedPosition[i]));
                ++sentToTop;
            }
        }
        while(!pq.empty()){
            std::cout << turtles[pq.top().id] << '\n';
            pq.pop();
        }
        std::cout << '\n';
    }
    return 0;
}
