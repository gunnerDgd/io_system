#pragma once
#include <io_system/file/details/executor/iosys_fexec_io_type.h>
#include <io_system/file/details/executor/iosys_fexec_type.h>

bool
__synapse_iosys_fexec_run_once		     (__synapse_iosys_fexec*);

void
__synapse_iosys_fexec_run_until_complete(__synapse_iosys_fexec*);

void
__synapse_iosys_fexec_run_n_count		 (__synapse_iosys_fexec*, size_t);