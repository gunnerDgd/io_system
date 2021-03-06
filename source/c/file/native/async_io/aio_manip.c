#include <io_system/file/native/async_io/aio_manip.h>
#include <io_system/file/details/native/async_io/iosys_file_native_aio_manip.h>

synapse_io_system_file_aio_request
synapse_io_system_file_aio_read_from
	(synapse_io_system_file_aio_handle pAio, synapse_io_system_file_aio_request pAioReq)
{
	__synapse_io_system_file_aio_read_from
		(synapse_io_system_opaque_reference(pAio), 
		 synapse_io_system_opaque_reference(pAioReq));

	return pAioReq;
}

synapse_io_system_file_aio_request
synapse_io_system_file_aio_write_to
	(synapse_io_system_file_aio_handle pAio, synapse_io_system_file_aio_request pAioReq)
{
	__synapse_io_system_file_aio_write_to
		(synapse_io_system_opaque_reference(pAio), 
		 synapse_io_system_opaque_reference(pAioReq));

	return pAioReq;
}

size_t
synapse_io_system_file_aio_wait_until
	(synapse_io_system_file_aio_handle pAio, synapse_io_system_file_aio_request pAioReq)
{
	return
		__synapse_io_systesm_file_aio_wait_until
			(synapse_io_system_opaque_reference(pAio),
			 synapse_io_system_opaque_reference(pAioReq));
}

size_t
synapse_io_system_file_aio_poll
	(synapse_io_system_file_aio_handle pAio, synapse_io_system_file_aio_request pAioReq)
{
	return
		__synapse_io_system_file_aio_poll
			(synapse_io_system_opaque_reference(pAio),
			 synapse_io_system_opaque_reference(pAioReq));
}