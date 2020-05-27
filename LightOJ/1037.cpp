#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int T, k = 0; std::cin >> T;
    while(T--){
        int n; std::cin >> n;
        std::vector <int> lengths(n);
        for(int i = 0 ; i < n ; ++i){
            std::cin >> lengths[i];
        }

        std::sort(lengths.begin(), lengths.end());

        // Idea: first sort the sticks and then take each pair of sticks 
        // the sum of each pair of sticks denote the sum of two triangle sides
        // to be a valid triangle, (side1 + side2 > side3) condition must be upheld
        // so we do a binary search among the stick values to see which sticks are stictly less than the sum of two sides
        // upper bound gives the index of minimum value that is greater than the provided parameter value
        // if we provided "sum" as the third parameter to the upper bound function, then it would return the value strictly greater than "sum"
        // so the just before index of the index returned by upper bound can be equal to "sum"
        // in that case a valid triangle would not be formed, we need a > relation not a >= relation
        // as the sticks values are integers, we decrement "sum" by 1 and then do upper bound
        // the upper bound of "sum - 1" is "sum" and the just before index would be strictly 
        // as we cannot use the sticks more than once, so we look for values strictly less than "sum" from j to index and add to counter
        
        int counter = 0;
        // for(int i = 0 ; i < n - 1; ++i){
        //     for(int j = i + 1 ; j < n ; ++j){
        //         int sum = lengths[i] + lengths[j];
        //         //std::cout << lengths[i] << " " << lengths[j] << " sum: " << sum << '\n';
        //         int index = std::upper_bound(lengths.begin(), lengths.end(), sum - 1) - lengths.begin() - 1;
        //         //std::cout << "(upper bound - 1) of sum " << index << '\n';
        //         counter += index - j;
        //         //std::cout << "counter " << counter << '\n';
        //     }
        // }


        // Idea: for each stick length at index i
        // iterate the stick lengths from 0 to i - 1
        // keep two variables low and hi 
        // for each index i, increment low as long as val[low] + val[high] doesn't exceed val[i]
        // when such low is found that val[low] + val[high] > val[i] come out of while loop
        // for index i and val[high], (high - low) triangles can be formed with the third side beign val[low]
        // add (high - low) to answer
        // now for each index i and each hi, we don't always need to start at low = 0
        // because inside while loop the highest "low" values is recorded 
        // so when "hi" is decremented, obviously val[low] + val[hi] will be less than val[i]
        // so we can just start from low, instead of starting from 0 every time
        // and in decrementing hi, if hi == lo then we just break the loop
        // because for all lower values of "hi" will not yield a valid triangle
        // if it was to be found, we would've found for a smaller value of "lo"

        for(int i = 0 ; i < n ; ++i){
            int low = 0;
            for(int hi = i - 1 ; hi > 0; --hi){
                while(low < hi && lengths[low] + lengths[hi] <= lengths[i]) ++low;
                if(low == hi) break; 
                counter += hi - low;
            }
        }


        std::cout << "Case " << ++k << ": " << counter << '\n';
    }
    return 0;
}
