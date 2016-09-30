#Todos os seus .c
OBJS	=		./src/main.cpp	\
					./src/Node.cpp  \
					./src/Tree.cpp  \
					./src/Encode.cpp
#Seu compilador
CC = clang

#Suas flags
COMPILER_FLAGS = -w -std=c++0x

#Nome do seu executavel
OBJ_NAME =	./build/Huffman

#Todos os alvos marcados para a compilação
all : $(OBJS)
	$(CC) $(OBJS) $(DEPS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
