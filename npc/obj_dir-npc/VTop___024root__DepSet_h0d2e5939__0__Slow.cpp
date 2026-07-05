// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___eval_static(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_static\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
}

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VTop___024root___eval_final(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_final\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VTop___024root___eval_phase__stl(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_settle(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_settle\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("build-npc/Top.sv", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VTop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__stl\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf);
VL_ATTR_COLD void VTop___024root____Vm_traceActivitySetAll(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VTop___024root___stl_sequent__TOP__0(vlSelf);
        VTop___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

extern const VlUnpacked<CData/*2:0*/, 256> VTop__ConstPool__TABLE_hf6bc0ebc_0;
extern const VlUnpacked<CData/*3:0*/, 32> VTop__ConstPool__TABLE_h2558f6b1_0;

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Top__DOT__core__DOT__csr__DOT___GEN = 
        ((0xffffff7fU & vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus) 
         | (0x00000080U & (vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus 
                           << 4U)));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata 
        = (vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rs2_data 
           << (0x00000018U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result 
                              << 3U)));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb 
        = ((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
            ? 0x0000000fU : (0x0000000fU & ((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                             ? ((2U 
                                                 & vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)
                                                 ? 0x0cU
                                                 : 3U)
                                             : ((0U 
                                                 != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                                 ? 0U
                                                 : 
                                                ((IData)(1U) 
                                                 << 
                                                 (3U 
                                                  & vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result))))));
    vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_re)
            ? (((0x0300U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                 ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus
                 : 0U) | (((0x0305U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                            ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__mtvec
                            : 0U) | (((0x0341U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                                       ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__mepc
                                       : 0U) | (((0x0342U 
                                                  == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                                                  ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcause
                                                  : 0U) 
                                                | (((0x0b00U 
                                                     == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                                                     ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycle
                                                     : 0U) 
                                                   | (((0x0b80U 
                                                        == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                                                        ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycleh
                                                        : 0U) 
                                                      | (((0x0f11U 
                                                           == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                                                           ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__mvendorid
                                                           : 0U) 
                                                         | ((0x0f12U 
                                                             == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                                                             ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__marchid
                                                             : 0U))))))))
            : vlSelfRef.Top__DOT__core__DOT__bitsReg_5_data);
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data 
        = ((0x00800000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
            ? ((0x00400000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                ? ((0x00200000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                    ? ((0x00100000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_15
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_14)
                    : ((0x00100000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_13
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_12))
                : ((0x00200000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                    ? ((0x00100000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_11
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_10)
                    : ((0x00100000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_9
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_8)))
            : ((0x00400000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                ? ((0x00200000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                    ? ((0x00100000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_7
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_6)
                    : ((0x00100000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_5
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_4))
                : ((0x00200000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                    ? ((0x00100000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_3
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_2)
                    : ((0x00100000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_1
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_0))));
    if ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner))) {
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata = 0U;
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp = 2U;
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid 
            = vlSelfRef.Top__DOT__uart__DOT__rvalid;
    } else if ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner))) {
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata 
            = vlSelfRef.Top__DOT__clint__DOT__rdata;
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp = 0U;
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid 
            = vlSelfRef.Top__DOT__clint__DOT__rvalid;
    } else {
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata 
            = vlSelfRef.Top__DOT___mem_axi_rdata;
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp 
            = vlSelfRef.Top__DOT___mem_axi_rresp;
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid 
            = vlSelfRef.Top__DOT___mem_axi_rvalid;
    }
    vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_5));
    vlSelfRef.Top__DOT__core__DOT__wbu__DOT___GEN = 
        ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ecall) 
         | (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rready 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__valid_reg)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg));
    vlSelfRef.Top__DOT__core__DOT__exu__DOT__alu__DOT__io_out_result 
        = ((8U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
            ? ((4U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                ? 0U : ((2U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                         ? ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                             ? 0U : vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2)
                         : ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                             ? VL_SHIFTRS_III(32,32,5, vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1, 
                                              (0x0000001fU 
                                               & vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2))
                             : (vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1 
                                >> (0x0000001fU & vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2)))))
            : ((4U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                ? ((2U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                    ? ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                        ? (vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1 
                           << (0x0000001fU & vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2))
                        : (vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1 
                           ^ vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2))
                    : ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                        ? (vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1 
                           | vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2)
                        : (vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1 
                           & vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2)))
                : ((2U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                    ? ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                        ? (vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1 
                           < vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2)
                        : VL_LTS_III(32, vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1, vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2))
                    : ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op))
                        ? (vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1 
                           - vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2)
                        : (vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1 
                           + vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2)))));
    vlSelfRef.Top__DOT__xbar__DOT__io_uart_awready 
        = (1U & ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)) 
                 & (~ (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg))));
    vlSelfRef.Top__DOT__xbar__DOT__io_clint_awready 
        = (1U & ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)) 
                 & (~ (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg))));
    vlSelfRef.Top__DOT__xbar__DOT__io_uart_wready = 
        (1U & ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)) 
               & (~ (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg_1))));
    vlSelfRef.Top__DOT__xbar__DOT__io_clint_wready 
        = (1U & ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)) 
                 & (~ (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg_1))));
    vlSelfRef.Top__DOT__mem__DOT____VdfgRegularize_hf43a80a8_0_2 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & (~ (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid))));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_mem_ar_arvalid 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__signal_reg))));
    vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w = ((0x10000004U 
                                                   == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result) 
                                                  | (0x10000008U 
                                                     == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result));
    vlSelfRef.__VdfgRegularize_he50b618e_0_5 = ((1U 
                                                 != (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                                & ((2U 
                                                    != (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                                   & (3U 
                                                      == (IData)(vlSelfRef.Top__DOT___mem_axi_rresp))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem) 
           & ((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4) 
              & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__signal_reg)) 
                 & (~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception)))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_load 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0 
        = ((0x00000380U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                           >> 5U)) | (0x0000007fU & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__load_data_shifted 
        = (((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
             ? 0U : vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata) 
           >> (0x00000018U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_4_raddr 
                              << 3U)));
    vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_we) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect));
    vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN 
        = (((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_wr_reg) 
            & (IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect)) 
           & (0U != (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))));
    vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_mret 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_mret) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect));
    vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_wb_ex 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT___GEN) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_5));
    vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready = 
        ((~ (IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen)) 
         & (IData)(vlSelfRef.Top__DOT__mem__DOT____VdfgRegularize_hf43a80a8_0_2));
    vlSelfRef.Top__DOT__xbar__DOT__io_mem_wready = 
        ((~ (IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen)) 
         & (IData)(vlSelfRef.Top__DOT__mem__DOT____VdfgRegularize_hf43a80a8_0_2));
    vlSelfRef.Top__DOT__xbar__DOT__hit_mem_w = (1U 
                                                & (~ 
                                                   ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w) 
                                                    | (0x10000000U 
                                                       == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result))));
    vlSelfRef.Top__DOT__mem__DOT__b_fire = (((~ ((1U 
                                                  == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                                 | (2U 
                                                    == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)))) 
                                             & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready)) 
                                            & (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid));
    vlSelfRef.Top__DOT__uart__DOT__b_fire = ((IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid) 
                                             & ((1U 
                                                 == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                                & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready)));
    vlSelfRef.Top__DOT__clint__DOT__b_fire = ((IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid) 
                                              & ((1U 
                                                  != (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                                 & ((2U 
                                                     == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                                    & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__b_fire 
        = (((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
             ? (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)
             : ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                 ? (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)
                 : (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid))) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire 
        = (((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid) 
            & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rready));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_r_rready 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_load) 
           & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__valid_reg)) 
              & (~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception))));
    if (vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw) {
        vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata 
            = vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata;
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready 
            = vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rready;
    } else {
        vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata = 0U;
        vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready 
            = vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_r_rready;
    }
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_8 
        = ((0x0263U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
           | (0x02e3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_9 
        = ((0x0067U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
           | ((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
              | ((0x0083U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                 | (0x0103U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_4 
        = ((0x0013U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
           | (0x0113U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_7 
        = ((0x0213U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
           | (0x0313U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_2 
        = ((0x0023U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
           | (0x00a3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_7 
        = ((0x0203U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
           | (0x0283U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_1 
        = ((0x0363U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
           | (0x03e3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_1 
        = ((0x0063U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
           | (0x00e3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_3 
        = ((0x00f3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
           | (0x0173U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN = 
        ((0x0001fc00U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                         >> 0x0000000fU)) | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__casez_tmp 
        = ((0U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_bit_width))
            ? ((((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_sign)
                  ? 0U : (0x00ffffffU & (- (IData)(
                                                   (1U 
                                                    & (vlSelfRef.Top__DOT__core__DOT__lswu__DOT__load_data_shifted 
                                                       >> 7U)))))) 
                << 8U) | (0x000000ffU & vlSelfRef.Top__DOT__core__DOT__lswu__DOT__load_data_shifted))
            : ((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_bit_width))
                ? ((((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_sign)
                      ? 0U : (0x0000ffffU & (- (IData)(
                                                       (1U 
                                                        & (vlSelfRef.Top__DOT__core__DOT__lswu__DOT__load_data_shifted 
                                                           >> 0x0000000fU)))))) 
                    << 0x00000010U) | (0x0000ffffU 
                                       & vlSelfRef.Top__DOT__core__DOT__lswu__DOT__load_data_shifted))
                : vlSelfRef.Top__DOT__core__DOT__lswu__DOT__load_data_shifted));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_wb_ex)
            ? (0xfffffffcU & vlSelfRef.Top__DOT__core__DOT__csr__DOT__mtvec)
            : vlSelfRef.Top__DOT__core__DOT__csr__DOT__mepc);
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_wb_ex) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_mret));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wready 
        = ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg)) 
           & ((0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)
               ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_uart_wready)
               : ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)
                   ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_clint_wready)
                   : (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wready))));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire_preserved 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__valid_reg));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_ctrl_ex_found_out 
        = (((2U == ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
                     ? (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp)
                     : 0U)) | ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw) 
                               & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_5))) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire 
        = (((~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)) 
            & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_r_rready));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_3 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_2) 
           | (0x0123U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_11 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_9) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_7));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_2 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_1) 
           | ((0x0263U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
              | ((0x02e3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                 | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_1))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_4 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_3) 
           | ((0x01f3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
              | ((0x02f3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                 | ((0x0373U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                    | (0x03f3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_12 
        = ((0x00000033U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
           | ((0x00008033U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
              | ((0x000000b3U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                 | (0x00000133U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_10 
        = ((0x000002b3U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
           | (0x000082b3U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_8 
        = ((0x0393U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
           | (0x00000093U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_valid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__validReg) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire_preserved));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_has_exception 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_ctrl_ex_found_out) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__resp_ex_preserved_signal_reg));
    vlSelfRef.Top__DOT__mem__DOT__r_fire = (((~ ((1U 
                                                  == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                                 | (2U 
                                                    == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)))) 
                                             & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready)) 
                                            & (IData)(vlSelfRef.Top__DOT___mem_axi_rvalid));
    vlSelfRef.Top__DOT__uart__DOT__r_fire = (((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                              & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready)) 
                                             & (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid));
    vlSelfRef.Top__DOT__clint__DOT__r_fire = (((1U 
                                                != (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                               & ((2U 
                                                   == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                                  & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready))) 
                                              & (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT___need_skip_ref_preserved_T 
        = (((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire) 
            & ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
               & (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid))) 
           | ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__b_fire) 
              & ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                 & (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__ready_go 
        = (1U & ((~ ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem) 
                     | (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem))) 
                 | (((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem) 
                     & ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire) 
                        | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__valid_reg))) 
                    | ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem) 
                       & ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__b_fire) 
                          | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__signal_reg))))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in 
        = ((((2U == ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
                      ? 0U : (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp))) 
             | ((~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)) 
                & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_5))) 
            & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire)) 
           | (((2U == ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                        ? 0U : ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                                 ? 2U : (IData)(vlSelfRef.Top__DOT___mem_axi_bresp)))) 
               | ((1U != (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                  & ((2U != (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                     & (3U == (IData)(vlSelfRef.Top__DOT___mem_axi_bresp))))) 
              & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__b_fire)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_alu_op 
        = ((0x00000033U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
            ? 0U : ((0x00008033U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                     ? 1U : ((0x000000b3U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                              ? 7U : ((0x00000133U 
                                       == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                                       ? 2U : ((0x000001b3U 
                                                == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                                                ? 3U
                                                : (
                                                   (0x00000233U 
                                                    == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                                                    ? 6U
                                                    : 
                                                   ((0x000002b3U 
                                                     == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                                                     ? 8U
                                                     : 
                                                    ((0x000082b3U 
                                                      == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                                                      ? 9U
                                                      : 
                                                     ((0x00000333U 
                                                       == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                                                       ? 5U
                                                       : 
                                                      ((0x000003b3U 
                                                        == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                                                        ? 4U
                                                        : 
                                                       (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_11) 
                                                         | (0x0013U 
                                                            == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)))
                                                         ? 0U
                                                         : 
                                                        ((0x0113U 
                                                          == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                                          ? 2U
                                                          : 
                                                         ((0x0193U 
                                                           == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                                           ? 3U
                                                           : 
                                                          ((0x0213U 
                                                            == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                                            ? 6U
                                                            : 
                                                           ((0x0313U 
                                                             == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                                             ? 5U
                                                             : 
                                                            ((0x0393U 
                                                              == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                                              ? 4U
                                                              : 
                                                             ((0x00000093U 
                                                               == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                                                               ? 7U
                                                               : 
                                                              ((0x00000293U 
                                                                == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                                                                ? 8U
                                                                : 
                                                               ((0x00008293U 
                                                                 == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN)
                                                                 ? 9U
                                                                 : 
                                                                (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_4) 
                                                                  | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_3))
                                                                  ? 0U
                                                                  : 
                                                                 ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_1)
                                                                   ? 1U
                                                                   : 
                                                                  ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_8)
                                                                    ? 2U
                                                                    : 
                                                                   ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_1)
                                                                     ? 3U
                                                                     : 
                                                                    ((0x37U 
                                                                      == 
                                                                      (0x0000007fU 
                                                                       & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst))
                                                                      ? 0x0aU
                                                                      : 0U))))))))))))))))))))))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_6 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_12) 
           | ((0x000001b3U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
              | ((0x00000233U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                 | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_10) 
                    | ((0x00000333U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                       | (0x000003b3U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN))))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_13 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_4) 
           | ((0x0193U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
              | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_7) 
                 | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_8) 
                    | ((0x00000293U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                       | (0x00008293U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN))))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_out_valid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__ready_go));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_ready 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4)) 
                                                 | ((~ (IData)(vlSelfRef.reset)) 
                                                    & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__ready_go)))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved_signal_reg));
    vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_valid 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_2));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_3));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_5 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_13) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_4));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_6)
            ? 0U : ((0x0067U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                     ? 4U : (((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                              | ((0x0083U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                 | ((0x0103U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                    | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_7))))
                              ? 1U : ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_13)
                                       ? 0U : ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_4)
                                                ? 7U
                                                : ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_3)
                                                    ? 2U
                                                    : 
                                                   ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_2)
                                                     ? 3U
                                                     : 
                                                    ((0x37U 
                                                      == 
                                                      (0x0000007fU 
                                                       & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x17U 
                                                       == 
                                                       (0x0000007fU 
                                                        & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst))
                                                       ? 5U
                                                       : 
                                                      ((0x6fU 
                                                        == 
                                                        (0x0000007fU 
                                                         & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst))
                                                        ? 4U
                                                        : 
                                                       ((0x00000073U 
                                                         == vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                                                         ? 8U
                                                         : 
                                                        ((0x00100073U 
                                                          == vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                                                          ? 6U
                                                          : 
                                                         ((0x30200073U 
                                                           == vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
                                                           ? 9U
                                                           : 0x0aU)))))))))))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT___resp_ex_preserved_T_1 
        = ((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_out_valid));
    vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read 
        = ((~ (((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem) 
                & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid)) 
               | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_load))) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_mem_ar_arvalid));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT____VdfgRegularize_h086239f3_0_0 
        = ((~ ((((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__valid_reg)) 
                 & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem)) 
                | ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__signal_reg)) 
                   & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem))) 
               & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4))) 
           & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_has_exception)) 
              & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid)));
    vlSelfRef.__Vtableidx1 = ((((((0x6fU == (0x0000007fU 
                                             & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)) 
                                  << 3U) | ((0x17U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)) 
                                            << 2U)) 
                                | (((0x37U == (0x0000007fU 
                                               & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)) 
                                    << 1U) | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_2))) 
                               << 4U) | ((((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_3) 
                                           << 3U) | 
                                          ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_5) 
                                           << 2U)) 
                                         | (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_11) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_6))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType 
        = VTop__ConstPool__TABLE_hf6bc0ebc_0[vlSelfRef.__Vtableidx1];
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1 
        = ((6U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType))
            ? 0x0000000aU : (0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                            >> 0x0000000fU)));
    vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved 
        = ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read) 
           | (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved_signal_reg));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_ar_arvalid 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg)) 
           & ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem) 
              & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT____VdfgRegularize_h086239f3_0_0)));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT____VdfgRegularize_h086239f3_0_1 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_mem) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT____VdfgRegularize_h086239f3_0_0));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm 
        = ((4U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType))
            ? ((2U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType))
                ? 0U : ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType))
                         ? (((- (IData)((vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                         >> 0x0000001fU))) 
                             << 0x00000014U) | ((((0x000001feU 
                                                   & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                      >> 0x0000000bU)) 
                                                  | (1U 
                                                     & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                        >> 0x00000014U))) 
                                                 << 0x0000000bU) 
                                                | (0x000007feU 
                                                   & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                      >> 0x00000014U))))
                         : (0xfffff000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)))
            : ((2U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType))
                ? ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType))
                    ? (((- (IData)((vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                    >> 0x0000001fU))) 
                        << 0x0000000cU) | ((0x00000800U 
                                            & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                               << 4U)) 
                                           | ((0x000007e0U 
                                               & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                  >> 0x00000014U)) 
                                              | (0x0000001eU 
                                                 & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                    >> 7U)))))
                    : (((- (IData)((vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                    >> 0x0000001fU))) 
                        << 0x0000000cU) | ((0x00000fe0U 
                                            & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                               >> 0x00000014U)) 
                                           | (0x0000001fU 
                                              & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                 >> 7U)))))
                : ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType))
                    ? (((- (IData)((vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                    >> 0x0000001fU))) 
                        << 0x0000000cU) | (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                           >> 0x00000014U))
                    : 0U)));
    vlSelfRef.__Vtableidx2 = (((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType)) 
                               << 4U) | (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType) 
                                          << 1U) | 
                                         (5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits 
        = VTop__ConstPool__TABLE_h2558f6b1_0[vlSelfRef.__Vtableidx2];
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rdata1 
        = ((8U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
            ? ((4U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                ? ((2U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                    ? ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_15
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_14)
                    : ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_13
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_12))
                : ((2U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                    ? ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_11
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_10)
                    : ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_9
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_8)))
            : ((4U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                ? ((2U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                    ? ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_7
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_6)
                    : ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_5
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_4))
                : ((2U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                    ? ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_3
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_2)
                    : ((1U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))
                        ? vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_1
                        : vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_0))));
    vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr 
        = ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)
            ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__pc
            : vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result);
    vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_ar_arvalid) 
           | (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_2)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT____VdfgRegularize_h086239f3_0_1));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_1)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT____VdfgRegularize_h086239f3_0_1));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_br_target 
        = (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc 
           + vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm);
    vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_2 
        = (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits) 
            >> 2U) & (0U != (0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                            >> 0x00000014U))));
    vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_0 
        = (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits) 
            >> 3U) & (IData)(((0U != (0x000f8000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)) 
                              | (6U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1 
        = ((0x00004000U & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst)
            ? (0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                              >> 0x0000000fU)) : vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rdata1);
    vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r = ((0x10000004U 
                                                   == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr) 
                                                  | (0x10000008U 
                                                     == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr));
    vlSelfRef.Top__DOT__uart__DOT__ar_fire = ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid)) 
                                              & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                                 & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                                    & (0x10000000U 
                                                       == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr))));
    vlSelfRef.Top__DOT__uart__DOT__w_fire = (((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid) 
                                              & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg)) 
                                                 & (0x10000000U 
                                                    == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result))) 
                                             & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_uart_wready));
    vlSelfRef.Top__DOT__clint__DOT__w_fire = (((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid) 
                                               & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg)) 
                                                  & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w))) 
                                              & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_clint_wready));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__w_fire 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wready));
    vlSelfRef.Top__DOT__xbar__DOT__io_mem_wvalid = 
        ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid) 
         & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg)) 
            & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_mem_w)));
    vlSelfRef.Top__DOT__uart__DOT__aw_fire = (((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid) 
                                               & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
                                                  & (0x10000000U 
                                                     == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result))) 
                                              & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_uart_awready));
    vlSelfRef.Top__DOT__clint__DOT__aw_fire = (((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid) 
                                                & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
                                                   & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w))) 
                                               & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_clint_awready));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__aw_fire 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid) 
           & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
              & ((0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)
                  ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_uart_awready)
                  : ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)
                      ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_clint_awready)
                      : (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready)))));
    vlSelfRef.Top__DOT__xbar__DOT__io_mem_awvalid = 
        ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid) 
         & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
            & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_mem_w)));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target 
        = ((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType))
            ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_br_target
            : (0xfffffffeU & (vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm 
                              + vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rdata1)));
    vlSelfRef.Top__DOT__clint__DOT__ar_fire = ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid)) 
                                               & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                                  & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                                     & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r))));
    vlSelfRef.Top__DOT__mem__DOT__w_fire = ((IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wvalid) 
                                            & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wready));
    vlSelfRef.Top__DOT__uart__DOT__write_req_complete 
        = (((IData)(vlSelfRef.Top__DOT__uart__DOT__aw_fire) 
            | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg)) 
           & ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)) 
              & ((IData)(vlSelfRef.Top__DOT__uart__DOT__w_fire) 
                 | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg_1))));
    vlSelfRef.Top__DOT__clint__DOT__write_req_complete 
        = (((IData)(vlSelfRef.Top__DOT__clint__DOT__aw_fire) 
            | (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg)) 
           & ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)) 
              & ((IData)(vlSelfRef.Top__DOT__clint__DOT__w_fire) 
                 | (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg_1))));
    vlSelfRef.Top__DOT__mem__DOT__aw_fire = ((IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awvalid) 
                                             & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready));
    vlSelfRef.Top__DOT__xbar__DOT__io_mem_arready = 
        (1U & ((~ (IData)(vlSelfRef.reset)) & (~ ((IData)(vlSelfRef.Top__DOT___mem_axi_rvalid) 
                                                  | ((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen) 
                                                     | ((IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awvalid) 
                                                        | ((IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen) 
                                                           | ((IData)(vlSelfRef.Top__DOT___mem_axi_bvalid) 
                                                              | (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wvalid)))))))));
    if (vlSelfRef.Top__DOT__mem__DOT__w_fire) {
        vlSelfRef.Top__DOT__mem__DOT__write_data = vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata;
        vlSelfRef.Top__DOT__mem__DOT__write_strb = vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb;
    } else {
        vlSelfRef.Top__DOT__mem__DOT__write_data = vlSelfRef.Top__DOT__mem__DOT__wdata_latched;
        vlSelfRef.Top__DOT__mem__DOT__write_strb = vlSelfRef.Top__DOT__mem__DOT__wstrb_latched;
    }
    if (vlSelfRef.Top__DOT__mem__DOT__aw_fire) {
        vlSelfRef.Top__DOT__mem__DOT__write_id = 1U;
        vlSelfRef.Top__DOT__mem__DOT__write_addr = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result;
    } else {
        vlSelfRef.Top__DOT__mem__DOT__write_id = vlSelfRef.Top__DOT__mem__DOT__awid_latched;
        vlSelfRef.Top__DOT__mem__DOT__write_addr = vlSelfRef.Top__DOT__mem__DOT__awaddr_latched;
    }
    vlSelfRef.Top__DOT__mem__DOT__write_req_complete 
        = (((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen) 
            | (IData)(vlSelfRef.Top__DOT__mem__DOT__aw_fire)) 
           & ((~ (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid)) 
              & ((IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen) 
                 | (IData)(vlSelfRef.Top__DOT__mem__DOT__w_fire))));
    vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arready 
        = (1U & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                 & ((0x10000000U == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr)
                     ? (~ (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid))
                     : ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r)
                         ? (~ (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid))
                         : (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_arready)))));
    vlSelfRef.Top__DOT__xbar__DOT__ar_fire = ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                              & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arready));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ar_fire 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_mem_ar_arvalid) 
           & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved) 
              & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arready) 
                 & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read))));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__ar_fire 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_ar_arvalid) 
           & ((~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)) 
              & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arready)));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_valid 
        = ((~ (IData)(vlSelfRef.reset)) & ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ar_fire) 
                                           | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__signal_reg)));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__ready_go 
        = (1U & ((~ ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem) 
                     | (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_mem))) 
                 | (((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem) 
                     & ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__ar_fire) 
                        | (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg))) 
                    | ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_mem) 
                       & (((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__aw_fire) 
                           | (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_1)) 
                          & ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__w_fire) 
                             | (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_2)))))));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_valid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__ready_go));
    vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_ready 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid)) 
                                                 | ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__ready_go) 
                                                    & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_ready)))));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT___GEN = 
        ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_ready) 
         & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_valid));
    vlSelfRef.Top__DOT__core__DOT___flush_next_cycle_T_6 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_valid) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_ready));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_ready 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_valid)) 
                                                 | (IData)(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_ready))));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_valid) 
           & (((0U == vlSelfRef.Top__DOT__core__DOT__exu__DOT__alu__DOT__io_out_result) 
               == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_expect_0)) 
              & ((IData)(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_ready) 
                 & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_has_exception)) 
                    & (IData)(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_valid)))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_flush 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken) 
           | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in) 
              | (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_need_flush_in_IF_or_IW)));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__valid 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_flush)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_1));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__ready_go 
        = (1U & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__valid)) 
                 | (~ (((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in)) 
                        & ((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_2) 
                           & ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_reg) 
                              & (((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_0) 
                                  & ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd)) 
                                     & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1) 
                                        == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd)))) 
                                 | ((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_2) 
                                    & ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd)) 
                                       & ((0x0000001fU 
                                           & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                              >> 0x00000014U)) 
                                          == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd)))))))) 
                       | (((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_3) 
                           & ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_reg) 
                              & (((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_0) 
                                  & ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd)) 
                                     & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1) 
                                        == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd)))) 
                                 | ((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_2) 
                                    & ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd)) 
                                       & ((0x0000001fU 
                                           & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                              >> 0x00000014U)) 
                                          == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd))))))) 
                          | (((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4) 
                              & ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_reg) 
                                 & (((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_0) 
                                     & ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd)) 
                                        & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1) 
                                           == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd)))) 
                                    | ((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_2) 
                                       & ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd)) 
                                          & ((0x0000001fU 
                                              & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                 >> 0x00000014U)) 
                                             == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd))))))) 
                             | ((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_5) 
                                & ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_wr_reg) 
                                   & (((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_0) 
                                       & ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd)) 
                                          & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1) 
                                             == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd)))) 
                                      | ((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_2) 
                                         & ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd)) 
                                            & ((0x0000001fU 
                                                & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                   >> 0x00000014U)) 
                                               == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd)))))))))))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_has_exception)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__valid));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_ready 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__valid)) 
                                                 | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__ready_go) 
                                                    & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_ready)))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_valid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__valid) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__ready_go));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re 
        = ((7U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ebreak 
        = ((6U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_inv 
        = ((0x0aU == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ecall 
        = ((8U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_mret 
        = ((9U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_ready) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_valid));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_ready 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__validReg)) 
                                                 | ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire_preserved) 
                                                    & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_ready)))));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___ftrace_is_jalr_T_3 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_ready) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_valid));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_ready) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_valid));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_flush_ex_found_in 
        = ((((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ebreak) 
             | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_inv) 
                | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ecall) 
                   | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_mret)))) 
            & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___ftrace_is_jalr_T_3)) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in));
    vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_6 
        = ((4U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___ftrace_is_jalr_T_3));
    vlSelfRef.Top__DOT__core__DOT____Vcellinp__ifu__io_ctrl_ex_found_in 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_ctrl_ex_found_out) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_flush_ex_found_in));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_6) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_need_flush_in_IF 
        = (((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid) 
            | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg)) 
           | (((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken) 
               | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_1)) 
              | (((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid) 
                  | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_2)) 
                 | ((IData)(vlSelfRef.Top__DOT__core__DOT____Vcellinp__ifu__io_ctrl_ex_found_in) 
                    | ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid)) 
                       & (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ex_found_in_preserved_signal_reg))))));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW 
        = (((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken) 
            | ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid) 
               | ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken)) 
                  & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_flush_ex_found_in)))) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_dnpc 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid)
            ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target
            : ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_2)
                ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg_2
                : ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken)
                    ? vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_target
                    : ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_1)
                        ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg_1
                        : ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid)
                            ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target
                            : ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg)
                                ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg
                                : ((IData)(4U) + vlSelfRef.Top__DOT__core__DOT__ifu__DOT__pc)))))));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved_signal_reg));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_need_flush_in_IF_or_IW 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_need_flush_in_IF) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved));
}

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf);

VL_ATTR_COLD bool VTop___024root___eval_phase__stl(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__stl\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VTop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VTop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__ico\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__act\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__nba\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root____Vm_traceActivitySetAll(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vm_traceActivitySetAll\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void VTop___024root___ctor_var_reset(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ctor_var_reset\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5452235342940299466ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->Top__DOT___mem_axi_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 376985391473744318ull);
    vlSelf->Top__DOT___mem_axi_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17506572391639370459ull);
    vlSelf->Top__DOT___mem_axi_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11162632857370809161ull);
    vlSelf->Top__DOT___mem_axi_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3838260888867727468ull);
    vlSelf->Top__DOT___mem_axi_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4190378706338041534ull);
    vlSelf->Top__DOT__core__DOT__validReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15663322972807497235ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_need_flush_in_IF = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13135638108553522705ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 64153332283538010ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5875812706652226132ull);
    vlSelf->Top__DOT__core__DOT__validReg_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1265457034013304846ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_1_need_flush_in_IF_or_IW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18296372627401827770ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_1_inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 494762570227536601ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_1_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17285132242691106750ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_1_dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14606261863380883696ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_1_has_exception = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18167450247246534719ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_1_exception_code = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17690947066663856778ull);
    vlSelf->Top__DOT__core__DOT__flush_preserved_signal_reg_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7241989592812733447ull);
    vlSelf->Top__DOT__core__DOT__validReg_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6460534210255619135ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7537848788864643939ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9898999346797002178ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14522426414260234999ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7245525056883418659ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4202416071101765167ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_wr_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12516948077427400348ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_rd_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11564251514708339702ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_wr_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3339628762032593107ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_bit_width = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6707912461701879009ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5558154408439687384ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_br_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4786410661697919208ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_br_expect_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3838709432509472729ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_br_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6360532125159745477ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18341692081742583265ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7669806068345377130ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2711471529912477398ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_csrReq_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 9092115915045791014ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_csrReq_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18197984924280874109ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_csrReq_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17259578486310726637ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_csrReq_wmask = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 963921026022471540ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_csrReq_wvalue = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4004987912519844009ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_ebreak = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8336380744023848423ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_inv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2159337874604880109ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6426807863383611381ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16606218743548328782ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_has_exception = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10298609585330911312ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_2_exception_code = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14038113491819192404ull);
    vlSelf->Top__DOT__core__DOT__validReg_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9522198711066454003ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9217827583832576077ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 647651907215080620ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_wr_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 907991744435413692ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1993074701175414700ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_rd_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17768790263586369437ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_wr_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11040877399229942901ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_bit_width = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15462860840312565700ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13047991235387862193ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16394140681673665539ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1418973420884260708ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10968247130622581591ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_csrReq_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 8617526937499762824ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_csrReq_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5167096119079081261ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_csrReq_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 581437309793464544ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_csrReq_wmask = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6017556935423991670ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_csrReq_wvalue = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1499631363375801218ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_ebreak = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4495359360078598312ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_inv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3014014013052883360ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11441068808027009754ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3702527075838978253ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_has_exception = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16912320935840805317ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_3_exception_code = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3846540109569011403ull);
    vlSelf->Top__DOT__core__DOT__flush_preserved_signal_reg_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3384389770583854065ull);
    vlSelf->Top__DOT__core__DOT__validReg_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17883756494518993272ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_raddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16596280623161808871ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_bit_width = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1488889925337444618ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13716830724387420752ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_rd_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6962888446324427718ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_wr_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7392414851402364211ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5355552410946357545ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_wr_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5082741670420002942ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13532405361080960893ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9562269252900853846ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6730876568230592851ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7180205375950804628ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_csrReq_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 10306124258777265180ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_csrReq_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15985718046272026315ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_csrReq_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10004736366387994419ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_csrReq_wmask = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15818514532554079718ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_csrReq_wvalue = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5956990549033263448ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_ebreak = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 49245142514414599ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_inv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 888075403972908613ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6224691553690321405ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16774166164372187152ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_has_exception = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4286604874320027132ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_4_exception_code = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4979125566173782226ull);
    vlSelf->Top__DOT__core__DOT__validReg_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7970297547553223624ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16236114032132103787ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_wr_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2522690968290630868ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2648170327168514420ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15302163075545870939ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16182531363742703194ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12418206980902065967ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_csrReq_addr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 16366155235315992193ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_csrReq_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14317652714171884546ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_csrReq_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2550493069202027864ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_csrReq_wmask = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15588318003849796876ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5520845849985474311ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_ebreak = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3754971603062007473ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_inv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8311876783993962483ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8127574048053580533ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2048332733171420297ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_has_exception = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3405050572995108799ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_exception_code = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13862138545886809189ull);
    vlSelf->Top__DOT__core__DOT__bitsReg_5_need_skip_ref = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14839589789577178544ull);
    vlSelf->Top__DOT__core__DOT___flush_next_cycle_T_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10891457519865214283ull);
    vlSelf->Top__DOT__core__DOT____Vcellinp__ifu__io_ctrl_ex_found_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17289950100175026392ull);
    vlSelf->Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10547103747029387418ull);
    vlSelf->Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10741356201241178154ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__io_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15323073597127993991ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__io_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11951612137107722824ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__io_out_bits_need_flush_in_IF = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2765184696094268498ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__io_out_bits_dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15905789741697228468ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9302591320928127865ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7351904754934806004ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12878657799917477872ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7679076249263872471ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2185904621643557457ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__io_mem_ar_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11903635670795398663ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__ar_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14711717003758195167ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10075290343949785786ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14009951915881182277ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2274926039396943692ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__data_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18011061027328432316ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__valid_reg_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5205495001665630683ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__data_reg_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15351330354674035674ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__valid_reg_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13058488962733897047ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__data_reg_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10199678061431608160ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__ex_found_in_preserved_signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5482389251397001255ull);
    vlSelf->Top__DOT__core__DOT__ifu__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10156749583564012493ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__io_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13905873931459474721ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__io_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 818867400123549614ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__io_out_bits_need_flush_in_IF_or_IW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12465685567294313665ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__io_out_bits_has_exception = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4642684803574019933ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13951011817286092943ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__io_mem_r_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16596349340938521219ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__io_ctrl_ex_found_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12166238655729850005ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__io_flush_ex_found_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11339599832584425739ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__r_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13421950838721059407ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8747652429576238591ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9352400607497636151ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__data_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11908856286100404444ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__r_fire_preserved = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8601351844320674759ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__resp_ex_preserved_signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14134107937860630428ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1607275515783589339ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved_signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12650546161911714831ull);
    vlSelf->Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15125844050125315769ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4240896888929594231ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5136600283069209966ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_out_bits_alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 808631906878400291ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3165663552260582170ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_out_bits_br_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3699269426495039816ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6413963290851837151ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_out_bits_ebreak = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8641650650316326795ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_out_bits_inv = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10780529837481333070ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_out_bits_ecall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1381500088159498864ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_out_bits_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18254904770477243519ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_rf_rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16700618716572280980ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_rf_rdata1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1713528500844329089ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1979603579064308837ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__io_flush_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6838214806005447000ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4719915816574969615ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__allow_side_effect = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8276300844400512154ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__ready_go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14991281068972400256ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___GEN = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14255610960740954260ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___GEN_0 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 2184438481010575729ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___GEN_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13860315246221559713ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___GEN_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14056662217004562200ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___GEN_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4509697644086001286ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___GEN_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14669307738548618225ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___GEN_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16132729620832329568ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___GEN_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6714389707957117549ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__instType = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9929809927543925620ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___GEN_7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10092578437243245172ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__funcType = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12946752964263867855ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___GEN_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18337421684703578590ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__usageBits = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12283597413898054374ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT___ftrace_is_jalr_T_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 280113732472935237ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__csr_src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4020427885324502927ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13439420589015677774ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2660920595587287923ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4363638503277146177ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17410383602838609234ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11463210814789613771ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1037752538426633770ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14683220091379908155ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_9 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5375551543867318839ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_10 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17371231585160713425ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_11 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2991697724206375302ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_12 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13060160471913549804ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_13 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5473239135896363203ull);
    vlSelf->Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16564198685710957115ull);
    vlSelf->Top__DOT__core__DOT__exu__DOT__io_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13835166933954280275ull);
    vlSelf->Top__DOT__core__DOT__exu__DOT__io_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7635170077783938882ull);
    vlSelf->Top__DOT__core__DOT__exu__DOT__alu__DOT__io_out_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13914060644990546522ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__io_out_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5360590516542563059ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__io_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10297223998346715679ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__io_mem_ar_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15574225757176097269ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1809355036747643789ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4894414325523887046ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12626486996446738942ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1424841583418810968ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__io_mem_w_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17093156140463601293ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14378820024144159004ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__ar_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8149628805274814832ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__aw_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8332680773008069090ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__w_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3441002420137224071ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16323217614919871972ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__signal_reg_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12525140828583567510ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__signal_reg_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11834330317785743034ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT__ready_go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 306678760603499566ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT___GEN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1671881924109380286ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT____VdfgRegularize_h086239f3_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14340889642782371436ull);
    vlSelf->Top__DOT__core__DOT__lsu__DOT____VdfgRegularize_h086239f3_0_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10096246050423403209ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__io_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11847015286119879731ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__io_mem_r_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16983869711605391101ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17333298766483966843ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__io_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9222681022368322210ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__casez_tmp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11556248987915603150ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__r_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14816880520186120219ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__b_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18181509910813244158ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__valid_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17841189372986126030ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__data_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6980726426409204624ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16204068936271959097ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT___need_skip_ref_preserved_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2114867550674049055ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7725032748795586988ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__ready_go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13424549233334880603ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved_signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8016469034533418543ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13896400343625295791ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT__load_data_shifted = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7330189226884186030ull);
    vlSelf->Top__DOT__core__DOT__lswu__DOT___resp_ex_preserved_T_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 391290209181551286ull);
    vlSelf->Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6321723193594781285ull);
    vlSelf->Top__DOT__core__DOT__wbu__DOT__io_csr_wb_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17198356021466080620ull);
    vlSelf->Top__DOT__core__DOT__wbu__DOT__io_csr_mret = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10762158679474868894ull);
    vlSelf->Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11418763297312006033ull);
    vlSelf->Top__DOT__core__DOT__wbu__DOT__allow_side_effect = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14620188753699756087ull);
    vlSelf->Top__DOT__core__DOT__wbu__DOT__submit_dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16609565380538667055ull);
    vlSelf->Top__DOT__core__DOT__wbu__DOT___GEN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8277208494212701909ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3145204578784162781ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6204135133871780626ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1557526683506459580ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10212437531263864792ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6818191638647248142ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_5 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1691036019885087738ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_6 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15459154069283834409ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_7 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3794784732436113497ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_8 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5492477423908527756ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_9 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2827356822049769306ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_10 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12306775812806136643ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_11 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15431792226366571179ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_12 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 657261846314896423ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_13 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12958648711244068855ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_14 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6331484791856431671ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT__regfile_15 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3489490894906585305ull);
    vlSelf->Top__DOT__core__DOT__regfile__DOT___GEN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14660264977096228721ull);
    vlSelf->Top__DOT__core__DOT__csr__DOT__priv = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18132820560560789223ull);
    vlSelf->Top__DOT__core__DOT__csr__DOT__mstatus = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 251625857136381293ull);
    vlSelf->Top__DOT__core__DOT__csr__DOT__mtvec = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12110513790445365018ull);
    vlSelf->Top__DOT__core__DOT__csr__DOT__mepc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2271517187703889545ull);
    vlSelf->Top__DOT__core__DOT__csr__DOT__mcause = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14444687999917199657ull);
    vlSelf->Top__DOT__core__DOT__csr__DOT__mcycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1216773236875007872ull);
    vlSelf->Top__DOT__core__DOT__csr__DOT__mcycleh = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16586869794540275889ull);
    vlSelf->Top__DOT__core__DOT__csr__DOT__mvendorid = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10970981914423114094ull);
    vlSelf->Top__DOT__core__DOT__csr__DOT__marchid = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 396225179672309012ull);
    vlSelf->Top__DOT__core__DOT__csr__DOT___GEN = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15003007176136814107ull);
    vlSelf->Top__DOT__arbiter__DOT__io_xbar_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4344900575859347225ull);
    vlSelf->Top__DOT__arbiter__DOT__io_xbar_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16397032044609583141ull);
    vlSelf->Top__DOT__arbiter__DOT__io_xbar_araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12459435871765419776ull);
    vlSelf->Top__DOT__arbiter__DOT__io_xbar_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4915174916206033592ull);
    vlSelf->Top__DOT__arbiter__DOT__io_xbar_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15819484550359373174ull);
    vlSelf->Top__DOT__arbiter__DOT__io_xbar_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7522706881015739778ull);
    vlSelf->Top__DOT__arbiter__DOT__io_xbar_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9537621391933963015ull);
    vlSelf->Top__DOT__arbiter__DOT__grant_if_iw_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17748327336498401287ull);
    vlSelf->Top__DOT__arbiter__DOT__grant_if_iw_read_preserved_signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8452305814000927321ull);
    vlSelf->Top__DOT__arbiter__DOT__grant_if_iw_read_preserved = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13348678645049878014ull);
    vlSelf->Top__DOT__arbiter__DOT__read_owner_is_if_iw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6652030002292379158ull);
    vlSelf->Top__DOT__xbar__DOT__io_mem_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5591629170357164387ull);
    vlSelf->Top__DOT__xbar__DOT__io_mem_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11876648600736457216ull);
    vlSelf->Top__DOT__xbar__DOT__io_mem_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6654950446183174722ull);
    vlSelf->Top__DOT__xbar__DOT__io_mem_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16371192121306984370ull);
    vlSelf->Top__DOT__xbar__DOT__io_mem_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3931501697887460059ull);
    vlSelf->Top__DOT__xbar__DOT__io_uart_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6936206582559747552ull);
    vlSelf->Top__DOT__xbar__DOT__io_uart_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14068393213445819674ull);
    vlSelf->Top__DOT__xbar__DOT__io_clint_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 823399434265020361ull);
    vlSelf->Top__DOT__xbar__DOT__io_clint_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10870183666409514926ull);
    vlSelf->Top__DOT__xbar__DOT__ar_fire_after_signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8049501485769762532ull);
    vlSelf->Top__DOT__xbar__DOT__signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15036333368111556148ull);
    vlSelf->Top__DOT__xbar__DOT__w_fire_after_signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5719761217723921896ull);
    vlSelf->Top__DOT__xbar__DOT__hit_clint_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11611707897251637082ull);
    vlSelf->Top__DOT__xbar__DOT__hit_clint_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11390285870662371682ull);
    vlSelf->Top__DOT__xbar__DOT__hit_mem_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17053276888628544466ull);
    vlSelf->Top__DOT__xbar__DOT__read_owner = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15426408371101681702ull);
    vlSelf->Top__DOT__xbar__DOT__write_owner = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12785686450552656107ull);
    vlSelf->Top__DOT__xbar__DOT__ar_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2438812660876948644ull);
    vlSelf->Top__DOT__mem__DOT__axi_bid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10457567626119567216ull);
    vlSelf->Top__DOT__mem__DOT__axi_rid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5927762237047009077ull);
    vlSelf->Top__DOT__mem__DOT__axi_rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13559336098981399388ull);
    vlSelf->Top__DOT__mem__DOT__aw_seen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12018356387516348090ull);
    vlSelf->Top__DOT__mem__DOT__w_seen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6019241482512223830ull);
    vlSelf->Top__DOT__mem__DOT__awaddr_latched = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10453662480160330063ull);
    vlSelf->Top__DOT__mem__DOT__awid_latched = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18202156927171038072ull);
    vlSelf->Top__DOT__mem__DOT__wdata_latched = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12710704462016847811ull);
    vlSelf->Top__DOT__mem__DOT__wstrb_latched = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11961420643612671890ull);
    vlSelf->Top__DOT__mem__DOT__r_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3086899211872626107ull);
    vlSelf->Top__DOT__mem__DOT__aw_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12379549798765353264ull);
    vlSelf->Top__DOT__mem__DOT__w_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13651324775586038022ull);
    vlSelf->Top__DOT__mem__DOT__b_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12812127434160017860ull);
    vlSelf->Top__DOT__mem__DOT__write_req_complete = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2653149875880485633ull);
    vlSelf->Top__DOT__mem__DOT__write_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8088348884054591505ull);
    vlSelf->Top__DOT__mem__DOT__write_id = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16947843783552367946ull);
    vlSelf->Top__DOT__mem__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4056212774923359364ull);
    vlSelf->Top__DOT__mem__DOT__write_strb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1824453809933797678ull);
    vlSelf->Top__DOT__mem__DOT____VdfgRegularize_hf43a80a8_0_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8871958761719826606ull);
    vlSelf->Top__DOT__uart__DOT__aw_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8643630989537368031ull);
    vlSelf->Top__DOT__uart__DOT__w_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8210416409201745733ull);
    vlSelf->Top__DOT__uart__DOT__rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17481582200150951283ull);
    vlSelf->Top__DOT__uart__DOT__bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13770371112689050240ull);
    vlSelf->Top__DOT__uart__DOT__signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 748313668026110715ull);
    vlSelf->Top__DOT__uart__DOT__signal_reg_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1283550345479055662ull);
    vlSelf->Top__DOT__uart__DOT__write_req_complete = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4970986667871890400ull);
    vlSelf->Top__DOT__uart__DOT__wdata_preserved_data_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15802084184982895569ull);
    vlSelf->Top__DOT__uart__DOT__wstrb_preserved_data_reg = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14441098773248144426ull);
    vlSelf->Top__DOT__uart__DOT__ar_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12619796527650452099ull);
    vlSelf->Top__DOT__uart__DOT__r_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5134530444067674933ull);
    vlSelf->Top__DOT__uart__DOT__b_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13323732215303882382ull);
    vlSelf->Top__DOT__clint__DOT__mtime = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 640483610850001939ull);
    vlSelf->Top__DOT__clint__DOT__mtime_snapshot = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 906633187241629369ull);
    vlSelf->Top__DOT__clint__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18330812952184696983ull);
    vlSelf->Top__DOT__clint__DOT__aw_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11718839082386451428ull);
    vlSelf->Top__DOT__clint__DOT__w_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17174902717633680218ull);
    vlSelf->Top__DOT__clint__DOT__rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9945986591485731031ull);
    vlSelf->Top__DOT__clint__DOT__bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2410319944511558718ull);
    vlSelf->Top__DOT__clint__DOT__signal_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1178874685897398447ull);
    vlSelf->Top__DOT__clint__DOT__signal_reg_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1060499149442845726ull);
    vlSelf->Top__DOT__clint__DOT__write_req_complete = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15344880846811504455ull);
    vlSelf->Top__DOT__clint__DOT__ar_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11232701153403739177ull);
    vlSelf->Top__DOT__clint__DOT__r_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9591788106915377318ull);
    vlSelf->Top__DOT__clint__DOT__b_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2603729031886058046ull);
    vlSelf->__VdfgRegularize_he50b618e_0_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5832906720996318670ull);
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtableidx2 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13272892335938733197ull);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
