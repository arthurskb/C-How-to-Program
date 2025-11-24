6.10
#include <stdio.h>

int main(void) {
        int sales_salaries[] = {201, 344, 567, 590, 601, 602, 603, 904, 1002, 1500};
        int counter[4] = {0};
        int ref = sizeof(sales_salaries)/4;
        for (size_t i = 0; i < ref; i++) {
                if(sales_salaries[i] <= 299 && sales_salaries[i] >= 200) counter[0]++;
                else if(sales_salaries[i] >= 300 && sales_salaries[i] <= 399) counter[1]++;
                else if(sales_salaries[i] >= 400 && sales_salaries[i] <= 499) counter[2]++;
                else if(sales_salaries[i] >= 500) counter[3]++;
        }
        int j, k;
        for (size_t i = 0, j = 200, k = 299; i < 4; i++, j += 100, k += 100) {
                if (i == 3) {
                        printf("%d%s%d%s", counter[i], " people earned more than ", j, "bucks\n");
                        break;
                }
                printf("%d%s%d%s%d%s", counter[i], " people earned between ", j, " and ", k, " bucks\n");
        }
}