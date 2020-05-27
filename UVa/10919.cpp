#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
#include <unordered_map>

int main(int argc, char const *argv[])
{
    int k;
    while(std::cin >> k){
        if(!k) break;
        int m;
        std::cin >> m;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::string input;
        std::getline(std::cin, input);
        
        std::unordered_map <std::string, bool> courses_taken;

        {
            std::string token;
            std::istringstream ss(input);
            while(ss >> token){
                courses_taken[token] = true; // all courses taken are distinct
            }
        }

        bool requirements_met = true;
        for(int i = 0 ; i < m ; ++i){
            std::string input;
            std::getline(std::cin, input);
        
            std::string token;
            std::istringstream ss(input);
            
            ss >> token >> token;
            int minimum_required_courses = std::stoi(token);

            int courses_taken_in_this_category = 0;
            while(ss >> token){
                if(courses_taken.find(token) != courses_taken.end()){
                    ++courses_taken_in_this_category;
                }
            }
            if(courses_taken_in_this_category < minimum_required_courses){
                requirements_met = false;
            }
        }
        
        if(requirements_met){
            std::cout << "yes\n";
        } else{
            std::cout << "no\n";
        }
    }
    return 0;
}
