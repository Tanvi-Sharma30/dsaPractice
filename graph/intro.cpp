#include<iostream>
using namespace std;

// store value for 
/*int main(){
    int n,m;
    cin>>n>>m;
    vector <int> adjMatrix[n+1];//each row has vector space
    for(int i=0; i<m; i++){
        int u,v;
        adjMatrix[u].push_back(v);
        adjMatrix[v].push_back(u);// this line is not required in dir graph
    }
    return 0;
}*/

// stored values of connectivity and edge weight
int main(){
    int n,m;
    cin>>n>>m;
    vector <pair<int,int>> adjMatrix[n+1];//each row has vector space
    for(int i=0; i<m; i++){
        int u,v,w;
        adjMatrix[u].push_back({v,w});
        adjMatrix[v].push_back({u,w});// this line is not required in dir graph
    }
    return 0;
}

