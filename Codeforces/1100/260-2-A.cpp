#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Laptop{
    int price, quality;
    bool operator < (const Laptop &lapotp) const{
        return price < lapotp.price;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <Laptop> laptops(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> laptops[i].price >> laptops[i].quality;
    }
    sort(laptops.begin(), laptops.end());
    bool happy = false;
    for(int i = 0 ; i < n - 1 ; ++i){
        if(laptops[i].quality > laptops[i + 1].quality){
            happy = true;
            break;
        }
    }
    cout << (happy ? "Happy Alex" : "Poor Alex") << '\n';
    return 0;
}
