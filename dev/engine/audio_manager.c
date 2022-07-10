#include "audio_manager.h"
#include "enum_manager.h"
#include "hack_manager.h"
#include "sample_manager.h"
#include "../object/audio_object.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../content/psg.h"
#include <stdlib.h>

const unsigned char psgInit[] =
{
	0x9F, 0xBF, 0xDF, 0xFF, 0x81, 0x00, 0xA1, 0x00, 0x00, 0xC1, 0x00
};

void engine_sound_manager_init()
{
	engine_sample_manager_init( psgInit );
}

void engine_sound_manager_play( unsigned char index )
{
	struct_hack_object *ho = &global_hack_object;
	const unsigned char *data;
	unsigned char bank;

	data = sound_sample_data[ index ];
	bank = sound_sample_bank[ index ];

	if( !ho->hack_sounds )
	{
		return;
	}

	devkit_SMS_mapROMBank( bank );
	devkit_PSGSFXPlay( ( void * ) data, devkit_SFX_CHANNEL2() );
}

void engine_sound_manager_fight()
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char index = rand() % 5;

	if( !ho->hack_sounds )
	{
		return;
	}

	engine_sound_manager_play( index );
}

void engine_sound_manager_kill()
{
	struct_hack_object *ho = &global_hack_object;
	if( !ho->hack_sounds )
	{
		return;
	}

	devkit_PSGSFXPlay( ( void * ) sfx_death_psg, devkit_SFX_CHANNEL2() );
}

void engine_music_manager_play( unsigned char index )
{
	struct_hack_object *ho = &global_hack_object;
	const unsigned char *data;
	unsigned char bank;

	data = music_sample_data[ index ];
	bank = music_sample_bank[ index ];

	if( !ho->hack_musics )
	{
		return;
	}

	devkit_SMS_mapROMBank( bank );
	engine_sample_manager_play( data );
}

void engine_music_manager_beat()
{
	struct_hack_object *ho = &global_hack_object;
	const unsigned char *data;
	unsigned char bank;

	// Beat screen music although in sound bank!
	data = sound_sample_data[ sound_type_11 ];
	bank = sound_sample_bank[ sound_type_11 ];

	if( !ho->hack_musics )
	{
		return;
	}

	devkit_SMS_mapROMBank( bank );
	devkit_PSGPlayNoRepeat( ( void * ) data );
}