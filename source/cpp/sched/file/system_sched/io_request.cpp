#include <io_system/sched/file/system_sched/cpp/io_request.hpp>
#include <io_system/sched/file/system_sched/system_sched_init.h>

io_system::schedule::system_scheduler::io_request::io_request
	(pointer pIoPtr, size_type pIoSize, size_type pIoOffset)
		: __M_iosys_req_handle
			(synapse_iosys_sched_system_io_request_initialize(pIoPtr, pIoSize, pIoOffset)) { }

io_system::schedule::system_scheduler::io_request::io_request
	(native_handle_type pHandle)
		: __M_iosys_req_handle(pHandle) {}

io_system::schedule::system_scheduler::io_request::io_request(io_request& pCopy)
	: __M_iosys_req_handle
		(pCopy.__M_iosys_req_handle) {  }

io_system::schedule::system_scheduler::io_request::io_request(io_request&& pMove)
	: __M_iosys_req_handle
		(pMove.__M_iosys_req_handle) { pMove.__M_iosys_req_handle.opaque = nullptr; }

io_system::schedule::system_scheduler::io_request::~io_request()
{
	synapse_iosys_sched_system_io_request_cleanup
		(__M_iosys_req_handle);
}