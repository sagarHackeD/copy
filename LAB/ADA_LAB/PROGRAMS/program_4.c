
*BCSL404 Program 4*/

/*4.find shortest paths from a given vertex in a weighted connected graph to other vertices using Dijkstra's algorithm.*/

#include<stdio.h>

#define INF 999

void dijkstra(int c[10][10],int n,int s,int d[10])

{

    int v[10],min,u,i,j;

    for(i=1; i<=n; i++)

    {

        d[i]=c[s][i];

        v[i]=0;

    }

    v[s]=1;

    for(i=1; i<=n; i++)

    {

        min=INF;

        for(j=1; j<=n; j++)

            if(v[j]==0 && d[j]<min)

            {

                min=d[j];

                u=j;

            }

        v[u]=1;

        for(j=1; j<=n; j++)

            if(v[j]==0 && (d[u]+c[u][j])<d[j])

                d[j]=d[u]+c[u][j];

    }

}

int main()

{

    int c[10][10],d[10],i,j,s,sum,n;

    printf("\nEnter n value:");

    scanf("%d",&n);

    printf("\nEnter the graph data:\n");

    for(i=1; i<=n; i++)

        for(j=1; j<=n; j++)

            scanf("%d",&c[i][j]);

    printf("\nEnter the souce node:");

    scanf("%d",&s);

    dijkstra(c,n,s,d);

    for(i=1; i<=n; i++)

        printf("\nShortest distance from %d to %d is %d",s,i,d[i]);

    return 0;

}

/*Enter n value:4



Enter the graph data:

444  767 987 12

999  87  56  45

1    0   999 678

444  678 235 0



Enter the souce node:1



Shortest distance from 1 to 1 is 444

Shortest distance from 1 to 2 is 247

Shortest distance from 1 to 3 is 247

Shortest distance from 1 to 4 is 12*/