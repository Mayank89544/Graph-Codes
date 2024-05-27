#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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
            cout<<it<<",";
        }
        cout<<endl;
    }
}

vector<int> bfs(unordered_map<int,list<int>>& mp,unordered_map<int,bool>& visited,int node)
{
    queue<int> q;
    q.push(node);

    visited[node] = true;
    vector<int> result;
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        result.push_back(frontNode);

        for(auto itr : mp[frontNode])
        {
            if(!visited[itr])
            {
                q.push(itr);
                visited[itr] = true;
            }
        }
    }
    return result;

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
        cin >> u >> v;
        CreateAdjacency(mp,u,v);
    }
    PrintAdjacency(mp);

    unordered_map<int,bool> visited;
    vector<int> result;
    for(auto itr : mp)
    {
        if(!visited[itr.first])
        {
            vector<int> temp = bfs(mp,visited,itr.first);
            result.insert(result.end(),temp.begin(),temp.end());
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<result[i]<<" ";
    }

}