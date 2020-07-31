#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

class Period{
    public:
        int start, finish;
};

int main(int argc, char const *argv[])
{
    int n, P1, P2, P3, T1, T2;
    cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;
    std::vector <Period> periods(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> periods[i].start >> periods[i].finish;
    }
    int consumption = 0;
    for(int i = 0 ; i < n ; ++i){
        consumption += (periods[i].finish - periods[i].start) * P1;
        if(i < n - 1){
            int gap = periods[i + 1].start - periods[i].finish;
            consumption += std::min(T1, gap) * P1;
            gap -= T1;
            if(gap > 0){
                consumption += std::min(T2, gap) * P2;
                gap -= T2;
                if(gap > 0){
                    consumption += gap * P3;
                }
            }
        }
    }
    cout << consumption << '\n';
    return 0;
}