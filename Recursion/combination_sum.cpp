#include<bits/stdc++.h>
using namespace std;

void generate(int index, vector<int>&ds, int vec[], int target, int n, vector<vector<int>>&ans){
    if(index == n){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }

    if(vec[index] <= target){
        ds.push_back(vec[index]);
        generate(index, ds, vec, target - vec[index], n, ans);
        ds.pop_back();
    }
    
    generate(index + 1, ds, vec, target, n, ans);

}

int main(){
    int vec[] = {2,3,6,7};
    int n = 4;
    int index = 0;
    vector<int>ds;
    vector<vector<int>>ans;
    int target = 7;
    int sum = 0;
    generate(index, ds, vec, target, n, ans);

    for(int i = 0 ; i < ans.size() ; i++){
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout<<ans[i][j]<<endl;
        }
    }
    return 0;
}