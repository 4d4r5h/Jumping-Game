#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<dos.h>
#include<stdio.h>
int j=61,z=random(61)+20,n=1,t=0,score=0;
char name[100];
void ground()
{
textcolor(RED);
for(int i=1;i<80;i++)
{
gotoxy(i,22);
cprintf("~");
}
}
void scorecard()
{
gotoxy(33,3);
cout<<"SCORE : "<<score;
if(n==4)
{
gotoxy(28,5);
cout<<"NOW FACE TWO OBSTACLES.";
}
else if(n==6)
{
gotoxy(28,5);
cout<<"SPEED HAS BEEN INCREASED.";
}
else if(n==9)
{
gotoxy(24,5);
cout<<"SPEED HAS BEEN INCREASED FURTHER.";
}
}
void obstacle1()
{
if(z==0)
{
for(int a=18;a<22;a++)
{
gotoxy(1,a);
cout<<" ";
}
z=random(61)+20;
}
if(z==3)
{
score+=20;
n++;
scorecard();
}
for(int i=18;i<22;i++)
{
if(z!=4)
{
gotoxy((z+1),i);
cout<<" ";
}
gotoxy(z,i);
cout<<"|";
}
z--;
}
void obstacle()
{
if(j==0)
{
for(int a=18;a<22;a++)
{
gotoxy(1,a);
cout<<" ";
}
j=random(61)+20;
}
if(j==3)
{
score+=20;
n++;
scorecard();
if(n==6)
t=30;
else if(n==9)
t=60;
}
for(int i=18;i<22;i++)
{
if(j!=4)
{
gotoxy((j+1),i);
cout<<" ";
}
gotoxy(j,i);
cout<<"|";
}
delay(140-t);
j--;
}
void runner()
{
textcolor(BLUE);
char ch;
while(1)
{
while(!kbhit())
{
for(int i=18;i<22;i++)
{
gotoxy(5,i);
cprintf("#");
}
if(n<=3)
obstacle();
else
{
obstacle1();
obstacle();
}
if(j==4||z==4)
{
sound(420);
sleep(1);
nosound();
clrscr();
gotoxy(35,13);
cout<<"GAME OVER ";
gotoxy(23,14);
cprintf("Name : %s           Score : %d",name,score);
getch();
exit(0);
}
}
sound(420);
ch=getch();
if(ch=='j'||ch=='J')
{
for(int i=14;i<18;i++)
{
gotoxy(5,i);
cprintf("#");
gotoxy(5,i+4);
cout<<" ";
}
}
else
exit(0);
if(n<=3)
obstacle();
else
{
obstacle1();
obstacle();
}
nosound();
for(int i=18;i<22;i++)
{
gotoxy(5,i);
cprintf("#");
gotoxy(5,i-4);
cout<<" ";
}
}
}
void main()
{
clrscr();
_setcursortype(_NOCURSOR);
cout<<"Enter your name : ______________\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
gets(name);
cout<<"\n\n-> USE J/j TO JUMP.\n";
cout<<"\n\n-> PRESS ANY OTHER KEY TO TERMINATE.\n";
getch();
randomize();
clrscr();
scorecard();
ground();
runner();
}