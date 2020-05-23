#include<stdio.h>
#include<string.h>
static int count=0;
struct gift
{
 int cus_id;
 float balance;
 int pin;
 int gift_id;
 
}s[3];
struct gc
{
 int gift_id;
 int pin;
 char status[10];
 int id;
int amt;
}gf[10];
int main()
{
  int i,n,x=10000;
 // static int count=0;
  for(i=0;i<3;i++)
  {
   s[i].cus_id=(i+1);
   s[i].balance=x;
  x=x+10000;
  }
  while(1)
  {
  printf("1.display,2.create_gift,3.topup,4.close_gift card,5.display_gift_card\n");
  scanf("%d",&n);
  switch(n)
  {
   case 1:display(s,3);
          break;         
   case 2:create_gift_card(s,3,gf,10);
          break; 
   case 3:topup(s,3,gf,10);
          break;     
   case 4:close_gift(s,3,gf,10);
          break;  
   case 5:dis(s,3,gf,10);
          break;                          
  }
 }
}
void display(struct gift s[],int n)
 {
   int i;
   printf("_________________________________\n");
   printf("cus_id\tbalance\n");
   printf("_________________________________\n");
   for(i=0;i<n;i++)
   {
    printf("%d\t%f\n",s[i].cus_id,s[i].balance);
   }
 }
void create_gift_card(struct gift s[],int n,struct gc gf[],int a)
{
  int i,m,k;
  static int j=0;
  printf("enter customer_id\n");
  scanf("%d",&m);
  for(i=0;i<n;i++)
  {
   if(s[i].cus_id==m) 
   {
    printf("enter gift_card_no.\n");
    scanf("%d",&gf[j].gift_id);
    printf("enter pin no.\n");
    scanf("%d",&gf[j].pin);
    strcpy(gf[j].status,"active");
    printf("enter gift card amount\n");
    scanf("%d",&gf[j].amt);
    s[i].balance=s[i].balance-gf[j].amt;
    gf[j].id=s[i].cus_id;
     count++;
     j++;
    }
  }
}
void topup(struct gift s[],int n,struct gc gf[],int a)
{
  int i,tamt,m,k;
  printf("enter gift_card_no\n");
  scanf("%d",&m);
  printf("enter topup amount\n");
  scanf("%d",&tamt);
  for(i=0;i<count;i++)
  {
   if(gf[i].gift_id==m)
   {
     gf[i].amt=gf[i].amt+tamt;
     for(k=0;k<n;k++)
     {
     if(gf[i].id==s[k].cus_id)
      {
        s[k].balance=s[k].balance-tamt;
      }
     }
   }
  } 
}
void close_gift(struct gift s[],int n,struct gc gf[],int a)
{
  int m,cpin,k,i;
  printf("enter gift card no.\n");
  scanf("%d",&m);
  printf("enter pin no.\n");
  scanf("%d",&cpin);
  for(i=0;i<count;i++)
  {
    if(gf[i].gift_id==m && gf[i].pin==cpin)
    {
      for(k=0;k<n;k++)
      {
        if(gf[i].id==s[k].cus_id)
        {
          s[k].balance=s[k].balance+gf[i].amt;
          strcpy(gf[i].status,"inactive");
        }
      }
    }
  }
}
 void dis(struct gift s[],int n,struct gc gf[],int a)
{
 int k;
 printf("card_no\tcus_id\tpin\tamount\tstatus\n");
 printf("-----------------------------------------------------\n");
  for(k=0;k<count;k++)
  {
    printf("%d\t%d\t%d\t%d\t%s\n",gf[k].gift_id,gf[k].id,gf[k].pin,gf[k].amt,gf[k].status);

    printf("-----------------------------------------------------\n");
  }
}

void pur_item(struct gift s[],int n,struct gc gf[],int a)
{
  int m,ppin;
  printf("Enter card NO.\n");
  scanf("%d",&m);
  printf("enter pin no.\n");
  scanf("%d",&ppin);
  for(i=0;i<count;i++)
  {
    if(gf[i].gift_id==m && gf[i].pin==ppin)
    {
      for(k=0;k<n;k++)
      {
        if(gf[i].id==s[k].cus_id)
        {
          s[k].balance=s[k].balance+gf[i].amt;
          strcpy(gf[i].status,"inactive");
        }
      }
    }
  }
  
}
