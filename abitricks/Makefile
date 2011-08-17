stuff:
	gcc -g -fPIC -I. -shared -o libfoo.so -DABI_VERSION=13 abi.cpp
	gcc -I. -o client -DABI_VERSION=13 client.cpp ./libfoo.so -lstdc++
	./client
	gcc -I. -g -o client -DABI_VERSION=14 client.cpp ./libfoo.so -lstdc++
	./client

