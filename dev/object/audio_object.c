#include "audio_object.h"
#include "../banks/bank4.h"
#include "../banks/bank5.h"
#include "../banks/bank6.h"
#include "../banks/bank7.h"
#include "../banks/bank8.h"
#include "../banks/bank9.h"
#include "../banks/bank10.h"
#include "../banks/bank11.h"
#include "../banks/bank12.h"
#include "../banks/bank13.h"
#include "../banks/bank14.h"

const unsigned char *music_sample_data[] =
{
	Intro01_wav_pcmenc,
	Intro02_wav_pcmenc,
	Intro03_wav_pcmenc,
	Intro04_wav_pcmenc,
	Intro05_wav_pcmenc,
	Boss01_wav_pcmenc,
	Boss02_wav_pcmenc,
	Boss03_wav_pcmenc,
	Over01_wav_pcmenc,
	Over02_wav_pcmenc,
};

const unsigned char music_sample_bank[] =
{
	Intro01_wav_pcmenc_bank,
	Intro02_wav_pcmenc_bank,
	Intro03_wav_pcmenc_bank,
	Intro04_wav_pcmenc_bank,
	Intro05_wav_pcmenc_bank,
	Boss01_wav_pcmenc_bank,
	Boss02_wav_pcmenc_bank,
	Boss03_wav_pcmenc_bank,
	Over01_wav_pcmenc_bank,
	Over02_wav_pcmenc_bank,
};

const unsigned char *sound_sample_data[] =
{
	sound0_psg,
	sound1_psg,
	sound2_psg,
	sound3_psg,
	sound4_psg,
	sound5_psg,
	sound6_psg,
	sound7_psg,
	sound8_psg,
	sound9_psg,
	sound10_psg,
	sound11_psg,
};

const unsigned char sound_sample_bank[] =
{
	sound0_psg_bank,
	sound1_psg_bank,
	sound2_psg_bank,
	sound3_psg_bank,
	sound4_psg_bank,
	sound5_psg_bank,
	sound6_psg_bank,
	sound7_psg_bank,
	sound8_psg_bank,
	sound9_psg_bank,
	sound10_psg_bank,
	sound11_psg_bank,
};