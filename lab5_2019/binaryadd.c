#include<stdio.h>
#include<string.h>
void addtion(int,int);
void subtraction(int,int);
int global=0,sglobal=0;
int main()
{
    int n,num1,num2,dum1,num[8]= {0},i,j,test=0;
    while(test!=1)
    {
        printf("\nENTER\n1)FOR ADDITION\n2)FOR SUBTRACTION\n");
        printf("YOU CHOSED : ");
        scanf("%d",&n);
        switch(n)
        {
        case 1 :
            printf("Enter the binary numbers which you want to add\n");
            printf("\nEnter the first number : ");
            scanf("%d",&num1);
            printf("\nEnter the second number : ");
            scanf("%d",&num2);
            sign(num1,num2,1);
            break;
        case 2 :
            printf("Enter the binary numbers which you want to subtract\n");
            printf("\nEnter in 8 bit format where 8th bit is sign bit");
            printf("\nEnter the first number : ");
            scanf("%d",&num1);
            printf("\nEnter the second number : ");
            scanf("%d",&num2);
            subtraction(num1,num2);
            break;
        default :
            test =1;
            printf("\nENTER A VALID OPTION\n");

        }
    }
}

void addition(int num1,int num2)
{
    int dumy1,dumy2,temp,addnum=0;
    int k,i=7,f;
    int a,b,c;
    int add[]= {0,0,0,0,0,0,0,0};

    dumy1=num1;
    dumy2=num2;
    c=0;
    while((dumy1!=0)&&(dumy2!=0)||i>0)
    {
        a=dumy1%10;
        b=dumy2%10;
        f=a+b+c;
        switch(f)
        {
        case 0 :
            add[i]=f;
            c=0;
            i=i-1;
            break;
        case 1 :
            add[i]=f;
            c=0;
            i=i-1;
            break;
        case 2 :
            add[i]=0;
            c=1;
            i=i-1;
            break;
        case 3 :
            add[i]=1;
            c=1;
            i=i-1;
            break;
        }
        dumy1=dumy1/10;
        dumy2=dumy2/10;
    }
    printf("\n");
    for(i=0; i<8; i++)
    {
        printf("%d ",add[i]);
    }

    for(i=0; i<8; i++)
    {
        addnum=addnum*10+add[i];
    }
    global=addnum;
}

void subtraction(int num1,int num)
{
    int addnum;
    addnum=compliment(num);
    addition(num1,addnum);
}

int compliment(int num)
{
    int comp[8]= {0};
    int i,j,k,dum2=num;
    int addnum;
    for(i=7; i>0; i--)
    {
        comp[i]=dum2%10;
        dum2=dum2/10;
    }

    for(k=7; k>=0; k--)
    {

        if(comp[k]==1)
        {
            break;
        }
    }
    for(j=k-1; j>-1; j--)
    {

        if(comp[j]==0)
        {
            comp[j]=1;
        }
        else
        {
            comp[j]=0;
        }
    }


    addnum=0;
    for(i=0; i<8; i++)
    {
        addnum=addnum*10+comp[i];
    }
    printf("\n2s COMPLIMENT OF THE NUMBER IS %d",addnum);
    return addnum;
}


void sign(int num1,int num2,int type)
{
    int dum1=num1,dum2=num2,i,j,k,num[8]= {0},check1=0,check2=0,numf=num1;
    if(type==1)
    {
        for(i=7; i>=0; i--)
        {
            num[i]=dum1%10;
            dum1=dum1/10;
        }
        if(num[0]==1)
        {
            num1=compliment(num1);
            check1=1;
        }
        for(i=7; i>=0; i--)
        {
            num[i]=dum2%10;
            dum2=dum2/10;
        }
        if(num[0]==1)
        {
            num2=compliment(num2);
            check2=1;
        }
        if(check1==0&&check2==0)
        {
            addition(num1,num2);
            printf("ADDITION OF NUMBERS %d +%d =%d",num1,num2,global);
        }
        else if(check1==1&&check2==0)
        {
            subtraction(num2,num1);
            printf("ADDITION OF NUMBERS %d +%d =%d",num1,num2,global);
        }
        else if(check1==0&&check2==1)
        {
            subtraction(num1,num2);
            printf("ADDITION OF NUMBERS %d +%d =%d",num1,num2,global);
        }
        else
        {
            addition(num1,num2);
            global=compliment(global);
            printf("ADDITION OF NUMBERS\n %d +%d =%d",num1,num2,global);
        }
    }
    else if(type==2)
    {
        for(i=7; i>=0; i--)
        {
            num[i]=dum1%10;
            dum1=dum1/10;
        }
        if(num[0]==1)
        {
            num1=compliment(num1);
            check1=1;
        }
        for(i=7; i>=0; i--)
        {
            num[i]=dum2%10;
            dum2=dum2/10;
        }
        if(num[0]==1)
        {
            num2=compliment(num2);
            check2=1;
        }
        if(check1==0&&check2==0)
        {
            subtraction(num1,num2);
            printf("ADDITION OF NUMBERS %d +%d =%d",num1,num2,global);
        }
        else if(check1==1&&check2==0)
        {
            addition(num2,num1);
            printf("ADDITION OF NUMBERS %d +%d =%d",num1,num2,global);
        }
        else if(check1==0&&check2==1)
        {
            addition(num1,num2);
            printf("ADDITION OF NUMBERS %d +%d =%d",num1,num2,global);
        }
        else
        {
            subtraction(num1,num2);
            global=compliment(global);
            printf("ADDITION OF NUMBERS\n %d +%d =%d",num1,num2,global);
        }
    }

}
