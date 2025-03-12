#include "recompiler/context.h"

const std::unordered_set<std::string> N64Recomp::reimplemented_funcs {
    // OS initialize functions
    "__osInitialize_common",
    "osInitialize",
    "osGetMemSize",
    // Audio interface functions
    "osAiGetLength",
    "osAiGetStatus",
    "osAiSetFrequency",
    "osAiSetNextBuffer",
    // Video interface functions
    "osViSetXScale",
    "osViSetYScale",
    "osCreateViManager",
    "osViBlack",
    "osViSetSpecialFeatures",
    "osViGetCurrentFramebuffer",
    "osViGetNextFramebuffer",
    "osViSwapBuffer",
    "osViSetMode",
    "osViSetEvent",
    // RDP functions
    "osDpSetNextBuffer",
    // RSP functions
    "osSpTaskLoad",
    "osSpTaskStartGo",
    "osSpTaskYield",
    "osSpTaskYielded",
    "__osSpSetPc",
    // Controller functions
    "osContInit",
    "osContStartReadData",
    "osContGetReadData",
    "osContStartQuery",
    "osContGetQuery",
    "osContSetCh",
    // EEPROM functions
    "osEepromProbe",
    "osEepromWrite",
    "osEepromLongWrite",
    "osEepromRead",
    "osEepromLongRead",
    // Rumble functions
    "__osMotorAccess",
    "osMotorInit",
    "osMotorStart",
    "osMotorStop",
    // PFS functions
    "osPfsInitPak",
    "osPfsFreeBlocks",
    "osPfsAllocateFile",
    "osPfsDeleteFile",
    "osPfsFileState",
    "osPfsFindFile",
    "osPfsReadWriteFile",
    // Parallel interface (cartridge, DMA, etc.) functions
    "osCartRomInit",
    "osCreatePiManager",
    "osPiStartDma",
    "osEPiStartDma",
    "osPiGetStatus",
    "osEPiRawStartDma",
    "osEPiReadIo",
    // Flash saving functions
    "osFlashInit",
    "osFlashReadStatus",
    "osFlashReadId",
    "osFlashClearStatus",
    "osFlashAllErase",
    "osFlashAllEraseThrough",
    "osFlashSectorErase",
    "osFlashSectorEraseThrough",
    "osFlashCheckEraseEnd",
    "osFlashWriteBuffer",
    "osFlashWriteArray",
    "osFlashReadArray",
    "osFlashChange",
    // Threading functions
    "osCreateThread",
    "osStartThread",
    "osStopThread",
    "osDestroyThread",
    "osSetThreadPri",
    "osGetThreadPri",
    "osGetThreadId",
    // Message Queue functions
    "osCreateMesgQueue",
    "osRecvMesg",
    "osSendMesg",
    "osJamMesg",
    "osSetEventMesg",
    // Timer functions
    "osGetTime",
    "osSetTimer",
    "osStopTimer",
    // Voice functions
    "osVoiceSetWord",
    "osVoiceCheckWord",
    "osVoiceStopReadData",
    "osVoiceInit",
    "osVoiceMaskDictionary",
    "osVoiceStartReadData",
    "osVoiceControlGain",
    "osVoiceGetReadData",
    "osVoiceClearDictionary",
    // interrupt functions
    "osSetIntMask",
    "__osDisableInt",
    "__osRestoreInt",
    // TLB functions
    "osVirtualToPhysical",
    // Coprocessor 0/1 functions
    "osGetCount",
    "__osSetFpcCsr",
    // Cache funcs
    "osInvalDCache",
    "osInvalICache",
    "osWritebackDCache",
    "osWritebackDCacheAll",
    // Debug functions
    "is_proutSyncPrintf",
    "__checkHardware_msp",
    "__checkHardware_kmc",
    "__checkHardware_isv",
    "__osInitialize_msp",
    "__osInitialize_kmc",
    "__osInitialize_isv",
    "__osRdbSend",
    // ido math routines
    "__ull_div",
    "__ll_div",
    "__ll_mul",
    "__ull_rem",
    "__ull_to_d",
    "__ull_to_f",
};

const std::unordered_set<std::string> N64Recomp::ignored_funcs{
    // OS initialize functions
    "__createSpeedParam",
    "__osInitialize_common",
    "osInitialize",
    "osGetMemSize",
    // Audio interface functions
    "osAiGetLength",
    "osAiGetStatus",
    "osAiSetFrequency",
    "osAiSetNextBuffer",
    "__osAiDeviceBusy",
    // Video interface functions
    "osViBlack",
    "osViFade",
    "osViGetCurrentField",
    "osViGetCurrentFramebuffer",
    "osViGetCurrentLine",
    "osViGetCurrentMode",
    "osViGetNextFramebuffer",
    "osViGetStatus",
    "osViRepeatLine",
    "osViSetEvent",
    "osViSetMode",
    "osViSetSpecialFeatures",
    "osViSetXScale",
    "osViSetYScale",
    "osViSwapBuffer",
    "osCreateViManager",
    "viMgrMain",
    "__osViInit",
    "__osViSwapContext",
    "__osViGetCurrentContext",
    // RDP functions
    "osDpGetCounters",
    "osDpSetStatus",
    "osDpGetStatus",
    "osDpSetNextBuffer",
    "__osDpDeviceBusy",
    // RSP functions
    "osSpTaskLoad",
    "osSpTaskStartGo",
    "osSpTaskYield",
    "osSpTaskYielded",
    "__osSpDeviceBusy",
    "__osSpGetStatus",
    "__osSpRawStartDma",
    "__osSpRawReadIo",
    "__osSpRawWriteIo",
    "__osSpSetPc",
    "__osSpSetStatus",
    // Controller functions
    "osContGetQuery",
    "osContGetReadData",
    "osContInit",
    "osContReset",
    "osContSetCh",
    "osContStartQuery",
    "osContStartReadData",
    "__osContAddressCrc",
    "__osContDataCrc",
    "__osContGetInitData",
    "__osContRamRead",
    "__osContRamWrite",
    "__osContChannelReset",
    // EEPROM functions
    "osEepromLongRead",
    "osEepromLongWrite",
    "osEepromProbe",
    "osEepromRead",
    "osEepromWrite",
    "__osEepStatus",
    // Rumble functions
    "osMotorInit",
    "osMotorStart",
    "osMotorStop",
    "__osMotorAccess",
    "_MakeMotorData",
    // Pack functions
    "__osCheckId",
    "__osCheckPackId",
    "__osGetId",
    "__osPfsRWInode",
    "__osRepairPackId",
    "__osPfsSelectBank",
    "__osCheckPackId",
    "ramromMain",
    // PFS functions
    "osPfsAllocateFile",
    "osPfsChecker",
    "osPfsDeleteFile",
    "osPfsFileState",
    "osPfsFindFile",
    "osPfsFreeBlocks",
    "osPfsGetLabel",
    "osPfsInit",
    "osPfsInitPak",
    "osPfsIsPlug",
    "osPfsNumFiles",
    "osPfsRepairId",
    "osPfsReadWriteFile",
    "__osPackEepReadData",
    "__osPackEepWriteData",
    "__osPackRamReadData",
    "__osPackRamWriteData",
    "__osPackReadData",
    "__osPackRequestData",
    "__osPfsGetInitData",
    "__osPfsGetOneChannelData",
    "__osPfsGetStatus",
    "__osPfsRequestData",
    "__osPfsRequestOneChannel",
    "__osPfsCreateAccessQueue",
    "__osPfsCheckRamArea",
    "__osPfsGetNextPage",
    // Low level serial interface functions
    "__osSiDeviceBusy",
    "__osSiGetStatus",
    "__osSiRawStartDma",
    "__osSiRawReadIo",
    "__osSiRawWriteIo",
    "__osSiCreateAccessQueue",
    "__osSiGetAccess",
    "__osSiRelAccess",
    // Parallel interface (cartridge, DMA, etc.) functions
    "osCartRomInit",
    "osLeoDiskInit",
    "osCreatePiManager",
    "__osDevMgrMain",
    "osPiGetCmdQueue",
    "osPiGetStatus",
    "osPiReadIo",
    "osPiStartDma",
    "osPiWriteIo",
    "osEPiGetDeviceType",
    "osEPiStartDma",
    "osEPiWriteIo",
    "osEPiReadIo",
    "osPiRawStartDma",
    "osPiRawReadIo",
    "osPiRawWriteIo",
    "osEPiRawStartDma",
    "osEPiRawReadIo",
    "osEPiRawWriteIo",
    "__osPiRawStartDma",
    "__osPiRawReadIo",
    "__osPiRawWriteIo",
    "__osEPiRawStartDma",
    "__osEPiRawReadIo",
    "__osEPiRawWriteIo",
    "__osPiDeviceBusy",
    "__osPiCreateAccessQueue",
    "__osPiGetAccess",
    "__osPiRelAccess",
    "__osLeoAbnormalResume",
    "__osLeoInterrupt",
    "__osLeoResume",
    // Flash saving functions
    "osFlashInit",
    "osFlashReadStatus",
    "osFlashReadId",
    "osFlashClearStatus",
    "osFlashAllErase",
    "osFlashAllEraseThrough",
    "osFlashSectorErase",
    "osFlashSectorEraseThrough",
    "osFlashCheckEraseEnd",
    "osFlashWriteBuffer",
    "osFlashWriteArray",
    "osFlashReadArray",
    "osFlashChange",
    // Threading functions
    "osCreateThread",
    "osStartThread",
    "osStopThread",
    "osDestroyThread",
    "osYieldThread",
    "osSetThreadPri",
    "osGetThreadPri",
    "osGetThreadId",
    "__osDequeueThread",
    // Message Queue functions
    "osCreateMesgQueue",
    "osSendMesg",
    "osJamMesg",
    "osRecvMesg",
    "osSetEventMesg",
    // Timer functions
    "osStartTimer",
    "osSetTimer",
    "osStopTimer",
    "osGetTime",
    "__osInsertTimer",
    "__osTimerInterrupt",
    "__osTimerServicesInit",
    "__osSetTimerIntr",
    // Voice functions
    "osVoiceSetWord",
    "osVoiceCheckWord",
    "osVoiceStopReadData",
    "osVoiceInit",
    "osVoiceMaskDictionary",
    "osVoiceStartReadData",
    "osVoiceControlGain",
    "osVoiceGetReadData",
    "osVoiceClearDictionary",
    "__osVoiceCheckResult",
    "__osVoiceContRead36",
    "__osVoiceContWrite20",
    "__osVoiceContWrite4",
    "__osVoiceContRead2",
    "__osVoiceSetADConverter",
    "__osVoiceContDataCrc",
    "__osVoiceGetStatus",
    "corrupted",
    "corrupted_init",
    // exceptasm functions
    "__osExceptionPreamble",
    "__osException",
    "__ptExceptionPreamble",
    "__ptException",
    "send_mesg",
    "handle_CpU",
    "__osEnqueueAndYield",
    "__osEnqueueThread",
    "__osPopThread",
    "__osNop",
    "__osDispatchThread",
    "__osCleanupThread",
    "osGetCurrFaultedThread",
    "osGetNextFaultedThread",
    // interrupt functions
    "osSetIntMask",
    "osGetIntMask",
    "__osDisableInt",
    "__osRestoreInt",
    "__osSetGlobalIntMask",
    "__osResetGlobalIntMask",
    // TLB functions
    "osMapTLB",
    "osUnmapTLB",
    "osUnmapTLBAll",
    "osSetTLBASID",
    "osMapTLBRdb",
    "osVirtualToPhysical",
    "__osGetTLBHi",
    "__osGetTLBLo0",
    "__osGetTLBLo1",
    "__osGetTLBPageMask",
    "__osGetTLBASID",
    "__osProbeTLB",
    // Coprocessor 0/1 functions
    "__osSetCount",
    "osGetCount",
    "__osSetSR",
    "__osGetSR",
    "__osSetCause",
    "__osGetCause",
    "__osSetCompare",
    "__osGetCompare",
    "__osSetConfig",
    "__osGetConfig",
    "__osSetWatchLo",
    "__osGetWatchLo",
    "__osSetFpcCsr",
    // Cache funcs
    "osInvalDCache",
    "osInvalICache",
    "osWritebackDCache",
    "osWritebackDCacheAll",
    // Microcodes
    "rspbootTextStart",
    "gspF3DEX2_fifoTextStart",
    "gspS2DEX2_fifoTextStart",
    "gspL3DEX2_fifoTextStart",
    // Debug functions
    "msp_proutSyncPrintf",
    "__osInitialize_msp",
    "__checkHardware_msp",
    "kmc_proutSyncPrintf",
    "__osInitialize_kmc",
    "__checkHardware_kmc",
    "isPrintfInit",
    "is_proutSyncPrintf",
    "__osInitialize_isv",
    "__checkHardware_isv",
    "__isExpJP",
    "__isExp",
    "__osRdbSend",
    "__rmonSendData",
    "__rmonWriteMem",
    "__rmonReadWordAt",
    "__rmonWriteWordTo",
    "__rmonWriteMem",
    "__rmonSetSRegs",
    "__rmonSetVRegs",
    "__rmonStopThread",
    "__rmonGetThreadStatus",
    "__rmonGetVRegs",
    "__rmonHitSpBreak",
    "__rmonRunThread",
    "__rmonClearBreak",
    "__rmonGetBranchTarget",
    "__rmonGetSRegs",
    "__rmonSetBreak",
    "__rmonReadMem",
    "__rmonRunThread",
    "__rmonCopyWords",
    "__rmonExecute",
    "__rmonGetExceptionStatus",
    "__rmonGetExeName",
    "__rmonGetFRegisters",
    "__rmonGetGRegisters",
    "__rmonGetRegionCount",
    "__rmonGetRegions",
    "__rmonGetRegisterContents",
    "__rmonGetTCB",
    "__rmonHitBreak",
    "__rmonHitCpuFault",
    "__rmonIdleRCP",
    "__rmonInit",
    "__rmonIOflush",
    "__rmonIOhandler",
    "__rmonIOputw",
    "__rmonListBreak",
    "__rmonListProcesses",
    "__rmonListThreads",
    "__rmonLoadProgram",
    "__rmonMaskIdleThreadInts",
    "__rmonMemcpy",
    "__rmonPanic",
    "__rmonRCPrunning",
    "__rmonRunRCP",
    "__rmonSendFault",
    "__rmonSendHeader",
    "__rmonSendReply",
    "__rmonSetComm",
    "__rmonSetFault",
    "__rmonSetFRegisters",
    "__rmonSetGRegisters",
    "__rmonSetSingleStep",
    "__rmonStepRCP",
    "__rmonStopUserThreads",
    "__rmonThreadStatus",
    "__rmon",
    "__rmonRunThread",
    "rmonFindFaultedThreads",
    "rmonMain",
    "rmonPrintf",
    "rmonGetRcpRegister",
    "kdebugserver",
    "send",

    // ido math routines
    "__ll_div",
    "__ll_lshift",
    "__ll_mod",
    "__ll_mul",
    "__ll_rem",
    "__ll_rshift",
    "__ull_div",
    "__ull_divremi",
    "__ull_rem",
    "__ull_rshift",
    "__d_to_ll",
    "__f_to_ll",
    "__d_to_ull",
    "__f_to_ull",
    "__ll_to_d",
    "__ll_to_f",
    "__ull_to_d",
    "__ull_to_f",
    // Setjmp/longjmp for mario party
    "setjmp",
    "longjmp"
    // 64-bit functions for banjo
    "func_8025C29C",
    "func_8025C240",
    "func_8025C288",

    // rmonregs
    "LoadStoreSU",
    "LoadStoreVU",
    "SetUpForRCPop",
    "CleanupFromRCPop",
    "__rmonGetGRegisters",
    "__rmonSetGRegisters",
    "__rmonGetFRegisters",
    "__rmonSetFRegisters",
    "rmonGetRcpRegister",
    "__rmonGetSRegs",
    "__rmonSetSRegs",
    "__rmonGetVRegs",
    "__rmonSetVRegs",
    "__rmonGetRegisterContents",

    // rmonbrk
    "SetTempBreakpoint",
    "ClearTempBreakpoint",
    "__rmonSetBreak",
    "__rmonListBreak",
    "__rmonClearBreak",
    "__rmonGetBranchTarget",
    "IsJump",
    "__rmonSetSingleStep",
    "__rmonGetExceptionStatus",
    "rmonSendBreakMessage",
    "__rmonHitBreak",
    "__rmonHitSpBreak",
    "__rmonHitCpuFault",
    "rmonFindFaultedThreads",

    // kdebugserver
    "string_to_u32",
    "send_packet",
    "clear_IP6",
    "send",
    "kdebugserver",
};

const std::unordered_set<std::string> N64Recomp::renamed_funcs {
    // Math
    "sincosf",
    "sinf",
    "cosf",
    "__sinf",
    "__cosf",
    "asin",
    "asinf",
    "acos",
    "acosf",
    "atanf",
    "atan2f",
    "tanf",
    "sqrt",
    "sqrtf",

    // Memory
    "isalpha",
    "isdigit",
    "isspace",
    "toupper",
    "tolower",
    "strncmp",
    "strncpy",
    "memcpy",
    "memset",
    "memmove",
    "memcmp",
    "strcmp",
    "strcat",
    "strcpy",
    "strchr",
    "strlen",
    "strtok",
    "strtol",
    "sprintf",
    "bzero",
    "bcopy",
    "bcmp",

    // long jumps
    "setjmp",
    "longjmp",

    // Math 2
    "ldiv",
    "lldiv",
    "ceil",
    "ceilf",
    "floor",
    "floorf",
    "fmodf",
    "fmod",
    "modf",
    "lround",
    "lroundf",
    "nearbyint",
    "nearbyintf",
    "round",
    "roundf",
    "trunc",
    "truncf",

    // printf family
    "vsprintf",
    "gcvt",
    "fcvt",
    "ecvt",

    "__assert",

    // allocations
    "malloc",
    "free",
    "realloc",
    "calloc",

    // rand
    "rand",
    "srand",
    "random",

    // gzip
    "huft_build",
    "huft_free",
    "inflate_codes",
    "inflate_stored",
    "inflate_fixed",
    "inflate_dynamic",
    "inflate_block",
    "inflate",
    "expand_gzip",
    "auRomDataRead"
    "data_write",
    "unzip",
    "updcrc",
    "clear_bufs",
    "fill_inbuf",
    "flush_window",

    // libgcc math routines
    "__muldi3",
    "__divdi3",
    "__udivdi3",
    "__umoddi3",
    "div64_64",
    "div64_32",
    "__moddi3",
    "_matherr",
};
