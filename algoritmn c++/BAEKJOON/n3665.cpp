//
//  n3665.cpp
//  algoritmn c++
//  위상정렬
//  Created by 오지우 on 2022/01/31.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,team;

int map[505][505]; //그래프
vector<int>v[505]; //위상정렬
vector<int>t; //팀저장
queue<int>q;
int num[505];

void init(int team){
    
    for(int i=1;i<=team;i++){
        num[i]=0;
        v[i].clear();
        for(int j=1;j<=team;j++){
            map[i][j]=0;
        }
    }
    t.clear();
    while(q.empty()!=true)q.pop();
}
int main(){
    
    cin>>n;
    for(int k=0;k<n;k++){
        
        cin>>team; //팀수
        init(team);
        for(int i=0;i<team;i++){
            int a;
            cin>>a;
            t.push_back(a);
        }
        for(int i=0;i<team;i++){
            for(int j=i+1;j<team;j++){
                map[t[i]][t[j]]=1;
            }
        }
        int c;//바뀐수
        cin>>c;
        for(int i=0;i<c;i++){
            int a,b;
            cin>>a>>b;
            if(map[a][b]==1){
                map[a][b]=0;
                map[b][a]=1;
            }
            else{
                map[a][b]=1;
                map[b][a]=0;
            }
        }
     
        for(int i=1;i<=team;i++){
            for(int j=1;j<=team;j++){
                if(map[i][j]==1){
                    v[i].push_back(j);
                    num[j]++;
                }
            }
        }//위상정렬
        
        for(int i=1;i<=team;i++){
            if(num[i]==0)q.push(i);
        }
        vector<int>answer;
        int code=0;
        while(q.empty()!=true){
            if(q.size()>1){answer.clear();code=2;break;}
            int cur=q.front();
            q.pop();
            answer.push_back(cur);
            for(int i=0;i<v[cur].size();i++){
                if(--num[v[cur][i]]==0)q.push(v[cur][i]);
            }
            
        }
        if(answer.size()<team)code=1;
        if(code==1)cout<<"IMPOSSIBLE\n";
        else if(code==2)cout<<"?\n";
        else{
            for(int i=0;i<answer.size();i++){
                cout<<answer[i]<<" ";
            }cout<<"\n";
            
        }
        
    }
    
    return 0;
}
