#include <iostream>

class Pair{
    public:
        int counter;
        std::string rep;
};

inline Pair parity(int n){
    Pair p{}; // C++11 style aggregate initialization
    while(n){
        if(n & 1) {
            p.rep += '1';
            ++p.counter;
        } else{
            p.rep += '0';
        }
        n >>= 1;
    }
    return p;
}

int main(int argc, char const *argv[])
{
    int n; 
    while(std::cin >> n && n){
        Pair ret = parity(n);
        std::cout << "The parity of ";
        for(int i = ret.rep.length() - 1 ; i >= 0 ; --i){
            std::cout << ret.rep[i];
        }
        std::cout << " is " << ret.counter << " (mod 2).\n";
    }
    return 0;
}
