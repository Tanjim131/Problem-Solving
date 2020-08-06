#include <iostream>
#include <vector>
//#include <set> // set will also work
//#include <queue> // stack will also work

using std::cin;
using std::cout;

int main(int, char const *[])
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        std::string bits;
        cin >> bits;
        //std::set <int> zero, one;
        //std::queue <int> zero, one;
        std::vector <int> zero, one; 
        zero.reserve(bits.length());
        one.reserve(bits.length());
        int id = 0;
        std::vector <int> ids; 
        ids.reserve(bits.length());
        for(int i = 0 ; i < bits.length() ; ++i){
            if(bits[i] == '0'){
                if(one.empty()){
                    //zero.insert(++id);

                    // zero.push(++id);
                    // ids.emplace_back(id);


                    zero.emplace_back(++id);
                    ids.emplace_back(id);
                } else{
                    // ids.emplace_back(*one.begin());
                    // zero.insert(*one.begin());
                    // one.erase(*one.begin());
                    
                    // ids.emplace_back(one.front());
                    // zero.push(one.front());
                    // one.pop();

                    ids.emplace_back(one.back());
                    zero.emplace_back(one.back());
                    one.pop_back();
                }
            } else{
                if(zero.empty()){
                    // one.insert(++id);
                    
                    // one.push(++id);
                    // ids.emplace_back(id);

                    one.emplace_back(++id);
                    ids.emplace_back(id);
                } else{
                    // ids.emplace_back(*zero.begin());
                    // one.insert(*zero.begin());
                    // zero.erase(*zero.begin());
                    
                    // ids.emplace_back(zero.front());
                    // one.push(zero.front());
                    // zero.pop();

                    ids.emplace_back(zero.back());
                    one.emplace_back(zero.back());
                    zero.pop_back();
                }
            }
        }
        cout << id << '\n';
        for(auto i : ids){
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}
