#include "mytime.h"

uint8_t LED_0F[17] =
{ //  0   1     2    3    4    5    6    7    8    9    A   B    C    D    E    F    -
	0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x8C,0xBF,0xC6,0xA1,0x86,0xFF,0xbf
};

bool mytime_state;

mytime::mytime()
{
	year = 1900;
	md = 101;
	hm = 1;
	DIOpin = 1;
	SCLKpin = 2;
	RCLKpin = 3;
	setup();
	//show();
	// thread th(&mytime::show,this);
	// th.detach();
}

bool mytime::setyear(int year)
{
	this->year = year;
	return true;
}

bool mytime::setmd(int md)
{
	this->md = md;
	return true;
}

bool mytime::sethm(int hm)
{
	this->hm = hm;
	return true;
}


int mytime::getyear()
{
	return year;
}

int mytime::gethm()
{
	return hm;
}

int mytime::getmd()
{
	return md;
}

void mytime::setup()
{
	if (-1 == wiringPiSetup())
	{
		std::cout << "setup error" << std::endl;
		exit(-1);
	}

	pinMode(DIOpin, OUTPUT);
	pinMode(SCLKpin, OUTPUT);
	pinMode(RCLKpin, OUTPUT);
}


void show(mytime &mTime)
{
	while(mytime_state)
	{
		outnum(mTime,mTime.getyear());
		delay(3);
		outnum(mTime,mTime.getmd());
		delay(3);
		outnum(mTime,mTime.gethm());
		delay(3);
	}
}

void outnum(mytime &mTime,int num)
{
	int x1 = num / 1000;
	int x2 = (num / 100) % 10;
	int x3 = (num / 10) % 10;
	int x4 = num % 10;

	for (int i = 0; i < 200; ++i)
	{
		shiftOut(mTime.DIOpin, mTime.SCLKpin, MSBFIRST, LED_0F[x1]);
		shiftOut(mTime.DIOpin, mTime.SCLKpin, MSBFIRST, 0x08);
		digitalWrite(mTime.RCLKpin, LOW);
		digitalWrite(mTime.RCLKpin, HIGH);
		delay(3);

		shiftOut(mTime.DIOpin, mTime.SCLKpin, MSBFIRST, LED_0F[x2]);
		shiftOut(mTime.DIOpin, mTime.SCLKpin, MSBFIRST, 0x04);
		digitalWrite(mTime.RCLKpin, LOW);
		digitalWrite(mTime.RCLKpin, HIGH);
		delay(3);

		shiftOut(mTime.DIOpin, mTime.SCLKpin, MSBFIRST, LED_0F[x3]);
		shiftOut(mTime.DIOpin, mTime.SCLKpin, MSBFIRST, 0x02);
		digitalWrite(mTime.RCLKpin, LOW);
		digitalWrite(mTime.RCLKpin, HIGH);
		delay(3);

		shiftOut(mTime.DIOpin, mTime.SCLKpin, MSBFIRST, LED_0F[x4]);
		shiftOut(mTime.DIOpin, mTime.SCLKpin, MSBFIRST, 0x01);
		digitalWrite(mTime.RCLKpin, LOW);
		digitalWrite(mTime.RCLKpin, HIGH);
		delay(3);
	}
}