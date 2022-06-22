#pragma once
#include <io_system/file/file_handle_type.h>

typedef struct synapse_io_system_file
{
	synapse_io_system_file_handle handle;

	size_t(*read_from)		(synapse_io_system_file_handle, void*, size_t, size_t);
	size_t(*write_to)		(synapse_io_system_file_handle, void*, size_t, size_t);

	size_t(*current_pointer)(synapse_io_system_file_handle);
	size_t(*move_pointer)	(synapse_io_system_file_handle, size_t);

	void  (*wait_until)     (synapse_io_system_file_handle);
} synapse_io_system_file;



#define synapse_io_system_file_read_from(pFile, pIoPtr, pIoSize, pIoOffset)\
	pFile->read_from(pFile->handle, pIoPtr, pIoSize, pIoOffset)

#define synapse_io_system_file_write_to(pFile, pIoPtr, pIoSize, pIoOffset)\
	pFile->write_to(pFile->handle, pIoPtr, pIoSize, pIoOffset)

#define synapse_io_system_file_wait_until(pFile)\
	pFile->wait_until(pFile->handle)