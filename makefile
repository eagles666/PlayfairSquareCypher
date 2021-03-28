files := $(wildcard sources/*.c)
 
all:PlayfairSquare
	@echo "Done."

PlayfairSquare: $(files)
	gcc -Wall -o $@ $(files) -I headers/
