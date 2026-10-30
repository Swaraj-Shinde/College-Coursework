#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of locations: ";
    cin>>n;
    int weight[n][n];
    cout<<"enter adjacency matrix: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>weight[i][j];
        }
    }
    int source;
    cout<<"enter source location: ";
    cin>>source;

    int dist[n],visited[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[source]=0;

    for(int i=0;i<n;i++)
    {
        int min=INT_MAX,u=-1;
        
        //find unvisited locations
        for(int j=0;j<n;j++)
        {
            if(visited[j]==0 && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }
        if(u==-1)
        {
            break;
        }
        else
        {
            visited[u]=1;
        }

        //update for neighbouring locations
        for(int v=0;v<n;v++)
        {
            if(weight[u][v]!=0 && visited[v]==0)
            {
                if(dist[u]+weight[u][v]<dist[v])
                {
                    dist[v]=dist[u]+weight[u][v];
                }
            }
        }
    }
    cout<<"Shortest distance: ";
    for(int i=0;i<n;i++)
    {
        cout<<"LOCation:"<<"i"<<" "<<dist[i]<<endl;
    } 
    return 0;
}