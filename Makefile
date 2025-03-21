# Nombre del ejecutable
TARGET = app1.exe

# Directorios
SRC_DIR = src
INC_DIR = include

# Archivos fuente
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/csv_reader.c
# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Compilador
CC = gcc
CFLAGS = -I$(INC_DIR) -Wall -Wextra -std=c11

# Regla principal: compilar todo
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Regla para compilar archivos .c a .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)
