//
//  n2206.cpp
//  algoritmn c++
//
//  Created by 오지우 on 2022/01/26.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int inf=987654321;
int n,m; //행,열의 개수
int map[1004][1004];
int dx[4] = {0,1,0,-1}; //북쪽부터 시계방향
int dy[4] = {-1,0,1,0};
int answer=0;
int temp[1004][1004][2];
bool vis[1004][1004][2];
queue <pair<pair<int,int>,int>> q; //x,y,벽 부순 여부(0:안부숨 1:부숨)
void bfs(){
    q.push(make_pair(make_pair(0,0),0));
    while(q.empty()!=true){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int check=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int new_y=y+dy[i]; int new_x=x+dx[i];
            if( new_x >= 0 && new_x <m && new_y >= 0 && new_y < n){
                if(check == 1){ //이미 부숨
                    if(map[new_y][new_x]!=1 && temp[new_y][new_x][1] > temp[y][x][1]+1){
                        temp[new_y][new_x][1] = temp[y][x][1]+1;
                        q.push(make_pair(make_pair(new_x,new_y),1));
                    }// 방문한적이 없거나 현재가 최단거리일 경우
                }
                else{ //아직 안부숨
                    if(map[new_y][new_x]==0 &&temp[new_y][new_x][0] > temp[y][x][0]+1){
                        temp[new_y][new_x][0] = temp[y][x][0]+1 ;
                        q.push(make_pair(make_pair(new_x,new_y),0));
                    }else if(map[new_y][new_x]==1 &&temp[new_y][new_x][1] >
                             temp[y][x][0]+1){
                        temp[new_y][new_x][1] = temp[y][x][0]+1;
                        q.push(make_pair(make_pair(new_x,new_y),1));
                    }
                }
            }
        }
    }
}
int main(){
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin>>a;
            map[i][j]=a-'0';
            temp[i][j][0]=inf;
            temp[i][j][1]=inf;
        }
    }
    temp[0][0][0]=1;
    temp[0][0][1]=1;
    bfs();
    answer = min(temp[n-1][m-1][0],temp[n-1][m-1][1]);
    if(answer==inf)answer=-1;
    cout<<answer;
    return 0;
}
