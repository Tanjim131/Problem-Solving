#include <iostream>
#include <vector>

class Pair{
    public:
        int value,index;
        Pair(){}
        Pair(int _v, int _i) : value(_v), index(_i){}
};

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        
        std::vector <Pair> even, odd; 
        even.reserve(n); 
        odd.reserve(n);
        
        for(int i = 1 ; i <= 2 * n ; ++i){
            int x; std::cin >> x;
            if(x % 2 == 0) even.emplace_back(Pair(x, i));
            else odd.emplace_back(Pair(x, i));
        }

        if(even.size() % 2 && odd.size() % 2){
            even.pop_back(); odd.pop_back();
        } else if(even.size() < odd.size()){
            odd.pop_back(); odd.pop_back();
        } else{
            even.pop_back(); even.pop_back();
        }
        
        for(int i = 0 ; i < even.size() ; i += 2){
            std::cout << even[i].index << " " << even[i + 1].index << '\n';
        }
        for(int i = 0 ; i < odd.size() ; i += 2){
            std::cout << odd[i].index << " " << odd[i + 1].index << '\n';
        }
    }
    return 0;
}
