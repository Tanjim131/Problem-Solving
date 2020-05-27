#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
#include <tuple>

constexpr double EPS = 1e-4;

class Proposal{
    public:
        std::string name;
        double price;
        int r;
        std::vector <std::string> requirements_met;
        int input_order;

        Proposal() = default;
        bool operator < (const Proposal &proposal) const{
            if(r == proposal.r){
                // if(std::abs(price - proposal.price) < EPS){
                //     return input_order < proposal.input_order;
                // }
                // return price < proposal.price;
                return std::tie(price, input_order) < std::tie(proposal.price, proposal.input_order);
            }
            return r > proposal.r;       
        }
};

int main(int argc, char const *argv[])
{
    int n,p,k = 0;
    while(std::cin >> n >> p){
        if(!n && !p) break;
        if(k > 0) std::cout << '\n';
        std::vector <std::string> requirements(n);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for(int i = 0 ; i < n ; ++i){
            std::getline(std::cin, requirements[i]);
        }
        std::vector <Proposal> proposals(p);
        for(int i = 0 ; i < p ; ++i){
            std::getline(std::cin, proposals[i].name);
            std::cin >> proposals[i].price >> proposals[i].r;            
            proposals[i].input_order = i;
            proposals[i].requirements_met.reserve(proposals[i].r);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(int j = 0 ; j < proposals[i].r ; ++j){
                std::string requirment_met;
                std::getline(std::cin, requirment_met);
                proposals[i].requirements_met.emplace_back(requirment_met);
            }
        }
        std::sort(proposals.begin(), proposals.end());
        std::cout << "RFP #" << ++k << '\n';
        std::cout << proposals[0].name << '\n';        
    } 
    return 0;
}
