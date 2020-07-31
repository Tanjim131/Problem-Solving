#include <iostream>
#include <map>

void printCount(std::map <std::string, int> &verdicts, const std::string &verdict){
    std::cout << verdict << " x " << verdicts[verdict] << '\n';
}

int main(int argc, char const *argv[])
{
    std::map <std::string, int> verdicts;
    
    int N;
    std::cin >> N;
    while(N--){
        std::string verdict;
        std::cin >> verdict;
        ++verdicts[verdict];
    }

    printCount(verdicts, "AC");
    printCount(verdicts, "WA");
    printCount(verdicts, "TLE");
    printCount(verdicts, "RE");

    return 0;
}
