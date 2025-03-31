# Nombre del ejecutable
TARGET = app1

# Directorios
SRC_DIR = src
INC_DIR = include

# Archivos fuente
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/csv_reader.c $(SRC_DIR)/metrics.c

# Compilador y banderas
CC = gcc
CFLAGS = -I$(INC_DIR) -Wall -Wextra -std=c11

# Regla principal
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Limpiar archivos generados
clean:
	rm -f $(TARGET)
