#pragma once
#include <stdint.h>
#include <io_system/defines/opaque/opaque.h>

synapse_io_system_opaque_define
	(synapse_io_system_file_vectorized_handle)

synapse_io_system_opaque_define
	(synapse_io_system_file_vectorized_request)

synapse_io_system_opaque_define
	(synapse_io_system_file_vector_handle)

typedef struct synapse_io_system_file_vector
{
	synapse_io_system_file_vector_handle 
		handle;

	void*
		(*push)    (synapse_io_system_file_vector_handle, size_t);
	void
		(*pop)     (synapse_io_system_file_vector_handle);
	size_t
		(*count)   (synapse_io_system_file_vector_handle);
	void*
		(*retrieve)(synapse_io_system_file_vector_handle, size_t);
} synapse_io_system_file_vector;

typedef struct synapse_io_system_file_vectorized_traits
{
	synapse_io_system_file_vectorized_handle
		handle;

	synapse_io_system_file_vectorized_request
		(*vector_read_from)
			(synapse_io_system_file_vectorized_handle, synapse_io_system_file_vector*, size_t);
	synapse_io_system_file_vectorized_request
		(*vector_write_to)
			(synapse_io_system_file_vectorized_handle, synapse_io_system_file_vector*, size_t);
	void  
		(*wait_until)
			(synapse_io_system_file_vectorized_handle);
} synapse_io_system_file_vectorized_traits;