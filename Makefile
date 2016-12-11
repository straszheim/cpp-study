CC=/usr/bin/clang-3.8

% : %.cpp
	@rm -f ./$@
	gcc -O3 -I. -Wall -o $@ $< name_of.cpp -lstdc++ -lboost_thread
	@echo "-----------------------------------------------"
	./$@ $(ARGS)
	@echo "-----------------------------------------------"
	@rm -f ./$@


ALLSRC=$(wildcard *.cpp)

all : $(ALLSRC:.cpp=)

%-thread : %-thread.cpp
	@rm -f ./$@
	gcc -O3 -I. -Wall -o $@ $< name_of.cpp -lstdc++ -lboost_thread-mt
	@echo "-----------------------------------------------"
	./$@
	@echo "-----------------------------------------------"
	@rm -f ./$@
