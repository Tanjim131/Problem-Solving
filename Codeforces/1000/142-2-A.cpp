#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dragon{
    int strength, bonus;
    bool operator < (const Dragon &d) const{
        return strength < d.strength;
    }
};

int main(int argc, char const *argv[])
{
    int s, n;
    cin >> s >> n;
    vector <Dragon> dragons(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> dragons[i].strength >> dragons[i].bonus;
    }
    sort(dragons.begin(), dragons.end());
    bool possible = true;
    for(int i = 0, collected = 0 ; i < n ; ++i){
        if(s <= dragons[i].strength){
            if(s + collected > dragons[i].strength){
                s += collected;
                collected = 0;
            } else{
                possible = false;
                break;
            }
        }
        collected += dragons[i].bonus;
    }
    cout << (possible ? "YES" : "NO") << '\n';
    return 0;
}
