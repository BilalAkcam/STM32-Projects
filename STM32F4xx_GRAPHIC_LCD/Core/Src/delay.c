#include "delay.h"

void delay_ns(unsigned int d){	/* Not exact value, for 168 MHz @ Level3 Opt */
	unsigned int i;
	i=d/25;while(i)i--;
}

void delay_us(unsigned int d){	/* for 168 MHz @ Level3 Opt */
	unsigned int i,j;
	i=d;while(i){i--;j=55;while(j)j--;}
}

void delay_ms(unsigned int d){	/* for 168 MHz @ Level3 Opt */
	unsigned int i;
	i=d;while(i){i--;delay_us(998);}
}
