#include <iostream>
#include <vector>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::vector <int> a(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
    }
    std::vector <int> steps;
    for(int i = 0 ; i < n - 1 ; ++i){
        if(a[i + 1] == 1){
            steps.emplace_back(a[i]);
        }
    }
    steps.emplace_back(a[n - 1]);
    cout << steps.size() << '\n';
    for(int step : steps){
        cout << step << " ";
    }
    return 0;
}
