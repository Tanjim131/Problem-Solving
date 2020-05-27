#include <iostream>
#include <sstream>
#include <memory>

class Operation{
    int q_size, first, last;
    std::unique_ptr <int[]> array;

    public:
        Operation(int s): q_size(s){
            array = std::make_unique<int[]>(s);
            first = -1;
            last = 0;
        }

        bool isFull(){
            return first == ((last + 1) % q_size);
        }

        bool isEmpty(){
            return first == -1;
        }

        void pushLeft(int x){
            if(isFull()){
                std::cout << "The queue is full\n";
                return;
            }
            if(first == -1){
                first = 0;
            } else{
                first = (first + q_size - 1) % q_size;
            }
            array[first] = x;
            std::cout << "Pushed in left: " << x << "\n";
        }

        void pushRight(int x){
            if(isFull()){
                std::cout << "The queue is full\n";
                return;
            }
            if(first == -1){
                first = 0;
            } else{
                last = (last + 1) % q_size;
            }
            array[last] = x;
            std::cout << "Pushed in right: " << x << "\n";
        }

        void popLeft(){
            if(isEmpty()){
                std::cout << "The queue is empty\n";
                return;
            }
            std::cout << "Popped from left: " << array[first] << "\n";
            if(first == last){
                first = -1;
                last = 0;
            } else{
                first = (first + 1) % q_size;
            }
        }

        void popRight(){
            if(isEmpty()){
                std::cout << "The queue is empty\n";
                return;
            }
            std::cout << "Popped from right: " << array[last] << "\n";
            if(first == last){
                first = -1;
                last = 0;
            } else{
                last = (last + q_size - 1) % q_size;
            }
        } 
};

class Command{
    public:
        bool isPush;
        bool isLeft;
        int itemValue;

        Command(){
            isPush = isLeft = false;
            itemValue = 999;   
        }

        Command(bool iP, bool iL, int iV) : isPush(iP), isLeft(iL), itemValue(iV){}
};

Command parse_command(const std::string &command){
    std::stringstream ss(command);
    std::string token; ss >> token;

    Command parsed_command;

    std::string push_prefix = "push";
    std::string pop_prefix = "pop";

    if(!token.compare(0, push_prefix.size(), push_prefix)){
        parsed_command.isPush = true;
    }

    std::string left_prefix = "Left";
    if(parsed_command.isPush){
        if(!token.compare(push_prefix.size(), left_prefix.size(), left_prefix)){
            parsed_command.isLeft = true;
        } 
    } else{
        if(!token.compare(pop_prefix.size(), left_prefix.size(), left_prefix)){
            parsed_command.isLeft = true;
        }
    }
    return parsed_command;
}

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T, k = 0;  std::cin >> T;
    while(T--){
        int n,m;
        std::cin >> n >> m;
        Operation operation(n);
        std::string input_command;
        std::cout << "Case " << ++k << ":\n";
        while(m--){
            std::cin >> input_command;   
            Command parsed_command = parse_command(input_command);     
            if(parsed_command.isPush){
                // push command
                int item; std::cin >> item;
                parsed_command.itemValue = item;

                if(parsed_command.isLeft){
                    // pushLeft 
                    operation.pushLeft(item);
                } else{
                    // pushRight
                    operation.pushRight(item);
                }
            } else{
                // pop command
                if(parsed_command.isLeft){
                    // popLeft
                    operation.popLeft();
                } else{
                    // popRight
                    operation.popRight();
                }
            }
        }
    }
    return 0;
}
