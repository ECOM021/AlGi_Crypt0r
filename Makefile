OBJS	=	main.cpp			\
		./libhuffman/src/Encode.cpp	\
		./libhuffman/src/Tree.cpp	\
		./libhuffman/src/Node.cpp	\
		./libhuffman/src/Decode.cpp	\
		./libhuffman/utils/Debug.cpp	\
		./librsa/src/Math2.cpp		\
		./librsa/src/PrimeSet.cpp	\
		./librsa/src/Encrypt.cpp	\
		./librsa/src/Decrypt.cpp	\
		./View/src/Window.cpp

DEPS	=	./libhuffman/inc/Encode.hpp	\
		./libhuffman/inc/Globals.hpp	\
		./libhuffman/inc/Tree.hpp	\
		./libhuffman/inc/Node.hpp	\
		./libhuffman/inc/Decode.hpp	\
		./libhuffman/utils/Debug.hpp	\
		./librsa/inc/Math2.hpp		\
		./librsa/inc/PrimeSet.hpp	\
		./librsa/inc/Decrypt.hpp	\
		./librsa/inc/Encrypt.hpp	\
		./View/inc/Window.hpp

CC = g++

COMPILER_FLAGS = -w -std=c++0x -lm
OBJ_NAME = "AlGi Crypt0r"

all : $(OBJS)
	$(CC) $(OBJS) $(DEPS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ./build/$(OBJ_NAME) `pkg-config --cflags --libs gtkmm-3.0`
