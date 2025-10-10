#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b;
    printf("\n read for a&b:");
    scanf("%d%d",&a,&b);
    printf("\n gcd of %d and %d is %d",a,b,gcd(a,b));
    return 0;

}


