GCC_CMD=gcc -z execstack -fno-stack-protector

exploit: exploit.c
	${GCC_CMD} -o exploit exploit.c

stack: stack.c
	${GCC_CMD} -o stack stack.c

call_shellcode: call_shellcode.c
	${GCC_CMD} -o call_shellcode call_shellcode.c

clean:
	rm -f exploit stack call_shellcode