#!/bin/bash
SUB_DIR="./submissions"
BACKUP_DIR="./backup"
REPORT_FILE="system_report.txt"
ERROR_LOG="error_log.txt"

mkdir -p "$BACKUP_DIR"
processed=0; duplicated=0; backed_up=0
declare -A hashes

for file in "$SUB_DIR"/*; do
  if [ -f "$file" ]; then
    ((processed++))
    hash=$(md5sum "$file" 2>> "$ERROR_LOG" | awk '{print $1}')
    if [[ -n "${hashes[$hash]}" ]]; then
      ((duplicated++))
    else
      hashes[$hash]="$file"
      cp "$file" "$BACKUP_DIR/" 2>> "$ERROR_LOG"
      ((backed_up++))
    fi
  fi
done 2>> "$ERROR_LOG"

cat << EOF > "$REPORT_FILE"
=== Submission Processing Report ===
Total Files Processed: $processed
Duplicate Files Found: $duplicated
Unique Files Backed Up: $backed_up
EOF

echo "Done."

