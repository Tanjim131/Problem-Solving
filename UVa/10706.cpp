#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <ext/numeric>

// calculates the number of digits from 1 to k
// for example, when k = 9, then there are 9 digits
// when k = 12 then there are 15 digits
int numberOfDigits(int k){
    int digitsOfK = static_cast<int>(std::floor(std::log10(k))) + 1;
    int digits = digitsOfK * (k + 1) - (__gnu_cxx::power(10, digitsOfK) - 1) / 9;
    return digits;
}

// this function calculates continuously sums up the number of digits until the sum exceed some threshold
// for example when k = 12, then from 1 to k(=12), there are a total of 15 digits
// sum = 15
// when k = 13, then from 1 to k(=13), there are a total of 17 digits
// sum = 15 + 17 = 32
// this process continues until sum > 2^31 (INT_MAX)
std::vector <long long> precalculateSumOfNumberOfDigits(){
    std::vector <long long> sumOfNumberOfDigits;
    sumOfNumberOfDigits.emplace_back(0);
    long long sum = 0;
    for(int k = 1 ; sum < std::numeric_limits<int>::max() ; ++k){
        int digits = numberOfDigits(k);
        sum += digits;
        sumOfNumberOfDigits.emplace_back(sum);
        //std::cout << "sum " << sum << '\n';
    }
    return sumOfNumberOfDigits;
}

// this function calculates count of digits of length = 1,2,3,...N
// for example if N = 2, then there are 90 numbers, each with 2 digits, so a total of 180 digits
std::vector <long long> precalculateSumOfCountOfDigitsOfGivenLength(int N = 5){
    std::vector <long long> sumOfCountNumberOfDigitsOfGivenLength(N + 1, 0);
    for(int i = 1 ; i <= N ; ++i){
        // there are 9 * 10^(i - 1) numbers of length i and each number has i digits
        // so in total there are 9 * 10^(i - 1) * i digits
        long long totalDigitsOfLengthI = 9 * __gnu_cxx::power(10, i - 1) * static_cast<long long>(i);
        sumOfCountNumberOfDigitsOfGivenLength[i] = totalDigitsOfLengthI + sumOfCountNumberOfDigitsOfGivenLength[i - 1];
    }
    return sumOfCountNumberOfDigitsOfGivenLength;
}

// extracts i-th digit (from right) of given number, 1 based indexing
int extractDigit(int number, int position){
    int mask = __gnu_cxx::power(10, position);
    int portion = number % mask;
    return portion / __gnu_cxx::power(10, position - 1);
}

int solve(int position, const std::vector<long long> &sumOfNumberOfDigits, const std::vector<long long> &sumOfCountOfDigitsOfGivenLength){
    int index1 = std::lower_bound(sumOfNumberOfDigits.begin(), sumOfNumberOfDigits.end(), position) - sumOfNumberOfDigits.begin();
    int indexStart1 = position - sumOfNumberOfDigits[index1 - 1];
    int index2 = std::lower_bound(sumOfCountOfDigitsOfGivenLength.begin(), sumOfCountOfDigitsOfGivenLength.end(), indexStart1) - sumOfCountOfDigitsOfGivenLength.begin();
    int indexStart2 = indexStart1 - sumOfCountOfDigitsOfGivenLength[index2 - 1];
    std::div_t result = std::div(indexStart2 - 1, index2);
    int number = __gnu_cxx::power(10, index2 - 1) + result.quot;
    int offset = index2 - result.rem;
    return extractDigit(number, offset);
}

int main(int argc, char const *argv[])
{
    std::vector <long long> sumOfNumberOfDigits = precalculateSumOfNumberOfDigits();
    std::vector <long long> sumOfCountOfDigitsOfGivenLength = precalculateSumOfCountOfDigitsOfGivenLength();
    int T;
    std::cin >> T;
    while(T--){
        int position;
        std::cin >> position;
        std::cout << solve(position, sumOfNumberOfDigits, sumOfCountOfDigitsOfGivenLength) << '\n';
    }
    return 0;
}
