

#include "Si446x.h"

si446x_info_t info; 

void setup()
{
	Serial.begin(115200);

	pinMode(A5, OUTPUT); // LED

	Si446x_init();
}


void loop()
{

  Si446x_getInfo(&info); 
  Serial.println(info.chipRev, HEX);
  Serial.println(info.part, HEX); 
	delay(1000);	
}
