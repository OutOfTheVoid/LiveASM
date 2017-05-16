#ifndef LIVEASM_X86_64_ARCH_H
#define LIVEASM_X86_64_ARCH_H

#include <LiveASM/LiveASM.h>

enum LA_X86_64_R64_Indirect
{
	
	kLA_X86_64_R64_Indirect_RAX = 0,
	kLA_X86_64_R64_Indirect_RCX = 1,
	kLA_X86_64_R64_Indirect_RDX = 2,
	kLA_X86_64_R64_Indirect_RBX = 3,
	kLA_X86_64_R64_Indirect_RSI = 6,
	kLA_X86_64_R64_Indirect_RDI = 7,
	kLA_X86_64_R64_Indirect_R8 = 8,
	kLA_X86_64_R64_Indirect_R9 = 9,
	kLA_X86_64_R64_Indirect_R10 = 10,
	kLA_X86_64_R64_Indirect_R11 = 11,
	kLA_X86_64_R64_Indirect_R12 = 12,
	kLA_X86_64_R64_Indirect_R13 = 13,
	kLA_X86_64_R64_Indirect_R14 = 14,
	kLA_X86_64_R64_Indirect_R15 = 15,
	
};

enum LA_X86_64_R64_SIBIndex
{
	
	kLA_X86_64_R64_SIBIndex_ZERO = 4,
	
	kLA_X86_64_R64_SIBIndex_RAX = kLA_X86_64_R64_Indirect_RAX,
	kLA_X86_64_R64_SIBIndex_RCX = kLA_X86_64_R64_Indirect_RCX,
	kLA_X86_64_R64_SIBIndex_RDX = kLA_X86_64_R64_Indirect_RDX,
	kLA_X86_64_R64_SIBIndex_RBX = kLA_X86_64_R64_Indirect_RBX,
	kLA_X86_64_R64_SIBIndex_RBP = 5,
	kLA_X86_64_R64_SIBIndex_RSI = kLA_X86_64_R64_Indirect_RSI,
	kLA_X86_64_R64_SIBIndex_RDI = kLA_X86_64_R64_Indirect_RDI,
	kLA_X86_64_R64_SIBIndex_R8 = kLA_X86_64_R64_Indirect_R8,
	kLA_X86_64_R64_SIBIndex_R9 = kLA_X86_64_R64_Indirect_R9,
	kLA_X86_64_R64_SIBIndex_R10 = kLA_X86_64_R64_Indirect_R10,
	kLA_X86_64_R64_SIBIndex_R11 = kLA_X86_64_R64_Indirect_R11,
	kLA_X86_64_R64_SIBIndex_R13 = kLA_X86_64_R64_Indirect_R13,
	kLA_X86_64_R64_SIBIndex_R14 = kLA_X86_64_R64_Indirect_R14,
	kLA_X86_64_R64_SIBIndex_R15 = kLA_X86_64_R64_Indirect_R15,
	
};

enum LA_X86_64_R64_SIBBase
{
	
	kLA_X86_64_R64_SIBBase_ZERO = 5,
	
	kLA_X86_64_R64_SIBBase_RAX = kLA_X86_64_R64_Indirect_RAX,
	kLA_X86_64_R64_SIBBase_RCX = kLA_X86_64_R64_Indirect_RCX,
	kLA_X86_64_R64_SIBBase_RDX = kLA_X86_64_R64_Indirect_RDX,
	kLA_X86_64_R64_SIBBase_RBX = kLA_X86_64_R64_Indirect_RBX,
	kLA_X86_64_R64_SIBBase_RSP = 4,
	kLA_X86_64_R64_SIBBase_RSI = kLA_X86_64_R64_Indirect_RSI,
	kLA_X86_64_R64_SIBBase_RDI = kLA_X86_64_R64_Indirect_RDI,
	kLA_X86_64_R64_SIBBase_R8 = kLA_X86_64_R64_Indirect_R8,
	kLA_X86_64_R64_SIBBase_R9 = kLA_X86_64_R64_Indirect_R9,
	kLA_X86_64_R64_SIBBase_R10 = kLA_X86_64_R64_Indirect_R10,
	kLA_X86_64_R64_SIBBase_R11 = kLA_X86_64_R64_Indirect_R11,
	kLA_X86_64_R64_SIBBase_R12 = kLA_X86_64_R64_Indirect_R12,
	kLA_X86_64_R64_SIBBase_R14 = kLA_X86_64_R64_Indirect_R14,
	kLA_X86_64_R64_SIBBase_R15 = kLA_X86_64_R64_Indirect_R15,
	
};

enum LA_X86_64_SIBScale
{
	
	kLA_X86_64_SIBScale_1,
	kLA_X86_64_SIBScale_2,
	kLA_X86_64_SIBScale_4,
	kLA_X86_64_SIBScale_8,
	
};

enum LA_X86_64_R64_Old
{
	
	kLA_X86_64_R64_Old_RAX = kLA_X86_64_R64_SIBIndex_RAX,
	kLA_X86_64_R64_Old_RCX = kLA_X86_64_R64_SIBIndex_RCX,
	kLA_X86_64_R64_Old_RDX = kLA_X86_64_R64_SIBIndex_RDX,
	kLA_X86_64_R64_Old_RBX = kLA_X86_64_R64_SIBIndex_RBX,
	kLA_X86_64_R64_Old_RSP = kLA_X86_64_R64_SIBBase_RSP,
	kLA_X86_64_R64_Old_RBP = kLA_X86_64_R64_SIBIndex_RBP,
	kLA_X86_64_R64_Old_RSI = kLA_X86_64_R64_SIBIndex_RSI,
	kLA_X86_64_R64_Old_RDI = kLA_X86_64_R64_SIBIndex_RDI,
	
};

enum LA_X86_64_R64
{
	
	kLA_X86_64_R64_RAX = kLA_X86_64_R64_Old_RAX,
	kLA_X86_64_R64_RCX = kLA_X86_64_R64_Old_RCX,
	kLA_X86_64_R64_RDX = kLA_X86_64_R64_Old_RDX,
	kLA_X86_64_R64_RBX = kLA_X86_64_R64_Old_RBX,
	kLA_X86_64_R64_RSP = kLA_X86_64_R64_Old_RSP,
	kLA_X86_64_R64_RBP = kLA_X86_64_R64_Old_RBP,
	kLA_X86_64_R64_RSI = kLA_X86_64_R64_Old_RSI,
	kLA_X86_64_R64_RDI = kLA_X86_64_R64_Old_RDI,
	kLA_X86_64_R64_R8 = kLA_X86_64_R64_SIBIndex_R8,
	kLA_X86_64_R64_R9 = kLA_X86_64_R64_SIBIndex_R9,
	kLA_X86_64_R64_R10 = kLA_X86_64_R64_SIBIndex_R10,
	kLA_X86_64_R64_R11 = kLA_X86_64_R64_SIBIndex_R11,
	kLA_X86_64_R64_R12 = kLA_X86_64_R64_SIBBase_R12,
	kLA_X86_64_R64_R13 = kLA_X86_64_R64_SIBIndex_R13,
	kLA_X86_64_R64_R14 = kLA_X86_64_R64_SIBIndex_R14,
	kLA_X86_64_R64_R15 = kLA_X86_64_R64_SIBIndex_R15,
	
};

enum LA_X86_64_R32_Indirect
{
	
	kLA_X86_64_R32_Indirect_EAX = 0,
	kLA_X86_64_R32_Indirect_ECX = 1,
	kLA_X86_64_R32_Indirect_EDX = 2,
	kLA_X86_64_R32_Indirect_EBX = 3,
	kLA_X86_64_R32_Indirect_ESI = 6,
	kLA_X86_64_R32_Indirect_EDI = 7,
	
};

enum LA_X86_64_R32
{
	
	kLA_X86_64_R32_EAX = kLA_X86_64_R32_Indirect_EAX,
	kLA_X86_64_R32_ECX = kLA_X86_64_R32_Indirect_ECX,
	kLA_X86_64_R32_EDX = kLA_X86_64_R32_Indirect_EDX,
	kLA_X86_64_R32_EBX = kLA_X86_64_R32_Indirect_EBX,
	kLA_X86_64_R32_ESP = 4,
	kLA_X86_64_R32_EBP = 5,
	kLA_X86_64_R32_ESI = kLA_X86_64_R32_Indirect_ESI,
	kLA_X86_64_R32_EDI = kLA_X86_64_R32_Indirect_EDI,
	
};

enum LA_X86_64_R16_Indirect
{
	
	kLA_X86_64_R16_Indirect_AX = 0,
	kLA_X86_64_R16_Indirect_CX = 1,
	kLA_X86_64_R16_Indirect_DX = 2,
	kLA_X86_64_R16_Indirect_BX = 3,
	kLA_X86_64_R16_Indirect_SI = 6,
	kLA_X86_64_R16_Indirect_DI = 7,
	
};

enum LA_X86_64_R16
{
	
	kLA_X86_64_R16_AX = kLA_X86_64_R16_Indirect_AX,
	kLA_X86_64_R16_CX = kLA_X86_64_R16_Indirect_CX,
	kLA_X86_64_R16_DX = kLA_X86_64_R16_Indirect_DX,
	kLA_X86_64_R16_BX = kLA_X86_64_R16_Indirect_BX,
	kLA_X86_64_R16_SP = 4,
	kLA_X86_64_R16_BP = 5,
	kLA_X86_64_R16_SI = kLA_X86_64_R16_Indirect_SI,
	kLA_X86_64_R16_DI = kLA_X86_64_R16_Indirect_DI,
	
};

enum LA_X86_64_R8_Low
{
	
	kLA_X86_64_R8_Low_AL = 0,
	kLA_X86_64_R8_Low_CL = 1,
	kLA_X86_64_R8_Low_DL = 2,
	kLA_X86_64_R8_Low_BL = 3,
	
};

enum LA_X86_64_Segment
{
	
	kLA_X86_64_Segment_FS = 4,
	kLA_X86_64_Segment_GS = 5,
	
};

enum LA_X86_64_R8
{
	
	kLA_X86_64_R8_AL = kLA_X86_64_R8_Low_AL,
	kLA_X86_64_R8_BL = kLA_X86_64_R8_Low_BL,
	kLA_X86_64_R8_CL = kLA_X86_64_R8_Low_CL,
	kLA_X86_64_R8_DL = kLA_X86_64_R8_Low_DL,
	kLA_X86_64_R8_AH = 4,
	kLA_X86_64_R8_CH = 5,
	kLA_X86_64_R8_DH = 6,
	kLA_X86_64_R8_BH = 7,
	
};

enum LA_X86_64_OpSize
{
	
	kLA_X86_64_OpSize_64,
	kLA_X86_64_OpSize_32,
	kLA_X86_64_OpSize_16,
	kLA_X86_64_OpSize_8,
	
};

typedef struct LA_X86_64_SIB_R64_Struct
{
	
	LA_X86_64_SIB_R64_Struct ():
		IndexScale ( kLA_X86_64_SIBScale_1 ),
		IndexRegister ( kLA_X86_64_R64_SIBIndex_ZERO ),
		BaseRegister ( kLA_X86_64_R64_SIBBase_ZERO )
	{
	}
	
	LA_X86_64_SIB_R64_Struct ( LA_X86_64_SIBScale IndexScale, LA_X86_64_R64_SIBIndex IndexRegister, LA_X86_64_R64_SIBBase BaseRegister ):
		IndexScale ( IndexScale ),
		IndexRegister ( IndexRegister ),
		BaseRegister ( BaseRegister )
	{
	}
	
	LA_X86_64_SIBScale IndexScale;
	LA_X86_64_R64_SIBIndex IndexRegister;
	
	LA_X86_64_R64_SIBBase BaseRegister;
	
} LA_X86_64_SIB_R64;

typedef struct LA_X86_64_Operand_Struct
{
	
	enum _E_AsR64Direct { AS_R64_DIRECT };
	enum _E_AsR32Direct { AS_R32_DIRECT };
	enum _E_AsR16Direct { AS_R16_DIRECT };
	enum _E_AsR8Direct { AS_R8_DIRECT };
	
	enum _E_AsR64Indirect { AS_R64_INDIRECT };
	enum _E_AsR64IndirectOffsetSIMM8 { AS_R64_INDIRECT_OFFSET_SIMM8 };
	enum _E_AsR64IndirectOffsetSIMM32 { AS_R64_INDIRECT_OFFSET_SIMM32 };
	
	enum _E_AsSegment { AS_SEGMENT };
	
	enum _E_AsSIMM8 { AS_SIMM8 };
	enum _E_AsSIMM16 { AS_SIMM16 };
	enum _E_AsSIMM32 { AS_SIMM32 };
	
	enum _E_AsIMM64 { AS_IMM64 };
	enum _E_AsIMM32 { AS_IMM32 };
	enum _E_AsIMM16 { AS_IMM16 };
	enum _E_AsIMM8 { AS_IMM8 };
	
	enum _E_AsIMM64Offset { AS_IMM64_OFFSET };
	
	enum _E_AsSIB { AS_SIB };
	enum _E_AsSIBOffsetSIMM8 { AS_SIB_OFFSET_SIMM8 };
	enum _E_AsSIBOffsetSIMM32  { AS_SIB_OFFSET_SIMM32 };
	
	enum Type
	{
		
		kType_R64_Direct,
		kType_R32_Direct,
		kType_R16_Direct,
		kType_R8_Direct,
		kType_R64_Indirect,
		kType_R64_Indirect_Offset_SIMM8,
		kType_R64_Indirect_Offset_SIMM32,
		kType_Segment,
		kType_SIMM8,
		kType_SIMM16,
		kType_SIMM32,
		kType_IMM8,
		kType_IMM16,
		kType_IMM32,
		kType_IMM64,
		kType_IMM64_Offset,
		kType_SIB,
		kType_SIB_Offset_SIMM8,
		kType_SIB_Offset_SIMM32,
		
	};
	
	inline LA_X86_64_Operand_Struct ( _E_AsR64Direct AS_R64_DIRECT, LA_X86_64_R64 Register ):
		OperandType ( kType_R64_Direct ),
		Value ( Register )
	{
		
		(void) AS_R64_DIRECT;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsR32Direct AS_R32_DIRECT, LA_X86_64_R32 Register ):
		OperandType ( kType_R32_Direct ),
		Value ( Register )
	{
		
		(void) AS_R32_DIRECT;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsR16Direct AS_R16_DIRECT, LA_X86_64_R16 Register ):
		OperandType ( kType_R16_Direct ),
		Value ( Register )
	{
		
		(void) AS_R16_DIRECT;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsR8Direct AS_R8_DIRECT, LA_X86_64_R8 Register ):
		OperandType ( kType_R8_Direct ),
		Value ( Register )
	{
		
		(void) AS_R8_DIRECT;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsR64Indirect AS_R64_INDIRECT, LA_X86_64_R64_Indirect IndirectRegister ):
		OperandType ( kType_R64_Indirect ),
		Value ( IndirectRegister )
	{
		
		(void) AS_R64_INDIRECT;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsR64IndirectOffsetSIMM8 AS_R64_INDIRECT_OFFSET_SIMM8, LA_X86_64_R64_Indirect IndirectRegister, int8_t Offset ):
		OperandType ( kType_R64_Indirect_Offset_SIMM8 ),
		Value ( IndirectR64 ( IndirectRegister, Offset ) )
	{
		
		(void) AS_R64_INDIRECT_OFFSET_SIMM8;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsR64IndirectOffsetSIMM32 AS_R64_INDIRECT_OFFSET_SIMM32, LA_X86_64_R64_Indirect IndirectRegister, int32_t Offset ):
		OperandType ( kType_R64_Indirect_Offset_SIMM32 ),
		Value ( IndirectR64 ( IndirectRegister, Offset ) )
	{
		
		(void) AS_R64_INDIRECT_OFFSET_SIMM32;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsSegment AS_SEGMENT, LA_X86_64_Segment Segment ):
		OperandType ( kType_Segment ),
		Value ( Segment )
	{
		
		(void) AS_SEGMENT;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsSIMM8 AS_SIMM8, int8_t SIMM8 ):
		OperandType ( kType_SIMM8 ),
		Value { SIMM8 }
	{
		
		(void) AS_SIMM8;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsSIMM16 AS_SIMM16, int32_t SIMM16 ):
		OperandType ( kType_SIMM16 ),
		Value { SIMM16 }
	{
		
		(void) AS_SIMM16;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsSIMM32 AS_SIMM32, int32_t SIMM32 ):
		OperandType ( kType_SIMM32 ),
		Value { SIMM32 }
	{
		
		(void) AS_SIMM32;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsIMM64 AS_IMM64, uint64_t IMM64 ):
		OperandType ( kType_IMM64 ),
		Value { IMM64 }
	{
		
		(void) AS_IMM64;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsIMM64Offset AS_IMM64_OFFSET, uint64_t IMM64 ):
		OperandType ( kType_IMM64_Offset ),
		Value { IMM64 }
	{
		
		(void) AS_IMM64_OFFSET;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsIMM32 AS_IMM32, uint32_t IMM32 ):
		OperandType ( kType_IMM32 ),
		Value { IMM32 }
	{
		
		(void) AS_IMM32;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsIMM16 AS_IMM16, uint32_t IMM16 ):
		OperandType ( kType_IMM16 ),
		Value { IMM16 }
	{
		
		(void) AS_IMM16;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsIMM8 AS_IMM8, int8_t IMM8 ):
		OperandType ( kType_IMM8 ),
		Value { IMM8 }
	{
		
		(void) AS_IMM8;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsSIB AS_SIB, const LA_X86_64_SIB_R64 & SIB ):
		OperandType ( kType_SIB ),
		Value { SIBData_Struct ( SIB ) }
	{
		
		(void) AS_SIB;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsSIBOffsetSIMM8 AS_SIB_OFFSET_SIMM8, const LA_X86_64_SIB_R64 & SIB, int8_t Offset ):
		OperandType ( kType_SIB_Offset_SIMM8 ),
		Value { SIBData_Struct { SIB, Offset } }
	{
		
		(void) AS_SIB_OFFSET_SIMM8;
		
	}
	
	inline LA_X86_64_Operand_Struct ( _E_AsSIBOffsetSIMM32 AS_SIB_OFFSET_SIMM32, const LA_X86_64_SIB_R64 & SIB, int32_t Offset ):
		OperandType ( kType_SIB_Offset_SIMM32 ),
		Value { SIBData_Struct { SIB, Offset } }
	{
		
		(void) AS_SIB_OFFSET_SIMM32;
		
	}
	
	typedef struct SIBData_Struct
	{
		
		inline explicit SIBData_Struct ( const LA_X86_64_SIB_R64 & SIB ):
			SIB ( SIB ),
			Offset { 0 }
		{
		}
		
		inline explicit SIBData_Struct ( const LA_X86_64_SIB_R64 & SIB, int32_t Offset ):
			SIB ( SIB ),
			Offset { Offset }
		{
		}
		
		inline explicit SIBData_Struct ( const LA_X86_64_SIB_R64 & SIB, int8_t Offset ):
			SIB ( SIB ),
			Offset { Offset }
		{
		}
		
		inline SIBData_Struct ()
		{
		}
		
		inline SIBData_Struct ( const struct SIBData_Struct & CopyFrom ):
			SIB ( CopyFrom.SIB )
		{
			
			Offset.SIMM32 = CopyFrom.Offset.SIMM32;
			
		}
		
		LA_X86_64_SIB_R64 SIB;
		
		union Offset_Union
		{
			
			inline explicit Offset_Union ( int32_t Offset ): SIMM32 ( Offset ) {};
			inline explicit Offset_Union ( int8_t Offset ): SIMM8 ( Offset ) {};
			inline Offset_Union (): SIMM32 ( 0 ) {};
			
			int32_t SIMM32;
			int8_t SIMM8;
			
		} Offset;
		
	} SIBData;
	
	typedef struct IndirectR64_Struct
	{
		
		inline explicit IndirectR64_Struct ( LA_X86_64_R64_Indirect IndirectR64 ):
			R64 ( IndirectR64 ),
			Offset ( 0 )
		{
		}
		
		inline explicit IndirectR64_Struct ( LA_X86_64_R64_Indirect IndirectR64, int32_t Offset ):
			R64 ( IndirectR64 ),
			Offset ( Offset )
		{
		}
		
		inline explicit IndirectR64_Struct ( LA_X86_64_R64_Indirect IndirectR64, int8_t Offset ):
			R64 ( IndirectR64 ),
			Offset ( Offset )
		{
		}
		
		LA_X86_64_R64_Indirect R64;
		
		union Offset_Union
		{
			
			inline explicit Offset_Union ( int8_t SIMM8 ): SIMM8 ( SIMM8 ) {};
			inline explicit Offset_Union ( int32_t SIMM32 ): SIMM32 ( SIMM32 ) {};
			
			int8_t SIMM8;
			int32_t SIMM32;
			
		} Offset;
		
	} IndirectR64;
	
	Type OperandType;
	
	union Value_Union
	{
		
		inline explicit Value_Union ( LA_X86_64_R64 R64 ): R64 ( R64 ) {};
		inline explicit Value_Union ( IndirectR64 Indirect ): Indirect ( Indirect ) {};
		inline explicit Value_Union ( LA_X86_64_R32 R32 ): R32 ( R32 ) {};
		inline explicit Value_Union ( LA_X86_64_R16 R16 ): R16 ( R16 ) {};
		inline explicit Value_Union ( LA_X86_64_R8 R8 ): R8 ( R8 ) {};
		
		inline explicit Value_Union ( LA_X86_64_Segment Segment ): Segment ( Segment ) {};
		
		inline explicit Value_Union ( uint64_t IMM64 ): IMM64 ( IMM64 ) {};
		inline explicit Value_Union ( uint32_t IMM32 ): IMM32 ( IMM32 ) {};
		inline explicit Value_Union ( uint16_t IMM16 ): IMM16 ( IMM16 ) {};
		inline explicit Value_Union ( uint8_t IMM8 ): IMM8 ( IMM8 ) {};
		
		inline explicit Value_Union ( int32_t SIMM32 ): SIMM32 ( SIMM32 ) {};
		inline explicit Value_Union ( int16_t SIMM16 ): SIMM16 ( SIMM16 ) {};
		inline explicit Value_Union ( int8_t SIMM8 ): SIMM8 ( SIMM8 ) {};
		
		inline explicit Value_Union ( const SIBData & SIB ): SIB ( SIB ) {};
		
		LA_X86_64_R64 R64;
		LA_X86_64_R32 R32;
		LA_X86_64_R16 R16;
		LA_X86_64_R8 R8;
		
		IndirectR64 Indirect;
		
		LA_X86_64_Segment Segment;
		
		uint64_t IMM64;
		uint32_t IMM32;
		uint32_t IMM16;
		uint32_t IMM8;
		
		int32_t SIMM32;
		int32_t SIMM16;
		int8_t SIMM8;
		
		SIBData SIB;
		
	} Value;
	
} LA_X86_64_Operand;

enum AutoOpResult
{
	
	kAutoOpResult_Success,
	kAutoOpResult_IllegalOperation,
	kAutoOpResult_Success_EquivalentModified,
	
};

//======================================[PUSH]======================================//

void LA_X86_64_Push_SX_SIMM8 ( LiveASM_CodeBuffer & Buffer, int8_t SIMM8 );
void LA_X86_64_Push_SX_SIMM16 ( LiveASM_CodeBuffer & Buffer, int16_t SIMM16 );
void LA_X86_64_Push_SX_SIMM32 ( LiveASM_CodeBuffer & Buffer, int32_t SIMM32 );
void LA_X86_64_Push_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Register );
void LA_X86_64_Push_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Register );
void LA_X86_64_Push_FS ( LiveASM_CodeBuffer & Buffer );
void LA_X86_64_Push_GS ( LiveASM_CodeBuffer & Buffer );
void LA_X86_64_Push_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Register );
void LA_X86_64_Push_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Register, int8_t Offset );
void LA_X86_64_Push_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Register, int32_t Offset );
void LA_X86_64_Push_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data );
void LA_X86_64_Push_Indirect_SIB_R64_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data, int8_t Offset );
void LA_X86_64_Push_Indirect_SIB_R64_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data, int32_t Offset );

AutoOpResult LA_X86_64_Push_Auto ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_Operand & Source );

//======================================[POP]======================================//

void LA_X86_64_Pop_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Register );
void LA_X86_64_Pop_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Register );
void LA_X86_64_Pop_FS ( LiveASM_CodeBuffer & Buffer );
void LA_X86_64_Pop_GS ( LiveASM_CodeBuffer & Buffer );
void LA_X86_64_Pop_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Register );
void LA_X86_64_Pop_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Register, int8_t Offset );
void LA_X86_64_Pop_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Register, int32_t Offset );
void LA_X86_64_Pop_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data );
void LA_X86_64_Pop_Indirect_SIB_R64_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data, int8_t Offset );
void LA_X86_64_Pop_Indirect_SIB_R64_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & SIB_Data, int32_t Offset );

AutoOpResult LA_X86_64_Pop_Auto ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_Operand & Destination );

//======================================[MOV]======================================//

void LA_X86_64_Move_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64 Source );
void LA_X86_64_Move_R32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R32 Source );
void LA_X86_64_Move_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R16 Source );
void LA_X86_64_Move_R8_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, LA_X86_64_R8 Source );
void LA_X86_64_Move_Indirect_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect SourceIndirect );
void LA_X86_64_Move_Indirect_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect SourceIndirect );
void LA_X86_64_Move_Indirect_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect SourceIndirect );
void LA_X86_64_Move_Indirect_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, LA_X86_64_R64_Indirect SourceIndirect );
void LA_X86_64_Move_Indirect_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect SourceIndirect, int8_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect SourceIndirect, int8_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect SourceIndirect, int8_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM8_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, LA_X86_64_R64_Indirect SourceIndirect, int8_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect SourceIndirect, int32_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect SourceIndirect, int32_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM32_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect SourceIndirect, int32_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM32_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, LA_X86_64_R64_Indirect SourceIndirect, int32_t Offset );
void LA_X86_64_Move_Indirect_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB );
void LA_X86_64_Move_Indirect_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB );
void LA_X86_64_Move_Indirect_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB );
void LA_X86_64_Move_Indirect_SIB_R64_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB );
void LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int8_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int8_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int8_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int8_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int32_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int32_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int32_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int32_t Offset );
void LA_X86_64_Move_R64_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect , LA_X86_64_R64 Source );
void LA_X86_64_Move_R32_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, LA_X86_64_R32 Source );
void LA_X86_64_Move_R16_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, LA_X86_64_R16 Source );
void LA_X86_64_Move_R8_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, LA_X86_64_R8 Source );
void LA_X86_64_Move_R64_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int8_t Offset, LA_X86_64_R16 Source );
void LA_X86_64_Move_R32_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int8_t Offset, LA_X86_64_R32 Source );
void LA_X86_64_Move_R16_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int8_t Offset, LA_X86_64_R16 Source );
void LA_X86_64_Move_R8_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int8_t Offset, LA_X86_64_R8 Source );
void LA_X86_64_Move_R64_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int32_t Offset, LA_X86_64_R64 Source );
void LA_X86_64_Move_R32_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int32_t Offset, LA_X86_64_R32 Source );
void LA_X86_64_Move_R16_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int32_t Offset, LA_X86_64_R16 Source );
void LA_X86_64_Move_R8_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect DestinationIndirect, int32_t Offset, LA_X86_64_R8 Source );
void LA_X86_64_Move_R64_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, LA_X86_64_R64 Source );
void LA_X86_64_Move_R32_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, LA_X86_64_R32 Source );
void LA_X86_64_Move_R16_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, LA_X86_64_R16 Source );
void LA_X86_64_Move_R8_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, LA_X86_64_R8 Source );
void LA_X86_64_Move_R64_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, LA_X86_64_R64 Source );
void LA_X86_64_Move_R32_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, LA_X86_64_R32 Source );
void LA_X86_64_Move_R16_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, LA_X86_64_R16 Source );
void LA_X86_64_Move_R8_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, LA_X86_64_R8 Source );
void LA_X86_64_Move_R64_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, LA_X86_64_R64 Source );
void LA_X86_64_Move_R32_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, LA_X86_64_R32 Source );
void LA_X86_64_Move_R16_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, LA_X86_64_R16 Source );
void LA_X86_64_Move_R8_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, LA_X86_64_R8 Source );
void LA_X86_64_Move_R64_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R64 Source );
void LA_X86_64_Move_R32_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R32 Source );
void LA_X86_64_Move_R16_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R16 Source );
void LA_X86_64_Move_Indirect_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_Move_Indirect_OffsetSIMM8_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM32_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_Move_Indirect_SIB_R64_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB );
void LA_X86_64_Move_Indirect_OffsetSIMM8_SIB_R64_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int8_t Offset );
void LA_X86_64_Move_Indirect_OffsetSIMM32_SIB_R64_To_Segment ( LiveASM_CodeBuffer & Buffer, LA_X86_64_Segment Destination, const LA_X86_64_SIB_R64 & SourceIndirectSIB, int32_t Offset );
void LA_X86_64_Move_Segment_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_Segment Source );
void LA_X86_64_Move_Segment_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_Segment Source );
void LA_X86_64_Move_Segment_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_Segment Source );
void LA_X86_64_Move_Segment_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, LA_X86_64_Segment Source );
void LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, LA_X86_64_Segment Source );
void LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, LA_X86_64_Segment Source );
void LA_X86_64_Move_Segment_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, LA_X86_64_Segment Source );
void LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int8_t Offset, LA_X86_64_Segment Source );
void LA_X86_64_Move_Segment_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & DestinationIndirectSIB, int32_t Offset, LA_X86_64_Segment Source );
void LA_X86_64_Move_Offset_IMM64_To_RAX ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset );
void LA_X86_64_Move_Offset_IMM64_To_EAX ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset );
void LA_X86_64_Move_Offset_IMM64_To_AX ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset );
void LA_X86_64_Move_Offset_IMM64_To_AL ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset );
void LA_X86_64_Move_RAX_To_Offset_IMM64 ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset );
void LA_X86_64_Move_EAX_To_Offset_IMM64 ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset );
void LA_X86_64_Move_AX_To_Offset_IMM64 ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset );
void LA_X86_64_Move_AL_To_Offset_IMM64 ( LiveASM_CodeBuffer & Buffer, uint64_t SourceOffset );
void LA_X86_64_Move_IMM64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Register, uint64_t IMM64 );
void LA_X86_64_Move_SIMM32_SX_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Register, int32_t SIMM32 );
void LA_X86_64_Move_IMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Register, uint32_t IMM32 );
void LA_X86_64_Move_IMM16_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Register, uint16_t IMM16 );
void LA_X86_64_Move_IMM8_To_R8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Register, uint8_t IMM8 );
void LA_X86_64_Move_SIMM32_SX64_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t SIMM32 );
void LA_X86_64_Move_IMM32_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, uint32_t IMM32 );
void LA_X86_64_Move_IMM16_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, uint16_t IMM16 );
void LA_X86_64_Move_IMM8_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, uint8_t IMM8 );
void LA_X86_64_Move_SIMM32_SX64_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, int32_t SIMM32 );
void LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, uint32_t IMM32 );
void LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, uint16_t IMM16 );
void LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, uint8_t IMM8 );
void LA_X86_64_Move_SIMM32_SX64_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, int32_t SIMM32 );
void LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, uint32_t IMM32 );
void LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, uint16_t IMM16 );
void LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, uint8_t IMM8 );
void LA_X86_64_Move_SIMM32_SX64_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t SIMM32 );
void LA_X86_64_Move_IMM32_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, uint32_t IMM32 );
void LA_X86_64_Move_IMM16_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, uint16_t IMM16 );
void LA_X86_64_Move_IMM8_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, uint8_t IMM8 );
void LA_X86_64_Move_SIMM32_SX64_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int8_t Offset, int32_t SIMM32 );
void LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int8_t Offset, uint32_t IMM32 );
void LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int8_t Offset, uint16_t IMM16 );
void LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int8_t Offset, uint8_t IMM8 );
void LA_X86_64_Move_SIMM32_SX64_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t Offset, int32_t SIMM32 );
void LA_X86_64_Move_IMM32_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t Offset, uint32_t IMM32 );
void LA_X86_64_Move_IMM16_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t Offset, uint16_t IMM16 );
void LA_X86_64_Move_IMM8_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t Offset, uint8_t IMM8 );

AutoOpResult LA_X86_64_Move_Auto ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_Operand & Destination, const LA_X86_64_Operand & Source );

//======================================[MOVBE]======================================//

void LA_X86_64_MoveBigEndian_R64_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, LA_X86_64_R64 Source );
void LA_X86_64_MoveBigEndian_R32_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, LA_X86_64_R32 Source );
void LA_X86_64_MoveBigEndian_R16_To_Indirect ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, LA_X86_64_R16 Source );
void LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, LA_X86_64_R64 Source );
void LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, LA_X86_64_R32 Source );
void LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM8 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int8_t Offset, LA_X86_64_R16 Source );
void LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, LA_X86_64_R64 Source );
void LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, LA_X86_64_R32 Source );
void LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Destination, int32_t Offset, LA_X86_64_R16 Source );
void LA_X86_64_MoveBigEndian_R64_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, LA_X86_64_R64 Source );
void LA_X86_64_MoveBigEndian_R32_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, LA_X86_64_R32 Source );
void LA_X86_64_MoveBigEndian_R16_To_Indirect_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, LA_X86_64_R16 Source );
void LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int8_t Offset, LA_X86_64_R64 Source );
void LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int8_t Offset, LA_X86_64_R32 Source );
void LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM8_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int8_t Offset, LA_X86_64_R16 Source );
void LA_X86_64_MoveBigEndian_R64_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t Offset, LA_X86_64_R64 Source );
void LA_X86_64_MoveBigEndian_R32_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t Offset, LA_X86_64_R32 Source );
void LA_X86_64_MoveBigEndian_R16_To_Indirect_OffsetSIMM32_SIB_R64 ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Destination, int32_t Offset, LA_X86_64_R16 Source );

void LA_X86_64_MoveBigEndian_Indirect_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveBigEndian_Indirect_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveBigEndian_Indirect_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveBigEndian_Indirect_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveBigEndian_Indirect_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM8_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveBigEndian_Indirect_OffsetSIMM32_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );

AutoOpResult LA_X86_64_MoveBigEndian_Auto ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_Operand & Destination, const LA_X86_64_Operand & Source );

//======================================[MOVS]=====================================//

void LA_X86_64_MoveString_64 ( LiveASM_CodeBuffer & Buffer );
void LA_X86_64_MoveString_32 ( LiveASM_CodeBuffer & Buffer );
void LA_X86_64_MoveString_16 ( LiveASM_CodeBuffer & Buffer );
void LA_X86_64_MoveString_8 ( LiveASM_CodeBuffer & Buffer );

AutoOpResult LA_X86_64_MoveString_Auto ( LiveASM_CodeBuffer & Buffer, LA_X86_64_OpSize Size );

//=====================================[MOVSX]=====================================//

void LA_X86_64_MoveSignExtended_R8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R8 Source );
void LA_X86_64_MoveSignExtended_R8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R8 Source );
void LA_X86_64_MoveSignExtended_R8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R8 Source );
void LA_X86_64_MoveSignExtended_R16_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R16 Source );
void LA_X86_64_MoveSignExtended_R16_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R16 Source );
void LA_X86_64_MoveSignExtended_R32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R32 Source );
void LA_X86_64_MoveSignExtended_Indirect8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveSignExtended_Indirect8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveSignExtended_Indirect8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveSignExtended_Indirect16_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveSignExtended_Indirect16_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveSignExtended_Indirect32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveSignExtended_Indirect8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveSignExtended_Indirect8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveSignExtended_Indirect16_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveSignExtended_Indirect16_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveSignExtended_Indirect32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect16_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveSignExtended_Indirect32_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );

AutoOpResult LA_X86_64_MoveSignExtended_Auto ( LiveASM_CodeBuffer & Buffer, LA_X86_64_OpSize SourceSize, const LA_X86_64_Operand & Destination, const LA_X86_64_Operand & Source );

//=====================================[MOVZX]=====================================//

void LA_X86_64_MoveZeroExtended_R8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R8 Source );
void LA_X86_64_MoveZeroExtended_R8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R8 Source );
void LA_X86_64_MoveZeroExtended_R8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R8 Source );
void LA_X86_64_MoveZeroExtended_R16_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R16 Source );
void LA_X86_64_MoveZeroExtended_R16_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R16 Source );
void LA_X86_64_MoveZeroExtended_Indirect8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveZeroExtended_Indirect8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveZeroExtended_Indirect8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveZeroExtended_Indirect16_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveZeroExtended_Indirect16_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM8_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect16_OffsetSIMM8_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect16_OffsetSIMM8_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int8_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM32_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect16_OffsetSIMM32_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect16_OffsetSIMM32_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, LA_X86_64_R64_Indirect Source, int32_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveZeroExtended_Indirect8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveZeroExtended_Indirect8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveZeroExtended_Indirect16_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveZeroExtended_Indirect16_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect16_OffsetSIMM8_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect16_OffsetSIMM8_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int8_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R16 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect8_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect16_OffsetSIMM32_SIB_R64_To_R32 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );
void LA_X86_64_MoveZeroExtended_Indirect16_OffsetSIMM32_SIB_R64_To_R64 ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Destination, const LA_X86_64_SIB_R64 & Source, int32_t Offset );

AutoOpResult LA_X86_64_MoveZeroExtended_Auto ( LiveASM_CodeBuffer & Buffer, LA_X86_64_OpSize SourceSize, const LA_X86_64_Operand & Destination, const LA_X86_64_Operand & Source );

//======================================[MUL]======================================//

void LA_X86_64_Multiply_AL_By_R8_To_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R8 Multiplier );
void LA_X86_64_Multiply_AX_By_R16_To_DX_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R16 Multiplier );
void LA_X86_64_Multiply_EAX_By_R32_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R32 Multiplier );
void LA_X86_64_Multiply_RAX_By_R64_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64 Multiplier );
void LA_X86_64_Multiply_AL_By_Indirect_To_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier );
void LA_X86_64_Multiply_AX_By_Indirect_To_DX_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier );
void LA_X86_64_Multiply_EAX_By_Indirect_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier );
void LA_X86_64_Multiply_RAX_By_Indirect_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier );
void LA_X86_64_Multiply_AL_By_Indirect_OffsetSIMM8_To_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int8_t Offset );
void LA_X86_64_Multiply_AX_By_Indirect_OffsetSIMM8_To_DX_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int8_t Offset );
void LA_X86_64_Multiply_EAX_By_Indirect_OffsetSIMM8_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int8_t Offset );
void LA_X86_64_Multiply_RAX_By_Indirect_OffsetSIMM8_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int8_t Offset );
void LA_X86_64_Multiply_AL_By_Indirect_OffsetSIMM32_To_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int32_t Offset );
void LA_X86_64_Multiply_AX_By_Indirect_OffsetSIMM32_To_DX_AX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int32_t Offset );
void LA_X86_64_Multiply_EAX_By_Indirect_OffsetSIMM32_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int32_t Offset );
void LA_X86_64_Multiply_RAX_By_Indirect_OffsetSIMM32_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, LA_X86_64_R64_Indirect Multiplier, int32_t Offset );
void LA_X86_64_Multiply_AL_By_Indirect_SIB_R64_To_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier );
void LA_X86_64_Multiply_AX_By_Indirect_SIB_R64_To_DX_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier );
void LA_X86_64_Multiply_EAX_By_Indirect_SIB_R64_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier );
void LA_X86_64_Multiply_RAX_By_Indirect_SIB_R64_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier );
void LA_X86_64_Multiply_AL_By_Indirect_OffsetSIMM8_SIB_R64_To_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int8_t Offset );
void LA_X86_64_Multiply_AX_By_Indirect_OffsetSIMM8_SIB_R64_To_DX_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int8_t Offset );
void LA_X86_64_Multiply_EAX_By_Indirect_OffsetSIMM8_SIB_R64_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int8_t Offset );
void LA_X86_64_Multiply_RAX_By_Indirect_OffsetSIMM8_SIB_R64_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int8_t Offset );
void LA_X86_64_Multiply_AL_By_Indirect_OffsetSIMM32_SIB_R64_To_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int32_t Offset );
void LA_X86_64_Multiply_AX_By_Indirect_OffsetSIMM32_SIB_R64_To_DX_AX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int32_t Offset );
void LA_X86_64_Multiply_EAX_By_Indirect_OffsetSIMM32_SIB_R64_To_EDX_EAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int32_t Offset );
void LA_X86_64_Multiply_RAX_By_Indirect_OffsetSIMM32_SIB_R64_To_RDX_RAX ( LiveASM_CodeBuffer & Buffer, const LA_X86_64_SIB_R64 & Multiplier, int32_t Offset );

//======================================[RET]======================================//

void LA_X86_64_NearReturn ( LiveASM_CodeBuffer & Buffer );
void LA_X86_64_NearReturn_PopIMM16 ( LiveASM_CodeBuffer & Buffer, uint16_t IMM16 );

AutoOpResult LA_X86_64_NearReturn_Auto ( LiveASM_CodeBuffer & Buffer, uint16_t PopByteCount );

//======================================[NOP]======================================//

void LA_X86_64_Noop ( LiveASM_CodeBuffer & Buffer );


#endif
