int add(int x, int y)
{
  return x + y;
}

int multiply(int x, int y)
{
  return x * y;
}

int square(int x)
{
  return x * x;
}

int onoff(int port, int direction)
{
  int returnValue = 0;

  if(direction > 0)
  {
    //fprintf("Port: %d turned on\n", port);
    returnValue = 1;
  }
  else if(direction < 0)
  {
    //fprintf("Port: %d turned off\n", port);
    returnValue = -1;
  }
  else
  {
    //fprintf("Port %d stayed the same...\n", port);
    returnValue = 0;
  }

  return returnValue;
}
