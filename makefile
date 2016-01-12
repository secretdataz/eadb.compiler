# build paramaters
CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -g -O -I/usr/local/include -Ilibsort
LDFLAGS=/usr/local/lib/liblua.a libsort/libsort.a
LIB=-lsqlite3 -lm

OBJ_DIR=src
DB_DIR=src/db
IC_DIR=src/ic
CM_DIR=src/common

CFLAGS+=-I$(DB_DIR) -I$(IC_DIR) -I$(CM_DIR)

# item script compiler object files
IC_OBJ:=db_search.c format.c name_range.c range.c script.c util.c
IC_OBJ:=$(patsubst %.c,$(OBJ_DIR)/%.o,$(IC_OBJ))

# item database loader object files
DB_OBJ:=db_eathena.c db_rathena.c db_resources.c load.c util.c
DB_OBJ:=$(patsubst %.c,$(OBJ_DIR)/%.o,$(DB_OBJ))

# default target compiles the tools
all: ic dbc

ic: $(IC_DIR)/ic.c $(IC_OBJ)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS) $(LIB)

dbc: $(DB_DIR)/db.c $(DB_OBJ)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS) $(LIB)

$(OBJ_DIR)/%.o: $(DB_DIR)/%.c
	$(CC) -c -o $@ $(CFLAGS) $^

$(OBJ_DIR)/%.o: $(IC_DIR)/%.c
	$(CC) -c -o $@ $(CFLAGS) $^

$(OBJ_DIR)/%.o: $(CM_DIR)/%.c
	$(CC) -c -o $@ $(CFLAGS) $^

# clean object files for git inclusion
.PHONY: clean

clean:
	rm -rf src/*.o
	rm -f ic
	rm -f dbc
	rm -rf ic.dSYM
	rm -rf dbc.dSYM
	rm -f .DS_Store
