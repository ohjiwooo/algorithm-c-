//
//  n1865.cpp
//  algoritmn c++
//  Bellman-ford
//  Created by 오지우 on 2022/02/02.
//  출발점이 정해지지 않으므로 inf인 정점도 방문가능

#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define inf INT_MAX
typedef long long ll;

int test,n,m,k;
vector<pair<int,ll>>map[505];
ll dis[505];


bool bellman_ford(){
    
    
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<map[j].size();k++){
                if(dis[map[j][k].first] > dis[j]+map[j][k].second){
                    dis[map[j][k].first] = dis[j]+map[j][k].second;
                    if(i==n-1)return true;
                }
            }
        }
    }
    return false;
}
void init(){
    
    for(int i=1;i<=n;i++){
        dis[i]=inf;
        map[i].clear();
    }
    dis[1]=0;
}
int main(){
    
    cin>>test;
    while(test--){
        cin>>n>>m>>k;
        
        init();
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            map[a].push_back(make_pair(b,c));
            map[b].push_back(make_pair(a,c));
        }
        for(int i=0;i<k;i++){
            int a,b,c;
            cin>>a>>b>>c;
            map[a].push_back(make_pair(b,-c));
        }
        
        if(bellman_ford()==true)cout<<"YES\n";
        else{cout<<"NO\n";}
    }
    
    
    return 0;
}
