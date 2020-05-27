#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

int main(int argc, char const *argv[])
{
    int n;
    std::vector <int> numbers(10000, 0);
    int index = 0;
    while(std::cin >> n){
        // online insertion sort version
        // O(n) traversal needed at most for each element, total O(n^2)
        // if we used std::sort, then O(nlogn) traversal would be needed for each element, total - O(n^2logn)
        numbers[index++] = n;
        for(int i = index - 1 ; i >= 0 ; --i){
            if(numbers[i] > n){
                std::swap(numbers[i], numbers[i + 1]);
            }
        }
        int median = -1;
        if(index % 2 == 1){
            int m_index = (index - 1) / 2;
            median = numbers[m_index];
        } else{
            int m_index1 = index / 2;
            int m_index2 = (index / 2) - 1;
            median = (numbers[m_index1] + numbers[m_index2]) / 2;
        }
        std::cout << median << '\n';
    }
    return 0;
}
