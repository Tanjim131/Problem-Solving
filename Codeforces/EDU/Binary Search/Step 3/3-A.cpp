#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Person{
    int position, speed;
};

bool ok(const vector <Person> &persons, double t){
    double maxLeft = -1e9, minRight = 1e9;
    for(int i = 0 ; i < persons.size() ; ++i){
        double left = persons[i].position - t * persons[i].speed;
        double right = persons[i].position + t * persons[i].speed;
        maxLeft = max(maxLeft, left);
        minRight = min(minRight, right);
    }
    return maxLeft <= minRight;
}

double binary_search(const vector <Person> &persons){
    double low = 0.0, high = 1e9;
    for(int i = 0 ; i < 100 ; ++i){
        double mid = (low + high) / 2;
        if(ok(persons, mid)){
            high = mid;
        } else{
            low = mid;
        }
    }
    return high;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <Person> persons(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> persons[i].position >> persons[i].speed;
    }
    cout << fixed << setprecision(17) << binary_search(persons) << '\n';
    return 0;
}
