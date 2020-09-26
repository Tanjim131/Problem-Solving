#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	deque <int> answer;
	for(int i = n - 1 ; i >= 0 ; --i){
		if(i % 2 == 0){
			answer.push_back(a[i]);
		} else{
			answer.push_front(a[i]);
		}
	}
	for(auto it = answer.begin() ; it != answer.end() ; ++it){
		cout << *it << " ";
	}
	cout << '\n';
	return 0;
}