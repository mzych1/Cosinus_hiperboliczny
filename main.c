/*
	Projekt: Cosinus hiperboliczny, PRI- projekt 1
	Autor: Magdalena Zych
	Data: 11.2017
*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
double  x=0.0, epsilon=0.0, value=0.0;
int c;

int menu();
double cosineh( double a,  double accuracy);

int main()
{
    while(1)
    {
    menu();
    puts("Type x (in radians): ");

    while(scanf("%lf", &x)==0)  //checking if x is a number
    {
    do
    {c=getchar();} while(c!='\n'&& c!=EOF);//clearing bufor
    puts("Invalid data. Type x (in radians) again: ");
    }
    puts("Type epsilon: ");
    while(scanf("%lf", &epsilon)==0||epsilon<0.0)  //checking if epsilon is a number
    {
    do
    {c=getchar();} while(c!='\n'&& c!=EOF);//clearing bufor
    puts("Invalid data. Type epsilon again (it can not be negative): "); //
    }
    value=cosineh(x, epsilon);
    if(isnan(value))
    printf("Cosh(%f) is invinite\n", x);
    else
    printf("cosh(%.2f)=%e\n\n", x, value); //cosh calculated by function cosineh
    puts("------------------------------------\n");
    }
    return 0;
}
int menu()
{
    int decision=0;
    puts("Select one of the following:");
    puts("1-Find cosh(x)");
    puts("2-Exit");

    while((scanf("%d", &decision)!=1)||(decision!=1 && decision!=2)) //case when the decision in the menu was keyed in incorrectly
    {
    puts("Invalid data. Type 1 or 2: ");

    do
    {c=getchar();} while(c!='\n'&& c!=EOF);//clearing bufor
    }

    if(decision==2)
    exit(0);
}

 double cosineh( double a,  double accuracy)
{
     double answer=1.0;
     double element=1.0, xn=1.0;
     double n=0.0;
     double silnia=1.0;

    do
    {
        n=n+2.0;
        silnia*=n*(n-1.0);
        xn*=a*a;
        element=xn/silnia;
        //element*=a*a/n/n-1;
        answer+=element;
    }while(accuracy<element); //calculating the value of cosh(x)
    return answer;
}
