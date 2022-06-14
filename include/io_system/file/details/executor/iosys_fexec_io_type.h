#pragma once
#include <io_system/file/file_io_system.h>
#include <structure/queue/linear/linear_queue.h>

#include <stdbool.h>

typedef struct __synapse_iosys_fexec_io_request
{
	bool
		  io_exec_completed;
	void
		(*io_exec_pointer)(synapse_context_default_entity, void*);
	synapse_io_system_file* 
		  io_exec_handle;
	synapse_context_default_entity
		  io_exec_context;

	size_t
		io_exec_size  ,
		io_exec_offset;
} __synapse_iosys_fexec_io_request;

typedef struct __synapse_iosys_fexec_io_standard_request
{
	__synapse_iosys_fexec_io_request req;
	void*							 io_pointer;
} __synapse_iosys_fexec_io_standard_request;

typedef struct __synapse_iosys_fexec_io_vector_request
{
	__synapse_iosys_fexec_io_request req;
	synapse_io_system_file_vector    io_vector;
} __synapse_iosys_fexec_io_vector_request;