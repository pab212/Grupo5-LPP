#include <stdio.h>
#include <stdlib.h>
#include "../include/csv_reader.h"
#include "../include/metrics.h"
#include <string.h>

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
    
    // Selección de categorías para demostrar datos
    char aux[4];
    char *categorias; 
    categorias = aux;
    while (1){
        printf("¿Que datos quiere conocer?: \n");
        scanf("%s", categorias);
        if (strcmp(categorias, "pms") == 0){
            char *mas_vendida = pizza_mas_vendida(iOrders, aOrders);
            printf("Pizza más vendida: %s\n", mas_vendida);
            }
        else if (strcmp(categorias, "pls") == 0){
            char *menos_vendida = pizza_menos_vendida(iOrders, aOrders);
            printf("Pizza menos vendida: %s\n", menos_vendida);
        }
        else if (strcmp(categorias, "dms") == 0){
            dia_mas_dinero();
        
        }
        else if (strcmp(categorias, "dls") == 0){
            dia_menos_dinero();
        }
        else if (strcmp(categorias, "dmsp") == 0){
            dia_mas_pizza();
        }
        else if (strcmp(categorias, "dlsp") == 0){
            dia_menos_pizza();
        }
        else if (strcmp(categorias, "apo") == 0){
            promedio_pizzas_orden();
        }
        else if (strcmp(categorias, "apd") == 0){
            promedio_pizzas_dia();
        }
        else if (strcmp(categorias, "ims") == 0){
            ingrediente_mas_vendido();
        }
        else if (strcmp(categorias, "hp") == 0){
            categoria_pizzas();
        }
    }

    // Liberar memorias asignadas
    free_orders(aOrders, iOrders); // Liberar la memoria de las ordenes
    free(mas_vendida);   // Liberar la memoria de la pizza más vendida
    free(menos_vendida); // Liberar la memoria de la pizza menos vendida
    free(aux); // Liberar la memoria de la variable auxiliar en donde se almacena la categoría seleccionada

    return 0;
}
