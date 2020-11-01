#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>
long int Square_and_multiply(long int x,long int c,long int n)
{
    unsigned long int z=1;
    long int e[100],k=0,i;
    while (c>0)
    {
        e[k]=(c%2);
        c=(c/2);
        k++;
    }
    for(i=k-1;i>-1;i--)
    {
        z=((z*z)%n);
        if (e[i]==1)
        {
            z=((z*x)%n);
        }
    }
    return z;
}
long int gcd(long int k,long int r)
{
if(r==0)
    {
        return k;
    }
else
    {
        return gcd(r,(k%r));
    }
}
long int Jacobi(long int a,long int n,long int b)
{
    long int p=0;
    if(gcd(a,n)>1)
    {
        return 0;
    }
    else
    {
        if(a%2==1 && a!=1)
        {
            if(a<n)
            {
                if((n%4)==3 && (a%4)==3)
                {
                    b=b*(-1);
                }
                return Jacobi(n,a,b);
            }
            else
            {
                return Jacobi((a%n),n,b);
            }
        }
        else
        {
            while(a%2==0)
            {
                a=a/2;
                p++;
            }
            if((p%2==1 && n%8==3) || (p%2==1 && n%8==5))
            {
                b=b*(-1);
            }
            if(a==1)
            {
                return b;
            }
            else
            {
                return Jacobi(a,n,b);
            }
        }
    }
    if(a==1)
        {
            return b;
        }
}
int main()
{
    long int n,b,c,d,e=0,a;
    O:printf("\n Enter your number to check it is prime or not (Solovay-Strassen method):-");
    scanf("%d",&n);

    if(n<1)
    {
        printf("It is a non positive number so it is not prime obviously.");
        goto O;
    }
if(n>65535)
    {
        printf("unsigned long int (It accepts biggest natural number among all types of variables) in C can take numbers up to +4294967295.\nwe have to calculate square of this number in a variable and square of 65536 is 4234967296 which is out of range of all variables of c. So we can't accept the number greater than 65535 to check this is prime or not.\n ");
        goto O;
    }
    if (n==1)
    {
        printf("\n we can't say about the number %d about it's primality.",n);
        return 0;
    }
    for(b=0;b<100;b++)
    {
        a=rand() % (n-1)+1;
        c=((Jacobi(a,n,1)+n)%n);
        if (c==0)
        {
            printf("\n %d is a composite number.",n);
            e=1;
            break;
        }
        d=Square_and_multiply(a,((n-1)/2),n);
        if(d!=c)
        {
            printf("\n %d is a composite number.",n);
            e=1;
            break;
        }

    }
    if(e==0)
    {
        printf("\n %d is a prime number.",n);
    }
    return 0;
}
