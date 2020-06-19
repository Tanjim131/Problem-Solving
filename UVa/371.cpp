#include <iostream>

//  although the problem states that the largest number can be as high as 2^32- 1
//  the pairs will be given in such a manner that it will be feasible to compute the answer in the given time limit
//  for example: 1 4294967295 this type of input will not be given

//  note:
//      -   In the event that two numbers in the interval should both produce equally long sequences, report
//          the first.
//      -   the numbers in the input might not be in the correct order (for example [a,b] can be a > b)

int computeLength(long long i){
    int counter = 0;
    do{ // use do-while instead of while because for i = 1, the length is 3
        std::lldiv_t result = std::lldiv(i,2LL);
        if(result.rem != 0){
            // odd condition
            i = 3 * i + 1;
        } else{
            i = result.quot;
        }
        ++counter;
    } while(i != 1);
    return counter;
}

class Pair{
    public:
        int number;
        int length;
        Pair(int _n, int _l): number(_n), length(_l){}
};

Pair solve(int a, int b){
    Pair ans(-1,-1);
    for(int i = a ; i <= b ; ++i){
        int counter = computeLength(i);
        if(ans.length < counter){
            ans.length = counter;
            ans.number = i;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int a,b;
    while(std::cin >> a >> b){
        if(!a && !b) break;
        if(a > b) std::swap(a,b);
        Pair ans = solve(a,b);
        std::cout << "Between " << a << " and " << b << ", " << ans.number << " generates the longest sequence of " << ans.length << " values.\n";
    }
    return 0;
}
