#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector <int> beautiful;
    for(int i = 1 ; ; ++i){
        int num = ((1 << i) - 1) * (1 << (i - 1));
        if(num > 1e5) break;
        beautiful.emplace_back(num);
    }
    int n;
    cin >> n;
    for(int i = beautiful.size() - 1 ; i >= 0 ; --i){
        if(n % beautiful[i] == 0){
            cout << beautiful[i] << '\n';
            break;
        }
    }
    return 0;
}
