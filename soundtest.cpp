// soundtest.cpp : Defines the entry point for the console application.
//test if it can even play wav files


#include "stdafx.h"
#include <memory.h>
#include "bass.h" //look at documentation for fucks sake http://stackoverflow.com/questions/7180920/bass-play-a-stream
#include <windows.h>
#include <thread>
#include <iostream>
#include <mmsystem.h>
#include <stdio.h> //provides funciton _getch(void) which can be used to read keystroke without echoing them. 
#include <conio.h>
#include <WinBase.h> //threadpools/ do this later ^_^ https://msdn.microsoft.com/en-us/library/windows/desktop/ms684847(v=vs.85).aspx#thread_pool_functions
using namespace std;
void stopmp3() {
	PlaySound(NULL, NULL, SND_ASYNC);
}
void playwav(char button, char flip, int counter) {
	//BASS_Free();
	int device = -1;
	int freq = 44100;
	//cout << "get here??";
	HSAMPLE streamHandle;
	HCHANNEL channel;
	/* Initialize output device */
	BASS_Init(device, freq, BASS_DEVICE_DEFAULT, 0, NULL);
	char concatonated[] = { button, flip, '\0' };
	//cout << "concatonated is : " << concatonated;
	string str(concatonated);
	if (strcmp(concatonated, "ah") == 0) //playsound documentation https://msdn.microsoft.com/en-us/library/windows/desktop/dd743680(v=vs.85).aspx
	{
		streamHandle = BASS_SampleLoad(false, "D.wav", 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		/* Once you are done with your sample you should free it */
		BASS_ChannelPlay(channel, FALSE);
		//place all files in same directory or else shit goes down just put all files in resouces even though you're not using anything
		//http://www.cplusplus.com/forum/windows/26944/
	}
	else if (strcmp(concatonated, "sh") == 0)
	{
		streamHandle = BASS_SampleLoad(false, "D.wav", 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		BASS_ChannelPlay(channel, FALSE);
	}
	else if (strcmp(concatonated, "dh") == 0)
	{
		streamHandle = BASS_SampleLoad(false, "D.wav", 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		BASS_ChannelPlay(channel, FALSE);
	}
	else if (strcmp(concatonated, "fh") == 0)
	{
		streamHandle = BASS_SampleLoad(false, "D.wav", 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		BASS_ChannelPlay(channel, FALSE);
	}
	else if (strcmp(concatonated, "gh") == 0)
	{
		streamHandle = BASS_SampleLoad(false, "D.wav", 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		BASS_ChannelPlay(channel, FALSE);
	}
	else if (strcmp(concatonated, "hh") == 0)
	{
		BASS_Free();
		cout << "you reached here!"; return;
	}
	else
		cout << "not a valid input" << endl; return;

	return;
	/* Load sample and play it */
	

}

void playwav1(char button, char flip, int counter) {
	//BASS_Free();
	int device = -1;
	int freq = 44100;
	//cout << "get here??";
	HSAMPLE streamHandle;
	HCHANNEL channel;
	/* Initialize output device */
	BASS_Init(device, freq, BASS_DEVICE_DEFAULT, 0, NULL);
	char concatonated[] = { button, flip, '\0' };
	//cout << "concatonated is : " << concatonated;
	string str(concatonated);
	if (strcmp(concatonated, "ah") == 0) //playsound documentation https://msdn.microsoft.com/en-us/library/windows/desktop/dd743680(v=vs.85).aspx
	{
		streamHandle = BASS_SampleLoad(false, "D.wav", 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		/* Once you are done with your sample you should free it */
		BASS_ChannelPlay(channel, FALSE);
		//place all files in same directory or else shit goes down just put all files in resouces even though you're not using anything
		//http://www.cplusplus.com/forum/windows/26944/
	}
	else if (strcmp(concatonated, "sh") == 0)
	{
		streamHandle = BASS_SampleLoad(false, "D.wav", 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		BASS_ChannelPlay(channel, FALSE);
	}
	else if (strcmp(concatonated, "dh") == 0)
	{
		streamHandle = BASS_SampleLoad(false, "D.wav", 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		BASS_ChannelPlay(channel, FALSE);
	}
	else if (strcmp(concatonated, "fh") == 0)
	{
		streamHandle = BASS_SampleLoad(false, "D.wav", 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		BASS_ChannelPlay(channel, FALSE);
	}
	else if (strcmp(concatonated, "gh") == 0)
	{
		streamHandle = BASS_SampleLoad(false, "D.wav", 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_OVER_POS | BASS_SAMPLE_OVER_VOL);
		channel = BASS_SampleGetChannel(streamHandle, FALSE);
		BASS_ChannelPlay(channel, FALSE);
	}
	else if (strcmp(concatonated, "hh") == 0)
	{
		BASS_Free();
		cout << "you reached here!"; return;
	}
	else
		cout << "not a valid input" << endl; return;
	return;
	/* Load sample and play it */
}

struct input {
	char button;
	char strum;
};
input input1, input2; 

int main()
{	
	input* ptoin1; 
	ptoin1 = &input1; 
	int i = 0;
	while (1) {
		i++;
		input1.button = _getch(); cout << input1.button;
		input1.strum = _getch(); cout << input1.strum;
		playwav(input1.button,input1.strum, i);
		input2.button = _getch(); cout << input1.button;
		input2.strum = _getch(); cout << input1.strum;
		playwav1(input2.button, input2.strum, i);


	}



	//i don't need to use threads
		//figure out how to join thread
	//cout << "roar";
//https://www.tutorialcup.com/cplusplus/multithreading.htm
	
return 0;
}

