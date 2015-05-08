#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int read_cmd(byte *buf);
int write_cmd(byte *buf, int len);

//Defined in test1.c
int setup();
int turn_on(int port);
int turn_off(int port);

int main()
{
  int fn, arg1, arg2, result;
  byte buff[100];

  while(read_cmd(buff) > 0)
  {
    fn = buff[0];

    if(fn == 1)
    {
      result = setup();
    }
    else if (fn == 2)
    {
      arg1 = buff[1];

      result = turn_on(arg1);
    }
    else if (fn == 3)
    {
      arg1 = buff[1];

      result = turn_off(arg1);
    }
    else
    {
      exit(EXIT_FAILURE);
    }

    buff[0] = result;
    write_cmd(buff, 1);
  }
}
