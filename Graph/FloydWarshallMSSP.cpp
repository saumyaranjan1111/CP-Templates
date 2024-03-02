#define INF INT_MAX
class Solution {
    
public:
    void floydWarshall(vector<vector<long long>> &graph)
    {
        long long V = 26;
        long long i, j, k;

        for (k = 0; k < V; k++) {

            for (i = 0; i < V; i++) {

                for (j = 0; j < V; j++) {

                    if ((graph[k][j] != INF && graph[i][k] != INF) && graph[i][j] > (graph[i][k] + graph[k][j]))
                        graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    
    void printSolution(vector<vector<long long>> &graph)
    {
        long long V = 26;
        for (long long i = 0; i < V; i++) {
            for (long long j = 0; j < V; j++) {
                if (graph[i][j] == INF)
                    cout << "INF"
                         << " ";
                else
                    cout << graph[i][j] << "   ";
            }
            cout << endl;
        }
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long n = cost.size();
        
        vector<vector<long long>> graph(26, vector<long long>(26, INF));
        for(long long i = 0; i<n; i++){
            long long u = original[i] - 'a';
            long long v = changed[i] - 'a';
            long long wt = cost[i];
            
            // important
            graph[u][v] = min(graph[u][v], (long long)cost[i]);
        }
        
        for(long long i = 0; i<26; i++){
            graph[i][i] = 0;
        }
        
        // printSolution(graph);
        // cout<<endl;
        floydWarshall(graph);
        // printSolution(graph);
        // cout<<endl;
        
        long long ans = 0;
        
        for(long long i = 0; i<source.size(); i++){
            
            long long u = source[i] - 'a';
            long long v = target[i] - 'a';
            // if(u == v) continue;
            
            if(graph[u][v] != INF){
                ans += graph[u][v];
            }
            else return -1;
        }
        
        return ans;
    }
};