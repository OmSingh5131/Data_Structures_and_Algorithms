
#include<bits/stdc++.h>
using namespace std;

bool printF( int index, vector<int> & ans, int sum, int target, int arr[], int size){

    // base case
    if( index == size){
        if( sum == target){
            for(auto i : ans){
                cout << i << " ";
            } 
            cout << endl;
            return true;
        }
        return false;
    }
   
    ans.push_back(arr[index]);
    sum = sum + arr[index];

    if(printF( index + 1, ans, sum, target, arr, size)){
        return true;
    }

    ans.pop_back();
    sum = sum - arr[index];

    if(printF( index + 1, ans, sum, target, arr, size)){
        return true;
    }

    return false;
}

int main(){
    int arr[3] = { 1,2, 1};
    int size = 3;
    int target = 2;
    vector<int> ans;
    printF(0, ans, 0, target, arr, size );
    return 0;
}