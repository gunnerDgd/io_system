#pragma once
#include <io_system/file/file_handle_type.h>

typedef struct synapse_io_system_file_vector
{
	synapse_io_system_file_vector_handle handle;

	void*
		(*push)    (synapse_io_system_file_vector_handle, size_t);
	void
		(*pop)     (synapse_io_system_file_vector_handle);
	size_t
		(*count)   (synapse_io_system_file_vector_handle);
	void*
		(*retrieve)(synapse_io_system_file_vector_handle, size_t);
} synapse_io_system_file_vector;

typedef struct synapse_io_system_file_vectorized
{
	synapse_io_system_file_handle handle;

	size_t(*vector_read_from)(synapse_io_system_file_handle, synapse_io_system_file_vector*, size_t);
	size_t(*vector_write_to) (synapse_io_system_file_handle, synapse_io_system_file_vector*, size_t);

	void  (*wait_until)		 (synapse_io_system_file_handle);
} synapse_io_system_file_vectorized;