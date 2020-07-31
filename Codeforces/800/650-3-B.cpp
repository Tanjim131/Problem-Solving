#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        std::vector <int> arr(n);
        int invalidEvenParityCounter = 0, invalidOddParityCounter = 0;
        //bool isGood = true;
        //int initialInvalidIndex = -1;
        for(int i = 0 ; i < n ; ++i){
            std::cin >> arr[i];
            if(i % 2 == 1 && arr[i] % 2 == 0){
                ++invalidEvenParityCounter;
            } else if(i % 2 == 0 && arr[i] % 2 == 1){
                ++invalidOddParityCounter;
            }
            // if(i % 2 != arr[i] % 2){
            //     isGood = false;
            //     if(initialInvalidIndex == -1) initialInvalidIndex = i;
            // }
        }
        

        // Time complexity: O(n)
        if(invalidEvenParityCounter == invalidOddParityCounter){
            // equal number of matchings are needed to make the array good
            std::cout << invalidEvenParityCounter << '\n';
        } else{
            std::cout << "-1\n";
        }

        // if(isGood){
        //     // array is already good
        //     // 0 moves needed to make it good
        //     std::cout << "0\n";
        //     continue;
        // } 
        
        // the array isn't good
        // it means that there exists at least two (index,value) pairs such that their parity mismatches
        
        // now if it's possible to make the array good, then for each invalid(index,value) pair
        // there should be another so that when these two are swapped the array becomes good
        // so from the initial invalid(index,value) pair, greedily look for another pair to swap 
        // if there's not one to be found, then the array can't be made good
        // otherwise increment count and continue with the process
        // as for one invalid pair, swapping any other invalid pair(with different parity) with itself will work
        // so greedy solution will give the correct answer

        // worst case time complexity O(n^2)

        // int moves = 0;
        // bool doesSolutionExist = true;
        // for(int i = initialInvalidIndex ; i < arr.size() ; ++i){
        //     if(i % 2 != arr[i] % 2){
        //         // mismatch occurs
        //         // find potential swapping
        //         bool doesPairExists = false;
        //         for(int j = i + 1 ; j < arr.size() ; j += 2){
        //             // increment by 2
        //             // because (index,value) = (even,odd) needs to be swapped with (odd,even) and vice versa
        //             if(j % 2 != arr[j] % 2){
        //                 // found pair
        //                 std::swap(arr[i], arr[j]);
        //                 doesPairExists = true;
        //                 ++moves;
        //                 break;
        //             }
        //         }
        //         if(!doesPairExists){
        //             doesSolutionExist = false;
        //             break;
        //         }
        //     }
        // }
        // if(doesSolutionExist){
        //     std::cout << moves << '\n';
        // } else{
        //     std::cout << "-1\n";
        // }
    }
    return 0;
}
