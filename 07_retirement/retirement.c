#include<stdio.h>
#include<stdlib.h>
struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;
double actAcount(double actual,retire_info acount,int startAge)
{
  double balance=actual;
  for(int i=0;i<acount.months;i++)
    {
      int ageYears=startAge/12;
      int ageMonth=startAge-ageYears*12;
      printf("Age %3d month %2d you have $%.2lf\n",ageYears,ageMonth,balance);
      balance=balance*(1+acount.rate_of_return/12)+acount.contribution;
      startAge=startAge+1;
    }
  return balance;
}
void retirement(int startAge,double initial,retire_info working,retire_info retired)
{
  double afterRet=actAcount(initial,working,startAge);
  int actAge=startAge+working.months;
  actAcount(afterRet,retired,actAge);
}

int main()
{
  retire_info working;
  working.months=489;
  working.contribution=1000;
  working.rate_of_return=0.045;
  retire_info retired;
  retired.months=384;
  retired.contribution=-4000;
  retired.rate_of_return=0.01;
  retirement(327,21345,working,retired);
  return 0;
}
