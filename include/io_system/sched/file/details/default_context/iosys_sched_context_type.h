#pragma once
#include <context/all.h>
#include <structure/queue/linear/linear_queue.h>
#include <io_system/file/file_io_system.h>

#include <stdbool.h>

typedef struct __synapse_iosys_sched_default_context
{
	synapse_structure_linear_queue
		hnd_queue_processing,
		hnd_queue_completed ;
} __synapse_iosys_sched_default_context;

typedef struct __synapse_iosys_sched_default_context_io_context
{
	synapse_context_default_entity
		hnd_context,
		hnd_context_loop;

	void*
		ptr_io_context_stack ;
	size_t
		size_io_context_stack;
} __synapse_iosys_sched_default_context_io_context;

typedef struct __synapse_iosys_sched_default_context_io_request
{
	__synapse_iosys_sched_default_context_io_context
		hnd_io_context;
	synapse_io_system_file*
		hnd_file;
	
	void*  io_req_ptr      ;
	size_t io_req_size     ,
		   io_req_offset   ,
		   io_req_processed;
} __synapse_iosys_sched_default_context_io_request;