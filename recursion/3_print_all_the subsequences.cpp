// Print all the subsequences of the String

#include<bits/stdc++.h>
using namespace std;

void printSubsequences( int index, vector<int> &ans, int *arr , int n){

    // base case
    if( index >= n){

        if( ans.empty()){
            cout << "{}" << endl;
        }

        for( auto it : ans ){
            cout << it << " ";
        } cout << endl;

        return;
    
    }
    ans.push_back( arr[index] );
    printSubsequences( index + 1, ans, arr, n);
    ans.pop_back();
    printSubsequences( index + 1, ans, arr, n);

    return;



}

int main(){

    int arr[3] = {3,2,1};
    int n = 3;
    vector<int> ans;
    printSubsequences(0, ans, arr, n);

    return 0;
}