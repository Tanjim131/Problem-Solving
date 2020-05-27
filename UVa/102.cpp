#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

#define LL long long

const LL MAXN = 1e12;

vector <string> perm;
LL ss;

void preprocess(string in, int low, int high) {
	if (low == high) perm.push_back(in);
	for (int i = low; i <= high; i++) {
		swap(in[i], in[low]);
		preprocess(in, low + 1, high);
		swap(in[i], in[low]);
	}
}

LL value(string in, LL *arr) {
	LL ret = ss;
	if (in == "BCG") {
		ret -= (arr[0] + arr[5] + arr[7]);
	}
	else if (in == "BGC") {
		ret -= (arr[0] + arr[4] + arr[8]);
	}
	else if (in == "CBG") {
		ret -= (arr[2] + arr[3] + arr[7]);
	}
	else if (in == "CGB") {
		ret -= (arr[2] + arr[4] + arr[6]);
	}
	else if (in == "GBC") {
		ret -= (arr[1] + arr[3] + arr[8]);
	}
	else if(in == "GCB") {
		ret -= (arr[1] + arr[5] + arr[6]);
	}
    return ret;
}

pair <string, LL> solve(LL *arr) {
	string ret;
	LL sum = MAXN;

	for (auto val : perm) {
		LL qq = value(val, arr);

		if (sum > qq) {
			sum = qq;
			ret = val;
		}
	}
	return make_pair(ret, sum);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	preprocess("BCG", 0, 2);
	sort(perm.begin(), perm.end());
	while (scanf("%d", &n) != EOF) {
		LL ara[9];
		ara[0] = n;
		ss = 0;
		ss += n;
		for (int i = 1; i < 9; i++) { scanf("%lld", &ara[i]); ss += ara[i]; }
		pair <string, LL> ret = solve(ara);
		cout << ret.first << " " << ret.second << endl;
	}
	return 0;
}
