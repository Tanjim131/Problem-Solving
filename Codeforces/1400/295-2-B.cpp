#include <iostream>

using namespace std;

// why does the problem becomes easy when tackled backward?

int compute_steps(int source, int destination){
    if(source == destination) {
        return 0;
    }
    if(source % 2 == 0 && source > destination){
        return 1 + compute_steps(source / 2, destination);
    }
    return 1 + compute_steps(source + 1, destination);
}

int main(int argc, char const *argv[])
{
    int source, destination;
    cin >> source >> destination;
    if(source >= destination){
        cout << source - destination << '\n';
        return 0;
    }
    // start from destination and try to reach source
    cout << compute_steps(destination, source) << '\n';
    return 0;
}
