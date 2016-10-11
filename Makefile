#Todos os seus .c
OBJS	=	./libhuffman/src/Encode.cpp		\
		./libhuffman/src/main.cpp		\
		./libhuffman/src/Tree.cpp		\
		./libhuffman/src/Node.cpp		\
		./libhuffman/src/Decode.cpp		\
		./libhuffman/utils/Debug.cpp	\
		./librsa/src/Math.cpp

#Todos os seus .h
DEPS	=	./libhuffman/inc/Encode.hpp		\
		./libhuffman/inc/Globals.hpp		\
		./libhuffman/inc/Tree.hpp		\
		./libhuffman/inc/Node.hpp		\
		./libhuffman/inc/Decode.hpp		\
		./libhuffman/utils/Debug.hpp	\
		./librsa/inc/Math.hpp

#Seu compilador
CC = g++

#Suas flags
COMPILER_FLAGS = -w -std=c++0x

#Nome do seu executavel
OBJ_NAME	=	"AlGi Crypt0r"

#Todos os alvos marcados para a compilação
all : $(OBJS)
	$(CC) $(OBJS) $(DEPS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ./build/$(OBJ_NAME)
