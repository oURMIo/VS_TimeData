#include <stdio.h>  
#include <string.h>  
#include <time.h>  
#include <conio.h>

using namespace std;

int main()
{
	struct tm newtime;
	char am_pm[] = "AM";
	__time64_t long_time;
	char timebuf[26];
	errno_t err;

	// Get time as 64-bit integer.  
	_time64(&long_time);
	// Convert to local time.  

	err = _localtime64_s(&newtime, &long_time);
	if (err)
	{
		printf("Invalid argument to _localtime64_s.");
		_getch();
		return(0);
	}
	if (newtime.tm_hour > 12)        // Set up extension.   
		strcpy_s(am_pm, sizeof(am_pm), "PM");

	if (newtime.tm_hour > 12)        // Convert from 24-hour   
		newtime.tm_hour -= 12;    // to 12-hour clock.   

	if (newtime.tm_hour == 0)        // Set hour to 12 if midnight.  
		newtime.tm_hour = 12;


	// Convert to an ASCII representation  
	err = asctime_s(timebuf, 26, &newtime);
	if (err)
	{
		printf("Invalid argument to asctime_s.");
		_getch();
		return(0);
	}

	printf("%.19s %s\n", timebuf,am_pm);
	_getch();
}