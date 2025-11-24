#include <stdio.h>

int main() {

        double sales[4][5] = {{0}};
        char check = 'y';

        for (size_t i = 0; i < 4; i++){
                printf("%s%ld%s", "Insert sales person ", i+1, " numbers of slips to insert:\n");
                int slips;
                scanf("%d", &slips);
                for (size_t j = 0; j < slips; j++){
                        printf("%s%ld%s", "This is the ", j+1, "º slip:\n");
                        for (size_t k = 0; k < 5; k++) {
                                double aux = 0;
                                printf("%s%ld%s", "Insert total dollar value of product ", k+1, " sold: ");
                                scanf("%lf", &aux);
                                sales[i][k] += aux;
                        }
                }
        }

        double row_total[4] = {0};
        double collum_total[5] = {0};

        printf("         ");

        for (size_t i = 0; i < 5; i++) {
                printf("%12s%ld", "Product ", i+1);
        }

        printf("%13s", "Total");
        printf("\n");

        for (size_t i = 0; i < 4; i++) {
                printf("%s%ld%s", "Person ", i+1, ":");
                for (size_t j = 0; j < 5; j++) {
                        printf("%13.2lf", sales[i][j]);
                        row_total[i] += sales[i][j];
                }
                printf("%13.2f", row_total[i]);
                printf("\n");
        }

        printf("%s", "Total:   ");

        for (size_t j = 0; j < 5; j++){
                for (size_t i = 0; i < 4; i++) {
                        collum_total[j] += sales[i][j];
                }
                printf("%13.2lf", collum_total[j]);
        }

        printf("\n");

}
