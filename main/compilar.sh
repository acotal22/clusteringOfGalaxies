g++ 1.primero.cpp -o primero -lX11 -pthread
g++ filesread.cpp -o filesread
g++ ultimo.cpp -o ultimo -lX11 -pthread
g++ GUI.cpp -o ejecutable -std=c++11 pkg-config --cflags --libs opencv
