#include<bits/stdc++.h>
using namespace std;

//parent track
int parent[1000];

//parentLevel track
int parentLevel[1000];
void dsu_set(int n){
    for(int i=0; i<n; i++){
        //initially all parent are -1
        parent[i]=-1;
        //initially all parent size are 1
        parentLevel[i]=0;
    }
}

//find implementation
int dsu_find(int node){
    while(parent[node]!=-1){
        node=parent[node];
    }
 return node;
}

//union implementation
void dsu_union(int a, int b){
    int leaderA= dsu_find(a);
    int leaderB= dsu_find(b);
    if(leaderA !=leaderB){
       if(parentLevel[leaderA]>parentLevel[leaderB]){
            parentLevel[leaderB]=leaderA;
       }
    }
    else if(parentLevel[leaderB]>parentLevel[leaderA]){
        parentLevel[leaderA]=leaderB;
       
    }
    else{
        parentLevel[leaderB]=leaderA;
        parentLevel[leaderA]++;
    }


    }
    


int main(){
    
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    while(e--){
        int a, b;
        cin>>a>>b;
        dsu_union(a,b);
    }
    cout<<dsu_find(4);
    return 0;
}