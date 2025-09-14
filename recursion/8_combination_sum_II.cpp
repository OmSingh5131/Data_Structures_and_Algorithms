// https://leetcode.com/problems/combination-sum-ii/description/
// COMBINATION SUM II


#include<bits/stdc++.h>
using namespace std;

// This is the basic and very core logic and is not optimized as it prints redundant combinations

void f(int index, int target, vector<int> &ds,int arr[], int n){
    // base case
    
    if( index == n){
        if( target == 0){
            for( auto it : ds){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // pick
    if(arr[index] <=  target){

        ds.push_back(arr[index]);
        f(index + 1, target - arr[index], ds, arr, n);

        ds.pop_back();

    }

    f( index + 1, target, ds, arr, n);

}


int main(){

    int arr[7] = {10,1,2,7,6,1,5};
    int target = 8;
    vector<int> ds;

    f(0,8,ds,arr,7);
    return 0;

}


// Developing the logic to print the non redundant combinations

#include<bits/stdc++.h>
using namespace std;


void fu(int index, int target, vector<int> ds, vector<int> arr, int n){
    // base case 

    if( target == 0){
        for(auto it : ds){
            cout << it << " ";
        } cout << endl;

        return;
    }

    for( int i = index; i < n; i++){
        if( i > index && arr[i] == arr[i-1]){
            continue;
        }
        if( arr[i] > target ){
            break;
        }
        ds.push_back(arr[i]);
        fu( i + 1, target - arr[i], ds, arr, n);
        ds.pop_back();
    }
}

int main(){

    vector<int> arr = {1,1,1,2,2};
    int n = arr.size();
    int target =4 ;
    vector<int> ds;
    sort(arr.begin(), arr.end()); // This is the important step for your logic

    fu(0,target,ds,arr,n);


    return 0;
}


class Solution {
public:

    void f( int index, int target, vector<int> &ds, vector<int> &candidates, vector<vector<int>> &ans){
        // base case
        if( target == 0){
            ans.push_back(ds);
            return;
        }

        for( int i = index; i < candidates.size(); i++ ) {

            if( i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            if( candidates[i] > target ){
                break;
            }

            ds.push_back(candidates[i]);
            f( i + 1 , target - candidates[i], ds, candidates, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {


        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        f( 0 , target, ds, candidates , ans);
        return ans;
        
    }
};