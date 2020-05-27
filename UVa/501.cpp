#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int box[30005];
    while(T--){
        int m,n;
        scanf("%d %d",&m,&n);

        for(int i = 0 ; i < m ; i++){
            scanf("%d",&box[i]);
        }

        multiset <int> ms;
        ms.insert(box[0]);
        multiset <int> :: iterator it = ms.begin();

        int b = 1;
        bool first = true;

        for(int i = 0 ; i < n ; i++){
            int x; scanf("%d",&x);

            while(x > b){
                ms.insert(box[b]);
                if(*it > box[b]) it--; // checking if smaller elements are being inserted or not
                                        // if it is , then decrementing the pointer
                b++;
            }

            if(first) first = false; // for first case , we do not need to increment the pointer
            else it++; // from 1st min -> 2nd min , 2nd min -> 3rd min , incrementing

            cout << *it << endl;
        }

        if(T) printf("\n");
    }
    return 0;
}

