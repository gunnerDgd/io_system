#include <io_system/file/details/executor/iosys_fexec_execution.h>

bool
__synapse_iosys_fexec_run_once(__synapse_iosys_fexec* pExecRead)
{
	synapse_structure_linear_queue_node ptr_node_exec
		= synapse_structure_linear_queue_retrieve_front(pExecRead->fexec_queue);

	__synapse_iosys_fexec_io_request*	ptr_req
		= synapse_structure_linear_queue_node_data(ptr_node_exec);

		ptr_req->io_exec_pointer(ptr_req);
	if (ptr_req->io_exec_completed) {
		synapse_structure_linear_queue_pop_front(pExecRead->fexec_queue, ptr_node_exec);
		
		return true;
	}
	else
		synapse_structure_lqueue_push_back_node (pExecRead->fexec_queue, ptr_node_exec);
}

void
__synapse_iosys_fexec_run_until_complete(__synapse_iosys_fexec* pExecRead)
{

}

void
__synapse_iosys_fexec_run_n_count(__synapse_iosys_fexec*, size_t);