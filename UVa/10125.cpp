#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

class First{
    public:
        int x,y,sum;
        First() = default;
        First(int _x, int _y, int _s) : x(_x), y(_y), sum(_s){};
        bool operator < (const First &first) const{
            return sum < first.sum;
        }
};

int bs(const std::vector<First> &first, int value, int x, int y){
    int lo = 0, hi = first.size() - 1;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(first[mid].sum > value) hi = mid - 1;
        else if(first[mid].sum < value) lo = mid + 1;
        else{
            for(int i = mid ; i <= hi ; ++i){
                if(first[i].sum != value) break;
                if(first[i].sum == value && first[i].x != x && first[i].x != y && first[i].y != x && first[i].y != y){
                    return 1;
                }
            }
            for(int i = mid ; i >= lo ; --i){
                if(first[i].sum != value) break;
                if(first[i].sum == value && first[i].x != x && first[i].x != y && first[i].y != x && first[i].y != y){
                    return 1;
                }
            }
            return 0;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    while(std::cin >> n && n != 0){

        std::vector <int> numbers(n);
        for(int i = 0 ; i < n ; ++i){
            std::cin >> numbers[i];
        }

        std::sort(numbers.begin(), numbers.end());

        std::vector <First> first;
        first.reserve(numbers.size());

        for(int i = 0 ; i < numbers.size() ; ++i){
            for(int j = i + 1 ; j < numbers.size() ; ++j){
                first.emplace_back(First(numbers[i], numbers[j], numbers[i] + numbers[j]));
            }
        }

        std::sort(first.begin(), first.end());

        bool solution = false;
        int ans = -1;
        for(int i = numbers.size() - 1 ; i >= 0 ; --i){
            for(int j = 0 ; j < i ; ++j){
                int sub = numbers[i] - numbers[j];
                int ret = bs(first, sub, numbers[i],  numbers[j]);
                if(ret){
                    ans = numbers[i];
                    solution = true;
                    break;
                }
            }
            if(solution) break;
        }

        if(solution){
            std::cout << ans << '\n';
        } else{
            std::cout << "no solution\n";
        }
    }
    return 0;
}
