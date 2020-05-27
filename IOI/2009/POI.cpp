#include <iostream>
#include <vector>
#include <algorithm>

class Contestant{
    public:
        int score, problems_solved,id;

        bool operator < (const Contestant &contestant) const{
            if(score == contestant.score){
                if(problems_solved == contestant.problems_solved){
                    return id < contestant.id;
                }
                return problems_solved > contestant.problems_solved;
            }
            return score > contestant.score;
        }
};

int main(int argc, char const *argv[])
{
    int N,T,P;
    std::cin >> N >> T >> P;
    std::vector<std::vector<int>> contestants_data(N, std::vector<int>(T));
    std::vector <int> task_scores(T);
    
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < T ; ++j){
            std::cin >> contestants_data[i][j];
            if(!contestants_data[i][j]) ++task_scores[j];
        }
    }

    std::vector <Contestant> contestants(N);
    for(int i = 0 ; i < N ; ++i){
        contestants[i].id = i + 1;
        for(int j = 0 ; j < T ; ++j){
            if(contestants_data[i][j]){
                // contestant i solved task j
                contestants[i].score += task_scores[j];
                ++contestants[i].problems_solved;
            }
        }
    }

    std::sort(contestants.begin(), contestants.end());
    int ranking = -1, score = -1;
    for(int i = 0 ; i < N ; ++i){
        if(contestants[i].id == P){
            ranking = i + 1;
            score = contestants[i].score;
            break;
        }
    }
    std::cout << score << " " << ranking << '\n';
    
    return 0;
}
