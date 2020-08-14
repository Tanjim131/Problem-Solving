#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

template<typename T>
std::ostream & operator<<(std::ostream & os, std::vector<T> vec)
{
    os<<"{ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, " "));
    os<<"}";
    return os;
}

using namespace std;

bool isValid(const vector <int> &v){
    for(int i = 0 ; i < v.size() - 1 ; ++i){
        int diff = v[i] - v[i + 1];
        if(diff == 1 || diff == -1) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n = 6;
    vector <int> v(n, 0);
    iota(v.begin(), v.end(), 1);
    //cout << v << '\n';
    do{
        if(isValid(v)){
            cout << v << '\n';
            //break;
        }
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}
