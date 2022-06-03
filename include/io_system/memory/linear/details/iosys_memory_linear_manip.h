#pragma once
#include <io_system/memory/linear/details/iosys_memory_linear.h>

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_iterate(__synapse_iosys_memory_linear*);

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_iterate_next(__synapse_iosys_memory_linear_node*);

size_t
__synapse_iosys_memory_linear_copy_from(__synapse_iosys_memory_linear* pMmodel, uint8_t* pReadMemory, size_t pReadSize);

size_t
__synapse_iosys_memory_linear_copy_to  (__synapse_iosys_memory_linear* pMmodel, uint8_t* pWriteMemory, size_t pWriteSize);