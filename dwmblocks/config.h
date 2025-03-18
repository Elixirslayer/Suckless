//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
  {"", "playerctl metadata artist -f '{{ artist }} - {{ title }}'", 1, 0},
  {"", "/home/oc/Suckless/dwmblocks/netspeed", 1, 1},
  {"CPU: ", "/home/oc/Suckless/dwmblocks/scripts/cpu_usage.sh", 1, 0},
  {"GPU: ", "/home/oc/Suckless/dwmblocks/scripts/GPU.sh", 1, 0},
  {"", "/home/oc/Suckless/dwmblocks/scripts/volume.sh", 0, 10},
  {"", "/home/oc/Suckless/dwmblocks/scripts/disk_free", 15, 2},
  {"Ram:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed 's/i//g'", 30, 0},
  {"", "date '+%b %d (%a) %I:%M%p'", 5, 0}
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = " | ";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
