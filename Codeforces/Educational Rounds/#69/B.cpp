#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::vector <int> pillars(n);
    
    int max_index = -1;
    for(int i = 0 ; i < n ; ++i){
        std::cin >> pillars[i];
        if(pillars[i] == n){
            max_index = i; 
        }
    }

    bool possible = true;
    
    for(int i = max_index - 1, j = max_index + 1 ; i > 0 || j < pillars.size() - 1; --i, ++j){
        if(i > 0 && pillars[i - 1] > pillars[i]){
            possible = false;
            break;
        }
        if(j < pillars.size() - 1 && pillars[j + 1] > pillars[j]){
            possible = false;
            break;
        }
    }
    
    if(possible){
        std::cout << "YES\n";
    } else{
        std::cout << "NO\n";
    }
    
    return 0;
}
