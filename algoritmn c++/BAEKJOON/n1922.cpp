//
//  n1922.cpp
//  algoritmn c++
//  Kruskal
//  Created by 오지우 on 2022/01/31.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n,m;//컴퓨터의 수, 간선의 수
priority_queue<pair<int,pair<int,int>>>pq;
int root[1005];
int answer=0;

void init(){
    
    for(int i=1;i<=n;i++){
        root[i]=i;
    }
}
int find(int a){
    if(root[a]==a)return a;
    else return find(root[a]);
}

void uni(int a,int b){
    int pa=find(a);
    int pb=find(b);
    
    root[pa]=pb;
}
int main(){
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        pq.push(make_pair(-c,make_pair(a,b)));
    }
    
    init();
    
    for(int i=0;i<m;i++){
        int c=-pq.top().first;
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        pq.pop();
        
        if(find(a)!=find(b)){
            answer+=c;
            uni(a,b);
        }
        
    }
    cout<<answer;
    return 0;
}
