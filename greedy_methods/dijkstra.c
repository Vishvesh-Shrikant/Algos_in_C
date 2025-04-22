// Online C compiler to run C program online
#include <stdio.h>
#include <limits.h>
#define V 6
int graph[V][V], src; 


void printDistance (int dist[])
{
    int i = 0;
    for( i = 0 ; i < V ; i++)
    {
        printf("Distance of source %f from to destination %d : %d", src, i , dist[i]);
        printf("\n");
    }
}
int minDistance( int dist [], int visited[])
{
    int i, min=INT_MAX, min_idx; 
    for ( i=0 ; i< V; i++)
    {
        if( visited[i]==0 && dist[i]< min)
        {
            min=dist[i];
            min_idx=i;
        }
    }
    return min_idx;
}


void dijsktra()
{
    int dist[V], visited[V];
    int i, u,v;
    
    //setting all distance to infinity at the start
    //making all nodes the unvisited at the start
    for ( i=0 ; i< V; i++)
    {
        dist[V]= INT_MAX;
        visited[i]=0;
    }
    
    dist[src]= 0;
    
    for ( i = 0 ; i < V-1 ;i++)
    {
        //used to find the vertex with the smallest distance
        //initially it will start with src node , and the progress onto other nodes once visited
        u= minDistance(dist, visited);
        visited[u]=1;
        
        for (v =0 ; v < V; v++)
        {
            //this checks if : node is not visited , that dist[u] is not inifinity 
            //then  it checks if distance of u and weight of graph is lesser than current distance
            if( visited[v]==0 && graph[u][v] && dist[u]!= INT_MAX && (dist[u]+ graph[u][v] < dist[v]))
            {
                dist[v]=dist[u]+ graph[u][v];
            }
        }
    }
    
    printDistance(dist);
}


void input_graph()
{
    int u, v;
    printf("\nEnter the adjacency matrix\n");
    printf("\nNote: if there is no direct edge , enter a 1000\n");
    for (u = 0 ; u < V ; u++)
    {
        for ( v =0 ; v< V ; v++)
        {
            scanf("%d", &graph[u][v]);
            if( graph[u][v] >= 1000)
            {
                graph[u][v]= INT_MAX;
            }
        }
        printf("\n");
    }
}


int main() {
    
    input_graph();
    //to validate a proper source,which is within liimits
    do
    {
        printf("\nEnter source node: ");
        scanf("%d", &src);
        if(src >= V)
        {
            printf("\nEnter a valid source.\n");
        }
    }while ( src >= V);
    dijsktra();
    return 0;
}