#include <iostream>
#include <vector>

class Webpage{
    public:
        std::string url;
        int relevance;

        Webpage() = default;
};

int main(int argc, char const *argv[])
{
    int T, k = 0; 
    std::cin >> T;
    while(T--){
        std::vector <Webpage> webpages(10);
        int maxRelevance = -1;
        for(int i = 0 ; i < 10 ; ++i){
            std::cin >> webpages[i].url >> webpages[i].relevance;
            maxRelevance = std::max(maxRelevance, webpages[i].relevance);
        }
        std::cout << "Case #" << ++k << ":\n";
        for(int i = 0 ; i < 10 ; ++i){
            if(webpages[i].relevance == maxRelevance){
                std::cout << webpages[i].url << '\n';
            }
        }
    }
    return 0;
}
