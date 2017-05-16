#include <LiveASM/X86_64/Arch.h>
#include <LiveASM/X86_64/OpCodes.h>
#include <LiveASM/X86_64/OpUtil.h>

void LA_X86_64_Pop_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Register )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OP_POP_R64 | _LA_X86_64_R16ToIndex3 ( Register ) );
	
}

void LA_X86_64_Pop_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Register )
{
	
	if ( _LA_X86_64_R64IsGPR ( Register ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
		
	Buffer.push_back ( X86_64_OP_POP_R64 | _LA_X86_64_R64ToIndex3 ( Register ) );
	
}

void LA_X86_64_Pop_FS ( LiveASM_CodeBuffer & Buffer )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_POP_FS );
	
}

void LA_X86_64_Pop_GS ( LiveASM_CodeBuffer & Buffer )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_POP_GS );
	
}

void LA_X86_64_Pop_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Register )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Register ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OP_POP_IND );
	_LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( Buffer, 0, Register );
	
}

void LA_X86_64_Pop_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Register, int8_t Offset )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Register ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OP_POP_IND );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( Buffer, 0, Register );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Pop_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Register, int32_t Offset )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Register ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OP_POP_IND );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( Buffer, 0, Register );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Pop_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_POP_IND );
	_LA_X86_64_WriteModRM_Indirect_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, SIB_Data.IndexScale, SIB_Data.IndexRegister, SIB_Data.BaseRegister );
	
}

void LA_X86_64_Pop_Indirect_SIB_R64_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data, int8_t Offset )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_POP_IND );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, SIB_Data.IndexScale, SIB_Data.IndexRegister, SIB_Data.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Pop_Indirect_SIB_R64_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data, int32_t Offset )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_POP_IND );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, SIB_Data.IndexScale, SIB_Data.IndexRegister, SIB_Data.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

AutoOpResult LA_X86_64_Pop_Auto ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_Operand & Destination )
{
	
	switch ( Destination.OperandType )
	{
		
		case LA_X86_64_Operand_Struct :: kType_R64_Direct:
			LA_X86_64_Pop_R64 ( Buffer, Destination.Value.R64 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_R32_Direct:
			return kAutoOpResult_IllegalOperation;
			
		case LA_X86_64_Operand_Struct :: kType_R16_Direct:
			LA_X86_64_Pop_R16 ( Buffer, Destination.Value.R16 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_R8_Direct:
			return kAutoOpResult_IllegalOperation;
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
			LA_X86_64_Pop_Indirect ( Buffer, Destination.Value.Indirect.R64 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
			LA_X86_64_Pop_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
			LA_X86_64_Pop_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_Segment:
		{
			
			switch ( Destination.Value.Segment )
			{
				
				case kLA_X86_64_Segment_GS:
					LA_X86_64_Pop_GS ( Buffer );
					return kAutoOpResult_Success;
				
				case kLA_X86_64_Segment_FS:
					LA_X86_64_Pop_FS ( Buffer );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
			
		case LA_X86_64_Operand_Struct :: kType_SIMM8:
		case LA_X86_64_Operand_Struct :: kType_SIMM16:
		case LA_X86_64_Operand_Struct :: kType_SIMM32:
		case LA_X86_64_Operand_Struct :: kType_IMM8:
		case LA_X86_64_Operand_Struct :: kType_IMM16:
		case LA_X86_64_Operand_Struct :: kType_IMM32:
		case LA_X86_64_Operand_Struct :: kType_IMM64:
		case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
			return kAutoOpResult_IllegalOperation;
		
		case LA_X86_64_Operand_Struct :: kType_SIB:
			LA_X86_64_Pop_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
			LA_X86_64_Pop_Indirect_SIB_R64_OffsetSIMM8 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
			LA_X86_64_Pop_Indirect_SIB_R64_OffsetSIMM32 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32 );
			return kAutoOpResult_Success;
		
	}
	
	return kAutoOpResult_IllegalOperation;
	
}
