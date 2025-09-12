// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTabValue=PROBLEM

// MAXIMUM SUM OF NON ADJACENT ELEMENTS


// Implementing the basic logic.

// You are given an array like (2, 1, 4, 9) and you need to find the maximum sum of non adjacent elements, which is 11 in this case

#include<bits/stdc++.h>
using namespace std;

int sum( int index, int arr[]){

    if( index == 0){
        // 0 pe pahunch hi gaye ho to sum ko maximise kar lo, arr[0] ko include karke
        return arr[0];
    }

    else if( index < 0){
        return 0;
    }

    int pick = arr[ index ] + sum(index-2, arr);
    int not_pick = 0 + sum( index - 1, arr);

    return max(pick, not_pick);
}

int main(){
    // Here you are given the array
    int arr[4] = {2,1,4,9};
    int n = 4 ;

    int ans = sum(3, arr);

    cout << ans << endl;

}

// Incorporating DP in this 

#include <bits/stdc++.h> 
using namespace std;

int sum(int n, vector<int> &nums, vector<int> &dp){

    // base case
    dp[0] = nums[0];

    if(dp[n] != -1){
        return dp[n];
    }


    // Introduce the dp in this logic

    int pick = nums[n];

    if(n > 1){
        pick = pick + sum( n - 2, nums, dp);
    }
    
    int not_pick = 0 + sum( n - 1, nums, dp);

    // Put the result into the dp
    dp[n] = max(pick, not_pick);

}

int maximumNonAdjacentSum(vector<int> &nums){

    // We can introduce memoization in it
    // Introducing the dp array

    vector<int> dp( nums.size(), - 1) ;
    
    sum( nums.size() - 1, nums, dp );

    int ans = dp[nums.size()-1];
    return ans;

}


// Using the tabulation approach ( Bottom Up)

// We need to code the tabulation format.

#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[4] = {2, 1, 4, 9};

    vector<int> dp( 4, -1 );
    dp[0] = arr[0];

    for( int i = 1; i < 4; i++ ){
        int take = arr[i] + 0;
        if(i > 1){
            take = take + dp[ i - 2];
        }
        int not_take = 0 + dp[i - 1];

        dp[i] = max(take,not_take);

    }

    cout << dp[3];

    
}

// Space Optimization

#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[4] = {2, 1, 4, 9};
    
    int prevprev = 0;
    int prev = arr[0];

    int curr;
    

    for( int i = 1; i < 4; i++ ){
        
        int take = arr[i];
        if( i > 1){
            take = arr[i] + prevprev;
        }

        int not_take = 0 + prev;

        curr = max(take, not_take);

        prevprev = prev;
        prev = curr;

    }

    cout << curr;

    

}


