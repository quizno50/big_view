OBJ=big_view.o main.o

big_view: $(OBJ)
	$(CC) -o $@ $^
