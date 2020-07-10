#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void printSolution(const std::vector <int> &steps){
    const std::map <int, std::string> mp = {
        {0, "fill A"},
        {1, "fill B"},
        {2, "empty A"},
        {3, "empty B"},
        {4, "pour A B"},
        {5, "pour B A"}
    };
    for(const auto &step : steps){
        std::cout << mp.at(step) << '\n';
    }
    std::cout << "success\n";
}

void backtrack(std::vector <std::vector<char>> &states, int C_a, int C_b, int &goal, int a = 0, int b = 0, std::vector <int> steps = std::vector <int>()){
    if(a == goal || b == goal){
        printSolution(steps);
        goal = -1; // goal reached
        return;
    } 

    if(goal != -1){
        states[a][b] = '1';

        //fill A
        if(states[C_a][b] == '0'){
            steps.emplace_back(0);
            backtrack(states, C_a, C_b, goal, C_a, b, steps);
            steps.pop_back();
        }
        
        //fill B
        if(states[a][C_b] == '0'){
            steps.emplace_back(1);
            backtrack(states, C_a, C_b, goal, a, C_b, steps);
            steps.pop_back();
        }

        //empty A
        if(states[0][b] == '0'){
            steps.emplace_back(2);
            backtrack(states, C_a, C_b, goal, 0, b, steps);
            steps.pop_back();
        }

        //empty B
        if(states[a][0] == '0'){
            steps.emplace_back(3);
            backtrack(states, C_a, C_b, goal, a, 0, steps);
            steps.pop_back();
        }

        // pour A B
        // B can accommodate C_b - b 
        // after pouring A will have a - (C_b - b), if this quantity is < 0, then A will have 0
        int rem_A = std::max(0, a + b - C_b);
        int cur_B = a + b - rem_A;
        if(states[rem_A][cur_B] == '0'){
            steps.emplace_back(4);
            backtrack(states, C_a, C_b, goal, rem_A, cur_B, steps);
            steps.pop_back();
        }

        // pour B A
        // A can accommodate C_a - a 
        // after pouring B will have b - (C_a - a), if this quantity is < 0, then B will have 0
        int rem_B = std::max(0, a + b - C_a);
        int cur_A = a + b - rem_B;
        if(states[cur_A][rem_B] == '0'){
            steps.emplace_back(5);
            backtrack(states, C_a, C_b, goal, cur_A, rem_B, steps);
            steps.pop_back();
        }

        states[a][b] = '0';
    }
}

int main(int argc, char const *argv[])
{
    int C_a, C_b, N;
    while(std::cin >> C_a >> C_b >> N){
        std::vector <std::vector<char>> states(C_a + 1, std::vector<char>(C_b + 1, '0'));
        backtrack(states, C_a, C_b, N);
    }
    return 0;
}
