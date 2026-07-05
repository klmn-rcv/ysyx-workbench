object Elaborate extends App {
  val firtoolOptions = Array(
    "--default-layer-specialization=enable",
    "--verification-flavor=immediate",
    "--lowering-options=" + List(
      // Keep generated SV friendly to common downstream tools.
      "disallowLocalVariables",
      "disallowPackedArrays",
      "locationInfoStyle=wrapInAtSquareBracket"
    ).mkString(",")
  )

  val mode = sys.env.getOrElse("NPC_ELAB_MODE", "ysyxsoc")
  mode match {
    case "ysyxsoc" =>
      circt.stage.ChiselStage.emitSystemVerilogFile(new cpu.ysyx_26050145(resetVector = 0x30000000L), args, firtoolOptions)
    case "npc" =>
      circt.stage.ChiselStage.emitSystemVerilogFile(new cpu.npc.Top, args, firtoolOptions)
    case other =>
      throw new IllegalArgumentException(s"unknown NPC_ELAB_MODE: $other")
  }
}
