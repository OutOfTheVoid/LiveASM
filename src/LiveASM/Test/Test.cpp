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
	
}

