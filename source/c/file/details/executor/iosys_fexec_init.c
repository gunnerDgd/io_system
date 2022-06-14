#include <io_system/file/details/executor/iosys_fexec_init.h>

#include <stdlib.h>
#include <string.h>

__synapse_iosys_fexec*
__synapse_iosys_fexec_initialize(synapse_context_default_entity pContext)
{
	__synapse_iosys_fexec* ptr_fexec
		= malloc(sizeof(__synapse_iosys_fexec));

	ptr_fexec->fexec_context = pContext;
	ptr_fexec->fexec_rdqueue = synapse_structure_linear_queue_initialize_default();
	ptr_fexec->fexec_wrqueue = synapse_structure_linear_queue_initialize_default();

	return ptr_fexec;
}

__synapse_iosys_fexec*
__synapse_iosys_fexec_initialize_default()
{
	synapse_context_default_entity ptr_fexec_context
		= synapse_context_default_initialize();

	return __synapse_iosys_fexec_initialize(ptr_fexec_context);
}

void
__synapse_iosys_fexec_cleanup(__synapse_iosys_fexec* pExec)
{
	synapse_structure_linear_queue_cleanup(pExec->fexec_rdqueue);
	synapse_structure_linear_queue_cleanup(pExec->fexec_wrqueue);

	free(pExec);
}