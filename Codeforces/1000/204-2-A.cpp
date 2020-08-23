#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int f = 0; // count the number of 5's
    for(int i = 0 ; i < n ; ++i){
        int x; cin >> x;
        f += x == 5; // x is either 5 or 0
    }
    if(f == n){
        cout << "-1\n"; // no 0's
    } else{
        string maximum;
        int counter = f / 9 * 9; // closest multiple of 9, left to right evaluation, integer division is the same as floor
        while(counter--) maximum += '5';
        if(!maximum.empty()){ // this condition is necessary, otherwise we would be putting leading 0's
            int z = n - f - 1;
            while(z--) maximum += '0'; // 0's between 5's and the trailing 0 to make the number as large as possible
        }
        maximum += '0'; // trailing zero to make the number divisible by 10
        cout << maximum << '\n'; 
    }
    return 0;
}
