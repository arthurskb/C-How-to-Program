#include <stdio.h>
#include <time.h>

typedef struct {
    unsigned int month;
    unsigned int day;
    unsigned int year;
} BirthDate;

typedef struct {
  char firstName[25];
  char lastName[25];
  char gender;
  BirthDate birthDate;
  double height;
  double weight;
} HealthProfile;


HealthProfile readData();
unsigned int calculateAge(const unsigned int month, const unsigned int day, const unsigned int year);
void displayHeartConditions(const unsigned int age);
void displayBMI(const double height, const double weight);
void displayInfo(const HealthProfile const *data);
void clearInputBuffer();

int main() {
  HealthProfile data = readData();
  printf("\n");
  displayInfo(&data);
}

HealthProfile readData() {
  HealthProfile data;
  printf("Welcome, please provide you the following data to estabilish your health profile: \n");
  printf("First Name: (Max of 24 characters) ");
  scanf("%24s", data.firstName);
  printf("Last Name: (Max of 24 characters) ");
  clearInputBuffer();
  scanf("%24s", data.lastName);
  printf("Birth Gender: (M - Male, F - Female) ");
  clearInputBuffer();
  scanf("%c", &data.gender);
  printf("Date of Birth: \n");
  printf("Month: ");
  scanf("%u", &data.birthDate.month);
  printf("Day: ");
  scanf("%u", &data.birthDate.day);
  printf("Year: ");
  scanf("%u", &data.birthDate.year);
  printf("Height: (in inches) ");
  scanf("%lf", &data.height);
  printf("Weight: (in pounds) ");
  scanf("%lf", &data.weight);
  return data;
}

void displayInfo(const HealthProfile const *data) {
  unsigned int age = calculateAge(data->birthDate.month, data->birthDate.day, data->birthDate.year);
  printf("Displaying user's data\n");
  printf("First Name: %s\n", data->firstName);
  printf("Last Name: %s\n", data->lastName);
  printf("Birth Gender: %c\n", data->gender);
  printf("Date of birth: %u-%u-%u\n", data->birthDate.month, data->birthDate.day, data->birthDate.year);
  printf("Height in inches: %lf\n", data->height);
  printf("Weight in inches: %lf\n", data->weight);
  printf("Age: %u years\n", age);
  displayBMI(data->height, data->weight);
  displayHeartConditions(age);
}

unsigned int calculateAge(const unsigned int month, const unsigned int day, const unsigned int year) {
  time_t timeAux = time(NULL);
  struct tm *timeInfo = localtime(&timeAux);
  unsigned int currMonth = ((unsigned int) timeInfo->tm_mon) + 1;
  unsigned int currDay = (unsigned int) timeInfo->tm_mday;
  unsigned int currYear = (unsigned int) timeInfo->tm_year + 1900;
  unsigned int age = currYear - year;
  if (currMonth < month) {
    age -= 1;
  } else if (currMonth == month) {
    if (currDay < day) {
      age -= 1;
    }
  }
  return age;
}

void displayBMI(const double height, const double weight) {
  double bmi = (weight * 703)/(height*height);
  printf("Your BMI is %.1lf\n", bmi);
  printf("Table for reference:\n");
  printf("BMI VALUES\n");
  printf("%-12s less than 18.5\n", "Underweight:");
  printf("%-12s between 18.5 and 24.9\n", "Normal:");
  printf("%-12s between 25 and 29.9\n", "Overweight:");
  printf("%-12s 30 or greater\n", "Obese:");
}

void displayHeartConditions(const unsigned int age) {
  unsigned int maxRate = 220 - age;
  unsigned int lowerBound = maxRate * 0.5;
  unsigned int upperBound = maxRate * 0.85;
  printf("Your maximum heart rate suggested is: %u beats per minute.\n", maxRate);
  printf("During exercise, you should aim to keep your heart rate between %u and %u beats per minute.\n", lowerBound, upperBound);
}

void clearInputBuffer() {
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}

