#include <io_system/file/details/executor/iosys_fexec_init.h>

#include <stdlib.h>
#include <string.h>

__synapse_iosys_fexec*
__synapse_iosys_fexec_initialize(synapse_context_default_entity pContext)
{
	__synapse_iosys_fexec* ptr_fexec
		= malloc(sizeof(__synapse_iosys_fexec));

	ptr_fexec->fexec_context = pContext;
	ptr_fexec->fexec_queue	 = synapse_structure_linear_queue_initialize();

	return ptr_fexec;
}

__synapse_iosys_fexec*
__synapse_iosys_fexec_initialize_default()
{
	return __synapse_iosys_fexec_initialize(synapse_context_default_initialize());
}

void
__synapse_iosys_fexec_cleanup(__synapse_iosys_fexec* pContext)
{
	synapse_structure_linear_queue_cleanup(pContext->fexec_queue);
	free(pContext);
}