#ifndef METRICS_H
#define METRICS_H

#include "csv_reader.h"

typedef char* (*MetricFunction)(int *size, Order *orders);

//Hay que declarar las funciones para cada metrica aqui
char* pizza_mas_vendida(int size, Order *orders);
char* pizza_menos_vendida(int size, Order *orders);

#endif
