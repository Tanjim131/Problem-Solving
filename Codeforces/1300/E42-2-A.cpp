#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> v(n);
    int sum = 0;
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
        sum += v[i];
    }
    int half = static_cast<int>(ceil(sum / 2.0));
    int days = 0;
    for(int i = 0, sum = 0 ; i < n ; ++i){
        sum += v[i];
        if(sum >= half){
            days = i + 1;
            break;
        }
    }
    cout << days << '\n';
    return 0;
}
