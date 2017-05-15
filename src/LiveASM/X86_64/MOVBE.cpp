#include <LiveASM/X86_64/Arch.h>
#include <LiveASM/X86_64/OpCodes.h>
#include <LiveASM/X86_64/OpUtil.h>

void LA_X86_64_MoveBigEndian_R64_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( Source ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( Destination ) );
	
}

void LA_X86_64_MoveBigEndian_R32_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, LA_X86_64_R32 Source )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( Destination ) );
	
}

void LA_X86_64_MoveBigEndian_R16_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, LA_X86_64_R16 Source )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R16_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( Destination ) );
	
}

void LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( Source ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R64_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( Destination ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, LA_X86_64_R32 Source )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R32_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( Destination ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R16_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( Destination ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( Source ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R64_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( Destination ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, LA_X86_64_R32 Source )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R32_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( Destination ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R16_RM_R64 ( Buffer, Source, static_cast <LA_X86_64_R64> ( Destination ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R64_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( Source ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, Destination.IndexScale, Destination.IndexRegister, Destination.BaseRegister );
	
}

void LA_X86_64_MoveBigEndian_R32_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, LA_X86_64_R32 Source )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, Destination.IndexScale, Destination.IndexRegister, Destination.BaseRegister );
	
}

void LA_X86_64_MoveBigEndian_R16_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_REG_R16_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, Destination.IndexScale, Destination.IndexRegister, Destination.BaseRegister );
	
}

void LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int8_t Offset, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( Source ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R64_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, Destination.IndexScale, Destination.IndexRegister, Destination.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int8_t Offset, LA_X86_64_R32 Source )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R32_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, Destination.IndexScale, Destination.IndexRegister, Destination.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int8_t Offset, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R16_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, Destination.IndexScale, Destination.IndexRegister, Destination.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t Offset, LA_X86_64_R64 Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( Source ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R64_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, Destination.IndexScale, Destination.IndexRegister, Destination.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t Offset, LA_X86_64_R32 Source )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R32_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, Destination.IndexScale, Destination.IndexRegister, Destination.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t Offset, LA_X86_64_R16 Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Destination.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_REG_MEM );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R16_SIB ( Buffer, Source );
	_LA_X86_64_WriteSIB64 ( Buffer, Destination.IndexScale, Destination.IndexRegister, Destination.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	
}

void LA_X86_64_MoveBigEndian_Indirect_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	
}

void LA_X86_64_MoveBigEndian_Indirect_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R16_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R16_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R64_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset )
{
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R32_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	if ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source ) ) )
		_LA_X86_64_WriteREX ( Buffer, kLA_X86_64_REXFlag_B );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R16_RM_R64 ( Buffer, Destination, static_cast <LA_X86_64_R64> ( Source ) );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	
}

void LA_X86_64_MoveBigEndian_Indirect_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	
}

void LA_X86_64_MoveBigEndian_Indirect_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_REG_R16_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset8_REG_R16_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM8 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 ) | ( _LA_X86_64_R64IsGPR ( Destination ) ? kLA_X86_64_REXFlag_R : 0 ) );
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R64_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset )
{
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R32_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	
	LA_X86_64_REXFlag REXFlags = ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.BaseRegister ) ) ? kLA_X86_64_REXFlag_B : 0 ) | ( _LA_X86_64_R64IsGPR ( static_cast <LA_X86_64_R64> ( Source.IndexRegister ) ) ? kLA_X86_64_REXFlag_X : 0 );
	
	if ( REXFlags != 0 )
		_LA_X86_64_WriteREX ( Buffer, REXFlags );
	
	Buffer.push_back ( X86_64_OPPREFIX_EXTENDEDOP );
	Buffer.push_back ( X86_64_OPPREFIX_DOUBLEEXTENDEDOP );
	Buffer.push_back ( X86_64_DEXOP_MOVBE_MEM_REG );
	_LA_X86_64_WriteModRM_Indirect_Offset32_REG_R16_SIB ( Buffer, Destination );
	_LA_X86_64_WriteSIB64 ( Buffer, Source.IndexScale, Source.IndexRegister, Source.BaseRegister );
	_LA_X86_64_WriteSIMM32 ( Buffer, Offset );
	
}

AutoOpResult LA_X86_64_MoveBigEndian_Auto ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_Operand & Destination, const LA_X86_64_Operand & Source )
{
	
	switch ( Source.OperandType )
	{
		
		case LA_X86_64_Operand_Struct :: kType_R64_Direct:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_MoveBigEndian_R64_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.R64 );
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
					LA_X86_64_MoveBigEndian_R64_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.R64 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R32_Direct:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_MoveBigEndian_R32_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.R32 );
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
					LA_X86_64_MoveBigEndian_R32_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.R32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.R32 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R16_Direct:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
				case LA_X86_64_Operand_Struct :: kType_R8_Direct:
					return kAutoOpResult_IllegalOperation;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
					LA_X86_64_MoveBigEndian_R16_To_Indirect ( Buffer, Destination.Value.Indirect.R64, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
					LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM8 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM8, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
					LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM32 ( Buffer, Destination.Value.Indirect.R64, Destination.Value.Indirect.Offset.SIMM32, Source.Value.R16 );
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
					LA_X86_64_MoveBigEndian_R16_To_Indirect_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
					LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM8_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM8, Source.Value.R16 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
					LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM32_SIB_R64 ( Buffer, Destination.Value.SIB.SIB, Destination.Value.SIB.Offset.SIMM32, Source.Value.R16 );
					return kAutoOpResult_Success;
				
			}
			
			return kAutoOpResult_IllegalOperation;
			
		}
		
		case LA_X86_64_Operand_Struct :: kType_R8_Direct:
			return kAutoOpResult_IllegalOperation;
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_MoveBigEndian_Indirect_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_MoveBigEndian_Indirect_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_MoveBigEndian_Indirect_To_R16 ( Buffer, Destination.Value.R16, Source.Value.Indirect.R64 );
					return kAutoOpResult_Success;
				
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
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM8:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_To_R16 ( Buffer, Destination.Value.R16, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM8 );
					return kAutoOpResult_Success;
				
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
		
		case LA_X86_64_Operand_Struct :: kType_R64_Indirect_Offset_SIMM32:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_To_R64 ( Buffer, Destination.Value.R64, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_To_R32 ( Buffer, Destination.Value.R32, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_To_R16 ( Buffer, Destination.Value.R16, Source.Value.Indirect.R64, Source.Value.Indirect.Offset.SIMM32 );
					return kAutoOpResult_Success;
				
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
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_MoveBigEndian_Indirect_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_MoveBigEndian_Indirect_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_MoveBigEndian_Indirect_SIB_R64_To_R16 ( Buffer, Destination.Value.R16, Source.Value.SIB.SIB );
					return kAutoOpResult_Success;
				
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
		
		case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM8:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_SIB_R64_To_R16 ( Buffer, Destination.Value.R16, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM8 );
					return kAutoOpResult_Success;
				
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
		
		case LA_X86_64_Operand_Struct :: kType_SIB_Offset_SIMM32:
		{
			
			switch ( Destination.OperandType )
			{
				
				case LA_X86_64_Operand_Struct :: kType_R64_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_SIB_R64_To_R64 ( Buffer, Destination.Value.R64, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R32_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_SIB_R64_To_R32 ( Buffer, Destination.Value.R32, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
					return kAutoOpResult_Success;
					
				case LA_X86_64_Operand_Struct :: kType_R16_Direct:
					LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_SIB_R64_To_R16 ( Buffer, Destination.Value.R16, Source.Value.SIB.SIB, Source.Value.SIB.Offset.SIMM32 );
					return kAutoOpResult_Success;
				
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
		
	}
	
}


//=======================================[MOVSB]=======================================//

void LA_X86_64_MoveString_64 ( LiveASM_CodeBuffer & Buffer )
{
	
	_LA_X86_64_WriteREX_64 ( Buffer, 0 );
	Buffer.push_back ( X86_64_OP_MOVS );
	
}

void LA_X86_64_MoveString_32 ( LiveASM_CodeBuffer & Buffer )
{
	
	Buffer.push_back ( X86_64_OP_MOVS );
	
}

void LA_X86_64_MoveString_16 ( LiveASM_CodeBuffer & Buffer )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_OPSIZE_OVR );
	Buffer.push_back ( X86_64_OP_MOVS );
	
}

void LA_X86_64_MoveString_8 ( LiveASM_CodeBuffer & Buffer )
{
	
	Buffer.push_back ( X86_64_OP_MOVS_8 );
	
}

AutoOpResult LA_X86_64_MoveString_Auto ( LiveASM_CodeBuffer & Buffer, LA_X86_64_OpSize Size )
{
	
	switch ( Size )
	{
		
		case kLA_X86_64_OpSize_64:
			LA_X86_64_MoveString_64 ( Buffer );
			return kAutoOpResult_Success;
			
		case kLA_X86_64_OpSize_32:
			LA_X86_64_MoveString_32 ( Buffer );
			return kAutoOpResult_Success;
			
		case kLA_X86_64_OpSize_16:
			LA_X86_64_MoveString_16 ( Buffer );
			return kAutoOpResult_Success;
			
		case kLA_X86_64_OpSize_8:
			LA_X86_64_MoveString_8 ( Buffer );
			return kAutoOpResult_Success;
			
	}
	
	return kAutoOpResult_IllegalOperation;
	
}
