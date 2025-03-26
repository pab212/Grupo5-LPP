#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/metrics.h"

#define MAX_PIZZAS 50

typedef struct {
    char pizza_name_id[50];
    int total_sold;
} PizzaCount;

char* pizza_mas_vendida(int size, Order *orders) {
    PizzaCount pizzas[MAX_PIZZAS] = {0}; 
    int pizza_count = 0;

    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < pizza_count; j++) {
            if (strcmp(pizzas[j].pizza_name_id, orders[i].pizza_name_id) == 0) {
                pizzas[j].total_sold += orders[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && pizza_count < MAX_PIZZAS) {
            strcpy(pizzas[pizza_count].pizza_name_id, orders[i].pizza_name_id);
            pizzas[pizza_count].total_sold = orders[i].quantity;
            pizza_count++;
        }
    }

    int max_index = 0;
    for (int i = 1; i < pizza_count; i++) {
        if (pizzas[i].total_sold > pizzas[max_index].total_sold) {
            max_index = i;
        }
    }

    return strdup(pizzas[max_index].pizza_name_id); // Copia dinámica del string
}

char* pizza_menos_vendida(int size, Order *orders) {
    PizzaCount pizzas[MAX_PIZZAS] = {0}; 
    int pizza_count = 0;

    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < pizza_count; j++) {
            if (strcmp(pizzas[j].pizza_name_id, orders[i].pizza_name_id) == 0) {
                pizzas[j].total_sold += orders[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found && pizza_count < MAX_PIZZAS) {
            strcpy(pizzas[pizza_count].pizza_name_id, orders[i].pizza_name_id);
            pizzas[pizza_count].total_sold = orders[i].quantity;
            pizza_count++;
        }
    }

    int min_index = 0;
    for (int i = 1; i < pizza_count; i++) {
        if (pizzas[i].total_sold < pizzas[min_index].total_sold) {
            min_index = i;
        }
    }

    return strdup(pizzas[min_index].pizza_name_id); // Copia dinámica del string
}
