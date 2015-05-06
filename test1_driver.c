#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int read_cmd(byte *buf);
int write_cmd(byte *buf, int len);

//Defined in test1.c
int add(int x, int y);
int multiply(int x, int y);
int square(int x);
int onoff(int port, int direction);

int main()
{
  int fn, arg1, arg2, result;
  byte buff[100];

  while(read_cmd(buff) > 0)
  {
    fn = buff[0];

    if(fn == 1)
    {
      arg1 = buff[1];
      arg2 = buff[2];

      result = add(arg1, arg2);
    }
    else if (fn == 2)
    {
      arg1 = buff[1];
      arg2 = buff[2];

      result = multiply(arg1, arg2);
    }
    else if (fn == 3)
    {
      arg1 = buff[1];

      result = square(arg1);
    }
    else if (fn == 4)
    {
      arg1 = buff[1];
      arg2 = buff[2];

      result = onoff(arg1, arg2);
    }
    else
    {
      exit(EXIT_FAILURE);
    }

    buff[0] = result;
    write_cmd(buff, 1);
  }
}
