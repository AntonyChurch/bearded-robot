#include <wiringPi.h>

//Used [WiringPi docs](http://wiringpi.com/wp-content/uploads/2013/03/pins.pdf)
int pins[21];

int setup()
{
  int setupValue = wiringPiSetup();
  return setupValue;
}

int turn_on(int port)
{
  configure_port(port);

  digitalWrite(port, 1);

  return 1;
}

int turn_off(int port)
{
  configure_port(port);

  digitalWrite(port, 0);

  return 1;
}

void configure_port(int port)
{
  if(pins[port] == null)
  {
    pinMode(port, OUTPUT);
    pins[port] = port;
  }
}
