#include <iostream>
#include <vector>
#include <cmath>

// the mean of N numbers will minimize the cost
// let x = (a_1 + a_2 + ... + a_N) / N be the mean of given N numbers
// then (a_1 - x)^2 + (a_2 - x)^2 + .... + (a_N - x)^2 is minimzed
// so we're interested in turning all the numbers into the mean
// but the mean can be a fraction and we're only interested in integers
// so if x is a fraction we'll round it to the nearest integer


int main(int argc, char const *argv[])
{
    int N;
    std::cin >> N;
    std::vector <int> numbers(N);
    
    int sum = 0;
    for(int i = 0 ; i < N ; ++i) {
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    std::div_t result = std::div(sum, N);
    int mean = result.quot;
    if(result.rem > 0){
        // mean is a fraction
        mean = static_cast<int>(std::round(sum * 1.0 / N));
    }

    int cost = 0;
    for(int i = 0 ; i < N ; ++i){
        int difference = mean - numbers[i];
        if(numbers[i] > mean){
            difference = numbers[i] - mean;
        }
        cost += difference * difference;
    }

    std::cout << cost << '\n';

    return 0;
}
