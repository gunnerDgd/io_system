#include <io_system/caching/linear/details/iosys_caching_linear_manip.h>
#include <string.h>

size_t
__synapse_iosys_caching_linear_read_from(__synapse_iosys_caching_linear* pCache, uint8_t* pReadPointer, size_t pReadCount)
{
	synapse_structure_double_linked_node ptr_node_dlist
		= synapse_structure_double_linked_node_begin(pCache->linear_memory_rdcache);

	size_t sz_read = 0;
	for ( ; pReadCount && ptr_node_dlist.opaque
		  ; pReadCount--, ptr_node_dlist = synapse_structure_double_linked_node_next(ptr_node_dlist))
	{
		__synapse_iosys_caching_linear_node** ptr_node
			= synapse_structure_double_linked_node_data(ptr_node_dlist);

		sz_read											   += (*ptr_node)->node_size	;
		memcpy(pReadPointer + sz_read, (*ptr_node)->node_ptr, (*ptr_node)->node_pointer);
	}

	return sz_read;
}

size_t
__synapse_iosys_caching_linear_write_to(__synapse_iosys_caching_linear* pCache, void* pWritePointer, size_t pWriteCount)
{
	synapse_structure_double_linked_node ptr_node_dlist
		= synapse_structure_double_linked_node_end(pCache->linear_memory_wrcache);

	size_t sz_write = 0;
	for ( ; pWriteCount && ptr_node_dlist.opaque
		  ; pWriteCount--, ptr_node_dlist = synapse_structure_double_linked_node_next(ptr_node_dlist))
	{
		__synapse_iosys_caching_linear_node** ptr_node
			= synapse_structure_double_linked_node_data(ptr_node_dlist);
		
		sz_write													    += (*ptr_node)->node_size	 ;
		memcpy(pWriteCount + sz_write, (*ptr_node)->node_ptr, (*ptr_node)->node_pointer);
	}
}

size_t
__synapse_iosys_caching_linear_reserved_read_from(__synapse_iosys_caching_linear* pCache, size_t pReadByte)
{
	
}	

size_t
__synapse_iosys_caching_linear_reserved_write_to(__synapse_iosys_caching_linear* pCache, size_t pWriteByte)
{

}