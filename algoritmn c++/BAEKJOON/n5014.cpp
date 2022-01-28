//
//  n5014.cpp
//  algoritmn c++
//  BFS
//  Created by 오지우 on 2022/01/28.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int f,s,g,u,d;//총 층수, 현재 층, 목표 층,위 버튼, 아래버튼
bool vis[1000005];
queue<pair<int,int>> q;
int answer=987654321;

void bfs(){
    vis[s]=true;
    q.push(make_pair(s,0));
    
    while(q.empty()!=true){
        int cur=q.front().first;
        int n=q.front().second;
        q.pop();
        if(cur==g){
            answer=min(answer,n);
        }
        else{
            if(cur+u > 0 && cur+u <= f &&vis[cur+u]!=true){
                q.push(make_pair(cur+u,n+1));
                vis[cur+u]=true;
            }
            if(cur-d > 0 && cur-d <= f &&vis[cur-d]!=true){
                q.push(make_pair(cur-d,n+1));
                vis[cur-d]=true;
            }
        }
    }
}

int main(){
    
    cin>>f>>s>>g>>u>>d;
    bfs();
    if(answer==987654321)cout<<"use the stairs";
    else{cout<<answer;}
    return 0;
}
