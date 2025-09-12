// Here we will be printing all the subsequences through recursion which comes out to be equal to target sum k.

#include<bits/stdc++.h>
using namespace std;

void printS(int index, vector<int> &ans, int sum, int target, int *arr, int n){

    if( index == n){
        if( sum  == target ){
            for( auto it : ans){
                cout << it << " ";
            } cout << endl;
        }

        return ;

    }
    
    // pick
    ans.push_back(arr[index]);
    sum = sum + arr[index];

    printS( index + 1, ans, sum, target, arr , n);

    // Not pick
    ans.pop_back();
    sum = sum - arr[index];

    printS( index + 1, ans, sum, target, arr , n);
}

int main(){
    int arr[3] = {1, 2, 1};
    int n = 3;
    int target = 2;
    vector<int> ans;
    printS(0, ans, 0, target, arr, n);

    return 0;
}


/* This is exactly similar to the print all the subsequence problem, here just we need to keep track of the sum
and then just print that data structure whose sum came out to be given. */