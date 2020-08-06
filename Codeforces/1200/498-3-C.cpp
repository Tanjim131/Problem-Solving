#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::vector <int> v(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
    }
    long long max_sum = 0;
    int left = 0, right = n - 1;
    long long left_sum = 0, right_sum = 0;
    while(left <= right){
        if(left_sum <= right_sum) left_sum += v[left++];
        else if(right_sum < left_sum) right_sum += v[right--];
        if(right_sum == left_sum){
            max_sum = std::max(max_sum, left_sum);
        }
    }
    cout << max_sum << '\n';
    return 0;
}
