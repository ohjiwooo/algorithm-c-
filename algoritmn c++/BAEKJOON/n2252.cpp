//
//  n2252.cpp
//  algoritmn c++
//
//  Created by 오지우 on 2022/01/30.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n,m;
vector<int>arr[32005];
int num[32005];
queue<int>q;
int main(){
    
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b; //a가 b의 앞
        arr[a].push_back(b);
        num[b]++;
    }
    
    for(int i=1;i<=n;i++){
        if(num[i]==0)q.push(i);
    }
    
    while(q.empty()!=true){
        int cur=q.front();q.pop();
        cout<<cur<<" ";
        for(int i=0;i<arr[cur].size();i++){
            if(--num[arr[cur][i]]==0)q.push(arr[cur][i]);
        }
    }
    return 0;
}
