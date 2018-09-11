#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include<iostream>
using namespace std;
struct Edge
{
    int src, dest;
    float weight;
};
struct point{

int x1;
int y1;
};
struct Graph
{
    int V, E;
    struct Edge* edge;
};

struct point p[100];
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 //for sorting
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

//MSt
void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

   //sort out
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1)
    {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
setcolor(GREEN);
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
    {
        line(p[result[i].src].x1,p[result[i].src].y1,p[result[i].dest].x1,p[result[i].dest].y1);
        delay(1000);
        printf("%d -- %d == %f\n", result[i].src, result[i].dest,
                                                   result[i].weight);
    }
    return;
}

int main()
{
    int x, y;

    initwindow(750, 800);

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
 //   outtextxy(20, 20, "Click the point you want in the graph.");

    setcolor(BROWN);
    int g=0,h,w;
    circle(400,400,25);
    while(1){
        while (!ismouseclick(WM_LBUTTONDOWN))

            {
            delay(30);
            }
    getmouseclick(WM_LBUTTONDOWN, x, y);
    if(((x-400)*(x-400)+(y-400)*(y-400))<=2500) {break;}
    setcolor(WHITE);
    circle(x,y,5);
   p[g].x1=x;
   p[g].y1=y;
   g++;
    }
    int V = g;
    int E = g*(g-1)/2;
    struct Graph* graph = createGraph(V, E);
int q1=0;
for (h=0;h<g;h++){
        for(w=h+1;w<g;w++)
        {setcolor(RED),line(p[h].x1,p[h].y1,p[w].x1,p[w].y1);
        graph->edge[q1].src = h;
    graph->edge[q1].dest = w;
    graph->edge[q1].weight = (abs(p[h].x1-p[w].x1)+abs(p[h].y1-p[w].y1))/float(100);
    q1++;}
    cout << "The mouse was clicked at: "<< h<<"  ";

    cout << "x=" << p[h].x1<<"  ";

    cout << " y=" << p[h].y1 << endl;

}
    KruskalMST(graph);
getch();
    closegraph( );
    return 0;
}

