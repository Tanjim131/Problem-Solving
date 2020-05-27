#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, k = 0; std::cin >> T;
    while(T--){
        int n; std:: cin >> n;
        int max_x1 = 0 , min_x2 = 1000, max_y1 = 0, min_y2 = 1000, max_z1 = 0 , min_z2 = 1000;
        for(int i = 0 ; i < n ; ++i){
            int x1,y1,z1,x2,y2,z2;
            std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

            max_x1 = std::max(max_x1, x1);
            max_y1 = std::max(max_y1, y1);
            max_z1 = std::max(max_z1, z1);

            min_x2 = std::min(min_x2, x2);
            min_y2 = std::min(min_y2, y2);
            min_z2 = std::min(min_z2, z2);
        }

        int diff_x = min_x2 - max_x1; diff_x = std::max(diff_x, 0);
        int diff_y = min_y2 - max_y1; diff_y = std::max(diff_y, 0);
        int diff_z = min_z2 - max_z1; diff_z = std::max(diff_z, 0);

        int intersection = diff_x * diff_y * diff_z;
        std::cout << "Case " << ++k << ": " << intersection << "\n";
    }
    return 0;
}
