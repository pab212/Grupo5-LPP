#ifndef METRICS_H
#define METRICS_H

#include "csv_reader.h"

typedef char* (*MetricFunction)(int *size, Order *orders);

//Hay que declarar las funciones para cada metrica aqui
char* pizza_mas_vendida(int size, Order *orders);
char* pizza_menos_vendida(int size, Order *orders);
char* dia_mas_dinero(int size, Order *orders, float *total);
char* dia_menos_dinero(int size, Order *orders, float *total);

//Declaraciones que no estan (Temporal para poder correr el codigo)
void dia_mas_pizza();
void dia_menos_pizza();
void promedio_pizzas_orden();
void promedio_pizzas_dia();
void ingrediente_mas_vendido();
void categoria_pizzas();
#endif
