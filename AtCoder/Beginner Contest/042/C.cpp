#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// O(log10(n))
std::vector <int> get_digits(int num){
    std::set <int> digits;
    while(num){
        digits.insert(num % 10); // insert is O(log(n)), total insert const (log_10(n) + 1) * O(log(n))
        num /= 10;
    }
    return std::vector<int>(digits.begin(), digits.end()); // vector is sorted
}

// allowable digits containt at least 1 digit (the sole digit is never 0)
// so the following loop will certainly halt 

// worst case: N = 9999, allowable digit = 8 ?
// answer will be <= 10N, because the answer can have at most 1 extra digit
// O(NlogN) 

int construct(int payable_amount, const std::vector <int> &allowable_digits){
    int answer = -1;
    for(int i = payable_amount ; ; ++i){ // starting from payable amount, when the loop halts, the answer is guaranteed to be smallest
        std::vector <int> digits = get_digits(i);
        if(std::includes(allowable_digits.begin(), allowable_digits.end(), digits.begin(), digits.end())){
            // "allowable digits" containt all elements of "digits"
            // the two container parameters have to be sorted, here they already are sorted
            answer = i;
            break;
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    int N,K;
    std::cin >> N >> K;
    
    std::vector <int> allowable_digits;
    allowable_digits.reserve(10 - K);
    
    int start = 0;

    for(int i = 0 ; i < K ; ++i){
        int disliked_digit;
        std::cin >> disliked_digit;
        for(int j = start ; j < disliked_digit ; ++j){
            allowable_digits.emplace_back(j);
        }
        start = disliked_digit + 1;
    }
    
    for(int i = start ; i < 10 ; ++i){
        allowable_digits.emplace_back(i);
    }

    // "allowable_digits" is already sorted as the disallowable digits were given in sorted order
    std::cout << construct(N, allowable_digits) << '\n';

    return 0;
}
