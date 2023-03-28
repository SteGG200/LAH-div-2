#include <bits/stdc++.h>
#define MOD 33
#define int long long

using namespace std;

//others function
string s;
int n;
vector<int> suffix;

void solve1(){
	vector<int> modlist(MOD, 0);
	modlist[0] = 1;
	for(int i = 0; i < n; i++){
		modlist[suffix[i]]++;
	}

	int count = 0;
	for(int i = 0; i < MOD; i++){
		count += modlist[i] * (modlist[i] - 1) / 2;
	}
	cout << count << endl;
}

string maxcmp(const string &a, const string &b){
	if(a.size() < b.size()) return b;
	else if(a.size() > b.size()) return a;
	else{
		for(int i = 0; i < a.size(); i++){
			if(a[i] < b[i]) return b;
			else if(a[i] > b[i]) return a;
		}
	}
	return a;
}

void solve2(){
	vector<int> left(MOD, -1);
	vector<int> right(MOD, -1);
	string result;
	for(int i = 0; i <= n; i++){
		if(left[suffix[i]] == -1) left[suffix[i]] = i;
	}
	for(int i = n; i >= 0; i--){
		if(right[suffix[i]] == -1) right[suffix[i]] = i;
	}
	for(int i = 0; i < MOD; i++){
		if(left[i] != right[i]){
			result = maxcmp(result, s.substr(left[i], right[i] - left[i]));
		}
	}
	if(result.size()) {
		while(result.size() > 1 && result[0] == '0'){
			result.erase(0, 1);
		}
		cout << result << endl;
	}
	else cout << -1 << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	n = s.size();
	suffix.assign(n + 1, 0);
	// s[l, r] = suffix[l] - suffix[r + 1]
	int temp = 1;
	for(int i = n - 1; i >= 0; i--){
		suffix[i] = (suffix[i + 1] + (s[i] - '0') * temp) % MOD;
		temp = (temp * 10) % MOD;
	}
	solve1();
	solve2();

	return 0;
}
