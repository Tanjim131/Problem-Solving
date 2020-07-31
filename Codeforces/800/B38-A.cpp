#include <iostream>
#include <vector>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::vector <int> required(n - 1);
    for(int i = 0 ; i < n - 1 ; ++i){
        cin >> required[i];
    }
    int a,b;
    cin >> a >> b;
    int years = 0;
    for(int i = a ; i < b ; ++i){
        years += required[i - 1];
    }
    cout << years << '\n';
    return 0;
}
