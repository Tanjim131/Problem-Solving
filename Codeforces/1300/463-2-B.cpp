#include <iostream>
#include <vector>

using std::cin;
using std::cout;

std::vector <std::vector <int>> v(10, std::vector <int>(1000000 + 5));

int compute(int i){
    if(i < 10) return i;
    int prod = 1;
    while(i != 0){
        int rem = i % 10;
        if(rem > 1) prod *= rem;
        i /= 10;
    }
    return compute(prod);
}

void preprocess(){
    std::vector <int> output(1000000 + 5);
    for(int i = 1 ; i <= 1000000 ; ++i){
        output[i] = compute(i);
    }
    for(int k = 1 ; k <= 9 ; ++k){
        int counter = 0;
        for(int i = 1 ; i <= 1000000 ; ++i){
            if(output[i] == k){
                ++counter;
            } 
            v[k][i] = counter;
        }
    }
}

int main(int argc, char const *argv[])
{
    preprocess();
    int Q;
    cin >> Q;
    while(Q--){
        int l,r,k;
        cin >> l >> r >> k;
        cout << v[k][r] - v[k][l - 1] << '\n';
    }
    return 0;
}
