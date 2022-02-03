//
//  n11728.cpp
//  algoritmn c++
//  ywo pointer
//  Created by 오지우 on 2022/02/03.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


int n,m;
vector<int>arr1;
vector<int>arr2;
vector<int>answer;
int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr1.push_back(a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        arr2.push_back(a);
    }
    
    int a=0;
    int b=0;
    while(a < n && b < m){
        if(arr1[a]>=arr2[b]){
            answer.push_back(arr2[b++]);
        }else{
            answer.push_back(arr1[a++]);
        }
    }
    
    while(a<n)answer.push_back(arr1[a++]);
    while(b<m)answer.push_back(arr2[b++]);
    
    for(int i=0;i<n+m;i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}
