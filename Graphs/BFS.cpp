#include<bits/stdc++.h>
#include <list>
using namespace std;

class Graph{
    int v;
    list<int>*l; // l does not point to the linked list 
    // Rather l points to the integers

    public:
    Graph(int vertex){
        v=vertex;
        l=new list<int>[v];
    }

    void addEdge(int u,int v){

        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printAdjList(){
        for(int i =0;i<v;i++){
            cout << i <<"---";
            for(int neigh : l[i]){
                cout << neigh << " ";
            }
            cout <<endl;
        }
    }

    void BFS(){ //O(V+E)
        queue<int>q;
        vector<bool>vis(v,false); // vertices 0,1,2,3
                                 //,4 so index gula vertex mean korbe

        q.push(0); // pushing the first source node
        vis[0]=true;
        while(q.size()>0){

            int source=q.front();
            q.pop();

            cout<<source<< " ";
            for(int neighbour: l[source]){ // it will loop through the list of that vertice
                if(vis[neighbour]==false){
                    vis[neighbour]=true;
                    q.push(neighbour);
                };
                
            }
        }
    }

};
int main(){
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(1,3);
    g1.addEdge(1,2);
    g1.addEdge(2,4);

    g1.printAdjList();

    g1.BFS();

}