#include <stdio.h>


// Progress (in order of occurrence):
//  Niko Procopi
//	Pin toggling system
//	mapPinToAction based on fixed-number threshold
//  Hillary Li
//	mapPinToAction based on percentage between min and max inputs of one pin
//  Niko Procopi
//	created min and max arrays, for all pins we use
//	program waits until it collects legitimate data before using the data

#define numPins 20
int minValue[numPins];
int maxValue[numPins];

int enablePin(int pin)
{
  pinMode(pin, OUTPUT);  
}

void disablePin(int pin)
{
  pinMode(pin, INPUT);  
}

void mapPinToAction(int inputPin, int outputPin, int triggerPercent)
{
  int x = analogRead(inputPin);
  int i = outputPin;

  if(x < minValue[i])
	minValue[i] = x;
 
  if(x > maxValue[i])
	maxValue[i] = x;

  int y = map(x, minValue[i], maxValue[i], 0, 100);

  if(y > triggerPercent)
	enablePin(outputPin);
  else
	disablePin(outputPin);
}

void setup()
{
  for(int i = 0; i < numPins; i++)
  {
	// This is default garbage
	// That will be overwritten
	// as soon as we collect data
	minValue[i] = 1024;
	maxValue[i] = 0;  
  }
}

void loop()
{
  // 0 is back
  // 1 is forward
  // 2 is left
  // 3 is right

  // back
  // left shoulder
  mapPinToAction(A2, 0, 85);
 
  // forward
  // left arm
  mapPinToAction(A3, 1, 95);
 
  // left
  // right shoulder
  mapPinToAction(A4, 2, 80);
 
  // right
  // right arm
  mapPinToAction(A5, 3, 80);
}




