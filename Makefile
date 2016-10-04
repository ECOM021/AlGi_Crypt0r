#Todos os seus .c
OBJS	=	./src/Encode.cpp	\
		./src/main.cpp		\
		./src/Tree.cpp		\
		./src/Node.cpp		\
		./utils/Debug.cpp
#Todos os seus .h
DEPS	=	./inc/Encode.hpp	\
		./inc/Globals.hpp	\
		./inc/Tree.hpp		\
		./inc/Node.hpp		\
		./utils/Debug.hpp

#Seu compilador
CC = g++

#Suas flags
COMPILER_FLAGS = -w -std=c++0x

#Nome do seu executavel
OBJ_NAME	=	"AlGi Crypt0r"

#Todos os alvos marcados para a compilação
all : $(OBJS)
	$(CC) $(OBJS) $(DEPS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ./build/$(OBJ_NAME)
