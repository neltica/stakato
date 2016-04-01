#pragma once

#define MAX_MIDI_TRACKS	512

#include <Windows.h>

#include <commctrl.h>
#include <process.h>
#include <winsock.h>

#include <stdio.h>
#include <ctype.h>
#include <io.h>
#include <math.h>
#include <assert.h>

typedef struct playlist_t {
	char filename[MAX_PATH];
	struct playlist_t *prev;
	struct playlist_t *next;
} playlist_t;

typedef struct midi_header_t {
	char id[4];							// MIDI header ID ("MThd")
	unsigned int header_size;			// Size of header in bytes
	unsigned short file_format;			// MIDI file type (0, 1, or 2)
	unsigned short num_tracks;			// Number of tracks in MIDI file
	unsigned short num_ticks;			// Number of ticks per quarter note (used to calc tempo)
} midi_header_t;

typedef struct track_header_t {
	char id[4];							// Track header ID ("MTrk")
	unsigned int length;				// Length of track chunk in bytes
	unsigned int num_events;			// Number of events in this track
	unsigned int num_events_done;		// Number of events processed in this track
	unsigned char *data;				// Pointer to beginning of track chunk
	unsigned char *dataptr;				// Pointer to current location in track chunk
	double start;						// Starting time of current event
	double trigger;						// Ending time of current event
	double dt;							// Length of current event in ticks
	char enabled;						// Is this track enabled?
	unsigned short tracknum;			// Number of this track
	unsigned char lastcmd;				// Last command byte (used in running mode)
	// Historical values
	char name[256];						// Name of this track
	signed char last_channel;			// Last channel used by this track
	signed char last_note_pitch;		// Last note pitch played from this track
	signed char last_note_velocity;		// Last note velocity played from this track
	signed char last_controller;		// Last controller set from this track
	signed char last_controller_value;	// Last controller value set from this track
	signed char last_program;			// Last program set from this track
	signed char last_bank;				// Last bank set from this track
	signed int last_pitch_bend;			// Last pitch bend set from this track
} track_header_t;

typedef struct channel_state_t {
	// State values
	int normal_program;					// Normal program used by this channel
	int override_program;				// Program that the user has overridden this channel with
	unsigned char notes[128];			// Current velocity for each possible note (0 is off)
	signed short int controllers[128];	// Continuous controller values (-1 is unset)
	unsigned char controller_overridden[128];	// Is this controller overridden with a user-specified value?
	int note_count;						// Number of notes currently on
	int displayed_controller;			// Currently displayed controller (over background for note display)
	unsigned char lock_controller;		// Prevent automatically switching displayed controller to last used?
	// State flags
	int program_overridden;				// Has the user overridden this channel's program?
	int muted;							// Is this channel muted?
	int drawn;							// Have lines been drawn for this channel since last frame?
	// Historical values
	signed char track_references[MAX_MIDI_TRACKS];	// Tracks which have events on this channel
	signed char last_note_pitch;		// Last note pitch played from this track
	signed char last_note_velocity;		// Last note velocity played from this track
	signed char last_controller;		// Last controller set from this track
	signed char last_controller_value;	// Last controller value set from this track
	signed char last_program;			// Last program set from this track
	signed char last_bank;				// Last bank set from this track
	signed int last_pitch_bend;			// Last pitch bend set from this track
} channel_state_t;

typedef struct midi_state_t {
	char perform_analysis;				// Should this song be analyzed on loading?
	char analyzing;						// Is this song currently being analyzed?
	char seek_sliding;					// Is the seek bar sliding? (user holding down button)
	char seeking;						// Is this song currently seeking?
	double seek_to;						// Place to seek to (in milliseconds)
	int stop_requested;					// Has there been a request to stop the playback thread?
	int playing;						// Is the playback thread playing?
	int paused;							// Is the playback thread paused?
	int found_note_on;					// Has there been a Note On event yet?
	double first_note_on;				// Time when the first Note On event was found
	int finished_naturally;				// Did the current MIDI file finish naturally?
	int loop_count;						// Number of times left to loop the playback
	double starttime;					// Starting playback time
	double curtime;						// Current playback time
	unsigned int tempo;					// Current tempo
	double tick_length;					// Current tick length in milliseconds
	int song_length;					// Length of song in seconds
	int num_events;						// Number of MIDI events in song
	int peak_polyphony;					// Peak polyphony seen throughout the song
	int uses_percussion;				// Does this MIDI file use percussion? (channel 10)
	int highest_pitch_bend;				// Highest pitch bend used in song (used in pitch bend visualization calculations)
	signed int mod_velocity;			// Velocity modification (-127 to 127)
	signed int mod_pitch;				// Pitch modification (-127 to 127)
	char current_text[256];				// Current text event being displayed
	int title_displayed;				// Has the title been displayed yet?
	channel_state_t channels[16];		// Channel state structs
	int midi_standard;					// MIDI standard used by this MIDI file (as sysex indicates)
	char filename[256];
} midi_state_t;

typedef struct midi_text_t {
	char *midi_text;					// MIDI text string
	int text_type;						// Type of text event
	double midi_time;					// Time (in seconds) when this text event occurs
	int track;							// Track this text is embedded in
	int track_offset;					// Offset (in bytes) where this text event occurs

	midi_text_t *next;
} midi_text_t;

typedef struct midi_sysex_t {
	unsigned char *data;				// Pointer to sysex data (in track chunk in memory)
	int length;							// Length of this sysex
	double midi_time;					// Time (in seconds) when this sysex occurs
	int track;							// Track this sysex is embedded in
	int track_offset;					// Offset (in bytes) where this sysex occurs
	int channel;						// Channel this sysex data goes out on

	midi_sysex_t *next;
} midi_sysex_t;

typedef struct midi_device_t {
	char *user_device_name;				// User-defined name for this device
	char enabled;						// Is this device currently enabled for playback?
	char usable;						// Does the user consider this device usable?
	int standards;						// Device type flags (MT-32, GM, GS, XG)
	char dx_device;						// Is this a DirectMusic device?
	char input_device;					// Is this an input device?
	MIDIINCAPS incaps;					// Input device caps
	MIDIOUTCAPS outcaps;				// Output device caps

	midi_device_t *next;
} midi_device_t;


//#include "resource.h"
class midi
{
public:
	//Thread
	DWORD dwThreadID;

	//channel track name
	int track[16];
	int track_program[16];
	int track_count;

	// Windows variables
	HINSTANCE ghInstance ;
	HWND hwndApp ;
	HWND hwndText;
	HWND hwndStatusBar;
	HKEY key;	// handle to registry key
	HHOOK g_hhk;	// hook for tooltips
	HWND g_hwndTT;	// window handle for tooltip control
	char temp_dir[MAX_PATH];
	char analysis_file[MAX_PATH];
	char filename_to_load[MAX_PATH];

	// GDI resources
	HBRUSH hNoteBackgroundBrush;
	HBRUSH hControllerBrush;
	HPEN hNoteBackgroundPen;
	HFONT hControllerFont;
	HFONT hJapaneseFont;

	// Tracks window variables
	HWND hwndTracks;
	int tracksLastValuesSet;

	// Channels window variables
	HWND hwndChannels;
	int channelsLastValuesSet;

	// Sysex window variables
	HWND hwndSysex;
	int sysexLastValuesSet;

	// Settings saved in the registry
	int midi_in_cb;
	int midi_out_cb;
	int appRectSaved;
	int textRectSaved;
	int tracksRectSaved;
	int channelsRectSaved;
	int sysexRectSaved;
	int genericTextRectSaved;
	RECT appRect;
	RECT textRect;
	RECT tracksRect;
	RECT channelsRect;
	RECT sysexRect;
	RECT genericTextRect;
	int alwaysCheckAssociations;

	// MIDI I/O handles
	HMIDIIN hin;
	HMIDIOUT hout;

	// Timing variables
	LARGE_INTEGER LIfreq;
	LARGE_INTEGER LIms_time;
	int freq;
	int hr_ms_time;


	midi_device_t *midi_devices;		// MIDI devices
	playlist_t *playlist;			// Playlist
	playlist_t *playback_head;		// Pointer to playlist entry currently being played (or last played)
	midi_header_t mh;						// MIDI file header struct
	track_header_t th[MAX_MIDI_TRACKS];		// Track state structs
	midi_state_t ms;						// MIDI state struct
	midi_text_t *midi_text_events;	// MIDI text events
	midi_sysex_t *midi_sysex_events;	// MIDI sysex events
	char mt32_patch_groups[128];			// MT-32 timbre group for a given patch
	char mt32_patch_programs[128];			// MT-32 program number for a given patch
	char mt32_memory_names[64][11];			// MT-32 memory timbre names

	char **program_names;

public:
	midi(void);
	~midi(void);
	void enum_devices();
	int load_midi(char *filename);
	int analyze_midi(void);
	int handle_sysex_dump(FILE *fp);
	void playback_thread();//void *spointer);
	void close_midi_out(void);
	inline double GetHRTickCount(void);
	char *extract_filename(char *filename);
	void init_midi_out();//(HWND hwndcb);
	void kill_all_midi_text(void);
	void kill_all_midi_sysex(void);
	void set_channel_mute(int channel, int mute);
	int process_midi_event(track_header_t *th);
	midi_sysex_t *new_midi_sysex(unsigned char *data, int length, double midi_time, int track, int track_offset, int channel);
	midi_text_t *new_midi_text(char *midi_text, int text_type, double midi_time, int track, int track_offset);
	inline unsigned int read_vlq_mem(track_header_t *th);
	unsigned char read_byte_mem(track_header_t *th);
	unsigned int read_int_mem(track_header_t *th);
	unsigned short int read_short_mem(track_header_t *th);
	int read_bytes_mem(track_header_t *th, unsigned char *buf, int num);
	void check_midi_standard(unsigned char *data);
	void set_tempo(int new_tempo);
	void note_on(unsigned char on, unsigned char note, unsigned char velocity, unsigned char chan);
	void update_note_volume(char channel, char note, char volume);
	char *interpret_sysex(unsigned char *s, int len);
	void init_mt32_state(void);
	void interpret_mt32_timbre_memory(unsigned char *s, int len);
	void interpret_mt32_patch_memory(unsigned char *s, int len);
	char *get_yamaha_effect_name(unsigned char effect);
	char interpret_sysex_part(unsigned char c);
	void set_channel_program(int channel, int program, int bank);
	char *get_program_name(unsigned char program, unsigned char bank);
	char *get_drum_kit_name(int program);
	void output_sysex_data(unsigned char channel, unsigned char *data, int length);
	void set_mod_pitch(signed int i);
	void set_mod_velocity(signed int i);
	char *stristr(char *src, char *target);
	void all_notes_off(void);
	void all_notes_off_channel(int channel);
	int read_bytes(FILE *fp, unsigned char *buf, int num);
	unsigned int read_int(FILE *fp);
	unsigned short int read_short(FILE *fp);
	void run();
	static unsigned int WINAPI Thread(LPVOID);
};

