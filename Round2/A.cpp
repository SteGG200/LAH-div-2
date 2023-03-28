#include <bits/stdc++.h>

using namespace std;

//others function

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> women(n);
	for(int i = 0; i < n; i++){
		cin >> women[i];
	}

	vector<int> men(m);
	for(int i = 0; i < m; i++){
		cin >> men[i];
	}

	sort(women.begin(), women.end());
	sort(men.begin(), men.end());

	int i = women.size() - 1;
	int j = men.size() - 1;
	int count = 0;
	while(i >= 0 && j >= 0){
		if(women[i] > men[j]){
			count++;
			i--;
		}else i--, j--;
	}

	count += i + j + 2;
	cout << count << endl;

	return 0;
}
