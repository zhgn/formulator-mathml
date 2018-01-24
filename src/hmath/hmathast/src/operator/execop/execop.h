

#if !defined( __PARSEDSR_OPERATOR_EXECOP_EXECOP_H__ )
#define __PARSEDSR_OPERATOR_EXECOP_EXECOP_H__

#include "../operator.h"

///////////////////////////////////////////////////////////////////////////////

class UniWord;
class CParseDsrSymbolTable;
class CDSR_VMEval;
struct MMD_Address;

typedef long (*CDsrOperationCall)( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg );

__HMATHLNGDLL__ extern CDsrOperationCall CDsrOperationCallArray[ FUNCTION_STD_LAST ];
__HMATHLNGDLL__ long __ml_OperationCall( CDSR_VMEval& vm, MMD_Address& addr, UniWord *arg );

///////////////////////////////////////////////////////////////////////////////

#endif
