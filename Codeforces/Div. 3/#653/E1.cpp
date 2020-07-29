#include <iostream>
#include <vector>
#include <algorithm>
 
int main(int argc, char const *argv[])
{
    
    int n,k;
    std::cin >> n >> k;
    
    std::vector <int> both_like, alice_likes, bob_likes;
 
    for(int i = 0 ; i < n ; ++i){
        int reading_time, a, b;
        std::cin >> reading_time >> a >> b;
        if(a == 1 && b == 1) {
            both_like.emplace_back(reading_time);
        } else if(a) {
            alice_likes.emplace_back(reading_time);
        } else if(b){
            bob_likes.emplace_back(reading_time);
        }
    }
 
    if(both_like.size() + alice_likes.size() < k || both_like.size() + bob_likes.size() < k){
        std::cout << "-1\n";
        return 0;
    }
 
    std::sort(both_like.begin(), both_like.end());
    std::sort(alice_likes.begin(), alice_likes.end());
    std::sort(bob_likes.begin(), bob_likes.end());
 
    int answer = 0;
    int both_index = 0, a_index = 0, b_index = 0;
    while(k--){
        int both = -1, a = -1, b = -1;
        if(both_index < both_like.size()) both = both_like[both_index];
        if(a_index < alice_likes.size()) a = alice_likes[a_index];
        if(b_index < bob_likes.size()) b = bob_likes[b_index];
 
        if(a == -1 || b == -1){
            answer += both;
            ++both_index;
            continue;
        }
 
        if(both == -1){
            answer += a + b;
            ++a_index;
            ++b_index;
            continue;
        }
 
        if(both <= a + b){
            answer += both;
            ++both_index;
        } else{
            answer += a + b;
            ++a_index;
            ++b_index;
        }
    }
 
    std::cout << answer << '\n';
    
    return 0;
}