#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector < int > vv[55];

int binary(int ff,int ret){
    int idx = -1;
    int low = 0 , high = vv[ret].size() - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(vv[ret][mid] >= ff){
            idx = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return idx == -1 ? idx : vv[ret][idx];
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a;
    cin >> a;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] >= 'A' && a[i] <= 'Z') vv[a[i] - 'A'].push_back(i);
        else vv[a[i] - 'a' + 26].push_back(i);
    }

    /*for(int i = 0 ; i < 52 ; i++){
        if(i < 26){
            printf("%c: ",'A' + i);
        }
        else printf("%c: ",'a' + i - 26);
        for(int j = 0 ; j < vv[i].size() ; j++){
            printf("%d ",vv[i][j]);
        }
        printf("\n");
    }*/

    int qq;
    scanf("%d",&qq);
    while(qq--){
        bool ff = true;
        string cc;
        cin >> cc;
        int l = 0;
        int first = 0 , last = 0;
        for(int i = 0 ; i < cc.size() ; i++){
            int ret = 0;
            if(cc[i] >= 'A' && cc[i] <= 'Z') ret = cc[i] - 'A';
            else ret = cc[i] - 'a' + 26;
            int ans = binary(l,ret);
            //cout << "i " << i << " ans " << ans << " LL " << l << endl;
            if(ans == -1){
                printf("Not matched\n");
                ff = false;
                break;
            }
            if(i == 0) first = ans;
            if(i == cc.size() - 1) last = ans;
            l = ans + 1;
        }
        if(ff) printf("Matched %d %d\n",first,last);
    }

    return 0;
}
