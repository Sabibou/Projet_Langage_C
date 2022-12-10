CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=test.c  affichage.c deplacement.c niveau_fichier.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main
.PHONY : clean
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean :
	rm -rf $(OBJETS) $(EXECUTABLE)
