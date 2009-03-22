/*
 * Definitions for handling the .xz file format
 *
 * Author: Lasse Collin <lasse.collin@tukaani.org>
 *
 * This file has been put into the public domain.
 * You can do whatever you want with this file.
 */

#ifndef XZ_STREAM_H
#define XZ_STREAM_H

#if defined(__KERNEL__) && !defined(XZ_INTERNAL_CRC32)
#	include <linux/crc32.h>
#	undef crc32
#	define xz_crc32(buf, size, crc) \
		(~crc32_le(~(uint32_t)(crc), buf, size))
#endif

/*
 * See the .xz file format specification at
 * http://tukaani.org/xz/xz-file-format.txt
 * to understand the container format.
 */

#define STREAM_HEADER_SIZE 12

#define HEADER_MAGIC "\3757zXZ\0"
#define HEADER_MAGIC_SIZE 6

#define FOOTER_MAGIC "YZ"
#define FOOTER_MAGIC_SIZE 2

/*
 * Variable-length integer can hold a 63-bit unsigned integer, or a special
 * value to indicate that the value is unknown.
 */
typedef uint64_t vli_type;

#define VLI_MAX ((vli_type)-1 / 2)
#define VLI_UNKNOWN ((vli_type)-1)

#endif
