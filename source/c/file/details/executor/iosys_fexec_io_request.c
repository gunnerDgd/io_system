#include <io_system/file/details/executor/iosys_fexec_io_request.h>
#include <context/all.h>

#include <stdlib.h>

size_t
__synapse_iosys_fexec_io_request_read_standard(synapse_context_default_entity pExec, void* pVoidReq)
{
	__synapse_iosys_fexec_io_standard_request* ptr_req
		= pVoidReq;
	
	size_t sz_io_processed = 0;
	for (; sz_io_processed < ptr_req->req.io_exec_size; )
	{
		sz_io_processed += synapse_io_system_file_read_from((*ptr_req->req.io_exec_handle),
															  ptr_req->io_pointer		  ,
															  ptr_req->req.io_exec_size)  ;
	
		
	}
	
	synapse_context_default_switch_to(ptr_req->req.io_exec_context, pExec);
}

size_t
__synapse_iosys_fexec_io_request_write_standard(__synapse_iosys_fexec*, void*);

