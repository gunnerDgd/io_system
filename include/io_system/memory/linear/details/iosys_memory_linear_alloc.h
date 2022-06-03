#pragma once
#include <io_system/memory/linear/details/iosys_memory_linear.h>

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_allocate_back	  (__synapse_iosys_memory_linear*);

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_allocate_front  (__synapse_iosys_memory_linear*);

void
__synapse_iosys_memory_linear_deallocate_back (__synapse_iosys_memory_linear*);

void
__synapse_iosys_memory_linear_deallocate_front(__synapse_iosys_memory_linear*);

void
__synapse_iosys_memory_linear_deallocate_node (__synapse_iosys_memory_linear*, __synapse_iosys_memory_linear_node*);