#include <iostream>
#include <vector>

using namespace std;

/* all Pi's are distinct so a loop around any cycle not containing the start point is not possible */

/* 
    for the general case (where P_i's can be repeated), we loop through n times
    because of pigeonhole principle, if the destination is reachable, it will be reachble within n steps
*/

int main(int argc, char const *argv[])
{
    int n, s, t;
    cin >> n >> s >> t;
    vector <int> v(n);
    for(int i = 0 ; i < n ; ++i) cin >> v[i];
    int steps = -1;
    for(int i = 0 ; i < n ; ++i){
        if(s == t){
            steps = i;
            break;
        }
        s = v[s - 1];
    }
    cout << steps << '\n';
    return 0;
}
