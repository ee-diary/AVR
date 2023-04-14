#ifndef F_CPU
#define FCPU 4000000UL
#endif


#include <avr/io.h>
#include <util/delay.h>

int main()
 { 
    lcdinit();
    adcinit();

    char Ctemp[10], Ftemp[10];

	float c, f;
	lcdstr("***Temperature***");

   while(1){
		c = (adcread(0)*4.88);
		c = (c/10.00);
        f = (c*9)/5 + 32;

		dtostrf(c, 6, 2, Ctemp);
		dtostrf(f, 5, 2, Ftemp);

		lcdgoto(0,2);
		lcdstr(Ctemp);
		lcdchar(0xDF); 
	    lcdstr("C");
	    lcdstr("(");
	    lcdstr(Ftemp);
		lcdchar(0xDF); 
	    lcdstr("F)");
      }
   return 0;
 }