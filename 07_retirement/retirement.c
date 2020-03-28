#include <stdio.h>
#include <stdlib.h>

/*

struct retire_info_t {
  int months;
  double contribution;
  double rate_of_return;
};
  
typedef struct retire_info_t retire_info;
*/

void print_balance(double beg, int periods, double pmt, double rate, int age) {

  printf("hello");
  
  //  int beginning_balance = beg;
  int number_of_periods = periods;
  // int  payment = pmt;
  //int = rate;
 

  for (int i = 0; i < number_of_periods; i++) {
    int months = age + i; 
    int years = (months / 12);
    printf("Age %3d month %2d you have $.21f\n", years, months%12);
  }


}
	   
  //void retirement(int startAge, double initial, retire_info working, retire_info retired) { print_balance(working);


int main(void) {
  print_balance(1000,24,100,.05,36);
}
