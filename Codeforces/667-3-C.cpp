#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        int d = y - x;
        for(int i = 1 ; i <= d ; ++i){
            if(d % i == 0){
                int k = i;
                int e = d / i + 1;
                if(e > n) continue;
                int counter = 0;
                for(int j = x ; j <= y && counter < n ; j += k, ++counter){
                    cout << j << " ";
                }
                for(int j = x - k ; j > 0 && counter < n ; j -= k, ++counter){
                    cout << j << " ";
                }
                for(int j = y + k ; counter < n ; j += k, ++counter){
                    cout << j << " ";
                }
                cout << '\n';
                break;
            }
        }
    }
    return 0;
}
