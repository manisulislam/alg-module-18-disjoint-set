#include<bits/stdc++.h>
using namespace std;

//parent track
int parent[1000];

//parentsize track
int parentSize[1000];
void dsu_set(int n){
    for(int i=0; i<n; i++){
        //initially all parent are -1
        parent[i]=-1;
        //initially all parent size are 1
        parentSize[i]=1;
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
        if(parentSize[leaderA]> parentSize[leaderB]){
        //when leader A
        parent[leaderB]=leaderA;
        parentSize[leaderA]+=parentSize[leaderB];
    }
    else{
        //when leader B
        parent[leaderA]=leaderB;
        parentSize[leaderB]+=parentSize[leaderA];
    }


    }
    

}
int main(){
    
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    while(e--){
        int a, b;
        cin>>a>>b;
        int leaderA= dsu_find(a);
        int leaderB= dsu_find(b);
        if(leaderA==leaderB){
            cout<<"cycle detect between : "<<a<<" "<<b<<endl;
        }
        else{

            dsu_union(a,b);
        }
        
        
        
    }
    
    return 0;
}