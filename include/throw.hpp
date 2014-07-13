
// Copyright (c) 2013,2014, niXman (i dotty nixman doggy gmail dotty com)
// All rights reserved.
//
// This file is part of THROW(https://github.com/niXman/throw) project.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright notice, this
//   list of conditions and the following disclaimer in the documentation and/or
//   other materials provided with the distribution.
//
//   Neither the name of the {organization} nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
// ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef _throw__throw_hpp
#define _throw__throw_hpp

#include <stdexcept>
#include <boost/format.hpp>

/***************************************************************************/

#define __THROW_%PREFIX%_VA_ARG_N( \
	_1, _2 ,_3, _4, _5, _6, _7, _8, _9, _10,_11,_12,_13,_14,_15,_16, \
	_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32, \
	_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48, \
	_49,_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,_60,_61,_62,_63,  N, ...) N

#define __THROW_%PREFIX%_VA_MORE1_ARGS(...) \
	__THROW_%PREFIX%_VA_ARG_N( \
		 __VA_ARGS__ \
		,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 \
		,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 \
	)

#define __THROW_%PREFIX%_RSEQ_N() \
	63,62,61,60,59,58,57,56,55,54, \
	53,52,51,50,49,48,47,46,45,44, \
	43,42,41,40,39,38,37,36,35,34, \
	33,32,31,30,29,28,27,26,25,24, \
	23,22,21,20,19,18,17,16,15,14, \
	13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define __THROW_%PREFIX%_SEPARATOR \
	%

#define __THROW_%PREFIX%_PRIMITIVE_CAT_(A, ...) \
	A ## __VA_ARGS__

#define __THROW_%PREFIX%_CONCAT(A, ...) \
	__THROW_%PREFIX%_PRIMITIVE_CAT_(A, __VA_ARGS__)

#define __THROW_%PREFIX%_PRIMITIVE_TOSTR_(A) \
	#A

#define __THROW_%PREFIX%_TOSTR(A) \
	__THROW_%PREFIX%_PRIMITIVE_TOSTR_(A)

#define __THROW_%PREFIX%_GET_ARGS_LIST(...) \
	__THROW_%PREFIX%_CONCAT(__THROW_%PREFIX%_GET_ARGS_LIST_, __THROW_%PREFIX%_VA_MORE1_ARGS(__VA_ARGS__))(__VA_ARGS__)

#define __THROW_%PREFIX%_GET_ARGS_LIST_0(...)

#define __THROW_%PREFIX%_GET_ARGS_LIST_1(F, ...) \
	__THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARGS(__VA_ARGS__)

#define __THROW_%PREFIX%_GET_FORMAT_STRING(F, ...) \
	F

#define __THROW_%PREFIX%_NARG(...) \
	__THROW_%PREFIX%_NARG_(__VA_ARGS__, __THROW_%PREFIX%_RSEQ_N())

#define __THROW_%PREFIX%_NARG_(...) \
	__THROW_%PREFIX%_VA_ARG_N(__VA_ARGS__)

#define __THROW_%PREFIX%_GET_ARG_1(item1, ...) (item1)
#define __THROW_%PREFIX%_GET_ARG_2(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_1(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_3(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_2(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_4(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_3(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_5(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_4(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_6(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_5(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_7(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_6(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_8(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_7(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_9(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_8(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_10(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_9(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_11(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_10(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_12(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_11(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_13(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_12(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_14(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_13(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_15(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_14(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_16(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_15(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_17(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_16(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_18(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_17(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_19(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_18(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_20(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_19(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_21(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_20(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_22(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_21(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_23(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_22(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_24(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_23(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_25(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_24(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_26(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_25(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_27(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_26(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_28(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_27(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_29(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_28(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_30(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_29(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_31(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_30(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_32(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_31(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_33(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_32(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_34(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_33(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_35(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_34(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_36(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_35(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_37(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_36(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_38(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_37(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_39(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_38(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_40(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_39(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_41(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_40(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_42(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_41(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_43(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_42(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_44(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_43(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_45(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_44(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_46(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_45(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_47(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_46(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_48(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_47(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_49(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_48(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_50(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_49(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_51(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_50(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_52(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_51(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_53(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_52(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_54(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_53(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_55(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_54(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_56(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_55(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_57(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_56(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_58(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_57(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_59(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_58(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_60(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_59(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_61(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_60(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_62(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_61(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARG_63(item1, ...) (item1) __THROW_%PREFIX%_SEPARATOR __THROW_%PREFIX%_GET_ARG_62(__VA_ARGS__)
#define __THROW_%PREFIX%_GET_ARGS(...) __THROW_%PREFIX%_CONCAT(__THROW_%PREFIX%_GET_ARG_, __THROW_%PREFIX%_NARG(__VA_ARGS__))(__VA_ARGS__)

/***************************************************************************/

/* usage:
 * std::cout << %PREFIX%_FORMAT_MESSAGE("message: %s, %d, %s", "string1", 33, "string2") << std::endl;
 * std::string str = %PREFIX%_FORMAT_MESSAGE_AS_STRING("message: %s, %d, %s", "string1", 33, "string2");
 */

#define %PREFIX%_FORMAT_MESSAGE(...) \
	boost::format( \
		__FILE__ "(" __THROW_%PREFIX%_TOSTR(__LINE__) ")[%s]: " \
		__THROW_%PREFIX%_GET_FORMAT_STRING(__VA_ARGS__,) \
	) % __PRETTY_FUNCTION__ __THROW_%PREFIX%_GET_ARGS_LIST(__VA_ARGS__)

#define %PREFIX%_FORMAT_MESSAGE_AS_STRING(...) \
	(%PREFIX%_FORMAT_MESSAGE(__VA_ARGS__)).str()

/***************************************************************************/

/* usage:
 * %PREFIX%_THROW("message: %s, %d, %s", "string1", 33, "string2");
 */

#define %PREFIX%_THROW(...) \
	throw std::runtime_error(%PREFIX%_FORMAT_MESSAGE_AS_STRING(__VA_ARGS__))

/***************************************************************************/

/* usage:
 * %PREFIX%_TYPED_THROW(std::logic_error, "message: %s, %d, %s", "string1", 33, "string2");
 */

#define %PREFIX%_TYPED_THROW(extype, ...) \
	throw extype(%PREFIX%_FORMAT_MESSAGE_AS_STRING(__VA_ARGS__))

/***************************************************************************/

/* usage:
 * %PREFIX%_TRY(exception_is_thrown)
 *    ...code...
 * %PREFIX%_CATCH(exception_is_thrown)
 * if ( exception_is_thrown ) {
 *    ...processing...
 * }
 *
 * usage:
 * %PREFIX%_TRY(exception_is_thrown)
 *    ...code...
 * %PREFIX%_CATCH_LOG(exception_is_thrown, std::cerr)
 * if ( exception_is_thrown ) {
 *    ...processing...
 * }
 */

#define %PREFIX%_TRY(flagname) \
	bool flagname = false; \
	((void)flagname); \
	try {

#define %PREFIX%_CATCH(flagname, ...) \
	} catch (const std::exception &) { \
		flagname = true; \
	} catch (...) { \
		flagname = true; \
	} \
	if ( flagname ) { \
		__VA_ARGS__; \
	}

#define %PREFIX%_CATCH_LOG(flagname, logstream, ...) \
	} catch (const std::exception &ex) { \
		flagname = true; \
		logstream << %PREFIX%_FORMAT_MESSAGE("[exception]: %s", ex.what()) << std::endl; \
	} catch (...) { \
		flagname = true; \
		logstream << %PREFIX%_FORMAT_MESSAGE("[exception]: unknown exception") << std::endl; \
	} \
	if ( flagname ) { \
		__VA_ARGS__; \
	}

/***************************************************************************/

#endif // _throw__throw_hpp
