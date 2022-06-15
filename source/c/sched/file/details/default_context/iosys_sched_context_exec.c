#include <io_system/sched/file/details/default_context/iosys_sched_context_exec.h>

void
__synapse_iosys_sched_default_context_do_read
	(synapse_context_default_entity pIoContext, 
	  __synapse_iosys_sched_default_context_io_request* pIoRequest)
{
	synapse_context_default_switch_to
		(pIoRequest->hnd_io_context.hnd_context,
		 pIoRequest->hnd_io_context.hnd_context_loop);

	while(pIoRequest->io_req_processed < pIoRequest->io_req_size) {
		  pIoRequest->io_req_processed += synapse_io_system_file_read_from (
				pIoRequest->hnd_file									,
				pIoRequest->io_req_ptr									,
				pIoRequest->io_req_size	  - pIoRequest->io_req_processed,
				pIoRequest->io_req_offset + pIoRequest->io_req_processed);

		  synapse_context_default_switch_to
				(pIoRequest->hnd_io_context.hnd_context,
				 pIoRequest->hnd_io_context.hnd_context_loop);
	}

	synapse_context_default_switch_to
		(pIoRequest->hnd_io_context.hnd_context,
		 pIoRequest->hnd_io_context.hnd_context_loop);
}

void
__synapse_iosys_sched_default_context_do_write
	(synapse_context_default_entity pIoContext, 
	 __synapse_iosys_sched_default_context_io_request* pIoRequest)
{
	synapse_context_default_switch_to
		(pIoRequest->hnd_io_context.hnd_context,
		 pIoRequest->hnd_io_context.hnd_context_loop);

	while(pIoRequest->io_req_processed < pIoRequest->io_req_size) {
		  pIoRequest->io_req_processed += synapse_io_system_file_write_to (
				pIoRequest->hnd_file									,
				pIoRequest->io_req_ptr									,
				pIoRequest->io_req_size	  - pIoRequest->io_req_processed,
				pIoRequest->io_req_offset + pIoRequest->io_req_processed);

		  synapse_context_default_switch_to
				(pIoRequest->hnd_io_context.hnd_context,
				 pIoRequest->hnd_io_context.hnd_context_loop);
	}

	synapse_context_default_switch_to
		(pIoRequest->hnd_io_context.hnd_context,
		 pIoRequest->hnd_io_context.hnd_context_loop);
}

void
__synapse_iosys_sched_default_context_do_run
	(__synapse_iosys_sched_default_context* pIoSched)
{
	while (!__synapse_iosys_sched_default_context_do_run_once(pIoSched));
}

int
__synapse_iosys_sched_default_context_do_run_once
	(__synapse_iosys_sched_default_context* pIoSched)
{
	synapse_structure_linear_queue_node ptr_task_node
		= synapse_structure_linear_queue_retrieve_front(pIoSched->hnd_queue_processing);
	__synapse_iosys_sched_default_context_io_request* ptr_task;
		
	if (!ptr_task_node.opaque)
		return -1;

	ptr_task
		= synapse_structure_linear_queue_node_data(ptr_task_node);

	synapse_context_default_switch_to
		(ptr_task->hnd_io_context.hnd_context_loop, ptr_task->hnd_io_context.hnd_context);

	if (ptr_task->io_req_processed >= ptr_task->io_req_size)
		synapse_structure_linear_queue_pop_front(
			pIoSched->hnd_queue_processing,
			ptr_task_node
		);

	return 0;
}