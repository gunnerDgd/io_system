#pragma once
#include <stdint.h>

typedef struct synapse_io_system_file_handle
{
	void* opaque;
} synapse_io_system_file_handle;

typedef struct synapse_io_system_file_vector_handle
{
	void* opaque;
} synapse_io_system_file_vector_handle;

typedef struct synapse_io_system_file_vector
{
	synapse_io_system_file_vector_handle handle;
	
	synapse_io_system_file_vector_handle
		(*initialize) (size_t);
	void
		(*cleanup)    (synapse_io_system_file_vector_handle);
	size_t
		(*push_vector)(synapse_io_system_file_vector_handle, void*, size_t);
};

typedef struct synapse_io_system_file
{
	synapse_io_system_file_handle handle;

	size_t(*read_from)		 (synapse_io_system_file_handle, void*, size_t);
	size_t(*read_from_vector)(synapse_io_system_file_handle, synapse_io_system_file_vector);

	size_t(*write_to)		 (synapse_io_system_file_handle, void*, size_t);
	size_t(*write_to_vector) (synapse_io_system_file_handle, synapse_io_system_file_vector);

	size_t(*current_pointer) (synapse_io_system_file_handle);
	size_t(*move_pointer)	 (synapse_io_system_file_handle, size_t);
} synapse_io_system_file;