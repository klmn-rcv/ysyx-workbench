// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


void VTop___024root__trace_chg_0_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_0\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);

    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;

    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;

    // Body
    VTop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VTop___024root__trace_chg_0_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_0_sub_0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);

    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved) 
                              & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arready) 
                                 & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read)))));
        bufp->chgBit(oldp+1,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_mem_ar_arvalid));
        bufp->chgBit(oldp+2,(((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
                              & ((0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)
                                  ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_uart_awready)
                                  : ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)
                                      ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_clint_awready)
                                      : (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready))))));
        bufp->chgBit(oldp+3,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wready));
        bufp->chgBit(oldp+4,(((~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)) 
                              & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arready))));
        bufp->chgBit(oldp+5,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arready));
        bufp->chgBit(oldp+6,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid));
        bufp->chgIData(oldp+7,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr),32);
        bufp->chgCData(oldp+8,((1U & (~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)))),4);
        bufp->chgCData(oldp+9,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)
                                 ? 2U : ((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                          ? 2U : ((1U 
                                                   == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                                   ? 1U
                                                   : 
                                                  ((0U 
                                                    != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width)) 
                                                   << 1U))))),3);
        bufp->chgBit(oldp+10,(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read));
        bufp->chgBit(oldp+11,(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved));
        bufp->chgBit(oldp+12,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ar_fire));
        bufp->chgBit(oldp+13,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                               & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                  & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r)))));
        bufp->chgBit(oldp+14,(vlSelfRef.Top__DOT__clint__DOT__ar_fire));
        bufp->chgBit(oldp+15,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_ready));
        bufp->chgBit(oldp+16,(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_ready));
        bufp->chgIData(oldp+17,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken)
                                  ? vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_target
                                  : vlSelfRef.Top__DOT__core__DOT__bitsReg_2_dnpc)),32);
        bufp->chgBit(oldp+18,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken));
        bufp->chgBit(oldp+19,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_ready));
        bufp->chgBit(oldp+20,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_valid));
        bufp->chgBit(oldp+21,(((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits) 
                               & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect))));
        bufp->chgBit(oldp+22,(((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                               & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect))));
        bufp->chgBit(oldp+23,(((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                               & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect))));
        bufp->chgBit(oldp+24,(((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                               & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect))));
        bufp->chgIData(oldp+25,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid)
                                  ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target
                                  : vlSelfRef.Top__DOT__core__DOT__bitsReg_1_dnpc)),32);
        bufp->chgSData(oldp+26,(((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re)
                                  ? (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                     >> 0x00000014U)
                                  : 0U)),12);
        bufp->chgBit(oldp+27,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re));
        bufp->chgBit(oldp+28,(((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re) 
                               & ((1U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                >> 0x0000000cU))) 
                                  | (((2U == (3U & 
                                              (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                               >> 0x0000000cU))) 
                                      | (3U == (3U 
                                                & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                   >> 0x0000000cU)))) 
                                     & (0U != (0x0000001fU 
                                               & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                  >> 0x0000000fU))))))));
        bufp->chgIData(oldp+29,(((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re)
                                  ? ((0U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                   >> 0x0000000cU)))
                                      ? 0U : ((1U == 
                                               (3U 
                                                & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                   >> 0x0000000cU)))
                                               ? 0xffffffffU
                                               : vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1))
                                  : 0U)),32);
        bufp->chgIData(oldp+30,(((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re)
                                  ? ((1U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                   >> 0x0000000cU)))
                                      ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1
                                      : (- (IData)(
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                        >> 0x0000000cU))))))
                                  : 0U)),32);
        bufp->chgBit(oldp+31,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ebreak));
        bufp->chgBit(oldp+32,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_inv));
        bufp->chgBit(oldp+33,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ecall));
        bufp->chgBit(oldp+34,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_mret));
        bufp->chgBit(oldp+35,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid));
        bufp->chgBit(oldp+36,((((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ebreak) 
                                | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_inv) 
                                   | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ecall) 
                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_mret)))) 
                               & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___ftrace_is_jalr_T_3))));
        bufp->chgBit(oldp+37,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_flush));
        bufp->chgBit(oldp+38,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__valid));
        bufp->chgBit(oldp+39,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
        bufp->chgBit(oldp+40,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__ready_go));
        bufp->chgBit(oldp+41,(((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType)) 
                               & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_6))));
        bufp->chgBit(oldp+42,(((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType)) 
                               & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_6))));
        bufp->chgBit(oldp+43,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_ready));
        bufp->chgBit(oldp+44,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_valid));
        bufp->chgBit(oldp+45,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_need_flush_in_IF));
        bufp->chgIData(oldp+46,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_dnpc),32);
        bufp->chgBit(oldp+47,(vlSelfRef.Top__DOT__core__DOT____Vcellinp__ifu__io_ctrl_ex_found_in));
        bufp->chgBit(oldp+48,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid) 
                               | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg))));
        bufp->chgBit(oldp+49,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken) 
                               | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_1))));
        bufp->chgBit(oldp+50,(((~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_need_flush_in_IF)) 
                               & (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T))));
        bufp->chgBit(oldp+51,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_need_flush_in_IF_or_IW));
        bufp->chgBit(oldp+52,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_flush_ex_found_in));
        bufp->chgBit(oldp+53,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW));
        bufp->chgBit(oldp+54,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved));
        bufp->chgBit(oldp+55,(((~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_need_flush_in_IF_or_IW)) 
                               & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T))));
        bufp->chgBit(oldp+56,(((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T) 
                               & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved))));
        bufp->chgBit(oldp+57,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_ready));
        bufp->chgBit(oldp+58,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_valid));
        bufp->chgBit(oldp+59,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__ar_fire));
        bufp->chgBit(oldp+60,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__aw_fire));
        bufp->chgBit(oldp+61,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__w_fire));
        bufp->chgBit(oldp+62,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__ready_go));
        bufp->chgBit(oldp+63,(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready));
        bufp->chgBit(oldp+64,(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wready));
        bufp->chgBit(oldp+65,(vlSelfRef.Top__DOT__xbar__DOT__io_mem_arready));
        bufp->chgBit(oldp+66,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                               & ((0x10000000U != vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr) 
                                  & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r)) 
                                     & (~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)))))));
        bufp->chgBit(oldp+67,((((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                & ((0x10000000U != vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr) 
                                   & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r)) 
                                      & (~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg))))) 
                               & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_arready))));
        bufp->chgBit(oldp+68,(vlSelfRef.Top__DOT__mem__DOT__aw_fire));
        bufp->chgBit(oldp+69,(vlSelfRef.Top__DOT__mem__DOT__w_fire));
        bufp->chgBit(oldp+70,(((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen) 
                               | (IData)(vlSelfRef.Top__DOT__mem__DOT__aw_fire))));
        bufp->chgBit(oldp+71,(((IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen) 
                               | (IData)(vlSelfRef.Top__DOT__mem__DOT__w_fire))));
        bufp->chgBit(oldp+72,((((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen) 
                                | (IData)(vlSelfRef.Top__DOT__mem__DOT__aw_fire)) 
                               & ((~ (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid)) 
                                  & ((IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen) 
                                     | (IData)(vlSelfRef.Top__DOT__mem__DOT__w_fire))))));
        bufp->chgIData(oldp+73,(((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_fire)
                                  ? vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result
                                  : vlSelfRef.Top__DOT__mem__DOT__awaddr_latched)),32);
        bufp->chgCData(oldp+74,(((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_fire)
                                  ? 1U : (IData)(vlSelfRef.Top__DOT__mem__DOT__awid_latched))),4);
        bufp->chgIData(oldp+75,(((IData)(vlSelfRef.Top__DOT__mem__DOT__w_fire)
                                  ? vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata
                                  : vlSelfRef.Top__DOT__mem__DOT__wdata_latched)),32);
        bufp->chgCData(oldp+76,(((IData)(vlSelfRef.Top__DOT__mem__DOT__w_fire)
                                  ? (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb)
                                  : (IData)(vlSelfRef.Top__DOT__mem__DOT__wstrb_latched))),4);
        bufp->chgCData(oldp+77,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)
                                  ? 0U : 1U)),8);
        bufp->chgBit(oldp+78,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                               & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                  & (0x10000000U == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr)))));
        bufp->chgBit(oldp+79,(((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid)) 
                               & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                  & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                     & (0x10000000U 
                                        == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr))))));
        bufp->chgBit(oldp+80,((0x10000000U == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr)));
        bufp->chgBit(oldp+81,(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r));
        bufp->chgBit(oldp+82,(vlSelfRef.Top__DOT__xbar__DOT__ar_fire));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+83,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__pc),32);
        bufp->chgBit(oldp+84,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rready));
        bufp->chgBit(oldp+85,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid) 
                               & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw))));
        bufp->chgCData(oldp+86,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
                                  ? (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp)
                                  : 0U)),2);
        bufp->chgIData(oldp+87,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata),32);
        bufp->chgBit(oldp+88,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid));
        bufp->chgIData(oldp+89,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result),32);
        bufp->chgCData(oldp+90,(((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                  ? 2U : ((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                           ? 1U : (
                                                   (0U 
                                                    != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width)) 
                                                   << 1U)))),3);
        bufp->chgBit(oldp+91,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid));
        bufp->chgIData(oldp+92,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata),32);
        bufp->chgCData(oldp+93,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb),4);
        bufp->chgBit(oldp+94,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready));
        bufp->chgBit(oldp+95,(((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                                ? (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)
                                : ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                                    ? (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)
                                    : (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid)))));
        bufp->chgCData(oldp+96,(((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                                  ? 0U : ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                                           ? 2U : (IData)(vlSelfRef.Top__DOT___mem_axi_bresp)))),2);
        bufp->chgBit(oldp+97,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_ar_arvalid));
        bufp->chgBit(oldp+98,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_r_rready));
        bufp->chgBit(oldp+99,(((~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)) 
                               & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid))));
        bufp->chgCData(oldp+100,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
                                   ? 0U : (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp))),2);
        bufp->chgIData(oldp+101,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
                                   ? 0U : vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata)),32);
        bufp->chgBit(oldp+102,((((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem) 
                                 & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid)) 
                                | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_load))));
        bufp->chgBit(oldp+103,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready));
        bufp->chgBit(oldp+104,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid));
        bufp->chgCData(oldp+105,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp),2);
        bufp->chgIData(oldp+106,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata),32);
        bufp->chgBit(oldp+107,(((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                & (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid))));
        bufp->chgBit(oldp+108,(((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                & (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid))));
        bufp->chgBit(oldp+109,(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved_signal_reg));
        bufp->chgBit(oldp+110,(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw));
        bufp->chgBit(oldp+111,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire));
        bufp->chgBit(oldp+112,(vlSelfRef.Top__DOT__xbar__DOT__io_clint_awready));
        bufp->chgBit(oldp+113,(((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid) 
                                & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
                                   & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)))));
        bufp->chgBit(oldp+114,(vlSelfRef.Top__DOT__xbar__DOT__io_clint_wready));
        bufp->chgBit(oldp+115,(((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid) 
                                & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg)) 
                                   & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)))));
        bufp->chgBit(oldp+116,(((1U != (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                & ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                   & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready)))));
        bufp->chgBit(oldp+117,(vlSelfRef.Top__DOT__clint__DOT__bvalid));
        bufp->chgBit(oldp+118,((1U & (~ (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid)))));
        bufp->chgBit(oldp+119,(((1U != (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                & ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                   & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready)))));
        bufp->chgBit(oldp+120,(vlSelfRef.Top__DOT__clint__DOT__rvalid));
        bufp->chgIData(oldp+121,(vlSelfRef.Top__DOT__clint__DOT__rdata),32);
        bufp->chgQData(oldp+122,(vlSelfRef.Top__DOT__clint__DOT__mtime),64);
        bufp->chgQData(oldp+124,(vlSelfRef.Top__DOT__clint__DOT__mtime_snapshot),64);
        bufp->chgBit(oldp+126,(vlSelfRef.Top__DOT__clint__DOT__aw_fire));
        bufp->chgBit(oldp+127,(vlSelfRef.Top__DOT__clint__DOT__w_fire));
        bufp->chgBit(oldp+128,(vlSelfRef.Top__DOT__clint__DOT__signal_reg));
        bufp->chgBit(oldp+129,(vlSelfRef.Top__DOT__clint__DOT__signal_reg_1));
        bufp->chgBit(oldp+130,((((IData)(vlSelfRef.Top__DOT__clint__DOT__aw_fire) 
                                 | (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg)) 
                                & ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)) 
                                   & ((IData)(vlSelfRef.Top__DOT__clint__DOT__w_fire) 
                                      | (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg_1))))));
        bufp->chgBit(oldp+131,((((1U != (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                 & ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                    & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready))) 
                                & (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid))));
        bufp->chgBit(oldp+132,(vlSelfRef.Top__DOT__clint__DOT__b_fire));
        bufp->chgBit(oldp+133,(vlSelfRef.Top__DOT__core__DOT__validReg));
        bufp->chgBit(oldp+134,(vlSelfRef.Top__DOT__core__DOT__bitsReg_need_flush_in_IF));
        bufp->chgIData(oldp+135,(vlSelfRef.Top__DOT__core__DOT__bitsReg_pc),32);
        bufp->chgIData(oldp+136,(vlSelfRef.Top__DOT__core__DOT__bitsReg_dnpc),32);
        bufp->chgBit(oldp+137,(vlSelfRef.Top__DOT__core__DOT__validReg_1));
        bufp->chgBit(oldp+138,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_need_flush_in_IF_or_IW));
        bufp->chgIData(oldp+139,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst),32);
        bufp->chgIData(oldp+140,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc),32);
        bufp->chgIData(oldp+141,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_dnpc),32);
        bufp->chgBit(oldp+142,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_has_exception));
        bufp->chgIData(oldp+143,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_exception_code),32);
        bufp->chgBit(oldp+144,(vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_1));
        bufp->chgBit(oldp+145,(vlSelfRef.Top__DOT__core__DOT__validReg_2));
        bufp->chgCData(oldp+146,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op),4);
        bufp->chgCData(oldp+147,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd),5);
        bufp->chgIData(oldp+148,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1),32);
        bufp->chgIData(oldp+149,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2),32);
        bufp->chgIData(oldp+150,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rs2_data),32);
        bufp->chgBit(oldp+151,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_reg));
        bufp->chgBit(oldp+152,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd_mem));
        bufp->chgBit(oldp+153,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_mem));
        bufp->chgCData(oldp+154,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_bit_width),2);
        bufp->chgBit(oldp+155,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_sign));
        bufp->chgBit(oldp+156,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_valid));
        bufp->chgBit(oldp+157,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_expect_0));
        bufp->chgIData(oldp+158,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_target),32);
        bufp->chgIData(oldp+159,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inst),32);
        bufp->chgIData(oldp+160,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_pc),32);
        bufp->chgIData(oldp+161,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_dnpc),32);
        bufp->chgSData(oldp+162,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_addr),12);
        bufp->chgBit(oldp+163,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_re));
        bufp->chgBit(oldp+164,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_we));
        bufp->chgIData(oldp+165,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wmask),32);
        bufp->chgIData(oldp+166,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wvalue),32);
        bufp->chgBit(oldp+167,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ebreak));
        bufp->chgBit(oldp+168,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inv));
        bufp->chgBit(oldp+169,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ecall));
        bufp->chgBit(oldp+170,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_mret));
        bufp->chgBit(oldp+171,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_has_exception));
        bufp->chgIData(oldp+172,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_exception_code),32);
        bufp->chgBit(oldp+173,(vlSelfRef.Top__DOT__core__DOT__validReg_3));
        bufp->chgIData(oldp+174,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rs2_data),32);
        bufp->chgBit(oldp+175,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_reg));
        bufp->chgCData(oldp+176,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd),5);
        bufp->chgBit(oldp+177,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem));
        bufp->chgBit(oldp+178,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_mem));
        bufp->chgCData(oldp+179,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width),2);
        bufp->chgBit(oldp+180,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_sign));
        bufp->chgIData(oldp+181,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_inst),32);
        bufp->chgIData(oldp+182,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_pc),32);
        bufp->chgIData(oldp+183,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_dnpc),32);
        bufp->chgSData(oldp+184,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_addr),12);
        bufp->chgBit(oldp+185,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_re));
        bufp->chgBit(oldp+186,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_we));
        bufp->chgIData(oldp+187,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_wmask),32);
        bufp->chgIData(oldp+188,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_wvalue),32);
        bufp->chgBit(oldp+189,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_ebreak));
        bufp->chgBit(oldp+190,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_inv));
        bufp->chgBit(oldp+191,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_ecall));
        bufp->chgBit(oldp+192,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_mret));
        bufp->chgBit(oldp+193,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_has_exception));
        bufp->chgIData(oldp+194,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_exception_code),32);
        bufp->chgBit(oldp+195,(vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_3));
        bufp->chgBit(oldp+196,(vlSelfRef.Top__DOT__core__DOT__validReg_4));
        bufp->chgIData(oldp+197,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_raddr),32);
        bufp->chgCData(oldp+198,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_bit_width),2);
        bufp->chgBit(oldp+199,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_sign));
        bufp->chgBit(oldp+200,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem));
        bufp->chgBit(oldp+201,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem));
        bufp->chgIData(oldp+202,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_result),32);
        bufp->chgBit(oldp+203,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_reg));
        bufp->chgCData(oldp+204,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd),5);
        bufp->chgIData(oldp+205,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_inst),32);
        bufp->chgIData(oldp+206,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_pc),32);
        bufp->chgIData(oldp+207,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_dnpc),32);
        bufp->chgSData(oldp+208,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_addr),12);
        bufp->chgBit(oldp+209,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_re));
        bufp->chgBit(oldp+210,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_we));
        bufp->chgIData(oldp+211,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_wmask),32);
        bufp->chgIData(oldp+212,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_wvalue),32);
        bufp->chgBit(oldp+213,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_ebreak));
        bufp->chgBit(oldp+214,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_inv));
        bufp->chgBit(oldp+215,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_ecall));
        bufp->chgBit(oldp+216,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_mret));
        bufp->chgBit(oldp+217,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception));
        bufp->chgIData(oldp+218,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_exception_code),32);
        bufp->chgBit(oldp+219,(vlSelfRef.Top__DOT__core__DOT__validReg_5));
        bufp->chgIData(oldp+220,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_data),32);
        bufp->chgBit(oldp+221,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_wr_reg));
        bufp->chgCData(oldp+222,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd),5);
        bufp->chgIData(oldp+223,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inst),32);
        bufp->chgIData(oldp+224,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_pc),32);
        bufp->chgIData(oldp+225,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_dnpc),32);
        bufp->chgSData(oldp+226,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr),12);
        bufp->chgBit(oldp+227,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_re));
        bufp->chgBit(oldp+228,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_we));
        bufp->chgIData(oldp+229,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask),32);
        bufp->chgIData(oldp+230,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue),32);
        bufp->chgBit(oldp+231,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ebreak));
        bufp->chgBit(oldp+232,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inv));
        bufp->chgBit(oldp+233,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ecall));
        bufp->chgBit(oldp+234,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_mret));
        bufp->chgBit(oldp+235,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception));
        bufp->chgIData(oldp+236,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_exception_code),32);
        bufp->chgBit(oldp+237,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_need_skip_ref));
        bufp->chgBit(oldp+238,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we));
        bufp->chgBit(oldp+239,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_wb_ex));
        bufp->chgIData(oldp+240,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception)
                                   ? vlSelfRef.Top__DOT__core__DOT__bitsReg_5_exception_code
                                   : ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ecall)
                                       ? ((0U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                           ? 8U : (
                                                   (1U 
                                                    == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                                    ? 9U
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                                     ? 0U
                                                     : 0x0000000bU)))
                                       : 0U))),32);
        bufp->chgIData(oldp+241,(((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT___GEN)
                                   ? vlSelfRef.Top__DOT__core__DOT__bitsReg_5_pc
                                   : 0U)),32);
        bufp->chgBit(oldp+242,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_mret));
        bufp->chgIData(oldp+243,((((0x0300U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                                    ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus
                                    : 0U) | (((0x0305U 
                                               == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                                               ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__mtvec
                                               : 0U) 
                                             | (((0x0341U 
                                                  == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
                                                  ? vlSelfRef.Top__DOT__core__DOT__csr__DOT__mepc
                                                  : 0U) 
                                                | (((0x0342U 
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
                                                                : 0U))))))))),32);
        bufp->chgCData(oldp+244,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv),2);
        bufp->chgIData(oldp+245,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mtvec),32);
        bufp->chgIData(oldp+246,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mepc),32);
        bufp->chgIData(oldp+247,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus),32);
        bufp->chgIData(oldp+248,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcause),32);
        bufp->chgIData(oldp+249,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycle),32);
        bufp->chgIData(oldp+250,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycleh),32);
        bufp->chgIData(oldp+251,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mvendorid),32);
        bufp->chgIData(oldp+252,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__marchid),32);
        bufp->chgBit(oldp+253,((0x0300U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->chgBit(oldp+254,((0x0305U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->chgBit(oldp+255,((0x0341U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->chgBit(oldp+256,((0x0342U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->chgBit(oldp+257,((0x0b80U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->chgBit(oldp+258,((0x0f11U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->chgBit(oldp+259,((0x0f12U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->chgBit(oldp+260,(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_valid));
        bufp->chgIData(oldp+261,(vlSelfRef.Top__DOT__core__DOT__exu__DOT__alu__DOT__io_out_result),32);
        bufp->chgBit(oldp+262,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in));
        bufp->chgCData(oldp+263,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_alu_op),4);
        bufp->chgCData(oldp+264,((0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                 >> 7U))),5);
        bufp->chgIData(oldp+265,((((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                                   | (4U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)))
                                   ? vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc
                                   : ((8U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits))
                                       ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rdata1
                                       : 0U))),32);
        bufp->chgIData(oldp+266,(((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType))
                                   ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm
                                   : ((4U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType))
                                       ? 4U : ((3U 
                                                == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType))
                                                ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits))
                                                    ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits))
                                                     ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data
                                                     : 0U)))))),32);
        bufp->chgIData(oldp+267,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data),32);
        bufp->chgCData(oldp+268,((((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_6) 
                                   | (0x0067U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)))
                                   ? 2U : ((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                            ? 0U : 
                                           ((0x0083U 
                                             == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                             ? 1U : 
                                            ((0x0103U 
                                              == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                              ? 2U : 
                                             ((0x0203U 
                                               == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                               ? 0U
                                               : ((0x0283U 
                                                   == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                                   ? 1U
                                                   : 
                                                  ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_5)
                                                    ? 2U
                                                    : 
                                                   ((0x0023U 
                                                     == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                                     ? 0U
                                                     : 
                                                    ((0x00a3U 
                                                      == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                                      ? 1U
                                                      : 2U)))))))))),2);
        bufp->chgBit(oldp+269,(((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_12)) 
                                & ((0x000001b3U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                                   | ((~ ((0x00000233U 
                                           == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                                          | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_10) 
                                             | ((0x00000333U 
                                                 == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                                                | ((0x000003b3U 
                                                    == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                                                   | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_9)))))) 
                                      & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_7) 
                                         | ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_4)) 
                                            & ((0x0193U 
                                                == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                               | ((~ 
                                                   ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_7) 
                                                    | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_8) 
                                                       | ((0x00000293U 
                                                           == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                                                          | ((0x00008293U 
                                                              == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                                                             | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_3) 
                                                                | ((0x01f3U 
                                                                    == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                                                   | ((0x02f3U 
                                                                       == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                                                      | ((0x0373U 
                                                                          == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                                                         | ((0x03f3U 
                                                                             == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                                                            | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_2) 
                                                                               | ((0x0123U 
                                                                                == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                                                                | ((0x0063U 
                                                                                == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                                                                | ((0x00e3U 
                                                                                == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                                                                | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_8))))))))))))))) 
                                                  & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_1))))))))));
        bufp->chgBit(oldp+270,(((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                                & ((0U == (7U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                 >> 0x0000000cU))) 
                                   | ((5U == (7U & 
                                              (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                               >> 0x0000000cU))) 
                                      | (7U == (7U 
                                                & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                   >> 0x0000000cU))))))));
        bufp->chgIData(oldp+271,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_br_target),32);
        bufp->chgCData(oldp+272,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1),5);
        bufp->chgCData(oldp+273,((0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                 >> 0x00000014U))),5);
        bufp->chgIData(oldp+274,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rdata1),32);
        bufp->chgIData(oldp+275,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target),32);
        bufp->chgBit(oldp+276,((1U & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits) 
                                      >> 3U))));
        bufp->chgBit(oldp+277,((1U & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits) 
                                      >> 2U))));
        bufp->chgBit(oldp+278,((((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in)) 
                                 & ((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_2) 
                                    & ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_reg) 
                                       & (((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_0) 
                                           & ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd)) 
                                              & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1) 
                                                 == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd)))) 
                                          | ((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_2) 
                                             & ((0U 
                                                 != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd)) 
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
                                             & ((0U 
                                                 != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd)) 
                                                & ((0x0000001fU 
                                                    & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                       >> 0x00000014U)) 
                                                   == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd))))))) 
                                   | (((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4) 
                                       & ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_reg) 
                                          & (((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_0) 
                                              & ((0U 
                                                  != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd)) 
                                                 & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1) 
                                                    == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd)))) 
                                             | ((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_2) 
                                                & ((0U 
                                                    != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd)) 
                                                   & ((0x0000001fU 
                                                       & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                          >> 0x00000014U)) 
                                                      == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd))))))) 
                                      | ((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_5) 
                                         & ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_wr_reg) 
                                            & (((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_0) 
                                                & ((0U 
                                                    != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1) 
                                                      == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd)))) 
                                               | ((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_2) 
                                                  & ((0U 
                                                      != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd)) 
                                                     & ((0x0000001fU 
                                                         & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                            >> 0x00000014U)) 
                                                        == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))))))))));
        bufp->chgCData(oldp+279,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType),3);
        bufp->chgCData(oldp+280,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType),4);
        bufp->chgCData(oldp+281,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits),4);
        bufp->chgIData(oldp+282,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm),32);
        bufp->chgIData(oldp+283,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1),32);
        bufp->chgIData(oldp+284,(((0U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                >> 0x0000000cU)))
                                   ? 0U : ((1U == (3U 
                                                   & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                      >> 0x0000000cU)))
                                            ? 0xffffffffU
                                            : vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1))),32);
        bufp->chgCData(oldp+285,((0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                 >> 0x0000000fU))),5);
        bufp->chgBit(oldp+286,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid));
        bufp->chgIData(oldp+287,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target),32);
        bufp->chgBit(oldp+288,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__signal_reg));
        bufp->chgBit(oldp+289,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg));
        bufp->chgIData(oldp+290,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg),32);
        bufp->chgBit(oldp+291,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_1));
        bufp->chgIData(oldp+292,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg_1),32);
        bufp->chgBit(oldp+293,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_2));
        bufp->chgIData(oldp+294,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg_2),32);
        bufp->chgBit(oldp+295,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid) 
                                | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_2))));
        bufp->chgBit(oldp+296,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ex_found_in_preserved_signal_reg));
        bufp->chgBit(oldp+297,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_valid));
        bufp->chgIData(oldp+298,(((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire)
                                   ? vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata
                                   : vlSelfRef.Top__DOT__core__DOT__iwu__DOT__data_reg)),32);
        bufp->chgBit(oldp+299,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_has_exception));
        bufp->chgIData(oldp+300,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_has_exception),32);
        bufp->chgBit(oldp+301,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_ctrl_ex_found_out));
        bufp->chgBit(oldp+302,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__valid_reg));
        bufp->chgIData(oldp+303,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__data_reg),32);
        bufp->chgBit(oldp+304,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire_preserved));
        bufp->chgBit(oldp+305,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__resp_ex_preserved_signal_reg));
        bufp->chgBit(oldp+306,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved_signal_reg));
        bufp->chgBit(oldp+307,(((((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__valid_reg)) 
                                  & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem)) 
                                 | ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__signal_reg)) 
                                    & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem))) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4))));
        bufp->chgBit(oldp+308,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid))));
        bufp->chgBit(oldp+309,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid));
        bufp->chgBit(oldp+310,(((~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_has_exception)) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid))));
        bufp->chgBit(oldp+311,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg));
        bufp->chgBit(oldp+312,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_1));
        bufp->chgBit(oldp+313,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_2));
        bufp->chgBit(oldp+314,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_out_valid));
        bufp->chgIData(oldp+315,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem)
                                   ? ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire)
                                       ? vlSelfRef.Top__DOT__core__DOT__lswu__DOT__casez_tmp
                                       : vlSelfRef.Top__DOT__core__DOT__lswu__DOT__data_reg)
                                   : vlSelfRef.Top__DOT__core__DOT__bitsReg_4_result)),32);
        bufp->chgBit(oldp+316,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception) 
                                | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved))));
        bufp->chgIData(oldp+317,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception)
                                   ? vlSelfRef.Top__DOT__core__DOT__bitsReg_4_exception_code
                                   : ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved)
                                       ? (5U | (2U 
                                                & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem)) 
                                                   << 1U)))
                                       : 0U))),32);
        bufp->chgBit(oldp+318,(((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT___need_skip_ref_preserved_T) 
                                | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg))));
        bufp->chgBit(oldp+319,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_load));
        bufp->chgIData(oldp+320,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__casez_tmp),32);
        bufp->chgBit(oldp+321,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire));
        bufp->chgBit(oldp+322,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__b_fire));
        bufp->chgBit(oldp+323,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__valid_reg));
        bufp->chgIData(oldp+324,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__data_reg),32);
        bufp->chgBit(oldp+325,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__signal_reg));
        bufp->chgBit(oldp+326,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg));
        bufp->chgBit(oldp+327,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__ready_go));
        bufp->chgBit(oldp+328,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved_signal_reg));
        bufp->chgBit(oldp+329,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved));
        bufp->chgIData(oldp+330,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__load_data_shifted),32);
        bufp->chgCData(oldp+331,((0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))),4);
        bufp->chgCData(oldp+332,((0x0000000fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                 >> 0x00000014U))),4);
        bufp->chgBit(oldp+333,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_wr_reg) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect))));
        bufp->chgCData(oldp+334,((0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))),4);
        bufp->chgIData(oldp+335,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data),32);
        bufp->chgIData(oldp+336,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_0),32);
        bufp->chgIData(oldp+337,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_1),32);
        bufp->chgIData(oldp+338,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_2),32);
        bufp->chgIData(oldp+339,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_3),32);
        bufp->chgIData(oldp+340,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_4),32);
        bufp->chgIData(oldp+341,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_5),32);
        bufp->chgIData(oldp+342,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_6),32);
        bufp->chgIData(oldp+343,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_7),32);
        bufp->chgIData(oldp+344,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_8),32);
        bufp->chgIData(oldp+345,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_9),32);
        bufp->chgIData(oldp+346,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_10),32);
        bufp->chgIData(oldp+347,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_11),32);
        bufp->chgIData(oldp+348,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_12),32);
        bufp->chgIData(oldp+349,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_13),32);
        bufp->chgIData(oldp+350,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_14),32);
        bufp->chgIData(oldp+351,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_15),32);
        bufp->chgBit(oldp+352,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect));
        bufp->chgIData(oldp+353,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid)
                                   ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target
                                   : vlSelfRef.Top__DOT__core__DOT__bitsReg_5_dnpc)),32);
        bufp->chgIData(oldp+354,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__submit_dnpc),32);
        bufp->chgIData(oldp+355,(((0U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                   ? 8U : ((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                            ? 9U : 
                                           ((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                             ? 0U : 0x0000000bU)))),32);
        bufp->chgIData(oldp+356,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inv)
                                   ? 1U : vlSelfRef.Top__DOT__core__DOT__bitsReg_5_data)),32);
        bufp->chgBit(oldp+357,((((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ebreak) 
                                 | (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inv)) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect))));
        bufp->chgBit(oldp+358,(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awvalid));
        bufp->chgBit(oldp+359,(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wvalid));
        bufp->chgBit(oldp+360,(((~ ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                    | (2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)))) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready))));
        bufp->chgBit(oldp+361,(vlSelfRef.Top__DOT___mem_axi_bvalid));
        bufp->chgCData(oldp+362,(vlSelfRef.Top__DOT___mem_axi_bresp),2);
        bufp->chgCData(oldp+363,(vlSelfRef.Top__DOT__mem__DOT__axi_bid),4);
        bufp->chgBit(oldp+364,(((~ ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                    | (2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)))) 
                                & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready))));
        bufp->chgBit(oldp+365,(vlSelfRef.Top__DOT___mem_axi_rvalid));
        bufp->chgIData(oldp+366,(vlSelfRef.Top__DOT___mem_axi_rdata),32);
        bufp->chgCData(oldp+367,(vlSelfRef.Top__DOT___mem_axi_rresp),2);
        bufp->chgCData(oldp+368,(vlSelfRef.Top__DOT__mem__DOT__axi_rid),4);
        bufp->chgBit(oldp+369,(vlSelfRef.Top__DOT__mem__DOT__axi_rlast));
        bufp->chgBit(oldp+370,(vlSelfRef.Top__DOT__mem__DOT__aw_seen));
        bufp->chgBit(oldp+371,(vlSelfRef.Top__DOT__mem__DOT__w_seen));
        bufp->chgIData(oldp+372,(vlSelfRef.Top__DOT__mem__DOT__awaddr_latched),32);
        bufp->chgCData(oldp+373,(vlSelfRef.Top__DOT__mem__DOT__awid_latched),4);
        bufp->chgIData(oldp+374,(vlSelfRef.Top__DOT__mem__DOT__wdata_latched),32);
        bufp->chgCData(oldp+375,(vlSelfRef.Top__DOT__mem__DOT__wstrb_latched),4);
        bufp->chgBit(oldp+376,((((~ ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                     | (2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)))) 
                                 & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready)) 
                                & (IData)(vlSelfRef.Top__DOT___mem_axi_rvalid))));
        bufp->chgBit(oldp+377,((((~ ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                     | (2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)))) 
                                 & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready)) 
                                & (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid))));
        bufp->chgBit(oldp+378,(((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen) 
                                | ((IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awvalid) 
                                   | ((IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen) 
                                      | ((IData)(vlSelfRef.Top__DOT___mem_axi_bvalid) 
                                         | (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wvalid)))))));
        bufp->chgBit(oldp+379,(vlSelfRef.Top__DOT__xbar__DOT__io_uart_awready));
        bufp->chgBit(oldp+380,(((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid) 
                                & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
                                   & (0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)))));
        bufp->chgBit(oldp+381,(vlSelfRef.Top__DOT__xbar__DOT__io_uart_wready));
        bufp->chgBit(oldp+382,(((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid) 
                                & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg)) 
                                   & (0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)))));
        bufp->chgBit(oldp+383,(((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready))));
        bufp->chgBit(oldp+384,(vlSelfRef.Top__DOT__uart__DOT__bvalid));
        bufp->chgBit(oldp+385,((1U & (~ (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid)))));
        bufp->chgBit(oldp+386,(((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready))));
        bufp->chgBit(oldp+387,(vlSelfRef.Top__DOT__uart__DOT__rvalid));
        bufp->chgBit(oldp+388,(vlSelfRef.Top__DOT__uart__DOT__aw_fire));
        bufp->chgBit(oldp+389,(vlSelfRef.Top__DOT__uart__DOT__w_fire));
        bufp->chgBit(oldp+390,(vlSelfRef.Top__DOT__uart__DOT__signal_reg));
        bufp->chgBit(oldp+391,(vlSelfRef.Top__DOT__uart__DOT__signal_reg_1));
        bufp->chgBit(oldp+392,((((IData)(vlSelfRef.Top__DOT__uart__DOT__aw_fire) 
                                 | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg)) 
                                & ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)) 
                                   & ((IData)(vlSelfRef.Top__DOT__uart__DOT__w_fire) 
                                      | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg_1))))));
        bufp->chgIData(oldp+393,(vlSelfRef.Top__DOT__uart__DOT__wdata_preserved_data_reg),32);
        bufp->chgCData(oldp+394,(vlSelfRef.Top__DOT__uart__DOT__wstrb_preserved_data_reg),4);
        bufp->chgBit(oldp+395,((((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                 & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready)) 
                                & (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid))));
        bufp->chgBit(oldp+396,(vlSelfRef.Top__DOT__uart__DOT__b_fire));
        bufp->chgBit(oldp+397,(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg));
        bufp->chgBit(oldp+398,(vlSelfRef.Top__DOT__xbar__DOT__signal_reg));
        bufp->chgBit(oldp+399,(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg));
        bufp->chgBit(oldp+400,((0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)));
        bufp->chgBit(oldp+401,(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w));
        bufp->chgBit(oldp+402,(vlSelfRef.Top__DOT__xbar__DOT__hit_mem_w));
        bufp->chgCData(oldp+403,(vlSelfRef.Top__DOT__xbar__DOT__read_owner),2);
        bufp->chgCData(oldp+404,(vlSelfRef.Top__DOT__xbar__DOT__write_owner),2);
    }
    bufp->chgBit(oldp+405,(vlSelfRef.clock));
    bufp->chgBit(oldp+406,(vlSelfRef.reset));
    bufp->chgBit(oldp+407,((1U & (~ (IData)(vlSelfRef.reset)))));
}

void VTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_cleanup\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);

    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;

    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
