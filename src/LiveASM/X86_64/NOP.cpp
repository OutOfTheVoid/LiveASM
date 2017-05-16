#include <LiveASM/X86_64/Arch.h>
#include <LiveASM/X86_64/OpCodes.h>
#include <LiveASM/X86_64/OpUtil.h>

void LA_X86_64_Noop ( LiveASM_CodeBuffer & Buffer )
{
	
	Buffer.push_back ( X86_64_OP_NOP );
	
}
