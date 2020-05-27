#include <iostream>
#include <vector>
#include <limits>
#include <sstream>

class Vector{
    public:
        int a,b,c;
        
        Vector(int _a, int _b, int _c) : a(_a), b(_b), c(_c){}
        Vector(const std::string &direction){
            a = b = c = 0;
            if(direction[1] == 'y'){
                b = 1;
                if(direction[0] == '-') b *= -1;
            } else{
                c = 1;
                if(direction[0] == '-') c *= -1;
            }
        }

        Vector operator * (const Vector &vector) const{
            return Vector (b * vector.c - c * vector.b , c * vector.a - a * vector.c,
                           a * vector.b - b * vector.a);
        }

        bool isNull(){
            return !a && !b && !c;
        }

        void printVector(){
            if(a){
                std::cout << ((a < 0) ? "-" : "+") << "x\n";
            } else if(b){
                std::cout << ((b < 0) ? "-" : "+") << "y\n";
            } else{
                std::cout << ((c < 0) ? "-" : "+") << "z\n";
            }
        }
};

int main(int argc, char const *argv[])
{
    int L;
    while(std::cin >> L){
        if(!L) break;
        
        std::string sequence;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, sequence);
        
        std::vector <std::string> decisions;
        decisions.reserve(L);
        
        {
            std::istringstream iss(sequence);
            std::string token;
            while(iss >> token){
                decisions.emplace_back(token);
            }
        }

        Vector last_segment(1,0,0);
        for(int i = 0 ; i < decisions.size() ; ++i){
           if(decisions[i] != "No"){
               Vector rotated(decisions[i]);
               Vector axis_of_rotation(Vector(1,0,0) * rotated);
               Vector cross_product = axis_of_rotation * last_segment;
               if(!cross_product.isNull()) last_segment = cross_product;
           }
        }
        last_segment.printVector();        
    }
    return 0;
}
