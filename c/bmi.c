#include <stdio.h>

float calc_bmi(float h, float w) {
  return w/(h*h);
}

void main() {
  float height, weight, bmi;
  
  printf("Введите рост в метрах: ");
  scanf("%f", &height);
  printf("Введите вес в килограммах: ");
  scanf("%f", &weight);

  bmi = calc_bmi(height, weight);

  if (bmi < 18.5)
    { printf("BMI = %.1f ниже нижней границы нормы\n", bmi); }
  else if (bmi > 25)
    { printf("BMI = %.1f выше верхней границы нормы\n", bmi); }
  else
    { printf("BMI = %.1f в пределах нормы\n", bmi); }
  
}
  
