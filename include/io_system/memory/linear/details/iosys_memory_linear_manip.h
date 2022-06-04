#pragma once
#include <io_system/memory/linear/details/iosys_memory_linear.h>

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_seek   (__synapse_iosys_memory_linear*, size_t);

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_iterate(__synapse_iosys_memory_linear*);

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_iterate_next(__synapse_iosys_memory_linear_node*);

size_t
__synapse_iosys_memory_linear_copy_from(__synapse_iosys_memory_linear*, uint8_t*, size_t, size_t);

size_t
__synapse_iosys_memory_linear_copy_to  (__synapse_iosys_memory_linear*, uint8_t*, size_t, size_t);