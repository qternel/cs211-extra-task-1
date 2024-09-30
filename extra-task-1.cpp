#include "extra-task-1.h"
#include <cstdlib>
#include<assert.h>
#include<cfloat>
//calculates seconds difference
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

//testing function for seconds_difference
void run_tests_seconds_difference() {
	assert(seconds_difference(1800.0, 3600.0) == 1800.0);
	assert(seconds_difference(3600.0, 1800.0) == -1800.0);
	assert(seconds_difference(1800.0, 2160.0) == 360.0);
	assert(seconds_difference(1800.0, 1800.0) == 0.0);
}

//calulates hours difference (time is given in seconds)
double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600.0;
}

//testing function for hours_difference
void run_tests_hours_difference() {
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);
}


//Returns the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
	assert((minutes >= 0) && (minutes < 60));
	assert((seconds >= 0) && (seconds < 60));
	return hours + minutes / 60.0 + seconds / 3600.0;
}

//testing function for to_float_hours
void run_tests_to_float_hours() {
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
}


//hours is a number of hours since midnight.Function returns the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return (hours - floor(hours / 24) * 24);
}


//testing function for to_24_hour_clock
void run_tests_to_24_hour_clock() {
	assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
}

//calculates hours elapsed since midnight ( time is given in seconds )
double get_hours(double time) {
	assert(time >= 0);
	return hours_difference(0.0, time);
}

//calculates minutes elapsed since midnight ( time is given in seconds )
double get_minutes(double time) {
	assert(time >= 0);
	return (time - get_hours(time) * 3600) / 60;
}

//calculates seconds elapsed since midnight ( time is given in seconds )
double get_seconds(double time) {
	assert(time >= 0);
	return (time - get_hours(time) * 3600 - get_minutes(time) * 60);
}

/*
	Implement three functions
		* get_hours
		* get_minutes
		* get_seconds
	They are used to determine the hours part, minutes part and seconds part
	of a time in seconds. E.g.:

	>>> get_hours(3800)
	1

	>>> get_minutes(3800)
	3

	>>> get_seconds(3800)
	20

	In other words, if 3800 seconds have elapsed since midnight,
	it is currently 01:03:20 (hh:mm:ss).
*/


//time to utc
double time_to_utc(int utc_offset, double time)
{
	double diff = time - utc_offset;
	return  diff - floor(diff / 24.0) * 24;

}

//testing function for time_to_utc
void run_tests_time_to_utc() {
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0)) < DBL_EPSILON);
}

//time from utc
double time_from_utc(int utc_offset, double time)
{
	return time_to_utc(-utc_offset, time);

}

//testing function for time_from_utc
void run_tests_time_from_utc() {
	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 23.0)) < DBL_EPSILON);

}

