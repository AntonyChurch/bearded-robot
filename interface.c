#include <wiringPi.h>

void configure_pin(int port);

//Used [WiringPi docs](http://wiringpi.com/wp-content/uploads/2013/03/pins.pdf)
int pins[21];
bool isSetup = false;

int setup()
{
  int setupValue = wiringPiSetup();

  int i = 0;
  for(i; i < 21; ++i)
  {
    pins[i] = 0;
  }

  setup = true;

  return setupValue;
}

int turn_on(int port)
{
  if(isSetup == false)
  {
    int setupReturn = setup();
    if(setupReturn == -1)
    {
      return setupReturn;
    }
  }

  configure_pin(port);

  digitalWrite(port, 1);

  return 1;
}

int turn_off(int port)
{
  if(isSetup == false)
  {
    int setupReturn = setup();
    if(setupReturn == -1)
    {
      return setupReturn;
    }
  }

  configure_pin(port);

  digitalWrite(port, 0);

  return 1;
}

void configure_pin(int port)
{
  if(pins[port] == -1)
  {
    pinMode(port, OUTPUT);
    pins[port] = port;
  }
}
