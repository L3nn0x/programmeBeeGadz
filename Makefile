#------------------------------------------------------------------------------
#
#
#       Programme Box
#
#
#------------------------------------------------------------------------------

CC = g++

SUFFIX = .cpp

PREFIX = .

EXE = a.out

INC = -I$(PREFIX)/libnfc -I$(PREFIX)/include

CFLAGS = -g -Wall -Werror -Wextra -std=c++11

LIB = $(PREFIX)/libnfc/libnfc.a -lusb

SRCDIR = $(PREFIX)/src

SRC = $(wildcard $(SRCDIR)/*$(SUFFIX))

OBJDIR = $(PREFIX)/obj

OBJ = $(subst $(SRCDIR), $(OBJDIR), $(SRC:$(SUFFIX)=.o)) $(OBJDIR)/mifare.o

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(INC) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%$(SUFFIX)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJDIR)/mifare.o: $(SRCDIR)/mifare.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all
