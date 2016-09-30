#Todos os seus .c
OBJS =

#Todos os seus .h
DEPS =

#Seu compilador
CC = g++

#Suas flags
COMPILER_FLAGS = -w

#Nome do seu executavel
OBJ_NAME =

#Todos os alvos marcados para a compilação
all : $(OBJS)
	$(CC) $(OBJS) $(DEPS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
