#include <io_system/memory/alloc/details/system_paging/iosys_memory_system_paging.h>
#include <Windows.h>

synapse_io_system_memory_alloc_model
__synapse_io_system_memory_system_paging_initialize(int pPageSelection)
{
	synapse_io_system_memory_alloc_model ptr_mmodel;

	switch (pPageSelection)
	{
	case SYNAPSE_MEMORY_SYSTEM_PAGING_4K:
		ptr_mmodel.allocate   = &__synapse_io_system_memory_system_paging_allocate  ;
		ptr_mmodel.deallocate = &__synapse_io_system_memory_system_paging_deallocate; break;

	case SYNAPSE_MEMORY_SYSTEM_PAGING_4M:
		ptr_mmodel.allocate   = &__synapse_io_system_memory_system_paging_allocate_4m;
		ptr_mmodel.deallocate = &__synapse_io_system_memory_system_paging_deallocate ; break;

	case SYNAPSE_MEMORY_SYSTEM_PAGING_1G:
		ptr_mmodel.allocate = &__synapse_io_system_memory_system_paging_allocate_1g;
		ptr_mmodel.deallocate = &__synapse_io_system_memory_system_paging_deallocate; break;

	default:
		ptr_mmodel.allocate   = &__synapse_io_system_memory_system_paging_allocate  ;
		ptr_mmodel.deallocate = &__synapse_io_system_memory_system_paging_deallocate; break;
		break;
	}

	return ptr_mmodel;
}

void*
__synapse_io_system_memory_system_paging_allocate(void* pEntity, void* pAllocHint, size_t pAllocSize)
{
	return VirtualAlloc(pAllocHint, 4096, MEM_COMMIT, PAGE_READWRITE);
}

void*
__synapse_io_system_memory_system_paging_allocate_4m(void* pEntity, void* pAllocHint, size_t pAllocSize)
{
	return VirtualAlloc(pAllocHint, 1024 * 1024 * 4, MEM_4MB_PAGES | MEM_COMMIT, PAGE_READWRITE);
}

void*
__synapse_io_system_memory_system_paging_allocate_1g(void* pEntity, void* pAllocHint, size_t pAllicSize)
{
	return VirtualAlloc(pAllocHint, 1024 * 1024 * 4, MEM_LARGE_PAGES | MEM_COMMIT, PAGE_READWRITE);
}

void
__synapse_io_system_memory_system_paging_deallocate(void* pEntity, void* pDeallocPtr, size_t pDeallocSize)
{
	return VirtualFree(pDeallocPtr, 0, MEM_FREE);
}