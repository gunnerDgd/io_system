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

	void*
		(*vector_push)    (synapse_io_system_file_vector_handle, size_t);
	void
		(*vector_pop)     (synapse_io_system_file_vector_handle);
	size_t
		(*vector_count)	  (synapse_io_system_file_vector_handle);
	void*
		(*vector_retrieve)(synapse_io_system_file_vector_handle, size_t);
} synapse_io_system_file_vector;

typedef struct synapse_io_system_file
{
	synapse_io_system_file_handle handle;

	size_t(*read_from)(synapse_io_system_file_handle, void*, size_t, size_t);
	size_t(*write_to) (synapse_io_system_file_handle, void*, size_t, size_t);

	size_t(*current_pointer) (synapse_io_system_file_handle);
	size_t(*move_pointer)	 (synapse_io_system_file_handle, size_t);

	void  (*wait_until)      (synapse_io_system_file_handle);
} synapse_io_system_file;

typedef struct synapse_io_system_file_vectorized
{
	synapse_io_system_file_handle handle;

	size_t(*vector_read_from)(synapse_io_system_file_handle, synapse_io_system_file_vector*, size_t);
	size_t(*vector_write_to) (synapse_io_system_file_handle, synapse_io_system_file_vector*, size_t);

	void  (*wait_until)		 (synapse_io_system_file_handle);
} synapse_io_system_file_vectorized;

#define synapse_io_system_file_read_from(pFile, pIoPtr, pIoSize, pIoOffset)\
	pFile.read_from(pFile.handle, pIoPtr, pIoSize, pIoOffset)

#define synapse_io_system_file_write_to(pFile, pIoPtr, pIoSize, pIoOffset)\
	pFile.write_to(pFile.handle, pIoPtr, pIoSize, pIoOffset)

#define synapse_io_system_file_vectorized_read_from(pFile, pIoVec, pIoSize)\
	pFile.vector_read_from(pFile.handle, pIoVec, pIoSize)

#define synapse_io_system_file_vectorized_write_to(pFile, pIoVec, pIoSize)\
	pFile.vector_write_to(pFile.handle, pIoVec, pIoSize)

#define synapse_io_system_file_wait_until(pFile)\
	pFile.wait_until(pFile.handle)