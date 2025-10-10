#include <stdio.h>
#include <stdlib.h>
void TOH(int n,char s,char d,char t)
{
    if(n>1)
    {
        TOH(n-1,s,t,d);
        printf("\n move %d disc from %c to %c",n,s,d);
        TOH(n-1,t,d,s);
    }
    else
        printf("\n move %d disc from %c to %d",n,s,d);

    }
    int main()
    {
        int n;
        printf("\n read no of discs:");
        scanf("%d",&n);
        TOH(n,'S','D','T');
        return 0;
    }
