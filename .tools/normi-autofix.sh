#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 ]]; then
	echo "Usage: normi-autofix.sh <file.c|file.h>"
	exit 1
fi

TARGET_FILE="$1"
if [[ ! -f "$TARGET_FILE" ]]; then
	echo "File not found: $TARGET_FILE"
	exit 1
fi

case "$TARGET_FILE" in
	*.c|*.h)
		;;
	*)
		echo "Unsupported file type: $TARGET_FILE"
		echo "Use this script with .c or .h files only."
		exit 1
		;;
esac

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE_ROOT="$(dirname "$SCRIPT_DIR")"
NORMI_PY="$WORKSPACE_ROOT/.tools/norminette-venv/bin/python3"

if command -v c_formatter_42 >/dev/null 2>&1; then
	c_formatter_42 "$TARGET_FILE" || true
elif command -v clang-format >/dev/null 2>&1; then
	clang-format -i "$TARGET_FILE" || true
fi

# Remove trailing whitespace and keep a single trailing newline.
sed -i 's/[[:space:]]\+$//' "$TARGET_FILE"
perl -0777 -i -pe 's/\n*\z/\n/' "$TARGET_FILE"

if [[ -x "$NORMI_PY" ]]; then
	NORMI_CMD=("$NORMI_PY" -m norminette)
else
	NORMI_CMD=(norminette)
fi

RAW_OUTPUT="$("${NORMI_CMD[@]}" "$TARGET_FILE" 2>&1 || true)"
ACTIONABLE="$(printf '%s\n' "$RAW_OUTPUT" | grep "Error:" | grep -v "INVALID_HEADER" || true)"

printf '%s\n' "--- Norminette (ignoring INVALID_HEADER) ---"
if [[ -n "$ACTIONABLE" ]]; then
	printf '%s\n' "$ACTIONABLE"
	printf '%s\n' "Autofix finished but actionable issues remain in: $TARGET_FILE"
	exit 2
fi

printf '%s\n' "No actionable norminette errors for: $TARGET_FILE"
