# Compiler
CC = g++

# Bison and Flex flags
BISON_FLAGS = -d
FLEX_FLAGS =

# Source files
BISON_FILE = parser.y
FLEX_FILE = lex.l

# Include files
INCLUDES = types.cpp node.cpp error.cpp main.cpp symtab.cpp globals.cpp threeAC.cpp x86.cpp

# Output file
OUTPUT_FILE = parser

all: $(OUTPUT_FILE)

$(OUTPUT_FILE):: $(BISON_FILE:.y=.tab.c) $(FLEX_FILE:.l=.yy.c) includes.hpp $(INCLUDES)
	$(CC) $(BISON_FILE:.y=.tab.c) $(FLEX_FILE:.l=.yy.c) $(INCLUDES) -o parser 

$(BISON_FILE:.y=.tab.c) $(BISON_FILE:.y=.tab.h): $(BISON_FILE)
	bison $(BISON_FLAGS) $(BISON_FILE)

$(FLEX_FILE:.l=.yy.c): $(FLEX_FILE) $(BISON_FILE:.y=.tab.h)
	flex $(FLEX_FLAGS) $(FLEX_FILE)

clean:
	rm -f $(OUTPUT_FILE) $(BISON_FILE:.y=.tab.c) $(BISON_FILE:.y=.tab.h) $(FLEX_FILE:.l=.yy.c)
