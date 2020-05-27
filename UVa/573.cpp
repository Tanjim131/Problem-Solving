#include <iostream>

int main(int argc, char const *argv[])
{
    constexpr double EPS = 1e-4;
    int H,U,D,F;
    while(std::cin >> H >> U >> D >> F){
        if(!H && !U && !D && !F) break;
        double height = 0.0;
        int day = 1;
        while(true){
            double distance_climbed = U - (F / 100.0) * U * (day - 1);
            if(distance_climbed > EPS){
                height += distance_climbed;
                if(height > H){
                    std::cout << "success on day " << day << '\n';
                    break;
                }
                //std::cout << "height after adding " << height << '\n';
            }
            height -= D;
            //std::cout << "height after falling " << height << '\n';
            if(height < 0){
                std::cout << "failure on day " << day << '\n';
                break;
            }
            ++day;
        }
    }
    return 0;
}
