#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct Exam{
    int scheduled, early;
    bool operator < (const Exam &e) const{
        return tie(scheduled, early) < tie(e.scheduled, e.early);
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <Exam> exams(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> exams[i].scheduled >> exams[i].early;
    }
    sort(exams.begin(), exams.end());
    int last = exams[0].early;
    for(int i = 1 ; i < n ; ++i){
        if(exams[i].early >= last){
            last = exams[i].early;
        } else{
            last = exams[i].scheduled;
        }
    }
    cout << last << '\n';
    return 0;
}
