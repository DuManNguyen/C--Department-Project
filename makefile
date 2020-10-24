objects=main.o helper.o
edit: $(objects)
	cc -o edit $(objects)

	
clean: 
	rm edit $(objects) 
