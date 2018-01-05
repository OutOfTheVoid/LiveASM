#include <LiveASM/X86_64/Arch.h>
#include <LiveASM/X86_64/OpCodes.h>
#include <LiveASM/X86_64/OpUtil.h>

void LA_X86_64_MoveSignExtended_R8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R8 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Direct_REG_R16_RM_R8 ( Buffer, Destination, Source );
	
}

void LA_X86_64_MoveSignExtended_R8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R8 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Direct_REG_R32_RM_R8 ( Buffer, Destination, Source );
	
}

void LA_X86_64_MoveSignExtended_R8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R8 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Direct_REG_R64_RM_R8 ( Buffer, Destination, Source );
	
}

void LA_X86_64_MoveSignExtended_R16_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Direct_REG_R32_RM_R16 ( Buffer, Destination, Source );
	
}

void LA_X86_64_MoveSignExtended_R16_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R16 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Direct_REG_R64_RM_R16 ( Buffer, Destination, Source );
	
}

void LA_X86_64_MoveSignExtended_R32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R32 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OP_MOVSX_32 );
	_LA_X86_64_WriteModRM_Direct_REG_R64_RM_R32 ( Buffer, Destination, Source );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_REG_R16_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	
}

void LA_X86_64_MoveSignExtended_Indirect32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OP_MOVSX_32 );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R16_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OP_MOVSX_32 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R16_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OP_MOVSX_32 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_REG_R16_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	
}

void LA_X86_64_MoveSignExtended_Indirect32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OP_MOVSX_32 );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R16_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OP_MOVSX_32 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R16_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_EXOP_MOVSX_16 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OP_MOVSX_32 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

AutoOpResult LA_X86_64_MoveSignExtended_Auto ( LiveASM_CodeBuffer & Buffer, LA_X86_64_OpSize SourceSize, const LA_X86_64_Operand & Destination, const LA_X86_64_Operand & Source )
{
	
	switch ( Source.OperandType )
	{
		
		case LA_X86_64_Operand_Struct :: kType_R64_Direct:
			return kAutoOpResult_IllegalOperation;
			
		case LA_X86_64_Operand_Struct :: kType_R32_Direct:
			
			if ( Destination.OperandType != LA_X86_64_Operand_Struct :: kType_R64_Direct )
				return kAutoOpResult_IllegalOperation;
			
			LA_X86_64_MoveSignExtended_R32_To_R64 ( Buffer, Destination.Value.R64, Source.Value.R32 );
			return kAutoOpResult_Success;
		
		case LA_X86_64_Operand_Struct :: kType_R16_Direct:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_MoveSignExtended_R16_To_R64 ( Buffer, Destination.Value.R64, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_MoveSignExtended_R16_To_R32 ( Buffer, Destination.Value.R32, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				default:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R8_Direct:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_MoveSignExtended_R8_To_R64 ( Buffer, Destination.Value.R64, Source.Value.R8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_MoveSignExtended_R8_To_R32 ( Buffer, Destination.Value.R32, Source.Value.R8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_MoveSignExtended_R8_To_R16 ( Buffer, Destination.Value.R16, Source.Value.R8 );
					return kAutoOpResult_Success;
					
				default:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
				{
					
					switch ( SourceSize )
					{
							
						case kLA_X86_64_OpSize_32:
							LA_X86_64_MoveSignExtended_Indirect32_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64 );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
				{
					
					switch ( SourceSize )
					{
						
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64 );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
				{
					
					if ( SourceSize == kLA_X86_64_OpSize_8 )
					{
						
						LA_X86_64_MoveSignExtended_Indirect8_To_R16 ( Buffer, Destination.Value.R16, Source.Value.Indirect.R64 );
						return kAutoOpResult_Success;
						
					}
					
					return kAutoOpResult_IllegalOperation;
					
				}
				
				default:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
				{
					
					switch ( SourceSize )
					{
							
						case kLA_X86_64_OpSize_32:
							LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM8_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
				{
					
					switch ( SourceSize )
					{
						
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
				{
					
					if ( SourceSize == kLA_X86_64_OpSize_8 )
					{
						
						LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_To_R16 ( Buffer, Destination.Value.R16, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
						return kAutoOpResult_Success;
						
					}
					
					return kAutoOpResult_IllegalOperation;
					
				}
				
				default:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
				{
					
					switch ( SourceSize )
					{
							
						case kLA_X86_64_OpSize_32:
							LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM32_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
				{
					
					switch ( SourceSize )
					{
						
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
				{
					
					if ( SourceSize == kLA_X86_64_OpSize_8 )
					{
						
						LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_To_R16 ( Buffer, Destination.Value.R16, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
						return kAutoOpResult_Success;
						
					}
					
					return kAutoOpResult_IllegalOperation;
					
				}
				
				default:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_SIB:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
				{
					
					switch ( SourceSize )
					{
							
						case kLA_X86_64_OpSize_32:
							LA_X86_64_MoveSignExtended_Indirect32_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
				{
					
					switch ( SourceSize )
					{
						
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
				{
					
					if ( SourceSize == kLA_X86_64_OpSize_8 )
					{
						
						LA_X86_64_MoveSignExtended_Indirect8_SIB_R64_To_R16 ( Buffer, Destination.Value.R16, Source.Value.SIB.SIB );
						return kAutoOpResult_Success;
						
					}
					
					return kAutoOpResult_IllegalOperation;
					
				}
				
				default:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
				{
					
					switch ( SourceSize )
					{
							
						case kLA_X86_64_OpSize_32:
							LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM8_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
				{
					
					switch ( SourceSize )
					{
						
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
				{
					
					if ( SourceSize == kLA_X86_64_OpSize_8 )
					{
						
						LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R16 ( Buffer, Destination.Value.R16, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
						return kAutoOpResult_Success;
						
					}
					
					return kAutoOpResult_IllegalOperation;
					
				}
				
				default:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
				{
					
					switch ( SourceSize )
					{
							
						case kLA_X86_64_OpSize_32:
							LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM32_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
				{
					
					switch ( SourceSize )
					{
						
						case kLA_X86_64_OpSize_16:
							LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
							return kAutoOpResult_Success;
							
						case kLA_X86_64_OpSize_8:
							LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
							return kAutoOpResult_Success;
							
						default:
							return kAutoOpResult_IllegalOperation;
						
					}
					
				}
				
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
				{
					
					if ( SourceSize == kLA_X86_64_OpSize_8 )
					{
						
						LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R16 ( Buffer, Destination.Value.R16, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
						return kAutoOpResult_Success;
						
					}
					
					return kAutoOpResult_IllegalOperation;
					
				}
				
				default:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		default:
			return kAutoOpResult_IllegalOperation;
		
	}
	
}
