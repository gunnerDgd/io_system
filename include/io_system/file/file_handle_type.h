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

#define synapse_io_system_file_vectorized_read_from(pFile, pIoVec, pIoSize)\
	pFile->vector_read_from(pFile->handle, pIoVec, pIoSize)

#define synapse_io_system_file_vectorized_write_to(pFile, pIoVec, pIoSize)\
	pFile->vector_write_to(pFile->handle, pIoVec, pIoSize)