#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;

// nearly equal to 0 ?
bool isNearlyEqual(double a){
    constexpr double EPS = 1e-7;
    return std::abs(a) < EPS;
}

bool isNonDegenerate(const std::vector <int> &edge){
    int a = edge[0], b = edge[1], c = edge[2];
    return a + b > c && a + c > b && b + c > a;
}

bool isDegenerate(const std::vector <int> &edge){
    int a = edge[0], b = edge[1], c = edge[2];
    double s = (a + b + c) / 2.0;
    double area = s * (s - a) * (s - b) * (s - c);
    return isNearlyEqual(area);
}

int main(int argc, char const *argv[])
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    std::vector <std::vector<int>> edges{
        {a,b,c},
        {a,b,d},
        {a,c,d},
        {b,c,d}
    };
    for(int i = 0 ; i < edges.size() ; ++i){
        if(isNonDegenerate(edges[i])){
            cout << "TRIANGLE\n";
            return 0;
        }
    }
    for(int i = 0 ; i < edges.size() ; ++i){
        if(isDegenerate(edges[i])){
            cout << "SEGMENT\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
