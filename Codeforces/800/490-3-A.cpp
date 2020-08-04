#include <iostream>
#include <vector>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n >> k;
    std::vector <int> v(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
    }
    int left = 0, right = n - 1;
    int counter = 0;
    while(left <= right){
        if(v[left] <= k){
            ++counter;
            ++left;
        } else if(v[right] <= k){
            ++counter;
            --right;
        } else{
            break;
        }
    }
    cout << counter << '\n';
    return 0;
}
