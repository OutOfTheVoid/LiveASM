#include <LiveASM/Test/Test.h>
#include <LiveASM/X86_64/Arch.h>

void LiveASM_FullTest ()
{
	
	// PUSH tests
	
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIMM8, - 20 ) ), ARLIT ( { 0x6a, 0xec } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIMM16, - 0x2000 ) ), ARLIT ( { 0x66, 0x68, 0x00, 0xE0  } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIMM32, - 0x2000 ) ), ARLIT ( { 0x68, 0x00, 0xE0, 0xFF, 0xFF } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_DIRECT, kLA_X86_64_R64_RCX ) ), ARLIT ( { 0x51 } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R16_DIRECT, kLA_X86_64_R16_DX ) ), ARLIT ( { 0x66, 0x52 } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SEGMENT, kLA_X86_64_Segment_FS ) ), ARLIT ( { 0x0F, 0xA0 } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SEGMENT, kLA_X86_64_Segment_GS ) ), ARLIT ( { 0x0F, 0xA8 } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT, kLA_X86_64_R64_Indirect_RAX ) ), ARLIT ( { 0xFF, 0x30 } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM8, kLA_X86_64_R64_Indirect_RAX, 40 ) ), ARLIT ( { 0xFF, 0x70, 0x28 } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM32, kLA_X86_64_R64_Indirect_RCX, 400 ) ), ARLIT ( { 0xFF, 0xB1, 0x90, 0x01, 0x00, 0x00 } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_2, kLA_X86_64_R64_SIBIndex_R8, kLA_X86_64_R64_SIBBase_R9 ) ) ), ARLIT ( { 0x43, 0xFF, 0x34, 0x41 } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM8, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_2, kLA_X86_64_R64_SIBIndex_R9, kLA_X86_64_R64_SIBBase_R10 ), 12 ) ), ARLIT ( { 0x43, 0xFF, 0x74, 0x4A, 0x0C } ) );
	ASSERT_OPCODE ( LA_X86_64_Push_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM32, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_2, kLA_X86_64_R64_SIBIndex_R8, kLA_X86_64_R64_SIBBase_R9 ), 12000 ) ), ARLIT ( { 0x43, 0xFF, 0xB4, 0x41, 0xE0, 0x2E, 0x00, 0x00 } ) );
	
	// POP tests
	
	ASSERT_OPCODE ( LA_X86_64_Pop_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_DIRECT, kLA_X86_64_R64_R12 ) ), ARLIT ( { 0x41, 0x5C } ) );
	ASSERT_OPCODE ( LA_X86_64_Pop_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R16_DIRECT, kLA_X86_64_R16_BX ) ), ARLIT ( { 0x66, 0x5B } ) );
	ASSERT_OPCODE ( LA_X86_64_Pop_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SEGMENT, kLA_X86_64_Segment_FS ) ), ARLIT ( { 0x0F, 0xA1 } ) );
	ASSERT_OPCODE ( LA_X86_64_Pop_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SEGMENT, kLA_X86_64_Segment_GS ) ), ARLIT ( { 0x0F, 0xA9 } ) );
	ASSERT_OPCODE ( LA_X86_64_Pop_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT, kLA_X86_64_R64_Indirect_RBX ) ), ARLIT ( { 0x8F, 0x03 } ) );
	ASSERT_OPCODE ( LA_X86_64_Pop_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM8, kLA_X86_64_R64_Indirect_R11, 13 ) ), ARLIT ( { 0x41, 0x8F, 0x43, 0x0D } ) );
	ASSERT_OPCODE ( LA_X86_64_Pop_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM32, kLA_X86_64_R64_Indirect_R13, 5846 ) ), ARLIT ( { 0x41, 0x8F, 0x85, 0xD6, 0x16, 0x00, 0x00 } ) );
	ASSERT_OPCODE ( LA_X86_64_Pop_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_4, kLA_X86_64_R64_SIBIndex_RAX, kLA_X86_64_R64_SIBBase_RCX ) ) ), ARLIT ( { 0x8F, 0x04, 0x81 } ) );
	ASSERT_OPCODE ( LA_X86_64_Pop_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM8, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_8, kLA_X86_64_R64_SIBIndex_RDX, kLA_X86_64_R64_SIBBase_RBX ), 12 ) ), ARLIT ( { 0x8F, 0x44, 0xD3, 0x0C } ) );
	ASSERT_OPCODE ( LA_X86_64_Pop_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM32, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_1, kLA_X86_64_R64_SIBIndex_R13, kLA_X86_64_R64_SIBBase_R12 ), 12000 ) ), ARLIT ( { 0x43, 0x8F, 0x84, 0x2C, 0xE0, 0x2E, 0x00, 0x00 } ) );
	
	// TODO: MOV tests
	
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_DIRECT, kLA_X86_64_R64_RAX ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_DIRECT, kLA_X86_64_R64_R9 ) ), ARLIT ( { 0x4C, 0x89, 0xC8 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R32_DIRECT, kLA_X86_64_R32_ESI ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R32_DIRECT, kLA_X86_64_R32_EAX ) ), ARLIT ( { 0x89, 0xC6 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R16_DIRECT, kLA_X86_64_R16_DI ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R16_DIRECT, kLA_X86_64_R16_CX ) ), ARLIT ( { 0x66, 0x89, 0xCF } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R8_DIRECT, kLA_X86_64_R8_AL ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R8_DIRECT, kLA_X86_64_R8_BL ) ), ARLIT ( { 0x88, 0xD8 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT, kLA_X86_64_R64_Indirect_RAX ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_DIRECT, kLA_X86_64_R64_R9 ) ), ARLIT ( { 0x4C, 0x89, 0x08 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT, kLA_X86_64_R64_Indirect_RBX ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R32_DIRECT, kLA_X86_64_R32_EAX ) ), ARLIT ( { 0x89, 0x03 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT, kLA_X86_64_R64_Indirect_RCX ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R16_DIRECT, kLA_X86_64_R16_CX ) ), ARLIT ( { 0x66, 0x89, 0x09 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT, kLA_X86_64_R64_Indirect_RDX ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R8_DIRECT, kLA_X86_64_R8_BL ) ), ARLIT ( { 0x88, 0x1A } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM8, kLA_X86_64_R64_Indirect_RAX, 13 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_DIRECT, kLA_X86_64_R64_R9 ) ), ARLIT ( { 0x4C, 0x89, 0x48, 0x0D } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM8, kLA_X86_64_R64_Indirect_RBX, 14 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R32_DIRECT, kLA_X86_64_R32_EAX ) ), ARLIT ( { 0x89, 0x43, 0x0E } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM8, kLA_X86_64_R64_Indirect_RCX, 15 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R16_DIRECT, kLA_X86_64_R16_CX ) ), ARLIT ( { 0x66, 0x89, 0x49, 0x0F } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM8, kLA_X86_64_R64_Indirect_RDX, 16 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R8_DIRECT, kLA_X86_64_R8_BL ) ), ARLIT ( { 0x88, 0x5A, 0x10 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM32, kLA_X86_64_R64_Indirect_RAX, 1300 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_DIRECT, kLA_X86_64_R64_R9 ) ), ARLIT ( { 0x4C, 0x89, 0x88, 0x14, 0x05, 0x00, 0x00 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM32, kLA_X86_64_R64_Indirect_RBX, 1400 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R32_DIRECT, kLA_X86_64_R32_EAX ) ), ARLIT ( { 0x89, 0x83, 0x78, 0x05, 0x00, 0x00 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM32, kLA_X86_64_R64_Indirect_RCX, 1500 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R16_DIRECT, kLA_X86_64_R16_CX ) ), ARLIT ( { 0x66, 0x89, 0x89, 0xDC, 0x05, 0x00, 0x00 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_INDIRECT_OFFSET_SIMM32, kLA_X86_64_R64_Indirect_RDX, 1600 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R8_DIRECT, kLA_X86_64_R8_BL ) ), ARLIT ( { 0x88, 0x9A, 0x40, 0x06, 0x00, 0x00 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_2, kLA_X86_64_R64_SIBIndex_R8, kLA_X86_64_R64_SIBBase_RCX ) ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_DIRECT, kLA_X86_64_R64_R9 ) ), ARLIT ( { 0x4E, 0x89, 0x0C, 0x41 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_8, kLA_X86_64_R64_SIBIndex_RAX, kLA_X86_64_R64_SIBBase_R8 ) ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R32_DIRECT, kLA_X86_64_R32_EAX ) ), ARLIT ( { 0x41, 0x89, 0x04, 0xC0 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_4, kLA_X86_64_R64_SIBIndex_R12, kLA_X86_64_R64_SIBBase_RCX ) ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R16_DIRECT, kLA_X86_64_R16_CX ) ), ARLIT ( { 0x66, 0x42, 0x89, 0x0C, 0xA1 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_2, kLA_X86_64_R64_SIBIndex_RAX, kLA_X86_64_R64_SIBBase_R15 ) ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R8_DIRECT, kLA_X86_64_R8_BL ) ), ARLIT ( { 0x41, 0x88, 0x1C, 0x47 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM8, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_2, kLA_X86_64_R64_SIBIndex_R8, kLA_X86_64_R64_SIBBase_RCX ), 10 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_DIRECT, kLA_X86_64_R64_R9 ) ), ARLIT ( { 0x4E, 0x89, 0x4C, 0x41, 0x0A } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM8, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_8, kLA_X86_64_R64_SIBIndex_RAX, kLA_X86_64_R64_SIBBase_R8 ), 11 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R32_DIRECT, kLA_X86_64_R32_EAX ) ), ARLIT ( { 0x41, 0x89, 0x44, 0xC0, 0x0B } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM8, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_4, kLA_X86_64_R64_SIBIndex_R12, kLA_X86_64_R64_SIBBase_RCX ), 12 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R16_DIRECT, kLA_X86_64_R16_CX ) ), ARLIT ( { 0x66, 0x42, 0x89, 0x4C, 0xA1, 0x0C } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM8, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_2, kLA_X86_64_R64_SIBIndex_RAX, kLA_X86_64_R64_SIBBase_R15 ), 13 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R8_DIRECT, kLA_X86_64_R8_BL ) ), ARLIT ( { 0x41, 0x88, 0x5C, 0x47, 0x0D } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM32, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_2, kLA_X86_64_R64_SIBIndex_R8, kLA_X86_64_R64_SIBBase_RCX ), 0xFF00 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R64_DIRECT, kLA_X86_64_R64_R9 ) ), ARLIT ( { 0x4E, 0x89, 0x8C, 0x41, 0x00, 0xFF, 0x00, 0x00 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM32, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_8, kLA_X86_64_R64_SIBIndex_RAX, kLA_X86_64_R64_SIBBase_R8 ), 0xFF00 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R32_DIRECT, kLA_X86_64_R32_EAX ) ), ARLIT ( { 0x41, 0x89, 0x84, 0xC0, 0x00, 0xFF, 0x00, 0x00 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM32, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_4, kLA_X86_64_R64_SIBIndex_R12, kLA_X86_64_R64_SIBBase_RCX ), 0xFF00 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R16_DIRECT, kLA_X86_64_R16_CX ) ), ARLIT ( { 0x66, 0x42, 0x89, 0x8C, 0xA1, 0x00, 0xFF, 0x00, 0x00 } ) );
	ASSERT_OPCODE ( LA_X86_64_Move_Auto ( Buffer, LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_SIB_OFFSET_SIMM32, LA_X86_64_SIB_R64 ( kLA_X86_64_SIBScale_2, kLA_X86_64_R64_SIBIndex_RAX, kLA_X86_64_R64_SIBBase_R15 ), 0xFF00 ), LA_X86_64_Operand ( LA_X86_64_Operand_Struct :: AS_R8_DIRECT, kLA_X86_64_R8_BL ) ), ARLIT ( { 0x41, 0x88, 0x9C, 0x47, 0x00, 0xFF, 0x00, 0x00 } ) );
	
}

