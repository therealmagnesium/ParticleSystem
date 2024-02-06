{ pkgs }: {
  deps = [
    pkgs.cloc
    pkgs.neofetch
    pkgs.sfml
    pkgs.llvmPackages_9.bintools-unwrapped
  ];
}