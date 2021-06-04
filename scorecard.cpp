#include<stdio.h>
#include<stdlib.h>
typedef int eletype;
typedef struct cricket
{
eletype number;
eletype score;
eletype balls;
eletype fours;
eletype sixes;
cricket *next;
}cricket;

typedef struct bowling
{
eletype number;
eletype overs;
eletype runs;
eletype wickets;
eletype maidens;
bowling *next;
}bowling;

cricket* create(eletype x,eletype y,eletype b,eletype f,eletype s)
{
  cricket *temp;
  temp=(cricket *)malloc(sizeof(cricket));
  temp->number=x;
  temp->score=y;
  temp->balls=b;
  temp->fours=f;
  temp->sixes=s;
  temp->next=NULL;
  return temp;
}

int insert_end(cricket *h,eletype x,eletype y,eletype b,eletype f,eletype s){
  cricket *temp=h,*t;
  t=(cricket *)malloc(sizeof(cricket));
  t->number=x;
  t->score=y;
  t->balls=b;
  t->fours=f;
  t->sixes=s;
  t->next=NULL;
  while(temp){
    if(temp->next==NULL){
      temp->next=t;
      return 1;
    }
    else
      temp=temp->next;
  }
  return 0;
}

int display(cricket *h)
{
  cricket *temp=h;
  printf("Batting scorecard: \nNumber  Score  Balls  Fours  Sixes\n");
  while(temp)
  {
    printf("%d       ",temp->number);
    printf("%d     ",temp->score);
    printf("%d     ",temp->balls);
    printf("%d      ",temp->fours);
    printf("%d\n",temp->sixes);
    temp=temp->next;
  }
  printf("\n");
  return 0;
}
bowling* create1(eletype n,eletype o,eletype r,eletype w,eletype m)
{
  bowling *temp;
  temp=(bowling *)malloc(sizeof(bowling));
  temp->number=n;
  temp->overs=o;
  temp->runs=r;
  temp->wickets=w;
  temp->maidens=m;
  temp->next=NULL;
  return temp;
}

int insert_end(bowling *head,eletype n,eletype o,eletype r,eletype w,eletype m){
  bowling *temp=head,*t;
  t=(bowling *)malloc(sizeof(bowling));
  t->number=n;
  t->overs=o;
  t->runs=r;
  t->wickets=w;
  t->maidens=m;
  t->next=NULL;
  while(temp){
    if(temp->next==NULL){
      temp->next=t;
      return 1;
    }
    else
      temp=temp->next;
  }
  while(temp)
  	printf("%d",temp->runs);
  return 0;
}

int display1(bowling *head)
{
  bowling *temp=head;
  printf("Bowling scorecard: \nNumber  Overs  Runs  Wickets  Maidens\n");
  while(temp)
  {
    printf("%d       ",temp->number);
    printf("%d      ",temp->overs);
    printf("%d    ",temp->runs);
    printf("%d        ",temp->wickets);
    printf("%d\n",temp->maidens);
    temp=temp->next;
  }
  printf("\n");
  return 0;
}

int total(bowling *head,eletype extras)
{
bowling *temp=head;
while(temp!=NULL)
{
extras+=temp->runs;
temp=temp->next;
}
return extras;
}

int outs(bowling *head)
{
eletype wicket=0;
bowling *temp=head;
while(temp!=NULL)
{
wicket+=temp->wickets;
temp=temp->next;
}
return wicket;
}

int over(bowling *head)
{
eletype o=0;
bowling *temp=head;
while(temp!=NULL)
{
o+=temp->overs;
temp=temp->next;
}
return o;
}

int main()
{
  cricket *h;
  FILE *fp,*fp1;
  fp=fopen("Batsmen.txt","w");
  for(int i=0;i<4;i++){
    int a,b,c,d,e;
    printf("Enter the batsmen's position : \n");
    scanf("%d",&a);
    printf("Enter the batsmen's runs : \n");
    scanf("%d",&b);
    printf("Enter the batsmen's balls faced : \n");
    scanf("%d",&c);
    printf("Enter the no of fours : \n");
    scanf("%d",&d);
    printf("Enter the no of sixes : \n");
    scanf("%d",&e);
    fprintf(fp,"%d %d %d %d %d \n",a,b,c,d,e);
  }
  fclose(fp);
  fp1=fopen("Batsmen.txt","r");
  for(int i=0;i<4;i++){
    int a,b,c,d,e;
    fscanf(fp1,"%d %d %d %d %d",&a,&b,&c,&d,&e);
    if(i==0){
      h=create(a,b,c,d,e);
    }
    else
      insert_end(h,a,b,c,d,e);
    }
  fclose(fp1);
  bowling *head;
  FILE *fp2,*fp3;
  fp2=fopen("Bowler.txt","w");
  for(int i=0;i<4;i++){
    int a,b,c,d,e;
    printf("Enter the bowler's number : \n");
    scanf("%d",&a);
    printf("Enter the bowler's over : \n");
    scanf("%d",&b);
    printf("Enter the bowler's runs : \n");
    scanf("%d",&c);
    printf("Enter the wickets : \n");
    scanf("%d",&d);
    printf("Enter the maidens : \n");
    scanf("%d",&e);
    fprintf(fp2,"%d %d %d %d %d \n",a,b,c,d,e);
  }
  fclose(fp2);
  fp3=fopen("Bowler.txt","r");
  for(int i=0;i<4;i++){
    int a,b,c,d,e;
    fscanf(fp3,"%d %d %d %d %d",&a,&b,&c,&d,&e);
    if(i==0){
      head=create1(a,b,c,d,e);
    }
    else
      insert_end(head,a,b,c,d,e);
    }
  fclose(fp3);
display(h);
display1(head);
eletype extras=10;
int totalscore=total(head,extras);
int wick=outs(head);
int ove=over(head);
printf("\nOvers : %d",ove);
printf("\nExtras : %d",extras);
printf("\nTotal : %d - %d",totalscore,wick);
return 0;
}
