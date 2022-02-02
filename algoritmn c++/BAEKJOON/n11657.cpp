//
//  n11657.cpp
//  algoritmn c++
//  Bellman-ford
//  Created by 오지우 on 2022/02/02.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define inf LLONG_MAX
typedef long long ll;
int n,m;
vector<pair<int,int>>map[505];
ll dis[505];

void init(){
    
    for(int i=2;i<=n;i++){
        dis[i]=inf;
    }
    dis[1]=0;
}
bool bellman_ford(){ // 사이클이있을시 1, 없을시 0반환
    bool flag=0;
    for(int i=0;i<n;i++){ //n-1 번째 변경시 사이클 존재
        for(int j=1;j<=n;j++){
            if(dis[j]==inf)continue;
            for(int k=0;k<map[j].size();k++){
                int new_node=map[j][k].first;
                int new_w=map[j][k].second;
                if(dis[j]+new_w < dis[new_node]){
                    dis[new_node]=dis[j]+new_w;
                    if(i==n-1)flag=1;
                }
            }
        }
    }
    return flag;
}
int main(){
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b,c));
    }
    
    init();
    if(bellman_ford()==1)cout<<-1;
    else{
        for(int i=2;i<=n;i++){
            if(dis[i]==inf)cout<<"-1\n";
            else{cout<<dis[i]<<"\n";}
        }
        
    }
    
    
    return 0;
}

