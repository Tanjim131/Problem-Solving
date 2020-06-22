#include <iostream>
#include <limits>
#include <sstream>

int main(int argc, char const *argv[])
{
    int T, k = 0;
    std::cin >> T;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(T--){
        std::string contestant, judge;
        std::getline(std::cin, contestant);
        std::getline(std::cin, judge);
        
        // check if there's space in contestant's output
        bool hasSpace = false;
        for(int i = 0 ; i < contestant.length() ; ++i){
            if(contestant[i] == ' '){
                hasSpace = true;
                break;
            }
        }

        if(hasSpace){
            // concatenate the tokens
            std::istringstream iss(contestant);
            std::string token;
            std::string concatenated;
            while(iss >> token){
                concatenated += token;
            }
            // if the concatenated tokens matches judges output
            // then you've outputted unnecessary whitespaces
            if(concatenated == judge){
                std::cout << "Case " << ++k << ": Output Format Error\n";
            } else{
                // otherwise if it doesn't match even after concatenatign tokens
                // then it's wrong answer (misspelling)
                std::cout << "Case " << ++k << ": Wrong Answer\n";
            }
        } else{
            if(contestant == judge){
                // as judges output doesn't contain any whitespaces
                // and contestant output doesn't contain any whitespace as well
                // then if they match, it means they are equal character by character
                std::cout << "Case " << ++k << ": Yes\n";
            } else{
                // contestant output doesn't containt any whitespace
                // but it doesn't match judges output character by character (contains misspellings)
                std::cout << "Case " << ++k << ": Wrong Answer\n";
            }
        }
    }
    return 0;
}
