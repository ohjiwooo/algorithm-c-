//
//  n2606.cpp
//  algoritmn c++
//  BFS
//  Created by 오지우 on 2022/01/26.
//

#include <stdio.h>
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int computer_num; //컴퓨터의 수
int pair_num; //연결된 쌍의 수
vector <int> conn[102]; //연결 표현
queue <int> q;
bool vis[102];
int answer=0;

int main(){
    
    cin>> computer_num >> pair_num;
    
    for(int i=0;i<pair_num;i++){
        int a,b;
        cin>>a>>b;
        conn[a].push_back(b);
        conn[b].push_back(a);
    }
    
    q.push(1);
    vis[1]=true;
    while(q.empty()!=true){
        int now= q.front();
        q.pop();
        for(int i=0;i<conn[now].size();i++){
            if(vis[conn[now][i]]==true) continue;
            vis[conn[now][i]]=true;
            answer++;
            q.push(conn[now][i]);
        }
    }
    
    cout<<answer;
    return 0;
}
