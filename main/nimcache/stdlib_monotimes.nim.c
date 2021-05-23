/* Generated by Nim Compiler v1.4.6 */
/*   (c) 2020 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 32

/* section: NIM_merge_HEADERS */

#include "nimbase.h"
#include <string.h>
#include <time.h>
#include <sys/types.h>
#undef LANGUAGE_C
#undef MIPSEB
#undef MIPSEL
#undef PPC
#undef R3000
#undef R4000
#undef i386
#undef linux
#undef mips
#undef near
#undef far
#undef powerpc
#undef unix

/* section: NIM_merge_FRAME_DEFINES */
  #  define nimfr_(proc, file) \
      TFrame FR_; \
      FR_.procname = proc; FR_.filename = file; FR_.line = 0; FR_.len = 0; nimFrame(&FR_);

  #  define nimfrs_(proc, file, slots, length) \
      struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename; NI len; VarSlot s[slots];} FR_; \
      FR_.procname = proc; FR_.filename = file; FR_.line = 0; FR_.len = length; nimFrame((TFrame*)&FR_);

  #  define nimln_(n, file) \
      FR_.line = n; FR_.filename = file;
  
/* section: NIM_merge_FORWARD_TYPES */
typedef struct tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w;
typedef struct tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw;

/* section: NIM_merge_TYPES */
struct tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w {NI64 ticks;
};
struct tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw {NI64 seconds;
NI nanosecond;
};

/* section: NIM_merge_PROC_HEADERS */
static N_INLINE(void, nimZeroMem)(void* p, NI size);
static N_INLINE(void, nimSetMem__JE6t4x7Z3v2iVz27Nx0MRAmemory)(void* a, int v, NI size);
static N_INLINE(NIM_BOOL*, nimErrorFlag)(void);
N_LIB_PRIVATE N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__mMRdr4sgmnykA9aWeM9aDZlw)(void);
static N_INLINE(void, popFrame)(void);
N_LIB_PRIVATE N_NIMCALL(tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw, initDuration__wcR3zetvspAUsyuvWZ07Xg)(NI64 nanoseconds, NI64 microseconds, NI64 milliseconds, NI64 seconds, NI64 minutes, NI64 hours, NI64 days, NI64 weeks);

/* section: NIM_merge_VARS */
extern NIM_THREADVAR NIM_BOOL nimInErrorMode__759bT87luu8XGcbkw13FUjA;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;

/* section: NIM_merge_PROCS */

#line 22 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/memory.nim"
static N_INLINE(void, nimSetMem__JE6t4x7Z3v2iVz27Nx0MRAmemory)(void* a, int v, NI size) {	void* T1_;
#line 24 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/memory.nim"

#line 24 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/memory.nim"
	T1_ = (void*)0;	T1_ = memset(a, v, ((size_t) (size)));}

#line 414 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
static N_INLINE(NIM_BOOL*, nimErrorFlag)(void) {	NIM_BOOL* result;	result = (NIM_BOOL*)0;
#line 415 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
	result = (&nimInErrorMode__759bT87luu8XGcbkw13FUjA);	return result;}

#line 33 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/memory.nim"
static N_INLINE(void, nimZeroMem)(void* p, NI size) {NIM_BOOL* nimErr_;{nimErr_ = nimErrorFlag();
#line 34 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/memory.nim"

#line 34 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/memory.nim"
	nimSetMem__JE6t4x7Z3v2iVz27Nx0MRAmemory(p, ((int) 0), size);
	if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;	}BeforeRet_: ;
}

#line 544 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
static N_INLINE(void, nimFrame)(TFrame* s) {
#line 545 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
	{
#line 545 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
		if (!(framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw == ((TFrame*) NIM_NIL))) goto LA3_;

#line 546 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
		(*s).calldepth = ((NI16) 0);	}
	goto LA1_;
	LA3_: ;
	{
#line 549 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"

#line 549 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
		(*s).calldepth = (NI16)((*framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw).calldepth + ((NI16) 1));	}
	LA1_: ;

#line 551 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
	(*s).prev = framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
#line 552 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
	framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw = s;
#line 553 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
	{
#line 553 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
		if (!((*s).calldepth == ((NI16) 2000))) goto LA8_;

#line 553 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"

#line 553 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
		callDepthLimitReached__mMRdr4sgmnykA9aWeM9aDZlw();
	}
	LA8_: ;
}

#line 86 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
static N_INLINE(void, popFrame)(void) {
#line 87 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/system/excpt.nim"
	framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw = (*framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw).prev;}

#line 86 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
N_LIB_PRIVATE N_NIMCALL(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w, getMonoTime__QkEugs2Q2iFK9b83sl2B6wA)(void) {	tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w result;	struct timespec ts;	int T1_;	NI64 TM__IP4V1hRabVpf8OnX9bWuPxw_2;	NI64 TM__IP4V1hRabVpf8OnX9bWuPxw_3;	nimfr_("getMonoTime", "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");{	nimZeroMem((void*)(&result), sizeof(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w));	nimZeroMem((void*)(&ts), sizeof(struct timespec));
#line 104 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	nimln_(104, "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");
#line 104 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"

#line 104 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	T1_ = (int)0;	T1_ = clock_gettime(((clockid_t) (CLOCK_MONOTONIC)), (&ts));	(void)(T1_);

#line 105 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	nimln_(105, "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");	nimZeroMem((void*)(&result), sizeof(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w));
#line 105 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"

#line 105 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	if (nimMulInt64(((NI64) (ts.tv_sec)), IL64(1000000000), &TM__IP4V1hRabVpf8OnX9bWuPxw_2)) { raiseOverflow(); goto BeforeRet_;};	if (nimAddInt64((NI64)(TM__IP4V1hRabVpf8OnX9bWuPxw_2), ((NI64) (ts.tv_nsec)), &TM__IP4V1hRabVpf8OnX9bWuPxw_3)) { raiseOverflow(); goto BeforeRet_;};	result.ticks = (NI64)(TM__IP4V1hRabVpf8OnX9bWuPxw_3);	}BeforeRet_: ;
	popFrame();	return result;}

#line 140 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, lteq___3KIZNy1Wl5YmzvX5mBokLA)(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w a, tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w b) {	NIM_BOOL result;	nimfr_("<=", "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");	result = (NIM_BOOL)0;
#line 141 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	nimln_(141, "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");
#line 142 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	nimln_(142, "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");	result = (a.ticks <= b.ticks);	popFrame();	return result;}

#line 144 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, eqeq___3KIZNy1Wl5YmzvX5mBokLA_2)(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w a, tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w b) {	NIM_BOOL result;	nimfr_("==", "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");	result = (NIM_BOOL)0;
#line 145 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	nimln_(145, "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");
#line 146 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	nimln_(146, "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");	result = (a.ticks == b.ticks);	popFrame();	return result;}

#line 136 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, lt___3KIZNy1Wl5YmzvX5mBokLA_3)(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w a, tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w b) {	NIM_BOOL result;	nimfr_("<", "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");	result = (NIM_BOOL)0;
#line 137 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	nimln_(137, "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");
#line 138 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	nimln_(138, "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");	result = (a.ticks < b.ticks);	popFrame();	return result;}

#line 124 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
N_LIB_PRIVATE N_NIMCALL(tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw, minus___p9cBm7joedh4BwcboQ3HMVQ)(tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w a, tyObject_MonoTime__FEvFMlkqJiSSGVO6HgTv8w b) {	tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw result;	NI64 TM__IP4V1hRabVpf8OnX9bWuPxw_4;NIM_BOOL* nimErr_;	nimfr_("-", "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");{nimErr_ = nimErrorFlag();	nimZeroMem((void*)(&result), sizeof(tyObject_Duration__lj9ar6Co3fgk6NgGnVaNpJw));
#line 125 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	nimln_(125, "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");
#line 126 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	nimln_(126, "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim");
#line 126 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	if (nimSubInt64(a.ticks, b.ticks, &TM__IP4V1hRabVpf8OnX9bWuPxw_4)) { raiseOverflow(); goto BeforeRet_;};
#line 126 "/home/elcritch/.asdf/installs/nim/1.4.6/lib/std/monotimes.nim"
	result = initDuration__wcR3zetvspAUsyuvWZ07Xg((NI64)(TM__IP4V1hRabVpf8OnX9bWuPxw_4), IL64(0), IL64(0), IL64(0), IL64(0), IL64(0), IL64(0), IL64(0));	if (NIM_UNLIKELY(*nimErr_)) goto BeforeRet_;	}BeforeRet_: ;
	popFrame();	return result;}