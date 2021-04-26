#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector <int> v(n);
        int smallest = 101; 
        int second_smallest = 101;
        for(int i = 0 ; i < n ; ++i){
            cin >> v[i];
            if(smallest > v[i]){
                second_smallest = smallest;
                smallest = v[i];
            } else if(second_smallest > v[i]){
                second_smallest = v[i];
            }
        }
        int sum = smallest + second_smallest;
        bool possible = true;
        for(int i = 0 ; i < n ; ++i){
            if(v[i] <= d) continue;
            else if(sum > d){
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
