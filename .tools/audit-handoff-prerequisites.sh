#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
HANDOFF_FILE="$ROOT_DIR/.github/chat-handoff.md"

if [[ ! -f "$HANDOFF_FILE" ]]; then
    echo "ERROR: handoff file not found: $HANDOFF_FILE"
    exit 1
fi

# Extract status for each handoff ID from markdown rows.
declare -A STATUS_BY_ID
while IFS='|' read -r _ col_date col_id col_topic col_fromto col_pre col_gate col_decision col_status _rest; do
    id="$(echo "$col_id" | xargs)"
    status="$(echo "$col_status" | xargs)"

    if [[ "$id" =~ ^H-[0-9]+$ ]]; then
        STATUS_BY_ID["$id"]="$status"
    fi
done < <(grep -E '^\| 20[0-9]{2}-[0-9]{2}-[0-9]{2} \| H-[0-9]+ \|' "$HANDOFF_FILE")

violations=0

# Validate WIP rows against prerequisite DONE status.
while IFS='|' read -r _ col_date col_id col_topic col_fromto col_pre col_gate col_decision col_status _rest; do
    id="$(echo "$col_id" | xargs)"
    pre_raw="$(echo "$col_pre" | xargs)"
    status="$(echo "$col_status" | xargs)"

    [[ "$id" =~ ^H-[0-9]+$ ]] || continue

    if [[ "$status" != "WIP" ]]; then
        continue
    fi

    if [[ "$pre_raw" == "none" || -z "$pre_raw" ]]; then
        continue
    fi

    pre_id="${pre_raw%%:*}"
    pre_status="${STATUS_BY_ID[$pre_id]:-UNKNOWN}"

    if [[ "$pre_status" != "DONE" ]]; then
        echo "VIOLATION: $id is WIP but prerequisite $pre_id is $pre_status"
        violations=$((violations + 1))
    fi
done < <(grep -E '^\| 20[0-9]{2}-[0-9]{2}-[0-9]{2} \| H-[0-9]+ \|' "$HANDOFF_FILE")

if [[ $violations -gt 0 ]]; then
    echo "FAILED: $violations prerequisite violation(s) detected."
    exit 2
fi

echo "OK: no WIP handoff violates prerequisite gates."