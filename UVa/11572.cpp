#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <vector>

using namespace std;

/**

My Approach:

It was a bit messy. I had some trouble understanding the problem statement.
The problem states that we have to find the maximum number of unique snowflakes
that come one after another. Or we could rephrase it in another way, Find the
longest length of contiguous/continuous sub-sequence that without any repetition.


Here, the order is not important. So, I used unordered map to increase efficiency.
First I took the input and stored it in a vector. Plus I stored the elements
as I have encountered them in their fist position and put them in a map.

Now for the second part, I used another map. Why did I do that?
Because I have to insert the elements as I traverse the vector , for that
I need another map. Now in this map, I just simply checked that , have I
encountered this element before? if not , then I just inserted it and
updated the mx variable. But one important observation is that, We have to
update the first map as we traverse the vector. Because whenever I encounter
an element I have previously seen, I have to start again. But from where do I start?
Obviously, from the position where I have encountered the element. But "ump" here
firstly contains the position as we first and foremost encountered them. So for that
reason, it needs to be updated. So once we have a duplicated element, we just need
to clear the "ret" map and we start all over again with the index we get from
"ump" map.

**/

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        unordered_map < int , int > ump;
        vector < int > vv;

        for(int i = 0 ; i < N ; i++){
            int x; scanf("%d",&x);
            vv.push_back(x);
            if(ump.find(x) == ump.end()) ump.insert(make_pair(x,i));
        }

        int i = 0 , counter = 0 , mx = 0;
        unordered_map < int , int > ret;

        while(i < N){
            if(ret.find(vv[i]) == ret.end()){
                ret.insert(make_pair(vv[i],i));
                ump[vv[i]] = i;
                i++ , counter++ , mx = max(mx,counter);
            }
            else{
                ret.clear();
                int temp = ump[vv[i]] + 1;
                ump[vv[i]] = i;
                i = temp;
                counter = 0;
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
