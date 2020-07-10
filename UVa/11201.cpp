#include <iostream>
#include <vector>
#include <cmath>

double spanish_beauty_criterion(const std::string &word, const std::vector <double> &probability){
    double sbc = 0.0;
    for(int i = 0 ; i < word.length() ; ++i){
        sbc += (i + 1) * probability[word[i] - 'a'];
    }
    return sbc;
}

void generate_words(std::string &current_word, int target_size, std::vector <int> &frequency, const std::vector <std::vector<char>> &letters, double &sbc_total, int &counter, const std::vector <double> &probability, int index = 2){
    if(current_word.length() == target_size){
        sbc_total += spanish_beauty_criterion(current_word, probability);
        ++counter;
        return;
    }

    int parity = index % 2; // parity - 0 (even), 1(odd)
    for(int i = 0 ; i < letters[parity].size() ; ++i){
        int k = letters[parity][i] - 'a';
        int f = frequency[k];
        if(f > 0){
            current_word.push_back(letters[parity][i]);
            --frequency[k];
            generate_words(current_word, target_size, frequency, letters, sbc_total, counter, probability, index + 1);
            current_word.pop_back();
            ++frequency[k];
        }
    }
}

bool isVowel(unsigned char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void precompute(std::vector <std::vector <double>> &precomputed_table, const std::vector <std::vector <char>> &letters, const std::vector <double> &probability){
    for(int i = 0 ; i < 26 ; ++i){
        unsigned char start_char = 'a' + i;
        if(isVowel(start_char)) continue;
        std::string current_word(1, start_char);
        std::vector <int> frequency(26, 2);
        --frequency[i];
        for(int j = 0 ; j < 7 ; ++j){
            double sbc_total = 0.0;
            int counter = 0;
            generate_words(current_word, j + 1, frequency, letters, sbc_total, counter, probability);
            double sbc_average = sbc_total / counter;
            precomputed_table[i][j] = sbc_average;
        }
    }
}

void printStatus(const std::string &word, const std::vector <double> &probability, const std::vector <std::vector <double>> &precomputed_table){
    double sbc = spanish_beauty_criterion(word, probability);
    double sbc_average = precomputed_table[word[0] - 'a'][word.length() - 1]; // (start_char, length)
    constexpr double EPS = 1e-4;
    if(sbc > sbc_average || std::abs(sbc - sbc_average) < EPS){
        std::cout << "above or equal\n";
    } else{
        std::cout << "below\n";
    }
}

// withtout caching - runtime 0.570s
// with caching - 0.380s

int main(int argc, char const *argv[])
{
    const std::vector <double> probability{
        12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15,
        6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02, 0.22, 0.90, 0.52
    };
    const std::vector <std::vector <char>> letters {
        {'a', 'e', 'i', 'o', 'u'},
        {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'}
    };
    std::vector <std::vector <double>> precomputed_table(26, std::vector <double>(7)); // starting character can be any of the 26 alphabets, length is at most 7
    
    precompute(precomputed_table, letters, probability);

    int T;
    std::cin >> T;
    while(T--){    
        std::string word;
        std::cin >> word;
        printStatus(word, probability, precomputed_table);
    }
    return 0;
}
