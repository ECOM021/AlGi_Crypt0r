#Todos os seus .c
OBJS	=	./libhuffman/src/Encode.cpp		\
		main.cpp		\
		./libhuffman/src/Tree.cpp		\
		./libhuffman/src/Node.cpp		\
		./libhuffman/src/Decode.cpp		\
		./libhuffman/utils/Debug.cpp	\
		./librsa/src/Math2.cpp		\
		./librsa/src/PrimeSet.cpp		\
		./librsa/src/Encrypt.cpp		\
		./librsa/src/Decrypt.cpp

#Todos os seus .h
DEPS	=	./libhuffman/inc/Encode.hpp		\
		./libhuffman/inc/Globals.hpp		\
		./libhuffman/inc/Tree.hpp		\
		./libhuffman/inc/Node.hpp		\
		./libhuffman/inc/Decode.hpp		\
		./libhuffman/utils/Debug.hpp	\
		./librsa/inc/Math2.hpp				\
		./librsa/inc/PrimeSet.hpp			\
		./librsa/inc/Decrypt.hpp		\
		./librsa/inc/Encrypt.hpp

#Seu compilador
CC = g++

#Suas flags
COMPILER_FLAGS = -w -std=c++0x -lm

#Nome do seu executavel
OBJ_NAME	=	"AlGi Crypt0r"

#Todos os alvos marcados para a compilação
all : $(OBJS)
	$(CC) $(OBJS) $(DEPS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ./build/$(OBJ_NAME)
