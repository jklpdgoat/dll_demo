with import <nixpkgs> {};
clangStdenv.mkDerivation {
  name = "dev-shell";

  src = ./.;
  
  nativeBuildInputs = [
    # pkg-config
    # cmake
    bear
    # clang 

    clang-tools
    
    llvmPackages_latest.lldb
    llvmPackages_latest.libllvm
    llvmPackages_latest.libstdcxxClang

    cmake-language-server
  ];
  buildInputs = [
    cmake-language-server
    # clang
    ncurses
    llvmPackages_latest.libstdcxxClang
    # zeromq
    # zlib
    # cryptsetup
    # libglvnd
  ];
}