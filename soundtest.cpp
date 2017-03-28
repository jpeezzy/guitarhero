// soundtest.cpp : Defines the entry point for the console application.
//test if it can even play wav files
#ifndef __linux__ 
	#include <windows.h>
	#include <Xinput.h>
	#include <WinBase.h>
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
	HSAMPLE streamHandle;
	HCHANNEL channel;
	/* Initialize output device */
	BASS_Init(device, freq, BASS_DEVICE_DEFAULT, 0, NULL);
	streamHandle = BASS_SampleLoad(false, file, 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		/* Once you are done with your sample you should free it, but we don't wnat to until the play sample is over, or else nothing happens */
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

std::map <WORD, string> getfilename(){
	std::map <WORD, string> wavfile;
	wavfile[XINPUT_GAMEPAD_A + XINPUT_GAMEPAD_DPAD_DOWN] = "D.Wav"; //in terms of button mapping this is GREEN
	wavfile[XINPUT_GAMEPAD_B + XINPUT_GAMEPAD_DPAD_DOWN] = "D.wav"; // RED
	wavfile[XINPUT_GAMEPAD_X + XINPUT_GAMEPAD_DPAD_DOWN] = "D.wav"; // BLUE 
	wavfile[XINPUT_GAMEPAD_Y + XINPUT_GAMEPAD_DPAD_DOWN] = "D.wav"; // YELLOW 
	wavfile[XINPUT_GAMEPAD_LEFT_SHOULDER + XINPUT_GAMEPAD_DPAD_DOWN] = "D.wav"; //Orange doesn't have adefault. Its 0x100 or 256
	wavfile[XINPUT_GAMEPAD_DPAD_DOWN + XINPUT_GAMEPAD_DPAD_DOWN] = ""; //down flipper ^_^
	return wavfile; 
};
int main()
{
	_XINPUT_GAMEPAD gamepad;
	DWORD dwResult;
	for (DWORD i = 0; i< XUSER_MAX_COUNT; i++)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

	    // Simply get the state of the controller from XInput.
		dwResult = XInputGetState(i, &state);

		if (dwResult == ERROR_SUCCESS)
		{
			cout << "Controller is connected" << endl;

		}
		else
		{
			cout << "Controller is not connected" << endl;
		}
	}
	

	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	std::map <WORD, string> roar = getfilename();
	input* ptoin1;
	ptoin1 = &input1;
	int i = 0;
	while (1) {
		//cout << "does it go here?";
	//	cout << "here too ??? ";
		dwResult = XInputGetState(0, &state);
	//	if (state.Gamepad.wButtons == XINPUT_GAMEPAD_LEFT_SHOULDER) //orange left sholder
		cout << state.Gamepad.wButtons << endl;
		Sleep(100);
		playwav(roar[state.Gamepad.wButtons]);
		;
	}
return 0;
}

