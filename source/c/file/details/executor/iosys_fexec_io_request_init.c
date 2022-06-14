#include <io_system/file/details/executor/iosys_fexec_io_request.h>
#include <context/all.h>

#include <stdlib.h>

__synapse_iosys_fexec_io_request*
__synapse_iosys_fexec_io_request_initialize_standard_read
	(synapse_io_system_file pFile    , 
	 size_t				    pIoSize  , 
	 size_t					pIoOffset)
{
	__synapse_iosys_fexec_io_request* ptr_io_req
		= malloc(sizeof(__synapse_iosys_fexec_io_request));

	ptr_io_req->io_exec_pointer 
		= &__synapse_iosys_fexec_io_request_initialize_standard_read;
	ptr_io_req->io_exec_handle
		= pFile;


}

__synapse_iosys_fexec_io_request*
__synapse_iosys_fexec_io_request_initialize_standard_write
	(synapse_io_system_file pFile	 ,
	 size_t					pIoSize  ,
	 size_t					pIoOffset)
{
	
}

void
__synapse_iosys_fexec_io_request_cleanup(__synapse_iosys_fexec_io_request*);

