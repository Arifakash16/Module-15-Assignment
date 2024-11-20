
void dfs(int node, const vector<vector<int>>& tree, const vector<int>& A, int C, int good_count, int& valid_paths, vector<bool>& visited) {
    //Mark the current node as visited
    visited[node] = true;
    
    //If this node is good, increase the good node count
    if (A[node] == 1) {
        good_count++;
    }
    
    //If the good count exceeds C, stop the search along this path
    if (good_count > C) {
        visited[node] = false;
        return;
    }
    
    //Check if it is a leaf node 
    bool is_leaf = true;
    
    //Traverse all the neighbors
    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) {
            is_leaf = false;
            dfs(neighbor, tree, A, C, good_count, valid_paths, visited);
        }
    }
    
    //If it's a leaf and valid path, increment the result
    if (is_leaf) {
        valid_paths++;
    }

    //Mark the current node as unvisited before returning to parent
    visited[node] = false;
}

int countValidPaths(int N, const vector<int>& A, const vector<pair<int, int>>& B, int C) {
    //Build the adjacency list for the tree
    vector<vector<int>> tree(N);
    for (const auto& edge : B) {
        tree[edge.first - 1].push_back(edge.second - 1);
        tree[edge.second - 1].push_back(edge.first - 1);
    }

    //Initialize variables
    int valid_paths = 0;
    vector<bool> visited(N, false);
    
    //Start DFS from the root (node 1, index 0)
    dfs(0, tree, A, C, 0, valid_paths, visited);
    
    return valid_paths;
}

// Time complexity: O(N+E)   //E is the number of edges
// Space complexity: O(N+E)
