from heapq import heappush , heappop, heapify

class Graph :
    def __init__(self, n ) :
        self.n = n
        self.adj = { v : [] for v in range(n) }

    def add_edge(self, s, t, w) :
        self.adj[s].append((t , w))

class Diksktras :
    def __init__(self, g , n) :
        self.g = g
        self.n = n
        self.path = [ 0 for _ in range(n) ]
    
    def find_shortest_distance(self, start, end) :
        distance = [float('inf') for _ in range(self.n)]
        g = self.g
        path = self.path

        heap = [(0, start)]
        distance[0] = 0
        heapify(heap)

        while heap :
            pr_node = heappop(heap)
            from_node = pr_node[1]

            for (to_node, w) in g.adj[from_node] :
                if distance[to_node] > distance[from_node] + w :
                    distance[to_node] = distance[from_node] + w
                    path[to_node] = from_node
                    heap.append((distance[to_node] , to_node))
                    heapify(heap)

        return distance[end]
    
edges = [   ( 0 , 2,  1 ) , ( 0, 3, 2 ) , ( 0, 1, 5 ) , ( 2, 1, 3) ,  ( 3, 1, 5 ) , ( 3, 4, 3 ) , ( 1 , 4, 1)   ]

g = Graph(5)

for ( s, t, w ) in edges :
    g.add_edge(s, t, w)

d = Diksktras(g, 5)

print(d.find_shortest_distance(0, 4))
print(d.path);
