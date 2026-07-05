// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

void VTop___024root___ico_sequent__TOP__0(VTop___024root* vlSelf);

void VTop___024root___eval_ico(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_ico\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VTop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void VTop___024root___ico_sequent__TOP__0(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT___resp_ex_preserved_T_1 
        = ((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_out_valid));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_ready 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4)) 
                                                 | ((~ (IData)(vlSelfRef.reset)) 
                                                    & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__ready_go)))));
    vlSelfRef.Top__DOT__xbar__DOT__io_mem_arready = 
        (1U & ((~ (IData)(vlSelfRef.reset)) & (~ ((IData)(vlSelfRef.Top__DOT___mem_axi_rvalid) 
                                                  | ((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen) 
                                                     | ((IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awvalid) 
                                                        | ((IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen) 
                                                           | ((IData)(vlSelfRef.Top__DOT___mem_axi_bvalid) 
                                                              | (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wvalid)))))))));
    vlSelfRef.Top__DOT__mem__DOT____VdfgRegularize_hf43a80a8_0_2 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & (~ (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid))));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_mem_ar_arvalid 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__signal_reg))));
    vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready = 
        ((~ (IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen)) 
         & (IData)(vlSelfRef.Top__DOT__mem__DOT____VdfgRegularize_hf43a80a8_0_2));
    vlSelfRef.Top__DOT__xbar__DOT__io_mem_wready = 
        ((~ (IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen)) 
         & (IData)(vlSelfRef.Top__DOT__mem__DOT____VdfgRegularize_hf43a80a8_0_2));
    vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read 
        = ((~ (((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem) 
                & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid)) 
               | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_load))) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_mem_ar_arvalid));
    vlSelfRef.Top__DOT__mem__DOT__aw_fire = ((IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awvalid) 
                                             & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__aw_fire 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid) 
           & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
              & ((0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)
                  ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_uart_awready)
                  : ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)
                      ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_clint_awready)
                      : (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready)))));
    vlSelfRef.Top__DOT__mem__DOT__w_fire = ((IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wvalid) 
                                            & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wready));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wready 
        = ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg)) 
           & ((0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)
               ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_uart_wready)
               : ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)
                   ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_clint_wready)
                   : (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wready))));
    vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_ar_arvalid) 
           | (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read));
    vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved 
        = ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read) 
           | (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved_signal_reg));
    if (vlSelfRef.Top__DOT__mem__DOT__aw_fire) {
        vlSelfRef.Top__DOT__mem__DOT__write_id = 1U;
        vlSelfRef.Top__DOT__mem__DOT__write_addr = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result;
    } else {
        vlSelfRef.Top__DOT__mem__DOT__write_id = vlSelfRef.Top__DOT__mem__DOT__awid_latched;
        vlSelfRef.Top__DOT__mem__DOT__write_addr = vlSelfRef.Top__DOT__mem__DOT__awaddr_latched;
    }
    if (vlSelfRef.Top__DOT__mem__DOT__w_fire) {
        vlSelfRef.Top__DOT__mem__DOT__write_data = vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata;
        vlSelfRef.Top__DOT__mem__DOT__write_strb = vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb;
    } else {
        vlSelfRef.Top__DOT__mem__DOT__write_data = vlSelfRef.Top__DOT__mem__DOT__wdata_latched;
        vlSelfRef.Top__DOT__mem__DOT__write_strb = vlSelfRef.Top__DOT__mem__DOT__wstrb_latched;
    }
    vlSelfRef.Top__DOT__mem__DOT__write_req_complete 
        = (((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen) 
            | (IData)(vlSelfRef.Top__DOT__mem__DOT__aw_fire)) 
           & ((~ (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid)) 
              & ((IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen) 
                 | (IData)(vlSelfRef.Top__DOT__mem__DOT__w_fire))));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__w_fire 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wready));
    vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr 
        = ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)
            ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__pc
            : vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result);
    vlSelfRef.Top__DOT__uart__DOT__ar_fire = ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid)) 
                                              & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                                 & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                                    & (0x10000000U 
                                                       == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr))));
    vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r = ((0x10000004U 
                                                   == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr) 
                                                  | (0x10000008U 
                                                     == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr));
    vlSelfRef.Top__DOT__clint__DOT__ar_fire = ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid)) 
                                               & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                                  & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                                     & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r))));
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

void VTop___024root___eval_triggers__ico(VTop___024root* vlSelf);

bool VTop___024root___eval_phase__ico(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__ico\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VTop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VTop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf);

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf);

bool VTop___024root___eval_phase__act(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__act\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VTop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VTop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VTop___024root___eval_phase__nba(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_phase__nba\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VTop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("build-npc/Top.sv", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VTop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VTop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("build-npc/Top.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("build-npc/Top.sv", 2, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VTop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VTop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_debug_assertions\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clock & 0xfeU)))) {
        Verilated::overWidthError("clock");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
}
#endif  // VL_DEBUG
