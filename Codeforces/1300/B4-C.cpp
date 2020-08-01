#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::unordered_map <std::string, int> ump;
    for(int i = 0 ; i < n ; ++i){
        std::string name;
        cin >> name;
        if(ump.find(name) == ump.end()){
            ump.insert({name, 0});
            cout << "OK\n";
        } else{
            cout << name << ++ump[name] << '\n';
        }
    }
    return 0;
}
