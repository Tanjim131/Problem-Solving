#include <iostream>
#include <vector>
#include <algorithm>

class Count{
    public:
        int zero_count, one_count;
        Count() = default;
};

int main(int argc, char const *argv[])
{
    std::string sequence;
    int k = 0;
    while(std::cin >> sequence){
        std::vector <Count> counter(sequence.length());

        if(sequence[0] == '0') ++counter[0].zero_count;
        else ++counter[0].one_count;

        for(int i = 1 ; i < sequence.length() ; ++i){
            if(sequence[i] == sequence[i - 1]){
                if(sequence[i] == '0'){
                    counter[i].zero_count = counter[i - 1].zero_count + 1;
                } else{
                    counter[i].one_count = counter[i - 1].one_count + 1;
                }
            } else{
                if(sequence[i] == '0'){
                    ++counter[i].zero_count;
                } else{
                    ++counter[i].one_count;
                }
            }
        }

        // for(int i = 0 ; i < sequence.length() ; ++i){
        //     std::cout << i << ": " << counter[i].zero_count << "," << counter[i].one_count << '\n';
        // }

        int T;
        std::cin >> T;
        std::cout << "Case " << ++k << ":\n";
        while(T--){
            int i,j;
            std::cin >> i >> j;
            int min_index = std::min(i,j);
            int max_index = std::max(i,j);

            int range = max_index - min_index + 1;

            // check for zero
            // between index min and max, there should be exactly max - min + 1 zeroes if all are zeroes
            int actual_zero_count = counter[max_index].zero_count;
            if(min_index != 0){
                actual_zero_count -= counter[min_index - 1].zero_count;
            } 

            if(actual_zero_count == range){
                std::cout << "Yes\n";
                continue;
            }

            int actual_one_count = counter[max_index].one_count;
            if(min_index != 0){
                actual_one_count -= counter[min_index - 1].one_count;
            }

            if(actual_one_count == range){
                std::cout << "Yes\n";
                continue;
            }

            std::cout << "No\n";
        }
    }
    return 0;
}
