// soundtest.cpp : Defines the entry point for the console application.

//Includes
#include <windows.h>
#include <Xinput.h> //https://msdn.microsoft.com/en-us/library/windows/desktop/ee417001(v=vs.85).aspx
#include <WinBase.h>
#include <string>
#include <map> 
#include "bass.h" //look at documentation for fucks sake http://stackoverflow.com/questions/7180920/bass-play-a-stream
#include <iostream>
#include <stdio.h> //provides funciton _getch(void) which can be used to read keystroke without echoing them. 
#include <memory.h>
#include <conio.h>

using namespace std;

//Constructors
void LED(); //44
std::map <WORD, string> getfilename(); //64
void playwav(std::string filename); //76

//Main Loop
int main()
{
	_XINPUT_GAMEPAD gamepad; DWORD dwResult; DWORD  dwp1= 0x0000;
	XINPUT_STATE state; //declare state object from xinput_state struct (get gamepad state)
	ZeroMemory(&state, sizeof(XINPUT_STATE)); //finding memory location of zero memory
	std::map <WORD, string> roar = getfilename();
	WORD wammy = 0x0; WORD previousconfig = 0;
	while (1) 
	{
		LED();
		dwResult = XInputGetState(0, &state);
		if (state.Gamepad.sThumbRX >= 0)
			wammy = 0x0020;
		else
			wammy = 0x0;

		if (previousconfig == state.Gamepad.wButtons + wammy)
		{
			cout << "stays the same" << endl;
			dwp1 = state.dwPacketNumber;
			continue;
		}
		cout << "dwstatepacketnumber==" << state.dwPacketNumber << endl;

		//now we have new information. Wammy bar goes from -32768 (-0x8000) to 32767 (0x8000); member SHORT sThumbRX of struct Gamepad;
		cout << state.Gamepad.wButtons + wammy << endl;
		Sleep(100);
		previousconfig = state.Gamepad.wButtons + wammy;
		playwav(roar[state.Gamepad.wButtons + wammy]);
		
		;
	}
	return 0;
}

//Functions
void LED() {
	_XINPUT_GAMEPAD gamepad; 
	DWORD dwResult; XINPUT_STATE state; //declare state object from xinput_state struct
	ZeroMemory(&state, sizeof(XINPUT_STATE)); //finding memory location of zero memory
	for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		// Simply get the state of the controller from XInput.
		dwResult = XInputGetState(i, &state);
	}

}

std::map <WORD, string> getfilename() {
	std::map <WORD, string> wavfile;
	wavfile[XINPUT_GAMEPAD_A + XINPUT_GAMEPAD_DPAD_DOWN] = "D.Wav"; //in terms of button mapping this is GREEN
	wavfile[XINPUT_GAMEPAD_B + XINPUT_GAMEPAD_DPAD_DOWN] = "ddouble.wav"; // RED
	wavfile[XINPUT_GAMEPAD_X + XINPUT_GAMEPAD_DPAD_DOWN] = "D.wav"; // BLUE 
	wavfile[XINPUT_GAMEPAD_Y + XINPUT_GAMEPAD_DPAD_DOWN] = "D.wav"; // YELLOW 
	wavfile[XINPUT_GAMEPAD_LEFT_SHOULDER + XINPUT_GAMEPAD_DPAD_DOWN] = "D.wav"; //Orange doesn't have adefault. Its 0x100 or 256
	wavfile[XINPUT_GAMEPAD_DPAD_DOWN + XINPUT_GAMEPAD_DPAD_DOWN] = ""; //down flipper ^_^
	wavfile[XINPUT_GAMEPAD_A + XINPUT_GAMEPAD_DPAD_DOWN + 0x0020] = "D.Wav";//wammy file
	wavfile[XINPUT_GAMEPAD_B + XINPUT_GAMEPAD_DPAD_DOWN + 0x0020] = "stop.wav";//stop

	return wavfile;
};

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

	if (!filename.compare("stop.wav"))
	{
		BASS_Free();
		BASS_Init(device, freq, BASS_DEVICE_DEFAULT, 0, NULL);
		streamHandle = BASS_SampleLoad(false, file, 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		BASS_ChannelPlay(channel, FALSE);
		Sleep(1200);
		BASS_Free();
		return;
			}
	/* Once you are done with your sample you should free it, but we don't wnat to until the play sample is over, or else nothing happens */
	BASS_ChannelPlay(channel, FALSE);
	//place all files in same directory or else shit goes down just put all files in resouces even though you're not using anything
	//http://www.cplusplus.com/forum/windows/26944/
	/* Load sampleza and play it */
}

