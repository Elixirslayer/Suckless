#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER " | "

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 45

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 1

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)             \
    X("  : ", "/home/oc/Suckless/dwmblocks-async/scripts/pomodoro", 1, 12)  \
    X("", "/home/oc/Suckless/dwmblocks-async/scripts/music", 0, 11)  \
    X("", "/home/oc/Suckless/dwmblocks-async/netspeed/netspeed", 1, 2)  \
    X("CPU: ", "/home/oc/Suckless/dwmblocks-async/scripts/cpu_usage", 2, 0)  \
    X("GPU: ", "/home/oc/Suckless/dwmblocks-async/scripts/GPU", 2, 0)  \
    X("", "/home/oc/Suckless/dwmblocks-async/scripts/volume", 0, 10)  \
    X("", "/home/oc/Suckless/dwmblocks-async/scripts/disk_free", 15, 3)  \
    X("Ram:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed 's/i//g'", 2, 0)  \
    X("", "date '+%b %d (%a) %I:%M%p'", 5, 0)  
#endif  // CONFIG_H
