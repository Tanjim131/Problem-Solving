#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int T, k = 0;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(T--){
        string input;
        getline(cin, input);
        istringstream iss(input);
        int n; iss >> n;
        vector <int> v(n);
        long long numerator = n;
        for(int i = 0 ; i < n ; ++i){
            iss >> v[i];
            numerator *= v[i];
        }
        long long denominator = 0;
        for(int i = 0 ; i < n ; ++i){
            denominator += numerator / n / v[i];
        }
        long long g = __gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        cout << "Case " << ++k << ": " << numerator << "/" << denominator << '\n';
    }
    return 0;
}
