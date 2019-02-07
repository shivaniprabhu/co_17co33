#include <stdio.h>
#define SIZE
int main()
{
  char binary1[SIZE + 1], binary2[SIZE+1], onesComp[SIZE + 1], twosComp[SIZE + 1];
  char binAdd, binSub;
    printf("Enter the %d value: "SIZE);
    gets(binary1);
    printf("Enter the second %d value: "SIZE);
    gets(binary2);
    binAdd=binAddition(binary1,binary2);
    binSub=binSubtracton(binary1,binary2);
    printf("Binary Addition: %d\n",binAdd);
    printf("Binary Subtraction: %d\n",binSub);
    return 0;
}
char binAddition(char a,char b)
{
    char onesComp[SIZE + 1], twosComp[SIZE + 1],binary1[SIZE + 1], binary2[SIZE+1];
     int c,i;
     while (b!= 0)
     {
       c=(a & b)<<1;
       a=a^b;
       b=c;
     }
    for(i=0; i<SIZE; i++)
    {
        if(binary1[i]||binary2[i] == '1')
        {
            onesComp[i] = '0';
        }
        else if(binary1[i]||binary2[i] == '0')
        {
            onesComp[i] = '1';
        }
    }
    onesComp[SIZE] = '\0';

    for(i=SIZE-1; i>=0; i--)
    {
        if(onesComp[i] == '1' && c == 1)
        {
            twosComp[i] = '0';
        }
        else if(onesComp[i] == '0' && c == 1)
        {
            twosComp[i] = '1';
            c = 0;
        }
        else
        {
            twosComp[i] = onesComp[i];
        }
    }
    twosComp[SIZE] = '\0';
   return a;
}

int binSubtracton(char a, char b)
{
    char onesComp[SIZE + 1], twosComp[SIZE + 1],binary1[SIZE + 1], binary2[SIZE+1];
    int carry,i;
    b = binAddition(~b, 1);
    while (b!=0)
    {
       carry = (a&b)<<1;
        a = a^b;
        b = carry;
    }
    for(i=0; i<SIZE; i++)
    {
        if(binary1[i]||binary2[i]  == '1')
        {
            onesComp[i] = '0';
        }
        else if(binary1[i]||binary2[i] == '0')
        {
            onesComp[i] = '1';
        }
    }
    onesComp[SIZE] = '\0';

    for(i=SIZE-1; i>=0; i--)
    {
        if(onesComp[i] == '1' && carry == 1)
        {
            twosComp[i] = '0';
        }
        else if(onesComp[i] == '0' && carry == 1)
        {
            twosComp[i] = '1';
            carry = 0;
        }
        else
        {
            twosComp[i] = onesComp[i];
        }
    }
    twosComp[SIZE] = '\0';
  return a;
}

