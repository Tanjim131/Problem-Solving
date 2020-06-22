#include <iostream>
#include <algorithm>
#include <vector>

// you buy two items and get one for free
// in order to maximize the total discout, we have to maximize the value of free items
// so we'll incrementally pick 3 highest priced items
// in this way, we'll get the 3rd item for free
// and in each iteration, there's no other item that can provide more discount than current 3rd item
// if we proceed like this, the sum of the 3rd items in all iteration will be optimal
// meaning, there's no other order than we can choose that can provide a better answer
// as the discount depens on the other two items being priced higher
// if we continuously make the first two items as high as possible, then the discount is maximized

// take for example price of 6 items 400 350 300 250 200 150
// in the first iteration, we take two items 400 350
// now for the third choice we can take any item from the remaining ones
// and the discount will be value of the 3rd item
// if we choose 300 then the discount is maximized
// but if the choose 250, then we lose the opportunity to get the maximum discount in this iteration
// (450, 350, 250) -> 250 discount + (300, 200, 150) -> 150 discount = 400 total (sub-optimal)
// (450, 350, 300) -> 300 discount + (250, 200, 150) -> 150 discount = 450 total (optimal)

// we need the discounts to be as high priced as possible
// so after sorting what is the highest priced discount we can get?
// is is the 3rd, 6th, 9th highest priced items...

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        std::vector <int> prices(n);
        for(int i = 0 ; i < n ; ++i){
            std::cin >> prices[i];
        }
        std::sort(prices.begin(), prices.end(), std::greater<int>()); // sort in descending order
        int discount = 0;
        for(int i = 0 ; i < n ; ++i){
            if((i + 1) % 3 == 0){ // take each 3rd item
                discount += prices[i];
            }
        }
        std::cout << discount << '\n';
    }
    return 0;
}
