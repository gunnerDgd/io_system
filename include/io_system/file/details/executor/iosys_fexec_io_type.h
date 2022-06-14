#pragma once
#include <io_system/file/file_io_system.h>
#include <structure/queue/linear/linear_queue.h>

#include <stdbool.h>

typedef struct __synapse_iosys_fexec_req_read
{
	void*					rd_pointer    ;
	size_t					rd_size       ;
	size_t					rd_offset     ;
	
	bool					rd_completed  ;
	synapse_io_system_file* rd_file_handle;
} __synapse_iosys_fexec_req_read;

typedef struct __synapse_iosys_fexec_req_write
{
	void*					wr_pointer    ;
	size_t					wr_size       ;
	size_t					wr_offset     ;
	
	bool					wr_completed  ;
	synapse_io_system_file* wr_file_handle;
} __synapse_iosys_fexec_req_write;

typedef struct __synapse_iosys_fexec_req_read_vec
{
	synapse_io_system_file_vector rd_vector;
	size_t						  rd_offset;

	bool						  rd_completed;
	synapse_io_system_file*		  rd_file_handle;
} __synapse_iosys_fexec_req_read_vec;

typedef struct __synapse_iosys_fexec_req_write_vec
{
	synapse_io_system_file_vector wr_vector;
	size_t						  wr_offset;

	bool						  wr_completed;
	synapse_io_system_file*		  wr_file_handle;
} __synapse_iosys_fexec_req_write_vec;