#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Song{
    public:
        int actual, reduced;
        bool operator < (const Song &song) const{
            return (actual - reduced) > (song.actual - song.reduced);
        }
};

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    vector <Song> songs(n);
    long long sum = 0;
    long long maximum_reduced = 0;
    for(int i = 0 ; i < n ; ++i){
        cin >> songs[i].actual >> songs[i].reduced;
        sum += songs[i].actual;
        maximum_reduced += songs[i].reduced;
    }
    long long required = sum - m;
    if(required <= 0){
        cout << 0 << '\n';
    } else if(maximum_reduced > m){
        cout << "-1\n";
    } else{
        sort(songs.begin(), songs.end());
        int counter = 0;
        for(int i = 0 ; i < songs.size() ; ++i){
            sum -= songs[i].actual - songs[i].reduced;
            ++counter;
            if(sum <= m){
                break;
            }
        }
        cout << counter << '\n';
    }
    return 0;
}
