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
int minKey(float key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < sizeof(key); v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}
void printMST(int parent[], int g, float graph[][100])
{
    setcolor(GREEN);
   printf("Edge   Weight\n");
   for (int i = 1; i < g; i++)
   {line(p[parent[i]].x1,p[parent[i]].y1,p[i].x1,p[i].y1);
        delay(1000);
      printf("%d - %d    %f \n", parent[i], i, graph[i][parent[i]]);}
}
void primMST(float graph[][100],int g)
{
     int parent[g];
     float key[g];
     bool mstSet[g];
     for (int i = 0; i < g; i++)
        key[i] = INT_MAX, mstSet[i] = false;

     key[0] = 0.0;
     parent[0] = -1;
     for (int count = 0; count < g-1; count++)
     {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < g; v++)
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     printMST(parent, g, graph);
}
int main()
{
    int x, y;

    initwindow(750, 800);

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    //outtextxy(20, 20, "Click the point you want in the graph.");

    setcolor(BROWN);
    int g=0,h,w;
    circle(400,400,20);
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
    int q1=0,k1,k2;
float gr[100][100];
for(k1=0;k1<g;k1++)
{
    for(k2=0;k2<g;k2++){
        gr[k1][k2]=0.0;
    }

}

for (h=0;h<g;h++){
        for(w=h+1;w<g;w++)
        {setcolor(RED),line(p[h].x1,p[h].y1,p[w].x1,p[w].y1);
        graph->edge[q1].src = h;
    graph->edge[q1].dest = w;
    graph->edge[q1].weight = (abs(p[h].x1-p[w].x1)+abs(p[h].y1-p[w].y1))/float(100);
    gr[h][w]=graph->edge[q1].weight;
    q1++;}
    cout << "The mouse was clicked at: "<< h<<"  ";

    cout << "x=" << p[h].x1<<"  ";

    cout << " y=" << p[h].y1 << endl;

}
for(k1=0;k1<g;k1++)
{
    for(k2=0;k2<g;k2++){
            if(gr[k2][k1]!=0.0)
        gr[k1][k2]=gr[k2][k1];
    else if(k1==k2)
        gr[k1][k2]=0.0;
    }
}
    primMST(gr,g);
getch();
    closegraph( );
    return 0;
}

