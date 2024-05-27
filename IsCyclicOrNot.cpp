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

bool CheckForCyclic(unordered_map<int,list<int>>& mp,unordered_map<int,bool>& visited,int node)
{
    unordered_map<int,int> parent;

    parent[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for(auto itr : mp[frontNode])
        {
            if(visited[itr] == true && itr != parent[frontNode])
            {
                return true;
            }
            else if(!visited[itr])
            {
                q.push(itr);
                visited[itr] = true;
                parent[itr] = frontNode;
            }
        }
    }
    return false;
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
    bool ans;
    for(auto itr : mp)
    {
        if(!visited[itr.first])
        {
            ans = CheckForCyclic(mp,visited,itr.first);
            if(ans == true)
            {
                cout<<"Cycle Found in the Graph";
                break;
            }
        }
    }
    if(ans != true)
    {
        cout<<"Cycle Not Found in the graph";
    }
    return 0;
}