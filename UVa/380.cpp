#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

class CallForwaring{
    public:
        std::string source, destination;
        int start_time, end_time;
        CallForwaring(){}
        CallForwaring(const std::string &_source, const std::string &_start_time, const std::string &_duration, const std::string &_destination){
            source = _source;
            start_time = std::stoi(_start_time);
            end_time = start_time + std::stoi(_duration);
            destination = _destination;
        }
};

bool doesSatisfy(const CallForwaring &record, int time, const std::string &current_extension){
    return record.source == current_extension && time >= record.start_time && time <= record.end_time;
}

std::string formatTime(int time){
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(4) << time;
    return oss.str();
}

void backtrack(const std::vector<CallForwaring> &records, int time, std::string initial_extension, std::string current_extension, std::string previous_extension = ""){
    if(!previous_extension.empty() && current_extension == initial_extension){
        std::cout << "AT " << formatTime(time) << " CALL TO " << initial_extension << " RINGS 9999\n";
        return;
    }
    //std::cout << "current_extension " << current_extension << '\n';
    bool flag = false;
    for (int i = 0; i < records.size() ; ++i){
        if(doesSatisfy(records[i], time, current_extension)){
            //std::cout << "Going from " << current_extension << " to " << records[i].destination << '\n';
            backtrack(records, time, initial_extension, records[i].destination, current_extension);
            flag = true;
            break;
        }
    }
    if(!flag){
        std::cout << "AT " << formatTime(time) << " CALL TO " << initial_extension << " RINGS " << current_extension << '\n';
    } 
}

int main(int argc, char const *argv[])
{
    int N; // number of call forwarding systems
    std::cin >> N;
    std::cout << "CALL FORWARDING OUTPUT\n";
    for(int i = 1 ; i <= N ; ++i){
        std::vector <CallForwaring> records; 
        records.reserve(100);
        std::string source;
        while(std::cin >> source){
            if(source == "0000") break;
            std::string start_time, duration, destination;
            std::cin >> start_time >> duration >> destination;
            records.emplace_back(CallForwaring(source, start_time, duration, destination)); 
        }
        int time;
        std::cout << "SYSTEM " << i << '\n';
        while(std::cin >> time){
            if(time == 9000) break;
            std::string extension;
            std::cin >> extension;
            backtrack(records, time, extension, extension);
        }
    }
    std::cout << "END OF OUTPUT\n";
    return 0;
}
