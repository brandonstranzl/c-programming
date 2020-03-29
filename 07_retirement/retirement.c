#include <stdio.h>
#include <stdlib.h>


struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
  
typedef struct _retire_info retire_info;

void retirement(
		int startAge,
		double initial,
		retire_info working,
		retire_info retired) {

  for (int i = 0; i < working.months; i++) {
    //double balance = beg_bal; 
    int months = (startAge + i) % 12; 
    int years = ((startAge + i) / 12);
    printf("Age %3d month %2d you have $%.2lf\n", years, months, initial);
    initial = (initial * (1 + (working.rate_of_return / 12))) + working.contribution;
  }

   for (int i = 0; i < retired.months; i++) {
    //double balance = beg_bal; 
    int months = (startAge + working.months + i) % 12; 
    int years = ((startAge + working.months + i) / 12);
    printf("Age %3d month %2d you have $%.2lf\n", years, months, initial);
    initial = (initial * (1 + (retired.rate_of_return / 12))) + retired.contribution;
  }
}


int main(void) {

  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = .045;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = .01;
    
  int startAge = 327;
  double initial = 21345;
  
  retirement(startAge, initial, working, retired);

  //  printf("\n ** months working %d ** \n", working.months);
  //printf("\n ** years working %d ** \n", (working.months / 12));
  //printf("\n ** retirement age %d  ** \n",(working.months / 12) + (beg_age /12));
  
}
