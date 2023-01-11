#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){

    int nodes;
    cout<<"Enter number of nodes"<<endl;
    cin>>nodes;

    int edges;
    cout<<"Enter number of edges"<<endl;
    cin>>edges;

    vector<pair<int,int>> temp;
    vector<vector<pair<int,int>>> adj(nodes,temp);

    for(int i = 0;i<edges;i++){
        int des,src,wt;
        cout<<"Enter the des "<<endl;
        cin>>des;
        cout<<"Enter the src "<<endl;
        cin>>src;
        cout<<"Enter the wt "<<endl;
        cin>>wt;

        adj[des].push_back({src,wt});
        adj[src].push_back({des,wt});
    }

    queue <int> q;
    q.push(0);
    vector<pair<int,int>> minDist(nodes,{1e9,-1});
    minDist[0] = {0,-1};

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto iter : adj[curr]){
            int des = iter.first;
            int wt = iter.second;

            if(minDist[des].first>wt+minDist[curr].first){
                minDist[des].first = wt+minDist[curr].first;
                minDist[des].second = curr;
                q.push(des);
            }
        }
    }
    
    for(int i = 1;i<nodes;i++){
        
        vector<int>vec;
        int curr = i;
        while(curr!=-1){
            vec.push_back(curr);
            curr = minDist[curr].second;
        }
        reverse(vec.begin(),vec.end());
        cout<<"Path for node "<<i<<" to 0 is "<<endl;
        for(auto it : vec){
            cout<<it<<"->";
        }
        cout<<endl;
    }

    return 0;
}