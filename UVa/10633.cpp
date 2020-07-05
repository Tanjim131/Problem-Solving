#include <iostream>
#include <vector>

long long compute(long long value){
    return value - value / 10;
}

std::vector <long long> binary_search(long long n){
    long long low = 10, high = 2000000000000000000LL; // 9N / 10 = 10^18 => N_Max = 111....(19 1's)
    std::vector <long long> answers;
    while(low <= high){
        long long mid = (low + high) / 2;
        long long computedValue = compute(mid);
        if(computedValue == n){
            if(compute(mid - 1) == n) answers.emplace_back(mid - 1);
            answers.emplace_back(mid);
            if(compute(mid + 1) == n) answers.emplace_back(mid + 1);
            break;
        } else if(computedValue < n){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return answers;
}

void printAnswers(const std::vector <long long> &answers){
    for(int i = 0 ; i < answers.size() ; ++i){
        std::cout << answers[i];
        if(i != answers.size() - 1) std::cout << " ";
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    long long n;
    while(std::cin >> n && n){
        std::vector <long long> answers = binary_search(n);
        printAnswers(answers);
    }
    return 0;
}
