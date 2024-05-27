#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

void CreateAdjacency(unordered_map<int,list<int>>& mp,int u,int v)
{
    mp[u].push_back(v);
    mp[v].push_back(u);
}

void PrintAdjacency(unordered_map<int,list<int>>& mp)
{
    for(auto itr : mp)
    {
        cout<<itr.first<<"->";
        for(auto it : itr.second)
        {
            cout<<","<<it;
        }
        cout<<endl;
    }
}

void dfs(unordered_map<int,list<int>>& mp,unordered_map<int,bool>& visited,int node,vector<int>& result)
{
    result.push_back(node);
    visited[node] = true;

    for(auto itr : mp[node])
    {
        if(!visited[itr])
        {
            dfs(mp,visited,itr,result);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the no. of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the no. of edges : ";
    cin>>m;

    unordered_map<int,list<int>> mp;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        CreateAdjacency(mp,u,v);
    }

    PrintAdjacency(mp);

    unordered_map<int,bool> visited;
    vector<int> result;

    for(auto itr : mp)
    {
        if(!visited[itr.first])
        {
            dfs(mp,visited,itr.first,result);
        }
    }

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }

}