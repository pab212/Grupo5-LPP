#include <stdio.h>
#include <stdlib.h>
#include "../include/csv_reader.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <ventas_pizzas.csv>\n", argv[0]);
        return 1;
    }

    Order *orders;
    int size = load_orders(argv[1], &orders);
    if (size == 0) return 1;

    printf("Se cargaron %d ordenes.\n", size);

    free(orders);
    return 0; 
}