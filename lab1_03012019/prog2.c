//binary to decimal and decimal to binary
#include <stdio.h>
#include <math.h>
int binary_decimal(int n);
int decimal_binary(int n);
int main()
{
   int n,choice;
   char c;
 do
 {
   printf("Enter 1 for printing decimal number\n");
   printf("Enter 2 for printing binary number\n");
   printf("Enter 3 to exit\n");
   printf("Enter your choice\n");
   scanf("%d",&choice);
   switch(choice)
   {
     case 1: printf("\nEnter a binary number: ");
             scanf("%d", &n);
             printf("%d in binary = %d in decimal\n", n, binary_decimal(n));
             break;
     case 2:  printf("\nEnter a decimal number: ");
             scanf("%d", &n);
             printf("%d in decimal = %d in binary\n", n, decimal_binary(n));
             break;
     case 3: exit(0);
     default:  printf("\nEnter proper choice ");
    }
}while(choice!=4);
}

int decimal_binary(int n)
{
    int rem, i=1, binary=0;
    while (n!=0)
    {
        rem=n%2;
        n=n/2;
        binary=binary+rem*i;
        i=i*10;
    }
    return binary;
}

int binary_decimal(int n)

{
    int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n=n/10;
        decimal=decimal+rem*pow(2,i);
        ++i;
    }
    return decimal;
}
