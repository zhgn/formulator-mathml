

#if !defined( __HMATH_CMMCALC_CMMCALCERR__ )
#define __HMATH_CMMCALC_CMMCALCERR__

///////////////////////////////////////////////////////////////////////////////

enum CMMLErrorID
{
	CMMLError_NONE = 0,

	CMMLError_NoAST,
	CMMLError_NoVM,
	CMMLError_NotSupportedCurrently,
	CMMLError_IgnoringNode_Deprecated,
	CMMLError_IgnoringNode_WrongContainer,
	CMMLError_UnexpectedApplyOp,
	CMMLError_IgnoreExcessArgs,
	CMMLError_NotAFunction,
	CMMLError_ArgNumberMismatch,
	CMMLError_ArgNumberMismatch_No,
	CMMLError_UnknownSymbol,
	CMMLError_UnknownXmlTag,
	CMMLError_CNSyntax,
	CMMLError_UnknownConstant,
	CMMLError_CNSyntax_Type,
	CMMLError_EmptyCI,
	CMMLError_ConstructorItemsExpected,
	CMMLError_MatrixItemsExpected,
	CMMLError_MatrixSyntax,
	CMMLError_Internal_NoRecord,
	CMMLError_FunctionBodyExpected,
	CMMLError_SymbolAlreadyDefined,
	CMMLError_SymbolInitError,
	CMMLError_PiecewiseSyntax,
	CMMLError_PiecewiseSyntax_Piece2Arg,
	CMMLError_PiecewiseSyntax_Piece2Apply,
	CMMLError_Semantic,

	CMMLError_LAST
};

///////////////////////////////////////////////////////////////////////////////

#endif
