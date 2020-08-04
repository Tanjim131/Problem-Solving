#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n >> k;
    std::vector <int> temps(n + 1);
    std::vector <int> range_sum(n + 1, 0);
    {
        int sum = 0;
        for(int i = 1 ; i <= n ; ++i){
            cin >> temps[i];
            sum += temps[i];
            range_sum[i] = sum;
        }
    }
    double maximum = 0.0;
    for(int i = k ; i <= n ; ++i){
        for(int j = 1 ; j + i - 1 < n + 1 ; ++j){
            int sum = range_sum[j + i - 1] - range_sum[j - 1];
            double average = sum * 1.0 / i;
            maximum = std::max(maximum, average);
        }
    }
    cout << std::setprecision(17) << maximum << '\n';
    return 0;
}
