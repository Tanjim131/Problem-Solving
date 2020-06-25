#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
#include <string>

// not very efficient implementation, but as there aren't any repetitions, this is will do fine

void combination(const std::vector<std::string> &newspapers, std::vector <std::string> current_subset, int target_subset_size, int index = 0){
    // at each index, we can either take the current newspaper or leave it
    if(current_subset.size() == target_subset_size){
        // print the solution
        for(int i = 0 ; i < current_subset.size() ; ++i){
            std::cout << current_subset[i];
            if(i != current_subset.size() - 1) std::cout << ", ";
        }
        std::cout << '\n';
        return;
    }
    if(index == newspapers.size()) return; // order of checking is important
                                            // when we go past the last index, we may have a valid solution at our hand
                                            // so checking the solution condition early is necessary
    
    //std::cout << "at index " << index << " taking " << newspapers[index] << '\n';
    current_subset.emplace_back(newspapers[index]);
    combination(newspapers, current_subset, target_subset_size, index + 1);
    //std::cout << "at index " << index << " leaving " << newspapers[index] << '\n';
    current_subset.pop_back();
    combination(newspapers, current_subset, target_subset_size, index + 1); 
}

// doesn't print in lexicographical order

// void combination_iterative(const std::vector<std::string> &newspapers, int target_subset_size){
//     int newspaper_number = newspapers.size();
//     int len = 1 << newspaper_number;
//     for(int i = 0 ; i < len ; ++i){
//         int number_of_set_bits = __builtin_popcount(i);
//         if(number_of_set_bits == target_subset_size){
//             for(int j = 0 ; j < newspaper_number ; ++j){
//                 if(i & (1 << j)){
//                     std::cout << newspapers[j] << ", ";
//                 }
//             }
//             std::cout << '\n';
//         }
//     }
// }

void printSolution(const std::vector <std::string> &newspapers, int start, int end){
    int target_subset_size = start;
    do{
        std::cout << "Size " << target_subset_size << '\n';
        combination(newspapers, std::vector <std::string>(), target_subset_size);
        std::cout << '\n';
        ++target_subset_size;
    } while(target_subset_size <= end); // when printing only a single "target_subset_size", end == -1
                                        // using do_while does the job
}

void parseToken(const std::string &first_line, std::string &token1, std::string &token2){
    std::istringstream iss(first_line);
    iss >> token1 >> token2;
}

int main(int argc, char const *argv[])
{
    int M;
    std::cin >> M;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore '\n' left in the buffer by std::cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume unnecessary blank line
    std::string first_line;
    for(int i = 0 ; i < M ; ++i){
        std::getline(std::cin, first_line);
        std::string token1, token2;
        parseToken(first_line, token1, token2);
        
        std::vector <std::string> newspapers;
        std::string newspaper;
        while(std::getline(std::cin, newspaper)){
            if(newspaper.empty()) break;
            newspapers.emplace_back(newspaper);
        }

        int start = 1, end = newspapers.size();
        if(token1 != "*") {
            start = std::stoi(token1);
            if(!token2.empty()) end = std::stoi(token2);
            else end = -1;
        }
        if(i > 0) std::cout << '\n';
        printSolution(newspapers, start, end);
    }
    return 0;
}
