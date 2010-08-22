% : %.cpp
	@rm -f ./$@
	gcc -O3 -I. -Wall -o $@ $< name_of.cpp -lstdc++
	@echo "-----------------------------------------------"
	./$@
	@echo "-----------------------------------------------"
	@rm -f ./$@


ALLSRC=$(wildcard *.cpp)

all : $(ALLSRC:.cpp=)
