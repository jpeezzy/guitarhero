// soundtest.cpp : Defines the entry point for the console application.
//test if it can even play wav files
#ifndef __linux__ 
	#include <windows.h>
#endif

#include <string>
#include <map> 
#include "bass.h" //look at documentation for fucks sake http://stackoverflow.com/questions/7180920/bass-play-a-stream
#include <iostream>
#include <stdio.h> //provides funciton _getch(void) which can be used to read keystroke without echoing them. 
#include <memory.h>
#include <conio.h>

using namespace std;
void playwav(std::string filename) {
	int device = -1;
	int freq = 44100;
	const void* file = filename.c_str();
	//cout << "get here??";
	HSAMPLE streamHandle;
	HCHANNEL channel;
	/* Initialize output device */
	BASS_Init(device, freq, BASS_DEVICE_DEFAULT, 0, NULL);
	streamHandle = BASS_SampleLoad(false, file, 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		/* Once you are done with your sample you should free it */
		BASS_ChannelPlay(channel, FALSE);
		//place all files in same directory or else shit goes down just put all files in resouces even though you're not using anything
		//http://www.cplusplus.com/forum/windows/26944/
	/* Load sampleza and play it */	
}

struct input {
	char button;
	char strum;
};
input input1, input2;

std::map <string, string> getfilename(){
	std::map <string, string> wavfile;
	wavfile["ah"] = "D.Wav";
	wavfile["sh"] = "D.wav";
	wavfile["dh"] = "D.wav";
	wavfile["fh"] = "D.wav";
	wavfile["gh"] = "D.wav";
	wavfile["hh"] = "D.wav";
	return wavfile; 
};
int main()
{	
	std::map <string, string> roar = getfilename();
	input* ptoin1;
	ptoin1 = &input1;
	int i = 0;
	while (1) {
		input1.button = _getch(); cout << input1.button;
		input1.strum = _getch(); cout << input1.strum;
		char concatonated[] = { input1.button, input1.strum, '\0' };
		string combo = string(concatonated);
		playwav(roar[combo]);
	}
return 0;
}

