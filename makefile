compile: main.c gameManager.c gameManager.h
	gcc main.c gameManager.c gameManager.h -Wall -g -o hangman.exe

run:
	./hangman.exe
