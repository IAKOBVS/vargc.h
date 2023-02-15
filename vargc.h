#define PP_NARG(...) \
         PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...) \
         PP_128TH_ARG(__VA_ARGS__)
#define PP_128TH_ARG( \
          _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,_64,_65,_66,_67,_68,_69,_70, \
         _71,_72,_73,_74,_75,_76,_77,_78,_79,_80, \
         _81,_82,_83,_84,_85,_86,_87,_88,_89,_90, \
         _91,_92,_93,_94,_95,_96,_97,_98,_99,_100, \
         _101,_102,_103,_104,_105,_106,_107,_108,_109,_110, \
         _111,_112,_113,_114,_115,_116,_117,_118,_119,_120, \
         _121,_122,_123,_124,_125,_126,_127,N,...) N
#define PP_RSEQ_N() \
         127,126,125,124,123,122,121,120, \
         119,118,117,116,115,114,113,112,111,110, \
         109,108,107,106,105,104,103,102,101,100, \
         99,98,97,96,95,94,93,92,91,90, \
         89,88,87,86,85,84,83,82,81,80, \
         79,78,77,76,75,74,73,72,71,70, \
         69,68,67,66,65,64,63,62,61,60, \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0
#define STRING_LENGTHS(...) \
    STRING_LENGTHS_(__VA_ARGS__, PP_RSEQ_N())
#define STRING_LENGTHS_(...) \
    PP_MAP(STRING_LENGTH, __VA_ARGS__)
#define STRING_LENGTH(ARG) \
    (sizeof(ARG) - 1)
#define PP_MAP(FUNC, ...) \
    PP_MAP_(FUNC, PP_NARG(__VA_ARGS__), __VA_ARGS__)
#define PP_MAP_(FUNC, N, ...) \
    PP_MAP__(FUNC, N, __VA_ARGS__)
#define PP_MAP__(FUNC, N, ...) \
    PP_MAP_##N(FUNC, __VA_ARGS__)
#define PP_MAP_0(FUNC, ...)
#define PP_MAP_1(FUNC, A, ...) FUNC(A), PP_MAP_0(FUNC, __VA_ARGS__)
#define PP_MAP_2(FUNC, A, ...) FUNC(A), PP_MAP_1(FUNC, __VA_ARGS__)
#define PP_MAP_3(FUNC, A, ...) FUNC(A), PP_MAP_2(FUNC, __VA_ARGS__)
#define PP_MAP_4(FUNC, A, ...) FUNC(A), PP_MAP_3(FUNC, __VA_ARGS__)
#define PP_MAP_5(FUNC, A, ...) FUNC(A), PP_MAP_4(FUNC, __VA_ARGS__)
#define PP_MAP_6(FUNC, A, ...) FUNC(A), PP_MAP_5(FUNC, __VA_ARGS__)
#define PP_MAP_7(FUNC, A, ...) FUNC(A), PP_MAP_6(FUNC, __VA_ARGS__)
#define PP_MAP_8(FUNC, A, ...) FUNC(A), PP_MAP_7(FUNC, __VA_ARGS__)
#define PP_MAP_9(FUNC, A, ...) FUNC(A), PP_MAP_8(FUNC, __VA_ARGS__)
#define PP_MAP_10(FUNC, A, ...) FUNC(A), PP_MAP_9(FUNC, __VA_ARGS__)
#define PP_MAP_11(FUNC, A, ...) FUNC(A), PP_MAP_10(FUNC, __VA_ARGS__)
#define PP_MAP_12(FUNC, A, ...) FUNC(A), PP_MAP_11(FUNC, __VA_ARGS__)
#define PP_MAP_13(FUNC, A, ...) FUNC(A), PP_MAP_12(FUNC, __VA_ARGS__)
#define PP_MAP_14(FUNC, A, ...) FUNC(A), PP_MAP_13(FUNC, __VA_ARGS__)
#define PP_MAP_15(FUNC, A, ...) FUNC(A), PP_MAP_14(FUNC, __VA_ARGS__)
#define PP_MAP_16(FUNC, A, ...) FUNC(A), PP_MAP_15(FUNC, __VA_ARGS__)
#define PP_MAP_17(FUNC, A, ...) FUNC(A), PP_MAP_16(FUNC, __VA_ARGS__)
#define PP_MAP_18(FUNC, A, ...) FUNC(A), PP_MAP_17(FUNC, __VA_ARGS__)
#define PP_MAP_19(FUNC, A, ...) FUNC(A), PP_MAP_18(FUNC, __VA_ARGS__)
#define PP_MAP_20(FUNC, A, ...) FUNC(A), PP_MAP_19(FUNC, __VA_ARGS__)
#define PP_MAP_21(FUNC, A, ...) FUNC(A), PP_MAP_20(FUNC, __VA_ARGS__)
#define PP_MAP_22(FUNC, A, ...) FUNC(A), PP_MAP_21(FUNC, __VA_ARGS__)
#define PP_MAP_23(FUNC, A, ...) FUNC(A), PP_MAP_22(FUNC, __VA_ARGS__)
#define PP_MAP_24(FUNC, A, ...) FUNC(A), PP_MAP_23(FUNC, __VA_ARGS__)
#define PP_MAP_25(FUNC, A, ...) FUNC(A), PP_MAP_24(FUNC, __VA_ARGS__)
#define PP_MAP_26(FUNC, A, ...) FUNC(A), PP_MAP_25(FUNC, __VA_ARGS__)
#define PP_MAP_27(FUNC, A, ...) FUNC(A), PP_MAP_26(FUNC, __VA_ARGS__)
#define PP_MAP_28(FUNC, A, ...) FUNC(A), PP_MAP_27(FUNC, __VA_ARGS__)
#define PP_MAP_29(FUNC, A, ...) FUNC(A), PP_MAP_28(FUNC, __VA_ARGS__)
#define PP_MAP_30(FUNC, A, ...) FUNC(A), PP_MAP_29(FUNC, __VA_ARGS__)
#define PP_MAP_31(FUNC, A, ...) FUNC(A), PP_MAP_30(FUNC, __VA_ARGS__)
#define PP_MAP_32(FUNC, A, ...) FUNC(A), PP_MAP_31(FUNC, __VA_ARGS__)
#define PP_MAP_33(FUNC, A, ...) FUNC(A), PP_MAP_32(FUNC, __VA_ARGS__)
#define PP_MAP_34(FUNC, A, ...) FUNC(A), PP_MAP_33(FUNC, __VA_ARGS__)
#define PP_MAP_35(FUNC, A, ...) FUNC(A), PP_MAP_34(FUNC, __VA_ARGS__)
#define PP_MAP_36(FUNC, A, ...) FUNC(A), PP_MAP_35(FUNC, __VA_ARGS__)
#define PP_MAP_37(FUNC, A, ...) FUNC(A), PP_MAP_36(FUNC, __VA_ARGS__)
#define PP_MAP_38(FUNC, A, ...) FUNC(A), PP_MAP_37(FUNC, __VA_ARGS__)
#define PP_MAP_39(FUNC, A, ...) FUNC(A), PP_MAP_38(FUNC, __VA_ARGS__)
#define PP_MAP_40(FUNC, A, ...) FUNC(A), PP_MAP_39(FUNC, __VA_ARGS__)
#define PP_MAP_41(FUNC, A, ...) FUNC(A), PP_MAP_40(FUNC, __VA_ARGS__)
#define PP_MAP_42(FUNC, A, ...) FUNC(A), PP_MAP_41(FUNC, __VA_ARGS__)
#define PP_MAP_43(FUNC, A, ...) FUNC(A), PP_MAP_42(FUNC, __VA_ARGS__)
#define PP_MAP_44(FUNC, A, ...) FUNC(A), PP_MAP_43(FUNC, __VA_ARGS__)
#define PP_MAP_45(FUNC, A, ...) FUNC(A), PP_MAP_44(FUNC, __VA_ARGS__)
#define PP_MAP_46(FUNC, A, ...) FUNC(A), PP_MAP_45(FUNC, __VA_ARGS__)
#define PP_MAP_47(FUNC, A, ...) FUNC(A), PP_MAP_46(FUNC, __VA_ARGS__)
#define PP_MAP_48(FUNC, A, ...) FUNC(A), PP_MAP_47(FUNC, __VA_ARGS__)
#define PP_MAP_49(FUNC, A, ...) FUNC(A), PP_MAP_48(FUNC, __VA_ARGS__)
#define PP_MAP_50(FUNC, A, ...) FUNC(A), PP_MAP_49(FUNC, __VA_ARGS__)
#define PP_MAP_51(FUNC, A, ...) FUNC(A), PP_MAP_50(FUNC, __VA_ARGS__)
#define PP_MAP_52(FUNC, A, ...) FUNC(A), PP_MAP_51(FUNC, __VA_ARGS__)
#define PP_MAP_53(FUNC, A, ...) FUNC(A), PP_MAP_52(FUNC, __VA_ARGS__)
#define PP_MAP_54(FUNC, A, ...) FUNC(A), PP_MAP_53(FUNC, __VA_ARGS__)
#define PP_MAP_55(FUNC, A, ...) FUNC(A), PP_MAP_54(FUNC, __VA_ARGS__)
#define PP_MAP_56(FUNC, A, ...) FUNC(A), PP_MAP_55(FUNC, __VA_ARGS__)
#define PP_MAP_57(FUNC, A, ...) FUNC(A), PP_MAP_56(FUNC, __VA_ARGS__)
#define PP_MAP_58(FUNC, A, ...) FUNC(A), PP_MAP_57(FUNC, __VA_ARGS__)
#define PP_MAP_59(FUNC, A, ...) FUNC(A), PP_MAP_58(FUNC, __VA_ARGS__)
#define PP_MAP_60(FUNC, A, ...) FUNC(A), PP_MAP_59(FUNC, __VA_ARGS__)
#define PP_MAP_61(FUNC, A, ...) FUNC(A), PP_MAP_60(FUNC, __VA_ARGS__)
#define PP_MAP_62(FUNC, A, ...) FUNC(A), PP_MAP_61(FUNC, __VA_ARGS__)
#define PP_MAP_63(FUNC, A, ...) FUNC(A), PP_MAP_62(FUNC, __VA_ARGS__)
#define PP_MAP_64(FUNC, A, ...) FUNC(A), PP_MAP_63(FUNC, __VA_ARGS__)
#define PP_MAP_65(FUNC, A, ...) FUNC(A), PP_MAP_64(FUNC, __VA_ARGS__)
#define PP_MAP_66(FUNC, A, ...) FUNC(A), PP_MAP_65(FUNC, __VA_ARGS__)
#define PP_MAP_67(FUNC, A, ...) FUNC(A), PP_MAP_66(FUNC, __VA_ARGS__)
#define PP_MAP_68(FUNC, A, ...) FUNC(A), PP_MAP_67(FUNC, __VA_ARGS__)
#define PP_MAP_69(FUNC, A, ...) FUNC(A), PP_MAP_68(FUNC, __VA_ARGS__)
#define PP_MAP_70(FUNC, A, ...) FUNC(A), PP_MAP_69(FUNC, __VA_ARGS__)
#define PP_MAP_71(FUNC, A, ...) FUNC(A), PP_MAP_70(FUNC, __VA_ARGS__)
#define PP_MAP_72(FUNC, A, ...) FUNC(A), PP_MAP_71(FUNC, __VA_ARGS__)
#define PP_MAP_73(FUNC, A, ...) FUNC(A), PP_MAP_72(FUNC, __VA_ARGS__)
#define PP_MAP_74(FUNC, A, ...) FUNC(A), PP_MAP_73(FUNC, __VA_ARGS__)
#define PP_MAP_75(FUNC, A, ...) FUNC(A), PP_MAP_74(FUNC, __VA_ARGS__)
#define PP_MAP_76(FUNC, A, ...) FUNC(A), PP_MAP_75(FUNC, __VA_ARGS__)
#define PP_MAP_77(FUNC, A, ...) FUNC(A), PP_MAP_76(FUNC, __VA_ARGS__)
#define PP_MAP_78(FUNC, A, ...) FUNC(A), PP_MAP_77(FUNC, __VA_ARGS__)
#define PP_MAP_79(FUNC, A, ...) FUNC(A), PP_MAP_78(FUNC, __VA_ARGS__)
#define PP_MAP_80(FUNC, A, ...) FUNC(A), PP_MAP_79(FUNC, __VA_ARGS__)
#define PP_MAP_81(FUNC, A, ...) FUNC(A), PP_MAP_80(FUNC, __VA_ARGS__)
#define PP_MAP_82(FUNC, A, ...) FUNC(A), PP_MAP_81(FUNC, __VA_ARGS__)
#define PP_MAP_83(FUNC, A, ...) FUNC(A), PP_MAP_82(FUNC, __VA_ARGS__)
#define PP_MAP_84(FUNC, A, ...) FUNC(A), PP_MAP_83(FUNC, __VA_ARGS__)
#define PP_MAP_85(FUNC, A, ...) FUNC(A), PP_MAP_84(FUNC, __VA_ARGS__)
#define PP_MAP_86(FUNC, A, ...) FUNC(A), PP_MAP_85(FUNC, __VA_ARGS__)
#define PP_MAP_87(FUNC, A, ...) FUNC(A), PP_MAP_86(FUNC, __VA_ARGS__)
#define PP_MAP_88(FUNC, A, ...) FUNC(A), PP_MAP_87(FUNC, __VA_ARGS__)
#define PP_MAP_89(FUNC, A, ...) FUNC(A), PP_MAP_88(FUNC, __VA_ARGS__)
#define PP_MAP_90(FUNC, A, ...) FUNC(A), PP_MAP_89(FUNC, __VA_ARGS__)
#define PP_MAP_91(FUNC, A, ...) FUNC(A), PP_MAP_90(FUNC, __VA_ARGS__)
#define PP_MAP_92(FUNC, A, ...) FUNC(A), PP_MAP_91(FUNC, __VA_ARGS__)
#define PP_MAP_93(FUNC, A, ...) FUNC(A), PP_MAP_92(FUNC, __VA_ARGS__)
#define PP_MAP_94(FUNC, A, ...) FUNC(A), PP_MAP_93(FUNC, __VA_ARGS__)
#define PP_MAP_95(FUNC, A, ...) FUNC(A), PP_MAP_94(FUNC, __VA_ARGS__)
#define PP_MAP_96(FUNC, A, ...) FUNC(A), PP_MAP_95(FUNC, __VA_ARGS__)
#define PP_MAP_97(FUNC, A, ...) FUNC(A), PP_MAP_96(FUNC, __VA_ARGS__)
#define PP_MAP_98(FUNC, A, ...) FUNC(A), PP_MAP_97(FUNC, __VA_ARGS__)
#define PP_MAP_99(FUNC, A, ...) FUNC(A), PP_MAP_98(FUNC, __VA_ARGS__)
#define PP_MAP_100(FUNC, A, ...) FUNC(A), PP_MAP_99(FUNC, __VA_ARGS__)
#define PP_MAP_101(FUNC, A, ...) FUNC(A), PP_MAP_100(FUNC, __VA_ARGS__)
#define PP_MAP_102(FUNC, A, ...) FUNC(A), PP_MAP_101(FUNC, __VA_ARGS__)
#define PP_MAP_103(FUNC, A, ...) FUNC(A), PP_MAP_102(FUNC, __VA_ARGS__)
#define PP_MAP_104(FUNC, A, ...) FUNC(A), PP_MAP_103(FUNC, __VA_ARGS__)
#define PP_MAP_105(FUNC, A, ...) FUNC(A), PP_MAP_104(FUNC, __VA_ARGS__)
#define PP_MAP_106(FUNC, A, ...) FUNC(A), PP_MAP_105(FUNC, __VA_ARGS__)
#define PP_MAP_107(FUNC, A, ...) FUNC(A), PP_MAP_106(FUNC, __VA_ARGS__)
#define PP_MAP_108(FUNC, A, ...) FUNC(A), PP_MAP_107(FUNC, __VA_ARGS__)
#define PP_MAP_109(FUNC, A, ...) FUNC(A), PP_MAP_108(FUNC, __VA_ARGS__)
#define PP_MAP_110(FUNC, A, ...) FUNC(A), PP_MAP_109(FUNC, __VA_ARGS__)
#define PP_MAP_111(FUNC, A, ...) FUNC(A), PP_MAP_110(FUNC, __VA_ARGS__)
#define PP_MAP_112(FUNC, A, ...) FUNC(A), PP_MAP_111(FUNC, __VA_ARGS__)
#define PP_MAP_113(FUNC, A, ...) FUNC(A), PP_MAP_112(FUNC, __VA_ARGS__)
#define PP_MAP_114(FUNC, A, ...) FUNC(A), PP_MAP_113(FUNC, __VA_ARGS__)
#define PP_MAP_115(FUNC, A, ...) FUNC(A), PP_MAP_114(FUNC, __VA_ARGS__)
#define PP_MAP_116(FUNC, A, ...) FUNC(A), PP_MAP_115(FUNC, __VA_ARGS__)
#define PP_MAP_117(FUNC, A, ...) FUNC(A), PP_MAP_116(FUNC, __VA_ARGS__)
#define PP_MAP_118(FUNC, A, ...) FUNC(A), PP_MAP_117(FUNC, __VA_ARGS__)
#define PP_MAP_119(FUNC, A, ...) FUNC(A), PP_MAP_118(FUNC, __VA_ARGS__)
#define PP_MAP_120(FUNC, A, ...) FUNC(A), PP_MAP_119(FUNC, __VA_ARGS__)
#define PP_MAP_121(FUNC, A, ...) FUNC(A), PP_MAP_120(FUNC, __VA_ARGS__)
#define PP_MAP_122(FUNC, A, ...) FUNC(A), PP_MAP_121(FUNC, __VA_ARGS__)
#define PP_MAP_123(FUNC, A, ...) FUNC(A), PP_MAP_122(FUNC, __VA_ARGS__)
#define PP_MAP_124(FUNC, A, ...) FUNC(A), PP_MAP_123(FUNC, __VA_ARGS__)
#define PP_MAP_125(FUNC, A, ...) FUNC(A), PP_MAP_124(FUNC, __VA_ARGS__)
#define PP_MAP_126(FUNC, A, ...) FUNC(A), PP_MAP_125(FUNC, __VA_ARGS__)
#define PP_MAP_127(FUNC, A, ...) FUNC(A), PP_MAP_126(FUNC, __VA_ARGS__)
#define PP_MAP_128(FUNC, A, ...) FUNC(A), PP_MAP_127(FUNC, __VA_ARGS__)
