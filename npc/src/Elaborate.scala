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

  circt.stage.ChiselStage.emitSystemVerilogFile(new cpu.CPU(), args, firtoolOptions)
}
