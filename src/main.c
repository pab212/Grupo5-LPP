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
        printf("No se encontraron ordenes en el archivo.\n");
        return 1;
    }

    // Cargar las órdenes del archivo
    CargaRegistros(argv[1], iOrders);
    if (aOrders == NULL) {
        printf("Error al cargar las ordenes.\n");
        return 1;
    }

    printf("Se cargaron %d ordenes.\n", iOrders);
    
    // Selección de categorías para demostrar datos
    char aux[4];
    char categorias[4];
    char *mas_vendida = NULL;
    char *menos_vendida = NULL;
    while (1){
        printf("Que datos quiere conocer?: \n");
        scanf("%s", categorias);
        if (strcmp(categorias, "pms") == 0) {
            if (mas_vendida) free(mas_vendida); // Liberar memoria previa si existe
            mas_vendida = pizza_mas_vendida(iOrders, aOrders);
            printf("Pizza mas vendida: %s\n", mas_vendida);
        }
        else if (strcmp(categorias, "pls") == 0) {
            if (menos_vendida) free(menos_vendida);
            menos_vendida = pizza_menos_vendida(iOrders, aOrders);
            printf("Pizza menos vendida: %s\n", menos_vendida);
        }
        else if (strcmp(categorias, "dms") == 0) {
            float ventas_mas = 0; // Variable para almacenar el total de ventas
            char *fecha_mas = dia_mas_dinero(iOrders, aOrders, &ventas_mas);
            printf("El dia con mas ventas fue: %s con un total de $%.2f\n", fecha_mas, ventas_mas);
            free(fecha_mas); // Liberar la memoria devuelta por strdup
        }
        else if (strcmp(categorias, "dls") == 0) {
            float ventas_menos = 0; // Variable para almacenar el total de ventas
            char *fecha_menos = dia_menos_dinero(iOrders, aOrders, &ventas_menos);
            printf("El dia con menos ventas fue: %s con un total de $%.2f\n", fecha_menos, ventas_menos);
            free(fecha_menos); // Liberar la memoria devuelta por strdup
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
        else {
            char respuesta[2];
            printf("Se pidio una metrica que no existe, Desea continuar?: (S/N)\n ");
            scanf(" %s",&respuesta);
            if (strcmp(respuesta, "N") == 0 || strcmp(respuesta, "n") == 0) {
                break;
            }
        }

        // Limpiar el búfer de entrada para evitar problemas en la siguiente iteración
        while (getchar() != '\n');
    }

    // Liberar memorias asignadas
    free(sCabecera);
    free_orders(aOrders, iOrders); // Liberar la memoria de las ordenes
    if (mas_vendida) free(mas_vendida);
    if (menos_vendida) free(menos_vendida);

    return 0;
    }
