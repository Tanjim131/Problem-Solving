#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Bottle{
    int self, other;
};

int main(int argc, char const *argv[])
{
    // O(nlogn) solution
    int n;
    cin >> n;
    vector <Bottle> bottles(n);
    vector <int> count(1000 + 1, 0);
    map <pair<int,int>, int> duplicate;
    for(int i = 0 ; i < n ; ++i){
        cin >> bottles[i].self >> bottles[i].other;
        ++count[bottles[i].self];
        if(bottles[i].self == bottles[i].other){
            ++duplicate[{bottles[i].self, bottles[i].other}];
        } 
    }
    for(int i = 0 ; i < n ; ++i){
        if(count[bottles[i].other] == 0) continue;
        if(bottles[i].self != bottles[i].other){
            count[bottles[i].other] = 0; // if a_i != b_i, then a_i can open every bottle of brand b_i
        } else if(duplicate[{bottles[i].self, bottles[i].other}] > 1){
            count[bottles[i].other] = 0; // a_i == b_i, this can only be opened if there exists some other pair (a_i', b_i') such that (a_i' == a_i) && (b_i' == b_i) [a_i' != a_i has been handled above]
        } else{                         
            count[bottles[i].other] = 1; // otherwise it can open every bottle of b_i except itself
        }
    }
    int unopened = 0;
    for(int i = 1 ; i < count.size() ; ++i){
        unopened += count[i];
    }
    cout << unopened << '\n';
    return 0;
}
