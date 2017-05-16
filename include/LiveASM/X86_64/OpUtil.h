#ifndef LIVEASM_X86_64_OPUTIL_H
#define LIVEASM_X86_64_OPUTIL_H

#include <LiveASM/X86_64/Arch.h>
#include <LiveASM/X86_64/OpCodes.h>

typedef uint8_t LA_X86_64_REXFlag;

const LA_X86_64_REXFlag kLA_X86_64_REXFlag_R = 0x01;
const LA_X86_64_REXFlag kLA_X86_64_REXFlag_B = 0x02;
const LA_X86_64_REXFlag kLA_X86_64_REXFlag_X = 0x04;

inline void _LA_X86_64_WriteSIMM8 ( LiveASM_CodeBuffer & Buffer, int8_t SIMM8 )
{
	
	Buffer.push_back ( * reinterpret_cast <uint8_t *> ( & SIMM8 ) );
	
}

inline void _LA_X86_64_WriteIMM16 ( LiveASM_CodeBuffer & Buffer, uint16_t IMM16 )
{
	
	Buffer.push_back ( IMM16 & 0xFF );
	Buffer.push_back ( ( IMM16 >> 8 ) & 0xFF );
	
}

inline void _LA_X86_64_WriteSIMM16 ( LiveASM_CodeBuffer & Buffer, int16_t SIMM16 )
{
	
	_LA_X86_64_WriteIMM16 ( Buffer, * reinterpret_cast <uint16_t *> ( & SIMM16 ) );
	
}

inline void _LA_X86_64_WriteIMM32 ( LiveASM_CodeBuffer & Buffer, uint32_t IMM32 )
{
	
	Buffer.push_back ( IMM32 & 0xFF );
	Buffer.push_back ( ( IMM32 >> 8 ) & 0xFF );
	Buffer.push_back ( ( IMM32 >> 16 ) & 0xFF );
	Buffer.push_back ( ( IMM32 >> 24 ) & 0xFF );
	
}

inline void _LA_X86_64_WriteSIMM32 ( LiveASM_CodeBuffer & Buffer, int32_t SIMM32 )
{
	
	_LA_X86_64_WriteIMM32 ( Buffer, * reinterpret_cast <uint32_t *> ( & SIMM32 ) );
	
}

inline void _LA_X86_64_WriteIMM64 ( LiveASM_CodeBuffer & Buffer, uint64_t IMM64 )
{
	
	Buffer.push_back ( IMM64 & 0xFF );
	Buffer.push_back ( ( IMM64 >> 8 ) & 0xFF );
	Buffer.push_back ( ( IMM64 >> 16 ) & 0xFF );
	Buffer.push_back ( ( IMM64 >> 24 ) & 0xFF );
	Buffer.push_back ( ( IMM64 >> 32 ) & 0xFF );
	Buffer.push_back ( ( IMM64 >> 40 ) & 0xFF );
	Buffer.push_back ( ( IMM64 >> 48 ) & 0xFF );
	Buffer.push_back ( ( IMM64 >> 56 ) & 0xFF );
	
}

inline LA_X86_64_R64 _LA_X86_64_R32ToR64 ( LA_X86_64_R32 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R32_EAX:
			return kLA_X86_64_R64_RAX;
			
		case kLA_X86_64_R32_ECX:
			return kLA_X86_64_R64_RCX;
			
		case kLA_X86_64_R32_EDX:
			return kLA_X86_64_R64_RDX;
			
		case kLA_X86_64_R32_EBX:
			return kLA_X86_64_R64_RBX;
			
		case kLA_X86_64_R32_ESP:
			return kLA_X86_64_R64_RSP;
			
		case kLA_X86_64_R32_EBP:
			return kLA_X86_64_R64_RBP;
			
		case kLA_X86_64_R32_ESI:
			return kLA_X86_64_R64_RSI;
			
		case kLA_X86_64_R32_EDI:
			return kLA_X86_64_R64_RDI;
		
	}
	
	return kLA_X86_64_R64_RAX;
	
}

inline LA_X86_64_R32 _LA_X86_64_R64OldToR32 ( LA_X86_64_R64_Old Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R64_Old_RAX:
			return kLA_X86_64_R32_EAX;
			
		case kLA_X86_64_R64_Old_RCX:
			return kLA_X86_64_R32_ECX;
			
		case kLA_X86_64_R64_Old_RDX:
			return kLA_X86_64_R32_EDX;
			
		case kLA_X86_64_R64_Old_RBX:
			return kLA_X86_64_R32_EBX;
			
		case kLA_X86_64_R64_Old_RSP:
			return kLA_X86_64_R32_ESP;
			
		case kLA_X86_64_R64_Old_RBP:
			return kLA_X86_64_R32_EBP;
			
		case kLA_X86_64_R64_Old_RSI:
			return kLA_X86_64_R32_ESI;
			
		case kLA_X86_64_R64_Old_RDI:
			return kLA_X86_64_R32_EDI;
		
	}
	
	return kLA_X86_64_R32_EAX;
	
}

inline LA_X86_64_R64 _LA_X86_64_R16ToR64 ( LA_X86_64_R16 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R16_AX:
			return kLA_X86_64_R64_RAX;
			
		case kLA_X86_64_R16_CX:
			return kLA_X86_64_R64_RCX;
			
		case kLA_X86_64_R16_DX:
			return kLA_X86_64_R64_RDX;
			
		case kLA_X86_64_R16_BX:
			return kLA_X86_64_R64_RBX;
			
		case kLA_X86_64_R16_SP:
			return kLA_X86_64_R64_RSP;
			
		case kLA_X86_64_R16_BP:
			return kLA_X86_64_R64_RBP;
			
		case kLA_X86_64_R16_SI:
			return kLA_X86_64_R64_RSI;
			
		case kLA_X86_64_R16_DI:
			return kLA_X86_64_R64_RDI;
		
	}
	
	return kLA_X86_64_R64_RAX;
	
}

inline LA_X86_64_R16 _LA_X86_64_R64OldToR16 ( LA_X86_64_R64_Old Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R64_Old_RAX:
			return kLA_X86_64_R16_AX;
			
		case kLA_X86_64_R64_Old_RCX:
			return kLA_X86_64_R16_CX;
			
		case kLA_X86_64_R64_Old_RDX:
			return kLA_X86_64_R16_DX;
			
		case kLA_X86_64_R64_Old_RBX:
			return kLA_X86_64_R16_BX;
			
		case kLA_X86_64_R64_Old_RSP:
			return kLA_X86_64_R16_SP;
			
		case kLA_X86_64_R64_Old_RBP:
			return kLA_X86_64_R16_BP;
			
		case kLA_X86_64_R64_Old_RSI:
			return kLA_X86_64_R16_SI;
			
		case kLA_X86_64_R64_Old_RDI:
			return kLA_X86_64_R16_DI;
		
	}
	
	return kLA_X86_64_R16_AX;
	
}

inline LA_X86_64_R32 _LA_X86_64_R16ToR32 ( LA_X86_64_R16 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R16_AX:
			return kLA_X86_64_R32_EAX;
			
		case kLA_X86_64_R16_CX:
			return kLA_X86_64_R32_ECX;
			
		case kLA_X86_64_R16_DX:
			return kLA_X86_64_R32_EDX;
			
		case kLA_X86_64_R16_BX:
			return kLA_X86_64_R32_EBX;
			
		case kLA_X86_64_R16_SP:
			return kLA_X86_64_R32_ESP;
			
		case kLA_X86_64_R16_BP:
			return kLA_X86_64_R32_EBP;
			
		case kLA_X86_64_R16_SI:
			return kLA_X86_64_R32_ESI;
			
		case kLA_X86_64_R16_DI:
			return kLA_X86_64_R32_EDI;
		
	}
	
	return kLA_X86_64_R32_EAX;
	
}

inline LA_X86_64_R16 _LA_X86_64_R32ToR16 ( LA_X86_64_R32 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R32_EAX:
			return kLA_X86_64_R16_AX;
		
		case kLA_X86_64_R32_ECX:
			return kLA_X86_64_R16_CX;
			
		case kLA_X86_64_R32_EDX:
			return kLA_X86_64_R16_DX;
			
		case kLA_X86_64_R32_EBX:
			return kLA_X86_64_R16_BX;
			
		case kLA_X86_64_R32_ESP:
			return kLA_X86_64_R16_SP;
			
		case kLA_X86_64_R32_EBP:
			return kLA_X86_64_R16_BP;
			
		case kLA_X86_64_R32_ESI:
			return kLA_X86_64_R16_SI;
			
		case kLA_X86_64_R32_EDI:
			return kLA_X86_64_R16_DI;						
		
	}
	
	return kLA_X86_64_R16_AX;
	
}

inline LA_X86_64_R64 _LA_X86_64_R8LowToR64 ( LA_X86_64_R8_Low Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R8_Low_AL:
			return kLA_X86_64_R64_RAX;
			
		case kLA_X86_64_R8_Low_CL:
			return kLA_X86_64_R64_RCX;
			
		case kLA_X86_64_R8_Low_DL:
			return kLA_X86_64_R64_RDX;
			
		case kLA_X86_64_R8_Low_BL:
			return kLA_X86_64_R64_RBX;
		
	}
	
	return kLA_X86_64_R64_RAX;
	
}

inline LA_X86_64_R8 _LA_X86_64_R64ToR8 ( LA_X86_64_R64 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R64_RAX:
			return kLA_X86_64_R8_AL;
			
		case kLA_X86_64_R64_RCX:
			return kLA_X86_64_R8_CL;
			
		case kLA_X86_64_R64_RDX:
			return kLA_X86_64_R8_DL;
			
		case kLA_X86_64_R64_RBX:
			return kLA_X86_64_R8_BL;
		
		default:
			break;
		
	}
	
	return kLA_X86_64_R8_AL;
	
}

inline LA_X86_64_R32 _LA_X86_64_R8LowToR32 ( LA_X86_64_R8_Low Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R8_Low_AL:
			return kLA_X86_64_R32_EAX;
			
		case kLA_X86_64_R8_Low_CL:
			return kLA_X86_64_R32_ECX;
			
		case kLA_X86_64_R8_Low_DL:
			return kLA_X86_64_R32_EDX;
			
		case kLA_X86_64_R8_Low_BL:
			return kLA_X86_64_R32_EBX;
		
	}
	
	return kLA_X86_64_R32_EAX;
	
}

inline LA_X86_64_R8 _LA_X86_64_R32ToR8 ( LA_X86_64_R32 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R32_EAX:
			return kLA_X86_64_R8_AL;
			
		case kLA_X86_64_R32_ECX:
			return kLA_X86_64_R8_CL;
			
		case kLA_X86_64_R32_EDX:
			return kLA_X86_64_R8_DL;
			
		case kLA_X86_64_R32_EBX:
			return kLA_X86_64_R8_BL;
		
		default:
			break;
		
	}
	
	return kLA_X86_64_R8_AL;
	
}

inline LA_X86_64_R16 _LA_X86_64_R8LowToR16 ( LA_X86_64_R8_Low Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R8_Low_AL:
			return kLA_X86_64_R16_AX;
			
		case kLA_X86_64_R8_Low_CL:
			return kLA_X86_64_R16_CX;
			
		case kLA_X86_64_R8_Low_DL:
			return kLA_X86_64_R16_DX;
			
		case kLA_X86_64_R8_Low_BL:
			return kLA_X86_64_R16_BX;
		
	}
	
	return kLA_X86_64_R16_AX;
	
}

inline LA_X86_64_R8 _LA_X86_64_R16ToR8 ( LA_X86_64_R16 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R16_AX:
			return kLA_X86_64_R8_AL;
			
		case kLA_X86_64_R16_CX:
			return kLA_X86_64_R8_CL;
			
		case kLA_X86_64_R16_DX:
			return kLA_X86_64_R8_DL;
			
		case kLA_X86_64_R16_BX:
			return kLA_X86_64_R8_BL;
		
		default:
			break;
		
	}
	
	return kLA_X86_64_R8_AL;
	
}

inline uint8_t _LA_X86_64_R64ToIndex3 ( LA_X86_64_R64 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R64_RAX:
			return 0;
			
		case kLA_X86_64_R64_RCX:
			return 1;
			
		case kLA_X86_64_R64_RDX:
			return 2;
			
		case kLA_X86_64_R64_RBX:
			return 3;
			
		case kLA_X86_64_R64_RSP:
			return 4;
			
		case kLA_X86_64_R64_RBP:
			return 5;
			
		case kLA_X86_64_R64_RSI:
			return 6;
			
		case kLA_X86_64_R64_RDI:
			return 7;
			
		case kLA_X86_64_R64_R8:
			return 0;
			
		case kLA_X86_64_R64_R9:
			return 1;
			
		case kLA_X86_64_R64_R10:
			return 2;
			
		case kLA_X86_64_R64_R11:
			return 3;
			
		case kLA_X86_64_R64_R12:
			return 4;
			
		case kLA_X86_64_R64_R13:
			return 5;
			
		case kLA_X86_64_R64_R14:
			return 6;
			
		case kLA_X86_64_R64_R15:
			return 7;
		
	}
	
	return 0;
	
}

inline uint8_t _LA_X86_64_R32ToIndex3 ( LA_X86_64_R32 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R32_EAX:
			return 0;
			
		case kLA_X86_64_R32_ECX:
			return 1;
			
		case kLA_X86_64_R32_EDX:
			return 2;
			
		case kLA_X86_64_R32_EBX:
			return 3;
			
		case kLA_X86_64_R32_ESP:
			return 4;
			
		case kLA_X86_64_R32_EBP:
			return 5;
			
		case kLA_X86_64_R32_ESI:
			return 6;
			
		case kLA_X86_64_R32_EDI:
			return 7;
		
	}
	
	return 0;
	
}

inline uint8_t _LA_X86_64_R16ToIndex3 ( LA_X86_64_R16 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R16_AX:
			return 0;
			
		case kLA_X86_64_R16_CX:
			return 1;
			
		case kLA_X86_64_R16_DX:
			return 2;
			
		case kLA_X86_64_R16_BX:
			return 3;
			
		case kLA_X86_64_R16_SP:
			return 4;
			
		case kLA_X86_64_R16_BP:
			return 5;
			
		case kLA_X86_64_R16_SI:
			return 6;
			
		case kLA_X86_64_R16_DI:
			return 7;
		
	}
	
	return 0;
	
}

inline uint8_t _LA_X86_64_R8ToIndex3 ( LA_X86_64_R8 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R8_AL:
			return 0;
			
		case kLA_X86_64_R8_CL:
			return 1;
			
		case kLA_X86_64_R8_DL:
			return 2;
			
		case kLA_X86_64_R8_BL:
			return 3;
			
		case kLA_X86_64_R8_AH:
			return 4;
			
		case kLA_X86_64_R8_CH:
			return 5;
			
		case kLA_X86_64_R8_DH:
			return 6;
			
		case kLA_X86_64_R8_BH:
			return 7;
		
	}
	
	return 0;
	
}

inline uint8_t _LA_X86_64_SegmentToIndex3 ( LA_X86_64_Segment Segment )
{
	
	switch ( Segment )
	{
			
		case kLA_X86_64_Segment_FS:
			return 4;
			
		case kLA_X86_64_Segment_GS:
			return 5;
		
	}
	
	return 0;
	
}

inline bool _LA_X86_64_R64IsGPR ( LA_X86_64_R64 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R64_RAX:
		case kLA_X86_64_R64_RBX:
		case kLA_X86_64_R64_RCX:
		case kLA_X86_64_R64_RDX:
		case kLA_X86_64_R64_RSP:
		case kLA_X86_64_R64_RBP:
		case kLA_X86_64_R64_RSI:
		case kLA_X86_64_R64_RDI:
			return false;
			
		case kLA_X86_64_R64_R8:
		case kLA_X86_64_R64_R9:
		case kLA_X86_64_R64_R10:
		case kLA_X86_64_R64_R11:
		case kLA_X86_64_R64_R12:
		case kLA_X86_64_R64_R13:
		case kLA_X86_64_R64_R14:
		case kLA_X86_64_R64_R15:
			return true;
		
	}
	
	return true;
	
}

inline bool _LA_X86_64_R8IsLow ( LA_X86_64_R8 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R8_AL:
		case kLA_X86_64_R8_CL:
		case kLA_X86_64_R8_DL:
		case kLA_X86_64_R8_BL:
			return true;
			
		default:
			break;
		
	}
	
	return false;
	
}

inline bool _LA_X86_64_R64IsLowAnalogue ( LA_X86_64_R64 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R64_RAX:
		case kLA_X86_64_R64_RCX:
		case kLA_X86_64_R64_RDX:
		case kLA_X86_64_R64_RBX:
			return true;
			
		default:
			break;
			
	}
		
	return false;
	
}

inline bool _LA_X86_64_R32IsLowAnalogue ( LA_X86_64_R32 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R32_EAX:
		case kLA_X86_64_R32_ECX:
		case kLA_X86_64_R32_EDX:
		case kLA_X86_64_R32_EBX:
			return true;
			
		default:
			break;
			
	}
		
	return false;
	
}

inline bool _LA_X86_64_R16IsLowAnalogue ( LA_X86_64_R16 Register )
{
	
	switch ( Register )
	{
		
		case kLA_X86_64_R16_AX:
		case kLA_X86_64_R16_CX:
		case kLA_X86_64_R16_DX:
		case kLA_X86_64_R16_BX:
			return true;
			
		default:
			break;
			
	}
		
	return false;
	
}

inline uint8_t _LA_X86_64_SIBScaleToIndex2 ( LA_X86_64_SIBScale Scale )
{
	
	switch ( Scale )
	{
		
		case kLA_X86_64_SIBScale_1:
			return 0;
			
		case kLA_X86_64_SIBScale_2:
			return 1;
			
		case kLA_X86_64_SIBScale_4:
			return 2;
			
		case kLA_X86_64_SIBScale_8:
			return 3;
		
	}
	
	return 0;
	
}

#endif


inline void _LA_X86_64_WriteModRM_Direct_REG_R64_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_R64ToIndex3 ( REGRegister ) << X86_64_OPPREFIX_MODRM_REG_SHIFT ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_R64_RM_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 REGRegister, LA_X86_64_R32 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_R64ToIndex3 ( REGRegister ) << X86_64_OPPREFIX_MODRM_REG_SHIFT ) | _LA_X86_64_R32ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_R64_RM_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 REGRegister, LA_X86_64_R16 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_R64ToIndex3 ( REGRegister ) << X86_64_OPPREFIX_MODRM_REG_SHIFT ) | _LA_X86_64_R16ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_R64_RM_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 REGRegister, LA_X86_64_R8 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_R64ToIndex3 ( REGRegister ) << X86_64_OPPREFIX_MODRM_REG_SHIFT ) | _LA_X86_64_R8ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_R32_RM_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 REGRegister, LA_X86_64_R32 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_R32ToIndex3 ( REGRegister ) << X86_64_OPPREFIX_MODRM_REG_SHIFT ) | _LA_X86_64_R32ToIndex3 ( RMRegister )  );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_R32_RM_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 REGRegister, LA_X86_64_R16 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_R32ToIndex3 ( REGRegister ) << X86_64_OPPREFIX_MODRM_REG_SHIFT ) | _LA_X86_64_R16ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_R32_RM_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 REGRegister, LA_X86_64_R8 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_R32ToIndex3 ( REGRegister ) << X86_64_OPPREFIX_MODRM_REG_SHIFT ) | _LA_X86_64_R8ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_R16_RM_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 REGRegister, LA_X86_64_R16 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_R16ToIndex3 ( REGRegister ) << X86_64_OPPREFIX_MODRM_REG_SHIFT ) | _LA_X86_64_R16ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_R16_RM_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 REGRegister, LA_X86_64_R8 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_R16ToIndex3 ( REGRegister ) << X86_64_OPPREFIX_MODRM_REG_SHIFT ) | _LA_X86_64_R8ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_R8_RM_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 REGRegister, LA_X86_64_R8 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_R8ToIndex3 ( REGRegister ) << X86_64_OPPREFIX_MODRM_REG_SHIFT ) | _LA_X86_64_R8ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_Digit_RM_R64 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( Digit << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_Digit_RM_R32 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R32 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( Digit << 3 ) | _LA_X86_64_R32ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_Digit_RM_R16 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R16 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( Digit << 3 ) | _LA_X86_64_R16ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_Digit_RM_R8 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R8 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( Digit << 3 ) | _LA_X86_64_R8ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_Segment_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_SegmentToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_Segment_RM_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment REGRegister, LA_X86_64_R32 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_SegmentToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R32ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Direct_REG_Segment_RM_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment REGRegister, LA_X86_64_R16 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_DIRECT | ( _LA_X86_64_SegmentToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R16ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_REG_Segment_RM_Indirect_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment REGRegister, LA_X86_64_R64_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( _LA_X86_64_SegmentToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( static_cast <LA_X86_64_R64> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset8_REG_Segment_RM_Indirect_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment REGRegister, LA_X86_64_R64_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( _LA_X86_64_SegmentToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( static_cast <LA_X86_64_R64> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset32_REG_Segment_RM_Indirect_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment REGRegister, LA_X86_64_R64_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( _LA_X86_64_SegmentToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( static_cast <LA_X86_64_R64> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_REG_R64_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( _LA_X86_64_R64ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_REG_R32_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( _LA_X86_64_R32ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_REG_R16_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( _LA_X86_64_R16ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_REG_R8_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( _LA_X86_64_R8ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R64_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( _LA_X86_64_R64ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R32_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( _LA_X86_64_R32ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R16_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( _LA_X86_64_R16ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset_SIMM8_REG_R8_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( _LA_X86_64_R8ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R64_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( _LA_X86_64_R64ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R32_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( _LA_X86_64_R32ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R16_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( _LA_X86_64_R16ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset_SIMM32_REG_R8_RM_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 REGRegister, LA_X86_64_R64 RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( _LA_X86_64_R8ToIndex3 ( REGRegister ) << 3 ) | _LA_X86_64_R64ToIndex3 ( RMRegister ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Digit_RM_R64 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R64_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( Digit << 3 ) | _LA_X86_64_R64ToIndex3 ( static_cast <LA_X86_64_R64> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Digit_RM_R32 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R32_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( Digit << 3 ) | _LA_X86_64_R32ToIndex3 ( static_cast <LA_X86_64_R32> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Digit_RM_R16 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R16_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( Digit << 3 ) | _LA_X86_64_R16ToIndex3 ( static_cast <LA_X86_64_R16> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R64 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R64_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( Digit << 3 ) | _LA_X86_64_R64ToIndex3 ( static_cast <LA_X86_64_R64> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R32 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R32_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( Digit << 3 ) | _LA_X86_64_R32ToIndex3 ( static_cast <LA_X86_64_R32> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset8_Digit_RM_R16 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R16_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( Digit << 3 ) | _LA_X86_64_R16ToIndex3 ( static_cast <LA_X86_64_R16> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R64 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R64_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( Digit << 3 ) | _LA_X86_64_R64ToIndex3 ( static_cast <LA_X86_64_R64> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R32 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R32_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( Digit << 3 ) | _LA_X86_64_R32ToIndex3 ( static_cast <LA_X86_64_R32> ( RMRegister ) ) );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset32_Digit_RM_R16 ( LiveASM_CodeBuffer & Buffer, uint8_t Digit, LA_X86_64_R16_Indirect RMRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( Digit << 3 ) | _LA_X86_64_R16ToIndex3 ( static_cast <LA_X86_64_R16> ( RMRegister ) ) );
	
}


inline void _LA_X86_64_WriteModRM_Indirect_Digit_SIB ( LiveASM_CodeBuffer & Buffer, uint8_t Digit )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( Digit << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset8_Digit_SIB ( LiveASM_CodeBuffer & Buffer, uint8_t Digit )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( Digit << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset32_Digit_SIB ( LiveASM_CodeBuffer & Buffer, uint8_t Digit )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( Digit << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_REG_R64_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( _LA_X86_64_R64ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_REG_R32_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( _LA_X86_64_R32ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_REG_R16_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( _LA_X86_64_R16ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_REG_R8_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( _LA_X86_64_R8ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_REG_Segment_RM_Indirect_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_0 | ( _LA_X86_64_SegmentToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset8_REG_R64_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( _LA_X86_64_R64ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset8_REG_R32_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( _LA_X86_64_R32ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset8_REG_R16_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( _LA_X86_64_R16ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset8_REG_R8_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( _LA_X86_64_R8ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset8_REG_Segment_RM_Indirect_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_1 | ( _LA_X86_64_SegmentToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset32_REG_R64_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( _LA_X86_64_R64ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset32_REG_R32_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( _LA_X86_64_R32ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset32_REG_R16_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( _LA_X86_64_R16ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset32_REG_R8_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( _LA_X86_64_R8ToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteModRM_Indirect_Offset32_REG_Segment_RM_Indirect_SIB ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment REGRegister )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_MODRM_MOD_REGISTER_INDIRECT_2 | ( _LA_X86_64_SegmentToIndex3 ( REGRegister ) << 3 ) | 0x04 );
	
}

inline void _LA_X86_64_WriteSIB64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_SIBScale IndexScale, LA_X86_64_R64_SIBIndex IndexRegister, LA_X86_64_R64_SIBBase BaseRegister )
{
	
	Buffer.push_back ( ( _LA_X86_64_SIBScaleToIndex2 ( IndexScale ) << 6 ) | ( _LA_X86_64_R64ToIndex3 ( static_cast <LA_X86_64_R64> ( IndexRegister ) ) << 3 ) | _LA_X86_64_R64ToIndex3 ( static_cast <LA_X86_64_R64> ( BaseRegister ) ) );
	
}

inline void _LA_X86_64_WriteREX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_REXFlag Flags )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_REX_FIXED | ( ( ( Flags & kLA_X86_64_REXFlag_R ) != 0 ) ? X86_64_OPPREFIX_REX_R : 0 ) | ( ( ( Flags & kLA_X86_64_REXFlag_B ) != 0 ) ? X86_64_OPPREFIX_REX_B : 0 ) | ( ( ( Flags & kLA_X86_64_REXFlag_X ) != 0 ) ? X86_64_OPPREFIX_REX_X : 0 ) );
	
}

inline void _LA_X86_64_WriteREX_64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_REXFlag Flags )
{
	
	Buffer.push_back ( X86_64_OPPREFIX_REX_FIXED | X86_64_OPPREFIX_REX_W | ( ( ( Flags & kLA_X86_64_REXFlag_R ) != 0 ) ? X86_64_OPPREFIX_REX_R : 0 ) | ( ( ( Flags & kLA_X86_64_REXFlag_B ) != 0 ) ? X86_64_OPPREFIX_REX_B : 0 ) | ( ( ( Flags & kLA_X86_64_REXFlag_X ) != 0 ) ? X86_64_OPPREFIX_REX_X : 0 ) );
	
}
