#!/usr/bin/env bash
#
# compile.sh para o decomp-permuter (https://github.com/simonlindholm/decomp-permuter)
#
# O permuter invoca este script como:   ./compile.sh <entrada.c> -o <saida.o>
#
# A entrada ja vem pre-processada (o base.c e' gerado a partir do .i do build),
# entao a cadeia aqui e' apenas cc1 -> maspsx, espelhando as regras
# "%.c.s" e "%.c.o" do Makefile.
#
# Variaveis de ambiente:
#   PROJECT_ROOT    raiz do repositorio (padrao: detectada via git)
#   MASPSX_EXTRA    flags extras do maspsx; use "--macro-inc" para codigo psyq
#
set -euo pipefail

INPUT=""
OUTPUT=""
while [ $# -gt 0 ]; do
    case "$1" in
        -o) OUTPUT="${2:-}"; shift 2 ;;
        *)  INPUT="$1";      shift   ;;
    esac
done

if [ -z "$INPUT" ] || [ -z "$OUTPUT" ]; then
    echo "uso: compile.sh <entrada.c> -o <saida.o>" >&2
    exit 1
fi

INPUT="$(realpath "$INPUT")"
OUTPUT="$(realpath -m "$OUTPUT")"

# O INCLUDE_ASM emite .include "include/macro.inc" com caminho relativo,
# entao o montador precisa rodar a partir da raiz do repositorio.
cd "${PROJECT_ROOT:-$(git rev-parse --show-toplevel)}"

CC="tools/gcc-2.7.2-psx/cc1"
MASPSX="python3 tools/maspsx/maspsx.py"

# Espelha Makefile: OPT_FLAGS + DL_FLAGS + CC_FLAGS / AS_FLAGS / MASPSX_FLAGS
CC_FLAGS="-O2 -G0 -mips1 -mcpu=3000 -funsigned-char -gcoff -quiet"
AS_FLAGS="-EL -Iinclude -I build -O2 -G0 -march=r3000 -mtune=r3000 -no-pad-sections"
MASPSX_FLAGS="--aspsx-version=2.56 --expand-div --use-comm-section --run-assembler"

TMP_S="$(mktemp -t permuter-XXXXXXXX.s)"
trap 'rm -f "$TMP_S"' EXIT

"$CC" $CC_FLAGS -o "$TMP_S" "$INPUT"
$MASPSX $MASPSX_FLAGS ${MASPSX_EXTRA:-} $AS_FLAGS -o "$OUTPUT" "$TMP_S"
