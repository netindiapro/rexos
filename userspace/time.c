/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2015, Alexey Kramarenko
    All rights reserved.
*/

#include "time.h"

static const unsigned short YDAY[2][12] = {
                                            { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 },
                                            { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 }
                                          };

bool is_leap_year(long year)
{
    return (!(year % 4) && ((year % 100) || !(year % 400)));
}

static long leap_years_between(long year)
{
    if (year > 0)
        return (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    else
        return 0;
}

TIME* mktime(struct tm* ts, TIME* time)
{
    time->day = (ts->tm_year - 1) * 365 + leap_years_between(ts->tm_year);
    time->day += YDAY[is_leap_year(ts->tm_year)][ts->tm_mon - 1] + ts->tm_mday - 1;
    time->ms = ((ts->tm_hour * 60 + ts->tm_min) * 60 + ts->tm_sec) * 1000 + ts->tm_msec;
    return time;
}

struct tm* gmtime(TIME* time, struct tm* ts)
{
    register long val = time->ms;
    register bool is_leap;
    //first - decode time
    ts->tm_msec = val % 1000;
    val /= 1000;
    ts->tm_sec = val % 60;
    val /= 60;
    ts->tm_min = val % 60;
    val /= 60;
    ts->tm_hour = val % 24;
    val /= 24;

    //decode year
    ts->tm_year = 1 + (time->day - leap_years_between(time->day / 365)) / 365;
    val = time->day - ((ts->tm_year - 1) * 365 + leap_years_between(ts->tm_year));
    is_leap = is_leap_year(ts->tm_year);

    //decode month
    ts->tm_mon = val / 31;
    //fine-tune date
    while (ts->tm_mon < 10 && YDAY[is_leap][ts->tm_mon + 1] < val)
        ++ts->tm_mon;
    val -= YDAY[is_leap][ts->tm_mon++];
    ts->tm_mday = val + 1;
    return ts;
}