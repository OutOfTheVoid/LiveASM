#ifndef LIVEASM_TEST_TEST_H
#define LIVEASM_TEST_TEST_H

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdarg.h>

inline void LiveASM_AssertFailure ( const std :: string & Message, uint32_t ExpectedLength, uint8_t * Expected, const std::vector <uint8_t> & Generated )
{
	
	std :: cerr << "LiveASM assert failure: " << Message << std :: endl;
	std :: cerr << "Expected: { " << std :: hex;
	
	if ( ExpectedLength != 1 )
	{
		
		for ( uint32_t I = 0; I < ( ExpectedLength - 1 ); I ++ )
			std :: cerr << (uint32_t) Expected [ I ] << ", ";
		
	}
	
	std :: cerr << (uint32_t) Expected [ ExpectedLength - 1 ] << " }" << std :: endl;
	
	std :: cerr << "Generated: { ";
	
	if ( Generated.size () != 1 )
	{
		
		for ( uint32_t I = 0; I < ( Generated.size () - 1 ); I ++ )
			std :: cerr << (uint32_t) Generated [ I ] << ", ";
		
	}
	
	std :: cerr << (uint32_t) Generated [ Generated.size () - 1 ] << " }" << std :: endl;
	
	exit ( 1 );
	
}

#define STR( s ) #s

#define ARLIT( ... ) __VA_ARGS__

#define ASSERT_OPCODE( opcall, bytearray ) \
{ \
	uint8_t CorrectBytes [] = bytearray; \
	std :: vector <uint8_t> Buffer; \
	opcall; \
	\
	if ( sizeof ( CorrectBytes ) != Buffer.size () ) \
		LiveASM_AssertFailure ( STR ( opcall ), sizeof ( CorrectBytes ) / sizeof ( uint8_t ), CorrectBytes, Buffer ); \
	\
	for ( uint32_t I = 0; I < ( sizeof ( CorrectBytes ) / sizeof ( uint8_t ) ); I ++ ) \
	{ \
		if ( Buffer [ I ] != CorrectBytes [ I ] ) \
			LiveASM_AssertFailure ( STR ( opcall ), sizeof ( CorrectBytes ) / sizeof ( uint8_t ), CorrectBytes, Buffer ); \
	} \
}

void LiveASM_FullTest ();

#endif
