#ifndef MANIP_H
#define MANIP_H

// Author: Todd Herron
// Source File: manip.h
// Description: A set of functions where you should manipulate
// the passed parameters to change the object in a specific way, 
// so that Pointers_test.h passes all tests.

#include "Pointers.h"

// A little something to get you going
void manip1(Pointers* p){
  *(p->getA()) = 10;
}

void manip2(Pointers* p){
  // TODO: Fill me in
  *(*p).getB() = 45;
}

void manip3(Pointers* p){
  // TODO: Fill me in
  *(*p).getB() = 383;
}

void manip4(Pointers* p, int* other){
  // TODO: Fill me in
  (*p).setB(other);
}

void manip5(Pointers* p, int* other){
  // TODO: Fill me in
  *other = 45;
  (*p).setB(other);
  (*p).setC();
}

void manip6(Pointers* p){
  // TODO: Fill me in
  *((*p).getB() + 2) = 10;
}

void manip7(Pointers* p){
  // TODO: Fill me in
  *(*p).getB() = 15;
}

void manip8(Pointers* p){
  // TODO: Fill me in
  *(*p).getA() = 199;
  (*p).setB((*p).getA());
  (*p).setC();
}

void manip9(Pointers* p, int* other){
  // TODO: Fill me in
  (*p).setB(other);
}

void manip10(Pointers* p){
  // TODO: Fill me in
  *p[5].getA() = 199;
  p[5].setB(p[5].getA());
  p[5].setC();
}

#endif
