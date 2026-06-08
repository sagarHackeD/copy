/*BCSL404 Program 5*/

/*5.obtain the Topological ordering of vertices in a given digraph.*/

#include<stdio.h>

#include<conio.h>

int temp[10],k=0;

void sort(int a[][10],int id[],int n)

{

    int i,j;

    for(i=1; i<=n; i++)

    {

        if(id[i]==0)

        {

            id[i]=-1;

            temp[++k]=i;

            for(j=1; j<=n; j++)

            {

                if(a[i][j]==1 && id[j]!=-1)

                    id[j]--;

            }

            i=0;

        }

    }

}

void main()

{

    int a[10][10],id[10],n,i,j;

    printf("\nEnter the n value:");

    scanf("%d",&n);

    for(i=1; i<=n; i++)

        id[i]=0;

    printf("\nEnter the graph data:\n");

    for(i=1; i<=n; i++)

        for(j=1; j<=n; j++)

        {

            scanf("%d",&a[i][j]);

            if(a[i][j]==1)

                id[j]++;

        }

    sort(a,id,n);

    if(k!=n)

        printf("\nTopological ordering not possible");

    else

    {

        printf("\nTopological ordering is:");

        for(i=1; i<=k; i++)

            printf("%d ",temp[i]);

    }

    getch();

}

/*****************************************OUTPU1****************************************



Enter the n value:6



Enter the graph data:

0 0 1 1 0 0

0 0 0 1 1 0

0 0 0 1 0 1

0 0 0 0 0 1

0 0 0 0 0 1

0 0 0 0 0 0



Topological ordering is: 1 2 3 4 5 6







****************************************OUTPU2****************************************



Enter the n value:4



Enter the graph data:

1 4 3 2

5 4 2 1

5 3 4 2

4 1 2 3



Topological ordering not possible*/