#include <iostream>
#include <limits>

int main(int argc, char const *argv[])
{
    int T, k = 0; std::cin >> T;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(T--){
        std::string input;
        std::getline(std::cin, input);
        int counter = 0;
        for(int i = 0 ; i < input.length() ; ++i){
            if(input[i] == ' ') ++counter;
            else if(input[i] - 'a' <= 14){
                counter += (input[i] - 'a') % 3 + 1;
            } else{
                int sub = input[i] - 'a' - 15;
                if(sub >= 4 && sub <= 6) counter += (sub % 4) + 1; 
                else counter += (sub % 7) + 1;
            }
            //std::cout << input[i] << " " << input[i] - 'a' << " " << counter << '\n'; 
        }
        std::cout << "Case #" << ++k << ": " << counter << '\n';
    }
    return 0;
}
