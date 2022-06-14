#include <io_system/file/native/cpp/native_io_vector.hpp>

io_system::file::vectorized::io_vector::vector::vector(pointer pVectorPtr, size_type pVectorSize)
	: __M_iovec_ptr (pVectorPtr),
	  __M_iovec_size(pVectorSize) { }

typename io_system::file::vectorized::io_vector::pointer 
		 io_system::file::vectorized::io_vector::vector::get_pointer() { return __M_iovec_ptr; }

typename io_system::file::vectorized::io_vector::size_type 
		 io_system::file::vectorized::io_vector::vector::size()		   { return __M_iovec_size; }

io_system::file::vectorized::io_vector::io_vector(size_type pVectorCount)
	: __M_iovec_handle(synapse_io_system_file_vector_initialize(pVectorCount)) {  }

io_system::file::vectorized::io_vector::~io_vector()
{
	synapse_io_system_file_vector_cleanup(__M_iovec_handle);
}

typename io_system::file::vectorized::io_vector::size_type 
		 io_system::file::vectorized::io_vector::push(size_t pSize)
{
	synapse_io_system_file_vector_push(__M_iovec_handle->handle, pSize);
	return
		synapse_io_system_file_vector_count(__M_iovec_handle->handle);
}

typename io_system::file::vectorized::io_vector::size_type 
		 io_system::file::vectorized::io_vector::pop()
{
	synapse_io_system_file_vector_pop(__M_iovec_handle->handle);
	return
		synapse_io_system_file_vector_count(__M_iovec_handle->handle);
}

typename io_system::file::vectorized::io_vector::vector
		 io_system::file::vectorized::io_vector::operator[] (size_type pIndex)
{
	return
		vector(
			synapse_io_system_file_vector_retrieve(__M_iovec_handle->handle, pIndex), 
													4096 * 4);
}

typename io_system::file::vectorized::io_vector::size_type
		 io_system::file::vectorized::io_vector::count()
{
	return
		__M_iovec_handle->vector_count(__M_iovec_handle->handle);
}