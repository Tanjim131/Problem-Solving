#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

class Triplet{
    public:
        int x,y,z;

        Triplet(int _x, int _y, int _z) : x(_x), y(_y), z(_z){}

        bool operator < (const Triplet &t) const{
            if(x == t.x){
                if(y == t.y){
                    return z < t.z;
                }
                return y < t.y;
            }
            return x < t.x;
        }
};

inline bool isUnique(int i, int j, int k){
    return i != j && j != k && k != i;
}

inline bool isSolution(int A,int B,int C, int i, int j, int k){
    int feq = i + j + k;
    int seq = i * j * k;
    int teq = i * i + j * j + k * k;

    return feq == A && seq == B && teq == C;
}

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    std::cin >> T;
    while(T--){
        int A, B, C;
        std::cin >> A >> B >> C;

        int minimum = sqrt(C);

        std::vector <Triplet> solutions;

        for(int i = -minimum ; i <= minimum ; ++i){
            for(int j = -minimum ; j <= minimum ; ++j){
                for(int k = -minimum ; k <= minimum ; ++k){
                    if(isUnique(i,j,k) && isSolution(A, B, C, i, j, k)){
                        solutions.emplace_back(Triplet(i, j, k));
                    }
                }
            }
        }

        if(solutions.size()){
            std::sort(solutions.begin(), solutions.end());
            std::cout << solutions[0].x << " " << solutions[0].y << " " << solutions[0].z << "\n"; 
        } else{
            std::cout << "No solution.\n";
        }
    }
    return 0;
}
