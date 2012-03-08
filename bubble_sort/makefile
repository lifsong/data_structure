UT_EXE = run.tests
SILENCE = @

all : *.c 
	$(SILENCE)gcc -Wall -Werror -O -std=c99 *.c -o $(UT_EXE)
	./$(UT_EXE)

clean:
	$(SILENCE)rm -rf *.o $(UT_EXE)