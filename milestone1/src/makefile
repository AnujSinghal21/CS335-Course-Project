# Compiler
CC = g++

# Bison and Flex flags
BISON_FLAGS = -d
FLEX_FLAGS =

# Source files
BISON_FILE = parser.y
FLEX_FILE = lex.l

# Include files
INCLUDES = symtab.hpp

# Output file
OUTPUT_FILE = parser

all: $(OUTPUT_FILE)

$(OUTPUT_FILE):: $(BISON_FILE:.y=.tab.c) $(FLEX_FILE:.l=.yy.c) $(INCLUDES) $(INCLUDES:.hpp=.cpp)
	$(CC) $(BISON_FILE:.y=.tab.c) $(FLEX_FILE:.l=.yy.c) $(INCLUDES:.hpp=.cpp) -o parser 

$(BISON_FILE:.y=.tab.c) $(BISON_FILE:.y=.tab.h): $(BISON_FILE)
	bison $(BISON_FLAGS) $(BISON_FILE)

$(FLEX_FILE:.l=.yy.c): $(FLEX_FILE) $(BISON_FILE:.y=.tab.h)
	flex $(FLEX_FLAGS) $(FLEX_FILE)

clean:
	rm -f $(OUTPUT_FILE) $(BISON_FILE:.y=.tab.c) $(BISON_FILE:.y=.tab.h) $(FLEX_FILE:.l=.yy.c)
