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

	// set I2S_IN -> Dac & ADC -> DAP -> I2S_OUT
	// DAP will pass through until AVC turned on
	sgtl5000.audioPreProcessorEnable();
	
	// 0-1, 1 is max
	sgtl5000.dacVolume(.7);
	// 31-13, 13 is max
	sgtl5000.lineOutLevel(31);

	// AUDIO_INPUT_LINEIN or AUDIO_INPUT_MIC
	sgtl5000.inputSelect(AUDIO_INPUT_LINEIN);
	// ADC Gain  0-15, 15 is loudest, match to input voltage
	sgtl5000.lineInLevel(2);

	// set DAP input mixer
	sgtl5000.dapMix(0.5,0);
	
	// set up DAP AVC
	sgtl5000.autoVolumeControl(2,1,0,0,3,20);
	// turn on AVC in the DAP
	sgtl5000.autoVolumeEnable();
	
	// turn on DAP eqBands
	sgtl5000.eqSelect(3);
	// each band adjusted by signed percentage -100/+100
	sgtl5000.eqBands(0.0,0.0,0.0,0.0,0.0);
		
	// disable DAP bass boost but use High Pass Filter
	// 0 is lowest cutoff, 6 is highest
	sgtl5000.enhanceBass(0.0,0.0,0.0,6);
	
	bcm2835_i2c_end();
}
