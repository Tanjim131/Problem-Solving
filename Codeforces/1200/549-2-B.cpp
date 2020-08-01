#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;

int computeProduct(const std::string &number){
    int product = 1;
    for(int i = 0 ; i < number.length() ; ++i){
        if(i == 0 && number[i] == '0') continue; // ignore leading zero
        product *= number[i] - '0';
    }
    return product;
}

int compute(int n){
    std::string number = std::to_string(n);
    int maxProduct = computeProduct(number);
    for(int i = number.length() - 1 ; i > 0 ; --i){
        if(number[i] != '9'){
            number[i] = '9';
            while(i > 0 && number[i - 1] == '0'){
                number[i - 1] = '9';
                --i;
            }
            --number[i - 1]; // no leading zero
            maxProduct = std::max(maxProduct, computeProduct(number));
        }
    }
    return maxProduct;
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << compute(n) << '\n';
    return 0;
}
