#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, s_x, s_y;
    cin >> n >> m >> s_x >> s_y;
    cout << s_x << " " << s_y << '\n';
    cout << s_x << " " << 1 << '\n';
    for(int i = 1 ; i <= n ; ++i){
        if(i == s_x) continue;
        cout << i << " " << 1 << '\n';
    }
    for(int i = 2 ; i <= m ; ++i){
        if(i % 2 == 0){
            // bottom to up
            for(int j = n ; j >= 1 ; --j){
                if(j == s_x && i == s_y) continue;
                cout << j << " " << i << '\n';
            }
        } else{
            // top to bottom
            for(int j = 1 ; j <= n ; ++j){
                if(j == s_x && i == s_y) continue;
                cout << j << " " << i << '\n';
            }
        }
    }
    
    return 0;
}
