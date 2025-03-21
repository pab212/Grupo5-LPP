#include <stdio.h>
#include <stdlib.h>
#include "../include/csv_reader.h"
#include "../include/metrics.h"

int main(int argc, char *argv[]) {
    // Aqui usamos load_orders para leer el csv
    if (argc < 2) {
        printf("Uso: %s <ventas_pizzas.csv>\n", argv[0]);
        return 1;
    }

    Order *orders;
    int size = load_orders(argv[1], &orders);
    if (size == 0) return 1;
    // Definir las métricas disponibles
    struct {
        char *name;
        MetricFunction func;
    } metrics[] = {
        {"pms", pizza_mas_vendida},
        {"pls", pizza_menos_vendida},
        {NULL, NULL}
    };

    printf("Se cargaron %d ordenes.\n", size);

    free(orders);
    
    return 0; 
}