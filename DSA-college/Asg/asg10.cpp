#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int graph[n][n];
    string dept[5]={"comp","it","aiml","entc","mech"};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    bool visited[5]={false};
    int total_dist=0;

    visited[0]=1;

    for(int count=0;count<n-1;count++) //n vertices toh n-1 edges
    {
        int min_dist=INT_MAX;
        int from=-1,to=-1;

        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
            for(int j=0;j<n;j++)
            {
                if(!visited[j] && graph[i][j]!=0 && graph[i][j]<min_dist)
                {
                    min_dist=graph[i][j];
                    from=i;
                    to=j;
                }
            }
            }
        }
        if(to==-1)
        {
            cout<<"graph not connnected\n";
        }
        else
        {
            cout<<dept[from]<<"-"<<dept[to]<<":"<<min_dist;
            visited[to]=true;
            total_dist+=min_dist;
        }
    }
    cout<<total_dist;
}