//
//  n2293.cpp
//  algoritmn c++
//  DP
//  Created by 오지우 on 2022/01/30.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int n,k;
int arr[105];
int dp[10005];


void d_p(){
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<=k;j++){
            dp[j]+=dp[j-arr[i]];
        }
    }
}
int main(){
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  
    d_p();
    cout<<dp[k];
    
    return 0;
}
