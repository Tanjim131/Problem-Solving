#include <iostream>
#include <algorithm>

using namespace std;

bool ok(int b, int s, int c, int nb, int ns, int nc, int pb, int ps, int pc, long long r, long long value){
    // with the ingredients I already have, I can make 'minimum' amount of burgers
    int minimum = min({b == 0 ? 0 : nb / b, s == 0 ? 0 : ns / s, c == 0 ? 0 : nc / c});
    nb -= b * minimum;
    ns -= s * minimum;
    nc -= c * minimum;
    if(minimum >= value) return true;
    value -= minimum;
    // now I cannot make any more burgers without buying
    // I have to make the remaining 'value' amount of burgers with 'r' rubles
    if(nb < value * b){ // need extra bread
        long long bn = value * b - nb; // this amount of extra bread is needed
        if(r < bn * pb) return false;
        r -= bn * pb;
    }
    if(ns < value * s){ // need extra sausage
        long long sn = value * s - ns;
        if(r < sn * ps) return false;
        r -= sn * ps;
    }
    if(nc < value * c){ // need extra cheese
        long long cn = value * c - nc;
        if(r < cn * pc) return false;
    }
    return true;
}

long long binary_search(int b, int s, int c, int nb, int ns, int nc, int pb, int ps, int pc, long long r){
    long long low = 0, high = 1e13;
    long long ans = -1;
    while(low <= high){
        long long mid = (low + high) / 2;
        if(ok(b, s, c, nb, ns, nc, pb, ps, pc, r, mid)){
            ans = mid;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string recipe;
    cin >> recipe;
    int b = 0, s = 0, c = 0;
    for(int i = 0 ; i < recipe.length() ; ++i){
        if(recipe[i] == 'B') ++b;
        else if(recipe[i] == 'S') ++s;
        else ++c;
    }
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    long long r;
    cin >> r;
    cout << binary_search(b, s, c, nb, ns, nc, pb, ps, pc, r) << '\n';
    return 0;
}
