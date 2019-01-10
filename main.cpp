#include "mytime.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

int main()
{
	mytime mTime;

	int year, md, hm;
	time_t tt;
	time(&tt);
	tt = tt + 8 * 3600;
	tm* t = gmtime(&tt);
	year = t->tm_year + 1900;
	md = (t->tm_mon + 1) * 100 + t->tm_mday;
	hm = t->tm_hour * 100 + t->tm_min;
	mTime.setyear(year);
	mTime.setmd(md);
	mTime.sethm(hm);
	mTime.show();
	while (true)
	{
		time(&tt);
		tt = tt + 8 * 3600;
		t = gmtime(&tt);
		year = t->tm_year + 1900;
		md = (t->tm_mon + 1) * 100 + t->tm_mday;
		hm = t->tm_hour * 100 + t->tm_min;
		if (hm != mTime.gethm())
		{
			printf("%d-%02d-%02d %02d:%02d:%02d\n",
				t->tm_year + 1900,
				t->tm_mon + 1,
				t->tm_mday,
				t->tm_hour,
				t->tm_min,
				t->tm_sec);
			mTime.setyear(year);
			mTime.setmd(md);
			mTime.sethm(hm);
			mTime.show();
		}
		//delay(800);

	}
}