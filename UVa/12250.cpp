#include <iostream>
#include <unordered_map>

int main(int argc, char const *argv[])
{
    std::unordered_map <std::string, std::string> ump = {
        {"HELLO", "ENGLISH"}, 
        {"HOLA", "SPANISH"},
        {"HALLO", "GERMAN"}, 
        {"BONJOUR", "FRENCH"},
        {"CIAO", "ITALIAN"},
        {"ZDRAVSTVUJTE", "RUSSIAN"}
    };
    std::string name;
    int k = 0;
    while(std::cin >> name){
        if(name == "#") break;
        if(ump.find(name) != ump.end()){
            std::cout << "Case " << ++k << ": " << ump[name] << '\n';
        } else{
            std::cout << "Case " << ++k << ": UNKNOWN\n";
        }
    }
    return 0;
}
