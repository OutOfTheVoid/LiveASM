#include <LiveASM/X86_64/Arch.h>
#include <LiveASM/X86_64/OpCodes.h>
#include <LiveASM/X86_64/OpUtil.h>

void LA_X86_64_Move_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Direct_REG_R64_RM_R64 ( Buffer, Source, Destination );
	
}

void LA_X86_64_Move_R32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R32 Source )
{
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Direct_REG_R32_RM_R32 ( Buffer, Source, Destination );
	
}

void LA_X86_64_Move_R16_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Direct_REG_R16_RM_R16 ( Buffer, Source, Destination );
	
}

void LA_X86_64_Move_R8_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, LA_X86_64_R8 Source )
{
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG_8 );
	_LA_X86_64_WriteModRM_Direct_REG_R8_RM_R8 ( Buffer, Source, Destination );
	
}

void LA_X86_64_Move_Indirect_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, LA_X86_64_R64_Indirect SourceIndirect )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM_8 );
	_LA_X86_64_WriteModRM_Indirect_REG_R8_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	
}

void LA_X86_64_Move_Indirect_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect SourceIndirect )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R16_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	
}

void LA_X86_64_Move_Indirect_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect SourceIndirect )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	
}

void LA_X86_64_Move_Indirect_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect SourceIndirect )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM8_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, LA_X86_64_R64_Indirect SourceIndirect, int8_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R8_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect SourceIndirect, int8_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R16_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect SourceIndirect, int8_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect SourceIndirect, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM32_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, LA_X86_64_R64_Indirect SourceIndirect, int32_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R8_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM32_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect SourceIndirect, int32_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R16_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect SourceIndirect, int32_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect SourceIndirect, int32_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( SourceIndirect ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_SIB_R64_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM_8 );
	_LA_X86_64_WriteModRM_Indirect_REG_R8_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	
}

void LA_X86_64_Move_Indirect_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R16_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	
}

void LA_X86_64_Move_Indirect_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	
}

void LA_X86_64_Move_Indirect_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int8_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R8_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int8_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R16_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int8_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int32_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R8_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int32_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R16_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int32_t Offset )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int32_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

//==================================================================================================================

void LA_X86_64_Move_R8_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, LA_X86_64_R8 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG_8 );
	_LA_X86_64_WriteModRM_Indirect_REG_R8_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	
}

void LA_X86_64_Move_R16_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R16_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	
}

void LA_X86_64_Move_R32_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, LA_X86_64_R32 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	
}

void LA_X86_64_Move_R64_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Source ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	
}

void LA_X86_64_Move_R8_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int8_t Offset, LA_X86_64_R8 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R8_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R16_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int8_t Offset, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R16_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R32_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int8_t Offset, LA_X86_64_R32 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R32_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R64_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int8_t Offset, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Source ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R64_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R8_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int32_t Offset, LA_X86_64_R8 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R8_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R16_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int32_t Offset, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R16_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R32_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int32_t Offset, LA_X86_64_R32 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R32_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R64_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int32_t Offset, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( Source ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirect ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R64_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( DestinationIndirect ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R8_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, LA_X86_64_R8 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG_8 );
	_LA_X86_64_WriteModRM_Indirect_REG_R8_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	
}

void LA_X86_64_Move_R16_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R16_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	
}

void LA_X86_64_Move_R32_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, LA_X86_64_R32 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	
}

void LA_X86_64_Move_R64_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	
	
}

void LA_X86_64_Move_R8_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, LA_X86_64_R8 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R8_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R16_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R16_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R32_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, LA_X86_64_R32 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R32_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R64_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R64_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
	
}

void LA_X86_64_Move_R8_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, LA_X86_64_R8 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R8_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R16_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R16_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R32_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, LA_X86_64_R32 Source )
{
	
	_LA_X86_64_WriteREX ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R32_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_R64_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) ? kLA_X86_64_REXFlag_R : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R64_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}
//==================================================================================================================

void LA_X86_64_Move_R64_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_SEG_REGMEM );
	_LA_X86_64_WriteModRM_Direct_REG_Segment_RM_R64 ( Buffer, Destination, Source );
	
}

void LA_X86_64_Move_R32_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R32 Source )
{
	
	Buffer.push_back ( X86_64_OP_MOV_SEG_REGMEM );
	_LA_X86_64_WriteModRM_Direct_REG_Segment_RM_R32 ( Buffer, Destination, Source );
	
}

void LA_X86_64_Move_R16_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OP_MOV_SEG_REGMEM );
	_LA_X86_64_WriteModRM_Direct_REG_Segment_RM_R16 ( Buffer, Destination, Source );
	
}

void LA_X86_64_Move_Indirect_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R64_Indirect Source )
{
	
	Buffer.push_back ( X86_64_OP_MOV_SEG_REGMEM );
	_LA_X86_64_WriteModRM_REG_Segment_RM_Indirect_R64 ( Buffer, Destination, Source );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM8_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R64_Indirect Source, int8_t Offset )
{
	
	Buffer.push_back ( X86_64_OP_MOV_SEG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_Segment_RM_Indirect_R64 ( Buffer, Destination, Source );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM32_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R64_Indirect Source, int32_t Offset )
{
	
	Buffer.push_back ( X86_64_OP_MOV_SEG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_Segment_RM_Indirect_R64 ( Buffer, Destination, Source );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_SIB_R64_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_SEG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_REG_Segment_RM_Indirect_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int8_t Offset )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_SEG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_Segment_RM_Indirect_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int32_t Offset )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( SourceIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_SEG_REGMEM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_Segment_RM_Indirect_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, SourceIndirectSIB.IndexScale, SourceIndirectSIB.IndexRegister, SourceIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Segment_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_Segment Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_SEG );
	_LA_X86_64_WriteModRM_Direct_REG_Segment_RM_R64 ( Buffer, Source, Destination );
	
}

void LA_X86_64_Move_Segment_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_Segment Source )
{
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_SEG );
	_LA_X86_64_WriteModRM_Direct_REG_Segment_RM_R32 ( Buffer, Source, Destination );
	
}

void LA_X86_64_Move_Segment_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_Segment Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_SEG );
	_LA_X86_64_WriteModRM_Direct_REG_Segment_RM_R16 ( Buffer, Source, Destination );
	
}

void LA_X86_64_Move_Segment_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, LA_X86_64_Segment Source )
{
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_SEG );
	_LA_X86_64_WriteModRM_REG_Segment_RM_Indirect_R64 ( Buffer, Source, Destination );
	
}

void LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, LA_X86_64_Segment Source )
{
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_SEG );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_Segment_RM_Indirect_R64 ( Buffer, Source, Destination );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, LA_X86_64_Segment Source )
{
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_SEG );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_Segment_RM_Indirect_R64 ( Buffer, Source, Destination );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Segment_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, LA_X86_64_Segment Source )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_SEG );
	_LA_X86_64_WriteModRM_Indirect_REG_Segment_RM_Indirect_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	
}

void LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, LA_X86_64_Segment Source )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_SEG );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_Segment_RM_Indirect_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, LA_X86_64_Segment Source )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_SEG );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_Segment_RM_Indirect_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_Move_Offset_IMM64_To_RAX ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, 0 );
	Buffer.push_back ( X86_64_OP_MOV_RA_MEM );
	_LA_X86_64_WriteIMM64 ( Buffer, SourceOffset );
	
}

void LA_X86_64_Move_Offset_IMM64_To_EAX ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset )
{
	
	Buffer.push_back ( X86_64_OP_MOV_RA_MEM );
	_LA_X86_64_WriteIMM64 ( Buffer, SourceOffset );
	
}

void LA_X86_64_Move_Offset_IMM64_To_AX ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OP_MOV_RA_MEM );
	_LA_X86_64_WriteIMM64 ( Buffer, SourceOffset );
	
}

void LA_X86_64_Move_Offset_IMM64_To_AL ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset )
{
	
	Buffer.push_back ( X86_64_OP_MOV_AL_MEM );
	_LA_X86_64_WriteIMM64 ( Buffer, SourceOffset );
	
}

void LA_X86_64_Move_RAX_To_Offset_IMM64 ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, 0 );
	Buffer.push_back ( X86_64_OP_MOV_MEM_RA );
	_LA_X86_64_WriteIMM64 ( Buffer, SourceOffset );
	
}

void LA_X86_64_Move_EAX_To_Offset_IMM64 ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset )
{
	
	Buffer.push_back ( X86_64_OP_MOV_MEM_RA );
	_LA_X86_64_WriteIMM64 ( Buffer, SourceOffset );
	
}

void LA_X86_64_Move_AX_To_Offset_IMM64 ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OP_MOV_MEM_RA );
	_LA_X86_64_WriteIMM64 ( Buffer, SourceOffset );
	
}

void LA_X86_64_Move_AL_To_Offset_IMM64 ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset )
{
	
	Buffer.push_back ( X86_64_OP_MOV_MEM_AL );
	_LA_X86_64_WriteIMM64 ( Buffer, SourceOffset );
	
}

void LA_X86_64_Move_IMM64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Register, uint64_t IMM64 )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( Register ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REG_IMM | _LA_X86_64_R64ToIndex3 ( Register ) );
	_LA_X86_64_WriteIMM64 ( Buffer, IMM64 );
	
}

void LA_X86_64_Move_SIMM32_SX_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Register, int32_t SIMM32 )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Register ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Direct_Digit_RM_R64 ( Buffer, 0, Register );
	_LA_X86_64_WriteSIMM32 ( Buffer, SIMM32 );
	
}

void LA_X86_64_Move_IMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Register, uint32_t IMM32 )
{
	
	Buffer.push_back ( X86_64_OP_MOV_REG_IMM | _LA_X86_64_R32ToIndex3 ( Register ) );
	_LA_X86_64_WriteIMM32 ( Buffer, IMM32 );
	
}

void LA_X86_64_Move_IMM16_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Register, uint16_t IMM16 )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OP_MOV_REG_IMM | _LA_X86_64_R16ToIndex3 ( Register ) );
	_LA_X86_64_WriteIMM16 ( Buffer, IMM16 );
	
}

void LA_X86_64_Move_IMM8_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Register, uint8_t IMM8 )
{
	
	Buffer.push_back ( X86_64_OP_MOV_REG_IMM_8 | _LA_X86_64_R8ToIndex3 ( Register ) );
	Buffer.push_back ( IMM8 );
	
}

void LA_X86_64_Move_IMM32_SX64_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t SIMM32 )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteSIMM32 ( Buffer, SIMM32 );
	
}

void LA_X86_64_Move_IMM32_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, uint32_t IMM32 )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteIMM32 ( Buffer, IMM32 );
	
}

void LA_X86_64_Move_IMM16_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, uint16_t IMM16 )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
		
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteIMM16 ( Buffer, IMM16 );
	
}

void LA_X86_64_Move_IMM8_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, uint8_t IMM8 )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM_8 );
	_LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( Buffer, 0, Destination );
	Buffer.push_back ( IMM8 );
	
}

void LA_X86_64_Move_IMM32_SX64_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, int32_t SIMM32 )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	_LA_X86_64_WriteSIMM32 ( Buffer, SIMM32 );
	
}

void LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, uint32_t IMM32 )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	_LA_X86_64_WriteIMM32 ( Buffer, IMM32 );
	
}

void LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, uint16_t IMM16 )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
		
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM ); 
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	_LA_X86_64_WriteIMM16 ( Buffer, IMM16 );
	
}

void LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, uint8_t IMM8 )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	Buffer.push_back ( IMM8 );
	
}

void LA_X86_64_Move_IMM32_SX64_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, int32_t SIMM32 )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	_LA_X86_64_WriteSIMM32 ( Buffer, SIMM32 );
	
}

void LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, uint32_t IMM32 )
{
	
	_LA_X86_64_WriteREX ( Buffer, _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	_LA_X86_64_WriteIMM32 ( Buffer, IMM32 );
	
}

void LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, uint16_t IMM16 )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
		
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM ); 
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	_LA_X86_64_WriteIMM16 ( Buffer, IMM16 );
	
}

void LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, uint8_t IMM8 )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( Buffer, 0, Destination );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	Buffer.push_back ( IMM8 );
	
}

void LA_X86_64_Move_IMM32_SX64_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t SIMM32 )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, SIMM32 );
	
}

void LA_X86_64_Move_IMM32_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, uint32_t IMM32 )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteIMM32 ( Buffer, IMM32 );
	
}

void LA_X86_64_Move_IMM16_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, uint16_t IMM16 )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteIMM16 ( Buffer, IMM16 );
	
}

void LA_X86_64_Move_IMM8_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, uint8_t IMM8 )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM_8 );
	_LA_X86_64_WriteModRM_Indirect_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	Buffer.push_back ( IMM8 );
	
}

void LA_X86_64_Move_IMM32_SX64_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, int32_t SIMM32 )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	_LA_X86_64_WriteSIMM32 ( Buffer, SIMM32 );
	
}

void LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, uint32_t IMM32 )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	_LA_X86_64_WriteIMM32 ( Buffer, IMM32 );
	
}

void LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, uint16_t IMM16 )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	_LA_X86_64_WriteIMM16 ( Buffer, IMM16 );
	
}

void LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, uint8_t IMM8 )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset8_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	Buffer.push_back ( IMM8 );
	
}

void LA_X86_64_Move_IMM32_SX64_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, int32_t SIMM32 )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) );
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	_LA_X86_64_WriteSIMM32 ( Buffer, SIMM32 );
	
}

void LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, uint32_t IMM32 )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	_LA_X86_64_WriteIMM32 ( Buffer, IMM32 );
	
}

void LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, uint16_t IMM16 )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	_LA_X86_64_WriteIMM16 ( Buffer, IMM16 );
	
}

void LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, uint8_t IMM8 )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( DestinationIndirectSIB.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OP_MOV_REGMEM_IMM_8 );
	_LA_X86_64_WriteModRM_Indirect_Offset32_Digit_SIB ( Buffer, 0 );
	_LA_X86_64_WriteSIB64 ( Buffer, DestinationIndirectSIB.IndexScale, DestinationIndirectSIB.IndexRegister, DestinationIndirectSIB.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	Buffer.push_back ( IMM8 );
	
}

AutoOpResult LA_X86_64_Move_Auto ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_Operand & Destination, const LA_X86_64_Operand & Source )
{
	
	switch ( Source.OperandType )
	{
		
		case LA_X86_64_Operand_Struct :: kType_R64_Direct:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					
					LA_X86_64_Move_R64_To_R64 ( Buffer, _LA_X86_64_R32ToR64 ( Source.Value.R32 ), Source.Value.R64 );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_R64_To_R64 ( Buffer, _LA_X86_64_R16ToR64 ( Destination.Value.R16 ), Source.Value.R64 );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					
					if ( _LA_X86_64_R8IsLow ( Destination.Value.R8 ) )
						LA_X86_64_Move_R64_To_R64 ( Buffer, _LA_X86_64_R8LowToR64 ( static_cast <LA_X86_64_R8_Low> ( Destination.Value.R8 ) ), Source.Value.R64 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
				
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_R64_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_R64_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_R64_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
					LA_X86_64_Move_R64_To_Segment ( Buffer, Destination.Value.Segment, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
					
					if ( Source.Value.R64 == kLA_X86_64_R64_RAX )
						LA_X86_64_Move_RAX_To_Offset_IMM64 ( Buffer, Destination.Value.IMM64 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB:
					LA_X86_64_Move_R64_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_R64_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_R64_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.R64 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R32_Direct:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					
					if ( _LA_X86_64_R64IsGPR ( Destination.Value.R64 ) )
						return kAutoOpResult_IllegalOperation;
					
					LA_X86_64_Move_R32_To_R32 ( Buffer, _LA_X86_64_R64OldToR32 ( static_cast <LA_X86_64_R64_Old> ( Destination.Value.R64 ) ), Source.Value.R32 );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_R32_To_R32 ( Buffer, Destination.Value.R32, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_R32_To_R32 ( Buffer, _LA_X86_64_R16ToR32 ( Destination.Value.R16 ), Source.Value.R32 );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					
					if ( _LA_X86_64_R8IsLow ( Destination.Value.R8 ) )
						LA_X86_64_Move_R32_To_R32 ( Buffer, _LA_X86_64_R8LowToR32 ( static_cast <LA_X86_64_R8_Low> ( Destination.Value.R8 ) ), Source.Value.R32 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
				
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_R32_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_R32_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_R32_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
					LA_X86_64_Move_R32_To_Segment ( Buffer, Destination.Value.Segment, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
					
					if ( Source.Value.R32 == kLA_X86_64_R32_EAX )
						LA_X86_64_Move_EAX_To_Offset_IMM64 ( Buffer, Destination.Value.IMM64 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB:
					LA_X86_64_Move_R32_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_R32_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_R32_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.R32 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R16_Direct:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					
					if ( _LA_X86_64_R64IsGPR ( Destination.Value.R64 ) )
						return kAutoOpResult_IllegalOperation;
					
					LA_X86_64_Move_R16_To_R16 ( Buffer, _LA_X86_64_R64OldToR16 ( static_cast <LA_X86_64_R64_Old> ( Destination.Value.R64 ) ), Source.Value.R16 );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_R16_To_R16 ( Buffer, _LA_X86_64_R32ToR16 ( Destination.Value.R32 ), Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_R16_To_R16 ( Buffer, Destination.Value.R16, Source.Value.R16 );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					
					if ( _LA_X86_64_R8IsLow ( Destination.Value.R8 ) )
						LA_X86_64_Move_R16_To_R16 ( Buffer, _LA_X86_64_R8LowToR16 ( static_cast <LA_X86_64_R8_Low> ( Destination.Value.R8 ) ), Source.Value.R16 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
				
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_R16_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_R16_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_R16_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
					LA_X86_64_Move_R16_To_Segment ( Buffer, Destination.Value.Segment, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
					
					if ( Source.Value.R16 == kLA_X86_64_R16_AX )
						LA_X86_64_Move_AX_To_Offset_IMM64 ( Buffer, Destination.Value.IMM64 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB:
					LA_X86_64_Move_R16_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_R16_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_R16_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.R16 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R8_Direct:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					
					if ( _LA_X86_64_R64IsLowAnalogue ( Destination.Value.R64 ) )
						LA_X86_64_Move_R8_To_R8 ( Buffer, _LA_X86_64_R64ToR8 ( Destination.Value.R64 ), Source.Value.R8 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success_EquivalentModified;
				
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					
					if ( _LA_X86_64_R32IsLowAnalogue ( Destination.Value.R32 ) )
						LA_X86_64_Move_R8_To_R8 ( Buffer, _LA_X86_64_R32ToR8 ( Destination.Value.R32 ), Source.Value.R8 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					
					if ( _LA_X86_64_R16IsLowAnalogue ( Destination.Value.R16 ) )
						LA_X86_64_Move_R8_To_R8 ( Buffer, _LA_X86_64_R16ToR8 ( Destination.Value.R16 ), Source.Value.R8 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					LA_X86_64_Move_R8_To_R8 ( Buffer, Destination.Value.R8, Source.Value.R8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_R8_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.R8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_R8_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.R8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_R8_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.R8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
					
					if ( Source.Value.R8 == kLA_X86_64_R8_AL )
						LA_X86_64_Move_AL_To_Offset_IMM64 ( Buffer, Destination.Value.IMM64 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB:
					LA_X86_64_Move_R8_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.R8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_R8_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.R8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_R8_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.R8 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_Indirect_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_Indirect_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_Indirect_To_R16 ( Buffer, Destination.Value.R16, Source.Value.Indirect.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					LA_X86_64_Move_Indirect_To_R8 ( Buffer, Destination.Value.R8, Source.Value.Indirect.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
					LA_X86_64_Move_Indirect_To_Segment ( Buffer, Destination.Value.Segment, Source.Value.Indirect.R64 );
					return kAutoOpResult_Success;
				
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
				case LA_X86_64_Operand_Struct :: kType_SIB:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM8_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM8_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM8_To_R16 ( Buffer, Destination.Value.R16, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM8_To_R8 ( Buffer, Destination.Value.R8, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
					LA_X86_64_Move_Indirect_OffsetSIMM8_To_Segment ( Buffer, Destination.Value.Segment, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
					return kAutoOpResult_Success;
				
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
				case LA_X86_64_Operand_Struct :: kType_SIB:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM32_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM32_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM32_To_R16 ( Buffer, Destination.Value.R16, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM32_To_R8 ( Buffer, Destination.Value.R8, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
					LA_X86_64_Move_Indirect_OffsetSIMM32_To_Segment ( Buffer, Destination.Value.Segment, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
					return kAutoOpResult_Success;
				
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
				case LA_X86_64_Operand_Struct :: kType_SIB:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_Segment:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_Segment_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Segment );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_Segment_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Segment );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_Segment_To_R16 ( Buffer, Destination.Value.R16, Source.Value.Segment );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_Segment_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.Segment );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.Segment );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.Segment );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
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
					LA_X86_64_Move_Segment_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.Segment );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.Segment );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.Segment );
					return kAutoOpResult_Success;
				
				break;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_SIMM8:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_SIMM32_SX_To_R64 ( Buffer, Destination.Value.R64, static_cast <int32_t> ( Source.Value.SIMM8 ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_IMM32_To_R32 ( Buffer, Destination.Value.R32, static_cast <uint32_t> ( static_cast <int32_t> ( Source.Value.SIMM8 ) ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_IMM16_To_R16 ( Buffer, Destination.Value.R16, static_cast <uint16_t> ( static_cast <int16_t> ( Source.Value.SIMM8 ) ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					LA_X86_64_Move_IMM8_To_R8 ( Buffer, Destination.Value.R8, static_cast <uint8_t> ( Source.Value.SIMM8 ) );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_IMM8_To_Indirect ( Buffer, Destination.Value.Indirect.R64, static_cast <uint8_t> ( Source.Value.SIMM8 ) );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, static_cast <uint8_t> ( Source.Value.SIMM8 ) );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, static_cast <uint8_t> ( Source.Value.SIMM32 ) );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
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
					LA_X86_64_Move_IMM8_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.SIMM8 );
					return kAutoOpResult_Success;
				
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.SIMM8 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_SIMM16:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_SIMM32_SX_To_R64 ( Buffer, Destination.Value.R64, static_cast <int32_t> ( Source.Value.SIMM16 ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_IMM32_To_R32 ( Buffer, Destination.Value.R32, static_cast <uint32_t> ( static_cast <int32_t> ( Source.Value.SIMM16 ) ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_IMM16_To_R16 ( Buffer, Destination.Value.R16, static_cast <uint16_t> ( static_cast <int16_t> ( Source.Value.SIMM16 ) ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_IMM16_To_Indirect ( Buffer, Destination.Value.Indirect.R64, static_cast <uint16_t> ( Source.Value.SIMM16 ) );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, static_cast <uint16_t> ( Source.Value.SIMM16 ) );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, static_cast <uint16_t> ( Source.Value.SIMM16 ) );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
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
					LA_X86_64_Move_IMM16_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.SIMM16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.SIMM16 );
					return kAutoOpResult_Success;
				
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.SIMM16 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_SIMM32:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_SIMM32_SX_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIMM32 );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_IMM32_To_R32 ( Buffer, Destination.Value.R32, static_cast <uint32_t> ( Source.Value.SIMM32 ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_IMM32_To_Indirect ( Buffer, Destination.Value.Indirect.R64, static_cast <uint32_t> ( Source.Value.SIMM32 ) );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, static_cast <uint16_t> ( Source.Value.SIMM32 ) );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, static_cast <uint16_t> ( Source.Value.SIMM32 ) );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
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
					LA_X86_64_Move_IMM32_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.SIMM32 );
					return kAutoOpResult_Success;
				
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.SIMM32 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_IMM8:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_SIMM32_SX_To_R64 ( Buffer, Destination.Value.R64, static_cast <int32_t> ( Source.Value.IMM8 ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_IMM32_To_R32 ( Buffer, Destination.Value.R32, static_cast <uint32_t> ( Source.Value.IMM8 ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_IMM16_To_R16 ( Buffer, Destination.Value.R16, static_cast <uint16_t> ( Source.Value.IMM8 ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					LA_X86_64_Move_IMM8_To_R8 ( Buffer, Destination.Value.R8, Source.Value.IMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_IMM8_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.IMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.IMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.IMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
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
					LA_X86_64_Move_IMM8_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.IMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.IMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.IMM8 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_IMM16:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_SIMM32_SX_To_R64 ( Buffer, Destination.Value.R64, static_cast <int32_t> ( Source.Value.IMM16 ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_IMM32_To_R32 ( Buffer, Destination.Value.R32, static_cast <uint32_t> ( Source.Value.IMM16 ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_IMM16_To_R16 ( Buffer, Destination.Value.R16, Source.Value.IMM16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_IMM16_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.IMM16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.IMM16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.IMM16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
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
					LA_X86_64_Move_IMM16_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.IMM16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.IMM16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.IMM16 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_IMM32:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_SIMM32_SX_To_R64 ( Buffer, Destination.Value.R64, static_cast <int32_t> ( Source.Value.IMM32 ) );
					return kAutoOpResult_Success_EquivalentModified;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_IMM32_To_R32 ( Buffer, Destination.Value.R32, Source.Value.IMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_Move_IMM32_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.IMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.IMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.IMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_Segment:
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
					LA_X86_64_Move_IMM32_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.IMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.IMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.IMM32 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_IMM64:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_IMM64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.IMM64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_Segment:
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
				case LA_X86_64_Operand_Struct :: kType_SIB:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					
					if ( Destination.Value.R64 == kLA_X86_64_R64_RAX )
						LA_X86_64_Move_Offset_IMM64_To_RAX ( Buffer, Source.Value.IMM64 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					
					if ( Destination.Value.R32 == kLA_X86_64_R32_EAX )
						LA_X86_64_Move_Offset_IMM64_To_EAX ( Buffer, Source.Value.IMM64 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					
					if ( Destination.Value.R16 == kLA_X86_64_R16_AX )
						LA_X86_64_Move_Offset_IMM64_To_AX ( Buffer, Source.Value.IMM64 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					
					if ( Destination.Value.R8 == kLA_X86_64_R8_AL )
						LA_X86_64_Move_Offset_IMM64_To_AL ( Buffer, Source.Value.IMM64 );
					else
						return kAutoOpResult_IllegalOperation;
					
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_Segment:
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
				case LA_X86_64_Operand_Struct :: kType_SIB:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
				break;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_SIB:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_Indirect_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_Indirect_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_Indirect_SIB_R64_To_R16 ( Buffer, Destination.Value.R16, Source.Value.SIB.SIB );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					LA_X86_64_Move_Indirect_SIB_R64_To_R8 ( Buffer, Destination.Value.R8, Source.Value.SIB.SIB );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
				case LA_X86_64_Operand_Struct :: kType_Segment:
					LA_X86_64_Move_Indirect_SIB_R64_To_Segment ( Buffer, Destination.Value.Segment, Source.Value.SIB.SIB );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
				case LA_X86_64_Operand_Struct :: kType_SIB:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R16 ( Buffer, Destination.Value.R16, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R8 ( Buffer, Destination.Value.R8, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
				case LA_X86_64_Operand_Struct :: kType_Segment:
					LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_Segment ( Buffer, Destination.Value.Segment, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
				case LA_X86_64_Operand_Struct :: kType_SIB:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R16 ( Buffer, Destination.Value.R16, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R8 ( Buffer, Destination.Value.R8, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
				case LA_X86_64_Operand_Struct :: kType_Segment:
					LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_Segment ( Buffer, Destination.Value.Segment, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIMM16:
				case LA_X86_64_Operand_Struct :: kType_SIMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM8:
				case LA_X86_64_Operand_Struct :: kType_IMM16:
				case LA_X86_64_Operand_Struct :: kType_IMM32:
				case LA_X86_64_Operand_Struct :: kType_IMM64:
				case LA_X86_64_Operand_Struct :: kType_IMM64_Offset:
				case LA_X86_64_Operand_Struct :: kType_SIB:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					return kAutoOpResult_IllegalOperation;
				
			}
			
		}
		
	}
	
	return kAutoOpResult_IllegalOperation;
	
}
