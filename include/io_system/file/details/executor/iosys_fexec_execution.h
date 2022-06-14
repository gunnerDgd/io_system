#pragma once
#include <io_system/file/details/executor/iosys_fexec_io_type.h>
#include <io_system/file/details/executor/iosys_fexec_type.h>

void
__synapse_iosys_fexec_run_once		      (__synapse_iosys_fexec*);

void
__synapse_iosys_fexec_run_until_complete  (__synapse_iosys_fexec*);

void
__synapse_iosys_fexec_io_read_request     (__synapse_iosys_fexec*, __synapse_iosys_fexec_req_read*);

void
__synapse_iosys_fexec_io_read_vec_request (__synapse_iosys_fexec*, __synapse_iosys_fexec_req_read_vec*);

void
__synapse_iosys_fexec_io_write_request    (__synapse_iosys_fexec*, __synapse_iosys_fexec_req_write*);

void
__synapse_iosys_fexec_io_write_vec_request(__synapse_iosys_fexec*, __synapse_iosys_fexec_req_write_vec*);