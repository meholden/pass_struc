// This stuff has to be in a separate file to work with arduino
#ifndef MyTypes_h
#define MyTypes_h

#include <WString.h> // to have the String type available

// this defines a struct named ctrlResults_t and makes it a variable type
typedef struct {
 int cmd_ACK;
 String raw_result;
 int cmd_results[8];
} ctlrResults_t;

#endif
