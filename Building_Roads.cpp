#include<bits/stdc++.h>
using namespace std;
//range;
const int N=1e5+5;
//parent track
int parent[N];

//parentsize track
int parentSize[N];
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
    int n, e;
    cin>>n>>e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin>>a>>b;
        dsu_union(a,b);
    }
    
    //map
    map<int,bool>mp;

    for(int i=1; i<=n; i++){
        int leader=dsu_find(i);
        mp[leader]=true;
    }
    vector<int>v;
    for(pair<int, bool>p:mp){
        v.push_back(p.first);
    }

    cout<<v.size()-1<<endl;
    for(int i=0; i<v.size()-1; i++){
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
    return 0;
}