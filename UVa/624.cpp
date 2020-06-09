#include <iostream>
#include <vector>
#include <algorithm>

void backtrack(const std::vector <int> &track_durations, int tape_length, int &answer, std::vector<int> &answer_choices, std::vector <int> current_choices = std::vector <int>(), int current_index = 0, int current_sum = 0){
    // at each index, we can either take the item or leave it
    if(current_index == track_durations.size()){
        if(answer < current_sum){
            answer = current_sum;
            answer_choices = current_choices;
        }
        return;
    }

    if(current_sum + track_durations[current_index] <= tape_length){
        current_choices.emplace_back(track_durations[current_index]);
        backtrack(track_durations, tape_length, answer, answer_choices, current_choices, current_index + 1, current_sum + track_durations[current_index]);
        current_choices.pop_back();
    }
    backtrack(track_durations, tape_length, answer, answer_choices, current_choices, current_index + 1, current_sum);
}

void printAnswer(int answer, const std::vector<int> &answer_choices){
    for(int i = 0 ; i < answer_choices.size() ; ++i){
        std::cout << answer_choices[i] << " ";
    }
    std::cout << "sum:" << answer << '\n';
}

int main(int argc, char const *argv[])
{
    int tape_length, number_tracks;
    while(std::cin >> tape_length >> number_tracks){
        std::vector <int> track_durations(number_tracks);
        for(int i = 0 ; i < number_tracks ; ++i){
            std::cin >> track_durations[i];
        }
        int answer = 0;
        std::vector <int> answer_choices;
        backtrack(track_durations, tape_length, answer, answer_choices);
        printAnswer(answer, answer_choices);
    }
    return 0;
}
