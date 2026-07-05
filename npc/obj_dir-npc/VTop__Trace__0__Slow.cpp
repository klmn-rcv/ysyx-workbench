// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


VL_ATTR_COLD void VTop___024root__trace_init_sub__TOP__0(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_init_sub__TOP__0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("Top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("arbiter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"io_if_iw_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_if_iw_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"io_if_iw_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+85,0,"io_if_iw_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"io_if_iw_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"io_if_iw_rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+88,0,"io_if_iw_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+3,0,"io_ls_lsw_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"io_ls_lsw_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_ls_lsw_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"io_ls_lsw_awsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+4,0,"io_ls_lsw_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"io_ls_lsw_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"io_ls_lsw_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"io_ls_lsw_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+95,0,"io_ls_lsw_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"io_ls_lsw_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"io_ls_lsw_bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+5,0,"io_ls_lsw_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"io_ls_lsw_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_ls_lsw_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"io_ls_lsw_arsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+99,0,"io_ls_lsw_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"io_ls_lsw_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"io_ls_lsw_rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+102,0,"io_ls_lsw_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+103,0,"io_ls_lsw_load",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"io_xbar_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"io_xbar_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_xbar_awaddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"io_xbar_awsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+4,0,"io_xbar_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"io_xbar_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"io_xbar_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"io_xbar_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+95,0,"io_xbar_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"io_xbar_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"io_xbar_bresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+6,0,"io_xbar_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"io_xbar_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"io_xbar_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"io_xbar_arid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+10,0,"io_xbar_arsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+104,0,"io_xbar_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"io_xbar_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"io_xbar_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+107,0,"io_xbar_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+108,0,"io_xbar_r_need_skip_ref",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"io_xbar_b_need_skip_ref",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"io_ls_lsw_r_need_skip_ref",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"io_ls_lsw_b_need_skip_ref",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"grant_if_iw_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"grant_if_iw_read_preserved_signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"grant_if_iw_read_preserved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"read_owner_is_if_iw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"io_if_iw_arready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"io_if_iw_rvalid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"if_iw_ar_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"if_iw_r_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("clint", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"io_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"io_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"io_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"io_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"io_axi_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"io_axi_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"io_axi_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"io_axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"io_axi_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"io_axi_arsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+120,0,"io_axi_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"io_axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"io_axi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+121,0,"io_r_need_skip_ref",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"io_axi_wready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"io_axi_awready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+123,0,"mtime",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+125,0,"mtime_snapshot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+122,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+127,0,"aw_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"w_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"signal_reg_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"write_req_complete",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"ar_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"r_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"b_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"io_inst_mem_axi_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_inst_mem_axi_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"io_inst_mem_axi_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+85,0,"io_inst_mem_axi_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"io_inst_mem_axi_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"io_inst_mem_axi_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+88,0,"io_inst_mem_axi_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+3,0,"io_data_mem_axi_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"io_data_mem_axi_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_data_mem_axi_awaddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"io_data_mem_axi_awsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+4,0,"io_data_mem_axi_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"io_data_mem_axi_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"io_data_mem_axi_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"io_data_mem_axi_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+95,0,"io_data_mem_axi_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"io_data_mem_axi_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"io_data_mem_axi_bresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+5,0,"io_data_mem_axi_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"io_data_mem_axi_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_data_mem_axi_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"io_data_mem_axi_arsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+99,0,"io_data_mem_axi_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"io_data_mem_axi_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"io_data_mem_axi_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+102,0,"io_data_mem_axi_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+103,0,"io_ls_lsw_load",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"io_data_mem_r_need_skip_ref",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"io_data_mem_b_need_skip_ref",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"validReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"bitsReg_need_flush_in_IF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"bitsReg_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"bitsReg_dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+138,0,"validReg_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"bitsReg_1_need_flush_in_IF_or_IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+140,0,"bitsReg_1_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"bitsReg_1_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+142,0,"bitsReg_1_dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+143,0,"bitsReg_1_has_exception",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"bitsReg_1_exception_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+145,0,"flush_preserved_signal_reg_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"validReg_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+147,0,"bitsReg_2_alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+148,0,"bitsReg_2_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+149,0,"bitsReg_2_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"bitsReg_2_src2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"bitsReg_2_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+152,0,"bitsReg_2_wr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"bitsReg_2_rd_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"bitsReg_2_wr_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+155,0,"bitsReg_2_bit_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+156,0,"bitsReg_2_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"bitsReg_2_br_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"bitsReg_2_br_expect_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+159,0,"bitsReg_2_br_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"bitsReg_2_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"bitsReg_2_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"bitsReg_2_dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"bitsReg_2_csrReq_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+164,0,"bitsReg_2_csrReq_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"bitsReg_2_csrReq_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+166,0,"bitsReg_2_csrReq_wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"bitsReg_2_csrReq_wvalue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+168,0,"bitsReg_2_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+169,0,"bitsReg_2_inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"bitsReg_2_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+171,0,"bitsReg_2_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+172,0,"bitsReg_2_has_exception",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+173,0,"bitsReg_2_exception_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+174,0,"validReg_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"bitsReg_3_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"bitsReg_3_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+176,0,"bitsReg_3_wr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+177,0,"bitsReg_3_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+178,0,"bitsReg_3_rd_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"bitsReg_3_wr_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+180,0,"bitsReg_3_bit_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+181,0,"bitsReg_3_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+182,0,"bitsReg_3_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"bitsReg_3_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"bitsReg_3_dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"bitsReg_3_csrReq_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+186,0,"bitsReg_3_csrReq_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"bitsReg_3_csrReq_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+188,0,"bitsReg_3_csrReq_wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"bitsReg_3_csrReq_wvalue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+190,0,"bitsReg_3_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"bitsReg_3_inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"bitsReg_3_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"bitsReg_3_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+194,0,"bitsReg_3_has_exception",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+195,0,"bitsReg_3_exception_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+196,0,"flush_preserved_signal_reg_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+197,0,"validReg_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+198,0,"bitsReg_4_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"bitsReg_4_bit_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+200,0,"bitsReg_4_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"bitsReg_4_rd_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"bitsReg_4_wr_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+203,0,"bitsReg_4_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+204,0,"bitsReg_4_wr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+205,0,"bitsReg_4_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+206,0,"bitsReg_4_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"bitsReg_4_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"bitsReg_4_dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+209,0,"bitsReg_4_csrReq_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+210,0,"bitsReg_4_csrReq_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"bitsReg_4_csrReq_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+212,0,"bitsReg_4_csrReq_wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+213,0,"bitsReg_4_csrReq_wvalue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+214,0,"bitsReg_4_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+215,0,"bitsReg_4_inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"bitsReg_4_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+217,0,"bitsReg_4_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+218,0,"bitsReg_4_has_exception",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+219,0,"bitsReg_4_exception_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+220,0,"validReg_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+221,0,"bitsReg_5_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"bitsReg_5_wr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"bitsReg_5_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+224,0,"bitsReg_5_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+225,0,"bitsReg_5_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+226,0,"bitsReg_5_dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+227,0,"bitsReg_5_csrReq_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+228,0,"bitsReg_5_csrReq_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+229,0,"bitsReg_5_csrReq_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+230,0,"bitsReg_5_csrReq_wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+231,0,"bitsReg_5_csrReq_wvalue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+232,0,"bitsReg_5_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+233,0,"bitsReg_5_inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+234,0,"bitsReg_5_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+235,0,"bitsReg_5_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"bitsReg_5_has_exception",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+237,0,"bitsReg_5_exception_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+238,0,"bitsReg_5_need_skip_ref",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+227,0,"io_in_req_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+239,0,"io_in_req_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+230,0,"io_in_req_wmask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+231,0,"io_in_req_wvalue",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+240,0,"io_in_wb_ex",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+241,0,"io_in_wb_cause",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"io_in_wb_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+243,0,"io_in_mret",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+244,0,"io_out_resp_rvalue",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+245,0,"io_out_priv",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+246,0,"io_out_mtvec",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+247,0,"io_out_mepc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+245,0,"priv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+248,0,"mstatus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+246,0,"mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+247,0,"mepc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+249,0,"mcause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+250,0,"mcycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+251,0,"mcycleh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"mvendorid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+253,0,"marchid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+254,0,"hits_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"hits_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+256,0,"hits_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+257,0,"hits_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+258,0,"hits_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+259,0,"hits_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+260,0,"hits_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("exu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"io_in_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"io_in_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+147,0,"io_in_bits_alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+148,0,"io_in_bits_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+149,0,"io_in_bits_src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"io_in_bits_src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"io_in_bits_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+152,0,"io_in_bits_wr_reg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"io_in_bits_rd_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"io_in_bits_wr_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+155,0,"io_in_bits_bit_width",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+156,0,"io_in_bits_sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"io_in_bits_br_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"io_in_bits_br_expect_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+159,0,"io_in_bits_br_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"io_in_bits_inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"io_in_bits_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"io_in_bits_dnpc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"io_in_bits_csrReq_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+164,0,"io_in_bits_csrReq_re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"io_in_bits_csrReq_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+166,0,"io_in_bits_csrReq_wmask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"io_in_bits_csrReq_wvalue",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+168,0,"io_in_bits_ebreak",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+169,0,"io_in_bits_inv",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"io_in_bits_ecall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+171,0,"io_in_bits_mret",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+172,0,"io_in_bits_has_exception",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+173,0,"io_in_bits_exception_code",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+17,0,"io_out_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"io_out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+262,0,"io_out_bits_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"io_out_bits_rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+152,0,"io_out_bits_wr_reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+148,0,"io_out_bits_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+153,0,"io_out_bits_rd_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"io_out_bits_wr_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+155,0,"io_out_bits_bit_width",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+156,0,"io_out_bits_sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+160,0,"io_out_bits_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"io_out_bits_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"io_out_bits_dnpc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"io_out_bits_csrReq_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+164,0,"io_out_bits_csrReq_re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"io_out_bits_csrReq_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+166,0,"io_out_bits_csrReq_wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"io_out_bits_csrReq_wvalue",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+168,0,"io_out_bits_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+169,0,"io_out_bits_inv",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+170,0,"io_out_bits_ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+171,0,"io_out_bits_mret",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+172,0,"io_out_bits_has_exception",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+173,0,"io_out_bits_exception_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+19,0,"io_ctrl_br_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+159,0,"io_ctrl_br_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+263,0,"io_flush_ex_found_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"io_flush_flush",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"io_ctrl_br_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+149,0,"io_in_src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"io_in_src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"io_in_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+262,0,"io_out_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+262,0,"casez_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("idu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"io_in_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"io_in_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"io_in_bits_need_flush_in_IF_or_IW",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+140,0,"io_in_bits_inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"io_in_bits_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+142,0,"io_in_bits_dnpc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+143,0,"io_in_bits_has_exception",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"io_in_bits_exception_code",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+16,0,"io_out_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"io_out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+264,0,"io_out_bits_alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+265,0,"io_out_bits_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+266,0,"io_out_bits_src1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+267,0,"io_out_bits_src2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"io_out_bits_rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+22,0,"io_out_bits_wr_reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"io_out_bits_rd_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"io_out_bits_wr_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+269,0,"io_out_bits_bit_width",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+270,0,"io_out_bits_sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"io_out_bits_br_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"io_out_bits_br_expect_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+272,0,"io_out_bits_br_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"io_out_bits_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"io_out_bits_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"io_out_bits_dnpc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"io_out_bits_csrReq_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+28,0,"io_out_bits_csrReq_re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"io_out_bits_csrReq_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"io_out_bits_csrReq_wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"io_out_bits_csrReq_wvalue",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+32,0,"io_out_bits_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"io_out_bits_inv",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"io_out_bits_ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"io_out_bits_mret",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"io_out_bits_has_exception",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"io_out_bits_exception_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"io_rf_rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+274,0,"io_rf_rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+275,0,"io_rf_rdata1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"io_rf_rdata2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+36,0,"io_ctrl_jump_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+276,0,"io_ctrl_jump_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+37,0,"io_ctrl_ex_found_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+277,0,"io_raw_info_needRs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+278,0,"io_raw_info_needRs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"io_raw_info_isRAW",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"io_flush_br_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"io_flush_ex_found_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"io_flush_flush",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"allow_side_effect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"ready_go",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"io_out_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+280,0,"instType",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+281,0,"funcType",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+282,0,"usageBits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+283,0,"casez_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+36,0,"io_ctrl_jump_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+276,0,"io_ctrl_jump_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+32,0,"io_out_bits_ebreak_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"io_out_bits_inv_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+284,0,"csr_src1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"io_out_bits_csrReq_re_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+285,0,"casez_tmp_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+34,0,"io_out_bits_ecall_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"io_out_bits_mret_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ftrace", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+141,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"target_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+265,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+286,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+283,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+42,0,"is_jal",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"is_jalr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("ifu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"io_out_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"io_out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"io_out_bits_need_flush_in_IF",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"io_out_bits_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"io_out_bits_dnpc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+287,0,"io_ctrl_ex_redirect_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+288,0,"io_ctrl_ex_redirect_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+36,0,"io_ctrl_jump_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+276,0,"io_ctrl_jump_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+19,0,"io_ctrl_br_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+159,0,"io_ctrl_br_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+48,0,"io_ctrl_ex_found_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"io_mem_ar_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+2,0,"io_mem_ar_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"io_mem_ar_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_mem_ar_arvalid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"io_out_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"ar_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"valid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+291,0,"data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+49,0,"jump_valid_preserved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"valid_reg_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+293,0,"data_reg_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+50,0,"br_taken_preserved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+294,0,"valid_reg_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+295,0,"data_reg_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+296,0,"ex_redirect_valid_preserved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+297,0,"ex_found_in_preserved_signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"need_flush_in_IF_preserved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("iringbuf", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+409,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+51,0,"before_ifetch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+410,0,"after_ifetch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+410,0,"flush_after_ifetch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("iwu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"io_in_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"io_in_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"io_in_bits_need_flush_in_IF",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"io_in_bits_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"io_in_bits_dnpc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+20,0,"io_out_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"io_out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"io_out_bits_need_flush_in_IF_or_IW",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+299,0,"io_out_bits_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"io_out_bits_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"io_out_bits_dnpc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+300,0,"io_out_bits_has_exception",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+301,0,"io_out_bits_exception_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"io_mem_r_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"io_mem_r_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+86,0,"io_mem_r_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"io_mem_r_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"io_ctrl_ex_found_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"io_flush_br_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"io_flush_jump_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"io_flush_ex_found_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"io_mem_r_rready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"io_out_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"r_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+303,0,"valid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+304,0,"data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+305,0,"r_fire_preserved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+299,0,"inst_preserved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+302,0,"resp_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+306,0,"resp_ex_preserved_signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+300,0,"resp_ex_preserved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"need_flush_in_IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+307,0,"need_flush_in_IW_preserved_signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"need_flush_in_IW_preserved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"io_out_bits_need_flush_in_IF_or_IW_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("iringbuf", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+299,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+410,0,"before_ifetch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"after_ifetch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"flush_after_ifetch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("lsu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_in_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"io_in_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_in_bits_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"io_in_bits_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+176,0,"io_in_bits_wr_reg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+177,0,"io_in_bits_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+178,0,"io_in_bits_rd_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"io_in_bits_wr_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+180,0,"io_in_bits_bit_width",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+181,0,"io_in_bits_sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+182,0,"io_in_bits_inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"io_in_bits_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"io_in_bits_dnpc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"io_in_bits_csrReq_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+186,0,"io_in_bits_csrReq_re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"io_in_bits_csrReq_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+188,0,"io_in_bits_csrReq_wmask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"io_in_bits_csrReq_wvalue",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+190,0,"io_in_bits_ebreak",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"io_in_bits_inv",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"io_in_bits_ecall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"io_in_bits_mret",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+194,0,"io_in_bits_has_exception",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+195,0,"io_in_bits_exception_code",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+58,0,"io_out_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"io_out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_out_bits_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"io_out_bits_bit_width",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+181,0,"io_out_bits_sign",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"io_out_bits_rd_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"io_out_bits_wr_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_out_bits_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+176,0,"io_out_bits_wr_reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+177,0,"io_out_bits_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+182,0,"io_out_bits_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"io_out_bits_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"io_out_bits_dnpc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+185,0,"io_out_bits_csrReq_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+186,0,"io_out_bits_csrReq_re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"io_out_bits_csrReq_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+188,0,"io_out_bits_csrReq_wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"io_out_bits_csrReq_wvalue",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+190,0,"io_out_bits_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"io_out_bits_inv",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"io_out_bits_ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"io_out_bits_mret",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+194,0,"io_out_bits_has_exception",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+195,0,"io_out_bits_exception_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"io_mem_ar_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"io_mem_ar_arsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+98,0,"io_mem_ar_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"io_mem_ar_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_mem_aw_awaddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"io_mem_aw_awsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+89,0,"io_mem_aw_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"io_mem_aw_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"io_mem_w_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"io_mem_w_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+92,0,"io_mem_w_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"io_mem_w_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+308,0,"io_ctrl_older_mem_pending",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"io_flush_ex_found_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"io_flush_flush",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+309,0,"io_load",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"io_mem_w_wvalid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"io_mem_aw_awvalid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"io_mem_ar_arvalid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+310,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"allow_side_effect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"ar_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"aw_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"w_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+312,0,"signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+313,0,"signal_reg_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+314,0,"signal_reg_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"ready_go",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"io_out_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lswu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"io_in_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+197,0,"io_in_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+198,0,"io_in_bits_raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"io_in_bits_bit_width",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+200,0,"io_in_bits_sign",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"io_in_bits_rd_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"io_in_bits_wr_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+203,0,"io_in_bits_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+204,0,"io_in_bits_wr_reg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+205,0,"io_in_bits_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+206,0,"io_in_bits_inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"io_in_bits_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"io_in_bits_dnpc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+209,0,"io_in_bits_csrReq_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+210,0,"io_in_bits_csrReq_re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"io_in_bits_csrReq_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+212,0,"io_in_bits_csrReq_wmask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+213,0,"io_in_bits_csrReq_wvalue",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+214,0,"io_in_bits_ebreak",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+215,0,"io_in_bits_inv",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"io_in_bits_ecall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+217,0,"io_in_bits_mret",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+218,0,"io_in_bits_has_exception",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+219,0,"io_in_bits_exception_code",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+408,0,"io_out_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"io_out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+316,0,"io_out_bits_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+204,0,"io_out_bits_wr_reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+205,0,"io_out_bits_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+206,0,"io_out_bits_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"io_out_bits_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"io_out_bits_dnpc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+209,0,"io_out_bits_csrReq_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+210,0,"io_out_bits_csrReq_re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"io_out_bits_csrReq_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+212,0,"io_out_bits_csrReq_wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+213,0,"io_out_bits_csrReq_wvalue",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+214,0,"io_out_bits_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+215,0,"io_out_bits_inv",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"io_out_bits_ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+217,0,"io_out_bits_mret",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"io_out_bits_has_exception",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+318,0,"io_out_bits_exception_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+319,0,"io_out_bits_need_skip_ref",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+102,0,"io_mem_r_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"io_mem_r_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+100,0,"io_mem_r_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"io_mem_r_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"io_mem_b_bresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+96,0,"io_mem_b_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"io_mem_b_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"io_mem_r_need_skip_ref",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"io_mem_b_need_skip_ref",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"io_ctrl_ex_found_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+308,0,"io_ctrl_older_mem_pending",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+320,0,"io_load",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"io_mem_b_bready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"io_mem_r_rready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+321,0,"casez_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+320,0,"io_load_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+322,0,"r_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+323,0,"b_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+324,0,"valid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+325,0,"data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+326,0,"signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+327,0,"need_skip_ref_preserved_signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+328,0,"ready_go",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"io_out_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"resp_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+329,0,"resp_ex_preserved_signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"resp_ex_preserved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+331,0,"load_data_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("regfile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+332,0,"io_in_raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+333,0,"io_in_raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+334,0,"io_in_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+335,0,"io_in_waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+336,0,"io_in_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"io_out_rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"io_out_rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+337,0,"regfile_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+338,0,"regfile_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+339,0,"regfile_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+340,0,"regfile_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+341,0,"regfile_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+342,0,"regfile_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+343,0,"regfile_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+344,0,"regfile_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+345,0,"regfile_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+346,0,"regfile_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+347,0,"regfile_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+348,0,"regfile_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+349,0,"regfile_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+350,0,"regfile_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+351,0,"regfile_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+352,0,"regfile_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"casez_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"casez_tmp_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("wbu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+408,0,"io_in_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"io_in_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+221,0,"io_in_bits_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+222,0,"io_in_bits_wr_reg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"io_in_bits_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+224,0,"io_in_bits_inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+225,0,"io_in_bits_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+226,0,"io_in_bits_dnpc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+227,0,"io_in_bits_csrReq_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+228,0,"io_in_bits_csrReq_re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+229,0,"io_in_bits_csrReq_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+230,0,"io_in_bits_csrReq_wmask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+231,0,"io_in_bits_csrReq_wvalue",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+232,0,"io_in_bits_ebreak",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+233,0,"io_in_bits_inv",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+234,0,"io_in_bits_ecall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+235,0,"io_in_bits_mret",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+236,0,"io_in_bits_has_exception",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+237,0,"io_in_bits_exception_code",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+238,0,"io_in_bits_need_skip_ref",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+245,0,"io_csr_priv",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+227,0,"io_csr_csrReq_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+239,0,"io_csr_csrReq_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+230,0,"io_csr_csrReq_wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+231,0,"io_csr_csrReq_wvalue",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+244,0,"io_csr_csrResp_rvalue",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+246,0,"io_csr_mtvec",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+247,0,"io_csr_mepc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+240,0,"io_csr_wb_ex",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+241,0,"io_csr_wb_cause",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"io_csr_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+243,0,"io_csr_mret",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+336,0,"io_rf_wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+334,0,"io_rf_wb_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+223,0,"io_rf_wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+287,0,"io_ctrl_ex_redirect_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+288,0,"io_ctrl_ex_redirect_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+240,0,"io_csr_wb_ex_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+243,0,"io_csr_mret_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+288,0,"io_ctrl_ex_redirect_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+287,0,"io_ctrl_ex_redirect_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+353,0,"allow_side_effect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+354,0,"dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+355,0,"submit_dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+356,0,"casez_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("halt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+357,0,"exit_code",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+225,0,"exit_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+358,0,"halt_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("itrace", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+225,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+224,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+354,0,"dnpc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+238,0,"need_skip_ref",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+359,0,"axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+411,0,"axi_awid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+412,0,"axi_awlen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+91,0,"axi_awsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+413,0,"axi_awburst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+65,0,"axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+360,0,"axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"axi_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+414,0,"axi_wlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+361,0,"axi_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+362,0,"axi_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+363,0,"axi_bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+364,0,"axi_bid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+66,0,"axi_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"axi_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"axi_arid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+412,0,"axi_arlen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+10,0,"axi_arsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+413,0,"axi_arburst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+365,0,"axi_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+366,0,"axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+367,0,"axi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+368,0,"axi_rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+369,0,"axi_rid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+370,0,"axi_rlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+415,0,"AXI_RESP_OKAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+371,0,"aw_seen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+372,0,"w_seen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+373,0,"awaddr_latched",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+374,0,"awid_latched",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+375,0,"wdata_latched",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+376,0,"wstrb_latched",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+68,0,"ar_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+377,0,"r_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"aw_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"w_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+378,0,"b_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+379,0,"write_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"aw_seen_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"w_seen_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"write_req_complete",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"write_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"write_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+76,0,"write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"write_strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+78,0,"read_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("uart", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+380,0,"io_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+381,0,"io_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+382,0,"io_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+383,0,"io_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"io_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"io_axi_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+384,0,"io_axi_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+385,0,"io_axi_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"io_axi_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"io_axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+387,0,"io_axi_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+388,0,"io_axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+385,0,"io_b_need_skip_ref",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+382,0,"io_axi_wready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+380,0,"io_axi_awready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+389,0,"aw_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+390,0,"w_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+388,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+385,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+391,0,"signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+392,0,"signal_reg_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+393,0,"write_req_complete",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+394,0,"wdata_preserved_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+395,0,"wstrb_preserved_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+80,0,"ar_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+396,0,"r_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"b_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("xbar", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+406,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"io_in_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"io_in_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_in_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"io_in_awsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+4,0,"io_in_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"io_in_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"io_in_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"io_in_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+95,0,"io_in_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"io_in_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"io_in_bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+6,0,"io_in_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"io_in_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"io_in_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"io_in_arid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+10,0,"io_in_arsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+104,0,"io_in_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"io_in_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"io_in_rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+107,0,"io_in_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+64,0,"io_mem_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+359,0,"io_mem_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"io_mem_awaddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"io_mem_awsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+65,0,"io_mem_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+360,0,"io_mem_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"io_mem_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"io_mem_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+361,0,"io_mem_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+362,0,"io_mem_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+363,0,"io_mem_bresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+66,0,"io_mem_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"io_mem_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"io_mem_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"io_mem_arid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+10,0,"io_mem_arsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+365,0,"io_mem_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+366,0,"io_mem_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+368,0,"io_mem_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+367,0,"io_mem_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+380,0,"io_uart_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+381,0,"io_uart_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+382,0,"io_uart_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+383,0,"io_uart_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"io_uart_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"io_uart_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+384,0,"io_uart_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+385,0,"io_uart_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"io_uart_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"io_uart_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+387,0,"io_uart_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+388,0,"io_uart_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"io_clint_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"io_clint_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"io_clint_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"io_clint_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"io_clint_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"io_clint_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"io_clint_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"io_clint_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"io_clint_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"io_clint_arsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+120,0,"io_clint_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"io_clint_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"io_clint_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+385,0,"io_uart_b_need_skip_ref",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"io_clint_r_need_skip_ref",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"io_r_need_skip_ref",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"io_b_need_skip_ref",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+398,0,"ar_fire_after_signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+399,0,"signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+400,0,"w_fire_after_signal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"hit_uart_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"hit_clint_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+401,0,"hit_uart_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+402,0,"hit_clint_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+403,0,"hit_mem_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+404,0,"read_owner",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+405,0,"write_owner",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+6,0,"io_in_arready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"io_in_rvalid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"io_in_awready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"io_in_wready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"io_in_bvalid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"ar_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"aw_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+323,0,"b_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VTop___024root__trace_init_top(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_init_top\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTop___024root__trace_register(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_register\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VTop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VTop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VTop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VTop___024root__trace_cleanup, vlSelf);
    }

    VL_ATTR_COLD void VTop___024root__trace_const_0_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

    VL_ATTR_COLD void VTop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
        VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_const_0\n"); );
        // Init
        VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);

        VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;

        // Body
        VTop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
    }

    VL_ATTR_COLD void VTop___024root__trace_const_0_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
        VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_const_0_sub_0\n"); );
        VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
        auto& vlSelfRef = std::ref(*vlSelf).get();
        // Init
        uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);

        // Body
        bufp->fullIData(oldp+409,(0U),32);
        bufp->fullBit(oldp+410,(0U));
        bufp->fullCData(oldp+411,(1U),4);
        bufp->fullCData(oldp+412,(0U),8);
        bufp->fullCData(oldp+413,(1U),2);
        bufp->fullBit(oldp+414,(1U));
        bufp->fullCData(oldp+415,(0U),2);
    }

    VL_ATTR_COLD void VTop___024root__trace_full_0_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

    VL_ATTR_COLD void VTop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
        VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_full_0\n"); );
        // Init
        VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);

        VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;

        // Body
        VTop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
    }

    VL_ATTR_COLD void VTop___024root__trace_full_0_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
        VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_full_0_sub_0\n"); );
        VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
        auto& vlSelfRef = std::ref(*vlSelf).get();
        // Init
        uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);

        // Body
        bufp->fullBit(oldp+1,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved) 
                               & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arready) 
                                  & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read)))));
        bufp->fullBit(oldp+2,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_mem_ar_arvalid));
        bufp->fullBit(oldp+3,(((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
                               & ((0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)
                                   ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_uart_awready)
                                   : ((IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)
                                       ? (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_clint_awready)
                                       : (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready))))));
        bufp->fullBit(oldp+4,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wready));
        bufp->fullBit(oldp+5,(((~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)) 
                               & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arready))));
        bufp->fullBit(oldp+6,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arready));
        bufp->fullBit(oldp+7,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid));
        bufp->fullIData(oldp+8,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr),32);
        bufp->fullCData(oldp+9,((1U & (~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)))),4);
        bufp->fullCData(oldp+10,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)
                                   ? 2U : ((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                            ? 2U : 
                                           ((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                             ? 1U : 
                                            ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width)) 
                                             << 1U))))),3);
        bufp->fullBit(oldp+11,(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read));
        bufp->fullBit(oldp+12,(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved));
        bufp->fullBit(oldp+13,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ar_fire));
        bufp->fullBit(oldp+14,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                   & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r)))));
        bufp->fullBit(oldp+15,(vlSelfRef.Top__DOT__clint__DOT__ar_fire));
        bufp->fullBit(oldp+16,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_ready));
        bufp->fullBit(oldp+17,(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_ready));
        bufp->fullIData(oldp+18,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken)
                                   ? vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_target
                                   : vlSelfRef.Top__DOT__core__DOT__bitsReg_2_dnpc)),32);
        bufp->fullBit(oldp+19,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken));
        bufp->fullBit(oldp+20,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_ready));
        bufp->fullBit(oldp+21,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_valid));
        bufp->fullBit(oldp+22,(((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect))));
        bufp->fullBit(oldp+23,(((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect))));
        bufp->fullBit(oldp+24,(((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect))));
        bufp->fullBit(oldp+25,(((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect))));
        bufp->fullIData(oldp+26,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid)
                                   ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target
                                   : vlSelfRef.Top__DOT__core__DOT__bitsReg_1_dnpc)),32);
        bufp->fullSData(oldp+27,(((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re)
                                   ? (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                      >> 0x00000014U)
                                   : 0U)),12);
        bufp->fullBit(oldp+28,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re));
        bufp->fullBit(oldp+29,(((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re) 
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
        bufp->fullIData(oldp+30,(((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re)
                                   ? ((0U == (3U & 
                                              (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                               >> 0x0000000cU)))
                                       ? 0U : ((1U 
                                                == 
                                                (3U 
                                                 & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                    >> 0x0000000cU)))
                                                ? 0xffffffffU
                                                : vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1))
                                   : 0U)),32);
        bufp->fullIData(oldp+31,(((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_csrReq_re)
                                   ? ((1U == (3U & 
                                              (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                               >> 0x0000000cU)))
                                       ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1
                                       : (- (IData)(
                                                    (2U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                         >> 0x0000000cU))))))
                                   : 0U)),32);
        bufp->fullBit(oldp+32,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ebreak));
        bufp->fullBit(oldp+33,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_inv));
        bufp->fullBit(oldp+34,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ecall));
        bufp->fullBit(oldp+35,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_mret));
        bufp->fullBit(oldp+36,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid));
        bufp->fullBit(oldp+37,((((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ebreak) 
                                 | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_inv) 
                                    | ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_ecall) 
                                       | (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_mret)))) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___ftrace_is_jalr_T_3))));
        bufp->fullBit(oldp+38,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_flush));
        bufp->fullBit(oldp+39,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__valid));
        bufp->fullBit(oldp+40,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__allow_side_effect));
        bufp->fullBit(oldp+41,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__ready_go));
        bufp->fullBit(oldp+42,(((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType)) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_6))));
        bufp->fullBit(oldp+43,(((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType)) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_6))));
        bufp->fullBit(oldp+44,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_ready));
        bufp->fullBit(oldp+45,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_valid));
        bufp->fullBit(oldp+46,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_need_flush_in_IF));
        bufp->fullIData(oldp+47,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_dnpc),32);
        bufp->fullBit(oldp+48,(vlSelfRef.Top__DOT__core__DOT____Vcellinp__ifu__io_ctrl_ex_found_in));
        bufp->fullBit(oldp+49,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_valid) 
                                | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg))));
        bufp->fullBit(oldp+50,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_br_taken) 
                                | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_1))));
        bufp->fullBit(oldp+51,(((~ (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_out_bits_need_flush_in_IF)) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT___iringbuf_before_ifetch_T))));
        bufp->fullBit(oldp+52,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_need_flush_in_IF_or_IW));
        bufp->fullBit(oldp+53,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_flush_ex_found_in));
        bufp->fullBit(oldp+54,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW));
        bufp->fullBit(oldp+55,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved));
        bufp->fullBit(oldp+56,(((~ (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_need_flush_in_IF_or_IW)) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T))));
        bufp->fullBit(oldp+57,(((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT___iringbuf_flush_after_ifetch_T) 
                                & (IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved))));
        bufp->fullBit(oldp+58,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_ready));
        bufp->fullBit(oldp+59,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_out_valid));
        bufp->fullBit(oldp+60,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__ar_fire));
        bufp->fullBit(oldp+61,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__aw_fire));
        bufp->fullBit(oldp+62,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__w_fire));
        bufp->fullBit(oldp+63,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__ready_go));
        bufp->fullBit(oldp+64,(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awready));
        bufp->fullBit(oldp+65,(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wready));
        bufp->fullBit(oldp+66,(vlSelfRef.Top__DOT__xbar__DOT__io_mem_arready));
        bufp->fullBit(oldp+67,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                & ((0x10000000U != vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr) 
                                   & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r)) 
                                      & (~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)))))));
        bufp->fullBit(oldp+68,((((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                 & ((0x10000000U != vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr) 
                                    & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r)) 
                                       & (~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg))))) 
                                & (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_arready))));
        bufp->fullBit(oldp+69,(vlSelfRef.Top__DOT__mem__DOT__aw_fire));
        bufp->fullBit(oldp+70,(vlSelfRef.Top__DOT__mem__DOT__w_fire));
        bufp->fullBit(oldp+71,(((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen) 
                                | (IData)(vlSelfRef.Top__DOT__mem__DOT__aw_fire))));
        bufp->fullBit(oldp+72,(((IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen) 
                                | (IData)(vlSelfRef.Top__DOT__mem__DOT__w_fire))));
        bufp->fullBit(oldp+73,((((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen) 
                                 | (IData)(vlSelfRef.Top__DOT__mem__DOT__aw_fire)) 
                                & ((~ (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid)) 
                                   & ((IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen) 
                                      | (IData)(vlSelfRef.Top__DOT__mem__DOT__w_fire))))));
        bufp->fullIData(oldp+74,(((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_fire)
                                   ? vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result
                                   : vlSelfRef.Top__DOT__mem__DOT__awaddr_latched)),32);
        bufp->fullCData(oldp+75,(((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_fire)
                                   ? 1U : (IData)(vlSelfRef.Top__DOT__mem__DOT__awid_latched))),4);
        bufp->fullIData(oldp+76,(((IData)(vlSelfRef.Top__DOT__mem__DOT__w_fire)
                                   ? vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata
                                   : vlSelfRef.Top__DOT__mem__DOT__wdata_latched)),32);
        bufp->fullCData(oldp+77,(((IData)(vlSelfRef.Top__DOT__mem__DOT__w_fire)
                                   ? (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb)
                                   : (IData)(vlSelfRef.Top__DOT__mem__DOT__wstrb_latched))),4);
        bufp->fullCData(oldp+78,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved)
                                   ? 0U : 1U)),8);
        bufp->fullBit(oldp+79,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                   & (0x10000000U == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr)))));
        bufp->fullBit(oldp+80,(((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid)) 
                                & ((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_arvalid) 
                                   & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg)) 
                                      & (0x10000000U 
                                         == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr))))));
        bufp->fullBit(oldp+81,((0x10000000U == vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_araddr)));
        bufp->fullBit(oldp+82,(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_r));
        bufp->fullBit(oldp+83,(vlSelfRef.Top__DOT__xbar__DOT__ar_fire));
        bufp->fullIData(oldp+84,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__pc),32);
        bufp->fullBit(oldp+85,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rready));
        bufp->fullBit(oldp+86,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid) 
                                & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw))));
        bufp->fullCData(oldp+87,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
                                   ? (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp)
                                   : 0U)),2);
        bufp->fullIData(oldp+88,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata),32);
        bufp->fullBit(oldp+89,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid));
        bufp->fullIData(oldp+90,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result),32);
        bufp->fullCData(oldp+91,(((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                   ? 2U : ((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width))
                                            ? 1U : 
                                           ((0U != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width)) 
                                            << 1U)))),3);
        bufp->fullBit(oldp+92,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid));
        bufp->fullIData(oldp+93,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wdata),32);
        bufp->fullCData(oldp+94,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wstrb),4);
        bufp->fullBit(oldp+95,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready));
        bufp->fullBit(oldp+96,(((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                                 ? (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)
                                 : ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                                     ? (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)
                                     : (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid)))));
        bufp->fullCData(oldp+97,(((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                                   ? 0U : ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner))
                                            ? 2U : (IData)(vlSelfRef.Top__DOT___mem_axi_bresp)))),2);
        bufp->fullBit(oldp+98,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_ar_arvalid));
        bufp->fullBit(oldp+99,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_r_rready));
        bufp->fullBit(oldp+100,(((~ (IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)) 
                                 & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid))));
        bufp->fullCData(oldp+101,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
                                    ? 0U : (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp))),2);
        bufp->fullIData(oldp+102,(((IData)(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw)
                                    ? 0U : vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata)),32);
        bufp->fullBit(oldp+103,((((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem) 
                                  & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid)) 
                                 | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_load))));
        bufp->fullBit(oldp+104,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready));
        bufp->fullBit(oldp+105,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rvalid));
        bufp->fullCData(oldp+106,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rresp),2);
        bufp->fullIData(oldp+107,(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rdata),32);
        bufp->fullBit(oldp+108,(((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                 & (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid))));
        bufp->fullBit(oldp+109,(((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                 & (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid))));
        bufp->fullBit(oldp+110,(vlSelfRef.Top__DOT__arbiter__DOT__grant_if_iw_read_preserved_signal_reg));
        bufp->fullBit(oldp+111,(vlSelfRef.Top__DOT__arbiter__DOT__read_owner_is_if_iw));
        bufp->fullBit(oldp+112,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire));
        bufp->fullBit(oldp+113,(vlSelfRef.Top__DOT__xbar__DOT__io_clint_awready));
        bufp->fullBit(oldp+114,(((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid) 
                                 & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
                                    & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)))));
        bufp->fullBit(oldp+115,(vlSelfRef.Top__DOT__xbar__DOT__io_clint_wready));
        bufp->fullBit(oldp+116,(((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid) 
                                 & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg)) 
                                    & (IData)(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w)))));
        bufp->fullBit(oldp+117,(((1U != (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                 & ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                    & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready)))));
        bufp->fullBit(oldp+118,(vlSelfRef.Top__DOT__clint__DOT__bvalid));
        bufp->fullBit(oldp+119,((1U & (~ (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid)))));
        bufp->fullBit(oldp+120,(((1U != (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                 & ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                    & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready)))));
        bufp->fullBit(oldp+121,(vlSelfRef.Top__DOT__clint__DOT__rvalid));
        bufp->fullIData(oldp+122,(vlSelfRef.Top__DOT__clint__DOT__rdata),32);
        bufp->fullQData(oldp+123,(vlSelfRef.Top__DOT__clint__DOT__mtime),64);
        bufp->fullQData(oldp+125,(vlSelfRef.Top__DOT__clint__DOT__mtime_snapshot),64);
        bufp->fullBit(oldp+127,(vlSelfRef.Top__DOT__clint__DOT__aw_fire));
        bufp->fullBit(oldp+128,(vlSelfRef.Top__DOT__clint__DOT__w_fire));
        bufp->fullBit(oldp+129,(vlSelfRef.Top__DOT__clint__DOT__signal_reg));
        bufp->fullBit(oldp+130,(vlSelfRef.Top__DOT__clint__DOT__signal_reg_1));
        bufp->fullBit(oldp+131,((((IData)(vlSelfRef.Top__DOT__clint__DOT__aw_fire) 
                                  | (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg)) 
                                 & ((~ (IData)(vlSelfRef.Top__DOT__clint__DOT__bvalid)) 
                                    & ((IData)(vlSelfRef.Top__DOT__clint__DOT__w_fire) 
                                       | (IData)(vlSelfRef.Top__DOT__clint__DOT__signal_reg_1))))));
        bufp->fullBit(oldp+132,((((1U != (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                  & ((2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                     & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready))) 
                                 & (IData)(vlSelfRef.Top__DOT__clint__DOT__rvalid))));
        bufp->fullBit(oldp+133,(vlSelfRef.Top__DOT__clint__DOT__b_fire));
        bufp->fullBit(oldp+134,(vlSelfRef.Top__DOT__core__DOT__validReg));
        bufp->fullBit(oldp+135,(vlSelfRef.Top__DOT__core__DOT__bitsReg_need_flush_in_IF));
        bufp->fullIData(oldp+136,(vlSelfRef.Top__DOT__core__DOT__bitsReg_pc),32);
        bufp->fullIData(oldp+137,(vlSelfRef.Top__DOT__core__DOT__bitsReg_dnpc),32);
        bufp->fullBit(oldp+138,(vlSelfRef.Top__DOT__core__DOT__validReg_1));
        bufp->fullBit(oldp+139,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_need_flush_in_IF_or_IW));
        bufp->fullIData(oldp+140,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst),32);
        bufp->fullIData(oldp+141,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc),32);
        bufp->fullIData(oldp+142,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_dnpc),32);
        bufp->fullBit(oldp+143,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_has_exception));
        bufp->fullIData(oldp+144,(vlSelfRef.Top__DOT__core__DOT__bitsReg_1_exception_code),32);
        bufp->fullBit(oldp+145,(vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_1));
        bufp->fullBit(oldp+146,(vlSelfRef.Top__DOT__core__DOT__validReg_2));
        bufp->fullCData(oldp+147,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_alu_op),4);
        bufp->fullCData(oldp+148,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd),5);
        bufp->fullIData(oldp+149,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src1),32);
        bufp->fullIData(oldp+150,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_src2),32);
        bufp->fullIData(oldp+151,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rs2_data),32);
        bufp->fullBit(oldp+152,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_reg));
        bufp->fullBit(oldp+153,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd_mem));
        bufp->fullBit(oldp+154,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_mem));
        bufp->fullCData(oldp+155,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_bit_width),2);
        bufp->fullBit(oldp+156,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_sign));
        bufp->fullBit(oldp+157,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_valid));
        bufp->fullBit(oldp+158,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_expect_0));
        bufp->fullIData(oldp+159,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_br_target),32);
        bufp->fullIData(oldp+160,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inst),32);
        bufp->fullIData(oldp+161,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_pc),32);
        bufp->fullIData(oldp+162,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_dnpc),32);
        bufp->fullSData(oldp+163,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_addr),12);
        bufp->fullBit(oldp+164,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_re));
        bufp->fullBit(oldp+165,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_we));
        bufp->fullIData(oldp+166,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wmask),32);
        bufp->fullIData(oldp+167,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_csrReq_wvalue),32);
        bufp->fullBit(oldp+168,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ebreak));
        bufp->fullBit(oldp+169,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_inv));
        bufp->fullBit(oldp+170,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_ecall));
        bufp->fullBit(oldp+171,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_mret));
        bufp->fullBit(oldp+172,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_has_exception));
        bufp->fullIData(oldp+173,(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_exception_code),32);
        bufp->fullBit(oldp+174,(vlSelfRef.Top__DOT__core__DOT__validReg_3));
        bufp->fullIData(oldp+175,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rs2_data),32);
        bufp->fullBit(oldp+176,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_reg));
        bufp->fullCData(oldp+177,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd),5);
        bufp->fullBit(oldp+178,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem));
        bufp->fullBit(oldp+179,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_wr_mem));
        bufp->fullCData(oldp+180,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_bit_width),2);
        bufp->fullBit(oldp+181,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_sign));
        bufp->fullIData(oldp+182,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_inst),32);
        bufp->fullIData(oldp+183,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_pc),32);
        bufp->fullIData(oldp+184,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_dnpc),32);
        bufp->fullSData(oldp+185,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_addr),12);
        bufp->fullBit(oldp+186,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_re));
        bufp->fullBit(oldp+187,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_we));
        bufp->fullIData(oldp+188,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_wmask),32);
        bufp->fullIData(oldp+189,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_csrReq_wvalue),32);
        bufp->fullBit(oldp+190,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_ebreak));
        bufp->fullBit(oldp+191,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_inv));
        bufp->fullBit(oldp+192,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_ecall));
        bufp->fullBit(oldp+193,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_mret));
        bufp->fullBit(oldp+194,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_has_exception));
        bufp->fullIData(oldp+195,(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_exception_code),32);
        bufp->fullBit(oldp+196,(vlSelfRef.Top__DOT__core__DOT__flush_preserved_signal_reg_3));
        bufp->fullBit(oldp+197,(vlSelfRef.Top__DOT__core__DOT__validReg_4));
        bufp->fullIData(oldp+198,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_raddr),32);
        bufp->fullCData(oldp+199,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_bit_width),2);
        bufp->fullBit(oldp+200,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_sign));
        bufp->fullBit(oldp+201,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem));
        bufp->fullBit(oldp+202,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem));
        bufp->fullIData(oldp+203,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_result),32);
        bufp->fullBit(oldp+204,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_reg));
        bufp->fullCData(oldp+205,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd),5);
        bufp->fullIData(oldp+206,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_inst),32);
        bufp->fullIData(oldp+207,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_pc),32);
        bufp->fullIData(oldp+208,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_dnpc),32);
        bufp->fullSData(oldp+209,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_addr),12);
        bufp->fullBit(oldp+210,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_re));
        bufp->fullBit(oldp+211,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_we));
        bufp->fullIData(oldp+212,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_wmask),32);
        bufp->fullIData(oldp+213,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_csrReq_wvalue),32);
        bufp->fullBit(oldp+214,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_ebreak));
        bufp->fullBit(oldp+215,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_inv));
        bufp->fullBit(oldp+216,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_ecall));
        bufp->fullBit(oldp+217,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_mret));
        bufp->fullBit(oldp+218,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception));
        bufp->fullIData(oldp+219,(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_exception_code),32);
        bufp->fullBit(oldp+220,(vlSelfRef.Top__DOT__core__DOT__validReg_5));
        bufp->fullIData(oldp+221,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_data),32);
        bufp->fullBit(oldp+222,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_wr_reg));
        bufp->fullCData(oldp+223,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd),5);
        bufp->fullIData(oldp+224,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inst),32);
        bufp->fullIData(oldp+225,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_pc),32);
        bufp->fullIData(oldp+226,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_dnpc),32);
        bufp->fullSData(oldp+227,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr),12);
        bufp->fullBit(oldp+228,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_re));
        bufp->fullBit(oldp+229,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_we));
        bufp->fullIData(oldp+230,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wmask),32);
        bufp->fullIData(oldp+231,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_wvalue),32);
        bufp->fullBit(oldp+232,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ebreak));
        bufp->fullBit(oldp+233,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inv));
        bufp->fullBit(oldp+234,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ecall));
        bufp->fullBit(oldp+235,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_mret));
        bufp->fullBit(oldp+236,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception));
        bufp->fullIData(oldp+237,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_exception_code),32);
        bufp->fullBit(oldp+238,(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_need_skip_ref));
        bufp->fullBit(oldp+239,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_csrReq_we));
        bufp->fullBit(oldp+240,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_wb_ex));
        bufp->fullIData(oldp+241,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_has_exception)
                                    ? vlSelfRef.Top__DOT__core__DOT__bitsReg_5_exception_code
                                    : ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ecall)
                                        ? ((0U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                            ? 8U : 
                                           ((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                             ? 9U : 
                                            ((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                              ? 0U : 0x0000000bU)))
                                        : 0U))),32);
        bufp->fullIData(oldp+242,(((IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT___GEN)
                                    ? vlSelfRef.Top__DOT__core__DOT__bitsReg_5_pc
                                    : 0U)),32);
        bufp->fullBit(oldp+243,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_csr_mret));
        bufp->fullIData(oldp+244,((((0x0300U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))
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
        bufp->fullCData(oldp+245,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv),2);
        bufp->fullIData(oldp+246,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mtvec),32);
        bufp->fullIData(oldp+247,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mepc),32);
        bufp->fullIData(oldp+248,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mstatus),32);
        bufp->fullIData(oldp+249,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcause),32);
        bufp->fullIData(oldp+250,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycle),32);
        bufp->fullIData(oldp+251,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mcycleh),32);
        bufp->fullIData(oldp+252,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__mvendorid),32);
        bufp->fullIData(oldp+253,(vlSelfRef.Top__DOT__core__DOT__csr__DOT__marchid),32);
        bufp->fullBit(oldp+254,((0x0300U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->fullBit(oldp+255,((0x0305U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->fullBit(oldp+256,((0x0341U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->fullBit(oldp+257,((0x0342U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->fullBit(oldp+258,((0x0b80U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->fullBit(oldp+259,((0x0f11U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->fullBit(oldp+260,((0x0f12U == (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_csrReq_addr))));
        bufp->fullBit(oldp+261,(vlSelfRef.Top__DOT__core__DOT__exu__DOT__io_out_valid));
        bufp->fullIData(oldp+262,(vlSelfRef.Top__DOT__core__DOT__exu__DOT__alu__DOT__io_out_result),32);
        bufp->fullBit(oldp+263,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in));
        bufp->fullCData(oldp+264,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_alu_op),4);
        bufp->fullCData(oldp+265,((0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                  >> 7U))),5);
        bufp->fullIData(oldp+266,((((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                                    | (4U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)))
                                    ? vlSelfRef.Top__DOT__core__DOT__bitsReg_1_pc
                                    : ((8U & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits))
                                        ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rdata1
                                        : 0U))),32);
        bufp->fullIData(oldp+267,(((5U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType))
                                    ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm
                                    : ((4U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType))
                                        ? 4U : ((3U 
                                                 == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType))
                                                 ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits))
                                                  ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits))
                                                   ? vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data
                                                   : 0U)))))),32);
        bufp->fullIData(oldp+268,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_rs2_data),32);
        bufp->fullCData(oldp+269,((((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_6) 
                                    | (0x0067U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0)))
                                    ? 2U : ((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                             ? 0U : 
                                            ((0x0083U 
                                              == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT___GEN_0))
                                              ? 1U : 
                                             ((0x0103U 
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
                                                       : 2U)))))))))),2);
        bufp->fullBit(oldp+270,(((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT____VdfgRegularize_h0ac14a35_0_12)) 
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
        bufp->fullBit(oldp+271,(((3U == (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType)) 
                                 & ((0U == (7U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                  >> 0x0000000cU))) 
                                    | ((5U == (7U & 
                                               (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                >> 0x0000000cU))) 
                                       | (7U == (7U 
                                                 & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                    >> 0x0000000cU))))))));
        bufp->fullIData(oldp+272,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_out_bits_br_target),32);
        bufp->fullCData(oldp+273,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1),5);
        bufp->fullCData(oldp+274,((0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                  >> 0x00000014U))),5);
        bufp->fullIData(oldp+275,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rdata1),32);
        bufp->fullIData(oldp+276,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_jump_target),32);
        bufp->fullBit(oldp+277,((1U & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits) 
                                       >> 3U))));
        bufp->fullBit(oldp+278,((1U & ((IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits) 
                                       >> 2U))));
        bufp->fullBit(oldp+279,((((~ (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_flush_ex_found_in)) 
                                  & ((IData)(vlSelfRef.Top__DOT__core__DOT__validReg_2) 
                                     & ((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_wr_reg) 
                                        & (((IData)(vlSelfRef.Top__DOT__core__DOT____VdfgRegularize_h7cfca71c_0_0) 
                                            & ((0U 
                                                != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_2_rd)) 
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
                                            & ((0U 
                                                != (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd)) 
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
        bufp->fullCData(oldp+280,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__instType),3);
        bufp->fullCData(oldp+281,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__funcType),4);
        bufp->fullCData(oldp+282,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__usageBits),4);
        bufp->fullIData(oldp+283,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__ftrace__DOT__imm),32);
        bufp->fullIData(oldp+284,(vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1),32);
        bufp->fullIData(oldp+285,(((0U == (3U & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                 >> 0x0000000cU)))
                                    ? 0U : ((1U == 
                                             (3U & 
                                              (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                               >> 0x0000000cU)))
                                             ? 0xffffffffU
                                             : vlSelfRef.Top__DOT__core__DOT__idu__DOT__csr_src1))),32);
        bufp->fullCData(oldp+286,((0x0000001fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                  >> 0x0000000fU))),5);
        bufp->fullBit(oldp+287,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid));
        bufp->fullIData(oldp+288,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target),32);
        bufp->fullBit(oldp+289,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__signal_reg));
        bufp->fullBit(oldp+290,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg));
        bufp->fullIData(oldp+291,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg),32);
        bufp->fullBit(oldp+292,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_1));
        bufp->fullIData(oldp+293,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg_1),32);
        bufp->fullBit(oldp+294,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_2));
        bufp->fullIData(oldp+295,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__data_reg_2),32);
        bufp->fullBit(oldp+296,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid) 
                                 | (IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__valid_reg_2))));
        bufp->fullBit(oldp+297,(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__ex_found_in_preserved_signal_reg));
        bufp->fullBit(oldp+298,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_valid));
        bufp->fullIData(oldp+299,(((IData)(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire)
                                    ? vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_mem_r_rdata
                                    : vlSelfRef.Top__DOT__core__DOT__iwu__DOT__data_reg)),32);
        bufp->fullBit(oldp+300,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_has_exception));
        bufp->fullIData(oldp+301,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_out_bits_has_exception),32);
        bufp->fullBit(oldp+302,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__io_ctrl_ex_found_out));
        bufp->fullBit(oldp+303,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__valid_reg));
        bufp->fullIData(oldp+304,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__data_reg),32);
        bufp->fullBit(oldp+305,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__r_fire_preserved));
        bufp->fullBit(oldp+306,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__resp_ex_preserved_signal_reg));
        bufp->fullBit(oldp+307,(vlSelfRef.Top__DOT__core__DOT__iwu__DOT__need_flush_in_IW_preserved_signal_reg));
        bufp->fullBit(oldp+308,(((((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__valid_reg)) 
                                   & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem)) 
                                  | ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__signal_reg)) 
                                     & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_wr_mem))) 
                                 & (IData)(vlSelfRef.Top__DOT__core__DOT__validReg_4))));
        bufp->fullBit(oldp+309,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_rd_mem) 
                                 & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid))));
        bufp->fullBit(oldp+310,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid));
        bufp->fullBit(oldp+311,(((~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_3_has_exception)) 
                                 & (IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__valid))));
        bufp->fullBit(oldp+312,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg));
        bufp->fullBit(oldp+313,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_1));
        bufp->fullBit(oldp+314,(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__signal_reg_2));
        bufp->fullBit(oldp+315,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_out_valid));
        bufp->fullIData(oldp+316,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem)
                                    ? ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire)
                                        ? vlSelfRef.Top__DOT__core__DOT__lswu__DOT__casez_tmp
                                        : vlSelfRef.Top__DOT__core__DOT__lswu__DOT__data_reg)
                                    : vlSelfRef.Top__DOT__core__DOT__bitsReg_4_result)),32);
        bufp->fullBit(oldp+317,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception) 
                                 | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved))));
        bufp->fullIData(oldp+318,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_has_exception)
                                    ? vlSelfRef.Top__DOT__core__DOT__bitsReg_4_exception_code
                                    : ((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved)
                                        ? (5U | (2U 
                                                 & ((~ (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_4_rd_mem)) 
                                                    << 1U)))
                                        : 0U))),32);
        bufp->fullBit(oldp+319,(((IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT___need_skip_ref_preserved_T) 
                                 | (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg))));
        bufp->fullBit(oldp+320,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_load));
        bufp->fullIData(oldp+321,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__casez_tmp),32);
        bufp->fullBit(oldp+322,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__r_fire));
        bufp->fullBit(oldp+323,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__b_fire));
        bufp->fullBit(oldp+324,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__valid_reg));
        bufp->fullIData(oldp+325,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__data_reg),32);
        bufp->fullBit(oldp+326,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__signal_reg));
        bufp->fullBit(oldp+327,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__need_skip_ref_preserved_signal_reg));
        bufp->fullBit(oldp+328,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__ready_go));
        bufp->fullBit(oldp+329,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved_signal_reg));
        bufp->fullBit(oldp+330,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__resp_ex_preserved));
        bufp->fullIData(oldp+331,(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__load_data_shifted),32);
        bufp->fullCData(oldp+332,((0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__idu__DOT__io_rf_rs1))),4);
        bufp->fullCData(oldp+333,((0x0000000fU & (vlSelfRef.Top__DOT__core__DOT__bitsReg_1_inst 
                                                  >> 0x00000014U))),4);
        bufp->fullBit(oldp+334,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_wr_reg) 
                                 & (IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect))));
        bufp->fullCData(oldp+335,((0x0000000fU & (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_rd))),4);
        bufp->fullIData(oldp+336,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__io_rf_wb_data),32);
        bufp->fullIData(oldp+337,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_0),32);
        bufp->fullIData(oldp+338,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_1),32);
        bufp->fullIData(oldp+339,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_2),32);
        bufp->fullIData(oldp+340,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_3),32);
        bufp->fullIData(oldp+341,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_4),32);
        bufp->fullIData(oldp+342,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_5),32);
        bufp->fullIData(oldp+343,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_6),32);
        bufp->fullIData(oldp+344,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_7),32);
        bufp->fullIData(oldp+345,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_8),32);
        bufp->fullIData(oldp+346,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_9),32);
        bufp->fullIData(oldp+347,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_10),32);
        bufp->fullIData(oldp+348,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_11),32);
        bufp->fullIData(oldp+349,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_12),32);
        bufp->fullIData(oldp+350,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_13),32);
        bufp->fullIData(oldp+351,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_14),32);
        bufp->fullIData(oldp+352,(vlSelfRef.Top__DOT__core__DOT__regfile__DOT__regfile_15),32);
        bufp->fullBit(oldp+353,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect));
        bufp->fullIData(oldp+354,(((IData)(vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_valid)
                                    ? vlSelfRef.Top__DOT__core__DOT__ifu__DOT__io_ctrl_ex_redirect_target
                                    : vlSelfRef.Top__DOT__core__DOT__bitsReg_5_dnpc)),32);
        bufp->fullIData(oldp+355,(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__submit_dnpc),32);
        bufp->fullIData(oldp+356,(((0U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                    ? 8U : ((1U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                             ? 9U : 
                                            ((2U == (IData)(vlSelfRef.Top__DOT__core__DOT__csr__DOT__priv))
                                              ? 0U : 0x0000000bU)))),32);
        bufp->fullIData(oldp+357,(((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inv)
                                    ? 1U : vlSelfRef.Top__DOT__core__DOT__bitsReg_5_data)),32);
        bufp->fullBit(oldp+358,((((IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_ebreak) 
                                  | (IData)(vlSelfRef.Top__DOT__core__DOT__bitsReg_5_inv)) 
                                 & (IData)(vlSelfRef.Top__DOT__core__DOT__wbu__DOT__allow_side_effect))));
        bufp->fullBit(oldp+359,(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awvalid));
        bufp->fullBit(oldp+360,(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wvalid));
        bufp->fullBit(oldp+361,(((~ ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                     | (2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)))) 
                                 & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready))));
        bufp->fullBit(oldp+362,(vlSelfRef.Top__DOT___mem_axi_bvalid));
        bufp->fullCData(oldp+363,(vlSelfRef.Top__DOT___mem_axi_bresp),2);
        bufp->fullCData(oldp+364,(vlSelfRef.Top__DOT__mem__DOT__axi_bid),4);
        bufp->fullBit(oldp+365,(((~ ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                     | (2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)))) 
                                 & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready))));
        bufp->fullBit(oldp+366,(vlSelfRef.Top__DOT___mem_axi_rvalid));
        bufp->fullIData(oldp+367,(vlSelfRef.Top__DOT___mem_axi_rdata),32);
        bufp->fullCData(oldp+368,(vlSelfRef.Top__DOT___mem_axi_rresp),2);
        bufp->fullCData(oldp+369,(vlSelfRef.Top__DOT__mem__DOT__axi_rid),4);
        bufp->fullBit(oldp+370,(vlSelfRef.Top__DOT__mem__DOT__axi_rlast));
        bufp->fullBit(oldp+371,(vlSelfRef.Top__DOT__mem__DOT__aw_seen));
        bufp->fullBit(oldp+372,(vlSelfRef.Top__DOT__mem__DOT__w_seen));
        bufp->fullIData(oldp+373,(vlSelfRef.Top__DOT__mem__DOT__awaddr_latched),32);
        bufp->fullCData(oldp+374,(vlSelfRef.Top__DOT__mem__DOT__awid_latched),4);
        bufp->fullIData(oldp+375,(vlSelfRef.Top__DOT__mem__DOT__wdata_latched),32);
        bufp->fullCData(oldp+376,(vlSelfRef.Top__DOT__mem__DOT__wstrb_latched),4);
        bufp->fullBit(oldp+377,((((~ ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                      | (2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)))) 
                                  & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready)) 
                                 & (IData)(vlSelfRef.Top__DOT___mem_axi_rvalid))));
        bufp->fullBit(oldp+378,((((~ ((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                      | (2U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)))) 
                                  & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready)) 
                                 & (IData)(vlSelfRef.Top__DOT___mem_axi_bvalid))));
        bufp->fullBit(oldp+379,(((IData)(vlSelfRef.Top__DOT__mem__DOT__aw_seen) 
                                 | ((IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_awvalid) 
                                    | ((IData)(vlSelfRef.Top__DOT__mem__DOT__w_seen) 
                                       | ((IData)(vlSelfRef.Top__DOT___mem_axi_bvalid) 
                                          | (IData)(vlSelfRef.Top__DOT__xbar__DOT__io_mem_wvalid)))))));
        bufp->fullBit(oldp+380,(vlSelfRef.Top__DOT__xbar__DOT__io_uart_awready));
        bufp->fullBit(oldp+381,(((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_aw_awvalid) 
                                 & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__signal_reg)) 
                                    & (0x10000000U 
                                       == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)))));
        bufp->fullBit(oldp+382,(vlSelfRef.Top__DOT__xbar__DOT__io_uart_wready));
        bufp->fullBit(oldp+383,(((IData)(vlSelfRef.Top__DOT__core__DOT__lsu__DOT__io_mem_w_wvalid) 
                                 & ((~ (IData)(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg)) 
                                    & (0x10000000U 
                                       == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)))));
        bufp->fullBit(oldp+384,(((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__write_owner)) 
                                 & (IData)(vlSelfRef.Top__DOT__core__DOT__lswu__DOT__io_mem_b_bready))));
        bufp->fullBit(oldp+385,(vlSelfRef.Top__DOT__uart__DOT__bvalid));
        bufp->fullBit(oldp+386,((1U & (~ (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid)))));
        bufp->fullBit(oldp+387,(((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                 & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready))));
        bufp->fullBit(oldp+388,(vlSelfRef.Top__DOT__uart__DOT__rvalid));
        bufp->fullBit(oldp+389,(vlSelfRef.Top__DOT__uart__DOT__aw_fire));
        bufp->fullBit(oldp+390,(vlSelfRef.Top__DOT__uart__DOT__w_fire));
        bufp->fullBit(oldp+391,(vlSelfRef.Top__DOT__uart__DOT__signal_reg));
        bufp->fullBit(oldp+392,(vlSelfRef.Top__DOT__uart__DOT__signal_reg_1));
        bufp->fullBit(oldp+393,((((IData)(vlSelfRef.Top__DOT__uart__DOT__aw_fire) 
                                  | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg)) 
                                 & ((~ (IData)(vlSelfRef.Top__DOT__uart__DOT__bvalid)) 
                                    & ((IData)(vlSelfRef.Top__DOT__uart__DOT__w_fire) 
                                       | (IData)(vlSelfRef.Top__DOT__uart__DOT__signal_reg_1))))));
        bufp->fullIData(oldp+394,(vlSelfRef.Top__DOT__uart__DOT__wdata_preserved_data_reg),32);
        bufp->fullCData(oldp+395,(vlSelfRef.Top__DOT__uart__DOT__wstrb_preserved_data_reg),4);
        bufp->fullBit(oldp+396,((((1U == (IData)(vlSelfRef.Top__DOT__xbar__DOT__read_owner)) 
                                  & (IData)(vlSelfRef.Top__DOT__arbiter__DOT__io_xbar_rready)) 
                                 & (IData)(vlSelfRef.Top__DOT__uart__DOT__rvalid))));
        bufp->fullBit(oldp+397,(vlSelfRef.Top__DOT__uart__DOT__b_fire));
        bufp->fullBit(oldp+398,(vlSelfRef.Top__DOT__xbar__DOT__ar_fire_after_signal_reg));
        bufp->fullBit(oldp+399,(vlSelfRef.Top__DOT__xbar__DOT__signal_reg));
        bufp->fullBit(oldp+400,(vlSelfRef.Top__DOT__xbar__DOT__w_fire_after_signal_reg));
        bufp->fullBit(oldp+401,((0x10000000U == vlSelfRef.Top__DOT__core__DOT__bitsReg_3_result)));
        bufp->fullBit(oldp+402,(vlSelfRef.Top__DOT__xbar__DOT__hit_clint_w));
        bufp->fullBit(oldp+403,(vlSelfRef.Top__DOT__xbar__DOT__hit_mem_w));
        bufp->fullCData(oldp+404,(vlSelfRef.Top__DOT__xbar__DOT__read_owner),2);
        bufp->fullCData(oldp+405,(vlSelfRef.Top__DOT__xbar__DOT__write_owner),2);
        bufp->fullBit(oldp+406,(vlSelfRef.clock));
        bufp->fullBit(oldp+407,(vlSelfRef.reset));
        bufp->fullBit(oldp+408,((1U & (~ (IData)(vlSelfRef.reset)))));
    }
