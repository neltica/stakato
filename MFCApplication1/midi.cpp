#pragma once
#include "stdafx.h"
#include "midi.h"

//#include "MidiStruct.h"
#include <mmsystem.h>
#include <conio.h>

#define HINYBBLE(a)		((a) >> 4)
#define LONYBBLE(a)		((a) & 15)
#define MAKEBYTE(l,h)	((l) | ((h) << 4))

#define MAX_MIDI_WAIT	1000.0f	// Max # of milliseconds to sleep in main playback loop
#define MAX_MIDI_TRACKS	512		// Max # of tracks TMIDI will read from a MIDI file

#define MAX_PITCH_BEND	0x2000	// Max value for pitch bends (this is a MIDI constant, do not change!)

#define MIDI_STANDARD_NONE		1
#define MIDI_STANDARD_GM		2
#define MIDI_STANDARD_GS		4
#define MIDI_STANDARD_XG		8
#define MIDI_STANDARD_MT32		16

#define WMAPP_LOADFILE			(WM_APP + 1)
#define WMAPP_DONE_PLAYING		(WM_APP + 2)
#define WMAPP_REFRESH_CHANNELS	(WM_APP + 3)

// Inter-process communication messages
#define IPC_PLAY	0

// Pitch bar dimensions
//#define BAR_X		170
//#define BAR_Y		55 //79
//#define BAR_WIDTH	93
//#define BAR_HEIGHT	10
//#define BAR_VSPACE	18

#define BAR_X		180 //170
#define BAR_Y		51 //79
#define BAR_WIDTH	93
#define BAR_HEIGHT	15
#define BAR_VSPACE	18

#define MAX_NOTE_HEIGHT		(BAR_HEIGHT - 2)


char *program_categories[] = {

	"Piano",
	"Chromatic Percussion",
	"Organ",
	"Guitar",
	"Bass",
	"Strings",
	"Ensemble",
	"Brass",
	"Reed",
	"Pipe",
	"Synth Lead",
	"Synth Pad",
	"Synth Effects",
	"Ethnic",
	"Percussive",
	"Sound Effects"

};

char *mt32_program_names[] = {

	"Acou Piano 1", 
	"Acou Piano 2", 
	"Acou Piano 3", 
	"Elec Piano 1", 
	"Elec Piano 2", 
	"Elec Piano 3", 
	"Elec Piano 4", 
	"Honkytonk", 
	"Elec Org 1", 
	"Elec Org 2", 
	"Elec Org 3", 
	"Elec Org 4", 
	"Pipe Org 1", 
	"Pipe Org 2", 
	"Pipe Org 3", 
	"Accordion", 
	"Harpsi 1", 
	"Harpsi 2", 
	"Harpsi 3", 
	"Clavi 1", 
	"Clavi 2", 
	"Clavi 3", 
	"Celesta 1", 
	"Celesta 2", 
	"Syn Brass 1", 
	"Syn Brass 2", 
	"Syn Brass 3", 
	"Syn Brass 4", 
	"Syn Bass 1", 
	"Syn Bass 2", 
	"Syn Bass 3", 
	"Syn Bass 4", 
	"Fantasy", 
	"Harmo Pan", 
	"Chorale", 
	"Glasses", 
	"Soundtrack", 
	"Atmosphere", 
	"Warm Bell", 
	"Funny Vox", 
	"Echo Bell", 
	"Ice Rain", 
	"Oboe 2001", 
	"Echo Pan", 
	"Doctor Solo", 
	"Schooldaze", 
	"Bellsinger", 
	"Square Wave", 
	"Str Sect 1", 
	"Str Sect 2", 
	"Str Sect 3", 
	"Pizzicato", 
	"Violin 1", 
	"Violin 2", 
	"Cello 1", 
	"Cello 2", 
	"Contrabass", 
	"Harp 1", 
	"Harp 2", 
	"Guitar 1", 
	"Guitar 2", 
	"Elec Gtr 1", 
	"Elec Gtr 2", 
	"Sitar", 
	"Acou Bass 1", 
	"Acou Bass 2", 
	"Elec Bass 1", 
	"Elec Bass 2", 
	"Slap Bass 1", 
	"Slap Bass 2", 
	"Fretless 1", 
	"Fretless 2", 
	"Flute 1", 
	"Flute 2", 
	"Piccolo 1", 
	"Piccolo 2", 
	"Recorder", 
	"Pan Pipes", 
	"Sax 1", 
	"Sax 2", 
	"Sax 3", 
	"Sax 4", 
	"Clarinet 1", 
	"Clarinet 2", 
	"Oboe", 
	"Engl Horn", 
	"Bassoon", 
	"Harmonica", 
	"Trumpet 1", 
	"Trumpet 2", 
	"Trombone 1", 
	"Trombone 2", 
	"Fr Horn 1", 
	"Fr Horn 2", 
	"Tuba", 
	"Brs Sect 1", 
	"Brs Sect 2", 
	"Vibe 1", 
	"Vibe 2", 
	"Syn Mallet", 
	"Windbell", 
	"Glock", 
	"Tube Bell", 
	"Xylophone", 
	"Marimba", 
	"Koto", 
	"Sho", 
	"Shakuhachi", 
	"Whistle 1", 
	"Whistle 2", 
	"Bottleblow", 
	"Breathpipe", 
	"Timpani", 
	"Melodic Tom", 
	"Deep Snare", 
	"Elec Perc 1", 
	"Elec Perc 2", 
	"Taiko", 
	"Taiko   Rim", 
	"Cymbal", 
	"Castanets", 
	"Triangle", 
	"Orche Hit", 
	"Telephone", 
	"Bird Tweet", 
	"One Note Jam", 
	"Water Bells", 
	"Jungle Tune"

};

char *midi_text_event_descriptions[] = {

	"Text",
	"Text",
	"Copyright text",
	"Sequence or track name",
	"Track instrument name",
	"Lyric",
	"Marker",
	"Cue point"

};

char *controller_names[] = {

	"Bank Select",
	"Modulation Wheel",
	"Breath controller",
	"Unknown controller",
	"Foot Pedal",
	"Portamento Time",
	"Data Entry",
	"Volume",
	"Balance",
	"Unknown controller",
	"Pan position",
	"Expression",
	"Effect Control 1",
	"Effect Control 2",
	"Unknown controller",
	"Unknown controller",
	"General Purpose Slider 1",
	"General Purpose Slider 2",
	"General Purpose Slider 3",
	"General Purpose Slider 4",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Bank Select (fine)",
	"Modulation Wheel (fine)",
	"Breath controller (fine)",
	"Unknown controller",
	"Foot Pedal (fine)",
	"Portamento Time (fine)",
	"Data Entry (fine)",
	"Volume (fine)",
	"Balance (fine)",
	"Unknown controller",
	"Pan position (fine)",
	"Expression (fine)",
	"Effect Control 1 (fine)",
	"Effect Control 2 (fine)",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Hold Pedal (on/off)",
	"Portamento (on/off)",
	"Sustenuto Pedal (on/off)",
	"Soft Pedal (on/off)",
	"Legato Pedal (on/off)",
	"Hold 2 Pedal (on/off)",
	"Sound Variation",
	"Sound Timbre",
	"Sound Release Time",
	"Sound Attack Time",
	"Sound Brightness",
	"Sound Decay Time",
	"Sound Vibrato Rate",
	"Sound Vibrato Depth",
	"Sound Vibrato Delay",
	"Sound Control 10",
	"General Purpose Button 1 (on/off)",
	"General Purpose Button 2 (on/off)",
	"General Purpose Button 3 (on/off)",
	"General Purpose Button 4 (on/off)",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Effects Level",
	"Tremolo Level",
	"Chorus Level",
	"Celeste Level",
	"Phaser Level",
	"Data Button increment",
	"Data Button decrement",
	"Non-registered Parameter (fine)",
	"Non-registered Parameter (coarse)",
	"Registered Parameter (fine)",
	"Registered Parameter (coarse)",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"Unknown controller",
	"All Sound Off",
	"All Controllers Off",
	"Local Keyboard (on/off)",
	"All Notes Off",
	"Omni Mode Off",
	"Omni Mode On",
	"Mono Operation",
	"Poly Operation"

};

char *common_controller_names[] = {

	"7 - Volume",
	"11 - Expression",
	"10 - Pan position",
	"1 - Modulation Wheel",
	"64 - Hold Pedal (on/off)",
	"91 - Effects Level",
	"93 - Chorus Level"

};

char *gm_program_names[] = {

	"Acoustic Grand Piano",
	"Bright Acoustic Piano",
	"Electric Grand Piano",
	"Honky-tonk Piano",
	"Electric Piano 1",
	"Electric Piano 2",
	"Harpsichord",
	"Clavi",
	"Celesta",
	"Glockenspiel",
	"Music Box",
	"Vibraphone",
	"Marimba",
	"Xylophone",
	"Tubular Bells",
	"Dulcimer",
	"Drawbar Organ",
	"Percussive Organ",
	"Rock Organ",
	"Church Organ",
	"Reed Organ",
	"Accordion",
	"Harmonica",
	"Tango Accordion",
	"Acoustic Guitar (nylon)",
	"Acoustic Guitar (steel)",
	"Electric Guitar (jazz)",
	"Electric Guitar (clean)",
	"Electric Guitar (muted)",
	"Overdriven Guitar",
	"Distortion Guitar",
	"Guitar harmonics",
	"Acoustic Bass",
	"Electric Bass (finger)",
	"Electric Bass (pick)",
	"Fretless Bass",
	"Slap Bass 1",
	"Slap Bass 2",
	"Synth Bass 1",
	"Synth Bass 2",
	"Violin",
	"Viola",
	"Cello",
	"Contrabass",
	"Tremolo Strings",
	"Pizzicato Strings",
	"Orchestral Harp",
	"Timpani",
	"String Ensemble 1",
	"String Ensemble 2",
	"SynthStrings 1",
	"SynthStrings 2",
	"Choir Aahs",
	"Voice Oohs",
	"Synth Voice",
	"Orchestra Hit",
	"Trumpet",
	"Trombone",
	"Tuba",
	"Muted Trumpet",
	"French Horn",
	"Brass Section",
	"SynthBrass 1",
	"SynthBrass 2",
	"Soprano Sax",
	"Alto Sax",
	"Tenor Sax",
	"Baritone Sax",
	"Oboe",
	"English Horn",
	"Bassoon",
	"Clarinet",
	"Piccolo",
	"Flute",
	"Recorder",
	"Pan Flute",
	"Blown Bottle",
	"Shakuhachi",
	"Whistle",
	"Ocarina",
	"Lead 1 (square)",
	"Lead 2 (sawtooth)",
	"Lead 3 (calliope)",
	"Lead 4 (chiff)",
	"Lead 5 (charang)",
	"Lead 6 (voice)",
	"Lead 7 (fifths)",
	"Lead 8 (bass + lead)",
	"Pad 1 (new age)",
	"Pad 2 (warm)",
	"Pad 3 (polysynth)",
	"Pad 4 (choir)",
	"Pad 5 (bowed)",
	"Pad 6 (metallic)",
	"Pad 7 (halo)",
	"Pad 8 (sweep)",
	"FX 1 (rain)",
	"FX 2 (soundtrack)",
	"FX 3 (crystal)",
	"FX 4 (atmosphere)",
	"FX 5 (brightness)",
	"FX 6 (goblins)",
	"FX 7 (echoes)",
	"FX 8 (sci-fi)",
	"Sitar",
	"Banjo",
	"Shamisen",
	"Koto",
	"Kalimba",
	"Bag pipe",
	"Fiddle",
	"Shanai",
	"Tinkle Bell",
	"Agogo",
	"Steel Drums",
	"Woodblock",
	"Taiko Drum",
	"Melodic Tom",
	"Synth Drum",
	"Reverse Cymbal",
	"Guitar Fret Noise",
	"Breath Noise",
	"Seashore",
	"Bird Tweet",
	"Telephone Ring",
	"Helicopter",
	"Applause",
	"Gunshot"

};
char *sysex_manufacturer_names[] = {
	"126 - GM", 
	"127 - (All)", 
	"125 - (Private Use)", 
	"64 - Kawai",
	"65 - Roland",
	"66 - Korg", 
	"67 - Yamaha",
	"68 - Casio",
	"70 - Kamiya Studio",
	"71 - Akai",
	"72 - Victor",
	"75 - Fujitsu",
	"76 - Sony",
	"78 - Teac",
	"80 - Matsushita",
	"81 - Fostex",
	"82 - Zoom",
	"84 - Matsushita",
	"85 - Suzuki",
	"86 - Fuji",
	"87 - Acoustic Technical Laboratory"
};

char *drum_kit_names[] = {

	"0 - Standard",
	"1 - Standard 2",
	"2 - Standard L/R",
	"8 - Room",
	"9 - Hip Hop",
	"10 - Jungle",
	"11 - Techno",
	"12 - Room L/R",
	"13 - House",
	"16 - Power",
	"24 - Electronic",
	"25 - TR-808",
	"26 - Dance",
	"27 - CR-78",
	"28 - TR-606",
	"29 - TR-707",
	"30 - TR-909",
	"32 - Jazz",
	"33 - Jazz L/R",
	"40 - Brush",
	"41 - Brush 2",
	"42 - Brush 2 L/R",
	"48 - Orchestra",
	"49 - Ethnic",
	"50 - Kick && Snare",
	"51 - Kick && Snare 2",
	"52 - Asia",
	"53 - Cymbal && Claps",
	"54 - Gamelan",
	"55 - Gamelan 2",
	"56 - SFX",
	"57 - Rhythm FX",
	"58 - Rhythm FX 2",
	"59 - Rhythm FX 3",
	"60 - SFX 2",
	"61 - Voice",
	"62 - Cymbal && Claps 2",
	"127 - CM-64/32"

};
midi::midi(void)
{
	//start initialize
	memset(&ghInstance,0,sizeof(HINSTANCE));
	memset(&hwndApp,0,sizeof(HWND));
	memset(&hwndText,0,sizeof(HWND));
	memset(&hwndStatusBar,0,sizeof(HWND));
	memset(&key,0,sizeof(HKEY));
	memset(&g_hhk,0,sizeof(HHOOK));
	memset(&g_hwndTT,0,sizeof(HWND));
	memset(temp_dir,0,sizeof(char)*MAX_PATH);
	memset(analysis_file,0,sizeof(char)*MAX_PATH);
	memset(&filename_to_load,0,sizeof(char)*MAX_PATH);

	// GDI resources
	memset(&hNoteBackgroundBrush,0,sizeof(HBRUSH));
	memset(&hControllerBrush,0,sizeof(HBRUSH));
	memset(&hNoteBackgroundPen,0,sizeof(HPEN));
	memset(&hControllerFont,0,sizeof(HFONT));
	memset(&hJapaneseFont,0,sizeof(HFONT));

	// Tracks window variables
	memset(&hwndTracks,0,sizeof(HWND));
	memset(&tracksLastValuesSet,0,sizeof(int));

	// Channels window variables
	memset(&hwndChannels,0,sizeof(HWND));
	memset(&channelsLastValuesSet,0,sizeof(int));

	// Sysex window variables
	memset(&hwndSysex,0,sizeof(HWND));
	memset(&sysexLastValuesSet,0,sizeof(int));

	// Settings saved in the registry
	memset(&midi_in_cb,0,sizeof(int));
	memset(&midi_out_cb,0,sizeof(int));
	memset(&appRectSaved,0,sizeof(int));
	memset(&textRectSaved,0,sizeof(int));
	memset(&tracksRectSaved,0,sizeof(int));
	memset(&channelsRectSaved,0,sizeof(int));
	memset(&sysexRectSaved,0,sizeof(int));
	memset(&genericTextRectSaved,0,sizeof(int));
	memset(&appRect,0,sizeof(RECT));
	memset(&textRect,0,sizeof(RECT));
	memset(&tracksRect,0,sizeof(RECT));
	memset(&channelsRect,0,sizeof(RECT));
	memset(&sysexRect,0,sizeof(RECT));
	memset(&genericTextRect,0,sizeof(RECT));
	memset(&alwaysCheckAssociations,0,sizeof(int));

	// MIDI I/O handles
	memset(&hin,0,sizeof(HMIDIIN));
	memset(&hout,0,sizeof(HMIDIIN));

	// Timing variables
	memset(&LIfreq,0,sizeof(LARGE_INTEGER));
	memset(&LIms_time,0,sizeof(LARGE_INTEGER));
	memset(&freq,0,sizeof(int));
	memset(&hr_ms_time,0,sizeof(int));


	memset(&midi_devices,0,sizeof(midi_device_t));
	memset(&playlist,0,sizeof(playlist_t));
	memset(&playback_head,0,sizeof(playlist_t));
	memset(&mh,0,sizeof(midi_header_t));
	memset(&th,0,sizeof(track_header_t)*MAX_MIDI_TRACKS);
	memset(&ms,0,sizeof(midi_state_t));
	memset(&midi_text_events,0,sizeof(midi_text_t));
	memset(&midi_sysex_events,0,sizeof(midi_sysex_t));
	memset(mt32_patch_groups,0,sizeof(char)*128);
	memset(mt32_patch_programs,0,sizeof(char)*128);
	memset(mt32_memory_names,0,sizeof(char)*64*11);
	memset(&program_names,0,sizeof(char**));
	memset(track,0,sizeof(int)*16);
	track_count = 0;

	//end initializes



	ghInstance = NULL;
	hwndApp = NULL;
	hwndText = NULL;
	hwndStatusBar = NULL;
	temp_dir[0] = '\0';
	analysis_file[0] = '\0';
	filename_to_load[0] = '\0';
	hNoteBackgroundBrush = NULL;
	hControllerBrush = NULL;
	hNoteBackgroundPen = NULL;
	hControllerFont = NULL;
	hJapaneseFont = NULL;
	hwndTracks = NULL;
	tracksLastValuesSet = 0;
	hwndChannels = NULL;
	channelsLastValuesSet = 0;
	hwndSysex = NULL;
	sysexLastValuesSet = 0;
	midi_in_cb = 0;
	midi_out_cb = 0;
	appRectSaved = 0;
	textRectSaved = 0;
	tracksRectSaved = 0;
	channelsRectSaved = 0;
	sysexRectSaved = 0;
	genericTextRectSaved = 0;
	alwaysCheckAssociations = 1;
	hin = NULL;
	hout = NULL;
	midi_devices = NULL;		// MIDI devices
	playlist = NULL;			// Playlist
	playback_head = NULL;		// Pointer to playlist entry currently being played (or last played)
	midi_text_events = NULL;	// MIDI text events
	midi_sysex_events = NULL;	// MIDI sysex events
	midi::program_names = gm_program_names;
}


midi::~midi(void)
{
}

unsigned short int midi::read_short(FILE *fp)
{
	unsigned char high, low;

	high = fgetc(fp);
	low = fgetc(fp);
	return MAKEWORD(low, high);
}
unsigned int midi::read_int(FILE *fp)
{
	unsigned short high, low;

	high = read_short(fp);
	low = read_short(fp);

	return ((high << 16) + low);
}
int midi::read_bytes(FILE *fp, unsigned char *buf, int num)
{
	return fread(buf, num, 1, fp);
}
void midi::all_notes_off_channel(int channel)
{
	// Clear saved note velocities for this channel
	memset(&ms.channels[channel].notes, 0, 128);
	ms.channels[channel].note_count = 0;
	// Turn off notes on the MIDI-out device
	if (hout)
	{
		// Better safe than sorry!
		midiOutShortMsg(hout, MAKELONG(MAKEWORD(0xB0 + channel, 120), MAKEWORD(0, 0)));
		midiOutShortMsg(hout, MAKELONG(MAKEWORD(0xB0 + channel, 121), MAKEWORD(0, 0)));
		midiOutShortMsg(hout, MAKELONG(MAKEWORD(0xB0 + channel, 123), MAKEWORD(0, 0)));
	}
}
void midi::all_notes_off(void)
{
	int c;

	for (c = 0; c < 16; c++)
		all_notes_off_channel(c);
}
char *midi::stristr(char *src, char *target)
{
	char *found = NULL;	// pointer to beginning of matched string
	char *sp;			// search pointer
	char *tp;			// target pointer

	// We don't like null pointers
	if (!src || !target)
		return NULL;

	// Loop through the source text
	while (*src)
	{
		sp = src;
		tp = target;
		found = NULL;
		// Search for an exact match from the current point in src
		while (*sp && *tp)
		{
			// Compare what we are looking at and what we want
			if (tolower(*sp) == tolower(*tp))
			{
				// If we match two chars for the first time, mark this spot
				if (!found)
					found = sp;
			}
			else
			{
				// If we haven't reached the end of the target..
				if (*tp)
					found = NULL;	// ...we haven't found the target
				break;
			}
			// Move on to compare the next chars
			sp++;
			tp++;
		}
		// If we found a matching string, return a pointer to its start
		if (found && !(*tp))
			return found;
		// Move on to the next char in src
		src++;
	}

	// We've reached the end of src without finding anything
	return NULL;
}
void midi::set_mod_velocity(signed int i)
{
	char buf[256];

	ms.mod_velocity = i;
	//SendDlgItemMessage(hwndApp, IDC_VELOCITY_SLIDER, TBM_SETPOS, TRUE, 64 + i);
	sprintf(buf, "Velocity: %d", i);
	//SetDlgItemText(hwndApp, IDC_VELOCITY, buf);
}
void midi::set_mod_pitch(signed int i)
{
	char buf[256];

	if (i != ms.mod_pitch)
		all_notes_off();
	ms.mod_pitch = i;
	//SendDlgItemMessage(hwndApp, IDC_PITCH_SLIDER, TBM_SETPOS, TRUE, 24 + i);
	sprintf(buf, "Pitch: %d", i);
	//SetDlgItemText(hwndApp, IDC_PITCH, buf);
}
void midi::output_sysex_data(unsigned char channel, unsigned char *data, int length)
{
	MIDIHDR mh;
	static unsigned char *buf = (unsigned char *) malloc(256);
	int buflen = 256;

	if (!hout)
		return;

	// Realloc the sysex buffer if it's too small
	if (length + 2 > buflen)
	{
		buflen = length + 32;
		buf = (unsigned char *) realloc(buf, buflen);
	}

	buf[0] = 0xF0;					// Sysex begin command
	memcpy(buf + 1, data, length);	// Copy the sysex data into the local sysex buffer

	// Prepare the MIDI out header
	memset(&mh, 0, sizeof(mh));
	mh.lpData = (char *) buf;
	mh.dwBufferLength = length + 1;
	mh.dwBytesRecorded = length + 1;
	// Prepare the sysex buffer for output
	midiOutPrepareHeader(hout, &mh, sizeof(mh));

	// Send the sysex buffer!
	midiOutLongMsg(hout, &mh, sizeof(mh));

	// Unprepare the sysex buffer
	midiOutUnprepareHeader(hout, &mh, sizeof(mh));
}
char *midi::get_drum_kit_name(int program)
{
	int i;
	char *ch;
	static char buf[256];

	for (i = 0; i < sizeof(drum_kit_names) / sizeof(char *); i++)
		if (atoi(drum_kit_names[i]) == program)
			break;
	if (i == sizeof(drum_kit_names) / sizeof(char *))
		sprintf(buf, "Unknown drum kit (%d)", program);
	else
	{
		ch = strchr(drum_kit_names[i], '-');
		strcpy(buf, ch + 2);
	}

	return buf;
}
char *midi::get_program_name(unsigned char program, unsigned char bank)
{
	static char name[256];

	assert(program >= 0 && program <= 127);

	switch (ms.midi_standard)
	{
	case MIDI_STANDARD_MT32:
		switch (mt32_patch_groups[program])
		{
		case 2:		// Memory patch
			if (mt32_patch_programs[program] < 64)
				return mt32_memory_names[mt32_patch_programs[program]];
		case 3:
			sprintf(name, "Rhythm patch %d", mt32_patch_programs[program]);
			return name;
		default:
			return mt32_program_names[mt32_patch_programs[program]];
		}
	default:
		if (bank == 0 || bank == 255)
			return gm_program_names[program];
		sprintf(name, "%s - BK%d", gm_program_names[program], bank);
		return name;
	}
}
void midi::set_channel_program(int channel, int program, int bank)
{
	int i;
	printf("%d , %d , %d\n",channel,program,bank);
	assert(channel < 16);
	assert(program < 128);
	printf("asee __ %d , %d , %d\n",channel,program,bank);
	if (hout)
		midiOutShortMsg(hout, MAKELONG(MAKEWORD(MAKEBYTE(channel, 0x0C), program), MAKEWORD(0, 0)));
	
	if (channel != 9)
	{
		for(i = 0 ; i < track_count;i++)
		{
			if(track[i] == channel)
				break;
		}
		if(track_count==i)
		{
			track[track_count] = channel;
			track_program[track_count] = program;
			track_count++;
			printf("channel = %d\n",channel);
			printf("name = %s\n", get_program_name(program, bank));
			//printf를 변환시켜서 UI적으로 반영(리스트박스)
		}
		else
		{
			track_program[i] = program;
			printf("channel = %d\n",i);
			printf("name = %s\n", get_program_name(program, bank));
			//printf를 변환시켜서 UI적으로 반영(리스트박스)
		}
		printf("9set_channel IDC_TO+channel = %d , name = %s\n",  channel, get_program_name(program, bank));
	//SetDlgItemText(hwndApp, IDC_T0 + channel, get_program_name(program, bank));
	}
	else
	{
		printf("-set_channel IDC_TO+channel = %d , name = %s\m",  channel, get_drum_kit_name(program));
	//SetDlgItemText(hwndApp, IDC_T0 + channel, get_drum_kit_name(program));
	}
}
char midi::interpret_sysex_part(unsigned char c)
{
	char lo = LONYBBLE(c);

	if (lo == 0x00)
		return 10;
	if (lo < 0x0A)
		return lo;
	return lo + 1;
}
char *midi::get_yamaha_effect_name(unsigned char effect)
{
	static char buf[64];

	switch (effect)
	{
	case 0x00: strcpy(buf, "No Effect"); break;
	case 0x01: strcpy(buf, "Hall1"); break;
	case 0x02: strcpy(buf, "Room1"); break;
	case 0x03: strcpy(buf, "Stage1"); break;
	case 0x04: strcpy(buf, "Plate"); break;
	case 0x05: strcpy(buf, "Delay L,C,R"); break;
	case 0x06: strcpy(buf, "Delay L,R"); break;
	case 0x07: strcpy(buf, "Echo"); break;
	case 0x08: strcpy(buf, "Cross Delay"); break;
	case 0x09: strcpy(buf, "ER1"); break;
	case 0x0A: strcpy(buf, "Gate Reverb"); break;
	case 0x0B: strcpy(buf, "Reverse Gate"); break;
	case 0x10: strcpy(buf, "White Room"); break;
	case 0x11: strcpy(buf, "Tunnel"); break;
	case 0x12: strcpy(buf, "Canyon"); break;
	case 0x13: strcpy(buf, "Basement"); break;
	case 0x14: strcpy(buf, "Karaoke1"); break;
	case 0x41: strcpy(buf, "Chorus1"); break;
	case 0x42: strcpy(buf, "Celeste1"); break;
	case 0x43: strcpy(buf, "Flanger1"); break;
	case 0x44: strcpy(buf, "Symphonic"); break;
	case 0x45: strcpy(buf, "Rotary Speaker"); break;
	case 0x46: strcpy(buf, "Tremolo"); break;
	case 0x47: strcpy(buf, "Auto Pan"); break;
	case 0x48: strcpy(buf, "Phaser1"); break;
	case 0x49: strcpy(buf, "Distortion"); break;
	case 0x4A: strcpy(buf, "Over Drive"); break;
	case 0x4B: strcpy(buf, "Amp Simulator"); break;
	case 0x4C: strcpy(buf, "3-Band EQ"); break;
	case 0x4D: strcpy(buf, "2-Band EQ"); break;
	case 0x4E: strcpy(buf, "Auto Wah (LFO)"); break;
	case 0x50: strcpy(buf, "Pitch Change"); break;
	case 0x51: strcpy(buf, "Aural Exciter"); break;
	case 0x52: strcpy(buf, "Touch Wah"); break;
	case 0x53: strcpy(buf, "Compressor"); break;
	case 0x54: strcpy(buf, "Noise Gate"); break;
	case 0x55: strcpy(buf, "Voice Cancel"); break;
	default: sprintf(buf, "Unknown (%02X)", effect);
	}

	return buf;
}
void midi::interpret_mt32_patch_memory(unsigned char *s, int len)
{
	int addr;
	unsigned char *p = s + 7;
	unsigned char ch, group, num;
	int patch;
	FILE *fp;

	//fp = fopen("k:\\projects\\tmidi\\patchmem.txt", "a");
	addr = (s[5] << 7) | s[6];
	//fprintf(fp, "\nStarting address: %d\n", addr);

	while (p - s < len - 9)
	{
		patch = addr / 8;
		//fprintf(fp, "\nAddr %d, patch %d:\n", addr, patch);
		group = ch = *p++;
		/*fprintf(fp, "   Timbre group: ");
		switch (ch)
		{
		case 0: fprintf(fp, "Group A\n"); break;
		case 1: fprintf(fp, "Group B\n"); break;
		case 2: fprintf(fp, "Memory\n"); break;
		case 3: fprintf(fp, "Rhythm\n"); break;
		default: fprintf(fp, "Unknown (%d)\n", ch);
		}*/
		mt32_patch_groups[patch] = ch;
		num = ch = *p++;
		//fprintf(fp, "  Timbre number: %d\n", ch);
		//fprintf(fp, " Program number: %d\n", group == 1 ? num + 64 : num);
		mt32_patch_programs[patch] = group == 1 ? num + 64 : num;
		ch = *p++;
		//fprintf(fp, "      Key shift: %d\n", (signed int) ch - 24);
		ch = *p++;
		//fprintf(fp, "      Fine tune: %d\n", (signed int) ch - 50);
		ch = *p++;
		//fprintf(fp, "   Bender range: %d\n", ch);
		ch = *p++;
		//fprintf(fp, "    Assign mode: Poly %d\n", ch + 1);
		ch = *p++;
		//fprintf(fp, "  Reverb switch: %s\n", ch ? "On" : "Off");
		ch = *p++;
		//fprintf(fp, "          Dummy: %d\n", ch);

		addr += 8;
	}

	//fclose(fp);
}
void midi::interpret_mt32_timbre_memory(unsigned char *s, int len)
{
	int timbre;

	timbre = s[5] / 2;
	mt32_memory_names[timbre][0] = '\0';
	strncat(mt32_memory_names[timbre], (char *) &s[7], 10);
}
// Initializes MT-32 state values on program startup
void midi::init_mt32_state(void)
{
	int i;

	for (i = 0; i < 128; i++)
	{
		if (i < 64)
			mt32_patch_groups[i] = 0;
		else
			mt32_patch_groups[i] = 1;
		mt32_patch_programs[i] = (char) i;
	}

	for (i = 0; i < 64; i++)
		mt32_memory_names[i][0] = '\0';
}
char *midi::interpret_sysex(unsigned char *s, int len)
{
	static char buf[256], timbreName[16];
	int i, j;

	buf[0] = '\0';

	switch (s[0])								// Manufacturer ID
	{
	case 0x41:	// Roland
		switch (s[2])						// Model ID
		{
		case 0x16:	// MT-32
			switch (s[4])
			{
			case 0x03:	// Patch Temp Area
				sprintf(buf, "Patch Temp Area, Part %d", HINYBBLE(s[6]) + 1);
				break;
			case 0x04:	// Timbre Temp Area
				strcpy(buf, "Timbre Temp Area");
				break;
			case 0x05:	// Patch Memory
				strcpy(buf, "Patch Memory");
				interpret_mt32_patch_memory(s, len);
				break;
			case 0x08:	// Timbre Memory
				strcpy(buf, "Timbre Memory: ");
				interpret_mt32_timbre_memory(s, len);
				strncat(buf, (char *) &s[7], 10);
				break;
			case 0x10:	// System Area
				strcpy(buf, "System Area");
				break;
			case 0x20:	// Display Area
				strcpy(buf, "MT-32 Display: ");
				j = strlen(buf);
				for (i = 7; i < len - 2; i++)
					buf[j++] = s[i];
				buf[j] = '\0';
				break;
			}
			break;
		case 0x42:	// GS Message
			switch (s[4])
			{
			case 0x00:	// SC-88 System Parameter
				switch (s[5])
				{
				case 0x00:	// System message
					switch (s[6])
					{
					case 0x7F:
						//sprintf(buf, "SC-88 System Mode Set: %s", s[7] ? "Double Module Mode" : "Single Module Mode");
						sprintf(buf, "SC-88 Reset (%s)", s[7] ? "Double" : "Single");
						break;
					}
					break;
				case 0x01:	// Part message
					sprintf(buf, "SC-88 Part %c%d: Port %c", HINYBBLE(s[6]) + 'A', interpret_sysex_part(LONYBBLE(s[6])), s[7] + 'A');
					break;
				}
				break;
			case 0x08:	// SC-88 Bulk Dump Setup Parameters
				strcpy(buf, "SC-88 Bulk Dump Setup Parameters");
				break;
			case 0x40:	// Parameter byte
				if (s[5] >= 0x10 && s[5] <= 0x1F)
				{
					sprintf(buf, "Part %d: ", interpret_sysex_part(s[5]));
					switch (s[6])
					{
					case 0x00:
						sprintf(&buf[strlen(buf)], "Tone #: Bank %d, Patch %d", s[7], s[8]);
						break;
					case 0x01:
						sprintf(&buf[strlen(buf)], "Rx Control Change: %s", s[7] ? "On" : "Off");
						break;
					case 0x02:
						sprintf(&buf[strlen(buf)], "Rx Channel: %d", s[7]);
						break;
					case 0x03:
						sprintf(&buf[strlen(buf)], "Rx Pitch Bend: %s", s[7] ? "On" : "Off");
						break;
					case 0x04:
						sprintf(&buf[strlen(buf)], "Rx Channel Pressure: %s", s[7] ? "On" : "Off");
						break;
					case 0x05:
						sprintf(&buf[strlen(buf)], "Rx Program Change: %s", s[7] ? "On" : "Off");
						break;
					case 0x06:
						sprintf(&buf[strlen(buf)], "Rx Control Change: %s", s[7] ? "On" : "Off");
						break;
					case 0x07:
						sprintf(&buf[strlen(buf)], "Rx Poly Pressure: %s", s[7] ? "On" : "Off");
						break;
					case 0x08:
						sprintf(&buf[strlen(buf)], "Rx Note Message: %s", s[7] ? "On" : "Off");
						break;
					case 0x09:
						sprintf(&buf[strlen(buf)], "RPN: %s", s[7] ? "On" : "Off");
						break;
					case 0x0A:
						sprintf(&buf[strlen(buf)], "NRPN: %s", s[7] ? "On" : "Off");
						break;
					case 0x0B:
						sprintf(&buf[strlen(buf)], "Rx Modulation: %s", s[7] ? "On" : "Off");
						break;
					case 0x0C:
						sprintf(&buf[strlen(buf)], "Rx Volume: %s", s[7] ? "On" : "Off");
						break;
					case 0x0D:
						sprintf(&buf[strlen(buf)], "Rx Panpot: %s", s[7] ? "On" : "Off");
						break;
					case 0x0E:
						sprintf(&buf[strlen(buf)], "Rx Expression: %s", s[7] ? "On" : "Off");
						break;
					case 0x0F:
						sprintf(&buf[strlen(buf)], "Rx Hold 1: %s", s[7] ? "On" : "Off");
						break;
					case 0x10:
						sprintf(&buf[strlen(buf)], "Rx Portamento: %s", s[7] ? "On" : "Off");
						break;
					case 0x11:
						sprintf(&buf[strlen(buf)], "Rx Sostenuto: %s", s[7] ? "On" : "Off");
						break;
					case 0x12:
						sprintf(&buf[strlen(buf)], "Rx Soft Pedal: %s", s[7] ? "On" : "Off");
						break;
					case 0x13:
						sprintf(&buf[strlen(buf)], "Mono/Poly Mode: %s", s[7] ? "On" : "Off");
						break;
					case 0x14:
						sprintf(&buf[strlen(buf)], "Assign Mode: %s", (s[7] > 0) ? ((s[7] == 1) ? "Limited" : "Full-Multi") : "Single");
						break;
					case 0x15:
						sprintf(&buf[strlen(buf)], "Use for Rhythm Part: %s", (s[7] > 0) ? ((s[7] == 1) ? "Map 1" : "Map 2") : "Off");
						break;
					case 0x16:
						sprintf(&buf[strlen(buf)], "Pitch Key Shift: %d", s[7]);
						break;
					case 0x17:
						sprintf(&buf[strlen(buf)], "Pitch Offset Fine: %d", s[7]);
						break;
					case 0x19:
						sprintf(&buf[strlen(buf)], "Rx Part Level: %d", s[7]);
						break;
					case 0x1A:
						sprintf(&buf[strlen(buf)], "Rx Velocity Sense Depth: %d", s[7]);
						break;
					case 0x1B:
						sprintf(&buf[strlen(buf)], "Rx Velocity Sense Offset: %d", s[7]);
						break;
					case 0x1C:
						sprintf(&buf[strlen(buf)], "Rx Part Panpot: %d", s[7]);
						break;
					case 0x1D:
						sprintf(&buf[strlen(buf)], "Key Range Low: %d", s[7]);
						break;
					case 0x1E:
						sprintf(&buf[strlen(buf)], "Key Range High: %d", s[7]);
						break;
					case 0x1F:
						sprintf(&buf[strlen(buf)], "CC1 Controller Number: %d", s[7]);
						break;
					case 0x20:
						sprintf(&buf[strlen(buf)], "CC2 Controller Number: %d", s[7]);
						break;
					case 0x21:
						sprintf(&buf[strlen(buf)], "Chorus Send Level: %d", s[7]);
						break;
					case 0x22:
						sprintf(&buf[strlen(buf)], "Reverb Send Level: %d", s[7]);
						break;
					case 0x23:
						sprintf(&buf[strlen(buf)], "Rx Bank Select: %s", s[7] ? "On" : "Off");
						break;
					case 0x24:
						sprintf(&buf[strlen(buf)], "SC-88 Rx Bank Select LSB: %s", s[7] ? "On" : "Off");
						break;
					case 0x2A:
						sprintf(&buf[strlen(buf)], "SC-88 Pitch Tune Fine: %d", s[7]);
						break;
					case 0x30:
						sprintf(&buf[strlen(buf)], "Vibrato Rate: %d", s[7]);
						break;
					case 0x31:
						sprintf(&buf[strlen(buf)], "Vibrato Depth: %d", s[7]);
						break;
					case 0x32:
						sprintf(&buf[strlen(buf)], "TVF Cutoff Frequency: %d", s[7] - 64);
						break;
					case 0x33:
						sprintf(&buf[strlen(buf)], "TVF Resonance: %d", s[7] - 64);
						break;
					case 0x34:
						sprintf(&buf[strlen(buf)], "TVF/TVA Envelope Attack: %d", s[7] - 64);
						break;
					case 0x35:
						sprintf(&buf[strlen(buf)], "TVF/TVA Envelope Decay: %d", s[7] - 64);
						break;
					case 0x36:
						sprintf(&buf[strlen(buf)], "TVF/TVA Envelope Release: %d", s[7] - 64);
						break;
					case 0x37:
						sprintf(&buf[strlen(buf)], "Vibrato Delay: %d", s[7]);
						break;
					case 0x40:
						sprintf(&buf[strlen(buf)], "Scale Tuning");
						break;
					}
				}
				else
					if (s[5] >= 0x20 && s[5] <= 0x2F)
					{
						strcpy(buf, "VCF/VCO/VCA Parameter");
					}
					else
						if (s[5] >= 0x40 && s[5] <= 0x4F)
						{
							sprintf(buf, "SC-88 Part %d: ", interpret_sysex_part(s[5]));
SC88PartParam:
							switch (s[6])
							{
							case 0x13:
								sprintf(&buf[strlen(buf)], "Mono/Poly mode: %s", s[7] ? "Polyphonic" : "Mono");
								break;
							case 0x20:
								sprintf(&buf[strlen(buf)], "EQ: %s", s[7] ? "On" : "Off");
								break;
							case 0x21:
								strcat(buf, "Output Assign: ");
								switch (s[7])
								{
								case 0x00: strcat(buf, "Output 1"); break;
								case 0x01: strcat(buf, "Output 2"); break;
								case 0x02: strcat(buf, "Output 2-L"); break;
								case 0x03: strcat(buf, "Output 2-R"); break;
								default: strcat(buf, itoa(s[7], buf, 10));
								}
								break;
							case 0x22:
								sprintf(&buf[strlen(buf)], "EFX: %s", s[7] ? "On" : "Off");
								break;
							case 0x2A:
								sprintf(&buf[strlen(buf)], "SC-88 Pitch Tune Fine: %d", s[7]);
								break;
							}
						}
						else
							switch (s[5])
						{
							case 0x00:	// System parameter
								switch (s[6])
								{
								case 0x00:	// Master Tune
								case 0x02:
								case 0x03:
									strcpy(buf, "Master Tune");
									break;
								case 0x04:	// Master Volume
									strcpy(buf, "Master Volume");
									break;
								case 0x05:	// Master Key Shift
									strcpy(buf, "Master Key Shift");
									break;
								case 0x06:	// Master Pan
									strcpy(buf, "Master Pan");
									break;
								case 0x7F:	// GS Reset
									strcpy(buf, "GS Reset");	// F0 41 10 42 12 40 00 7F 00 41 F7
									break;
								}
								break;
							case 0x01:	// Patch parameter
								switch (s[6])
								{
								case 0x00:	// Patch Name
									strcpy(buf, "Patch Name: ");
									j = strlen(buf);
									for (i = 8; i < len - 2; i++)
										buf[j++] = s[i];
									buf[j] = '\0';							
									break;
								case 0x10:	// Voice Reserve
									strcpy(buf, "Voice Reserve");
									break;
								case 0x30:	// Reverb Macro
									strcpy(buf, "Reverb Macro: ");
									switch (s[7])
									{
									case 0x00: strcat(buf, "Room 1"); break;
									case 0x01: strcat(buf, "Room 2"); break;
									case 0x02: strcat(buf, "Room 3"); break;
									case 0x03: strcat(buf, "Hall 1"); break;
									case 0x04: strcat(buf, "Hall 2"); break;
									case 0x05: strcat(buf, "Plate"); break;
									case 0x06: strcat(buf, "Delay"); break;
									case 0x07: strcat(buf, "Panning Delay"); break;
									}
									break;
								case 0x31:	// Reverb Character
									sprintf(buf, "Reverb Character: %d", s[7]);
									break;
								case 0x32:	// Reverb PRE-LPF
									sprintf(buf, "Reverb PRE-LPF: %d", s[7]);
									break;
								case 0x33:	// Reverb Level
									sprintf(buf, "Reverb Level: %d", s[7]);
									break;
								case 0x34:	// Reverb Time
									sprintf(buf, "Reverb Time: %d", s[7]);
									break;
								case 0x35:	// Reverb Delay Feedback
									sprintf(buf, "Reverb Delay Feedback: %d", s[7]);
									break;
								case 0x36:	// Reverb Send to Chorus
									sprintf(buf, "Reverb Send to Chorus: %d", s[7]);
									break;
								case 0x37:	// SC-88 Reverb Pre-Delay Time
									sprintf(buf, "SC-88 Reverb Pre-Delay Time: %d", s[7]);
									break;
								case 0x38:	// Chorus Macro
									strcpy(buf, "Chorus Macro: ");
									switch (s[7])
									{
									case 0x00: strcat(buf, "Chorus 1"); break;
									case 0x01: strcat(buf, "Chorus 2"); break;
									case 0x02: strcat(buf, "Chorus 3"); break;
									case 0x03: strcat(buf, "Chorus 4"); break;
									case 0x04: strcat(buf, "Feedback Chorus"); break;
									case 0x05: strcat(buf, "Flanger"); break;
									case 0x06: strcat(buf, "Short Delay"); break;
									case 0x07: strcat(buf, "Short Delay - Feedback"); break;
									}
									break;
								case 0x39:	// Chorus PRE-LPF
									sprintf(buf, "Chorus PRE-LPF: %d", s[7]);
									break;
								case 0x3A:	// Chorus Level
									sprintf(buf, "Chorus Level: %d", s[7]);
									break;
								case 0x3B:	// Chorus Feedback
									sprintf(buf, "Chorus Feedback: %d", s[7]);
									break;
								case 0x3C:	// Chorus Delay
									sprintf(buf, "Chorus Delay: %d", s[7]);
									break;
								case 0x3D:	// Chorus Rate
									sprintf(buf, "Chorus Rate: %d", s[7]);
									break;
								case 0x3E:	// Chorus Depth
									sprintf(buf, "Chorus Depth: %d", s[7]);
									break;
								case 0x3F:	// Chorus Send to Reverb
									sprintf(buf, "Chorus Send to Reverb: %d", s[7]);
									break;
								case 0x40:	// Chorus Send to Delay
									sprintf(buf, "Chorus Send to Delay: %d", s[7]);
									break;
								case 0x50:	// SC-88 Delay Macro
									strcpy(buf, "SC-88 Delay Macro: ");
									switch (s[7])
									{
									case 0x00: strcat(buf, "Delay 1"); break;
									case 0x01: strcat(buf, "Delay 2"); break;
									case 0x02: strcat(buf, "Delay 3"); break;
									case 0x03: strcat(buf, "Delay 4"); break;
									case 0x04: strcat(buf, "Pan Delay 1"); break;
									case 0x05: strcat(buf, "Pan Delay 2"); break;
									case 0x06: strcat(buf, "Pan Delay 3"); break;
									case 0x07: strcat(buf, "Pan Delay 4"); break;
									case 0x08: strcat(buf, "Delay to Reverb"); break;
									case 0x09: strcat(buf, "Pan Repeat"); break;
									}
									break;
								case 0x51:	// SC-88 Delay PRE-LPF
									sprintf(buf, "SC-88 Delay PRE-LPF: %d", s[7]);
									break;
								case 0x52:	// SC-88 Delay Time Center
									sprintf(buf, "SC-88 Delay Time Center: %d", s[7]);
									break;
								case 0x53:	// SC-88 Delay Time Ratio Left
									sprintf(buf, "SC-88 Delay Time Ratio Left: %d", s[7]);
									break;
								case 0x54:	// SC-88 Delay Time Ratio Right
									sprintf(buf, "SC-88 Delay Time Ratio Right: %d", s[7]);
									break;
								case 0x55:	// SC-88 Delay Level Center
									sprintf(buf, "SC-88 Delay Level Center: %d", s[7]);
									break;
								case 0x56:	// SC-88 Delay Level Left
									sprintf(buf, "SC-88 Delay Level Left: %d", s[7]);
									break;
								case 0x57:	// SC-88 Delay Level Right
									sprintf(buf, "SC-88 Delay Level Right: %d", s[7]);
									break;
								case 0x58:	// SC-88 Delay Level
									sprintf(buf, "SC-88 Delay Level: %d", s[7]);
									break;
								case 0x59:	// SC-88 Delay Feedback
									sprintf(buf, "SC-88 Delay Feedback: %s%d", s[7] > 0x40 ? "+" : "", s[7] - 0x40);
									break;
								case 0x5A:	// SC-88 Send Level to Reverb
									sprintf(buf, "SC-88 Send Level to Reverb: %d", s[7]);
									break;
								}
								break;
							case 0x02:	// SC-88 Equalization Parameter
								switch (s[6])
								{
								case 0x00:
									sprintf(buf, "SC-88 Low Freq. EQ: %d Hz", s[7] ? 200 : 100);
									break;
								case 0x01:
									sprintf(buf, "SC-88 Low Freq. Gain: %s%d db", s[7] >= 0x40 ? "+" : "", s[7] - 0x40);
									break;
								case 0x02:
									sprintf(buf, "SC-88 High Freq. EQ: %d kHz", s[7] ? 8 : 4);
									break;
								case 0x03:
									sprintf(buf, "SC-88 High Freq. Gain: %s%d db", s[7] >= 0x40 ? "+" : "", s[7] - 0x40);
									break;
								}
								break;
							case 0x03:	// SC-88 Pro EFX Parameter
								switch (s[6])
								{
								case 0x00:
									sprintf(buf, "SC-88 Pro EFX Type %d/%d", s[7], s[8]);
									break;
								default:
									sprintf(buf, "SC-88 Pro EFX Parameter %d: %d", s[6] - 2, s[7]);
									break;
								}
								break;
						}
						break;
			case 0x41:	// Drum Setup Parameter
				strcpy(buf, "Drum Setup");
				break;
			case 0x48:  // SC Bulk Dump
				strcpy(buf, "SC Bulk Dump");
				break;
			case 0x49:	// SC Bulk Dump Drum Parameters
				strcpy(buf, "SC Bulk Dump Drum Parameters");
				break;
			case 0x50:	// SC-88 Block "B" Parameter
				sprintf(buf, "SC-88 Block \"B\" SC-88 Part %d ", interpret_sysex_part(LONYBBLE(s[5])));
				goto SC88PartParam;		// Cheap but very effective
			case 0x58:	// SC-88 Block "B" Bulk Dump
				strcpy(buf, "SC-88 Block \"B\" Bulk Dump");
				break;
			case 0x59:	// SC-88 Block "B" Bulk Dump Drum Parameters
				strcpy(buf, "SC-88 Block \"B\" Bulk Dump Drum Parameters");
				break;
			}
			break;
		case 0x45:	// GS Display Data
			switch (s[4])
			{
			case 0x10:			// Sound Canvas Display
				switch (s[5])
				{
				case 0x00:	// Display Letters
					if (s[6] == 0x00)	// Letter bytes
					{
						strcpy(buf, "SC Display: ");
						j = strlen(buf);
						for (i = 7; i < len - 2; i++)
							buf[j++] = s[i];
						buf[j] = '\0';							
					}
					break;
				case 0x01:	// Display Dot Letters
					strcpy(buf, "SC Bitmap: Page 1");
					break;
				case 0x02:
					strcpy(buf, "SC Bitmap: Page 4");
					break;
				case 0x03:
					strcpy(buf, "SC Bitmap: Page 5");
					break;
				case 0x04:
					strcpy(buf, "SC Bitmap: Page 7");
					break;
				case 0x20:	// Set Display Page
					switch (s[6])
					{
					case 0x00:	// Display Page
						sprintf(buf, "Display Page: %d", s[7]);
						break;
					case 0x01:	// Display Page Time
						sprintf(buf, "Display Page Time: %.2f sec",
							(float) s[7] / 15.0f * 7.2f);
						break;
					}
					break;
				}
				break;
			}
			break;
		}
		break;
	case 0x43:	// Yamaha
		switch (s[2])						// Model ID
		{
		case 0x49:	// SW60XG Message
		case 0x7A:
			strcpy(buf, "SW60XG Message");
			break;
		case 0x4C:	// XG Message
			switch (s[3])				// XG System Parameter
			{
			case 0x00:
				switch (s[4])		// System Byte for XG System Parameter 0x00
				{
				case 0x00:
					switch (s[5])
					{
					case 0x00:	// Master Tune
						strcpy(buf, "Master Tune");
						break;
					case 0x04:	// Master Volume
						sprintf(buf, "Master Volume: %d", s[6]);
					case 0x7E:	// Set XG System On
						strcpy(buf, "XG Reset");
						break;
					case 0x7F:	// All Parameter Reset
						strcpy(buf, "All Parameter Reset");
						break;
					}
					break;
				}
				break;
			case 0x02:
				switch (s[4])		// System Byte for XG System Parameter 0x02
				{
				case 0x01:
					switch (s[5])
					{
					case 0x00:	// Reverb
						strcpy(buf, "Reverb Type: ");
						strcat(buf, get_yamaha_effect_name(s[6]));
						break;
					case 0x02:	// Reverb Time
						sprintf(buf, "Reverb Time: %d", s[6]);
						break;
					case 0x03:	// Reverb Diffusion
						sprintf(buf, "Reverb Diffusion: %d", s[6]);
						break;
					case 0x04:	// Reverb Initial Delay
						sprintf(buf, "Reverb Initial Delay: %d", s[6]);
						break;
					case 0x05:	// Reverb HPF Cutoff
						sprintf(buf, "Reverb HPF Cutoff: %d", s[6]);
						break;
					case 0x06:	// Reverb LPF Cutoff
						sprintf(buf, "Reverb LPF Cutoff: %d", s[6]);
						break;
					case 0x07:	// Reverb Width
						sprintf(buf, "Reverb Width: %d", s[6]);
						break;
					case 0x08:	// Reverb Height
						sprintf(buf, "Reverb Height: %d", s[6]);
						break;
					case 0x09:	// Reverb Depth
						sprintf(buf, "Reverb Depth: %d", s[6]);
						break;
					case 0x0A:	// Reverb Wall Vary
						sprintf(buf, "Reverb Wall Vary: %d", s[6]);
						break;
					case 0x0B:	// Reverb Dry/Wet
						sprintf(buf, "Reverb Dry/Wet: %s%d", (s[6] == 64) ? "" : (s[6] < 64 ? "D" : "W"), abs(s[6] - 64));
						break;
					case 0x0C:	// Reverb Level
						sprintf(buf, "Reverb Level: %d", s[6]);
						break;
					case 0x0D:	// Reverb Pan
						sprintf(buf, "Reverb Pan: %s%d", (s[6] == 64) ? "" : (s[6] < 64 ? "L" : "R"), abs(s[6] - 64));
						break;
					case 0x20:	// Chorus
						strcpy(buf, "Chorus Type: ");
						strcat(buf, get_yamaha_effect_name(s[6]));
						break;
					case 0x22:	// Chorus LFO Frequency
						sprintf(buf, "Chorus LFO Frequency: %d", s[6]);
						break;
					case 0x23:	// Chorus LFO Depth
						sprintf(buf, "Chorus LFO Depth: %d", s[6]);
						break;
					case 0x24:	// Chorus Feedback
						sprintf(buf, "Chorus Feedback: %s%d", s[6] > 0x40 ? "+" : "", s[6] - 0x40);
						break;
					case 0x25:	// Chorus Delay Offset
						sprintf(buf, "Chorus Delay Offset: %s%d", s[6] > 0x40 ? "+" : "", s[6] - 0x40);
						break;
					case 0x26:	// Chorus Parameter 5
						sprintf(buf, "Chorus Parameter 5: %d", s[6]);
						break;
					case 0x27:	// Chorus EQ Low Frequency
						sprintf(buf, "Chorus EQ Low Frequency: %d", s[6]);
						break;
					case 0x28:	// Chorus EQ Low Gain
						sprintf(buf, "Chorus EQ Low Gain: %d", s[6] - 64);
						break;
					case 0x29:	// Chorus EQ High Frequency
						sprintf(buf, "Chorus EQ High Frequency: %d", s[6]);
						break;
					case 0x2A:	// Chorus EQ High Gain
						sprintf(buf, "Chorus EQ High Gain: %d", s[6] - 64);
						break;
					case 0x2B:	// Chorus Dry/Wet
						sprintf(buf, "Chorus Dry/Wet: %d", s[6] - 64);
						break;
					case 0x2C:	// Chorus Level
						sprintf(buf, "Chorus Level: %d", s[6]);
						break;
					case 0x2D:	// Chorus Pan
						sprintf(buf, "Chorus Pan: %s%d", (s[6] == 64) ? "" : (s[6] < 64 ? "L" : "R"), abs(s[6] - 64));
						break;
					case 0x2E:	// Chorus Send to Reverb
						sprintf(buf, "Chorus Send to Reverb: %d", s[6]);
						break;
					case 0x40:	// Variation
						strcpy(buf, "Variation Type: ");
						strcat(buf, get_yamaha_effect_name(s[6]));
						break;
					case 0x42:	// Variation Parameter 1
						sprintf(buf, "Variation Parameter 1: %d", s[7]);
						break;
					case 0x44:	// Variation Parameter 2
						sprintf(buf, "Variation Parameter 2: %d", s[7]);
						break;
					case 0x46:	// Variation Parameter 3
						sprintf(buf, "Variation Parameter 3: %d", s[7]);
						break;
					case 0x48:	// Variation Parameter 4
						sprintf(buf, "Variation Parameter 4: %d", s[7]);
						break;
					case 0x4A:	// Variation Parameter 5
						sprintf(buf, "Variation Parameter 5: %d", s[7]);
						break;
					case 0x4C:	// Variation Parameter 6
						sprintf(buf, "Variation Parameter 6: %d", s[7]);
						break;
					case 0x4E:	// Variation Parameter 7
						sprintf(buf, "Variation Parameter 7: %d", s[7]);
						break;
					case 0x50:	// Variation Parameter 8
						sprintf(buf, "Variation Parameter 8: %d", s[7]);
						break;
					case 0x52:	// Variation Parameter 9
						sprintf(buf, "Variation Parameter 9: %d", s[7]);
						break;
					case 0x54:	// Variation Parameter 10
						sprintf(buf, "Variation Parameter 10: %d", s[7]);
						break;
					case 0x56:	// Variation Level
						sprintf(buf, "Variation Level: %d", s[6]);
						break;
					case 0x57:	// Variation Pan
						sprintf(buf, "Variation Pan: %s%d", (s[6] == 64) ? "" : (s[6] < 64 ? "L" : "R"), abs(s[6] - 64));
						break;
					case 0x58:	// Variation Send to Reverb
						sprintf(buf, "Variation Send to Reverb: %d", s[6]);
						break;
					case 0x59:	// Variation Send to Chorus
						sprintf(buf, "Variation Send to Chorus: %d", s[6]);
						break;
					case 0x5A:	// Variation Connection
						sprintf(buf, "Variation Connection: %s", s[6] ? "System" : "Insertion");
						break;
					case 0x5B:	// Variation Part
						sprintf(buf, "Variation Part: 0x%02X", s[6]);
						break;
					}
					break;
				case 0x40:
					switch (s[5])
					{
					case 0x00:	// EQ Type
						strcpy(buf, "EQ Type: ");
						switch (s[6])
						{
						case 0x00: strcat(buf, "Flat"); break;
						case 0x01: strcat(buf, "Jazz"); break;
						case 0x02: strcat(buf, "Pops"); break;
						case 0x03: strcat(buf, "Rock"); break;
						case 0x04: strcat(buf, "Classic"); break;
						default: sprintf(&buf[strlen(buf)], "Unknown (%02X)", s[6]); break;
						}
						break;
					case 0x01:	// EQ Gain 1
						sprintf(buf, "EQ Gain 1: %d", s[6]);
						break;
					case 0x02:	// EQ Frequency 1
						sprintf(buf, "EQ Frequency 1: %d", s[6]);
						break;
					case 0x03:	// EQ Q1
						sprintf(buf, "EQ Q1: %d", s[6]);
						break;
					case 0x04:	// EQ Shape 1
						sprintf(buf, "EQ Shape 1: %s", s[6] ? "Peaking" : "Shelving");
						break;
					case 0x05:	// EQ Gain 2
						sprintf(buf, "EQ Gain 2: %d", s[6]);
						break;
					case 0x06:	// EQ Frequency 2
						sprintf(buf, "EQ Frequency 2: %d", s[6]);
						break;
					case 0x07:	// EQ Q2
						sprintf(buf, "EQ Q2: %d", s[6]);
						break;
					case 0x09:	// EQ Gain 3
						sprintf(buf, "EQ Gain 3: %d", s[6]);
						break;
					case 0x0A:	// EQ Frequency 3
						sprintf(buf, "EQ Frequency 3: %d", s[6]);
						break;
					case 0x0B:	// EQ Q3
						sprintf(buf, "EQ Q3: %d", s[6]);
						break;
					case 0x0D:	// EQ Gain 4
						sprintf(buf, "EQ Gain 4: %d", s[6]);
						break;
					case 0x0E:	// EQ Frequency 4
						sprintf(buf, "EQ Frequency 4: %d", s[6]);
						break;
					case 0x0F:	// EQ Q4
						sprintf(buf, "EQ Q4: %d", s[6]);
						break;
					case 0x11:	// EQ Gain 5
						sprintf(buf, "EQ Gain 5: %d", s[6]);
						break;
					case 0x12:	// EQ Frequency 5
						sprintf(buf, "EQ Frequency 5: %d", s[6]);
						break;
					case 0x13:	// EQ Q5
						sprintf(buf, "EQ Q5: %d", s[6]);
						break;
					case 0x14:	// EQ Shape 5
						sprintf(buf, "EQ Shape 5: %s", s[6] ? "Peaking" : "Shelving");
						break;
					}
					break;
				}
				break;
			case 0x03:
				switch (s[4])		// System Byte for XG System Parameter 0x03
				{
				case 0x00:
				case 0x01:	// ??? Not sure if 0x01 should be included, see dajir1.mid
					switch (s[5])
					{
					case 0x00:	// Insertion Effect
						strcpy(buf, "Insertion Effect: ");
						strcat(buf, get_yamaha_effect_name(s[6]));
						break;
					case 0x0B:	// Insertion Parameter 10
						sprintf(buf, "Insertion Parameter 10: %d", s[6]);
						break;
					case 0x0C:	// Insertion Effect Part
						sprintf(buf, "Insertion Effect Part: %d", s[6]);
						break;
					}
					break;
				}
				break;
			case 0x06:	// XG Display
				/*							switch (s[5])
				{
				case 0x11:	// Displayed Letters
				case 0x12:	// Displayed Letters
				case 0x13:	// Displayed Letters*/
				strcpy(buf, "Displayed Letters: ");
				j = strlen(buf);
				for (i = 6; i < len - 1; i++)
					buf[j++] = s[i];
				buf[j] = '\0';
				break;
				//							}
				break;
			case 0x08:	// XG Part Parameter
				sprintf(buf, "Part %d ", s[4] + 1);
				switch (s[5])
				{
				case 0x00:	// Element Reserve
					sprintf(&buf[strlen(buf)], "Element Reserve: %d", s[6]);
					break;
				case 0x01:	// Bank Select MSB
					sprintf(&buf[strlen(buf)], "Bank Select MSB: %d", s[6]);
					break;
				case 0x02:	// Bank Select LSB
					sprintf(&buf[strlen(buf)], "Bank Select LSB: %d", s[6]);
					break;
				case 0x03:	// Program Number
					sprintf(&buf[strlen(buf)], "Program Number: %d (%s)", s[6], get_program_name(s[6], 0));
					break;
				case 0x04:	// Rx Channel
					sprintf(&buf[strlen(buf)], "Rx Channel: %d", s[6]);
					break;
				case 0x05:	// Mono/Poly Mode
					sprintf(&buf[strlen(buf)], "Mono/Poly Mode: %s", s[6] ? "Poly" : "Mono");
					break;
				case 0x06:	// Same Note Number Assign
					sprintf(&buf[strlen(buf)], "Same Note Number Assign: ");
					switch (s[6])
					{
					case 0x00: strcat(buf, "Single"); break;
					case 0x01: strcat(buf, "Multi"); break;
					case 0x02: strcat(buf, "Inst (for Drum)"); break;
					default: sprintf(&buf[strlen(buf)], "Unknown (%d)", s[6]);
					}
					break;
				case 0x07:	// Part Mode
					strcat(buf, "Part Mode: ");
					switch (s[6])
					{
					case 0x00: strcat(buf, "Normal"); break;
					case 0x01: strcat(buf, "Drum"); break;
					case 0x02: strcat(buf, "Drums 1"); break;
					case 0x03: strcat(buf, "Drums 2"); break;
					case 0x04: strcat(buf, "Drums 3"); break;
					case 0x05: strcat(buf, "Drums 4"); break;
					default: sprintf(&buf[strlen(buf)], "Unknown (%02X)", s[6]); break;
					}
					break;
				case 0x08:	// Note Shift
					sprintf(&buf[strlen(buf)], "Note Shift: %s%d semitones", s[6] > 0x40 ? "+" : "", s[6] - 0x40);
					break;
				case 0x09:	// Detune
					sprintf(&buf[strlen(buf)], "Detune: %d/%d", s[6], s[7]);
					break;
				case 0x0B:	// Volume
					sprintf(&buf[strlen(buf)], "Volume: %d", s[6]);
					break;
				case 0x0C:	// Velocity Sense Depth
					sprintf(&buf[strlen(buf)], "Velocity Sense Depth: %d", s[6]);
					break;
				case 0x0D:	// Velocity Sense Offset
					sprintf(&buf[strlen(buf)], "Velocity Sense Offset: %d", s[6]);
					break;
				case 0x0E:	// Pan
					strcat(buf, "Pan: ");
					if (!s[6])
						strcat(buf, "Random");
					else
						if (s[6] < 64)
							sprintf(&buf[strlen(buf)], "L%d", 64 - s[6]);
						else
							if (s[6] == 64)
								sprintf(&buf[strlen(buf)], "0");
							else
								sprintf(&buf[strlen(buf)], "R%d", s[6] - 64);
					break;
				case 0x11:	// Dry Level
					sprintf(&buf[strlen(buf)], "Dry Level: %d", s[6]);
					break;
				case 0x12:	// Chorus Level
					sprintf(&buf[strlen(buf)], "Chorus Level: %d", s[6]);
					break;
				case 0x13:	// Reverb Level
					sprintf(&buf[strlen(buf)], "Reverb Level: %d", s[6]);
					break;
				case 0x14:	// Variation Level
					sprintf(&buf[strlen(buf)], "Variation Level: %d", s[6]);
					break;
				case 0x15:	// Vibrato Rate
					sprintf(&buf[strlen(buf)], "Vibrato Rate: %d", s[6]);
					break;
				case 0x16:	// Vibrato Depth
					sprintf(&buf[strlen(buf)], "Vibrato Depth: %d", s[6]);
					break;
				case 0x17:	// Vibrato Delay
					sprintf(&buf[strlen(buf)], "Vibrato Delay: %d", s[6]);
					break;
				case 0x18:	// Filter Cutoff
					sprintf(&buf[strlen(buf)], "Filter Cutoff: %d", s[6]);
					break;
				case 0x19:	// Filter Resonance
					sprintf(&buf[strlen(buf)], "Filter Resonance: %d", s[6]);
					break;
				case 0x1A:	// Attack Time
					sprintf(&buf[strlen(buf)], "Attack Time: %d", s[6]);
					break;
				case 0x1B:	// Decay Time
					sprintf(&buf[strlen(buf)], "Decay Time: %d", s[6]);
					break;
				case 0x1C:	// Release Time
					sprintf(&buf[strlen(buf)], "Release Time: %d", s[6]);
					break;
				case 0x1D:	// Mod Pitch Control
					sprintf(&buf[strlen(buf)], "Mod Pitch Control: %d", s[6]);
					break;
				case 0x1E:	// Mod Filter Control
					sprintf(&buf[strlen(buf)], "Mod Filter Control: %d", s[6]);
					break;
				case 0x1F:	// Mod Amplitude Control
					sprintf(&buf[strlen(buf)], "Mod Amplitude Control: %d", s[6]);
					break;
				case 0x20:	// LFO PMOD Depth
					sprintf(&buf[strlen(buf)], "LFO PMOD Depth: %d", s[6]);
					break;
				case 0x21:	// LFO FMOD Depth
					sprintf(&buf[strlen(buf)], "LFO FMOD Depth: %d", s[6]);
					break;
				case 0x22:	// LFO AMOD Depth
					sprintf(&buf[strlen(buf)], "LFO AMOD Depth: %d", s[6]);
					break;
				case 0x23:	// Bend Pitch Control
					sprintf(&buf[strlen(buf)], "Bend Pitch Control: %d", s[6]);
					break;
				case 0x24:	// Bend Filter Control
					sprintf(&buf[strlen(buf)], "Bend Filter Control: %d", s[6]);
					break;
				case 0x25:	// Bend Amplitude Control
					sprintf(&buf[strlen(buf)], "Bend Amplitude Control: %d", s[6]);
					break;
				case 0x26:	// Bend LFO PMOD Depth
					sprintf(&buf[strlen(buf)], "Bend LFO PMOD Depth: %d", s[6]);
					break;
				case 0x27:	// Bend LFO FMOD Depth
					sprintf(&buf[strlen(buf)], "Bend LFO FMOD Depth: %d", s[6]);
					break;
				case 0x28:	// Bend LFO AMOD Depth
					sprintf(&buf[strlen(buf)], "Bend LFO AMOD Depth: %d", s[6]);
					break;
				case 0x69:	// Pitch Initial Level
					sprintf(&buf[strlen(buf)], "Pitch Initial Level: %d", s[6] - 64);
					break;
				case 0x6A:	// Pitch Attack Time
					sprintf(&buf[strlen(buf)], "Pitch Attack Time: %d", s[6] - 64);
					break;
				case 0x6B:	// Pitch Release Level
					sprintf(&buf[strlen(buf)], "Pitch Release Level: %d", s[6] - 64);
					break;
				case 0x6C:	// Pitch Release Time
					sprintf(&buf[strlen(buf)], "Pitch Release Time: %d", s[6] - 64);
					break;
				}
				break;
			case 0x30:	// XG Drum Parameter
			case 0x31:
				sprintf(buf, "Drum Note %d Parameter %d = %d", s[4], s[5], s[6]);
				break;
			}
			break;
		}

		break;
	case 0x7E:	// General MIDI
	case 0x7F:
		// F0 7E 7F 09 01 F7			(definitely standard GM Reset)
		// F0 7F 7F 04 01 00 7F F7		(??  from FF7 MIDI's)
		// F0H,7FH,7FH,04H,01H,llH,mmH,F7H
		// F0 7F 7F 04 01 00 7E F7
		if (s[1] == 0x7F && 
			s[2] == 0x09 && 
			s[3] == 0x01)
			strcpy(buf, "GM Reset");
		else
			if (s[1] == 0x7F &&
				s[2] == 0x04 &&
				s[3] == 0x01)
				sprintf(buf, "Master Volume: %d", s[5]);
		break;
	}

	return buf;
}
void midi::update_note_volume(char channel, char note, char volume)
{
	//int i;
	if (volume)
	{
		// Note on
		if (!(ms.channels[channel].notes[note]))
			ms.channels[channel].note_count++;
	}
	else
	{
		// Note off
		if (ms.channels[channel].notes[note])
			ms.channels[channel].note_count--;
	}
	// Store the value
	ms.channels[channel].notes[note] = volume;
	//SendDlgItemMessage(hwndApp, IDC_TVU0 + channel, WM_USER + 9, 0, RGB(rand() % 256, rand() % 256, rand() % 256));
	//SendDlgItemMessage(hwndApp, IDC_TVU0 + channel, PBM_SETPOS, (WPARAM) note, 0);
}
void midi::note_on(unsigned char on, unsigned char note, unsigned char velocity, unsigned char chan)
{
	DWORD dwParam1;
	signed int i;
	unsigned char channel = chan;

	// Perform global velocity modulation
	if (velocity && ms.mod_velocity)
	{
		i = (signed int) velocity;
		i += ms.mod_velocity;
		if (i < 0)
			i = 0;
		if (i > 127)
			i = 127;
		velocity = (unsigned char) i;
	}
	// Perform global pitch modulation
	if (channel != 9 && ms.channels[channel].last_bank != 127)
		note += ms.mod_pitch;

	// Update display/historic values
	update_note_volume(channel, note, on ? velocity : 0);
	ms.channels[channel].last_note_pitch = note;
	ms.channels[channel].last_note_velocity = velocity;

	// Don't actually play the note if this channel is muted
	if (ms.channels[channel].muted)
		return;

	// If the bank for this channel is 127, treat it as a percussive channel! (XG)
	// This needs to be an option, in case someone actually has a real XG synth.
	if (ms.midi_standard == MIDI_STANDARD_XG && ms.channels[channel].last_bank == 127)
		channel = 9;

	dwParam1 = MAKELONG(MAKEWORD(MAKEBYTE(channel, on ? 9 : 8), note), MAKEWORD(velocity, 0));
	if (hout)
		midiOutShortMsg(hout, dwParam1);
	
}
void midi::set_tempo(int new_tempo)
{
	double old_tick_length;
	char buf[256];
	int i;
	static int last_tempo = 0;

	// Calculate new tick length
	old_tick_length = ms.tick_length;
	ms.tick_length = ((double) (new_tempo / 1000) / (double) mh.num_ticks);

	if (new_tempo == last_tempo)
		return;

	last_tempo = new_tempo;

	if (!ms.analyzing || ms.seeking)
	{
		// Update tick length display on the main dialog
		sprintf(buf, "Tempo: %.2f ms/tick, %.0f bpm", ms.tick_length, 60000000.0f / new_tempo);
		//SetDlgItemText(hwndApp, IDC_TICK, buf);
		//SendDlgItemMessage(hwndApp, IDC_TEMPO_SLIDER, TBM_SETPOS, TRUE, (int) (60000000.0f / new_tempo));
	}

	// Output some debug info summarizing this tempo change
	//sprintf(buf, "(%d / 1000) / %d = %.2f", intd, mh.num_ticks, ms.tick_length);
	//OutputDebugString(buf);
	//sprintf(buf, "Set tempo: %d (%02X %02X %02X)\n", intd, id[0], id[1], id[2]);
	//OutputDebugString(buf);

	// Correct outstanding track triggers on each track
	for (i = 0; i < mh.num_tracks; i++)
	{
		if (!(th[i].enabled))
			continue;
		th[i].dt = (th[i].trigger - ms.curtime) / old_tick_length * ms.tick_length;
		th[i].trigger = ms.curtime + th[i].dt;
		//sprintf(buf, "Out of %.1f ticks, %.1f ticks remain (track %d)\n", 
		//	th[i].dt / old_tick_length, (th[i].trigger - curtime) / old_tick_length, i);
		//OutputDebugString(buf);
	}
}
void midi::check_midi_standard(unsigned char *data)
{
	switch (data[0])								// Manufacturer ID
	{
	case 0x41:	// Roland
		switch (data[2])
		{
		case 0x16:	// MT-32
			ms.midi_standard = MIDI_STANDARD_MT32;
			break;
		case 0x42:	// GS Message
			ms.midi_standard = MIDI_STANDARD_GS;
			break;
		}
		break;
	case 0x43:	// Yamaha
		switch (data[2])
		{
		case 0x4C:	// XG Message
			ms.midi_standard = MIDI_STANDARD_XG;
			break;
		}
		break;
	case 0x7E:	// General MIDI
	case 0x7F:
		ms.midi_standard = MIDI_STANDARD_GM;
		break;
	}
}
int midi::read_bytes_mem(track_header_t *th, unsigned char *buf, int num)
{
	memcpy(buf, th->dataptr, num);
	//	*(th->dataptr) += num;
	th->dataptr += num;

	return num;
}
unsigned short int midi::read_short_mem(track_header_t *th)
{
	unsigned char high, low;

	//	high = *(th->dataptr)++;
	//	low = *(th->dataptr)++;
	high = *(th->dataptr);
	th->dataptr++;
	low = *(th->dataptr);
	th->dataptr++;
	return MAKEWORD(low, high);
}
unsigned int midi::read_int_mem(track_header_t *th)
{
	unsigned short high, low;

	high = read_short_mem(th);
	low = read_short_mem(th);

	return ((high << 16) + low);
}
unsigned char midi::read_byte_mem(track_header_t *th)
{
	//	unsigned char data;

	//data = *(th->dataptr);
	//th->dataptr++;
	//return data;
	return *(th->dataptr)++;
}
inline unsigned int midi::read_vlq_mem(track_header_t *th)
{
	unsigned int value;
	unsigned char c;
	unsigned char *p = th->dataptr;

	if ((value = *p++) & 0x80)
	{
		value &= 0x7f;
		do
		{
			value = (value << 7) + ((c = *p++) & 0x7f);
		} while (c & 0x80);
	}
	th->dataptr = p;
	/*if ((value = *(th->dataptr)++) & 0x80)
	{
	value &= 0x7f;
	do
	{
	value = (value << 7) + ((c = *(th->dataptr)++) & 0x7f);
	} while (c & 0x80);
	}*/
	return value;
}
midi_text_t *midi::new_midi_text(char *midi_text, int text_type, double midi_time, int track, int track_offset)
{
	midi_text_t *p, *n;
	char *ch;

	// Allocate memory for the new node
	n = (midi_text_t *) calloc(1, sizeof(midi_text_t));

	// If the list is empty.. add this as the top node
	if (!midi_text_events)
		midi_text_events = n;
	else
	{
		// Otherwise find the end of the list and add this node to the end
		for (p = midi_text_events; p->next; p = p->next);
		p->next = n;
	}

	// Initialize data for this node
	n->text_type = text_type;
	n->midi_time = midi_time;
	n->track = track;
	n->track_offset = track_offset;
	n->next = NULL;

	if (midi_text)
	{
		// Sneaky trick to detect MT-32 MIDI files!
		if (ms.midi_standard == MIDI_STANDARD_NONE && strstr(midi_text, "MT-32"))
			ms.midi_standard = MIDI_STANDARD_MT32;

		// Cool trick to break up lines with CR/LF pairs
		// Search for a CR or LF
		ch = strchr(midi_text, 13);
		if (!ch)
			ch = strchr(midi_text, 10);
		// Found one?  Good.. let's break up the line into multiple text entries!
		if (ch)
		{
			// Terminate the string at this character and move to the next character
			*ch++ = '\0';
			// See if there's another CR/LF to seek past
			if (*ch == 13 || *ch == 10)
				ch++;
			// Make a new text entry with what we just seeked past
			new_midi_text(ch, text_type, midi_time, track, track_offset);
		}

		n->midi_text = strdup(midi_text);
	}

	// Return a pointer to the new node
	return n;
}
midi_sysex_t *midi::new_midi_sysex(unsigned char *data, int length, double midi_time, int track, int track_offset, int channel)
{
	midi_sysex_t *p, *n;

	// Allocate memory for the new node
	n = (midi_sysex_t *) calloc(1, sizeof(midi_sysex_t));

	// If the list is empty.. add this as the top node
	if (!midi_sysex_events)
		midi_sysex_events = n;
	else
	{
		// Otherwise find the end of the list and add this node to the end
		for (p = midi_sysex_events; p->next; p = p->next);
		p->next = n;
	}

	// See if the data is a MIDI reset
	check_midi_standard(data);

	// Initialize data for this node
	n->data = data;
	n->length = length;
	n->midi_time = midi_time;
	n->track = track;
	n->track_offset = track_offset;
	n->channel = channel;
	n->next = NULL;

	// Return a pointer to the new node
	return n;
}
int midi::process_midi_event(track_header_t *th)
{
	char *MThd = "MThd";
	char *MTrk = "MTrk";
	unsigned char *text;
	unsigned char id[4];
	char eventname[128];
	char buf[2048];
	unsigned int track = 0, i, blank, len, endtrack = 0;
	unsigned char lastcmd = 0, cmd, d1, d2, d3, d4, d5;
	signed char sd1;
	unsigned int intd;
	unsigned short pitchbend;
	int channel;
	unsigned char *cmdptr = th->dataptr;		// Pointer to the beginning of this event
	unsigned char *sysexptr;					// Pointer to beginning of sysex data

	// Read the MIDI event command
	cmd = read_byte_mem(th);

	//sprintf(buf, "Track %d: cmd = %d ", th->tracknum, cmd);
	//OutputDebugString(buf);

	// Handle running mode
	if (cmd < 128)
	{
		//sprintf(buf, "running mode ");
		//OutputDebugString(buf);
		th->dataptr--;
		cmd = th->lastcmd;
	}
	else
		th->lastcmd = cmd;

	if (cmd == 0xFF)		// Meta-event
	{
		cmd = read_byte_mem(th);
		len = read_vlq_mem(th);
		if (len > (th->dataptr - th->data) + th->length)
		{
			sprintf(buf, "Meta-event %02X at track %d offset %d has length %d, "
				"which would exceed track length of %d.\n\n"
				"Conclusion: %s is corrupt.", 
				cmd, th->tracknum, cmdptr - th->data, len, th->length, ms.filename);
			//MessageBox(hwndApp, buf, "TMIDI Read Error", MB_ICONERROR);
			return 1;
		}
		text = NULL;
		//sprintf(buf, "Meta-event %d/%d\n", cmd, len);
		//OutputDebugString(buf);
		switch (cmd)
		{
		case 0x00:		// Sequence number
			intd = read_short_mem(th);
			//				dprintf("Set Sequence number: %d\n", intd);
			break;
		case 0x01:		// Text
		case 0x02:		// Copyright info
		case 0x03:		// Sequence or track name
		case 0x04:		// Track instrument name
		case 0x05:		// Lyric
		case 0x06:		// Marker
		case 0x07:		// Cue point
			strcpy(eventname, midi_text_event_descriptions[cmd]);

			// Read the text
			text = (unsigned char *) malloc(len + 1);
			read_bytes_mem(th, text, len);
			text[len] = '\0';

			// If it's a track name, save it
			if (cmd == 3 || cmd == 4)
			{
				strncpy(th->name, (char *) text, sizeof(th->name));
				th->name[sizeof(th->name) - 1] = '\0';
			}
			else
				if (!th->name[0])
				{
					strncpy(th->name, (char *) text, sizeof(th->name));
					th->name[sizeof(th->name) - 1] = '\0';
				}

				// Save the text in the list of text events
				if (ms.analyzing && !ms.seeking)
					new_midi_text((char *) text, cmd, (ms.curtime - ms.starttime) / 1000.0f, th->tracknum, cmdptr - th->data);
				else
				{
					// Text to speech, heheh
					//if (cmd == 5)
					//	speak("%s", text);
					if (cmd == 5 && ms.current_text[strlen(ms.current_text) - 1] == '-')
						strcat(ms.current_text, (char *) text);
					else
						strncpy(ms.current_text, (char *) text, sizeof(ms.current_text));
					if (!(cmd == 3 && ms.title_displayed) || (cmd == 3 && text[0] == '\"'))
					{
						//if ((((cmd == 5) || (cmd == 6)) && (!ms.title_displayed || ms.curtime - ms.starttime > 500.0f)) || (cmd == 3 && text[0] == '\"') || ((cmd != 3 && (!(ms.title_displayed) || ms.curtime - ms.starttime > 3000.0f)) || ((cmd == 3 || cmd == 6) && (!(ms.title_displayed) || ms.curtime - ms.starttime > 3000.0f))))
						if ((cmd == 5) || (cmd == 6) || (cmd == 3 && text[0] == '\"') || ((cmd != 3 && (!(ms.title_displayed) || ms.curtime - ms.starttime > 3000.0f)) || ((cmd == 3 || cmd == 6) && (!(ms.title_displayed) || ms.curtime - ms.starttime > 3000.0f))))
						{
							if (cmd != 2)
							{
								blank = 1;
								for (i = 0; i < strlen(ms.current_text); i++)
									if (i != ' ')
										blank = 0;
								if (!blank)
								{
									//if (!ms.seeking)	// FIXME: don't go through all text while seeking...
									printf("current_text = %s", ms.current_text);
									ms.title_displayed = 1;
								}
							}
						}
					}
				}
				//sprintf(buf, "%s: %s\n", eventname, text);
				//OutputDebugString(buf);
				//fprintf(outfile, "%s: ", eventname);
				//fputs((const char *) text, outfile);
				//fprintf(outfile, "\n");
				break;
		case 0x20:		// MIDI Channel prefix
			d1 = read_byte_mem(th);
			//fprintf(outfile, "MIDI Channel Prefix: %d\n", d1);
			break;
		case 0x21:		// MIDI Port
			d1 = read_byte_mem(th);
			//fprintf(outfile, "MIDI Port: %d\n", d1);
			break;
		case 0x2F:		// End of track
			//				//fprintf(outfile, "End of track\n");
			sprintf(buf, "End of track %d\n", th->tracknum);
			OutputDebugString((LPCSTR)buf);
			th->enabled = 0;
			endtrack = 1;
			break;
		case 0x51:		// Set tempo
			read_bytes_mem(th, id, 3);
			intd = (id[0] << 16) + (id[1] << 8) + id[2];
			set_tempo(intd);
			break;
		case 0x54:		// SMPTE Offset
			d1 = read_byte_mem(th);
			d2 = read_byte_mem(th);
			d3 = read_byte_mem(th);
			d4 = read_byte_mem(th);
			d5 = read_byte_mem(th);
			//fprintf(outfile, "SMPTE Offset: %d:%02d:%02d.%02d.%02d\n", d1, d2, d3, d4, d5);
			break;
		case 0x58:		// Time signature
			d1 = read_byte_mem(th);
			d2 = read_byte_mem(th);
			d3 = read_byte_mem(th);
			d4 = read_byte_mem(th);
			//fprintf(outfile, "Time signature: %d/%d, %d ticks in metronome click, %d 32nd notes to quarter note\n", d1, d2, d3, d4);
			break;
		case 0x59:		// Key signature
			sd1 = read_byte_mem(th);
			d2 = read_byte_mem(th);
			//fprintf(outfile, "Key signature: ");
			//				if (sd1 < 0)
			//fprintf(outfile, "%d flats, ", 0 - sd1);
			//				else
			//					if (sd1 > 0)
			//fprintf(outfile, "%d sharps, ", sd1);
			//					else
			//fprintf(outfile, "Key of C, ");
			//fprintf(outfile, d2 ? "minor\n" : "major\n");
			break;
		case 0x7F:		// Sequencer-specific information
			//fprintf(outfile, "Sequencer-specific information, %d bytes: ", len);
			for (i = 0; i < len; i++)
				read_byte_mem(th);
			//fputc(read_byte_mem(th), outfile);
			//fprintf(outfile, "\n");
			break;
		default:		// Unknown
			//fprintf(outfile, "Meta-event, unknown command %X length %d: ", cmd, len);
			for (i = 0; i < len; i++)
				read_byte_mem(th);
			//					fputc(read_byte_mem(th), outfile);
			//fprintf(outfile, "\n");
		}
		if (text)
		{
			free(text);
			text = NULL;
		}
	}
	else
	{
		//sprintf(buf, "cmd = %d", cmd);
		//OutputDebugString(buf);
		channel = LONYBBLE(cmd);
		// *** cool symmetric part follows: ***
		// Save this channel number in the track struct for historical purposes
		th->last_channel = channel;
		// Save this track number in the channel struct for historical purposes
		ms.channels[channel].track_references[th->tracknum] = 1;
		switch (HINYBBLE(cmd))	// Normal event
		{
		case 0x08: // Note off
			d1 = read_byte_mem(th);
			d2 = read_byte_mem(th);
			if (!ms.analyzing)
			{
				note_on(FALSE, d1, d2, channel);
				//midiOutShortMsg(hout, MAKELONG(MAKEWORD(cmd, d1), MAKEWORD(d2, 0)));
				/*sprintf(buf, "Note off, d1 = %d, d2 = %d\n", d1, d2);
				SetDlgItemText(hwndApp, IDC_FILENAME, buf);
				OutputDebugString(buf);*/
			}
			//fprintf(outfile, "Note Off, note %d velocity %d\n", d1, d2);
			break;
		case 0x09: // Note on
			d1 = read_byte_mem(th);
			d2 = read_byte_mem(th);
			if (!ms.analyzing)
			{
				th->last_note_pitch = d1;
				th->last_note_velocity = d2;
				note_on(TRUE, d1, d2, channel);
				//midiOutShortMsg(hout, MAKELONG(MAKEWORD(cmd, d1), MAKEWORD(d2, 0)));
				/*sprintf(buf, "Note on, d1 = %d, d2 = %d\n", d1, d2);
				SetDlgItemText(hwndApp, IDC_FILENAME, buf);
				OutputDebugString(buf);*/
			}
			if (!ms.found_note_on)
			{
				ms.found_note_on = 1;
				ms.first_note_on = ms.curtime;
			}
			//fprintf(outfile, "Note On, note %d velocity %d\n", d1, d2);
			break;
		case 0x0A: // Key after-touch
			d1 = read_byte_mem(th);
			d2 = read_byte_mem(th);
			if (!ms.analyzing)
				midiOutShortMsg(hout, MAKELONG(MAKEWORD(cmd, d1), MAKEWORD(d2, 0)));
			//fprintf(outfile, "Key After-touch, note %d velocity %d\n", d1, d2);
			break;
		case 0x0B: // Control Change
			d1 = read_byte_mem(th);
			d2 = read_byte_mem(th);
			// Save the controller value
			if (ms.seeking)
				ms.channels[channel].controllers[d1] = d2;
			if (!ms.analyzing)
			{
				ms.channels[channel].last_controller = th->last_controller = d1;
				ms.channels[channel].last_controller_value = th->last_controller_value = d2;
				if (d1 == 0)
					ms.channels[channel].last_bank = th->last_bank = d2;
				if (!ms.channels[channel].lock_controller)
					ms.channels[channel].displayed_controller = d1;		// Automatically select which controller to display
				if (!ms.channels[channel].controller_overridden[d1])
				{
					ms.channels[channel].controllers[d1] = d2;			// Update controller value
					midiOutShortMsg(hout, MAKELONG(MAKEWORD(cmd, d1), MAKEWORD(d2, 0)));
				}
			}
			//fprintf(outfile, "Control Change, controller %d value %d\n", d1, d2);
			break;
		case 0x0C: // Program Change
			d1 = read_byte_mem(th);
			if (!ms.analyzing || ms.seeking)
			{
				ms.channels[channel].last_program = th->last_program = d1;
				ms.channels[channel].normal_program = d1;
				if (!(ms.channels[channel].program_overridden)) // && !ms.seeking)
					set_channel_program(channel, d1, ms.channels[channel].last_bank);
			}
			//fprintf(outfile, "Program Change, program %d\n", d1);
			break;
		case 0x0D: // Channel after-touch
			d1 = read_byte_mem(th);
			if (!ms.analyzing)
				midiOutShortMsg(hout, MAKELONG(MAKEWORD(cmd, d1), MAKEWORD(0, 0)));
			//fprintf(outfile, "Channel After-touch, channel %d\n", d1);
			break;
		case 0x0E: // Pitch wheel
			intd = read_short_mem(th);
			d2 = LOBYTE(intd);
			d1 = HIBYTE(intd);
			pitchbend = (unsigned short) d2;
			pitchbend <<= 7;
			pitchbend |= (unsigned short) d1;
			if (!ms.analyzing)
			{
				midiOutShortMsg(hout, MAKELONG(MAKEWORD(cmd, d1), MAKEWORD(d2, 0)));
				ms.channels[channel].last_pitch_bend = th->last_pitch_bend = (signed int) pitchbend - MAX_PITCH_BEND;
			}
			else
			{
				// Keep track of the highest pitch bend value used in this song
				if (abs((signed int) pitchbend - MAX_PITCH_BEND) > ms.highest_pitch_bend)
					ms.highest_pitch_bend = abs((signed int) pitchbend - MAX_PITCH_BEND);
			}
			//fprintf(outfile, "Pitch Wheel, amount %d\n", intd);
			break;
		case 0x0F: // System message
			switch (LONYBBLE(cmd))
			{
			case 0x02:
				d1 = read_byte_mem(th);
				d2 = read_byte_mem(th);
				intd = (d2 << 8) + d1;
				//fprintf(outfile, "System Message: Song position: %d\n", intd);
			case 0x03:
				d1 = read_byte_mem(th);
				//fprintf(outfile, "System Message: Song select: %d\n", d1);
			case 0x06:
				//fprintf(outfile, "System Message: Tune request\n");
				break;
			case 0x00:
			case 0x07:	// SYSEX data
				len = read_vlq_mem(th);
				if (len > (th->dataptr - th->data) + th->length)
				{
					sprintf(buf, "Sysex data at track %d offset %d has length %d, "
						"which would exceed track length of %d.\n\n"
						"Conclusion: %s is corrupt.", 
						th->tracknum, cmdptr - th->data, len, th->length, ms.filename);
					//MessageBox(hwndApp, buf, "TMIDI Read Error", MB_ICONERROR);
					return 1;
				}
				sysexptr = th->dataptr;
				if (ms.analyzing && !ms.seeking)
					new_midi_sysex(sysexptr, len, (ms.curtime - ms.starttime) / 1000.0f, th->tracknum, cmdptr - th->data, channel);
				//fprintf(outfile, "SysEx Data, length %d: %02X ", len, cmd);
				th->dataptr += len;
				/*for (i = 0; i < len; i++)
				read_byte_mem(th);*/
				if (!ms.analyzing)
				{
					// Interpret the sysex data, in case we need it (like MT-32)
					interpret_sysex(sysexptr, len);
					// Don't send sysex when seeking on the MT-32
					if (!(ms.midi_standard == MIDI_STANDARD_MT32 && ms.seeking))
						output_sysex_data(channel, sysexptr, len);
				}
				//fprintf(outfile, "%02X ", read_byte_mem(th));
				//fprintf(outfile, "\n");
				break;
			case 0x08:
				//fprintf(outfile, "System Message: Timing clock used when synchronization is required.\n");
				break;
			case 0x0A:
				//fprintf(outfile, "System Message: Start current sequence\n");
				break;
			case 0x0B:
				//fprintf(outfile, "System Message: Continue a stopped sequence where left off\n");
				break;
			case 0x0C:
				//fprintf(outfile, "System Message: Stop a sequence\n");
				break;
				//default:
				//fprintf(outfile, "System Message: Unknown (%d)\n", LONYBBLE(cmd));
			}
			break;
		default:
			//fprintf(outfile, "Unknown Message (%d)\n", HINYBBLE(cmd));
			read_byte_mem(th);
		}
		//OutputDebugString("\n");
	}

	return 0;
}

void midi::set_channel_mute(int channel, int mute)
{
	unsigned char vel, note, was_muted;
	//HWND hwnd = GetDlgItem(hwndApp, IDC_C0 + channel);

	//	style = GetWindowLong(hwnd, GWL_STYLE);

	was_muted = ms.channels[channel].muted;
	ms.channels[channel].muted = mute;

	if (mute)
	{
		// Mute the channel
		all_notes_off_channel(channel);
		//		style |= SS_SUNKEN;
	}
	else
	{
		// Unmute the channel

		// Restore any notes that should be playing (unless this is the percussion channel)
		if (channel != 9 && was_muted)
			for (note = 0; note < 128; note++)
			{
				vel = ms.channels[channel].notes[note];
				if (vel)
					note_on(TRUE, note, vel, channel);
			}
			// Change the channel text
			//		style &= ~SS_SUNKEN;
	}

	//SendMessage(hwnd, BM_SETCHECK, (WPARAM) mute, 0);
	//SetWindowLong(hwnd, GWL_STYLE, style);
	//SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOSIZE | SWP_DRAWFRAME);
	//InvalidateRect(hwnd, NULL, TRUE);
}

void midi::kill_all_midi_sysex(void)
{
	midi_sysex_t *p = midi_sysex_events, *next;

	while (p)
	{
		next = p->next;
		free(p);
		p = next;
	}
	midi_sysex_events = NULL;
}
void midi::kill_all_midi_text(void)
{
	midi_text_t *p = midi_text_events, *next;

	while (p)
	{
		if (p->midi_text)
			free(p->midi_text);
		next = p->next;
		free(p);
		p = next;
	}
	midi_text_events = NULL;
}
void midi::init_midi_out()//HWND hwndcb)
{
	int device;
	char msgbuf[256];

	if (hout)
	{
		midiOutClose(hout);
		hout = NULL;
	}

	midi_out_cb = device = 1;//SendMessage(hwndcb, CB_GETCURSEL, 0, 0);
	if (!device)
		return;
	device--;

	if (midiOutOpen(&hout, device, NULL, 0, NULL) != MMSYSERR_NOERROR)
	{
		hout = NULL;
		strcpy(msgbuf, "Unable to open MIDI-out device:\n");
		//SendMessage(hwndcb, CB_GETLBTEXT, (WPARAM) device + 1, (LPARAM) (LPCSTR) &msgbuf[strlen(msgbuf)]);
		printf("midiOutOpen() failed...\n");
	}
}
char *midi::extract_filename(char *filename)
{
	char *ch = strrchr(filename, '\\');
	if (ch)
		return ch + 1;
	else
		return filename;
}
inline double midi::GetHRTickCount(void)
{
	double d;

	timeBeginPeriod(1); 
	d = (double) timeGetTime();
	timeEndPeriod(1);
	return d;

	//QueryPerformanceCounter(&LIms_time);
	//return (double) (LIms_time.QuadPart / freq);
}

void midi::close_midi_out(void)
{
	int i = 0;

	if (hin)
		return;

	if (hout)
	{
		all_notes_off();
		midiOutReset(hout);
		while (midiOutClose(hout) != MMSYSERR_NOERROR && i++ < 10)
			Sleep(200);
		if (i == 10)
		{
			printf("Unable to close MIDI-out device!\n");
		}
		hout = NULL;
	}
}
int midi::handle_sysex_dump(FILE *fp)
{
	MIDIHDR mh;
	char *buf;
	char text[MAX_PATH];
	int filelen, i;
	double startTime, endTime, timelen, speed;

	// Read the file
	sprintf(text, "Reading sysex dump file %s...", ms.filename);
	filelen = _filelength(_fileno(fp));
	if (!filelen)
	{
		printf("Sysex file is empty!\n");
		return 1;
	}
	buf = (char *) malloc(filelen + 1);
	fread(buf, filelen, 1, fp);
	fclose(fp);

	// Open the MIDI-out device
	if (!hout)
		init_midi_out();
	if (!hout)
	{
		printf("Unable to open MIDI-out device for sysex dump!");
		return 1;
	}

	// Reset the MIDI-out device
	midiOutReset(hout);

	// Prepare the MIDI out header
	memset(&mh, 0, sizeof(mh));
	mh.lpData = buf;
	mh.dwBufferLength = filelen;
	mh.dwBytesRecorded = filelen;
	// Prepare the sysex buffer for output
	strcpy(text, "Preparing MIDI out header...");
	//SetWindowText(hwndStatusBar, (LPCWSTR)text);
	midiOutPrepareHeader(hout, &mh, sizeof(mh));

	// Send the sysex buffer!
	sprintf(text, "Sending %s (%d bytes)...", ms.filename, filelen);
	//SetWindowText(hwndStatusBar, (LPCWSTR)text);
	printf("Sending sysex data...\n");
	startTime = GetHRTickCount();
	midiOutLongMsg(hout, &mh, sizeof(mh));
	endTime = GetHRTickCount();
	printf("Sent sysex data.\n");

	// Unprepare the sysex buffer
	do
	{
		i = midiOutUnprepareHeader(hout, &mh, sizeof(mh));
		Sleep(50);
	} while (i == MIDIERR_STILLPLAYING);

	timelen = (endTime - startTime) / 1000.0f;
	if (timelen == 0.0f)
		speed = 0.0f;
	else
		speed = (double) filelen / timelen;
	sprintf(text, "Finished sending %s (%d bytes) in %.1f seconds (%.0f bytes per second)", 
		extract_filename(ms.filename), filelen, timelen, speed);
	//SetWindowText(hwndStatusBar, (LPCWSTR)text);

	// Close the MIDI-out device
	close_midi_out();

	return 0;
}
int midi::analyze_midi(void)
{
	int tracks = mh.num_tracks;
	int i, j;
	int num_events = 0;
	double curtime, starttime;
	double nexttrigger;
	double start_analyze, end_analyze;
	//double start_event, end_event, total_event = 0.0f;
	//double start_vlq, end_vlq, total_vlq = 0.0f;
	char buf[256];
	int first_pass;
	midi_text_t *p;
	static HANDLE standard_image = NULL;

	// Clear tic marks in the song position slider
	//SendMessage(GetDlgItem(hwndApp, IDC_SONG_SLIDER), TBM_CLEARTICS, TRUE, 0);

	// Initialize playback parameters
	ms.midi_standard = MIDI_STANDARD_NONE;
	ms.stop_requested = 0;
	//set_tempo(50000 / 1000);
	ms.tempo = 500000 / 1000;
	ms.tick_length = (double) ms.tempo / (double) mh.num_ticks;
	ms.found_note_on = 0;
	ms.first_note_on = 0.0f;
	ms.analyzing = 1;
	//sprintf(buf, "Tempo: %.2f ms/tick, %.0f bpm", ms.tick_length, 60000000.0f / ms.tempo);
	//SetDlgItemText(hwndApp, IDC_TICK, buf);

	// Initialize track parameters
	for (i = 0; i < tracks; i++)
	{
		th[i].name[0] = '\0';
		th[i].num_events = 0;
		th[i].num_events_done = 0;
		th[i].last_channel = -1;
		th[i].last_controller = -1;
		th[i].last_controller_value = -1;
		th[i].last_note_pitch = -1;
		th[i].last_note_velocity = -1;
		th[i].last_program = -1;
		th[i].last_bank = -1;
		th[i].lastcmd = 0;
		th[i].enabled = 1;
		th[i].trigger = 0.0f;
		th[i].dataptr = th[i].data;
		th[i].tracknum = i;
	}

	// Initialize historical channel values
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < MAX_MIDI_TRACKS; j++)
			ms.channels[i].track_references[j] = -1;
		ms.channels[i].last_controller = -1;
		ms.channels[i].last_controller_value = -1;
		ms.channels[i].last_note_pitch = -1;
		ms.channels[i].last_note_velocity = -1;
		ms.channels[i].last_program = -1;
		ms.channels[i].last_bank = -1;
	}

	// Record starting time
	curtime = starttime = 0.0f;
	ms.starttime = starttime;

	start_analyze = GetHRTickCount();

	// Loop until we've been asked to stop
	first_pass = 1;
	while (!ms.stop_requested)
	{
		// Schedule the next "wakeup time" MAX_MIDI_WAIT milliseconds into the future
		nexttrigger = curtime + MAX_MIDI_WAIT;
		// See if any tracks have pending data
		ms.stop_requested = 1;
		for (i = 0; i < tracks; i++)
		{
			// Continue on to the next track if this track is disabled
			if (!th[i].enabled)
				continue;
			else
				ms.stop_requested = 0;

			// Read the next event's delta time
			if (first_pass)
			{
				th[i].dt = (double) read_vlq_mem(&th[i]) * ms.tick_length;
				th[i].trigger = curtime + th[i].dt;
			}

			// Process MIDI events until one is scheduled for a time in the future
			while (curtime >= th[i].trigger)
			{
				// Process the event for this track
				ms.curtime = curtime;
				//start_event = GetHRTickCount();
				if (process_midi_event(&th[i]))
					return 1;
				//end_event = GetHRTickCount();
				//total_event += end_event - start_event;
				num_events++;
				th[i].num_events++;
				/*if (num_events % 1000 == 0)
				{
				sprintf(buf, "Loaded %s, analyzing... (%d events)", ms.filename, num_events);
				SetDlgItemText(hwndApp, IDC_FILENAME, buf);
				}*/

				// Check for end of track
				if (!(th[i].enabled))
					break;

				if (th[i].dataptr >= (th[i].data + th[i].length))
				{
					th[i].enabled = FALSE;
					break;
				}

				// Read the next event's delta time
				//start_vlq = GetHRTickCount();
				th[i].dt = (double) read_vlq_mem(&th[i]) * ms.tick_length;
				//end_vlq = GetHRTickCount();
				//total_vlq += end_vlq - start_vlq;
				th[i].trigger += th[i].dt;
			}
			// Check for end of track
			if (!(th[i].enabled))
				continue;

			// See if this track's trigger is the more recent than the next scheduled trigger
			// If so, make it the next trigger
			if (th[i].trigger < nexttrigger)
				nexttrigger = th[i].trigger;
		}
		first_pass = 0;
		curtime = nexttrigger;
	}
	// Analysis complete
	end_analyze = GetHRTickCount();
	// Store song length and # of events
	ms.song_length = (int) (curtime / 1000.0f);
	ms.num_events = num_events;
	// Set up velocity mod slider
	//SendDlgItemMessage(hwndApp, IDC_VELOCITY_SLIDER, TBM_SETRANGE, TRUE, MAKELONG(0, 128));
	//SendDlgItemMessage(hwndApp, IDC_VELOCITY_SLIDER, TBM_SETTICFREQ, 32, 0);
	set_mod_velocity(0);
	// Set up pitch mod slider
	//SendDlgItemMessage(hwndApp, IDC_PITCH_SLIDER, TBM_SETRANGE, TRUE, MAKELONG(0, 48));
	//SendDlgItemMessage(hwndApp, IDC_PITCH_SLIDER, TBM_SETTICFREQ, 12, 0);
	set_mod_pitch(0);
	// Set up tempo slider
	//SendDlgItemMessage(hwndApp, IDC_TEMPO_SLIDER, TBM_SETRANGE, TRUE, MAKELONG(0, 500));
	//SendDlgItemMessage(hwndApp, IDC_TEMPO_SLIDER, TBM_SETPOS, TRUE, 120);
	//SendDlgItemMessage(hwndApp, IDC_TEMPO_SLIDER, TBM_SETTICFREQ, 500 / 10, 0);
	// Set up MIDI event position slider
	//SendDlgItemMessage(hwndApp, IDC_EVENT_SLIDER, TBM_SETTICFREQ, num_events / 10, 0);
	//SendDlgItemMessage(hwndApp, IDC_EVENT_SLIDER, TBM_SETRANGE, TRUE, MAKELONG(0, num_events / 10));
	//SendDlgItemMessage(hwndApp, IDC_EVENT_SLIDER, TBM_SETPOS, FALSE, 0);
	// Set song length text
	sprintf(buf, "%d:%02d", ms.song_length / 60, ms.song_length % 60);
	//SetDlgItemText(hwndApp, IDC_SONG_LENGTH, buf);
	// Set up song position slider
	//SendDlgItemMessage(hwndApp, IDC_SONG_SLIDER, TBM_SETTICFREQ, ms.song_length / 10, 0);
	//SendDlgItemMessage(hwndApp, IDC_SONG_SLIDER, TBM_SETRANGE, TRUE, MAKELONG(0, ms.song_length));
	//SendDlgItemMessage(hwndApp, IDC_SONG_SLIDER, TBM_SETPOS, FALSE, 0);
	// Set tic marks for text events in the song position slider
	for (p = midi_text_events; p; p = p->next)
	{
		i = (int) p->midi_time;
		/*if (i && i != ms.song_length)
		SendMessage(GetDlgItem(hwndApp, IDC_SONG_SLIDER), TBM_SETTIC, 0, (LPARAM) (LONG) i);*/
	}
	// Set up the MIDI standard bitmap
	if (standard_image)
	{
		DeleteObject(standard_image);
		standard_image = NULL;
	}
	// If we haven't decided on a standard, check the filename/path for "MT32" or "MT-32"
	if (ms.midi_standard == MIDI_STANDARD_NONE && 
		(stristr(ms.filename, "MT32") || stristr(ms.filename, "MT-32")))
		ms.midi_standard = MIDI_STANDARD_MT32;
	// Choose an appropriate MIDI standard bitmap
	/*if (ms.midi_standard == MIDI_STANDARD_NONE)
	ShowWindow(GetDlgItem(hwndApp, IDC_MIDI_LOGO), SW_HIDE);
	else
	{
	switch (ms.midi_standard)
	{
	case MIDI_STANDARD_GM:
	standard_image = LoadImage(ghInstance, MAKEINTRESOURCE(IDB_GMLOGO), IMAGE_BITMAP, 0, 0, 0);
	break;
	case MIDI_STANDARD_GS:
	standard_image = LoadImage(ghInstance, MAKEINTRESOURCE(IDB_GSLOGO), IMAGE_BITMAP, 0, 0, 0);
	break;
	case MIDI_STANDARD_XG:
	standard_image = LoadImage(ghInstance, MAKEINTRESOURCE(IDB_XGLOGO), IMAGE_BITMAP, 0, 0, 0);
	break;
	case MIDI_STANDARD_MT32:
	standard_image = LoadImage(ghInstance, MAKEINTRESOURCE(IDB_MTLOGO), IMAGE_BITMAP, 0, 0, 0);
	break;
	}
	SendDlgItemMessage(hwndApp, IDC_MIDI_LOGO, STM_SETIMAGE, 
	(WPARAM) IMAGE_BITMAP, (LPARAM) standard_image);
	ShowWindow(GetDlgItem(hwndApp, IDC_MIDI_LOGO), SW_SHOW);
	}*/
	// Decide which instrument names to use
	switch (ms.midi_standard)
	{
	case MIDI_STANDARD_MT32: program_names = mt32_program_names; break;
	default: program_names = gm_program_names;
	}
	// If a text window is open, reinitialize its contents
	//if (hwndText)
	//	SendMessage(hwndText, WM_INITDIALOG, 0, 0);
	//// If a tracks window is open, reinitialize its contents
	//if (hwndTracks)
	//	SetupItemsTracksListView(GetDlgItem(hwndTracks, IDC_TRACKS_LIST));
	//// If a channels window is open, reinitialize its contents
	//if (hwndChannels)
	//	SetupItemsChannelsListView(GetDlgItem(hwndChannels, IDC_CHANNELS_LIST));
	//// If a tracks window is open, reinitialize its contents
	//if (hwndSysex)
	//	SetupItemsSysexListView(GetDlgItem(hwndSysex, IDC_SYSEX_LIST));

	//sprintf(buf, "Analysis of %d events took %.0f milliseconds, %.0f of which were spent in "
	//	"process_midi_event(), and %.0f of which were spent reading VLQ's.  That's an average of %.4f milliseconds per event.", 
	//	num_events, end_analyze - start_analyze, total_event, total_vlq, total_event / (double) num_events);
	//sprintf(buf, "Analysis of %d events took %.0f milliseconds.", 
	//	num_events, end_analyze - start_analyze);
	//MessageBox(hwndApp, buf, "Analysis complete.", 0);

	return 0;
}
int midi::load_midi(char *filename)
{
	FILE *infile = NULL, *outfile = NULL;
	char *MThd = "MThd";
	char *MTrk = "MTrk";
	char *RIFF = "RIFF";
	//unsigned char *text;
	unsigned char id[4];
	char buf[1024];
	unsigned int track = 0, i, len, endtrack = 0;
	//unsigned int offset, delta, intd;
	//char eventname[128];
	//unsigned char lastcmd = 0, cmd, d1, d2, d3, d4, d5;
	//signed char sd1;
	int success = 0;

	// Save the given filename
	strcpy(ms.filename, filename);

	// Dump any previously-loaded MIDI text and sysex events
	kill_all_midi_text();
	kill_all_midi_sysex();

	// Unload any previously-loaded MIDI data
	if (mh.num_tracks)
	{
		for (i = 0; i < mh.num_tracks; i++)
		{
			th[i].dataptr = NULL;
			if (th[i].data)
				free(th[i].data);
			memset(&th[i], 0, sizeof(track_header_t));		//어셈으로 Direct access to memory and initialize
		}
	}

	// Reset percussion flag
	ms.uses_percussion = 0;

	// Reset highest pitch bend value to zero
	ms.highest_pitch_bend = 0;

	// Reset channel states
	for (i = 0; i < 16; i++)
	{
		ms.channels[i].program_overridden = 0;
		ms.channels[i].muted = 0;
	}

	// Decide whether or not to perform pre-analysis
	ms.perform_analysis = 0;

	if (ms.perform_analysis)
	{
		outfile = fopen(analysis_file, "w");
		if (!outfile)
		{
			printf("Unable to open file for writing.\n");
			return 1;
		}
	}
	infile = fopen(filename, "rb");
	if (!infile)
	{
		printf("Unable to open file for reading.\n");
		return 1;
	}

	if (strlen(filename) > 4 && stristr(&filename[strlen(filename) - 4], ".SYX"))
	{
		handle_sysex_dump(infile);
		// Disable the "Display Analysis" button
		//EnableWindow(GetDlgItem(hwndApp, IDC_ANALYSIS), FALSE);
		//// Disable the "Display Text" button
		//EnableWindow(GetDlgItem(hwndApp, IDC_DISPLAY_TEXT), FALSE);
		//// Disable playback control button
		//EnableWindow(GetDlgItem(hwndApp, IDC_PLAY), FALSE);

		return 1;
	}

	__try
	{
		if (ms.perform_analysis)
			fprintf(outfile, "Analysis of %s\n\n", filename);

		// Read the MIDI file header
		read_bytes(infile, id, 4);

		// Check to see if the "MThd" ID is correct
		if (memcmp(MThd, id, 4))
		{
			// No?  Check for a RIFF header (RMID format)
			if (!memcmp(RIFF, id, 4))
			{
				// Yes!  Ok, skip past 4 byte filesize + 4 byte RMID
				read_bytes(infile, id, 4);
				read_bytes(infile, id, 4);
				read_bytes(infile, id, 4);
				read_bytes(infile, id, 4);
				// Now read the MIDI file header
				read_bytes(infile, id, 4);
				// Now look for MThd
				if (memcmp(MThd, id, 4))
				{
					sprintf(buf, "'%s' is not a MIDI file because it does not begin with \"MThd\".", filename);
					if (ms.perform_analysis)
						fprintf(outfile, "%s\n", buf);
					printf("TMIDI Error\n");
					return 1;
				}			
			}
			else
			{
				// STILL no MThd?  Search through the beginning of the file for MThd
				fseek(infile, 0, SEEK_SET);
				len = fread(buf, 1, sizeof(buf), infile);
				if (len > 4)
					for (i = 0; i < len - 4; i++)
						if (!memcmp(MThd, &buf[i], 4))
							break;
				if (len <= 4 || i == len - 4)
				{
					sprintf(buf, "'%s' is not a MIDI file because it does not begin with \"MThd\".", filename);
					if (ms.perform_analysis)
						fprintf(outfile, "%s\n", buf);
					printf("TMIDI Error\n");
					return 1;
				}
				else
				{
					fseek(infile, i, SEEK_SET);
					read_bytes(infile, id, 4);
					if (ms.perform_analysis)
						fprintf(outfile, "Warning: File is damaged... %d bytes of unexpected data before MThd header.\n", i);
				}
			}
		}

		// Read the header size
		mh.header_size = read_int(infile);
		if (ms.perform_analysis)
			fprintf(outfile, "Header size: %d bytes\n", mh.header_size);

		// Identify the file format
		mh.file_format = read_short(infile);
		if (ms.perform_analysis)
		{
			fprintf(outfile, "File format: ");
			switch (mh.file_format)
			{
			case 0: fprintf(outfile, "Type 0: Single-track\n"); break;
			case 1: fprintf(outfile, "Type 1: Multiple tracks, synchronous\n"); break;
			case 2: fprintf(outfile, "Type 2: Multiple tracks, asynchronous\n"); break;
			default: fprintf(outfile, "Unknown (%d)", mh.file_format);
				sprintf(buf, "Unknown MIDI file type: %d", mh.file_format);
				printf("TMIDI Error\n");
				return 1;
			}
		}

		// Output other information present in the header
		mh.num_tracks = read_short(infile);
		mh.num_ticks = read_short(infile);
		if (ms.perform_analysis)
		{
			fprintf(outfile, "Number of tracks: %d\n", mh.num_tracks);
			fprintf(outfile, "Ticks per quarter note: %d\n", mh.num_ticks);
		}

		// Read tracks
		while (!feof(infile))
		{
			// Read the track header
			if (!read_bytes(infile, id, 4))
				continue;
			// Check to see if the "MTrk" ID is correct
			if (memcmp(MTrk, id, 4))
			{
				if (ms.perform_analysis)
					fprintf(outfile, "Track header %d is not correct because it does not begin with \"MTrk\".\n", track + 1);
				if (track < mh.num_tracks)
				{
					sprintf(buf, "Track header %d is not correct because it does not begin with \"MTrk\"", track + 1);
					printf("TMIDI Warning\n");
				}
				break;
			}
			// Read track length in bytes
			th[track].length = read_int(infile);
			if (ms.perform_analysis)
				fprintf(outfile, "\n---- Track %d (%d bytes) ----\n\n", track + 1, th[track].length);

			// Read the track data into memory
			th[track].data = (unsigned char *) malloc(th[track].length);
			if (!th[track].data)
			{
				printf("malloc() failed trying to allocate memory for track data\n");
				break;
			}
			fread(th[track].data, th[track].length, 1, infile);
			track++;
			if (track >= MAX_MIDI_TRACKS)
			{
				sprintf(buf, "Warning: Max number of MIDI tracks reached (%d).\n\nI refuse to read any more from this file.", MAX_MIDI_TRACKS);
				//MessageBox(hwndApp, buf, "TMIDI Warning", MB_ICONWARNING);
				break;
			}
		}
		success = 1;

	}
	__finally
	{
		if (mh.num_tracks != track)
		{
			//sprintf(buf, "Warning: MIDI header indicated %d tracks but %d were found in the file.", mh.num_tracks, track);
			//MessageBox(hwndApp, buf, "Warning", MB_ICONWARNING);
			mh.num_tracks = track;
		}
		if (infile)
			fclose(infile);
		if (outfile)
			fclose(outfile);
		if (success)
		{
			sprintf(buf, "Loaded %s, analyzing...", filename);
			//SetWindowText(hwndStatusBar, buf);
			if (analyze_midi())
				goto LoadFailed;
			sprintf(buf, "Loaded %s.", filename);
			/*SetWindowText(hwndStatusBar, buf);*/
			strcpy(ms.filename, filename);
			// Enable the "Display Analysis" button
			//EnableWindow(GetDlgItem(hwndApp, IDC_ANALYSIS), ms.perform_analysis);
			//// Enable or disable the "Text" button depending on whether or not text was loaded
			//EnableWindow(GetDlgItem(hwndApp, IDC_DISPLAY_TEXT), midi_text_events ? TRUE : FALSE);
			//// Enable or disable the "Sysex" button depending on whether or not text was loaded
			//EnableWindow(GetDlgItem(hwndApp, IDC_DISPLAY_SYSEX), midi_sysex_events ? TRUE : FALSE);
			//// Enable playback control button
			//EnableWindow(GetDlgItem(hwndApp, IDC_PLAY), TRUE);
		}
		else
		{
LoadFailed:
			sprintf(buf, "Failed to load %s.", extract_filename(filename));
			//SetWindowText(hwndStatusBar, buf);
			//// Disable the "Display Analysis" button
			//EnableWindow(GetDlgItem(hwndApp, IDC_ANALYSIS), FALSE);
			//// Disable the "Display Text" button
			//EnableWindow(GetDlgItem(hwndApp, IDC_DISPLAY_TEXT), FALSE);
			//// Disable playback control button
			//EnableWindow(GetDlgItem(hwndApp, IDC_PLAY), FALSE);
		}
	}
	return 0;
}
void midi::playback_thread()//void *spointer)
{
	int tracks = mh.num_tracks;
	int i, j, polyphony, elapsed;
	int num_events;
	double curtime, starttime, pausetime, tmptime, timediff;
	double nexttrigger;
	char buf[256];
	char *ch;
	int first_pass;
	int tracks_active;
	int seeking = 0;
	float cstom_sleep=10;


	// Initialize seeking states
	ms.seeking = 0;
	ms.seek_sliding = 0;
	ms.seek_to = 0.0f;
	/*if (ms.found_note_on && ms.first_note_on > 0.0f)
	{
	ms.seeking = 1;
	ms.seek_to = ms.first_note_on;
	}*/

	// Update status line text
	sprintf(buf, "Playing %s...", extract_filename(ms.filename));
	//SetWindowText(hwndStatusBar, buf);

	// Show the default drum kit name on channel 10 if percussion is used by this song..
	// Otherwise blank out the drum kit name
	//if (ms.uses_percussion)
	//	SetDlgItemText(hwndApp, IDC_T0 + 9, "Standard");
	//else
	//	SetDlgItemText(hwndApp, IDC_T0 + 9, "");

	// Init MIDI-out device
	init_midi_out();//GetDlgItem(hwndApp, IDC_MIDI_OUT));
	if (!hout)
		return;

	// Set playback thread priority
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

	// Disable play button, enable pause and stop buttons
	//EnableWindow(GetDlgItem(hwndApp, IDC_PLAY), FALSE);
	//EnableWindow(GetDlgItem(hwndApp, IDC_PAUSE), TRUE);
	//EnableWindow(GetDlgItem(hwndApp, IDC_STOP), TRUE);

	for (i = 0; i < 16; i++)
	{
		// Set overridden instrument channels
		if (ms.channels[i].program_overridden)
		{
			if (i == 9)
			{
				ch = strchr(drum_kit_names[ms.channels[i].override_program], '-');
				//SetDlgItemText(hwndApp, IDC_T0 + i, ch + 2);
			}
			//else
			//SetDlgItemText(hwndApp, IDC_T0 + i, get_program_name(ms.channels[i].override_program, 0));
			set_channel_program(i, ms.channels[i].override_program, 0);
		}

		// Update channel mutes
		set_channel_mute(i, ms.channels[i].muted);

		// Reset displayed controller to none
		ms.channels[i].displayed_controller = -1;

		// Reset controller locks
		ms.channels[i].lock_controller = 0;
	}

	// Initialize modifiers
	ms.mod_pitch = 0;
	ms.mod_velocity = 0;

	// Initialize loop count
	ms.loop_count = 1;

	while (ms.loop_count--)
	{
BeginPlayback:
		// Initialize tempo
		set_tempo((int) (60000000.0f / ms.tempo));
		/*sprintf(buf, "Tempo: %.2f ms/tick, %.0f bpm", ms.tick_length, 60000000.0f / ms.tempo);
		SetDlgItemText(hwndApp, IDC_TICK, buf);
		SendDlgItemMessage(hwndApp, IDC_TEMPO_SLIDER, TBM_SETPOS, FALSE, (int) (60000000.0f / ms.tempo));
		*/

		// Initialize playback parameters
		num_events = 0;
		//ms.analyzing = 0;
		ms.analyzing = ms.seeking;
		ms.playing = 1;
		ms.paused = 0;
		ms.finished_naturally = FALSE;
		ms.stop_requested = 0;
		ms.tempo = 500000 / 1000;
		ms.tick_length = (double) ms.tempo / (double) mh.num_ticks;
		ms.peak_polyphony = 0;
		ms.current_text[0] = '\0';
		ms.title_displayed = 0;
		//SendDlgItemMessage(hwndApp, IDC_POLYPHONY_METER, PBM_SETRANGE, 0, MAKELPARAM(0, ms.peak_polyphony));

		// Reset channel states
		for (i = 0; i < 16; i++)
		{
			// Reset # of notes currently being played on this channel
			ms.channels[i].note_count = 0;
			ms.channels[i].drawn = 1;
			// Reset program values
			ms.channels[i].normal_program = 0;
			//ms.channels[i].override_program = -1;
			// Reset note values
			memset(ms.channels[i].notes, 0, sizeof(ms.channels[i].notes));
			// Reset controller values
			for (j = 0; j < 128; j++)
			{
				ms.channels[i].controllers[j] = -1;
				ms.channels[i].controller_overridden[j] = 0;
			}
			// Reset historical values
			ms.channels[i].last_controller = -1;
			ms.channels[i].last_controller_value = -1;
			ms.channels[i].last_note_pitch = -1;
			ms.channels[i].last_note_velocity = -1;
			ms.channels[i].last_pitch_bend = -1;
		}

		// Initialize track parameters
		for (i = 0; i < tracks; i++)
		{
			th[i].num_events_done = 0;
			//th[i].last_channel = -1;	// Let the analysis set the initial value for this
			th[i].last_controller = -1;
			th[i].last_controller_value = -1;
			th[i].last_note_pitch = -1;
			th[i].last_note_velocity = -1;
			//th[i].last_program = -1;	// Let the analysis set the initial value for this
			//th[i].last_bank = -1;		// Let the analysis set the initial value for this
			th[i].last_pitch_bend = -1;
			th[i].lastcmd = 0;
			th[i].enabled = 1;
			th[i].trigger = 0.0f;
			th[i].dataptr = th[i].data;
			th[i].tracknum = i;
		}

		// Record starting time
		ms.starttime = starttime = curtime = GetHRTickCount();
		//sprintf(buf, "starttime = %d", starttime);

		// Loop until we've been asked to stop
		first_pass = 1;
		while (!ms.stop_requested)
		{
			// See if we've been asked to seek and we're not already doing it
			if (ms.seeking && !seeking)
			{
				seeking = 1;
				goto BeginPlayback;		// Aaaah!  A goto!!
			}
			// Get current time
			if (!seeking)
				curtime = GetHRTickCount();
			// Schedule the next "wakeup time" MAX_MIDI_WAIT milliseconds into the future
			nexttrigger = curtime + MAX_MIDI_WAIT;
			// See if any tracks have pending data
			tracks_active = 0;
			for (i = 0; i < tracks; i++)
			{
				// Continue on to the next track if this track is disabled
				if (th[i].enabled)
					tracks_active = 1;
				else
					continue;

				// Disable this track if its data pointer has reached or exceeded the track length
				if (th[i].dataptr >= th[i].data + th[i].length)
				{
					th[i].enabled = FALSE;
					continue;
				}

				// Read the first event's delta time
				//if (th[i].trigger == 0.0f)
				if (first_pass)
				{
					th[i].dt = (double) read_vlq_mem(&th[i]) * ms.tick_length;
					th[i].trigger = curtime + th[i].dt;
				}

				//curtime = GetHRTickCount();

				// Process MIDI events until one is scheduled for a time in the future
				while (curtime >= th[i].trigger)
				{
					// Process the event for this track
					ms.curtime = curtime;
					if (process_midi_event(&th[i]))
					{
						ms.stop_requested = 1;
						break;
					}
					// Increment the global number of events processed, and the number of events for this track
					num_events++;
					th[i].num_events_done++;

					// Check for end of track
					if (!(th[i].enabled))
						break;

					// Read the next event's delta time
					th[i].dt = (double) read_vlq_mem(&th[i]) * ms.tick_length;
					th[i].trigger += th[i].dt;
				}
				// Check for end of track
				if (!(th[i].enabled))
					continue;

				// See if this track's trigger is the more recent than the next scheduled trigger
				if (th[i].trigger < nexttrigger)
					nexttrigger = th[i].trigger;
			}
			first_pass = 0;
			if (!seeking)
				curtime = GetHRTickCount();
			//sprintf(buf, "Sleeping for %.2f (now = %.2f, next = %.2f)\n", nexttrigger - curtime, curtime, nexttrigger);
			//OutputDebugString(buf);
			/*sprintf(buf, "%.1f", curtime);
			SetDlgItemText(hwndApp, IDC_CURRENT_TIME, buf);
			sprintf(buf, "%.1f", nexttrigger);
			SetDlgItemText(hwndApp, IDC_TRIGGER_TIME, buf);*/
			// Check to see if a pause has been requested
			if (ms.paused)
			{
				// Turn off the notes being played
				all_notes_off();
				// Save the time we paused at
				pausetime = curtime;
				// Wait until we're unpaused or not playing anymore
				while (1)
				{
					Sleep(100);
					if (!(ms.paused) || !(ms.playing) || ms.stop_requested)
						break;
				}
				// If we've been asked to stop.. break from the main playback loop
				if (!(ms.playing) || ms.stop_requested)
					break;
				// We need to resume.  Correct the start and trigger times to be up-to-date!
				curtime = GetHRTickCount();
				starttime += curtime - pausetime;
				nexttrigger += curtime - pausetime;
				for (i = 0; i < tracks; i++)
					th[i].trigger += curtime - pausetime;
			}

			if (!seeking)
			{
				// Set song current MIDI events / total MIDI events text
				sprintf(buf, "%d / %d", num_events, ms.num_events);//여기에서 프로그레스바 이벤트 발생시키면됨~
				printf("%d / %d\n", num_events, ms.num_events);
				//SetDlgItemText(hwndApp, IDC_EVENTS, buf);
				// Set MIDI events position slider
				//SendDlgItemMessage(hwndApp, IDC_EVENT_SLIDER, TBM_SETPOS, TRUE, num_events / 10);
				// Set song current time / total time text
				elapsed = (int) ((curtime - starttime) / 1000.0f);
				if (!ms.seek_sliding)
				{
					sprintf(buf, "%d:%02d / %d:%02d", elapsed / 60, elapsed % 60, ms.song_length / 60, ms.song_length % 60);
					//SetDlgItemText(hwndApp, IDC_SONG_LENGTH, buf);
					// Set song position slider
					//SendDlgItemMessage(hwndApp, IDC_SONG_SLIDER, TBM_SETPOS, TRUE, elapsed);
				}
				// Calculate and display polyphony
				for (polyphony = i = 0; i < 16; i++)
					polyphony += ms.channels[i].note_count;
				if (polyphony > ms.peak_polyphony)
				{
					ms.peak_polyphony = polyphony;
					//SendDlgItemMessage(hwndApp, IDC_POLYPHONY_METER, PBM_SETRANGE, 0, MAKELPARAM(0, ms.peak_polyphony));
				}
				sprintf(buf, "%02d/%02d", polyphony, ms.peak_polyphony);
				//SetDlgItemText(hwndApp, IDC_POLYPHONY, buf);
				//SendDlgItemMessage(hwndApp, IDC_POLYPHONY_METER, PBM_SETPOS, (WPARAM) polyphony, 0);
				// Update the tracks window, if it's open
				if (hwndTracks) printf("dd\n");
				//FillTracksListView(GetDlgItem(hwndTracks, IDC_TRACKS_LIST));
				// Update the channels window, if it's open
				if (hwndChannels) printf("tt\n");
				//FillChannelsListView(GetDlgItem(hwndChannels, IDC_CHANNELS_LIST));
				// Update graphical display
				//update_display(NULL);
			}

			// Wait until the next trigger time
			if (seeking)
			{
				curtime = nexttrigger;
				// See if the seek is done
				if (seeking && (curtime - starttime >= ms.seek_to))
				{
					// Seek is done - correct timing values
					tmptime = curtime;
					curtime = GetHRTickCount();
					timediff = tmptime - curtime;
					for (i = 0; i < mh.num_tracks; i++)
						th[i].trigger -= timediff;
					// Calculate corrected start time and elapsed time
					ms.starttime = starttime = curtime - timediff;
					elapsed = (int) (curtime - ms.starttime);
					ms.curtime = curtime;
					// Reset seek state flags
					seeking = ms.seeking = ms.analyzing = 0;
					// Turn all notes off
					all_notes_off();

					// Set channel values
					for (i = 0; i < 16; i++)
					{
						// Set program changes
						if (ms.channels[i].normal_program)
							set_channel_program(i, ms.channels[i].normal_program, ms.channels[i].last_bank);
						// Set controller values
						//for (j = 0; j < 128; j++)
						//	if (ms.channels[i].controllers[j] != -1)
						//		set_channel_controller(i, j, ms.channels[i].controllers[j]);
					}
				}
			}
			else
			{
				i = 0;
				while (curtime < nexttrigger && !(ms.stop_requested))
				{
					sprintf(buf, "Sleeping for %d ms\n", (int) (nexttrigger - curtime));
					OutputDebugString((LPCSTR)buf);
					Sleep((int) (nexttrigger - curtime));
					//Sleep(5);
					curtime = GetHRTickCount();
					i++;
					if ((i % 1000) == 0)
					{
						sprintf(buf, "curtime = %.1f, nexttrigger = %.1f, loop count = %d", curtime, nexttrigger, i);
						//SetWindowText(hwndStatusBar, buf);
					}
				}
				if (!tracks_active)
				{
					ms.finished_naturally = TRUE;
					break;
				}
			}
		}
		// Break out of looping if a stop was requested
		if (ms.stop_requested)
			break;
		// If the looping checkbox is checked, loop another time
		if (IsDlgButtonChecked(hwndApp, 1095)) //IDC_LOOP))
			ms.loop_count++;
	}
	// PLAYBACK HAS STOPPED
	// Turn off all the notes, reset the MIDI-out device, and close it
	all_notes_off();
	Sleep(50);
	midiOutReset(hout);
	close_midi_out();

	// Reset the track info displays
	for (i = 0; i < 16; i++)
	{
		//if (!(ms.channels[i].program_overridden))
		//SetDlgItemText(hwndApp, IDC_T0 + i, L"");
		memset(ms.channels[i].notes, 0, sizeof(ms.channels[i].notes));
		ms.channels[i].note_count = 0;
		ms.channels[i].displayed_controller = -1;
		ms.channels[i].lock_controller = 0;
		ms.channels[i].drawn = 1;
		//SendDlgItemMessage(hwndApp, IDC_TVU0 + i, PBM_SETPOS, 0, 0);
	}
	// Clear the note displays
	/*hdc = GetDC(hwndApp);
	if (hdc)
	{
	SelectObject(hdc, hNoteBackgroundBrush);
	for (i = 0; i < 16; i++)
	Rectangle(hdc, BAR_X, BAR_Y + i * BAR_VSPACE, BAR_X + BAR_WIDTH, BAR_Y + i * BAR_VSPACE + BAR_HEIGHT);
	}*/
	//update_display(NULL);
	// Clear the current text display
	//SetDlgItemText(hwndApp, IDC_CURRENT_TEXT, "");
	// Clear the polyphony display
	//SetDlgItemText(hwndApp, IDC_POLYPHONY, "");
	//SendDlgItemMessage(hwndApp, IDC_POLYPHONY_METER, PBM_SETPOS, 0, 0);
	// Set song current MIDI events / total MIDI events text
	//SetDlgItemText(hwndApp, IDC_EVENTS, "");
	// Set MIDI events position slider
	num_events = 0;
	sprintf(buf, "%d / %d", num_events, ms.num_events);
	//SetDlgItemText(hwndApp, IDC_EVENTS, buf);
	//SendDlgItemMessage(hwndApp, IDC_EVENT_SLIDER, TBM_SETPOS, TRUE, 0);
	// Set song current time / total time text
	elapsed = 0;
	sprintf(buf, "%d:%02d / %d:%02d", elapsed / 60, elapsed % 60, ms.song_length / 60, ms.song_length % 60);
	//SetDlgItemText(hwndApp, IDC_SONG_LENGTH, buf);
	// Set song position slider
	//SendDlgItemMessage(hwndApp, IDC_SONG_SLIDER, TBM_SETPOS, TRUE, 0);

	// Enable play button, disable pause and stop buttons
	//EnableWindow(GetDlgItem(hwndApp, IDC_PLAY), TRUE);
	//EnableWindow(GetDlgItem(hwndApp, IDC_PAUSE), FALSE);
	//EnableWindow(GetDlgItem(hwndApp, IDC_STOP), FALSE);

	ms.playing = 0;
	//PostMessage(hwndApp, WMAPP_DONE_PLAYING, 0, 0);
}
void midi::enum_devices()
{
	int indevs, outdevs;
	MIDIINCAPS incaps;
	MIDIOUTCAPS outcaps;
	int i, ret;
	//HWND hwndcb;
	midi_device_t *dev, *ld = NULL;

	//hwndcb = GetDlgItem(hwnd, IDC_MIDI_IN);
	/*SendMessage(hwndcb, CB_RESETCONTENT, 0, 0);
	SendMessage(hwndcb, CB_ADDSTRING, 0, (LPARAM) "[None]");*/
	indevs = midiInGetNumDevs();
	for (i = 0; i < indevs; i++)
	{
		ret = midiInGetDevCaps(i, &incaps, sizeof(incaps));
		if (ret != MMSYSERR_NOERROR)
			continue;

		// Set up a device node for this device
		dev = (midi_device_t *) calloc(1, sizeof(midi_device_t));
		//dev->user_device_name = strdup((const char*)incaps.szPname);
		printf("device = %s\n", dev->user_device_name = strdup((const char*)incaps.szPname));
		dev->input_device = 1;
		memcpy(&dev->incaps, &incaps, sizeof(MIDIINCAPS));
		dev->usable = 1;
		dev->standards = MIDI_STANDARD_GM;
		dev->next = NULL;
		if (!ld)
			midi_devices = dev;
		else
			ld->next = dev;
		ld = dev;

		//SendMessage(hwndcb, CB_ADDSTRING, 0, (LPARAM) incaps.szPname);
	}
	//SendMessage(hwndcb, CB_SETCURSEL, (WPARAM) midi_in_cb, 0);

	/*hwndcb = GetDlgItem(hwnd, IDC_MIDI_OUT);
	SendMessage(hwndcb, CB_RESETCONTENT, 0, 0);
	SendMessage(hwndcb, CB_ADDSTRING, 0, (LPARAM) "[None]");*/
	outdevs = midiOutGetNumDevs();
	for (i = 0; i < outdevs; i++)
	{
		ret = midiOutGetDevCaps(i, &outcaps, sizeof(outcaps));
		if (ret != MMSYSERR_NOERROR)
			continue;

		// Set up a device node for this device
		dev = (midi_device_t *) calloc(1, sizeof(midi_device_t));
		//dev->user_device_name = strdup((const char*)outcaps.szPname);
		printf("device = %s\n",dev->user_device_name = strdup((const char*)outcaps.szPname));
		memcpy(&dev->outcaps, &outcaps, sizeof(MIDIOUTCAPS));
		dev->usable = 1;
		dev->standards = MIDI_STANDARD_GM;
		dev->next = NULL;
		if (!ld)
			midi_devices = dev;
		else
			ld->next = dev;
		ld = dev;

		//SendMessage(hwndcb, CB_ADDSTRING, 0, (LPARAM) outcaps.szPname);
	}
	//SendMessage(hwndcb, CB_SETCURSEL, (WPARAM) midi_out_cb, 0);
}
void midi::run()
{
	int ErrorNumber, DOSErrorNumber;
     unsigned ThreadId;
     HANDLE hThread, hEvent;

     // Create a manual-reset nonsignaled unnamed event
     hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

     hThread = (HANDLE)_beginthreadex(NULL, 0, &Thread, (LPVOID)this, 0, &ThreadId);
     if (hThread == 0)
     {
          ErrorNumber = errno;
          DOSErrorNumber = _doserrno;
		  return;
     }
 

     //Sleep(10000<<1); // wait 2 seconds
     SetEvent(hEvent); // signal thread to end
	 //WaitForSingleObject( hThread, INFINITE );
     CloseHandle(hEvent);
     CloseHandle(hThread);

}
unsigned int WINAPI midi::Thread(void *p)
{
	 (  (midi* ) p )->playback_thread();
	 return 0;
}