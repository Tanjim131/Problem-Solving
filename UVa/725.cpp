#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

constexpr int MAXN = 79;

class Fraction{
    public:
        std::string numerator;
        std::string denominator;

        Fraction(const std::string &n, const std::string &d) : numerator(n), denominator(d){}

        bool operator < (const Fraction &frac) const{
            if(numerator == frac.numerator){
                return denominator < frac.denominator;
            }
            return numerator < frac.numerator;
        }
};

std::vector <std::string> perm;
std::vector <Fraction> solution[MAXN + 5];

void generatePermutations(std::string &sequence, int index){
    if(index == sequence.size()){
        if(sequence[0] != '0') perm.push_back(sequence); // if the numerator has leading zero, then n % d != 0
    } else{
        generatePermutations(sequence, index + 1);
        for(int i = index + 1 ; i < sequence.size() ; ++i){
            std::swap(sequence[index], sequence[i]);
            generatePermutations(sequence, index + 1);
            std::swap(sequence[index], sequence[i]);            
        }
    }
}

void preprocess(){
    std::string sequence = "0123456789";
    generatePermutations(sequence, 0);

    for(int i = 0 ; i < perm.size() ; ++i){
        std::string strn = perm[i].substr(0, 5);
        std::string strd = perm[i].substr(5);

        int n = std::stoi(strn);
        int d = std::stoi(strd);

        if(n % d) continue;

        int result = n / d;
        solution[result].emplace_back(Fraction(strn, strd));
    }

    for(int i = 2 ; i <= 79 ; ++i){
        if(solution[i].size()) std::sort(solution[i].begin(), solution[i].end());
    }
}

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    preprocess();
    int n; bool flag = false;
    while(std::cin >> n){
        if(!n) break;

        if(flag){
            std::cout << "\n";
        }

        flag = true;

        if(!solution[n].size()){
            std::cout << "There are no solutions for " << n << ".\n";
        } else{
            for(int i = 0 ; i < solution[n].size() ; ++i){
                std::cout << solution[n][i].numerator << " / " << solution[n][i].denominator << " = " << n << "\n";
            }
        }
    }
    return 0;
}
