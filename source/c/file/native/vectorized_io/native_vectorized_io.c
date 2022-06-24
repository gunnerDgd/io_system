#include <io_system/file/native/vectorized_io/native_vectorized_io.h>
#include <io_system/file/details/native/vectorized_io/iosys_file_native_vectorized_io.h>

size_t
synapse_io_system_file_vectorized_read_from
	(synapse_io_system_file_vectorized_handle  pVecHnd, 
	 synapse_io_system_file_vectorized_request pVecReq)
{
	return
		__synapse_iosys_file_native_vector_read_from
			(synapse_io_system_opaque_reference(pVecHnd),
			 synapse_io_system_opaque_reference(pVecReq));
}

size_t
synapse_io_system_file_vectorized_write_to
	(synapse_io_system_file_vectorized_handle  pVecHnd, 
	 synapse_io_system_file_vectorized_request pVecReq)
{
	return
		__synapse_iosys_file_native_vector_write_to
			(synapse_io_system_opaque_reference(pVecHnd),
			 synapse_io_system_opaque_reference(pVecReq));
}

size_t
synapse_io_system_file_vectorized_wait_until
	(synapse_io_system_file_vectorized_handle  pVecHnd, 
	 synapse_io_system_file_vectorized_request pVecReq)
{
	return
		__synapse_iosys_file_native_vector_wait_until
			(synapse_io_system_opaque_reference(pVecHnd),
			 synapse_io_system_opaque_reference(pVecReq));
}

size_t
synapse_io_system_file_vectorized_poll
	(synapse_io_system_file_vectorized_handle  pVecHnd, 
	 synapse_io_system_file_vectorized_request pVecReq)
{
	return
		__synapse_iosys_file_native_vector_poll
			(synapse_io_system_opaque_reference(pVecHnd),
			 synapse_io_system_opaque_reference(pVecReq));
}