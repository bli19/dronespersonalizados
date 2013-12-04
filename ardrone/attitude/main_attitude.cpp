/*
    main_attitude.c - AR.Drone attitude estimate demo program

    Copyright (C) 2011 Hugo Perquin - http://blog.perquin.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
    MA 02110-1301 USA.
*/








#include "../open_ardrone_v1_lib/all_headers_cpp.h"
#include "../open_ardrone_v1_lib/type.h"
#include "../open_ardrone_v1_lib/util.h"
#include "../open_ardrone_v1_lib/attitude.h"

int main()
{
	int rc;
	att_struct att;
	
	printf("Attitude Estimate test program\r\n");

	//init att board
	printf("Init Attitute Estimate ...\r\n");
	rc = att_Init(&att);
	if(rc) return rc;
	printf("Init Attitute Estimate OK\r\n");

   //flat trim
	att_FlatTrim(&att);

	//main loop	
	while(1) { 
		//get sample
		rc = att_GetSample(&att);
		if(rc) {
			printf("ERROR: att_GetSample return code=%d\n",rc); 
		}
		att_Print(&att);
	}
	att_Close();
	printf("\nDone...\n");
	return 0;
}