#include <stdio.h>
#include <stdlib.h>
#include "../include/csv_reader.h"
#include "../include/metrics.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <ventas_pizzas.csv>\n", argv[0]);
        return 1;
    }

    // Contar los registros del archivo
    iOrders = CuentaRegistros(argv[1]);
    if (iOrders == 0) {
        printf("No se encontraron órdenes en el archivo.\n");
        return 1;
    }

    // Cargar las órdenes del archivo
    CargaRegistros(argv[1], iOrders);
    if (aOrders == NULL) {
        printf("Error al cargar las órdenes.\n");
        return 1;
    }

    printf("Se cargaron %d órdenes.\n", iOrders);

    // Obtener la pizza más y menos vendida
    char *mas_vendida = pizza_mas_vendida(iOrders, aOrders);
    char *menos_vendida = pizza_menos_vendida(iOrders, aOrders);

    // Mostrar los resultados
    printf("Pizza más vendida: %s\n", mas_vendida);
    printf("Pizza menos vendida: %s\n", menos_vendida);

    // Liberar la memoria asignada
    free_orders(aOrders, iOrders);  // Liberar las órdenes
    free(mas_vendida);   // Liberar la memoria de la pizza más vendida
    free(menos_vendida); // Liberar la memoria de la pizza menos vendida
    
    return 0;
}
