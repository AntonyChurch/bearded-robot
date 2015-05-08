#include <wiringPi.h>

void configure_pin(int port);

//Used [WiringPi docs](http://wiringpi.com/wp-content/uploads/2013/03/pins.pdf)
int pins[21];

int setup()
{
  int setupValue = wiringPiSetup();

  int i = 0;
  for(i; i < 21; ++i)
  {
    pins[i] = 0;
  }

  return setupValue;
}

int turn_on(int port)
{
  configure_pin(port);

  digitalWrite(port, 1);

  return 1;
}

int turn_off(int port)
{
  configure_port(port);

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
