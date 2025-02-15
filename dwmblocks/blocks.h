static const Block blocks[] = {
  {"", "playerctl metadata artist -f '{{ artist }} - {{ title }}'", 1, 0},
  {"", "/home/oc/Suckless/dwmblocks/netspeed", 1, 1},
  {"CPU: ", "/home/oc/Suckless/dwmblocks/scripts/cpu_usage.sh", 1, 0},
  {"GPU: ", "/home/oc/Suckless/dwmblocks/scripts/GPU.sh", 1, 0},
  {"", "/home/oc/Suckless/dwmblocks/scripts/volume.sh", 0, 10},
  {"Space: ", "/home/oc/Suckless/dwmblocks/scripts/disk_free.sh", 60, 0},
  {"Ram:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed 's/i//g'", 30, 0},
  {"", "date '+%b %d (%a) %I:%M%p'", 5, 0}
};
//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 3;

