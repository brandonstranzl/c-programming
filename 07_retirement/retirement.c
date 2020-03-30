#include <stdio.h>
#include <stdlib.h>


struct retire_info_t {
  int months;
  double contribution;
  double rate;
};
  
typedef struct retire_info_t retire_info;

void print_balance(
		int beg_age,
		double  beg_bal,
		retire_info working,
		retire_info retirement) {

  for (int i = 0; i < working.months; i++) {
    //double balance = beg_bal; 
    int months = (beg_age + i) % 12; 
    int years = ((beg_age + i) / 12);
    printf("Age %3d month %2d you have $%.2lf\n", years, months, beg_bal);
    beg_bal = (beg_bal * (1 + (working.rate / 12))) + working.contribution;
  }

   for (int i = 0; i < retirement.months; i++) {
    //double balance = beg_bal; 
    int months = (beg_age + working.months + i) % 12; 
    int years = ((beg_age + working.months + i) / 12);
    printf("Age %3d month %2d you have $%.2lf\n", years, months, beg_bal);
    beg_bal = (beg_bal * (1 + (retirement.rate / 12))) + retirement.contribution;
  }
}


int main(void) {

  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate = .045;

  retire_info retirement;
  retirement.months = 384;
  retirement.contribution = -4000;
  retirement.rate = .01;
    
  int beg_age = 327;
  double beg_bal = 21345;
  
  print_balance(beg_age, beg_bal, working, retirement);

  //  printf("\n ** months working %d ** \n", working.months);
  //printf("\n ** years working %d ** \n", (working.months / 12));
  //printf("\n ** retirement age %d  ** \n",(working.months / 12) + (beg_age /12));
  return 0;
}
