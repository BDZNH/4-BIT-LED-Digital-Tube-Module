#include "mytime.h"

uint8_t LED_0F[17] =
{ //  0   1     2    3    4    5    6    7    8    9    A   B    C    D    E    F    -
	0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x8C,0xBF,0xC6,0xA1,0x86,0xFF,0xbf
};

mytime::mytime()
{
	year = 1900;
	md = 101;
	hm = 1;
	mytime_state = true;
	SERpin = 1;
	SCKpin = 2;
	RCKpin = 3;
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

bool mytime::gethm()
{
	return hm;
}

void mytime::show()
{
	//while(mytime_state)
	//{
	outnum(year);
	//delay(500);
	outnum(md);
	//delay(500);
	outnum(hm);
	//delay(500);
//}
}

void mytime::outnum(int num)
{
	int x1 = num / 1000;
	int x2 = (num / 100) % 10;
	int x3 = (num / 10) % 10;
	int x4 = num % 10;

	for (int i = 0; i < 200; ++i)
	{
		shiftOut(SERpin, SCKpin, MSBFIRST, LED_0F[x1]);
		shiftOut(SERpin, SCKpin, MSBFIRST, 0x08);
		digitalWrite(RCKpin, LOW);
		digitalWrite(RCKpin, HIGH);
		delay(3);

		shiftOut(SERpin, SCKpin, MSBFIRST, LED_0F[x2]);
		shiftOut(SERpin, SCKpin, MSBFIRST, 0x04);
		digitalWrite(RCKpin, LOW);
		digitalWrite(RCKpin, HIGH);
		delay(3);

		shiftOut(SERpin, SCKpin, MSBFIRST, LED_0F[x3]);
		shiftOut(SERpin, SCKpin, MSBFIRST, 0x02);
		digitalWrite(RCKpin, LOW);
		digitalWrite(RCKpin, HIGH);
		delay(3);

		shiftOut(SERpin, SCKpin, MSBFIRST, LED_0F[x4]);
		shiftOut(SERpin, SCKpin, MSBFIRST, 0x01);
		digitalWrite(RCKpin, LOW);
		digitalWrite(RCKpin, HIGH);
		delay(3);
	}

}

void mytime::setup()
{
	if (-1 == wiringPiSetup())
	{
		std::cout << "setup error" << std::endl;
		exit(-1);
	}

	pinMode(SERpin, OUTPUT);
	pinMode(RCKpin, OUTPUT);
	pinMode(SCKpin, OUTPUT);
}