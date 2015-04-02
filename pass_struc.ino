// arduino struct definitions must be in a separate file
// or the compiler can't find them in time.
#include "MyTYpes.h"

ctlrResults_t ctlrResults;  // This is a global variable

void setup () {
 do_something( &ctlrResults ); // pass the address (pointer) to ctlrResults to the function
 Serial.begin(115200);
 Serial.print("Raw Results:");
 Serial.println(ctlrResults.raw_result);
}

void loop() {
  
  ctlrResults = dodo();
  Serial.print(ctlrResults.raw_result);
  Serial.print(",");
  Serial.println(ctlrResults.cmd_results[0]);
  delay(1000);

}

void do_something( ctlrResults_t* r ) { // input to function is a pointer to r not values stored in r
 // here the function input (pointer) tells us where to store the output
 // since we have the pointer to r, we use the arrow de-reference operator
 // r->cmd_ACK is the same as (*r).cmd_ACK but "clearer" 
 // r-> can be thought of as the thing that r points to...
 r->cmd_ACK = 1; // since we have the pointer we can change the value
 r->raw_result = "M1:323:M2:435";
 r->cmd_results[0] = 323;
 r->cmd_results[1] = 435;
}

// This has the result as something to return
// it is not as efficient perhaps, as the structure must be copied
ctlrResults_t dodo()
{
   ctlrResults_t a;
   a.cmd_ACK = 1;
   a.raw_result = "so smart";
   a.cmd_results[0] = 123;
   a.cmd_results[1] = 456;
   return a;
}
