#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>

typedef struct node{
	int x;
	int y;
	struct node*next;
}snake;
snake *head;
int food_x,food_y;
int condition;
int score = 0; 
char m;//按键 

enum {U=1,D,L,R};

int status = R; 

void welcome ();
void Pos ();   //光标定位函数 需要掌握 
void background ();
void mysnake ();
void snakemovinig ();
void direction ();
void T_direction();
void producefood ();
void  bite_self ();
void crosswall ();
void showscore ();
void pause ();//这个函数有待研究 
 



int main ()
{
	welcome ();
	background ();
   	mysnake ();
   	producefood ();
   	showscore ();
    snakemoving ();
    	
	return 0;
}

void welcome ()
{
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t欢迎来到财财的贪吃蛇游戏!"); 
	printf("\n\n\n\n\n");
	printf("\t\t\t\t   “W S A D”分别控制蛇的上下左右哦!"); 
	printf("\n\n\n\n\n\n\n");
	system ("pause");
	system ("cls");
}

void Pos (int x,int y)
{
	COORD pos;
	pos.X = x ;
	pos.Y = y ;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void background ()
{
	int i ,j;
	for (i=0;i <= 52;i=i + 2)
	   for (j=0;j < 23;j++)
	      {
	      	Pos (i,0); 
	      	printf ("■");
	      	Pos (i,23);
	      	printf ("■");
	      	Pos (0,j);
	      	printf ("■");
	      	Pos (52,j);
	      	printf("■");
		  }
	printf("\n\n\n");
}

void mysnake ()
{
	int i;
	snake *body;
	head = (snake*)malloc(sizeof(snake));
    srand(time(NULL));	
    head->x = (rand () % 23)*2
	 + 2;
    head->y = rand () % 21 + 2;
    head->next = NULL; 
    for (i=1;i < 3;i++)
    {
    	body = (snake*)malloc(sizeof(snake));
    	(*body).x = (*head).x + 2;
		(*body).y = (*head).y;
		(*body).next = head;
		head = body ; 
	}
	while (body)
	{
		Pos (body->x ,body->y );
		printf("■");
		body = body->next ;
	}
    
}

void snakemoving ()
{
    while (1)
    {

		T_direction();
		direction ();
		Pos (92,12);
		printf ("%d",score);
		bite_self ();
		crosswall();
		
		if (condition == 1)
		{
			system ("cls");
			Pos (40,10);
			printf ("亲，您咬到自己了哦~您的最后得分为：%d\n\n\n\n\n\n\n",score);
			break;
		}
		if (condition == 2)
		{
			system ("cls");
			Pos (40,10);
			printf ("亲，您撞到墙了哦~您的最后得分为：%d\n\n\n\n\n\n\n\n\n",score);
			break;
		}
		
		Sleep(500);
    }
}

void direction()
{
	snake *p;
	snake *newhead;
	newhead = (snake*)malloc(sizeof(snake));
	
    if (status == U)
	{
		if(head->x==food_x&&head->y==food_y)
        {
            score = score + 10; 
            newhead->x=head->x;
            newhead->y=head->y-1;
            newhead->next=head;
            head=newhead;
            p=head;
            while(p)
            {
                Pos(p->x,p->y);
                printf("■");
                p=p->next;
            }
            producefood(); 
           
       }
        else
		{
		
			newhead ->x = head ->x;
			newhead ->y = head ->y - 1;
			newhead ->next = head;
			head = newhead;
			p= head ;
			while (p->next->next)
			{
				Pos (p->x ,p->y );
				printf ("■");
				p = p->next;
			}
			Pos (p->x ,p->y );
			printf ("■");
			Pos (p->next->x,p->next->y) ;
			printf ("  ");
			free (p->next);
			p -> next = NULL;
		}
   }
   if (status == D)
   {
   	   if(head->x==food_x&&head->y==food_y)
        {
        	score = score + 10;
            newhead->x=head->x;
            newhead->y=head->y+1;
            newhead->next=head;
            head=newhead;
            p=head;
            while(p)
            {
                Pos(p->x,p->y);
                printf("■");
                p=p->next;
            }
            producefood(); 
        }
        else
        {
	   	  
	   	    newhead->x = head->x ;
			newhead->y = head->y + 1;
			newhead->next = head;
			head = newhead;
			p = head;
			while (p->next->next)
			{
				Pos (p->x ,p->y );
				printf ("■");
				p = p->next;
			}
			Pos (p->x ,p->y );
			printf("■");
			Pos (p->next->x,p->next->y);
			printf("  ");
			free (p->next);
			p->next = NULL; 
		}
   }
   if (status == R)
   {
   	    if(head->x==food_x&&head->y==food_y)
        {
        	score = score + 10;
            newhead->x=head->x+2;
            newhead->y=head->y;
            newhead->next=head;
            head=newhead;
            p=head;
            while(p)
            {
                Pos(p->x,p->y);
                printf("■");
                p=p->next;
            }
            producefood(); 
        }
        else
        {
	   
	   	    newhead->x  = head -> x +2;
	   	    newhead->y  = head -> y;
	   	    newhead -> next = head;
			head = newhead ;
			p = head;
			while (p->next->next)
			{
				Pos (p->x ,p->y );
				printf("■");
				p = p->next;
			} 
		    Pos (p->x,p->y);
		    printf("■");
		    Pos (p->next->x,p->next->y);
		    printf("  ");
		    free (p->next);
		    p->next = NULL;
		}
   }
   if (status == L)
   {
   	    if(head->x==food_x&&head->y==food_y)
        {
        	score = score + 10;
            newhead->x=head->x-2;
            newhead->y=head->y;
            newhead->next=head;
            head=newhead;
            p=head;
            while(p)
            {
                Pos(p->x,p->y);
                printf("■");
                p=p->next;
            }
            producefood(); 
        }
        else
        {
	   	 
	   	    newhead ->x = head ->x - 2;
	   	    newhead ->y = head ->y;
	   	    newhead ->next = head;
	   	    head = newhead;
	   	    p = head ;
	   	    while (p->next->next)
	   	    {
	   	    	Pos (p->x ,p->y );
	   	    	printf("■");
	   	    	p = p->next;
		    }
		    Pos (p->x ,p->y );
		    printf("■");
		    Pos (p->next->x,p->next->y);
			printf("  ");
			free (p->next);
			p ->next = NULL; 
		}
   }
   
 } 
 
 void T_direction()
 {
 	
 	if (kbhit())   //如果不按就不执行 需要掌握 头文件 <conio.h> 
 	m = getch ();
 	switch (m)
 	{
 		case 'W' : if (status != D)  status = U;  break;
 		case 'S' : if (status != U)  status = D;  break;
 		case 'A' : if (status != R)  status = L;  break;
 		case 'D' : if (status != L)  status = R;  break;
 		case ' ' : pause();                       break;
 		default  : break ;
	}
 }
 
 void producefood ()
 {
 
 	bool aflag = true;
 	srand (time(NULL));
 	while (1)
 	{
	 	food_x = (rand ()% 24)*2+ 2;
	 	food_y = rand ()% 21 + 1;
	 	
	 	if ((food_x==head->x &&food_y==head->y )||(food_x==head->next->x&&food_y==head->next->y )
		    ||(food_x==head->next->next->x&&food_y==head->next->next->y))
	    {
	    	bool aflag = false;
	    	continue ;
		}
		if (aflag == true)
		break;
    }
 	Pos (food_x,food_y);
 	printf("■");
 	
 }
 
void bite_self ()
 {
 	snake *p;
 	p = head->next;
 	while(p)
    {
		if (p->x ==head->x &&p->y ==head->y )
	 	{
	        condition = 1;
	        break;
	    }
	    p = p -> next;
	}
 }
 
void crosswall ()
 {
 	if (head->x<=1||head->x >=52||head->y==0||head->y>=23)
 	{
 		condition = 2;
    }
 }
void showscore ()
{
	Pos (60,6);
	printf ("问世间情为何物？");
	Pos (60,8);
	printf ("直叫人生死相许。\n");
	Pos (79,6);
	printf("苟利国家生死以，\n");
	Pos (79,8);
	printf("岂因祸福避趋之？\n") ;
	Pos (60,12);
	printf("在这场惨烈的角逐中，你的分数是: %d\n",score);
//	Pos (92,12);
//	printf("2"); 
}
void pause ()
{ 
	while (1)
	{
	    if (m=getch()==' ')
		break;
	}
}

