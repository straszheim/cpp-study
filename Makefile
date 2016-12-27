CC=clang-3.8
INCLUDES=-I. -I/opt/toolkit
DEFINES=
CCARGS=-g -std=c++14 $(INCLUDES) $(DEFINES)
LIBS=-lstdc++

% : %.cpp
	@rm -f ./$@
	$(CC) $(CCARGS) -o $@ $< util/name_of.cpp $(LIBS)
	@echo "-----------------------------------------------"
	./$@ $(ARGS)
	@echo "-----------------------------------------------"
	@rm -f ./$@


ALLSRC=$(wildcard *.cpp)

all : $(ALLSRC:.cpp=)

%-thread : %-thread.cpp
	@rm -f ./$@
	$(CC) $(CCARGS) -I. -Wall -o $@ $< util/name_of.cpp -lstdc++ -lboost_thread-mt
	@echo "-----------------------------------------------"
	./$@
	@echo "-----------------------------------------------"
	@rm -f ./$@
