#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

std::pair<int,int> compute(int n){
    int sqrtN = std::sqrt(n);
    int a = 1;
    for(int i = 2 ; i <= sqrtN ; ++i){
        if(n % i == 0){
            a = i;
        }
    }
    int b = n / a;
    return {a,b};
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::pair <int,int> answer = compute(n);
    cout << answer.first << " " << answer.second << '\n';
    return 0;
}
