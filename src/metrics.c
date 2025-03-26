#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/metrics.h"
#include "../include/csv_reader.h"

// Aqui hay que crear las funciones para cada metrica

// Implementación de métricas

// Numero maximo de pizzas esperadas

#define MAX_PIZZAS 50

//Estructura "auxiliar" para contar las pizzas (Tanto para la pizza mas como menos vendida)

typedef struct {
    char pizza_name_id[50];
    int total_sold;
} PizzaCount;





char* pizza_mas_vendida(int size, Order *orders) {
    PizzaCount pizzas[MAX_PIZZAS] = {0}; 
    int pizza_count = 0;

    // Recorrer todas las órdenes

    for (int i = 0; i < size; i++) {
        int found = 0;

        // Verificar si ya existe en el contador

        for (int j = 0; j < pizza_count; j++) {
            if (strcmp(pizzas[j].pizza_name_id, orders[i].pizza_name_id) == 0) {
                pizzas[j].total_sold += orders[i].quantity;
                found = 1;
                break;
            }
        }

        // Si no se encontró, agregarlo

        if (!found && pizza_count < MAX_PIZZAS) {
            strcpy(pizzas[pizza_count].pizza_name_id, orders[i].pizza_name_id);
            pizzas[pizza_count].total_sold = orders[i].quantity;
            pizza_count++;
        }
    }

    // Encontrar la pizza con mayor cantidad vendida

    int max_index = 0;
    for (int i = 1; i < pizza_count; i++) {
        if (pizzas[i].total_sold > pizzas[max_index].total_sold) {
            max_index = i;
        }
    }

    return pizzas[max_index].pizza_name_id;
    
    //Retorna el nombre de la pizza mas vendida
}





//Exactamente la misma f**king funcion que la que busca la pizza mas vendida
//La diferencia es la desigualdad del final

char* pizza_menos_vendida(int size, Order *orders) {
    PizzaCount pizzas[MAX_PIZZAS] = {0}; 
    int pizza_count = 0;

    // Recorrer todas las órdenes

    for (int i = 0; i < size; i++) {
        int found = 0;

        // Verificar si ya existe en el contador

        for (int j = 0; j < pizza_count; j++) {
            if (strcmp(pizzas[j].pizza_name_id, orders[i].pizza_name_id) == 0) {
                pizzas[j].total_sold += orders[i].quantity;
                found = 1;
                break;
            }
        }

        // Si no se encontró, agregarlo

        if (!found && pizza_count < MAX_PIZZAS) {
            strcpy(pizzas[pizza_count].pizza_name_id, orders[i].pizza_name_id);
            pizzas[pizza_count].total_sold = orders[i].quantity;
            pizza_count++;
        }
    }

    // Encontrar la pizza menos vendida

    int min_sold = pizzas[0].total_sold; // Asumimos que la primera pizza tiene la menor cantidad
    int min_index = 0;  // Índice de la pizza menos vendida

    for (int i = 1; i < pizza_count; i++) {
        if (pizzas[i].total_sold < min_sold) {
            min_sold = pizzas[i].total_sold;
            min_index = i;
        }
    }

    return pizzas[min_index].pizza_name_id;
    
    // Retorna el nombre de la pizza menos vendida
}