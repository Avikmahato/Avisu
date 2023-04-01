/*Find Largest And Second Largest Using C:*/

#include<stdio.h>
#include<stdlib.h>

int main()
{

    int i,a[100],n,max,smax;
    printf("Enter How Many Do You Want To Compare:");
    scanf("%d",&n);
    
    for(i=0; i<n; i++)
    {
        printf("Enter [%d] Number:",i+1);
        scanf("%d",&a[i]);
    }
    max=smax=a[0];
    system("cls");
    for(i=0; i<n; i++)
    {
        if(a[i]>max)
        {
            smax=max;
            max=a[i];
        }

        if(smax<a[i] && a[i]<max)
        {
            smax=a[i];
        }
    }

    printf("The Largest Number Is         : %d\n\n",max);
    printf("The Second Largest Number Is  : %d",smax);
    return 0;
}