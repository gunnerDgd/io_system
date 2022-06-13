#pragma once
#include <stdint.h>

typedef enum synapse_iosys_file_access_mode 
{ 
	read_only  = 1, 
	write_only = (1 << 1), 
	all		   = (1 << 2) 
} synapse_iosys_file_access_mode;