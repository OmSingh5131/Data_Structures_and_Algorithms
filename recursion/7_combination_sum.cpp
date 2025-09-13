// https://leetcode.com/problems/combination-sum/

#include<bits/stdc++.h>
using namespace std;

void f( int index, vector<int> ds, int target, vector<int> arr){

    // base case

    if( target < 0 ){
        return ;
    }

    if( index == arr.size() ){
        if(target == 0){
            for( auto i : ds){
                cout << i << " ";
            }
            cout << endl; 
        }        
        return;
    }

    // picking
    ds.push_back(arr[index]);
    f( index, ds, target - arr[index], arr );

    // coming back
    ds.pop_back();
    f(index + 1, ds, target, arr );

}

int main(){

    vector<int> arr = {2,3,6,7};
    int target = 7;
    vector<int> ds;
    f(0, ds, target, arr);

    return 0;

}



