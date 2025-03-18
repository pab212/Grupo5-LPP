#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/csv_reader.h"

#define MAX_ORDERS 20 // Ajusta según el tamaño esperado

int load_orders(const char *filename, Order **orders) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error abriendo el archivo %s\n", filename);
        return 0;
    }

    *orders = malloc(MAX_ORDERS * sizeof(Order));
    int count = 0;
    char line[512];

    fgets(line, sizeof(line), file); // Saltar la primera línea (encabezados)
    while (fgets(line, sizeof(line), file) && count < MAX_ORDERS) {
        Order o;
        sscanf(line, "%d,%d,%49[^,],%d,%19[^,],%9[^,],%f,%f,%4[^,],%19[^,],%199[^,],%99[^\n]",
               &o.pizza_id, &o.order_id, o.pizza_name_id, &o.quantity, o.order_date, o.order_time,
               &o.unit_price, &o.total_price, o.pizza_size, o.pizza_category, o.pizza_ingredients, o.pizza_name);
        (*orders)[count++] = o;
    }

    fclose(file);
    return count; 
}
