#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    std::string input;
    while(std::cin >> input){
       
        std::vector <std::string> prefix;
        std::vector <std::string> suffix;

        std::string middle = "";
        int index = 0;
        while(index < input.size() && input[index] != '[' && input[index] != ']') {
            middle += input[index];
            index++;
        }

        std::string output = "";
        int i = index + 1;
        while(i < input.size()){
            while(i < input.size() && input[i] != '[' && input[i] != ']'){
                output += input[i++];
            }

            if(input[index] == '[') prefix.push_back(output);
            else suffix.push_back(output);
            output = "";
            
            while(i < input.size() && input[i] == '[' || input[i] == ']') i++;
            index = i - 1;
        }
    
        std::string out = "";
    
        for(int i = prefix.size() - 1 ; i >= 0 ; --i) out += prefix[i];
        out += middle;
        for(int i = 0 ; i < suffix.size() ; ++i) out += suffix[i];

        std::cout << out << "\n";
    }
    return 0;
}
