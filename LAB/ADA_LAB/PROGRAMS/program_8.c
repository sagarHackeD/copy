/*BCSL404 Program 8*/

/*8.find a subset of a given set S = {s1 , s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d.*/

#include<stdio.h>

#define MAX 10

int s[MAX],x[MAX],d;

void sumofsub(int p,int k,int r)

{

    int i;

    x[k]=1;

    if((p+s[k])==d)

    {

        for(i=1; i<=k; i++)

            if(x[i]==1)

                printf("%d ",s[i]);

        printf("\n");

    }

    else if(p+s[k]+s[k+1]<=d)

        sumofsub(p+s[k],k+1,r

                 -s[k]);

    if((p+r

            -s[k]>=d) && (p+s[k+1]<=d))

    {

        x[k]=0;

        sumofsub(p,k+1,r

                 -s[k]);

    }

}

int main()

{

    int i,n,sum=0;

    printf("\nEnter the n value:");

    scanf("%d",&n);

    printf("\nEnter the set in increasing order:");

    for(i=1; i<=n; i++)

        scanf("%d",&s[i]);

    printf("\nEnter the max subset value:");

    scanf("%d",&d);

    for(i=1; i<=n; i++)

        sum=sum+s[i];

    if(sum<d || s[1]>d)

        printf("\nNo subset possible");

    else

        sumofsub(0,1,sum);

    return 0;

}

/*Enter the n value:9



Enter the set in increasing order:1 2 3 4 5 6 7 8 9



Enter the max subset value:9

1 2 6

1 3 5

1 8

2 3 4

2 7

3 6

4 5

9*/