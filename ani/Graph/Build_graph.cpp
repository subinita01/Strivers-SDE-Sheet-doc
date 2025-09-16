#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int> *l; // dynamic array of lists

public:
    Graph(int V) {
        // initialize the number of vertices
        this->V = V;
        l = new list<int>[V];// create an array of V lists
    }

    void addEdge(int u, int v, bool undir = true) {
        l[u].push_back(v);
        if (undir) {
            l[v].push_back(u);
        }
    }

    void printAdjList() {
        // iterate over all the rows
        for (int i = 0; i < V; i++) {
            cout << i << "->";
            // iterate over the ith list
            for (auto node : l[i]) {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    void bfs(){
        vector<bool>vis (V,false);
        queue<int>Q;
        vis[0] = true;
        Q.push(0);
        while(Q.size()>0){
            int u = Q.front();
            Q.pop();
            cout<<u<<" ";

            for(int v: l[u]){
                if(!vis[v]){
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }


    }
    
    void dfsHelper(int u, vector<int>& vis){
        cout<<u<<" ";
        vis[u]=true;
        for(int v: l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }

    void dfs(){
        int u = 0;
        vector<int> vis(V,false);
        dfsHelper(u,vis);
    }

    bool isCycleUndirDFS(int src, int par, vector<bool>& vis){
        vis[src] = true;
        for(int v: l[src]){
            if(!vis[v]){
                if(isCycleUndirDFS(v,src,vis)){
                    return true;
                }
            }
            else if(v!=par){
                return true;
            }
            
        
        }
        return false;
    }

    bool isCycle(){
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
            if(isCycleUndirDFS(i,-1,vis)){
                return true;
            }
        }
        }
        return false;
    }
    

};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    cout<<"AdjList:"<<endl;
    g.printAdjList();
    cout<<"BFS:"<<" ";
    g.bfs();
    cout<<endl;
    cout<<"DFS:"<<" ";
    g.dfs();
    cout<<endl;
    cout<<"Check cycle present or not:"<<" ";
    cout<<g.isCycle();

    return 0;
}
