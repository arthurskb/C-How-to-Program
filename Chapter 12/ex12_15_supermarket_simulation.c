#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct queueNode {
  struct queueNode *nextPtr;
  int arrivalTime;
} Customer;

void enqueueCustomer(Customer **head, Customer **tail);
void dequeueCustomer(Customer **head, Customer **tail);
void marketSimulation(int arrivalInterval);

int main() {
  marketSimulation(4);
  marketSimulation(3);
}

void marketSimulation(int arrivalInterval) {
  srand(time(NULL));
  Customer *head = NULL;
  Customer *tail = NULL;
  int numOfCustomers = 0;
  int maxCustomers = 0;
  int maxTimeWaiting = 0;

  int firstArrival = rand() % arrivalInterval + 1;
  int serviceTime = firstArrival + rand() % 4 + 1;
  int nextArrival = firstArrival + rand() % arrivalInterval + 1;

  for (int i = 0; i <= 720; i++) {
    if (i == nextArrival) {
      printf("New customer arrived\n");
      enqueueCustomer(&head, &tail);
      tail->arrivalTime = i;
      nextArrival += rand() % arrivalInterval + 1;
      numOfCustomers++;
      if (numOfCustomers > maxCustomers) {
        maxCustomers = numOfCustomers;
      }
    }
    if (i == serviceTime) {
      printf("Finished customer service\n");
      serviceTime += rand() % 4 + 1;
      if (head != NULL) {
        int timeWaiting = i - head->arrivalTime;
        if (timeWaiting > maxTimeWaiting) {
          maxTimeWaiting = timeWaiting;
        }
        dequeueCustomer(&head, &tail);
        numOfCustomers--;
      }
    }
  }
  printf("Using arrival interval from 1 to %d minutes:\n", arrivalInterval);
  printf("%d is the Max number of customers in the queue\n", maxCustomers);
  printf("%d is the Max longest wait time experienced by a customer\n",
         maxTimeWaiting);
}

void enqueueCustomer(Customer **head, Customer **tail) {
  Customer *newCustomer = malloc(sizeof(Customer));

  if (*head == NULL) {
    *head = newCustomer;
  } else {
    (*tail)->nextPtr = newCustomer;
  }
  *tail = newCustomer;
  (*tail)->nextPtr = NULL;
}

void dequeueCustomer(Customer **head, Customer **tail) {
  Customer *temp = *head;
  *head = (*head)->nextPtr;
  if (*head == NULL) {
    *tail = NULL;
  }
  free(temp);
}
