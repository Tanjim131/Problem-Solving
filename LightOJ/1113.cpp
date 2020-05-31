#include<bits/stdc++.h>

using namespace std;

int main()

{
    int T,i=0;

    while(T--)
    {
        stack<string>b;
        stack<string>f;

        while(!b.empty()) b.pop();

        while(!f.empty()) f.pop();

        b.push("http://www.lightoj.com/");

        string i;
        string j;

        while(cin>>i)
        {
            if(i=="QUIT") break;

            else
            {
                if(i=="VISIT")
                {
                    cin>>j;
                    b.push(j);
                    while(!f.empty()) f.pop();
                    cout << b.top() << endl;
                }
                else if(i=="BACK")
                {
                    if(b.top()=="http://www.lightoj.com/") cout << "IGNORED" << endl;

                    else
                    {
                        f.push(b.top());
                        b.pop();
                        cout << b.top() << endl;
                    }
                }
                else if(i=="FORWARD")
                {
                    if(!f.empty())
                    {
                        b.push(f.top());
                        f.pop();
                        cout << f.top() << endl;
                    }
                    else cout << "IGNORED" << endl;
                }
            }

        }
    }

    return 0;
}
