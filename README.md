# Altsound-Editor
Simple Editor for PinMame Altsound.CSV files

This program is provides as is without any warranty and support.
If you think it is missing a function please feel free to modify it.

From the PinMAME documentation:

- Extend builtin alternate sound file support (Sound Mode 1) with a new CSV file-format

  Currently specified 8 fields/columns should have a standard order. But in order to be extensible, the first row must always contain all column names:
   "ID","CHANNEL","DUCK","GAIN","LOOP","STOP","NAME","FNAME"
  (So put this definition above as-is into the first line of the CSV)
  Possible future extensions could be:
   "GROUP","SHAKER","SERIAL"

  Then for each sound/line:
   ID: hexadecimal integer (as string) representing the soundboard command (format e.g. "0x10e"), technical ID as it comes from the MPU.
   CHANNEL: use specified channel for the sample. If something is already playing on that channel it will be stopped. Typical channel assignment should be 0: background music, 1: short music snippets, that interrupt or end the background music, everything else (2..15): arbitrary channels. If field is empty, any free channel (2..15) is used.
   DUCK: reduce volume of the background music when playing the sample. Range 0-100 (i.e. percentage).
   GAIN: increase or reduce volume of the sample. Range 0-100. 50 leaves the sample volume as-is (it's recommended to not go over 50 to avoid sample clamping/distortion).
   LOOP: loop the sample this many times. Range 0-100, where 100 represents endless looping of the sample.
   STOP: stop playback of background music. Can be 0 or 1.
   NAME: string, descriptive/internal name of the sample.
   FNAME: string, actual filepath/filename of the sample. Can contain any path prefixes if one likes to organize sound files in directories.
  The only fields that need to be specified are id, name and fname, the rest can optionally be left empty and will be filled in with defaults.

  If the table contains more than one record for a certain ID, the sound engine will pick one of these randomly. These same IDs must be grouped together one after another in a sequence.
