#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <queue>
#include <map>
#include <string>
#include <cstring>

#include <graphviz/cgraph.h>

#define DEBUG FALSE

void goUp (Agraph_t* g, Agnode_t* node);


int charsToInt(char* s);

int attrIntFromNode(Agnode_t* node, Agsym_t* attribute);


void outAsDot(Agraph_t* g);

#endif /* MAIN_H_ */
