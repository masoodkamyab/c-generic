run: clean compile
	./generic

compile:
	gcc generic.c -o generic.exe
	
clean:
	del generic.exe
	
.PHONY: run compile clean