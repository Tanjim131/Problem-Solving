#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        unordered_set <int> us;
        for(int i = 0 ; i < N ; ++i){
            int x; cin >> x;
            // did not notice that x can be equal to 0 
            if(x > 0 && us.find(x) == us.end()){
                us.insert(x);
            }
        }
        cout << us.size() << '\n';
    }
    return 0;
}
