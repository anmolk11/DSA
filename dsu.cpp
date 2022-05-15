#include<bits/stdc++.h>
using namespace std;

vector<int> Rank,par,total,minE,maxE;

int find(int x){
    return par[x] = (x == par[x] ? x : find(par[x])); 
}

void Union(int x,int y){
    int xr = find(x),yr = find(y);
    if(xr == yr) return;
    
    if(Rank[xr] > Rank[yr]){
        par[yr] = xr;
        total[xr] += total[yr]; 
        minE[xr] = min(minE[xr],minE[yr]);
        maxE[xr] = max(maxE[xr],maxE[yr]);
    }
    else if(Rank[xr] < Rank[yr]){
        par[xr] = yr;
        total[yr] += total[xr];
        minE[yr] = min(minE[xr],minE[yr]);
        maxE[yr] = max(maxE[xr],maxE[yr]);
    }
    else{
        par[yr] = xr;
        total[xr] += total[yr];
        minE[xr] = min(minE[xr],minE[yr]);
        maxE[xr] = max(maxE[xr],maxE[yr]);
        Rank[xr]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    Rank.resize(N+1,0);
    par.resize(N+1);
    total.resize(N+1,1);
    minE.resize(N+1);
    maxE.resize(N+1);
    for(int i = 0;i <= N;i++) minE[i] = maxE[i] = par[i] = i;
    string op;
    int x,y;
    while(M--){
        cin>>op;
        if(op == "union"){
            cin>>x>>y;
            Union(x,y);
        }
        else{
            cin>>x;
            int xr = find(x);
            cout<<minE[xr]<<' '<<maxE[xr]<<' '<<total[xr]<<'\n';
        }
    }
}
