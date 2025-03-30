GCC_CMD=gcc -z execstack -fno-stack-protector

exploit: exploit.c
	${GCC_CMD} -o exploit exploit.c

exploit-ec: exploit-ec.c
	${GCC_CMD} -o exploit-ec exploit-ec.c

stack: stack.c
	${GCC_CMD} -o stack stack.c
	chmod 4755 stack

stack-dbg: stack.c
	${GCC_CMD} -g -o stack-dbg stack.c
	chmod 4755 stack-dbg

call_shellcode: call_shellcode.c
	${GCC_CMD} -o call_shellcode call_shellcode.c

call_setuid: call_setuid.c
	${GCC_CMD} -o call_setuid call_setuid.c

badfile: exploit
	./exploit

clean:
	rm -f exploit exploit-ec stack stack-dbg call_shellcode call_setuid