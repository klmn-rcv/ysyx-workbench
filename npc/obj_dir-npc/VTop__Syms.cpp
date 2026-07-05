// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VTop__pch.h"
#include "VTop.h"
#include "VTop___024root.h"
#include "VTop___024unit.h"

// FUNCTIONS
VTop__Syms::~VTop__Syms()
{
}

VTop__Syms::VTop__Syms(VerilatedContext* contextp, const char* namep, VTop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(519);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-9);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_Top__arbiter.configure(this, name(), "Top.arbiter", "arbiter", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_Top__arbiter__assert___05Fchisel3_builtin.configure(this, name(), "Top.arbiter.assert__chisel3_builtin", "assert__chisel3_builtin", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_Top__arbiter__assert___05Fchisel3_builtin_0.configure(this, name(), "Top.arbiter.assert__chisel3_builtin_0", "assert__chisel3_builtin_0", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_Top__clint.configure(this, name(), "Top.clint", "clint", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_Top__clint__assert___05Fchisel3_builtin.configure(this, name(), "Top.clint.assert__chisel3_builtin", "assert__chisel3_builtin", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_Top__clint__assert___05Fchisel3_builtin_0.configure(this, name(), "Top.clint.assert__chisel3_builtin_0", "assert__chisel3_builtin_0", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_Top__clint__assert___05Fchisel3_builtin_1.configure(this, name(), "Top.clint.assert__chisel3_builtin_1", "assert__chisel3_builtin_1", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_Top__uart.configure(this, name(), "Top.uart", "uart", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_Top__uart__assert___05Fchisel3_builtin_0.configure(this, name(), "Top.uart.assert__chisel3_builtin_0", "assert__chisel3_builtin_0", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
    }
}
