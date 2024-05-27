#include<iostream>
#include<unordered_map>
#include<list>
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
}