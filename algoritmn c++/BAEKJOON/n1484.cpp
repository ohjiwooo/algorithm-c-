//
//  n1484.cpp
//  algoritmn c++
//  two pointer
//  Created by 오지우 on 2022/01/30.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int n;

int main(){
    
    cin>>n;
    int answer=0;
    int now=2;
    int pre=1;
    while(1){
        if(now==pre)break;
        int now2=now*now;
        int pre2=pre*pre;
        if(now2-pre2 < n) now++;
        else if(now2-pre2==n) {
            cout<<now<<"\n";
            now++;pre++;answer++;
        }
        else{
            pre++;
        }
    }
    if(answer==0)cout<<"-1";
    return 0;
}

