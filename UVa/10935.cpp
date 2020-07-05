#include <iostream>
#include <queue>

int main(int argc, char const *argv[])
{
    int n;
    while(std::cin >> n && n){
        std::queue<int> cards, discarded;
        for(int i = 1 ; i <= n ; ++i) cards.push(i);
        while(cards.size() != 1){
            discarded.push(cards.front());
            cards.pop();
            cards.push(cards.front());
            cards.pop();
        }
        std::cout << "Discarded cards:";
        while(!discarded.empty()){
            std::cout << " " << discarded.front();
            if(discarded.size() != 1) std::cout << ",";
            discarded.pop();
        }
        std::cout << "\nRemaining card: " << cards.front() << '\n';
    }
    return 0;
}
