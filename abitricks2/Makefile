stuff:
	rm libfoo.so client client.o
	gcc -g -fPIC -I. -shared -Dfoo_EXPORTS -DABI_VERSION=13 -o libfoo.so abi.cpp

	gcc -I. -c -DABI_VERSION=13 client.cpp
	gcc -o client client.o ./libfoo.so -lstdc++
	./client
	@echo
	@echo
	rm client

	gcc -I. -c -DABI_VERSION=14 client.cpp
	gcc -o client client.o ./libfoo.so -lstdc++
	./client
