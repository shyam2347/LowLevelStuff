#include <stdio.h>

int main()
{
  int a, b;

  for (a = 0; a < 8; a++)
  {
    __asm__("cpuid"
            :"=a"(b)                 // EAX into b (output)
            :"0"(a)                  // a into EAX (input)
            :"%ebx","%ecx","%edx");  // clobbered registers

    printf("The code %x gives %x\n", a, b);
  }

  return 0;
}
