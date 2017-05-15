#include <LiveASM/X86_64/Arch.h>
#include <LiveASM/X86_64/OpCodes.h>
#include <LiveASM/X86_64/OpUtil.h>

void LA_X86_64_NearReturn ( LiveASM_CodeBuffer & Buffer )
{
	
	Buffer.push_back ( X86_64_OP_RETURN_NEAR );
	
}

void LA_X86_64_NearReturn_PopIMM16 ( LiveASM_CodeBuffer & Buffer, uint16_t IMM16 )
{
	
	Buffer.push_back ( X86_64_OP_RETURN_NEAR_POP_IMM16 );
	_LA_X86_64_WriteIMM16 ( Buffer, IMM16 );
	
}

AutoOpResult LA_X86_64_NearReturn_Auto ( LiveASM_CodeBuffer & Buffer, uint16_t PopByteCount )
{
	
	if ( PopByteCount == 0 )
		LA_X86_64_NearReturn ( Buffer );
	else
		LA_X86_64_NearReturn_PopIMM16 ( Buffer, PopByteCount );
	
	return kAutoOpResult_Success;
	
}
