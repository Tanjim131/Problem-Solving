#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <set>

bool isUpper(const std::string &s){
    return !std::any_of(s.begin(), s.end(), [](unsigned char c) { return std::islower(c); });
}

class Project{
    public:
        std::string project_name;
        int number_of_signups;
        std::set <std::string> signups;

        Project(const std::string &_project_name) : project_name(_project_name){}

        bool operator < (const Project &project) const{
            if(number_of_signups == project.number_of_signups){
                return project_name < project.project_name;
            }
            return number_of_signups > project.number_of_signups;
        }

        void reset(const std::string &_project_name){
            project_name = _project_name;
            signups.clear();
        }
};

int main(int argc, char const *argv[])
{
    std::string input;
    while(std::getline(std::cin, input) && input != "0"){ // if the input is not "0", then it's always a project name
        std::vector <Project> projects;
        projects.reserve(100);
        
        Project project(input);
        std::set <std::string> all_signups;

        while(std::getline(std::cin, input) && input != "1"){
            if(isUpper(input)){
                // new project information
                project.number_of_signups = project.signups.size();
                projects.emplace_back(project); // first store the previous projects information
                project.reset(input); // now reset the temporary project variable with new project name
            } else{
                if(project.signups.find(input) == project.signups.end()){
                    // this student hasn't signed up before under this project
                    project.signups.insert(input);
                    all_signups.insert(input);
                } 
            }
        }

        // store the last project
        project.number_of_signups = project.signups.size();
        projects.emplace_back(project);

        // at this point there may be students who have signed up for multiple projects
        // remove them

        for(const std::string &individual : all_signups){
            int project_indices = -1; // instead of maintaining a vector of all project indices, we maintain a variable
                                    // if this variable tries to get updated more than once, we start deleting the individual
            bool multiple = false;
            for(int i = 0 ; i < projects.size() ; ++i){
                if(projects[i].signups.find(individual) != projects[i].signups.end()){
                    if(project_indices == -1){
                        project_indices = i;
                        continue;
                    }
                    multiple = true;
                    --projects[i].number_of_signups;
                }
            }

            if(multiple){
                --projects[project_indices].number_of_signups;
            }
        }

        // sort the projects according to singups values
        std::sort(projects.begin(), projects.end());
        
        // print the answer
        for(int i = 0 ; i < projects.size() ; ++i){
            std::cout << projects[i].project_name << " " << projects[i].number_of_signups << '\n';
        }
    }
    return 0;
}
