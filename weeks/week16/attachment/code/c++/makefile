debug: pointers.cc
	c++ -std=c++17 -o pointers pointers.cc -Wall -fsanitize=address,undefined

release: pointers.cc
	c++ -std=c++17 -o pointers pointers.cc -Wall -O2

.PHONY: debug release
