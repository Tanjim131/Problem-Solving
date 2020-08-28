#include <iostream>

using namespace std;

int remove_zero(int n){
    long long reversed = 0;
    while(n != 0){
        if(n % 10 != 0) reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    int modified = 0;
    while(reversed != 0){
        modified = modified * 10 + reversed % 10;
        reversed /= 10;
    }
    return modified;
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    int modified_a = remove_zero(a);
    int modified_b = remove_zero(b);
    int modified_sum = remove_zero(sum);
    if(modified_a + modified_b == modified_sum){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
    return 0;
}
