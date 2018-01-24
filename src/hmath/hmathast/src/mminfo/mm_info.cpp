

#include "../type/typedsr.h"
#include "mm_info.h"

int CDsrMMPropertyTable[ DSRMM_LAST ][ DSR_HAVE_LAST ] =
{
//							HAVE_NONE	HAVE_VAR_DECL	HAVE_VAR_TYPE	HAVE_VECTOR	HAVE_EQUATION	HAVE_INEQUATION	HAVE_FUNCTION_E	HAVE_FUNCTION_I	HAVE_FUNCTION_P	HAVE_FUNCTION_D	HAVE_FRACTAL	HAVE_RANGE	HAVE_CYCLE	HAVE_SET
/* MM_NONE			*/ {	0,			0,				0,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			0		},
/* MM_SET			*/ {	0,			1,				0,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			1		},
/* MM_DIGRAPH		*/ {	0,			1,				0,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			1		},
/* MM_NET			*/ {	0,			1,				0,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			0		},
/* MM_BOOL_FUN		*/ {	0,			1,				0,				0,			0,				0,				1,				0,				0,				0,				0,				1,			1,			0		},
/* MM_R_BOOL_FUN	*/ {	0,			1,				0,				0,			0,				0,				1,				0,				0,				0,				0,				1,			1,			0		},
/* MM_DFA			*/ {	0,			1,				0,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			0		},
/* MM_CFG			*/ {	0,			1,				0,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			0		},
/* MM_PETRI_NET		*/ {	0,			1,				0,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			0		},
/* MM_NEURON_NET	*/ {	0,			1,				0,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			0		},
/* MM_NUMERY		*/ {	0,			1,				1,				0,			1,				0,				0,				0,				0,				0,				0,				0,			0,			0		},
/* MM_FUNCTION		*/ {	0,			1,				1,				0,			0,				0,				1,				1,				1,				1,				0,				1,			1,			0		},
/* MM_FRACTAL		*/ {	0,			1,				0,				0,			0,				0,				0,				0,				0,				0,				1,				1,			1,			0		},
/*MM_VECTOR_FUNCTION*/ {	0,			1,				1,				1,			0,				0,				1,				0,				0,				0,				0,				1,			1,			0		},
/* MM_GROUPS		*/ {	0,			1,				0,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			1		},
/* MM_POLYNOM		*/ {	0,			1,				1,				0,			0,				0,				0,				0,				0,				0,				0,				1,			1,			0		},
/* MM_RATIONAL		*/ {	0,			1,				1,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			0		},
/* MM_GALUA			*/ {	0,			1,				0,				0,			0,				0,				0,				0,				0,				0,				0,				0,			0,			0		},
/* MM_VECTOR		*/ {	0,			1,				1,				1,			0,				0,				0,				0,				0,				0,				0,				1,			1,			0		},
/* MM_SLAU			*/ {	0,			1,				1,				1,			1,				0,				0,				0,				0,				0,				0,				1,			1,			0		},
/* MM_SNAU			*/ {	0,			1,				1,				1,			1,				0,				1,				0,				0,				0,				0,				1,			1,			0		},
/* MM_ODE			*/ {	0,			1,				1,				1,			1,				0,				1,				0,				0,				0,				0,				1,			1,			0		},
/* MM_EXTREMUM		*/ {	0,			1,				1,				1,			1,				0,				1,				0,				0,				0,				0,				1,			1,			0		},
/* MM_PM			*/ {	0,			1,				0,				1,			0,				0,				0,				0,				0,				0,				0,				0,			0,			0		},
/* MM_TAU			*/ {	0,			1,				1,				1,			1,				0,				1,				0,				0,				0,				0,				1,			1,			0		}
};

enum CDsrDataTypes CDsrMMDefaultTypeTable[ DSRMM_LAST ] =
{
/* MM_NONE			*/ DSRDATA_TYPE_UNKNOWN,
/* MM_SET			*/ DSRDATA_TYPE_INTEGER,
/* MM_DIGRAPH		*/ DSRDATA_TYPE_INTEGER,
/* MM_NET			*/ DSRDATA_TYPE_INTEGER,
/* MM_BOOL_FUN		*/ DSRDATA_TYPE_INTEGER,
/* MM_R_BOOL_FUN	*/ DSRDATA_TYPE_INTEGER,
/* MM_DFA			*/ DSRDATA_TYPE_INTEGER,
/* MM_CFG			*/ DSRDATA_TYPE_INTEGER,
/* MM_PETRI_NET		*/ DSRDATA_TYPE_INTEGER,
/* MM_NEURON_NET	*/ DSRDATA_TYPE_INTEGER,
/* MM_NUMERY		*/ DSRDATA_TYPE_REAL,
/* MM_FUNCTION		*/ DSRDATA_TYPE_REAL,
/* MM_FRACTAL		*/ DSRDATA_TYPE_REAL,
/*MM_VECTOR_FUNCTION*/ DSRDATA_TYPE_REAL,
/* MM_GROUPS		*/ DSRDATA_TYPE_GROUP_STRING,
/* MM_POLYNOM		*/ DSRDATA_TYPE_REAL,
/* MM_RATIONAL		*/ DSRDATA_TYPE_REAL,
/* MM_GALUA			*/ DSRDATA_TYPE_REAL,
/* MM_VECTOR		*/ DSRDATA_TYPE_REAL,
/* MM_SLAU			*/ DSRDATA_TYPE_REAL,
/* MM_SNAU			*/ DSRDATA_TYPE_REAL,
/* MM_ODE			*/ DSRDATA_TYPE_REAL,
/* MM_EXTREMUM		*/ DSRDATA_TYPE_REAL,
/* MM_PM			*/ DSRDATA_TYPE_INTEGER,
/* MM_TAU			*/ DSRDATA_TYPE_REAL
};

enum CDsrDataTypes getCDsrMMDefaultType( enum CDsrMathModel mm_id, long mm_int )
{
	if( mm_int == -1 )
		return CDsrMMDefaultTypeTable[ mm_id ];
	else
	{
		switch( mm_id )
		{
		case DSRMM_SET:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_DIGRAPH:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_NET:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_BOOL_FUN:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_R_BOOL_FUN:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_DFA:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_CFG:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_PETRI_NET:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_NEURON_NET:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_NUMERY:
			switch( mm_int )
			{
			case INT_MM_ID_NUMERIC_NATURAL:
				return DSRDATA_TYPE_NATURAL;
			case INT_MM_ID_NUMERIC_INTEGER:
			case INT_MM_ID_NUMERIC_DIOFANT_1:
			case INT_MM_ID_NUMERIC_DIOFANT_2:
				return DSRDATA_TYPE_INTEGER;
			case INT_MM_ID_NUMERIC_RATIONAL:
				return DSRDATA_TYPE_RATIONAL;
			case INT_MM_ID_NUMERIC_REAL:
				return DSRDATA_TYPE_REAL;
			case INT_MM_ID_NUMERIC_COMPLEX:
				return DSRDATA_TYPE_COMPLEX;
			default:
				break;
			}
			break;
		case DSRMM_FUNCTION:
			switch( mm_int )
			{
			case INT_MM_ID_FUNCTION_DISCRETE_NR:
				return DSRDATA_TYPE_INTEGER;
			case INT_MM_ID_FUNCTION_DISCRETE_R:
				return DSRDATA_TYPE_INTEGER;
			case INT_MM_ID_FUNCTION_REAL_E:
				return DSRDATA_TYPE_REAL;
			case INT_MM_ID_FUNCTION_REAL_I:
				return DSRDATA_TYPE_REAL;
			case INT_MM_ID_FUNCTION_REAL_P:
				return DSRDATA_TYPE_REAL;
			default:
				break;
			}
			break;
		case DSRMM_FRACTAL:
			return DSRDATA_TYPE_REAL;
		case DSRMM_VECTOR_FUNCTION:
			return DSRDATA_TYPE_REAL;
		case DSRMM_GROUPS:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_POLYNOM:
			return DSRDATA_TYPE_REAL;
		case DSRMM_RATIONAL:
			return DSRDATA_TYPE_REAL;
		case DSRMM_GALUA:
			return DSRDATA_TYPE_REAL;
		case DSRMM_VECTOR:
			return DSRDATA_TYPE_REAL;
		case DSRMM_SLAU:
			return DSRDATA_TYPE_REAL;
		case DSRMM_SNAU:
			return DSRDATA_TYPE_REAL;
		case DSRMM_ODE:
			return DSRDATA_TYPE_REAL;
		case DSRMM_EXTREMUM:
			return DSRDATA_TYPE_REAL;
		case DSRMM_PM:
			return DSRDATA_TYPE_INTEGER;
		case DSRMM_TAU:
			return DSRDATA_TYPE_REAL;
		default:
			break;
		}
	}
	return DSRDATA_TYPE_REAL;
}   

///////////////////////////////////////////////////////////////////////////////

long getCDsrMMProperty( enum CDsrMathModel mm_id, enum CDsrMMProperty mmprop_id )
{
	return CDsrMMPropertyTable[ mm_id ][ mmprop_id ];
}

int isCDsrAGWCongruence( int agw )
{
	return (agw >= AGW_CONGRUENCE_1 && agw <= AGW_CONGRUENCE_6) || 
			agw == AGW_CONGRUENCE_11;
}

///////////////////////////////////////////////////////////////////////////////
   
