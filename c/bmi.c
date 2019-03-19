#include <stdio.h>
#include <string.h>

float calc_bmi(float h, float w) {
  return w/(h*h);
}

void main() {
  float height, weight, bmi, bmi_low, bmi_high ;
  char gender[4] ;

  printf("Укажите пол (м/ж или m/f): ");
  scanf("%s", gender);

  if (!strcmp(gender, "м") || !strcmp(gender, "m"))
    { bmi_low = 18.5; bmi_high = 25; }
  else
    { bmi_low = 18.5; bmi_high = 25; }

  
  printf("Введите рост в метрах: ");
  scanf("%f", &height);
  printf("Введите вес в килограммах: ");
  scanf("%f", &weight);

  bmi = calc_bmi(height, weight);

  if (bmi < bmi_low)
    { printf("BMI = %.1f ниже нижней границы нормы (%.1f)\n", bmi, bmi_low); }
  else if (bmi > bmi_high)
    { printf("BMI = %.1f выше верхней границы нормы (%.1f)\n", bmi, bmi_high); }
  else
    { printf("BMI = %.1f в пределах нормы (%.1f–%.1f)\n", bmi, bmi_low, bmi_high); }
  
}
  
