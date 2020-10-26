#include <stdio.h>
#include <stdlib.h>
struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;
double calculator (int startAge, double initial, retire_info status) {
  for (int i = 1; i <= status.months; i++) {
    printf("Age %3d month %2d you have $%.2f\n", startAge/12, startAge%12, initial);
    initial = initial + (initial * status.rate_of_return) + status.contribution;
    startAge++;
}
  return initial;
}
void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  double finalBalance = calculator(startAge, initial, working);
  calculator(816, finalBalance, retired);//816 =startAge(327) + working.months(489)
}
int main (void) {
  retire_info working;
  retire_info retired;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return =0.045/12;
  retired.months =384;
  retired.contribution = -4000;
  retired.rate_of_return =0.01/12;
  retirement(327, 21345, working, retired);
  return 0;
}
