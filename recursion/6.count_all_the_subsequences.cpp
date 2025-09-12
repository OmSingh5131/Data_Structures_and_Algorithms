// If only count is asked , that how many subsequences could be there


#include<bits/stdc++.h>
using namespace std;

int printSub(int index, int sum, int target, int *arr, int n){

    if( index == n){
        // condition satisfied 
        if( sum  == target ){
            return 1;  
        }
        // condition not satisfied
        else{
            return 0;
        }
    }
    
    // pick
    sum = sum + arr[index];
    int l = printSub( index + 1, sum, target, arr , n);
    
    
    sum = sum - arr[index];

    // Not pick
    int r = printSub( index + 1, sum, target, arr , n);

    return l + r;
}

int main(){
    int arr[3] = {1, 2, 1};
    int n = 3;
    int target = 2  ;
    cout << printSub(0, 0, target, arr, n);

    return 0;
}