#include <io_system/sched/file/details/default_context/iosys_sched_context_init.h>
#include <stdlib.h>

__synapse_iosys_sched_default_context*
__synapse_iosys_sched_default_context_initialize()
{
	__synapse_iosys_sched_default_context* ptr_sched
		= malloc(sizeof(__synapse_iosys_sched_default_context));

	ptr_sched->hnd_queue_processing
		= synapse_structure_linear_queue_initialize_default();
	ptr_sched->hnd_queue_completed
		= synapse_structure_linear_queue_initialize_default();

	return ptr_sched;
}

void
__synapse_iosys_sched_default_context_cleanup(__synapse_iosys_sched_default_context* pIoSched)
{
	synapse_structure_linear_queue_cleanup
		(pIoSched->hnd_queue_processing);
	synapse_structure_linear_queue_cleanup
		(pIoSched->hnd_queue_completed);

	free(pIoSched);
}