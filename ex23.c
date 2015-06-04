#include <stdio.h>
#include <string.h>
#include "dbg.h"
#include <sys/times.h>


int normal_copy(char *from, char *to, int count)
{
	int i = 0;

	for (i = 0; i < count; i++) {
		to[i] = from[i];
	}

	return i;
}

int duffs_device(char *from, char *to, int count)
{
	{
		int n = (count + 7) / 8;

		switch(count % 8) {
		case 0: do { *to++ = *from++;
			case 7: *to++ = *from++;
			case 6: *to++ = *from++;
			case 5: *to++ = *from++;
			case 4: *to++ = *from++;
			case 3: *to++ = *from++;
			case 2: *to++ = *from++;
			case 1: *to++ = *from++;
		} while(--n > 0);
		}
	}
	
	return count;
}
 
int zeds_device(char *from, char *to, int count)
{
	{
		int n = (count + 7) / 8;

		switch(count % 8) {
		case 0:
		again: *to++ = *from++;

		case 7: *to++ = *from++;
		case 6: *to++ = *from++;
		case 5: *to++ = *from++;
		case 4: *to++ = *from++;
		case 3: *to++ = *from++;
		case 2: *to++ = *from++;
		case 1: *to++ = *from++;
			if(--n > 0) goto again;
		}
	}
	
	return count;
}

int valid_copy(char *data, int count, char expects)
{
	int i = 0;
	for(i = 0; i < count; i++) {
		if(data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			return 0;
		}
	}

	return 1;
}

void print_time(clock_t st_time, struct tms st_cpu,
		clock_t en_time, struct tms en_cpu,
		char *msg)
{
	printf("start: %jd\nend: %jd\n", st_time, en_time);
	fputs(msg, stdout);
	printf("Real Time: %jd, User time %jd, System Time %jd\n",
		(long)(en_time - st_time),
		(long)(en_cpu.tms_utime - st_cpu.tms_utime),
		(long)(en_cpu.tms_stime - st_cpu.tms_stime));
}

int main(int argc, char *argv[])
{
	static clock_t start;
	static clock_t end;
	static struct tms cpustart;
	static struct tms cpuend;

	char from[1000] = {'a'};
	char to[1000] = {'c'};
	int rc = 0;

	// setup the from to have some stuff
	memset(from, 'x', 1000);
	// set it to a failure mode
	memset(to, 'y', 1000);
	check(valid_copy(to, 1000, 'y'), "Not initialized right");

	// use normal copy to
	start = times(&cpustart);
	rc = normal_copy(from, to, 1000);
	check(rc == 1000, "Normal copy failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Normal copy failed.");
	end = times(&cpuend);
	print_time(start, cpustart, end, cpuend, "Normal_copy\t");

	// reset
	memset(to, 'y', 1000);

	// duffs version
	start = times(&cpustart);
	rc = duffs_device(from, to, 1000);
	check(rc == 1000, "Duff's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Duff's device failed");
	end = times(&cpuend);
	print_time(start, cpustart, end, cpuend, "Duff's device\t");

	// reset
	memset(to, 'y', 1000);

	// my version
	start = times(&cpustart);
	rc = zeds_device(from, to, 1000);
	check(rc == 1000, "Zed's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Zed's device failed");
	end = times(&cpuend);
	print_time(start, cpustart, end, cpuend, "Zed's device\t");

	return 0;
error:
	return 1;
}
