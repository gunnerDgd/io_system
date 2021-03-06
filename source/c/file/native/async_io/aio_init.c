#include <io_system/file/native/async_io/aio_init.h>
#include <io_system/file/details/native/async_io/iosys_file_native_aio_init.h>

synapse_io_system_file_aio_handle
synapse_io_system_file_aio_create_new
	(const wchar_t* pName)
{
	synapse_io_system_opaque_init
		(synapse_io_system_file_aio_handle,
		 ptr_aio,
		 __synapse_io_system_file_aio_create_new(pName));
	return ptr_aio;
}

synapse_io_system_file_aio_handle
synapse_io_system_file_aio_open_existing
	(const wchar_t* pName)
{
	synapse_io_system_opaque_init
		(synapse_io_system_file_aio_handle,
		 ptr_aio,
		 __synapse_io_system_file_aio_open_existing(pName));

	return ptr_aio;
}

synapse_io_system_file_aio_request
synapse_io_system_file_aio_request_initialize
	(void* pAioPtr, size_t pAioSize, size_t pAioOffset)
{
	synapse_io_system_opaque_init
		(synapse_io_system_file_aio_request,
		 ptr_aioreq,
		 __synapse_io_system_file_aio_request_initialize
			(pAioPtr, pAioSize, pAioOffset));

	return ptr_aioreq;
}

synapse_io_system_file_aio_request
synapse_io_system_file_aio_request_initialize_from_existing
	(synapse_io_system_file_aio_request pAioReq, void* pAioPtr, size_t pAioSize, size_t pAioOffset)
{
	synapse_io_system_opaque_init
		(synapse_io_system_file_aio_request,
		 ptr_aioreq,
			__synapse_io_system_file_aio_request_initialize_from_existing
				(synapse_io_system_opaque_reference(pAioReq), pAioPtr, pAioSize, pAioOffset));

	return ptr_aioreq;
}

void
synapse_io_system_file_aio_cleanup
	(synapse_io_system_file_aio_handle pAio)
{
	__synapse_io_system_file_aio_cleanup
		(synapse_io_system_opaque_reference(pAio));
}

void
synapse_io_system_file_aio_request_cleanup
	(synapse_io_system_file_aio_request pAioReq)
{
	__synapse_io_system_file_aio_request_cleanup
		(synapse_io_system_opaque_reference(pAioReq));
}