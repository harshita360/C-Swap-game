#include<stdio.h>

#include<string.h>

#include<unistd.h>

#include<sys/types.h>

#include <sys/stat.h>

#include <stdlib.h>

#include<time.h>

//#include<conio.h>

#define r 3

#define c 3

char matrix[r][c],name[30];

char new[r][c];

int count1=0,count;

char final[r][c] = {{'1','2','3'},{'4','5','6'},{'7','8',' '}};

int i,j;

char z ;

int p,q,x,y;

int t =0;

int result = 0;

void load()

{

for(i=0;i<3;i++)

{

for(j=0;j<3;j++)

{

if(new[i][j] == '0')

{

matrix[i][j]= ' ';

continue;

}

matrix[i][j]= new[i][j];

}

}

}

void blank()

{

for(i=0;i<3;i++)

{

for(j=0;j<3;j++)

{

new[i][j]= ' ';

}

}

}

int main()

{
    system("color f0");

printf("*****8 PUZZLE GAME*****\n");
printf("Enter your name:\n");
scanf("%s",name);

time_t T= time(NULL);

struct tm tm = *localtime(&T);

char f[4];

int rsl,choice ;

int random,t;

int randvalues[9];

main:

count = 0;

blank();

T= time(NULL);

tm = *localtime(&T);

srand(tm.tm_sec);

while(count!=9)

{

rsl=rand()%9;

sprintf(f,"%d",rsl);

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{

if((new[i][j]) == f[0])

{

i = 4; j = 4;

continue;

}

else if((new[i][j]) == ' ')

{

new[i][j] = f[0];

i = 4; j = 4;

count++;

}

}

}

}

load();

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{
//gotoxy(40,13);
printf("|%c|",matrix[i][j]);
//getch();
}

printf("\n");

}

while(1)

{

printf("enter value to change its position to blank space\n");

scanf(" %c",&z);

if(z=='q')

{

printf("\n*****You Quit*****\n");

printf("Number of moves=%d\n",count1);

printf("do you wish to continue?(1/0)\n");

scanf("%d",&choice);

switch(choice)
{
case 0:

   goto last;

            break;

case 1:
            printf("Enter the player name:\n");

            scanf("%s",name);

            goto main;

            break;

    default: printf("Invalid choice\n");

             goto last;

             break;
}

}

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{

if((matrix[i][j])== z)

{

p = i;

q = j;

}

else if((matrix[i][j])== ' ')

{

x = i;

y = j;

}

}

}

t =0;

int m , n ;

int r1[]={-1,0,1,0};

int c1[]={0,1,0,-1};

for(i=0;i<4;i++)
{
m=p+r1[i];

n=q+c1[i];

if(m>=0&&m<r&&n>=0&&n<c)
{
if(matrix[m][n]==' ')
{

t=1;

break;

}
}
}


if(t==1)//swap

{
    count1++;

matrix[x][y] = z;

matrix[p][q] = ' ';

}

t = 0;//for next time

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{

if((matrix[i][j])== final[i][j])

{

t++;

}

}

}

system("CLS");

printf("*****8 PUZZLE GAME*****\n");

printf("%s:\n",name);

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{

printf("|%c|",matrix[i][j]);//changed matrix

}

printf("\n");

}

if(t==9)

{

printf("\n****you Win****\n");

printf("Number of moves=\n",count1);

break;

}

}

last:return 0;

}

