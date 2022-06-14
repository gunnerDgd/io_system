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
} synapse_io_system_file_vector;

typedef struct synapse_io_system_file
{
	synapse_io_system_file_handle handle;

	size_t(*read_from)		 (synapse_io_system_file_handle, void*, size_t, size_t);
	size_t(*read_from_vector)(synapse_io_system_file_handle, synapse_io_system_file_vector, size_t);

	size_t(*write_to)		 (synapse_io_system_file_handle, void*, size_t, size_t);
	size_t(*write_to_vector) (synapse_io_system_file_handle, synapse_io_system_file_vector, size_t);

	size_t(*current_pointer) (synapse_io_system_file_handle);
	size_t(*move_pointer)	 (synapse_io_system_file_handle, size_t);
} synapse_io_system_file;

#define synapse_io_system_file_read_from(pFile, pIoPtr, pIoSize, pIoOffset)\
	pFile.read_from(pFile.handle, pIoPtr, pIoSize, pIoOffset)

#define synapse_io_system_file_write_to(pFile, pIoPtr, pIoSize, pIoOffset)\
	pFile.write_to(pFile.handle, pIoPtr, pIoSize, pIoOffset)

#define synapse_io_system_file_read_from_vector(pFile, pIoVec, pIoSize)\
	pFile.read_from_vector(pFile.handle, pIoVec, pIoSize)

#define synapse_io_system_file_write_to_vector(pFile, pIoVec, pIoSize)\
	pFile.write_to_vector(pFile.handle, pIoVec, pIoSize)