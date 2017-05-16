#include <LiveASM/X86_64/Arch.h>
#include <LiveASM/X86_64/OpCodes.h>
#include <LiveASM/X86_64/OpUtil.h>

void LA_X86_64_Multiply_AL_By_R8_To_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Multiplier )
{
	
	Buffer.push_back ( X86_64_EXOP_MUL_8 );
	_LA_X86_64_WriteModRM_Direct_Digit_RM_R8 ( Buffer, 4, Multiplier );
	
}

void LA_X86_64_Multiply_AX_By_R16_To_DX_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Multiplier )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Direct_Digit_RM_R16 ( Buffer, 4, Multiplier );
	
}

void LA_X86_64_Multiply_EAX_By_R32_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Multiplier )
{
	
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Direct_Digit_RM_R32 ( Buffer, 4, Multiplier );
	
}

void LA_X86_64_Multiply_RAX_By_R64_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Multiplier )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Multiplier ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Direct_Digit_RM_R64 ( Buffer, 4, Multiplier );
	
}

void LA_X86_64_Multiply_AL_By_Indirect_To_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_EXOP_MUL_8 );
	_LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( Buffer, 4, Multiplier );
	
}

void LA_X86_64_Multiply_AX_By_Indirect_To_DX_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_R );
	
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( Buffer, 4, Multiplier );
	
}

void LA_X86_64_Multiply_EAX_By_Indirect_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_R );
	
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( Buffer, 4, Multiplier );
	
}

void LA_X86_64_Multiply_RAX_By_Indirect_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( Buffer, 4, Multiplier );
	
}

void LA_X86_64_Multiply_AL_By_Indirect_OffsetSIMM8_To_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int8_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_EXOP_MUL_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( Buffer, 4, Multiplier );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Multiply_AX_By_Indirect_OffsetSIMM8_To_DX_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int8_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_R );
	
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( Buffer, 4, Multiplier );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Multiply_EAX_By_Indirect_OffsetSIMM8_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int8_t Offset )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_R );
	
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( Buffer, 4, Multiplier );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Multiply_RAX_By_Indirect_OffsetSIMM8_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( Buffer, 4, Multiplier );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

// TODO: Finish

void LA_X86_64_Multiply_AL_By_Indirect_OffsetSIMM32_To_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int32_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_EXOP_MUL_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( Buffer, 4, Multiplier );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Multiply_AX_By_Indirect_OffsetSIMM32_To_DX_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int32_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_R );
	
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( Buffer, 4, Multiplier );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Multiply_EAX_By_Indirect_OffsetSIMM32_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int32_t Offset )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_R );
	
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( Buffer, 4, Multiplier );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Multiply_RAX_By_Indirect_OffsetSIMM32_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int32_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier ) ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( Buffer, 4, Multiplier );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

// TODO: Finish


void LA_X86_64_Multiply_AL_By_Indirect_SIB_R64_To_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier.IndexRegister ) ) ? kLA_X86_64_REXFlag_R : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	Buffer.push_back ( X86_64_EXOP_MUL_8 );
	_LA_X86_64_WriteModRM_Indirect_Digit_SIB ( Buffer, 4 );
	
}

void LA_X86_64_Multiply_AX_By_Indirect_SIB_R64_To_DX_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier.IndexRegister ) ) ? kLA_X86_64_REXFlag_R : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Digit_SIB ( Buffer, 4 );
	
}

void LA_X86_64_Multiply_EAX_By_Indirect_SIB_R64_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier.IndexRegister ) ) ? kLA_X86_64_REXFlag_R : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Digit_SIB ( Buffer, 4 );
	
}

void LA_X86_64_Multiply_RAX_By_Indirect_SIB_R64_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Multiplier.IndexRegister ) ) ? kLA_X86_64_REXFlag_R : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX_64 ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_EXOP_MUL );
	_LA_X86_64_WriteModRM_Indirect_Digit_SIB ( Buffer, 4 );
	
}


/*void LA_X86_64_Multiply_AL_By_Indirect_SIB_R64_To_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier );
void LA_X86_64_Multiply_AX_By_Indirect_SIB_R64_To_DX_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier );
void LA_X86_64_Multiply_EAX_By_Indirect_SIB_R64_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier );
void LA_X86_64_Multiply_RAX_By_Indirect_SIB_R64_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier );*/
void LA_X86_64_Multiply_AL_By_Indirect_OffsetSIMM8_SIB_R64_To_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int8_t Offset );
void LA_X86_64_Multiply_AX_By_Indirect_OffsetSIMM8_SIB_R64_To_DX_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int8_t Offset );
void LA_X86_64_Multiply_EAX_By_Indirect_OffsetSIMM8_SIB_R64_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int8_t Offset );
void LA_X86_64_Multiply_RAX_By_Indirect_OffsetSIMM8_SIB_R64_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int8_t Offset );
void LA_X86_64_Multiply_AL_By_Indirect_OffsetSIMM32_SIB_R64_To_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int32_t Offset );
void LA_X86_64_Multiply_AX_By_Indirect_OffsetSIMM32_SIB_R64_To_DX_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int32_t Offset );
void LA_X86_64_Multiply_EAX_By_Indirect_OffsetSIMM32_SIB_R64_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int32_t Offset );
void LA_X86_64_Multiply_RAX_By_Indirect_OffsetSIMM32_SIB_R64_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int32_t Offset );
