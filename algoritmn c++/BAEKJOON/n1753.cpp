//
//  n1753.cpp
//  algoritmn c++
//  DIJK
//  Created by 오지우 on 2022/02/02.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int inf=999999999;
int v,e,start;
bool vis[20005];
vector<pair<int,int>>map[20005];
int answer[20005];
priority_queue <pair<int,int>>pq;

void init(){
    
    for(int i=0;i<=v;i++){
        answer[i]=inf;
    }
}
int main(){
    
    cin>>v>>e>>start;
    
    init();
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b,c));
    }
    
    pq.push(make_pair(0,start));
    answer[start]=0;
    while(pq.empty()!=true){
        int w=-pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(vis[node]==true)continue;
        vis[node]=true;
        
        for(int i=0;i<map[node].size();i++){
            int new_node=map[node][i].first;
            int new_w=map[node][i].second;
            answer[new_node]= min(answer[new_node],answer[node]+new_w);
            pq.push(make_pair(-answer[new_node],new_node));
        }
    }
    for(int i=1;i<=v;i++){
        if(answer[i]==inf)cout<<"INF\n";
        else
            cout<<answer[i]<<"\n";
        }

    return 0;
}
