// A simple web server that always just says "Hello World"

#include "etherShield.h"
#include "ETHER_28J60.h"

int relayPinA = A0;
int relayPinB = A1;
int relayPinC = A2;
int relayPinD = A3;

static uint8_t mac[6] = {
  0x54, 0x55, 0x58, 0x10, 0x00, 0x24};   // this just needs to be unique for your network, 
// so unless you have more than one of these boards
// connected, you should be fine with this value.

static uint8_t ip[4] = {
  172, 27, 2, 15};                       // the IP address for your board. Check your home hub
// to find an IP address not in use and pick that
// this or 10.0.0.15 are likely formats for an address
// that will work.

static uint16_t port = 80;                                      // Use port 80 - the standard for HTTP

ETHER_28J60 e;

void setup()
{ 
  e.setup(mac, ip, port);
  pinMode(relayPinA, OUTPUT);
  pinMode(relayPinB, OUTPUT);
  pinMode(relayPinC, OUTPUT);
  pinMode(relayPinD, OUTPUT);
}

void loop()
{
  char* params;
  if (params = e.serviceRequest())
  {
    e.print("<H1>Mattox Lights - Web Control</H1>");
    e.print("<br />");
    e.print("<A HREF='?cmd=relayA1'>Relay A - ON</A>");
    e.print("<br />");
    e.print("<A HREF='?cmd=relayA0'>Relay A - OFF</A>");
    e.print("<br />");
    e.print("<A HREF='?cmd=relayB1'>Relay B - ON</A>");
    e.print("<br />");
    e.print("<A HREF='?cmd=relayB0'>Relay B - OFF</A>");
    e.print("<br />");
    e.print("<A HREF='?cmd=relayC1'>Relay C - ON</A>");
    e.print("<br />");
    e.print("<A HREF='?cmd=relayC0'>Relay C - OFF</A>");
    e.print("<br />");
    e.print("<A HREF='?cmd=relayD1'>Relay D - ON</A>");
    e.print("<br />")
      e.print("<A HREF='?cmd=relayD0'>Relay D - OFF</A>");
    e.print("<br />");
    if (strcmp(params, "?cmd=relayA0") == 0)
    {
      digitalWrite(relayPinA, LOW);
    }
    if (strcmp(params, "?cmd=relayA1") == 0)
    {
      digitalWrite(relayPinA, HIGH);
    }
    if (strcmp(params, "?cmd=relayB0") == 0)
    {
      digitalWrite(relayPinA, LOW);
    }
    if (strcmp(params, "?cmd=relayB1") == 0)
    {
      digitalWrite(relayPinA, HIGH);
    }
    if (strcmp(params, "?cmd=relayC0") == 0)
    {
      digitalWrite(relayPinA, LOW);
    }
    if (strcmp(params, "?cmd=relayC1") == 0)
    {
      digitalWrite(relayPinA, HIGH);
    }
    if (strcmp(params, "?cmd=relayD0") == 0)
    {
      digitalWrite(relayPinA, LOW);
    }
    if (strcmp(params, "?cmd=relayD1") == 0)
    {
      digitalWrite(relayPinA, HIGH);
    }
    e.respond();
  }
}


