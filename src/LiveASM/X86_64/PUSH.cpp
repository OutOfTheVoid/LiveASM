#include <LiveASM/X86_64/Arch.h>
#include <LiveASM/X86_64/OpCodes.h>
#include <LiveASM/X86_64/OpUtil.h>

void LA_X86_64_Push_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Register )
{
	
	if ( _LA_X86_64_R64IsGPR ( Register ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
		
	Buffer.push_back ( X86_64_OP_PUSH_R64 | _LA_X86_64_R64ToIndex3 ( Register ) );
	
}

void LA_X86_64_Push_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Register )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OP_PUSH_R64 | _LA_X86_64_R16ToIndex3 ( Register ) );
	
}

void LA_X86_64_Push_SX_SIMM8 ( LiveASM_CodeBuffer & Buffer, int8_t SIMM8 )
{
	
	Buffer.push_back ( X86_64_OP_PUSH_SX_IMM8 );
	_LA_X86_64_WriteSIMM8 ( Buffer, SIMM8 );
	
}

void LA_X86_64_Push_SX_SIMM16 ( LiveASM_CodeBuffer & Buffer, int16_t SIMM16 )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OP_PUSH_SX );
	_LA_X86_64_WriteSIMM16 ( Buffer, SIMM16 );
	
}

void LA_X86_64_Push_SX_SIMM32 ( LiveASM_CodeBuffer & Buffer, int32_t SIMM32 )
{
	
	Buffer.push_back ( X86_64_OP_PUSH_SX );
	_LA_X86_64_WriteSIMM32 ( Buffer, SIMM32 );
	
}

void LA_X86_64_Push_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Register )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Register ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OP_PUSH_IND );
	_LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( Buffer, 6, Register );
	
}

void LA_X86_64_Push_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Register, int8_t Offset )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Register ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OP_PUSH_IND );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( Buffer, 6, Register );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Push_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Register, int32_t Offset )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Register ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OP_PUSH_IND );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( Buffer, 6, Register );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Push_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OP_PUSH_IND );
	_LA_X86_64_WriteModRM_Indirect_Digit_SIB ( Buffer, 6 );
	_LA_X86_64_WriteSIB64 ( Buffer, SIB_Data.IndexScale, SIB_Data.IndexRegister, SIB_Data.BaseRegister );
	
}

void LA_X86_64_Push_Indirect_SIB_R64_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data, int8_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OP_PUSH_IND );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_SIB ( Buffer, 6 );
	_LA_X86_64_WriteSIB64 ( Buffer, SIB_Data.IndexScale, SIB_Data.IndexRegister, SIB_Data.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Push_Indirect_SIB_R64_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data, int32_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SIB_Data.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OP_PUSH_IND );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_SIB ( Buffer, 6 );
	_LA_X86_64_WriteSIB64 ( Buffer, SIB_Data.IndexScale, SIB_Data.IndexRegister, SIB_Data.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Push_FS ( LiveASM_CodeBuffer & Buffer )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_PUSH_FS );
	
}

void LA_X86_64_Push_GS ( LiveASM_CodeBuffer & Buffer )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_PUSH_GS );
	
}

AutoOpResult LA_X86_64_Push_Auto ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_Operand & Source )
{
	
	switch ( Source.OperandType )
	{
		
		case LA_X86_64_Operand_Struct :: kType_R64_Direct:
			LA_X86_64_Push_R64 ( Buffer, Source.Value.R64 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_R32_Direct:
			return kAutoOpResult_IllegalOperation;
			
		case LA_X86_64_Operand_Struct :: kType_R16_Direct:
			LA_X86_64_Push_R16 ( Buffer, Source.Value.R16 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_R8_Direct:
			return kAutoOpResult_IllegalOperation;
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
			LA_X86_64_Push_Indirect ( Buffer, Source.Value.Indirect.R64 );
			return kAutoOpResult_Success;
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
			LA_X86_64_Push_Indirect_OffsetSIMM8 ( Buffer, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
			LA_X86_64_Push_Indirect_OffsetSIMM32 ( Buffer, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_Segment:
		{
			
			switch ( Source.Value.Segment )
			{
				
				case kLA_X86_64_Segment_FS:
					LA_X86_64_Push_FS ( Buffer );
					return kAutoOpResult_Success;
					
				case kLA_X86_64_Segment_GS:
					LA_X86_64_Push_GS ( Buffer );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
			
		case LA_X86_64_Operand_Struct :: kType_SIMM8:
			LA_X86_64_Push_SX_SIMM8 ( Buffer, Source.Value.SIMM8 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_SIMM16:
			LA_X86_64_Push_SX_SIMM16 ( Buffer, Source.Value.SIMM16 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_SIMM32:
			LA_X86_64_Push_SX_SIMM32 ( Buffer, Source.Value.SIMM32 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_IMM8:
			
			if ( Source.Value.IMM16 < 0x7F )
				LA_X86_64_Push_SX_SIMM8 ( Buffer, static_cast <int8_t> ( Source.Value.IMM8 ) );
			else
				LA_X86_64_Push_SX_SIMM16 ( Buffer, static_cast <int16_t> ( Source.Value.IMM8 ) );
			
			return kAutoOpResult_Success_EquivalentModified;
			
		case LA_X86_64_Operand_Struct :: kType_IMM16:
			
			if ( Source.Value.IMM16 < 0x7FFF )
				LA_X86_64_Push_SX_SIMM16 ( Buffer, static_cast <int16_t> ( Source.Value.IMM16 ) );
			else
				LA_X86_64_Push_SX_SIMM32 ( Buffer, static_cast <uint32_t> ( Source.Value.IMM16 ) );
			
			return kAutoOpResult_Success_EquivalentModified;
			
		case LA_X86_64_Operand_Struct :: kType_IMM32:
			
			if ( Source.Value.IMM32 > 0x7FFFFFFF )
				return kAutoOpResult_IllegalOperation;
			
			LA_X86_64_Push_SX_SIMM32 ( Buffer, static_cast <int32_t> ( Source.Value.IMM32 ) );
			return kAutoOpResult_Success_EquivalentModified;
			
		case LA_X86_64_Operand_Struct :: kType_IMM64:
			
			if ( Source.Value.IMM64 > 0x7FFFFFFF )
				return kAutoOpResult_IllegalOperation;
			
			LA_X86_64_Push_SX_SIMM32 ( Buffer, static_cast <int32_t> ( Source.Value.IMM64 ) );
			return kAutoOpResult_Success_EquivalentModified;
			
		case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
			return kAutoOpResult_IllegalOperation;
		
		case LA_X86_64_Operand_Struct :: kType_SIB:
			LA_X86_64_Push_Indirect_SIB_R64 ( Buffer, Source.Value.SIB.SIB );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
			LA_X86_64_Push_Indirect_SIB_R64_OffsetSIMM8 ( Buffer, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
			return kAutoOpResult_Success;
			
		case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
			LA_X86_64_Push_Indirect_SIB_R64_OffsetSIMM32 ( Buffer, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
			return kAutoOpResult_Success;
		
	}
	
	return kAutoOpResult_IllegalOperation;
	
}
