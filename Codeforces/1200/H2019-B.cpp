#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> angles(n);
    for(int i = 0 ; i < n ; ++i) cin >> angles[i];
    // for each angle, there's only two possible option
    // let 0 - clockwise, 1 - counterclockwise
    // iterate all possible subsets
    bool possible = false;
    for(int i = 0 ; i < (1 << n) ; ++i){
        int rotation = 0;
        for(int j = 0 ; j < n ; ++j){
            if(i & (1 << j)){
                rotation += angles[j];
            } else{
                rotation -= angles[j];
            }
        }
        if(rotation % 360 == 0){ // works even if rotation is negative
            possible = true;
            break;
        }
    }
    cout << (possible ? "YES" : "NO") << '\n';
    return 0;
}
