//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    
    if(A[0][0] == 0 || A[X][Y] == 0) return -1;
    queue<pair<int,int>> q;
    q.push({0,0});
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,-1,1};
    vector<vector<int>> dist(N,vector<int>(M,-1));
    dist[0][0] = 0;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if(x>=0 && x<N && y>=0 && y<M && A[x][y] == 1 && dist[x][y] == -1){
                dist[x][y] = dist[p.first][p.second] + 1;
                q.push({x,y});
            }
        }
    }
    return dist[X][Y];
}
int main(){
    int N,M,X,Y;
    cin>>N>>M;
    vector<vector<int>> A(N,vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }
    cin>>X>>Y;
    cout<<shortestDistance(N,M,A,X,Y);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends