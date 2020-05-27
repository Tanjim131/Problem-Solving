#include <iostream>
#include <unordered_map>
#include <sstream>
#include <limits>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(T--){
        std::string pieces;
        std::getline(std::cin, pieces);
        std::unordered_map<std::string,int> counter;
        {
            std::string piece;
            std::istringstream iss(pieces);
            while(iss >> piece){
                if(piece == "FM") piece = "MF";
                ++counter[piece];
            }
        }

        bool loop = false;
        if(counter["MF"]){
            if(!counter["MM"] && !counter["FF"]){
                if(counter["MF"] > 1) {
                    loop = true;
                }
            } else if(counter["MM"] == counter["FF"]){
                loop = true;
            }
        } else if(counter["MM"] > 0 && counter["FF"] > 0 && counter["MM"] == counter["FF"]) {
            loop = true;
        }

        if(loop){
            std::cout << "LOOP\n";
        } else{
            std::cout << "NO LOOP\n";
        }
    }
    return 0;
}
