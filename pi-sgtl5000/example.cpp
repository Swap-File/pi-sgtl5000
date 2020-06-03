#include <stdio.h>
#include <unistd.h>
#include <bcm2835.h>

#include "control_sgtl5000.h"

AudioControlSGTL5000 sgtl5000;

int main(void)
{
	if (getuid()) {
		printf("i2c access via bcm2835 requires root!\n");
		exit(1);
	}
	
	bcm2835_init();
	bcm2835_i2c_begin();
	
	printf("Mute On\n");
	sgtl5000.dacVolume(0.0,0.0);
	
	delay(2000);
	
	printf("Mute Off\n");
	sgtl5000.dacVolume(10.0,10.0);
	
	bcm2835_i2c_end();
}
