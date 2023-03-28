#include <bits/stdc++.h>

using namespace std;

//others function

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> table(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> table[i][j];
		}
	}

	vector<vector<bool>> check(n, vector<bool>(n, false));

	for(int i = 0; i < n; i++){
		int maxheight = table[i][0];
		if(table[i][0] != 0) check[i][0] = true;
		for(int j = 1; j < n; j++){
			if(maxheight < table[i][j]){
				maxheight = table[i][j];
				if(table[i][j] != 0) check[i][j] = true;
			}
		}
		
		maxheight = table[i][n - 1];
		if(table[i][n - 1] != 0) check[i][n - 1] = true;
		for(int j = n - 2; j >= 0; j--){
			if(maxheight < table[i][j]){
				maxheight = table[i][j];
				if(table[i][j] != 0) check[i][j] = true;
			}
		}
	}

	for(int j = 0; j < n; j++){
		int maxheight = table[0][j];
		if(table[0][j]) check[0][j] = true;
		for(int i = 1; i < n; i++){
			if(maxheight < table[i][j]){
				maxheight = table[i][j];
				if(table[i][j] != 0) check[i][j] = true;
			}
		}
		maxheight = table[n - 1][j];
		if(table[n - 1][j] != 0) check[n - 1][j] = true;
		for(int i = n - 2; i >= 0; i--){
			if(maxheight < table[i][j]){
				maxheight = table[i][j];
				if(table[i][j] != 0) check[i][j] = true;
			}
		}
	}

	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			count += check[i][j];
		}
	}

	cout << count << endl;

	return 0;
}