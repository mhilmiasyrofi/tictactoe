main: 
	$(CC) main.c board.c -o main

clean:
	rm -rf main *.o
