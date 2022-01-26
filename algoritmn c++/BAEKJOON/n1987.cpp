//
//  n1987.cpp
//  algoritmn c++
//  DFS
//  Created by 오지우 on 2022/01/26.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int r,c; //세로칸, 가로칸 수
char map[22][22];
bool vis[30];
int cur_x, cur_y; //현재 좌표
int dx[4]={0,1,0,-1}; //북쪽부터 시계방향
int dy[4]={-1,0,1,0};
int answer=0;

void dfs(int cur_x,int cur_y, int depth){
    answer= max(answer,depth);
    for(int i=0;i<4;i++){
        int new_x=cur_x+dx[i];
        int new_y =cur_y+dy[i];
        if( new_x< c && new_x>= 0 && new_y<r && new_y >= 0&& vis[map[new_y][new_x]-'A']!=true){
            vis[map[new_y][new_x]-'A']=true;
            dfs(new_x,new_y,depth+1);
            vis[map[new_y][new_x]-'A']=false;
        }
    }
}

int main(){
    
    cin>>r>>c;
    
    for(int i=0;i<r;i++){
        cin>>map[i];
    }
    vis[map[0][0]-'A']=true;
    dfs(0,0,0);
    cout<<answer+1;
    
    
    return 0;
}
