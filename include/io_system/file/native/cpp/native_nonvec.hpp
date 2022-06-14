#pragma once
extern "C"
{
#include <io_system/file/native/native.h>
}

#include <io_system/file/native/cpp/native_declare.hpp>
#include <io_system/file/native/cpp/native_openmode.hpp>

#include <string>

namespace io_system::file {
	template <typename CharT>
	class native
	{
	public:
		using native_handle_type = synapse_io_system_file*;
		using size_type			 = std::size_t	 ;
		using difference_type    = std::ptrdiff_t;

		using value_type		 = std::remove_all_extents_t<CharT>;
		using reference			 = value_type&;
		using pointer			 = value_type*;
		
	public:
		template <typename AnyOption>
		native(std::wstring, AnyOption&&)    
			{ static_assert(false, "[io_system::file::native][Critical] Invalid Creation Parameter"); }
		
		native (std::wstring, __open_existing);
		native (std::wstring, __create_new)   ;

		~native();
	public:
		size_type
			read_from(reference, difference_type);
		size_type
			read_from(reference);
		size_type
			read_from(pointer  , size_type, difference_type);
		size_type
			read_from(pointer  , size_type);

		size_type
			write_to (pointer  , size_type, difference_type);
		size_type
			write_to (reference, size_type, difference_type);
		size_type
			write_to (pointer  , size_type);
		size_type
			write_to (reference, size_type);

	private:
		native_handle_type
			__M_iosys_file_native;
		difference_type
			__M_iosys_file_native_offset;
	};
}

template <typename CharT>
io_system::file::native<CharT>::native(std::wstring pName, __open_existing)
	: __M_iosys_file_native
			(synapse_iosys_file_native_initialize_open_existing(pName.c_str())),
	  __M_iosys_file_native_offset
			(0) { }

template <typename CharT>
io_system::file::native<CharT>::native(std::wstring pName, __create_new)
	: __M_iosys_file_native
			(synapse_iosys_file_native_initialize_create_new(pName.c_str())),
	  __M_iosys_file_native_offset
			(0) { }

template <typename CharT>
io_system::file::native<CharT>::~native()
{
	synapse_iosys_file_native_cleanup(__M_iosys_file_native);
}

template <typename CharT>
typename io_system::file::native<CharT>::size_type
		 io_system::file::native<CharT>::read_from(reference pRead, difference_type pReadOffset)
{
	return
		synapse_io_system_file_read_from(__M_iosys_file_native, &pRead, sizeof(value_type), pReadOffset);
}

template <typename CharT>
typename io_system::file::native<CharT>::size_type
		 io_system::file::native<CharT>::read_from(pointer pRead, size_type pReadSize, difference_type pReadOffset)
{
	return
		synapse_io_system_file_read_from(__M_iosys_file_native, pRead, pReadSize, pReadOffset);
}

template <typename CharT>
typename io_system::file::native<CharT>::size_type
		 io_system::file::native<CharT>::read_from(reference pRead)
{
	size_t rd_size
		= synapse_io_system_file_read_from(__M_iosys_file_native, &pRead, sizeof(value_type), __M_iosys_file_native_offset);

	__M_iosys_file_native_offset += rd_size;
	return							rd_size;
}

template <typename CharT>
typename io_system::file::native<CharT>::size_type
		 io_system::file::native<CharT>::read_from(pointer pRead, size_type pReadSize)
{
	size_t rd_size
		= synapse_io_system_file_read_from(__M_iosys_file_native, pRead, pReadSize, __M_iosys_file_native_offset);

	__M_iosys_file_native_offset += rd_size;
	return							rd_size;
}

template <typename CharT>
typename io_system::file::native<CharT>::size_type
		 io_system::file::native<CharT>::write_to(reference pWrite, size_type pWriteSize, difference_type pWriteOffset)
{
	return
		synapse_io_system_file_write_to(__M_iosys_file_native, &pWrite, pWriteSize, pWriteOffset);
}

template <typename CharT>
typename io_system::file::native<CharT>::size_type
		 io_system::file::native<CharT>::read_from(pointer pRead, size_type pReadSize, difference_type pReadOffset)
{
	return
		synapse_io_system_file_read_from(__M_iosys_file_native, pRead, pReadSize, pReadOffset);
}

template <typename CharT>
typename io_system::file::native<CharT>::size_type
		 io_system::file::native<CharT>::read_from(reference pRead, size_type pReadSize)
{
	size_t rd_size
		= synapse_io_system_file_read_from(__M_iosys_file_native, &pRead, pReadSize, __M_iosys_file_native_offset);

	__M_iosys_file_native_offset += rd_size;
	return							rd_size;
}

template <typename CharT>
typename io_system::file::native<CharT>::size_type
		 io_system::file::native<CharT>::read_from(pointer pRead, size_type pReadSize)
{
	size_t rd_size
		= synapse_io_system_file_read_from(__M_iosys_file_native, pRead, pReadSize, __M_iosys_file_native_offset);

	__M_iosys_file_native_offset += rd_size;
	return							rd_size;
}