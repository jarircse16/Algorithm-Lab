#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define mt          make_tuple
#define PII         pair<ll, ll>
#define pi          pair<int, int>
#define fast_io     ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define loop_in     for(int i=0; i<n; i++)
#define INF         1000000000
#define SIZE        105

int nodes, edges, d[1000], step=0;
vector <int> vec[SIZE], cost[SIZE];
priority_queue <pi, vector<pi>, greater<pi> > pq;


void dijkstra(int root)
{
    int u;
    pi x;
    d[root] = 0;
    pq.push(mp(d[root], root));
    while(!pq.empty())
    {
        x = pq.top();
        u = x.second;
        for(int i=0; i<vec[u].size(); i++)
        {
            int v = vec[u][i];
            if((d[u] + cost[u][i])<(d[v]))
            {
                step++;
                d[v] = d[u] + cost[u][i];
                pq.push(mp(d[v], v));
            }
        }
        pq.pop();
    }
}

int main()
{
    fast_io

    ifstream fin;
    fin.open("city-map.txt");
    //ofstream fout("Output.txt");

    int i, j, w, t, tc=1;
    fin>>t;
    while(t--)
    {
        for(i=0; i<SIZE; i++)
        {
            vec[i].clear();
            cost[i].clear();
        }
        while (!pq.empty())
        {
            pq.pop();
        }
        for(i=0; i<nodes+5; i++)
        {
            d[i] = INF;
        }

        fin>>nodes;
        for(i=1; i<=nodes; i++)
        {
            for(j=1; j<=nodes; j++)
            {
                fin>>w;
                if(w)
                {
                    vec[i].pb(j);
                    cost[i].pb(w);
                }
            }
        }
        printf("Test Case: %d\n\n", tc);
        tc++;
        printf("Following is the adjacency list with cost of the given cost matrix: \n");
        for(i=1; i<=nodes; i++)
        {
            printf("%d --> ", i);
            for(j=0; j<vec[i].size(); j++)
            {
                printf("%d(%d)\t", vec[i][j], cost[i][j]);
            }
            cout<<endl;
        }
        step = 0;
        dijkstra(1);
        for(i=1; i<=nodes; i++)
        {
            if(d[i]>=INF)
            {
                printf("d[%d] = Infinity\n");
                continue;
            }
            printf("d[%d] = %d\n", i, d[i]);
        }
        printf("Number of step count for %d nodes: %d", nodes, step);
        cout<<endl<<endl<<endl;
    }
}
