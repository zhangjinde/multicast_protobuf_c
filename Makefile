all:
	gcc src/*.c proto/*-c.c -o mp -lcsfml-graphics -lcsfml-window -lcsfml-network -lcsfml-system -lcsfml-audio -lm -g -ljnxc -pthread -lX11 -luuid -lprotobuf-c
