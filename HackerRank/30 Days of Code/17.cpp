#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here

class Calculator{
    public:
        int power(int n, int p){
            if(n < 0 || p < 0){
                throw invalid_argument("n and p should be non-negative");
            }
            int product = 1;
            for(int i = 0 ; i < p ; ++i){
                product *= n;
            }
            return product;
        }
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}