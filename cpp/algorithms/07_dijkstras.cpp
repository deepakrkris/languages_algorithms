/**
 * @file 07_dijkstras.cpp
 * 
 * {  { 0 , 2 } , { 0, 3 } , { 2, 1 } , { 0, 1 } ,  {0 , 3 } , { 3, 4 } , { 1 , 4 }  }
 *        
 *       2            4          3         5           4           3         1        
 *          
 *        -> 2  ->
 *       0      -> 1  ->            
 *        -> 3  ->    -> 4
 *  
 * 0
 *   -> 2 (2, 0)
 *   -> 3 (3, 4)  
 * 
 * 2 -> 
 *   
 */
#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <stack>

using namespace std;

#define INF 100000

class Graph {
    map<int, list<pair<int, int>>> adj;

    public:
    int number_of_nodes;

    Graph(int n) : number_of_nodes(n) {}

    void add_edge(int u, int v, int w) {
        if (adj.find(u) == adj.end()) {
            adj[u] = {};
        }
        adj[u].push_back(make_pair(v, w));
        for_each(adj[u].begin(), adj[u].end(), [&u](auto e) {
            cout << " node " << u << " has edge to " << e.first << " with weight " << e.second << endl;
        });
    }

    list<pair<int, int>> get_edges(int u) {
        return adj[u];
    }
};

class Dijsktras {
    Graph g;
    vector<int> distance;
    vector<int> path;

    public:
    Dijsktras(Graph _g) : g(_g) {
        vector<int> d(g.number_of_nodes, INF);
        distance = d;
        vector<int> p(g.number_of_nodes, 0);
        path = p;
    }

    stack<int> find_path(int start, int end) {
        int from_node = end;
        stack<int> result;

        while (from_node != start) {
            result.push(from_node);
            from_node = path[from_node];
        }
   
        result.push(start);

        return result;
    }

    int find_shortest_distance(int start, int end) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        pq.push({0, start});
        distance[0] = 0;

        while (pq.size() > 0) {
            auto edge = pq.top();
            int from_node = edge.second;
            pq.pop();

            for (auto& [to_node, w] : g.get_edges(from_node)) {
                cout << "current distance to " << to_node << "  is " << distance[to_node] << endl;
                cout << "w : " << w << endl;
                cout << "proposed distance from " << from_node << " is "  << distance[from_node] + w << endl;
                if (distance[to_node] > distance[from_node] + w) {
                    path[to_node] = from_node;
                    distance[to_node] = distance[from_node] + w;
                    cout << "distance to  " << to_node << "  is " << distance[to_node] << " from " << path[to_node] << endl;
                    pq.push({ distance[to_node], to_node });
                }
                cout << std::string(20, '_') << endl;
            }
        }

        return distance[end];
    }
};

int main() {
    vector<vector<int>> edges = {  { 0 , 2 , 1 } , { 0, 3, 2 } , { 0, 1, 5 } , { 2, 1, 1 } , { 3, 1, 2 } , { 3, 4, 3 } , { 1 , 4, 1 }  };
    Graph g(5);

    for (auto e : edges) {
        g.add_edge(e[0], e[1], e[2]);
    }
    Dijsktras d(g);
    cout << d.find_shortest_distance(0 , 4) << endl;

    auto shortest_path = d.find_path(0, 4);

    cout << " shorted path is : " ;
 
    while(shortest_path.size() > 0) {
        cout << " -> " << shortest_path.top() ;
        shortest_path.pop();
    }

    cout << endl << endl;
    cout << string(20, '_') << endl;
}
