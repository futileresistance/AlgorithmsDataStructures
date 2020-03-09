from collections import deque

def breadth_first_search(graph, node):
    visited, queue = set(), deque([node])
    visited.add(node)
    while queue:
        next_vert = queue.pop()
        nodes = get_nodes(graph, next_vert)
        for node in nodes:
            if node not in visited:
                visited.add(node)
                queue.appendleft(node)
    return visited

def get_nodes(graph, node):
    return graph.get(node, [])