#include <iostream>

int main(int argc, char const *argv[])
{
    int a,b,c,d;
    while(std::cin >> a >> b >> c >> d){
        if(!a && !b && !c && !d) break;
        int rot = 120;
        rot += (a - b + 40) % 40; // going from a to b clockwise 
        rot += (c - b + 40) % 40; // going from b to c counter-clockwise is the same as going from c to b clockwise
        rot += (c - d + 40) % 40; // going from c to d clockwise
        std::cout << rot * 9 << '\n';
    }
    return 0;
}
