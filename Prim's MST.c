#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>
#define V 7

int minkey(int key[] , bool mstset[])
{
    int min = INT_MAX,min_index;
    for(int v=0;v<V;v++){
        if (mstset[v]==false && key[v]<min){
            min = key[v],min_index=v;
        }
    }
    return min_index;
}

int printmst(int parent[] ,int graph[V][V])
{
    int tot = 0;
    printf("Edge \t weight\n");
    for(int i=1;i<V;i++){
        printf("%d - %d \t %d \n",parent[i],i,graph[i][parent[i]]);
        tot += graph[i][parent[i]];
        
    }
    printf("\nTotal Weight of MST (Minimum Spanning Tree) : %d",tot);
}

void primmst(int graph[V][V])
{
    int parent[V];        // array to store a MST (Minimum Spanning Tree)
    int key[V];          // key values to pick min. weigth edge
    bool mstset[V];     // represents vertices that not yet included in MST (Minimum Spanning Tree)
    for(int i=0;i<V;i++)
    {
        key[i]=INT_MAX,mstset[i]=false;
    }
    key[0]=0;      // for the Source Vertex here, we take 0 as a Source Vertex
    parent[0]=-1; // first node is always root of MST
    for(int count=0;count<V-1;count++)
    {
        int u=minkey(key,mstset);
        mstset[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v]&& mstset[v]==false && graph[u][v]<key[v])
            {
                parent[v]=u,key[v]=graph[u][v];
            }
        }
    }
    printmst(parent,graph);
}

int main()
{
    int graph[V][V]={{0,28,0,0,0,10,0},
                     {28,0,16,0,0,0,0},
                     {0,16,0,12,0,0,0},
                     {0,0,12,0,22,0,18},
                     {0,0,0,22,0,25,24},
                     {10,0,0,0,25,0,0},
                     {0,0,0,18,24,0,0}};
    primmst(graph);
    return 0;
}
