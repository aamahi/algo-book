import Queue

inf = 2000000*100

def BFS(graph, src, sink, par):
    visit = [False] * len(graph)
    q = Queue.Queue()

    q.put(src)
    visit[src] = True

    while not q.empty():
        tmp = q.get()

        for i in range(len(graph[tmp])):
            if not visit[i] and graph[tmp][i] > 0:
                q.put(i)
                visit[i] = True
                par[i] = tmp

    return visit[sink]

def maxflow(graph, src, sink):
    ans = 0
    par = [-1] * len(graph)

    while BFS(graph, src, sink, par):
        pathmx = inf
        tmp = sink
        while tmp != src:
            pathmx = min(pathmx, graph[par[tmp]][tmp])
            tmp = par[tmp]
        
        ans += pathmx

        tmp = sink 
        while tmp != src:
            graph[par[tmp]][tmp] -= pathmx
            graph[tmp][par[tmp]] += pathmx
            tmp = par[tmp]
    
    return ans







