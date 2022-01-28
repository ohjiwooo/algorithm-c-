//
//  n1759.cpp
//  algoritmn c++
//
//  Created by 오지우 on 2022/01/28.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int l,c;
char arr[16];
bool check[30];

//최소 한 개의 모음(a, e, i, o, u)
void back_tracking(int a,int b,int num, int start,string temp){ //모음수, 자음수, 현재까지 글자수, 탐색시작할 인덱스
  
    if(num==l || start + (l-num)> c){ //글자수가 다됐거나, 남은 글자가 모자라는경우
        if(num == l && a>=1 && b>=2){
            cout<<temp<<"\n";
            return;
        }
        else return;
    }
    for(int i=start;i<c;i++){
        char cur=arr[i];
        if(check[cur-'a']==true){
            back_tracking(a+1,b,num+1,i+1,temp+cur);
        }else{
            back_tracking(a,b+1,num+1,i+1,temp+cur);
        }
        
        
    }
    
}

int main(){
    
    cin>>l>>c;
    for(int i=0;i<c;i++){
        cin>>arr[i];
    }
    sort(arr,arr+c);
    check['a'-'a']=true;
    check['e'-'a']=true;
    check['i'-'a']=true;
    check['o'-'a']=true;
    check['u'-'a']=true;
    
    back_tracking(0,0,0,0,"");
    return 0;
}
