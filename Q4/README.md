# Question 5: vi Crash Recovery Strategy

## Available Recovery Mechanisms in vi
1. **Swap Files (`.filename.swp`)**: Automatically generated during editing to log unsaved changes in real time.
2. **Undo History**: Retains in-memory changes during an active editing session (lost on system crash).
3. **Registers**: Temporary storage for copied/cut text inside volatile RAM (lost on system crash).
4. **Backup Files (`filename~`)**: Saved versions created only if explicit backup configurations exist.

## Most Reliable Strategy
The **Swap File (`.swp`)** is the most reliable strategy because `vi`/`vim` writes active buffers to disk automatically without requiring user intervention.

### Recovery Execution Steps:
1. Reopen the crashed file in recovery mode:
   `vi -r filename.txt`
2. Inspect and verify recovered content inside `vi`.
3. Save the restored file (`:w`).
4. Delete the hidden swap file to remove warnings on future edits:
   `rm .filename.txt.swp`
