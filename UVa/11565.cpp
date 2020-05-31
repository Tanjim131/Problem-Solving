#include <iostream>
#include <cmath>

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

        bool solution = false;

        for(int i = -minimum ; i <= minimum ; ++i){
            for(int j = -minimum ; j <= minimum ; ++j){
                for(int k = -minimum ; k <= minimum ; ++k){
                    if(isUnique(i,j,k) && isSolution(A, B, C, i, j, k)){
                        std::cout << i << " " << j << " " << k << '\n';
                        solution = true;
                    }
                }
                if(solution) break;
            }
            if(solution) break;
        }

        if(!solution){
            std::cout << "No solution.\n";
        }
    }
    return 0;
}
