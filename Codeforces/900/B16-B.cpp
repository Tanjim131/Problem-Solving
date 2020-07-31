#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

class Container{
    public:
        int matchbox, matches;
        bool operator < (const Container &container) const{
            return matches > container.matches;
        }
};

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    std::vector <Container> containers(m);
    for(int i = 0 ; i < m ; ++i){
        cin >> containers[i].matchbox >> containers[i].matches;
    }
    std::sort(containers.begin(), containers.end());
    int matches = 0;
    for(int i = 0 ; i < containers.size() ; ++i){
        matches += std::min(n, containers[i].matchbox) * containers[i].matches;
        n -= containers[i].matchbox;
        if(n < 0) break;
    }
    cout << matches << '\n';
    return 0;
}
