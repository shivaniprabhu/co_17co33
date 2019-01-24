//octal to binary and binary to octal
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long convertOctalToBinary(int octalNumber);
int convertBinarytoOctal(long long binaryNumber);
int main()
{
    int p,n;
    char hex[20];
    long long binaryNumber;
    int octalNumber;
    while(1){
    printf("\nPress 1 to convert binary to octal\n");
    printf("\nPress 2 to convert octal to binary\n");
    printf("\nPress 3 to convert binary to hexadecimal\n");
    printf("\nPress 4 to convert hexadecimal to binary\n");
    printf("\nPress 5 to exit\n");
    printf("\nEnter your choice");
    scanf("%d",&p);
    switch(p)
    {
        case 1:
                printf("Enter a binary number: ");
                scanf("%lld", &binaryNumber);
                printf("%lld in binary = %d in octal", binaryNumber, convertBinarytoOctal(binaryNumber));
                break;
        case 2:
                printf("Enter an octal number: ");
                scanf("%d", &octalNumber);
                printf("%d in octal = %lld in binary", octalNumber, convertOctalToBinary(octalNumber));
                break;
        case 3:
                printf("Enter binary number: ");
                scanf("%d",&n);
                binary_hex(n,hex);
                printf("Hexadecimal number: %s",hex);
                break;
        case 4:
                printf("Enter hexadecimal number: ");
                scanf("%s",hex);
                printf("Binary number: %d",hex_binary(hex));
                break;
        case 5: exit(1);

        default: printf("\nEnter proper choice");
    }
}
    return 0;
}
long long convertOctalToBinary(int octalNumber)
{
    int decimalNumber = 0, i = 0;
    long long binaryNumber = 0;

    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }

    return binaryNumber;
}

int convertBinarytoOctal(long long binaryNumber)
{
    int octalNumber = 0, decimalNumber = 0, i = 0;

    while(binaryNumber != 0)
    {
        decimalNumber += (binaryNumber%10) * pow(2,i);
        ++i;
        binaryNumber/=10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}
void binary_hex(int n, char hex[]) /* Function to convert binary to hexadecimal. */
{
    int i=0,decimal=0, rem;
    while (n!=0)
    {
        decimal += (n%10)*pow(2,i);
        n/=10;
        ++i;
    }

/* At this point, variable decimal contains binary number in decimal format. */
    i=0;
    while (decimal!=0)
    {
        rem=decimal%16;
        switch(rem)
        {
            case 10:
              hex[i]='A';
              break;
            case 11:
              hex[i]='B';
              break;
            case 12:
              hex[i]='C';
              break;
            case 13:
              hex[i]='D';
              break;
            case 14:
              hex[i]='E';
              break;
            case 15:
              hex[i]='F';
              break;
            default:
              hex[i]=rem+'0';
              break;
        }
        ++i;
        decimal/=16;
    }
    hex[i]='\0';

}

int hex_binary(char hex[])
{
    int i, length, decimal=0, binary=0;
    for(length=0; hex[length]!='\0'; ++length)
    for(i=0; hex[i]!='\0'; ++i, --length)
    {
        if(hex[i]>='0' && hex[i]<='9')
            decimal+=(hex[i]-'0')*pow(16,length-1);
        if(hex[i]>='A' && hex[i]<='F')
            decimal+=(hex[i]-55)*pow(16,length-1);
        if(hex[i]>='a' && hex[i]<='f')
            decimal+=(hex[i]-87)*pow(16,length-1);
    }


    i=1;
    while (decimal!=0)
    {
        binary+=(decimal%2)*i;
        decimal/=2;
        i*=10;
    }
    return binary;
}

