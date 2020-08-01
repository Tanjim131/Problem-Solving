#include <iostream>
#include <vector>

using std::cin;
using std::cout;

// unsigned char compute(unsigned char left, unsigned char right, unsigned char one = 0){
//     const std::vector <char> colors{'C', 'M', 'Y'};
//     unsigned char validChar = 0;
//     for(int i = 0 ; i < colors.size() ; ++i){
//         if(colors[i] != left && colors[i] != right && colors[i] != one){
//             validChar = colors[i];
//             break; 
//         }
//     }
//     return validChar;
// }

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::string input;
    cin >> input;
    bool possible = true;
    for(int i = 0 ; i < n - 1 ; ++i){
        if(input[i] != '?' && input[i] == input[i + 1]){
            possible = false;
            break;
        }
    } 
    if(!possible){
        cout << "No\n";
        return 0;
    }
    possible = false;
    for(int i = 0 ; i < n ; ++i){
        if(input[i] == '?'){
            if(i == 0 || i == n - 1) {
                possible = true;
                break;
            }
            if(input[i + 1] == '?' || input[i - 1] == input[i + 1]) {
                possible = true;
                break;
            }
        }
    }

    if(!possible){
        cout << "No\n";
    } else{
        cout << "Yes\n";
    }
    // std::string one{input};
    // for(int i = 0 ; i < input.length() ; ++i){
    //     if(input[i] == '?'){
    //         unsigned char left = 0, right = 0;
    //         if(i > 0){
    //             left = input[i - 1];
    //         }
    //         if(i < input.length() - 1){
    //             right = input[i + 1];
    //         }
    //         unsigned char validChar = compute(left, right);
    //         if(validChar != 0){
    //             one[i] = validChar;
    //         } else{
    //             possible = false;
    //             break;
    //         }
    //     }
    // }
    // if(!possible){
    //     //cout << "couldn't finish 1\n";
    //     cout << "No\n";
    //     return 0;
    // }
    // //cout << "one = " << one << '\n';
    // bool atLeastOne = false;
    // for(int i = 0 ; i < input.length() ; ++i){
    //     if(input[i] == '?'){
    //         unsigned char left = 0, right = 0;
    //         if(i > 0){
    //             left = input[i - 1];
    //         }
    //         if(i < input.length() - 1){
    //             right = input[i + 1];
    //         }
    //         unsigned char validChar = compute(left, right, one[i]);
    //         if(validChar != 0){
    //             atLeastOne = true;
    //             break;
    //         }
    //     }
    // }
    // if(!atLeastOne){
    //     //cout << "couldn't finish 2\n";
    //     cout << "No\n";
    // } else{
    //     cout << "Yes\n";
    // }
    return 0;
}
