#pragma once

#include "common.h"

#define nbRegFilter(name, base) class name : public base { public:	name (byte id) : base (id) { referance = this; }; };

namespace nebula {

	enum nbRegType {
		GP_8,
		GP_16,
		GP_32,
		GP_64,
	};

	class nbReg {
	protected:
		byte id;
		// For Using Dynamic Cast Without Using A Referance '&' or A Pointer '*'
		nbReg*		referance = nullptr;
	public:
		nbReg*		getRef() { return referance;			}
		byte		getId () { return (id & 0b111);			}
		byte		getW  () { return ((id & 0b1000) >> 3); }
		nbReg(byte id): id(id) {}
		virtual ~nbReg() = default;
	};

	nbRegFilter(nbRegFilterGp		, nbReg				)		// Accepts Every				General Purpose Register
	nbRegFilter(nbRegFilterSeg		, nbReg				)		// Accepts Segment				Registers
	nbRegFilter(nbRegFilterMM		, nbReg				)		// Accepts MMx					Registers
	nbRegFilter(nbRegFilterXMM		, nbReg				)		// Accepts Xmmx					Registers
	nbRegFilter(nbRegFilterCRx		, nbReg				)		// Accpets CRx					Registers
	nbRegFilter(nbRegFilterDRx		, nbReg				)		// Accepts DRx					Registers 
	nbRegFilter(nbRegFilterGp8		, nbRegFilterGp		)		// Accepts 8 bit				General Purpose Registers
	nbRegFilter(nbRegFilterGp136	, nbRegFilterGp		)		// Accepts 16, 32 and 64 bit	General Purpose Registers
	nbRegFilter(nbRegFilterGp16		, nbRegFilterGp136	)		// Accepts 16 bit				General Purpose Registers		
	nbRegFilter(nbRegFilterGp32		, nbRegFilterGp136	)		// Accepts 32 bit				General Purpose Registers
	nbRegFilter(nbRegFilterGp64		, nbRegFilterGp136	)		// Accepts 64 bit				General Purpose Registers

	
/* Intel Arch Registers */
	/* General Purpose Registers */																			/*		REX.R = 1  (for 64-bit mode only)                                                                   */
	nbRegFilterGp8		al  ( 0 ), cl  ( 1 ), dl  ( 2 ), bl  ( 3 ), ah  ( 4 ), ch  ( 5 ), dh  ( 6 ), bh  ( 7 ),		/**/	r8b ( 8 ), r9b ( 9 ), r10b ( 10 ), r11b ( 11 ), r12b ( 12 ), r13b ( 13 ), r14b ( 14 ), r15b ( 15 );
	nbRegFilterGp16		ax  ( 0 ), cx  ( 1 ), dx  ( 2 ), bx  ( 3 ), sp  ( 4 ), bp  ( 5 ), si  ( 6 ), di  ( 7 ),		/**/	r8w ( 8 ), r9w ( 9 ), r10w ( 10 ), r11w ( 11 ), r12w ( 12 ), r13w ( 13 ), r14w ( 14 ), r15w ( 15 );
	nbRegFilterGp32		eax ( 0 ), ecx ( 1 ), edx ( 2 ), ebx ( 3 ), esp ( 4 ), ebp ( 5 ), esi ( 6 ), edi ( 7 ),		/**/	r8d ( 8 ), r9d ( 9 ), r10d ( 10 ), r11d ( 11 ), r12d ( 12 ), r13d ( 13 ), r14d ( 14 ), r15d ( 15 );
	nbRegFilterGp64		rax ( 0 ), rcx ( 1 ), rdx ( 2 ), rbx ( 3 ), rsp ( 4 ), rbp ( 5 ), rsi ( 6 ), rdi ( 7 ),		/**/	r8  ( 8 ), r9  ( 9 ), r10  ( 10 ), r11  ( 11 ), r12  ( 12 ), r13  ( 13 ), r14  ( 14 ), r15  ( 15 );
	/* Segment	 Registers */																				/**/
	nbRegFilterSeg		es  ( 0 ), cs  ( 1 ), ss  ( 2 ), ds  ( 3 ), fs  ( 4 ), gs  ( 5 ); /*NO REG*/ /*NO REG*/		/**/	/* SAME */ /* SAME */ /* SAME */   /* SAME */   /* SAME */   /* SAME */   /* SAME */   /* SAME */ 
	/* MM & XMM	 Registers */																				/**/
	nbRegFilterMM		mm0 ( 0 ), mm1 ( 1 ), mm2 ( 2 ), mm3 ( 3 ), mm4 ( 4 ), mm5 ( 5 ), mm6 ( 6 ), mm7 ( 7 );		/**/	/* SAME */ /* SAME */ /* SAME */   /* SAME */   /* SAME */   /* SAME */   /* SAME */   /* SAME */ 
	nbRegFilterXMM		xmm0( 0 ), xmm1( 1 ), xmm2( 2 ), xmm3( 3 ), xmm4( 4 ), xmm5( 5 ), xmm6( 6 ), xmm7( 7 ),		/**/	xmm8( 8 ), xmm9( 9 ), xmm10( 10 ), xmm11( 11 ), xmm12( 12 ), xmm13( 13 ), xmm14( 14 ), xmm15( 15 );
	/* CRx & DRx Registers */																				/**/
	nbRegFilterCRx		cr0 ( 0 ), /*NO REG*/ cr2 ( 2 ), cr3 ( 3 ), cr4 ( 4 ), /*NO REG*/ /*NO REG*/ /*NO REG*/		/**/	cr8 ( 8 ); /*NO REG*/ /*NO REG*/   /*NO REG*/   /*NO REG*/   /*NO REG*/   /*NO REG*/   /*NO REG*/ 
	nbRegFilterDRx		dr0 ( 0 ), dr1 ( 1 ), dr2 ( 2 ), dr3 ( 3 ), dr4 ( 4 ), dr5 ( 5 ), dr6 ( 6 ), dr7 ( 7 );		/**/	/*NO REG*/ /*NO REG*/ /*NO REG*/   /*NO REG*/   /*NO REG*/   /*NO REG*/   /*NO REG*/   /*NO REG*/ 
}