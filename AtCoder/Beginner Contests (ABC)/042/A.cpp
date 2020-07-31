#include <iostream>

void test(int number, int &cnt_5, int &cnt_7){
    if(number == 5) ++cnt_5;
    else if(number == 7) ++cnt_7;
}

int main(int argc, char const *argv[])
{
    int A,B,C;
    std::cin >> A >> B >> C;
    int cnt_5 = 0, cnt_7 = 0;
    test(A, cnt_5, cnt_7);
    test(B, cnt_5, cnt_7);
    test(C, cnt_5, cnt_7);
    if(cnt_5 == 2 && cnt_7 == 1){
        std::cout << "YES\n";
    } else{
        std::cout << "NO\n";
    }
    return 0;
}
