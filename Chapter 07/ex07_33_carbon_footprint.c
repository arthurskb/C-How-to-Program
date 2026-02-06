#include <stdio.h>

#define BUILDINGFACTOR 0.475
#define CARFACTOR 2.31

void building();
void car();
void bicycle();

int main() {
  void (*carbonFunction[3])() = {building, car, bicycle};
  printf("Enter the type of carboon footprint:\n");
  printf("1 - Building\n2 - Car\n3 - Bicycle\n");
  int choice;
  scanf("%d", &choice);
  while (choice < 1 && choice >= 3) {
    printf("Invalid choice, try again:\n");
    printf("1 - Building\n2 - Car\n3 - Bicycle\n");
    scanf("%d", &choice);
  }
  (*carbonFunction[choice - 1])();
}

void building() {
  double data, result;
  printf("Input your average month electricity usage (in kWh): ");
  scanf("%lf", &data);
  printf("Building Footprint = Electricity Usage * Electric Factor\n");
  printf("Building Footprint = %.3lf * %.3lf\n", data, BUILDINGFACTOR);
  result = BUILDINGFACTOR * data;
  printf("Building Footprint = %.3lf kg of CO2\n", result);
}

void car() {
  double data, result;
  printf("Input the total of liters of fuel consumed\n");
  scanf("%lf", &data);
  printf("Car Footprint = Total Fuel x Fuel Factor\n");
  printf("Car Foot print = %.3lf * %.3lf\n", data, CARFACTOR);
  result = CARFACTOR * data;
  printf("Car Footprint = %.3lf kg of CO2\n", result);
}

void bicycle() {
  printf(
      "Using a bicycle generates an operational CO2 footprint of 0kg. Good "
      "Job!\n");
}
