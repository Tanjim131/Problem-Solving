#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<unordered_map>
#include<cstdio>

using namespace std;

unordered_map <string,int> ump;

void preprocess(){
    ump.clear();
    string first = "a";
    int counter = 1;
    for(int i = 1 ; i <= 26 ; i++){ // from a to z
        ump[first] = counter++;
        //cout << first << "---->" << counter - 1 << endl;
        first[0]++;
    }
    //cout << "a to z done" << endl;
    string second = "ab";
    for(int i = 1 ; i <= 25 ; i++){ // from ab to yz
        for(char j = second[0] + 1 ; j <= 'z' ; j++){
            second[1] = j;
            ump[second] = counter++;
            //cout << second << "---->" << counter - 1 << endl;
        }
        second[0]++;
    }
    //cout << "ab to yz done" << endl;
    string third = "abc";
    for(int i = 1 ; i <= 24 ; i++){ // from abc to xyz
        for(char j = third[0] + 1 ; j <= 'y' ; j++){
                third[1] = j;
            for(char k = third[1] + 1;  k <= 'z' ; k++){
                third[2] = k;
                ump[third] = counter++;
                //cout << third << "---->" << counter - 1 << endl;
            }
        }
        third[0]++;
    }
    string fourth = "abcd";
    for(int i = 1 ; i <= 23 ; i++){ // from abcd to wxyz
        for(char j = fourth[0] + 1 ; j <= 'x' ; j++){
            fourth[1] = j;
            for(char k = fourth[1] + 1 ; k <= 'y' ; k++){
                fourth[2] = k;
                for(char l = fourth[2] + 1 ; l <= 'z' ; l++){
                    fourth[3] = l;
                    ump[fourth] = counter++;
                    //cout << fourth << "---->" << counter - 1 << endl;
                }
            }
        }
        fourth[0]++;
    }
    string fifth = "abcde";
    for(int i = 1 ; i <= 22 ; i++){ // from abcde to vwxyz
        for(char j = fifth[0] + 1 ; j <= 'w' ; j++){
            fifth[1] = j;
            for(char k = fifth[1] + 1 ; k <= 'x' ; k++){
                fifth[2] = k;
                for(char l = fifth[2] + 1 ; l <= 'y' ; l++){
                    fifth[3] = l;
                    for(char m = fifth[3] + 1 ; m <= 'z' ; m++){
                        fifth[4] = m;
                        ump[fifth] = counter++;
                        //cout << fifth << "---->" << counter - 1 << endl;
                    }
                }
            }
        }
        fifth[0]++;
    }
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string input;
    preprocess();
    while(cin >> input){
        cout << ump[input] << endl;
    }

    return 0;
}
