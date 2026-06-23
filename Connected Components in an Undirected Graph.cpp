// The question is in the GFG . 
https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
class Solution {
  public:
    void bfs(int i ,vector<vector<int>>& adj , vector<bool>& vis,vector<int>& ans){
        int n = adj.size() ;
        vis[i] = true ;
        queue<int>q ;
        q.push(i) ;
        while(q.size() > 0){
            int front = q.front() ;
            q.pop() ;
            for(int ele : adj[front]){
                if(!vis[ele]){
                    vis[ele] = true ;
                    ans.push_back(ele) ;
                    q.push(ele) ;
                }
            }
        }
    }
  public:
    vector<vector<int>> getComponents(int v, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(v) ;
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0] , b = edges[i][1] ;
            adj[a].push_back(b) ;
            adj[b].push_back(a) ;
        }
        int n = adj.size() ;
        vector<bool> vis(v,false) ;
        vector<vector<int>> ans ;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> ans1 ;
                ans1.push_back(i) ;
                bfs(i,adj,vis,ans1) ;
                ans.push_back(ans1) ;
            }
        }
        return ans ;
    }
};
