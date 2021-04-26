#include <iostream>

using namespace std;

// initial assumption: take an odd, then take all the evens, and fill the rest with odds in pairs
// problem: if all the evens are taken, then a pair of odds may not be accommodated

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int even_count = 0, odd_count = 0;
        for(int i = 0 ; i < n ; ++i){
            int num; cin >> num;
            if(num % 2 == 0) ++even_count;
            else ++odd_count;
        }
        if(!odd_count){
            cout << "No\n"; // no odds, not possible
        } else{
            if(!even_count){ // no evens, possible if we are to take odd number of numbers
                cout << (x % 2 == 1 ? "Yes" : "No") << '\n';
            } else{ // contains at least one even and at least one odd
                if(even_count >= x - 1) cout << "Yes\n"; // check if there are enough evens after taking one odd
                else{
                    x = x - 1 - even_count; // if not take all the evens
                    if(x % 2 == 1) ++x; // if the remaining slots are odd, then exclude one even to make room for odd pairs
                    if(odd_count - 1 >= x){ // check if there are enough odd pairs
                        cout << "Yes\n";
                    } else{
                        cout << "No\n";
                    }
                }
            }
        }
    }
    return 0;
}
