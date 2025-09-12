// Two pointer approach

#include<bits/stdc++.h>
using namespace std;

void rev(int l, int arr[], int r ){
    if(l >= r){
        for(int i = 0; i < 5; i++){
            cout << arr[i] << " ";
        }
        return;
    }

    swap(arr[l], arr[r]);

    rev( l + 1, arr, r - 1);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    rev(0,arr,4);
    return 0;
}

// Optimising this with only one pointer

#include<bits/stdc++.h>
using namespace std;

void reve(int i, int arr[], int n){
    if(i >= n/2){

        for(int i = 0; i < 5; i++){
            cout << arr[i] << " ";
        }
        return;

    }
    swap(arr[i],arr[n-i-1]);
    reve(i+1,arr,5);

}

int main(){
    
    int arr[5] = {1,2,3,4,5};
    reve(0,arr,5);

    return 0;
} 


// check if a string is a palindrome or not


#include<bits/stdc++.h>
using namespace std;

bool palindrome(int i, string s){

    if(i >= s.size()/2){
        return true;
    }
    if(s[i] != s [ s.size() - i - 1]){
        return false;
    }
    
    return palindrome( i + 1, s);

}

int main(){
    
    string s = "MADAM";
    cout << palindrome(0,s);

    return 0;
} 

