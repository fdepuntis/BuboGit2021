CPPFLAGS=-std=c++11
OUTPUT_NAME= upload.cgi
SRC_REP=src/*.cpp
HEADER_REP = defs/
OUTPUT_REP = build/
LIB = -lcgicc
all:
	g++ $(CPPFLAGS) -I $(HEADER_REP) $(LIB) $(SRC_REP) -o $(OUTPUT_REP)$(OUTPUT_NAME)
