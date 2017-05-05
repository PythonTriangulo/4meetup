CFLAGS += `python3-config --cflags` --std=c11
LDLIBS += `python3-config --libs`

all: meu_modulo.so

%.so: %.c
	$(CC) $(CFLAGS) $(LDLIBS) -fPIC -shared $< -o $@
