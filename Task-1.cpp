

bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    //If the node is being visited a cycle is found
    if (visited[node] == 1)
        return true;
    
    //If the node is fully visited we skip it
    if (visited[node] == 2)
        return false;
    
    //Mark the node as visiting (in the current recursion stack)
    visited[node] = 1;
    
    //Explore all the neighbors
    for (int neighbor : graph[node]) {
        if (dfs(neighbor, graph, visited))
            return true;
    }
    
    //Mark the node as fully visited
    visited[node] = 2;
    return false;
}

int PresentCycle(int A, vector<vector<int>>& B) {
    //Create the adjacency list
    vector<vector<int>> graph(A + 1);  // Since nodes are numbered from 1 to A
    for (auto& edge : B) {
        graph[edge[0]].push_back(edge[1]);
    }
    
    //Initialize the visited states
    vector<int> visited(A + 1, 0); 
    
    //Run DFS from each node
    for (int node = 1; node <= A; node++) {
        if (visited[node] == 0) {  //If the node is not visited
            if (dfs(node, graph, visited))
                return 1;  //Cycle found
        }
    }
    
    return 0;  //No cycle found
}

// Time complexity: O(A+M)
// Space complexity: O(A+M)

