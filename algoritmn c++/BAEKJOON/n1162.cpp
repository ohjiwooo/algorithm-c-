//
//  n1162.cpp
//  algoritmn c++
//  DIJK
//  Created by 오지우 on 2022/02/02.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
#define inf LLONG_MAX

typedef long long ll;
int n,m,k;
vector<pair<int,int>> map[10003];
ll dis[10003][22];
bool vis[10003][23];
priority_queue <pair<ll,pair<int,int>>>pq; //가중치, 노드번호, 변경여부


void init(){
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dis[i][j]=inf;
        }
    }
    dis[1][0]=0;
    pq.push(make_pair(0,make_pair(1,0)));
}
int main(){
    
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b,c));
        map[b].push_back(make_pair(a,c));
        
    }
    init();
    while(pq.empty()!=true){
        
        int node=pq.top().second.first;
        int check=pq.top().second.second;
        ll w=-pq.top().first;
        pq.pop();
        if(vis[node][check]==true)continue;
        vis[node][check]=true;
        for(int i=0;i<map[node].size();i++){
            int new_node=map[node][i].first;
            int new_w=map[node][i].second;
            
            dis[new_node][check]=min(dis[new_node][check],w+new_w);
            pq.push(make_pair(-dis[new_node][check],make_pair(new_node,check)));
          
            if(check+1 <= k){
                dis[new_node][check+1]=min(dis[new_node][check+1],w);
                pq.push(make_pair(-dis[new_node][check+1],make_pair(new_node,check+1)));
            }
        }
    }
    ll answer=dis[n][0];
    for(int i=1;i<=k;i++){
        answer=min(answer,dis[n][i]);
    }
    cout<<answer;

    return 0;
}
