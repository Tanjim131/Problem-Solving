#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Element{
    public:
        int value, type, index;
        // bool operator < (const Element &element) const{
        //     return value < element.value;
        // }
        bool operator > (const Element &element) const{
            return value > element.value;
        }      
};

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        // O(n) solution
        int n;
        cin >> n;
        vector <Element> elements(n);
        for(int i = 0 ; i < n ; ++i){
            cin >> elements[i].value;
            //elements[i].index = i;
        }
        int oc = 0; // one count
        for(int i = 0 ; i < n ; ++i){
            cin >> elements[i].type;
            oc += elements[i].type;
        }
        bool isSorted = true;
        for(int i = 0 ; i < n - 1 ; ++i){
            if(elements[i] > elements[i + 1]){
                isSorted = false;
                break;
            }
        }
        // if there is at least one pair with different type, then it's possible to sort the array
        if(isSorted || oc != 0 && oc != n){ 
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
        // O(n^2) solution
        // vector <Element> v(elements.begin(), elements.end());
        // sort(v.begin(), v.end());
        // bool possible = true;
        // for(int i = 0 ; i < n ; ++i){
        //     if(elements[i].value == v[i].value) continue;
        //     if(elements[i].type != v[i].type){
        //         swap(elements[i], elements[v[i].index]);
        //     } else{
        //         bool found = false;
        //         for(int j = 0 ; j < n ; ++j){
        //             if(elements[i].type != elements[j].type){
        //                 swap(elements[i], elements[j]);
        //                 found = true;
        //                 break;
        //             }
        //         }
        //         if(found){
        //             swap(elements[i], elements[v[i].index]);
        //         } else{
        //             possible = false;
        //             break;
        //         }
        //     }
        // }
        //cout << (possible ? "Yes" : "No") << '\n';
    }
    return 0;
}
