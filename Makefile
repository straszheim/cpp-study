% : %.cpp
	@rm -f ./$@
	gcc -O3 -I. -I/home/troy/Downloads/boost_1_44_0/ -Wall -o $@ $< name_of.cpp -lstdc++
	@echo "-----------------------------------------------"
	./$@
	@echo "-----------------------------------------------"
	@rm -f ./$@


ALLSRC=$(wildcard *.cpp)

all : $(ALLSRC:.cpp=)

%-thread : %-thread.cpp
	@rm -f ./$@
	gcc -O3 -I. -I/home/troy/Downloads/boost_1_44_0/ -Wall -o $@ $< name_of.cpp -lstdc++ -lboost_thread-mt
	@echo "-----------------------------------------------"
	./$@
	@echo "-----------------------------------------------"
	@rm -f ./$@
