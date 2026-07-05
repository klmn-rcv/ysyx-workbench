// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop___024root.h"

extern "C" void iringbuf_reset();

void VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_reset_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_reset_TOP\n"); );
    // Body
    iringbuf_reset();
}

extern "C" void iringbuf_before_ifetch(unsigned int pc);

void VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_before_ifetch_TOP(IData/*31:0*/ pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_before_ifetch_TOP\n"); );
    // Body
    unsigned int pc__Vcvt;
    pc__Vcvt = pc;
    iringbuf_before_ifetch(pc__Vcvt);
}

extern "C" void iringbuf_after_ifetch(unsigned int pc, unsigned int inst);

void VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_after_ifetch_TOP(IData/*31:0*/ pc, IData/*31:0*/ inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_after_ifetch_TOP\n"); );
    // Body
    unsigned int pc__Vcvt;
    pc__Vcvt = pc;
    unsigned int inst__Vcvt;
    inst__Vcvt = inst;
    iringbuf_after_ifetch(pc__Vcvt, inst__Vcvt);
}

extern "C" void iringbuf_flush_after_ifetch(unsigned int pc);

void VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_flush_after_ifetch_TOP(IData/*31:0*/ pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_flush_after_ifetch_TOP\n"); );
    // Body
    unsigned int pc__Vcvt;
    pc__Vcvt = pc;
    iringbuf_flush_after_ifetch(pc__Vcvt);
}

extern "C" void ftrace(unsigned int pc, unsigned int target_pc, unsigned char inst_type, int rd, int rs1, int imm);

void VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__idu__DOT__ftrace__DOT__ftrace_TOP(IData/*31:0*/ pc, IData/*31:0*/ target_pc, CData/*7:0*/ inst_type, IData/*31:0*/ rd, IData/*31:0*/ rs1, IData/*31:0*/ imm) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__idu__DOT__ftrace__DOT__ftrace_TOP\n"); );
    // Body
    unsigned int pc__Vcvt;
    pc__Vcvt = pc;
    unsigned int target_pc__Vcvt;
    target_pc__Vcvt = target_pc;
    unsigned char inst_type__Vcvt;
    inst_type__Vcvt = inst_type;
    int rd__Vcvt;
    rd__Vcvt = rd;
    int rs1__Vcvt;
    rs1__Vcvt = rs1;
    int imm__Vcvt;
    imm__Vcvt = imm;
    ftrace(pc__Vcvt, target_pc__Vcvt, inst_type__Vcvt, rd__Vcvt, rs1__Vcvt, imm__Vcvt);
}

extern "C" void sim_halt(int exit_code, unsigned int exit_pc);

void VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__wbu__DOT__halt__DOT__sim_halt_TOP(IData/*31:0*/ exit_code, IData/*31:0*/ exit_pc) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__wbu__DOT__halt__DOT__sim_halt_TOP\n"); );
    // Body
    int exit_code__Vcvt;
    exit_code__Vcvt = exit_code;
    unsigned int exit_pc__Vcvt;
    exit_pc__Vcvt = exit_pc;
    sim_halt(exit_code__Vcvt, exit_pc__Vcvt);
}

extern "C" void itrace(unsigned int pc, unsigned int inst, unsigned int dnpc, char need_skip_ref);

void VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__wbu__DOT__itrace__DOT__itrace_TOP(IData/*31:0*/ pc, IData/*31:0*/ inst, IData/*31:0*/ dnpc, CData/*7:0*/ need_skip_ref) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__wbu__DOT__itrace__DOT__itrace_TOP\n"); );
    // Body
    unsigned int pc__Vcvt;
    pc__Vcvt = pc;
    unsigned int inst__Vcvt;
    inst__Vcvt = inst;
    unsigned int dnpc__Vcvt;
    dnpc__Vcvt = dnpc;
    char need_skip_ref__Vcvt;
    need_skip_ref__Vcvt = need_skip_ref;
    itrace(pc__Vcvt, inst__Vcvt, dnpc__Vcvt, need_skip_ref__Vcvt);
}

extern "C" int pmem_read(unsigned int raddr, unsigned char read_type);

void VTop___024root____Vdpiimwrap_Top__DOT__mem__DOT__pmem_read_TOP(IData/*31:0*/ raddr, CData/*7:0*/ read_type, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__mem__DOT__pmem_read_TOP\n"); );
    // Body
    unsigned int raddr__Vcvt;
    raddr__Vcvt = raddr;
    unsigned char read_type__Vcvt;
    read_type__Vcvt = read_type;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt, read_type__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void pmem_write(unsigned int waddr, int wdata, unsigned char wmask);

void VTop___024root____Vdpiimwrap_Top__DOT__mem__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__mem__DOT__pmem_write_TOP\n"); );
    // Body
    unsigned int waddr__Vcvt;
    waddr__Vcvt = waddr;
    int wdata__Vcvt;
    wdata__Vcvt = wdata;
    unsigned char wmask__Vcvt;
    wmask__Vcvt = wmask;
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval_triggers__ico(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_triggers__ico\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_triggers__act\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clock) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clock__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlUnpacked<CData/*2:0*/, 256> VTop__ConstPool__TABLE_hf6bc0ebc_0;
extern const VlUnpacked<CData/*3:0*/, 32> VTop__ConstPool__TABLE_h2558f6b1_0;

void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_Top__DOT__mem__DOT__pmem_read__9__Vfuncout;
    __Vfunc_Top__DOT__mem__DOT__pmem_read__9__Vfuncout = 0;
    CData/*0:0*/ __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_3;
    __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_3 = 0;
    CData/*0:0*/ __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_1;
    __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_1 = 0;
    CData/*0:0*/ __Vdly__Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg;
    __Vdly__Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg = 0;
    IData/*31:0*/ __Vdly__Top__DOT__core__DOT__csr__DOT__mvendorid;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mvendorid = 0;
    IData/*31:0*/ __Vdly__Top__DOT__core__DOT__csr__DOT__mcycle;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mcycle = 0;
    IData/*31:0*/ __Vdly__Top__DOT__core__DOT__csr__DOT__mcycleh;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mcycleh = 0;
    IData/*31:0*/ __Vdly__Top__DOT__core__DOT__csr__DOT__mcause;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mcause = 0;
    IData/*31:0*/ __Vdly__Top__DOT__core__DOT__csr__DOT__mepc;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mepc = 0;
    IData/*31:0*/ __Vdly__Top__DOT__core__DOT__csr__DOT__mtvec;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mtvec = 0;
    CData/*1:0*/ __Vdly__Top__DOT__core__DOT__csr__DOT__priv;
    __Vdly__Top__DOT__core__DOT__csr__DOT__priv = 0;
    IData/*31:0*/ __Vdly__Top__DOT__core__DOT__csr__DOT__mstatus;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mstatus = 0;
    IData/*31:0*/ __Vdly__Top__DOT__core__DOT__csr__DOT__marchid;
    __Vdly__Top__DOT__core__DOT__csr__DOT__marchid = 0;
    CData/*0:0*/ __Vdly__Top__DOT__xbar__DOT__ar_fire_after_signal_reg;
    __Vdly__Top__DOT__xbar__DOT__ar_fire_after_signal_reg = 0;
    QData/*63:0*/ __Vdly__Top__DOT__clint__DOT__mtime;
    __Vdly__Top__DOT__clint__DOT__mtime = 0;
    QData/*63:0*/ __Vdly__Top__DOT__clint__DOT__mtime_snapshot;
    __Vdly__Top__DOT__clint__DOT__mtime_snapshot = 0;
    // Body
    __Vdly__Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg 
        = vlSelfRef.Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg;
    __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_1 
        = vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_1;
    __Vdly__Top__DOT__clint__DOT__mtime = vlSelfRef.Top__DOT__clint__DOT__mtime;
    __Vdly__Top__DOT__clint__DOT__mtime_snapshot = vlSelfRef.Top__DOT__clint__DOT__mtime_snapshot;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY((((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ar_fire) 
                              & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire))))) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_26050145_AXI4Arbiter.sv:116: Assertion failed in %NTop.arbiter.assert__chisel3_builtin: Assertion failed: boolreg_set_clear: set and clear cannot be true at the same time\n\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name());
                Verilated::runFlushCallbacks();
                VL_STOP_MT("build-npc/ysyx_26050145_AXI4Arbiter.sv", 116, "");
            }
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY((((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_ar_arvalid) 
                              & ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid) 
                                 | (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid)))))) {
                VL_WRITEF_NX("[%0t] %%Error: ysyx_26050145_AXI4Arbiter.sv:120: Assertion failed in %NTop.arbiter.assert__chisel3_builtin_0: Assertion failed at AXI4Arbiter.scala:28\n\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name());
                Verilated::runFlushCallbacks();
                VL_STOP_MT("build-npc/ysyx_26050145_AXI4Arbiter.sv", 120, "");
            }
        }
    }
    if (vlSelfRef.reset) {
        VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_reset_TOP();
    } else if (((~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_need_flush_in_IF)) 
                & (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T))) {
        VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_before_ifetch_TOP(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__pc);
    }
    if (vlSelfRef.reset) {
        VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_reset_TOP();
    } else {
        if (((~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_need_flush_in_IF_or_IW)) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T))) {
            VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_after_ifetch_TOP(vlSelfRef.Top__DOT__core__DOT__bitsReg_pc, 
                                                                                ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire)
                                                                                 ? vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata
                                                                                 : vlSelfRef.Top__DOT__core__DOT__iwu__DOT__data_reg));
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved))) {
            VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__ifu__DOT__iringbuf__DOT__iringbuf_flush_after_ifetch_TOP(vlSelfRef.Top__DOT__core__DOT__bitsReg_pc);
        }
    }
    __Vdly__Top__DOT__xbar__DOT__ar_fire_after_signal_reg 
        = vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg;
    if (VL_UNLIKELY(((1U & (((((IData)(vlSelfRef.Top__DOT__uart__DOT__aw_fire) 
                               | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg)) 
                              & ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)) 
                                 & ((IData)(vlSelfRef.Top__DOT__uart__DOT__w_fire) 
                                    | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg_1)))) 
                             & ((IData)(vlSelfRef.Top__DOT__uart__DOT__w_fire)
                                 ? (1U & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb))
                                 : (1U & (IData)(vlSelfRef.Top__DOT__uart__DOT__wstrb_preserved_data_reg)))) 
                            & (~ (IData)(vlSelfRef.reset))))))) {
        VL_FWRITEF_NX(0x80000002U,"%c",0,8,(0x000000ffU 
                                            & ((IData)(vlSelfRef.Top__DOT__uart__DOT__w_fire)
                                                ? vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata
                                                : vlSelfRef.Top__DOT__uart__DOT__wdata_preserved_data_reg)));
        VL_FFLUSH_I(0x80000002U);
    }
    __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_3 
        = vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_3;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if (((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType)) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_6))) {
            VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__idu__DOT__ftrace__DOT__ftrace_TOP(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc, vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target, 0U, 
                                                                                (0x0000001fU 
                                                                                & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                                                >> 7U)), 0U, vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm);
        }
        if (((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType)) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_6))) {
            VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__idu__DOT__ftrace__DOT__ftrace_TOP(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc, vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target, 1U, 
                                                                                (0x0000001fU 
                                                                                & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                                                >> 7U)), 
                                                                                (0x0000001fU 
                                                                                & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                                                >> 0x0000000fU)), vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm);
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if (vlSelfRef.Top__DOT__core__DOT__validReg_5) {
            VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__wbu__DOT__itrace__DOT__itrace_TOP(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_pc, vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inst, 
                                                                                ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid)
                                                                                 ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target
                                                                                 : vlSelfRef.Top__DOT__core__DOT__bitsReg_5_dnpc), (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_need_skip_ref));
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY((((((IData)(vlSelfRef.Top__DOT__uart__DOT__aw_fire) 
                                | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg)) 
                               & ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)) 
                                  & ((IData)(vlSelfRef.Top__DOT__uart__DOT__w_fire) 
                                     | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg_1)))) 
                              & (IData)(vlSelfRef.Top__DOT__uart__DOT__b_fire))))) {
                VL_WRITEF_NX("[%0t] %%Error: UART.sv:106: Assertion failed in %NTop.uart.assert__chisel3_builtin_0: Assertion failed: boolreg_set_clear: set and clear cannot be true at the same time\n\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name());
                Verilated::runFlushCallbacks();
                VL_STOP_MT("build-npc/UART.sv", 106, "");
            }
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if ((((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ebreak) 
              | (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inv)) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect))) {
            VTop___024root____Vdpiimwrap_Top__DOT__core__DOT__wbu__DOT__halt__DOT__sim_halt_TOP(
                                                                                ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inv)
                                                                                 ? 1U
                                                                                 : vlSelfRef.Top__DOT__core__DOT__bitsReg_5_data), vlSelfRef.Top__DOT__core__DOT__bitsReg_5_pc);
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY((((IData)(vlSelfRef.Top__DOT__clint__DOT__ar_fire) 
                              & (((1U != (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                  & ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                     & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready))) 
                                 & (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid)))))) {
                VL_WRITEF_NX("[%0t] %%Error: CLINT.sv:88: Assertion failed in %NTop.clint.assert__chisel3_builtin: Assertion failed: boolreg_set_clear: set and clear cannot be true at the same time\n\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name());
                Verilated::runFlushCallbacks();
                VL_STOP_MT("build-npc/CLINT.sv", 88, "");
            }
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY((((((IData)(vlSelfRef.Top__DOT__clint__DOT__aw_fire) 
                                | (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg)) 
                               & ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)) 
                                  & ((IData)(vlSelfRef.Top__DOT__clint__DOT__w_fire) 
                                     | (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg_1)))) 
                              & (IData)(vlSelfRef.Top__DOT__clint__DOT__b_fire))))) {
                VL_WRITEF_NX("[%0t] %%Error: CLINT.sv:92: Assertion failed in %NTop.clint.assert__chisel3_builtin_0: Assertion failed: boolreg_set_clear: set and clear cannot be true at the same time\n\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name());
                Verilated::runFlushCallbacks();
                VL_STOP_MT("build-npc/CLINT.sv", 92, "");
            }
        }
    }
    if (((IData)(vlSelfRef.Top__DOT__clint__DOT__ar_fire) 
         & (~ (IData)(vlSelfRef.reset)))) {
        if (vlSymsp->_vm_contextp__->assertOnGet(2, 1)) {
            if (VL_UNLIKELY(((2U != ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)
                                      ? 2U : ((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                               ? 2U
                                               : ((1U 
                                                   == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                                   ? 1U
                                                   : 
                                                  ((0U 
                                                    != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width)) 
                                                   << 1U)))))))) {
                VL_WRITEF_NX("[%0t] %%Error: CLINT.sv:95: Assertion failed in %NTop.clint.assert__chisel3_builtin_1: Assertion failed at CLINT.scala:39\n\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -9,vlSymsp->name());
                Verilated::runFlushCallbacks();
                VL_STOP_MT("build-npc/CLINT.sv", 95, "");
            }
        }
    }
    __Vdly__Top__DOT__core__DOT__csr__DOT__mvendorid 
        = vlSelfRef.Top__DOT__core__DOT__csr__DOT__mvendorid;
    __Vdly__Top__DOT__core__DOT__csr__DOT__marchid 
        = vlSelfRef.Top__DOT__core__DOT__csr__DOT__marchid;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mcycle = vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycle;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mcycleh 
        = vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycleh;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mtvec = vlSelfRef.Top__DOT__core__DOT__csr__DOT__mtvec;
    __Vdly__Top__DOT__core__DOT__csr__DOT__priv = vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mstatus 
        = vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mepc = vlSelfRef.Top__DOT__core__DOT__csr__DOT__mepc;
    __Vdly__Top__DOT__core__DOT__csr__DOT__mcause = vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcause;
    __Vdly__Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT___resp_ex_preserved_T_1)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT___need_skip_ref_preserved_T) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg))));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__resp_ex_preserved_signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_ctrl_ex_found_out) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__resp_ex_preserved_signal_reg))));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved_signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved_signal_reg))));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ex_found_in_preserved_signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT____Vcellinp__ifu__io_ctrl_ex_found_in) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ex_found_in_preserved_signal_reg))));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_2 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_2))));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg))));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__valid_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__valid_reg))));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_1 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_1))));
    vlSelfRef.Top__DOT__clint__DOT__signal_reg = ((1U 
                                                   & (~ (IData)(vlSelfRef.reset))) 
                                                  && ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__b_fire)) 
                                                      & ((IData)(vlSelfRef.Top__DOT__clint__DOT__aw_fire) 
                                                         | (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg))));
    vlSelfRef.Top__DOT__uart__DOT__signal_reg = ((1U 
                                                  & (~ (IData)(vlSelfRef.reset))) 
                                                 && ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__b_fire)) 
                                                     & ((IData)(vlSelfRef.Top__DOT__uart__DOT__aw_fire) 
                                                        | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg))));
    vlSelfRef.Top__DOT__clint__DOT__signal_reg_1 = 
        ((1U & (~ (IData)(vlSelfRef.reset))) && ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__b_fire)) 
                                                 & ((IData)(vlSelfRef.Top__DOT__clint__DOT__w_fire) 
                                                    | (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg_1))));
    vlSelfRef.Top__DOT__uart__DOT__signal_reg_1 = (
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.reset))) 
                                                   && ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__b_fire)) 
                                                       & ((IData)(vlSelfRef.Top__DOT__uart__DOT__w_fire) 
                                                          | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg_1))));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT___GEN)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__ar_fire) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg))));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ar_fire) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__signal_reg))));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_2 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT___GEN)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__w_fire) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_2))));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_1 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT___GEN)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__aw_fire) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_1))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved_signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT___resp_ex_preserved_T_1)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved_signal_reg))));
    vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved_signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read) 
                                                      | (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved_signal_reg))));
    __Vdly__Top__DOT__xbar__DOT__ar_fire_after_signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ 
                                                    ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid) 
                                                     & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready))) 
                                                   & ((IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire) 
                                                      | (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg))));
    vlSelfRef.Top__DOT__xbar__DOT__signal_reg = ((1U 
                                                  & (~ (IData)(vlSelfRef.reset))) 
                                                 && ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__b_fire)) 
                                                     & ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__aw_fire) 
                                                        | (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg))));
    vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__b_fire)) 
                                                   & (((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid) 
                                                       & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wready)) 
                                                      | (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg))));
    vlSelfRef.Top__DOT__uart__DOT__rvalid = ((1U & 
                                              (~ (IData)(vlSelfRef.reset))) 
                                             && ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__r_fire)) 
                                                 & ((IData)(vlSelfRef.Top__DOT__uart__DOT__ar_fire) 
                                                    | (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid))));
    vlSelfRef.Top__DOT__clint__DOT__rvalid = ((1U & 
                                               (~ (IData)(vlSelfRef.reset))) 
                                              && ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__r_fire)) 
                                                  & ((IData)(vlSelfRef.Top__DOT__clint__DOT__ar_fire) 
                                                     | (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid))));
    vlSelfRef.Top__DOT__clint__DOT__bvalid = ((1U & 
                                               (~ (IData)(vlSelfRef.reset))) 
                                              && ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__b_fire)) 
                                                  & ((IData)(vlSelfRef.Top__DOT__clint__DOT__write_req_complete) 
                                                     | (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid))));
    vlSelfRef.Top__DOT__uart__DOT__bvalid = ((1U & 
                                              (~ (IData)(vlSelfRef.reset))) 
                                             && ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__b_fire)) 
                                                 & ((IData)(vlSelfRef.Top__DOT__uart__DOT__write_req_complete) 
                                                    | (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__signal_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT___resp_ex_preserved_T_1)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__b_fire) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__signal_reg))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__valid_reg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT___resp_ex_preserved_T_1)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire) 
                                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__valid_reg))));
    vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire)) 
                                                   & ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ar_fire) 
                                                      | (IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw))));
    if ((1U & (~ ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T) 
                  | (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid)))))) {
        vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg_2 
            = vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target;
    }
    if ((1U & (~ ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T) 
                  | (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid)))))) {
        vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg 
            = vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target;
    }
    if ((1U & (~ ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T) 
                  | (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken)))))) {
        vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg_1 
            = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_target;
    }
    if (vlSelfRef.reset) {
        __Vdly__Top__DOT__core__DOT__csr__DOT__mvendorid = 0x79737978U;
        __Vdly__Top__DOT__core__DOT__csr__DOT__marchid = 0x018d7e61U;
        __Vdly__Top__DOT__core__DOT__csr__DOT__mcycle = 0U;
        __Vdly__Top__DOT__core__DOT__csr__DOT__mcycleh = 0U;
        __Vdly__Top__DOT__core__DOT__csr__DOT__mtvec = 0U;
        __Vdly__Top__DOT__core__DOT__csr__DOT__priv = 3U;
        __Vdly__Top__DOT__core__DOT__csr__DOT__mstatus = 0x00001800U;
        __Vdly__Top__DOT__core__DOT__csr__DOT__mepc = 0U;
        __Vdly__Top__DOT__core__DOT__csr__DOT__mcause = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_need_flush_in_IF = 0U;
        vlSelfRef.Top__DOT__core__DOT__validReg = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rs2_data = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_1_need_flush_in_IF_or_IW = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op = 0U;
        vlSelfRef.Top__DOT__core__DOT__validReg_1 = 0U;
        __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_1 = 0U;
        __Vdly__Top__DOT__clint__DOT__mtime = 0ULL;
        __Vdly__Top__DOT__clint__DOT__mtime_snapshot = 0ULL;
        vlSelfRef.Top__DOT__clint__DOT__rdata = 0U;
        vlSelfRef.Top__DOT__core__DOT__validReg_2 = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_valid = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2 = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_re = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_mret = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_wr_reg = 0U;
        vlSelfRef.Top__DOT__core__DOT__wbu__DOT__submit_dnpc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1 = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_bit_width = 0U;
        vlSelfRef.Top__DOT__core__DOT__validReg_3 = 0U;
        __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_3 = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_raddr = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_sign = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem = 0U;
    } else {
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we) 
             & (0x0f11U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr)))) {
            __Vdly__Top__DOT__core__DOT__csr__DOT__mvendorid 
                = ((vlSelfRef.Top__DOT__core__DOT__csr__DOT__mvendorid 
                    & (~ vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask)) 
                   | (vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue 
                      & vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask));
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we) 
             & (0x0f12U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr)))) {
            __Vdly__Top__DOT__core__DOT__csr__DOT__marchid 
                = ((vlSelfRef.Top__DOT__core__DOT__csr__DOT__marchid 
                    & (~ vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask)) 
                   | (vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue 
                      & vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask));
        }
        __Vdly__Top__DOT__core__DOT__csr__DOT__mcycle 
            = ((IData)(1U) + vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycle);
        if ((0xffffffffU == vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycle)) {
            __Vdly__Top__DOT__core__DOT__csr__DOT__mcycleh 
                = ((IData)(1U) + vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycleh);
        } else if (((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we) 
                    & (0x0b80U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr)))) {
            __Vdly__Top__DOT__core__DOT__csr__DOT__mcycleh 
                = ((vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycleh 
                    & (~ vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask)) 
                   | (vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue 
                      & vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask));
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we) 
             & (0x0305U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr)))) {
            __Vdly__Top__DOT__core__DOT__csr__DOT__mtvec 
                = ((vlSelfRef.Top__DOT__core__DOT__csr__DOT__mtvec 
                    & (~ vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask)) 
                   | (vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue 
                      & vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask));
        }
        if (vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_wb_ex) {
            __Vdly__Top__DOT__core__DOT__csr__DOT__mstatus 
                = ((0xffffe000U & vlSelfRef.Top__DOT__core__DOT__csr__DOT___GEN) 
                   | ((0x07f7U & vlSelfRef.Top__DOT__core__DOT__csr__DOT___GEN) 
                      | ((IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv) 
                         << 0x0000000bU)));
            __Vdly__Top__DOT__core__DOT__csr__DOT__priv = 3U;
            __Vdly__Top__DOT__core__DOT__csr__DOT__mepc 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT___GEN)
                    ? vlSelfRef.Top__DOT__core__DOT__bitsReg_5_pc
                    : 0U);
            __Vdly__Top__DOT__core__DOT__csr__DOT__mcause 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception)
                    ? vlSelfRef.Top__DOT__core__DOT__bitsReg_5_exception_code
                    : ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ecall)
                        ? ((0U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                            ? 8U : ((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                     ? 9U : ((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                              ? 0U : 0x0000000bU)))
                        : 0U));
        } else {
            if (vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_mret) {
                __Vdly__Top__DOT__core__DOT__csr__DOT__priv 
                    = (3U & (vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus 
                             >> 0x0bU));
                __Vdly__Top__DOT__core__DOT__csr__DOT__mstatus 
                    = (0xffffe7ffU & (0x00000080U | 
                                      (0xffffff7fU 
                                       & ((0xf0000000U 
                                           & vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus) 
                                          | ((0x0ffffff7U 
                                              & vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus) 
                                             | (8U 
                                                & (vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus 
                                                   >> 4U)))))));
            } else if (((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we) 
                        & (0x0300U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr)))) {
                __Vdly__Top__DOT__core__DOT__csr__DOT__mstatus 
                    = ((vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus 
                        & (~ vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask)) 
                       | (vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue 
                          & vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask));
            }
            if (((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we) 
                 & (0x0341U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr)))) {
                __Vdly__Top__DOT__core__DOT__csr__DOT__mepc 
                    = ((vlSelfRef.Top__DOT__core__DOT__csr__DOT__mepc 
                        & (~ vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask)) 
                       | (vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue 
                          & vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask));
            }
            if (((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we) 
                 & (0x0342U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr)))) {
                __Vdly__Top__DOT__core__DOT__csr__DOT__mcause 
                    = ((vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcause 
                        & (~ vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask)) 
                       | (vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue 
                          & vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask));
            }
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_ready) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_valid))) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_need_flush_in_IF 
                = vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_need_flush_in_IF;
        }
        if (vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_ready) {
            vlSelfRef.Top__DOT__core__DOT__validReg 
                = vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_valid;
        }
        if (vlSelfRef.Top__DOT__core__DOT___flush_next_cycle_T_6) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rs2_data 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rs2_data;
        }
        if (vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_1_need_flush_in_IF_or_IW 
                = vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_need_flush_in_IF_or_IW;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_ready) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_valid))) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op 
                = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_alu_op;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_valid 
                = ((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                   & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2 
                = ((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType))
                    ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm
                    : ((4U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType))
                        ? 4U : ((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType))
                                 ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data
                                 : ((2U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits))
                                     ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm
                                     : ((4U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits))
                                         ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data
                                         : 0U)))));
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1 
                = (((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                    | (4U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)))
                    ? vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc
                    : ((8U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits))
                        ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rdata1
                        : 0U));
        }
        if (vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_ready) {
            vlSelfRef.Top__DOT__core__DOT__validReg_1 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_valid) 
                   & (~ (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_flush) 
                          | (IData)(vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_1)) 
                         & (~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T)))));
        }
        __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_1 
            = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T)) 
               & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_flush) 
                  | (IData)(vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_1)));
        __Vdly__Top__DOT__clint__DOT__mtime = (1ULL 
                                               + vlSelfRef.Top__DOT__clint__DOT__mtime);
        if (((IData)(vlSelfRef.Top__DOT__clint__DOT__ar_fire) 
             & (0x10000008U == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr))) {
            __Vdly__Top__DOT__clint__DOT__mtime_snapshot 
                = vlSelfRef.Top__DOT__clint__DOT__mtime;
        }
        if (vlSelfRef.Top__DOT__clint__DOT__ar_fire) {
            vlSelfRef.Top__DOT__clint__DOT__rdata = 
                ((0x10000008U == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr)
                  ? (IData)((vlSelfRef.Top__DOT__clint__DOT__mtime 
                             >> 0x20U)) : (IData)(vlSelfRef.Top__DOT__clint__DOT__mtime_snapshot));
        }
        if (vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_ready) {
            vlSelfRef.Top__DOT__core__DOT__validReg_2 
                = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_valid;
        }
        if (((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_out_valid))) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_re 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_re;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_mret 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_mret;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_wr_reg 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_reg;
        }
        if (vlSelfRef.Top__DOT__core__DOT__validReg_5) {
            vlSelfRef.Top__DOT__core__DOT__wbu__DOT__submit_dnpc 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid)
                    ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target
                    : vlSelfRef.Top__DOT__core__DOT__bitsReg_5_dnpc);
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_ready) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_valid))) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_bit_width 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_raddr 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_sign 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_sign;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_mem;
        }
        if (vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_ready) {
            vlSelfRef.Top__DOT__core__DOT__validReg_3 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_valid) 
                   & (~ (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in) 
                          | (IData)(vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_3)) 
                         & (~ (IData)(vlSelfRef.Top__DOT__core__DOT___flush_next_cycle_T_6)))));
        }
        __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_3 
            = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT___flush_next_cycle_T_6)) 
               & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in) 
                  | (IData)(vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_3)));
    }
    if (vlSelfRef.reset) {
        vlSelfRef.Top__DOT___mem_axi_rvalid = 0U;
        vlSelfRef.Top__DOT___mem_axi_rdata = 0U;
        vlSelfRef.Top__DOT___mem_axi_rresp = 0U;
        vlSelfRef.Top__DOT__mem__DOT__axi_rid = 0U;
        vlSelfRef.Top__DOT__mem__DOT__axi_rlast = 0U;
    } else if ((((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                 & ((0x10000000U != vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr) 
                    & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r)) 
                       & (~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg))))) 
                & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_arready))) {
        VTop___024root____Vdpiimwrap_Top__DOT__mem__DOT__pmem_read_TOP(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr, 
                                                                       ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)
                                                                         ? 0U
                                                                         : 1U), __Vfunc_Top__DOT__mem__DOT__pmem_read__9__Vfuncout);
        vlSelfRef.Top__DOT___mem_axi_rdata = __Vfunc_Top__DOT__mem__DOT__pmem_read__9__Vfuncout;
        vlSelfRef.Top__DOT___mem_axi_rresp = 0U;
        vlSelfRef.Top__DOT__mem__DOT__axi_rid = (1U 
                                                 & (~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)));
        vlSelfRef.Top__DOT__mem__DOT__axi_rlast = 1U;
        vlSelfRef.Top__DOT___mem_axi_rvalid = 1U;
    } else if (vlSelfRef.Top__DOT__mem__DOT__r_fire) {
        vlSelfRef.Top__DOT___mem_axi_rvalid = 0U;
        vlSelfRef.Top__DOT__mem__DOT__axi_rlast = 0U;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.Top__DOT__core__DOT__validReg_4 = 0U;
    } else if (vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_ready) {
        vlSelfRef.Top__DOT__core__DOT__validReg_4 = vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_valid;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.Top__DOT__mem__DOT__aw_seen = 0U;
        vlSelfRef.Top__DOT__mem__DOT__w_seen = 0U;
        vlSelfRef.Top__DOT__mem__DOT__awaddr_latched = 0U;
        vlSelfRef.Top__DOT__mem__DOT__awid_latched = 0U;
        vlSelfRef.Top__DOT__mem__DOT__wdata_latched = 0U;
        vlSelfRef.Top__DOT__mem__DOT__wstrb_latched = 0U;
        vlSelfRef.Top__DOT___mem_axi_bvalid = 0U;
        vlSelfRef.Top__DOT___mem_axi_bresp = 0U;
        vlSelfRef.Top__DOT__mem__DOT__axi_bid = 0U;
    } else {
        if (vlSelfRef.Top__DOT__mem__DOT__b_fire) {
            vlSelfRef.Top__DOT___mem_axi_bvalid = 0U;
        }
        if (vlSelfRef.Top__DOT__mem__DOT__aw_fire) {
            vlSelfRef.Top__DOT__mem__DOT__awaddr_latched 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result;
            vlSelfRef.Top__DOT__mem__DOT__awid_latched = 1U;
            vlSelfRef.Top__DOT__mem__DOT__aw_seen = 1U;
        }
        if (vlSelfRef.Top__DOT__mem__DOT__w_fire) {
            vlSelfRef.Top__DOT__mem__DOT__wdata_latched 
                = vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata;
            vlSelfRef.Top__DOT__mem__DOT__wstrb_latched 
                = vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb;
            vlSelfRef.Top__DOT__mem__DOT__w_seen = 1U;
        }
        if (vlSelfRef.Top__DOT__mem__DOT__write_req_complete) {
            VTop___024root____Vdpiimwrap_Top__DOT__mem__DOT__pmem_write_TOP(vlSelfRef.Top__DOT__mem__DOT__write_addr, vlSelfRef.Top__DOT__mem__DOT__write_data, (IData)(vlSelfRef.Top__DOT__mem__DOT__write_strb));
            vlSelfRef.Top__DOT___mem_axi_bresp = 0U;
            vlSelfRef.Top__DOT__mem__DOT__axi_bid = vlSelfRef.Top__DOT__mem__DOT__write_id;
            vlSelfRef.Top__DOT___mem_axi_bvalid = 1U;
            vlSelfRef.Top__DOT__mem__DOT__aw_seen = 0U;
            vlSelfRef.Top__DOT__mem__DOT__w_seen = 0U;
        }
    }
    if (vlSelfRef.reset) {
        vlSelfRef.Top__DOT__xbar__DOT__write_owner = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_expect_0 = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_we = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_15 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_4 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_14 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_13 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_2 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_12 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_8 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_0 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_1 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_3 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_5 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_6 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_7 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_9 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_10 = 0U;
        vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_11 = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_need_skip_ref = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inst = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ebreak = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inv = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_data = 0U;
        vlSelfRef.Top__DOT__xbar__DOT__read_owner = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_pc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ecall = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_exception_code = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rs2_data = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_re = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_mret = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_reg = 0U;
        vlSelfRef.Top__DOT__core__DOT__validReg_5 = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_dnpc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_sign = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_mem = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_we = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_inst = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_ebreak = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_inv = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_result = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_pc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_ecall = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_wmask = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_wvalue = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_addr = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_exception_code = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_re = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_mret = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_reg = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_dnpc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_bit_width = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_sign = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_mem = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_we = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_inst = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_ebreak = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_inv = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_pc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_ecall = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_wmask = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_wvalue = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_addr = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_exception_code = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_has_exception = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_re = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_mret = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_reg = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_dnpc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_we = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inst = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ebreak = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inv = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_pc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ecall = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wmask = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wvalue = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_addr = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_exception_code = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd_mem = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_has_exception = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_target = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_dnpc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_1_exception_code = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_1_has_exception = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_1_dnpc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_pc = 0U;
        vlSelfRef.Top__DOT__core__DOT__bitsReg_dnpc = 0U;
        vlSelfRef.Top__DOT__core__DOT__ifu__DOT__pc = 0x80000000U;
    } else {
        if (vlSelfRef.Top__DOT__core__DOT__lsu__DOT__aw_fire) {
            vlSelfRef.Top__DOT__xbar__DOT__write_owner 
                = ((0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)
                    ? 1U : ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w) 
                            << 1U));
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (0x0000000fU == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_15 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (4U == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_4 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (0x0eU == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_14 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (0x0dU == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_13 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (2U == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_2 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (0x0cU == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_12 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (8U == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_8 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (~ (0U != (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd)))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_0 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (1U == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_1 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (3U == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_3 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (5U == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_5 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (6U == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_6 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (7U == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_7 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (9U == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_9 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (0x0aU == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_10 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__regfile__DOT___GEN) 
             & (0x0bU == (0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))))) {
            vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_11 
                = vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data;
        }
        if (((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_out_valid))) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_we 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_we;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_need_skip_ref 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT___need_skip_ref_preserved_T) 
                   | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg));
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inst 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_inst;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ebreak 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_ebreak;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inv 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_inv;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_data 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem)
                    ? ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire)
                        ? vlSelfRef.Top__DOT__core__DOT__lswu__DOT__casez_tmp
                        : vlSelfRef.Top__DOT__core__DOT__lswu__DOT__data_reg)
                    : vlSelfRef.Top__DOT__core__DOT__bitsReg_4_result);
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_pc 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_pc;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ecall 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_ecall;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception) 
                   | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved));
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_wmask;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_wvalue;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_addr;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_exception_code 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception)
                    ? vlSelfRef.Top__DOT__core__DOT__bitsReg_4_exception_code
                    : ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved)
                        ? (5U | (2U & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem)) 
                                       << 1U))) : 0U));
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_dnpc 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_dnpc;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd;
        }
        if (vlSelfRef.Top__DOT__xbar__DOT__ar_fire) {
            vlSelfRef.Top__DOT__xbar__DOT__read_owner 
                = ((0x10000000U == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr)
                    ? 1U : ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r) 
                            << 1U));
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_ready) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_valid))) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_re 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_re;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_mret 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_mret;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_reg 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_reg;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_we 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_we;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_inst 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_inst;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_ebreak 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_ebreak;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_inv 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_inv;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_result 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_pc 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_pc;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_ecall 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_ecall;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_wmask 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_wmask;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_wvalue 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_wvalue;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_addr 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_addr;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_exception_code 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_exception_code;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_has_exception;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_dnpc 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_dnpc;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd;
        }
        if ((1U & (~ (IData)(vlSelfRef.reset)))) {
            vlSelfRef.Top__DOT__core__DOT__validReg_5 
                = vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_out_valid;
        }
        if (vlSelfRef.Top__DOT__core__DOT___flush_next_cycle_T_6) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_bit_width;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_sign 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_sign;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_mem 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_mem;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_re 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_re;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_mret 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_mret;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_reg 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_reg;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_we 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_we;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_inst 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inst;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_ebreak 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ebreak;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_inv 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inv;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result 
                = vlSelfRef.Top__DOT__core__DOT__exu__DOT__alu__DOT__io_out_result;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_pc 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_pc;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_ecall 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ecall;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_wmask 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wmask;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_wvalue 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wvalue;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_addr 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_addr;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_exception_code 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_exception_code;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd_mem;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_has_exception 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_has_exception;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_dnpc 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken)
                    ? vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_target
                    : vlSelfRef.Top__DOT__core__DOT__bitsReg_2_dnpc);
            vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd;
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_ready) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_valid))) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_expect_0 
                = ((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                   & ((0U == (7U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                    >> 0x0000000cU))) 
                      | ((5U == (7U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                       >> 0x0000000cU))) 
                         | (7U == (7U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                         >> 0x0000000cU))))));
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rs2_data 
                = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_bit_width 
                = (((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_6) 
                    | (0x0067U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)))
                    ? 2U : ((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                             ? 0U : ((0x0083U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                      ? 1U : ((0x0103U 
                                               == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                               ? 2U
                                               : ((0x0203U 
                                                   == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                                   ? 0U
                                                   : 
                                                  ((0x0283U 
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
                                                       : 2U)))))))));
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_sign 
                = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_12)) 
                   & ((0x000001b3U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                      | ((~ ((0x00000233U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                             | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_10) 
                                | ((0x00000333U == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                                   | ((0x000003b3U 
                                       == vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN) 
                                      | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_9)))))) 
                         & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_7) 
                            | ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_4)) 
                               & ((0x0193U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)) 
                                  | ((~ ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_7) 
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
                                     & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_1))))))));
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_mem 
                = ((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                   & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_re 
                = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_mret 
                = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_mret;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_reg 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits) 
                   & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
            if (vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re) {
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_we 
                    = ((1U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                     >> 0x0000000cU))) 
                       | (((2U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                         >> 0x0000000cU))) 
                           | (3U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                           >> 0x0000000cU)))) 
                          & (0U != (0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                   >> 0x0000000fU)))));
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inst 
                    = vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ebreak 
                    = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ebreak;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inv 
                    = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_inv;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_pc 
                    = vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ecall 
                    = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ecall;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wmask 
                    = ((0U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                     >> 0x0000000cU)))
                        ? 0U : ((1U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                              >> 0x0000000cU)))
                                 ? 0xffffffffU : vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1));
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wvalue 
                    = ((1U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                     >> 0x0000000cU)))
                        ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1
                        : (- (IData)((2U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                   >> 0x0000000cU))))));
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_addr 
                    = (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                       >> 0x00000014U);
            } else {
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_we = 0U;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inst 
                    = vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ebreak 
                    = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ebreak;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inv 
                    = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_inv;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_pc 
                    = vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ecall 
                    = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ecall;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wmask = 0U;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wvalue = 0U;
                vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_addr = 0U;
            }
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_exception_code 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_1_exception_code;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd_mem 
                = ((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                   & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_has_exception 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_1_has_exception;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_target 
                = vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_br_target;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_dnpc 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid)
                    ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target
                    : vlSelfRef.Top__DOT__core__DOT__bitsReg_1_dnpc);
            vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd 
                = (0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                  >> 7U));
        }
        if (vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_pc;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_1_exception_code 
                = vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_has_exception;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_1_has_exception 
                = vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_has_exception;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_1_dnpc 
                = vlSelfRef.Top__DOT__core__DOT__bitsReg_dnpc;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                = ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire)
                    ? vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata
                    : vlSelfRef.Top__DOT__core__DOT__iwu__DOT__data_reg);
        }
        if (((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_ready) 
             & (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_valid))) {
            vlSelfRef.Top__DOT__core__DOT__bitsReg_pc 
                = vlSelfRef.Top__DOT__core__DOT__ifu__DOT__pc;
            vlSelfRef.Top__DOT__core__DOT__bitsReg_dnpc 
                = vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_dnpc;
        }
        if (vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T) {
            vlSelfRef.Top__DOT__core__DOT__ifu__DOT__pc 
                = vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_dnpc;
        }
    }
    if (vlSelfRef.Top__DOT__uart__DOT__b_fire) {
        vlSelfRef.Top__DOT__uart__DOT__wstrb_preserved_data_reg = 0U;
        vlSelfRef.Top__DOT__uart__DOT__wdata_preserved_data_reg = 0U;
    } else if (vlSelfRef.Top__DOT__uart__DOT__w_fire) {
        vlSelfRef.Top__DOT__uart__DOT__wstrb_preserved_data_reg 
            = vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb;
        vlSelfRef.Top__DOT__uart__DOT__wdata_preserved_data_reg 
            = vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata;
    }
    vlSelfRef.Top__DOT__core__DOT__csr__DOT__mvendorid 
        = __Vdly__Top__DOT__core__DOT__csr__DOT__mvendorid;
    vlSelfRef.Top__DOT__core__DOT__csr__DOT__marchid 
        = __Vdly__Top__DOT__core__DOT__csr__DOT__marchid;
    vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycle 
        = __Vdly__Top__DOT__core__DOT__csr__DOT__mcycle;
    vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycleh 
        = __Vdly__Top__DOT__core__DOT__csr__DOT__mcycleh;
    vlSelfRef.Top__DOT__core__DOT__csr__DOT__mtvec 
        = __Vdly__Top__DOT__core__DOT__csr__DOT__mtvec;
    vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus 
        = __Vdly__Top__DOT__core__DOT__csr__DOT__mstatus;
    vlSelfRef.Top__DOT__core__DOT__csr__DOT__mepc = __Vdly__Top__DOT__core__DOT__csr__DOT__mepc;
    vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv = __Vdly__Top__DOT__core__DOT__csr__DOT__priv;
    vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcause 
        = __Vdly__Top__DOT__core__DOT__csr__DOT__mcause;
    vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_1 
        = __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_1;
    vlSelfRef.Top__DOT__clint__DOT__mtime = __Vdly__Top__DOT__clint__DOT__mtime;
    vlSelfRef.Top__DOT__clint__DOT__mtime_snapshot 
        = __Vdly__Top__DOT__clint__DOT__mtime_snapshot;
    vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_3 
        = __Vdly__Top__DOT__core__DOT__flush_preserved_signal_reg_3;
    vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg 
        = __Vdly__Top__DOT__xbar__DOT__ar_fire_after_signal_reg;
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_mem_ar_arvalid 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & (~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__signal_reg))));
    vlSelfRef.Top__DOT__xbar__DOT__io_clint_awready 
        = (1U & ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)) 
                 & (~ (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg))));
    vlSelfRef.Top__DOT__xbar__DOT__io_clint_wready 
        = (1U & ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)) 
                 & (~ (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg_1))));
    vlSelfRef.Top__DOT__xbar__DOT__io_uart_awready 
        = (1U & ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)) 
                 & (~ (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg))));
    vlSelfRef.Top__DOT__xbar__DOT__io_uart_wready = 
        (1U & ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)) 
               & (~ (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg_1))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg 
        = __Vdly__Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg;
    vlSelfRef.Top__DOT__core__DOT__csr__DOT___GEN = 
        ((0xffffff7fU & vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus) 
         | (0x00000080U & (vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus 
                           << 4U)));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rready 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__valid_reg)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg));
    vlSelfRef.Top__DOT__mem__DOT____VdfgRegularize_hf43a80a8_0_2 
        = (1U & ((~ (IData)(vlSelfRef.reset)) & (~ (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid))));
    if ((1U & (~ ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT___resp_ex_preserved_T_1) 
                  | (~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire)))))) {
        vlSelfRef.Top__DOT__core__DOT__lswu__DOT__data_reg 
            = vlSelfRef.Top__DOT__core__DOT__lswu__DOT__casez_tmp;
    }
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
    vlSelfRef.__VdfgRegularize_he50b618e_0_5 = ((1U 
                                                 != (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                                & ((2U 
                                                    != (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                                   & (3U 
                                                      == (IData)(vlSelfRef.Top__DOT___mem_axi_rresp))));
    vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready = 
        ((~ (IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen)) 
         & (IData)(vlSelfRef.Top__DOT__mem__DOT____VdfgRegularize_hf43a80a8_0_2));
    vlSelfRef.Top__DOT__xbar__DOT__io_mem_wready = 
        ((~ (IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen)) 
         & (IData)(vlSelfRef.Top__DOT__mem__DOT____VdfgRegularize_hf43a80a8_0_2));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__load_data_shifted 
        = (((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
             ? 0U : vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata) 
           >> (0x00000018U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_4_raddr 
                              << 3U)));
    vlSelfRef.Top__DOT__core__DOT__wbu__DOT___GEN = 
        ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ecall) 
         | (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception));
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
    vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_5));
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
    vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_wb_ex 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT___GEN) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_5));
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
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_wb_ex)
            ? (0xfffffffcU & vlSelfRef.Top__DOT__core__DOT__csr__DOT__mtvec)
            : vlSelfRef.Top__DOT__core__DOT__csr__DOT__mepc);
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_load 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem) 
           & ((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4) 
              & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__signal_reg)) 
                 & (~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception)))));
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_wb_ex) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_mret));
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
    vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w = ((0x10000004U 
                                                   == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result) 
                                                  | (0x10000008U 
                                                     == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_r_rready 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_load) 
           & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__valid_reg)) 
              & (~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception))));
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
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wready 
        = ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg)) 
           & ((0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)
               ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_uart_wready)
               : ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)
                   ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_clint_wready)
                   : (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wready))));
    vlSelfRef.Top__DOT__xbar__DOT__hit_mem_w = (1U 
                                                & (~ 
                                                   ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w) 
                                                    | (0x10000000U 
                                                       == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result))));
    vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire 
        = (((~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)) 
            & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_r_rready));
    vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready 
        = ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
            ? (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rready)
            : (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_r_rready));
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
    if ((1U & (~ ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T) 
                  | (~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire)))))) {
        vlSelfRef.Top__DOT__core__DOT__iwu__DOT__data_reg 
            = vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata;
    }
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata 
        = ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
            ? vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata
            : 0U);
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
    vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0 
        = ((0x00000380U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                           >> 5U)) | (0x0000007fU & vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst));
    vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_ar_arvalid) 
           | (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_2)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT____VdfgRegularize_h086239f3_0_1));
    vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid 
        = ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_1)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT____VdfgRegularize_h086239f3_0_1));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire 
        = (((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid) 
            & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rready));
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
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire_preserved 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__valid_reg));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_ctrl_ex_found_out 
        = (((2U == ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
                     ? (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp)
                     : 0U)) | ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw) 
                               & (IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_5))) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire));
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
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_valid 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__validReg) 
           & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire_preserved));
    vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_has_exception 
        = ((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_ctrl_ex_found_out) 
           | (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__resp_ex_preserved_signal_reg));
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
    vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr 
        = ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)
            ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__pc
            : vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result);
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
    vlSelfRef.Top__DOT__uart__DOT__ar_fire = ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid)) 
                                              & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                                 & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                                    & (0x10000000U 
                                                       == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr))));
    vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r = ((0x10000004U 
                                                   == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr) 
                                                  | (0x10000008U 
                                                     == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr));
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
    vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target 
        = ((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType))
            ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_br_target
            : (0xfffffffeU & (vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm 
                              + vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rdata1)));
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
