//
//  n2661.cpp
//  algoritmn c++
//  back tracking
//  Created by 오지우 on 2022/01/28.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int n;
char arr[3]={'1','2','3'};

bool check(string answer){
    
    int start=0;
    if(answer.length()%2!=0)start=1;
    int gap=answer.length()/2;
    
    while(start < answer.length()-1){
        string tmp1=answer.substr(start,gap);
        string tmp2=answer.substr(start+gap,gap);
        if(tmp1.compare(tmp2)==0)return false;
        gap--;
        start+=2;
    }
    return true;
}

bool dfs(string answer){
    
    if(answer.length()==n){
        cout<<answer;
        return true;}
    for(int i=0;i<3;i++){
        string temp=answer+arr[i];
        if(check(temp)==true){
            if(dfs(temp)==true){return true;}
        }
    }
    return false;
}

int main(){
    
    cin>>n;
    
    dfs("");
    return 0;
}
