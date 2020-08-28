#include <iostream>
#include <cmath>

using namespace std;

int compute_length(int n){
    if(n == 0) return 1;
    return static_cast<int>(log10(n)) + 1;
}

int compute_sod(int n){
    int sum = 0;
    while(n != 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    string n;
    cin >> n;
    if(n.length() == 1){
        cout << 0 << '\n';
        return 0;
    }
    int sod = 0;
    for(int i = 0 ; i < n.length() ; ++i){
        sod += n[i] - '0';
    }
    int counter = 1;
    while(compute_length(sod) != 1){
        sod = compute_sod(sod);
        ++counter;
    }
    cout << counter << '\n';
    return 0;
}
