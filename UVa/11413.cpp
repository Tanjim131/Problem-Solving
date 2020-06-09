#include <iostream>
#include <vector>
#include <algorithm>
 
bool check(const std::vector <int> &arr, int check_value, int container){
    int temp = check_value;
    for(int i = 0 ; i < arr.size() && container ; i++){
        if(arr[i] > check_value) return false;
        temp -= arr[i];
        if(temp < 0){
            container--;
            temp = check_value;
            temp -= arr[i];
        }
    }
    return container > 0;
}
 
int binary(const std::vector<int> &arr, int container){
    int low = 1, high = 1e9;
    while(low <= high){
        int mid = (low + high) / 2;
        if(check(arr,mid,container)) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
 
int main(){
    int n,m; 
    while(std::cin >> n >> m){
        int max_value = 0;
        std::vector<int> vessel(n);
        for(int i = 0 ; i < n ; i++){
            std::cin >> vessel[i];
            max_value = std::max(max_value, vessel[i]);
        }
        if(n >= m) {
            std::cout << binary(vessel, m) << '\n';
        }
        else{
            std::cout << max_value << '\n';
        } 
    }
    return 0;
}