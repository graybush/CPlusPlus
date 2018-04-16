BIN=bin
BUILD=build
LIB=lib

VERSION=1.0
LIBFILES=$(BUILD)/PatchFactory.o
CXXFLAGS= -g -c -O0 -Wall -Wextra -fpic -I include -I /usr/include/libxml2
ARFLAGS= -r -s

.PHONY: clean install

all:$(BIN)/patch

install:$(LIB)/libpatch.a $(LIB)/libpatch.so.$(VERSION)

$(BIN)/patch: $(BUILD)/patch.o $(BUILD)/PatchFactory.o
	mkdir -p $(BIN)
	g++ -o $@ $^ -lxml2 

$(BUILD)/%.o: src/%.cpp
	mkdir -p $(BUILD)
	g++ -o $@ $(CXXFLAGS) $<

$(LIB)/libpatch.a: $(LIBFILES)
	mkdir -p $(LIB)
	rm -f $@
	ar $(ARFLAGS) $@ $^

$(LIB)/libpatch.so.$(VERSION): $(LIBFILES)
	mkdir -p $(LIB)
	g++ -shared -fpic -Wl,-soname,libpatch.so -o $@ $^
	rm -f $(LIB)/libpatch.so
	ln -s libpatch.so.$(VERSION) $(LIB)/libpatch.so

clean:
	rm -rf $(BIN)
	rm -rf $(BUILD)
	rm -rf $(LIB)
