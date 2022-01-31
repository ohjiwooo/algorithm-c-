//
//  n2887.cpp
//  algoritmn c++
//  Kruskal
//  Created by 오지우 on 2022/01/31.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;//행성의 수
int root[100005];
int answer=0;
vector<pair<int,int>>x;
vector<pair<int,int>>y;
vector<pair<int,int>>z;
vector<pair<int,pair<int,int>>>all;




void init(){
    for(int i=1;i<=n;i++){
        root[i]=i;
    }
}

int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
    
}

void uni(int a,int b){
    int pa=find(a);
    int pb=find(b);
    
    root[pa]=pb;
}




int main(){
 
    cin>>n;
    
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        x.push_back(make_pair(a,i));
        y.push_back(make_pair(b,i));
        z.push_back(make_pair(c,i));
    }
    
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());
    
    for(int i=1;i<n;i++){
        all.push_back(make_pair(x[i].first-x[i-1].first,make_pair(x[i].second,x[i-1].second)));
        all.push_back(make_pair(y[i].first-y[i-1].first,make_pair(y[i].second,y[i-1].second)));
        all.push_back(make_pair(z[i].first-z[i-1].first,make_pair(z[i].second,z[i-1].second)));
        
    }
    sort(all.begin(),all.end());
    init();
    for(int i=0;i<all.size();i++){
        int c=all[i].first;
        int a=all[i].second.first;
        int b=all[i].second.second;
        if(find(a)!=find(b)){
            uni(a,b);
            answer+=c;
        }
    }
    cout<<answer;
    return 0;
}
