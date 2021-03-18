/*
	Copyright 2020 Bga <bga.email@gmail.com>

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2, or (at your option)
	any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; see the file COPYING.  If not, write to
	the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
	Boston, MA 02111-1307, USA.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

#define outputStream stderr

bool CString_isEmpty(const char* str) {
	if(str == NULL) return true;
	
	while(*str && isblank(*str)) {
		str += 1;
	}
	
	return *str == 0; 
}

int main(int argc, char* argv[]) {
	const char* promtp = (1 < argc) ? argv[1] : "> ";
	char* str = NULL;
	
	 rl_outstream = stderr;
	
	while(1) {
		if(str != NULL) {
			free(str);
			str = NULL;
		};
		
		str = readline(promtp);
		if(!CString_isEmpty(str)) {
			add_history(str);
			fprintf(outputStream, "%s\n", str);
			fflush(outputStream);
		};
	}
	
	return 0;
}
