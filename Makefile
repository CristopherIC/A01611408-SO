compila: 
	gcc hello.c -o hello
	./hello

clean:
	rm hello
	
push:
	git add .
	git commit -m "xv6"
	git push origin master