#pragma once
#include <stdint.h>
#include <io_system/defines/opaque/opaque.h>

synapse_io_system_opaque_define
	(synapse_io_system_file_handle)

typedef struct synapse_io_system_file_traits
{
	synapse_io_system_file_handle 
		handle;

	size_t(*read_from)		(synapse_io_system_file_handle, void*, size_t);
	size_t(*write_to)		(synapse_io_system_file_handle, void*, size_t);

	size_t(*current_pointer)(synapse_io_system_file_handle);
	size_t(*move_pointer)	(synapse_io_system_file_handle, size_t);
} synapse_io_system_file_traits;


#define synapse_io_system_file_read_from(pFile, pIoPtr, pIoSize)\
	pFile->read_from(pFile->handle, pIoPtr, pIoSize)

#define synapse_io_system_file_write_to(pFile, pIoPtr, pIoSize)\
	pFile->write_to(pFile->handle, pIoPtr, pIoSize)