// Sum of first n numbers 


// Parameter way

#include<bits/stdc++.h>
using namespace std;

void sum_first_n( int n, int sum){
    if(n < 1){
        cout << "Sum is : " << sum;
        return;
    }
    sum_first_n( n - 1, sum + n);
}

int main(){
    int n = 3;
    sum_first_n(3,0);
}

// Functional way : Instead of printing, I actually want something in return, I want some value

#include<bits/stdc++.h>
using namespace std;

int sum( int n){
    if( n == 0){
        return 0;
    }
    return n + sum(n-1);
}

int main(){
    int n = 3;

    cout << sum(n);
}


// Factorial of n

// Parameterised way

#include<bits/stdc++.h>
using namespace std;

void fact(int n, int product){

    if( n == 1){
        cout << product;
        return;
    }

    fact( n - 1, n * product);

}

int main(){
    int n = 4;

    fact(n, 1);
    return 0;
}


// Multiple Recursion calls

// fibonacci : T.C. = O(2^n)

#include<bits/stdc++.h>
using namespace std;

int fibo(int n){

    if( n == 0){
        return 0;
    }

    if( n == 1){
        return 1;
    }

    return fibo(n-1) + fibo(n-2);
}

int main(){
    cout << fibo(4);
    return 0;
}



