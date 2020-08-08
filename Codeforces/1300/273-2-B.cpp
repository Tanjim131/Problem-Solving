#include <iostream>
#include <cmath>

using namespace std;

long long pairs(long long people){
    return people * (people - 1) / 2;
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    long long whole = n / m;
    long long people1 = whole + 1, people2 = whole;
    int t1 = n % m, t2 = m - t1;
    long long minimum = t1 * pairs(people1) + t2 * pairs(people2); // t1 teams having floor(avg) and t2 teams having ceil(avg)
    long long maximum = pairs(n - m + 1); // m - 1 teams having 1 people and only one team having the remaining people
    cout << minimum << " " << maximum << '\n';
    return 0;
}
