#include <bits/stdc++.h>
using namespace std;

bool isOK(vector<int>&stalls, int mid, int cows){
	int p = stalls[0];
	int count = 1;
	for(int i=1;i<stalls.size();i++){
		if(stalls[i] - p >= mid){
			count++;
			p = stalls[i];
		}
	}
	
	return count >= cows;
}

int main() {
	// 1 2 4 8 9
	//[1       4]
	int t;
	cin >> t;
	
	while(t--){
		int n, c;
		int el;
		cin >> n >> c;
		vector<int>stalls;
		for(int i=0;i<n;i++){
			cin >> el;
			stalls.push_back(el);
		}
		
		sort(stalls.begin(), stalls.end());
		int low = 1, high = stalls[n-1] - stalls[0];
		int mid = (low + high) / 2;
		int res;
		
		while(low <= high){
			if(isOK(stalls, mid, c)){
				res = mid;
				low = mid + 1;
				
			}
			else{
				high = mid - 1;
			}
		}
		
		cout << res << endl;
	}
	return 0;
}