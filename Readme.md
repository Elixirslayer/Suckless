This is my Archlinux setup with Xorg and DWM.

**Prerequisites:**
Git, Make, Curl, Arch base-devel, dunst, libnotify, Rofi, xclip, maim, noto-fonts, noto-fonts-cjk, noto-fonts-emoji, nerd symbol fonts, Xserver, playerctl, feh

With pacman, these can be installed with:
``` 
sudo pacman -S xorg-xserver xorg-startx git make curl base-devel dunst libnotify rofi xclip noto-fonts noto-fonts-cjk noto-fonts-emoji ttf-nerd-fonts-symbols feh playerctl maim --needed
```
 **Installation:**
 ```
 git clone github.com/Elixirslayer/Suckless.git
 git clone github.com/Elixirslayer/Scripts.git
 sudo chmod +x Scripts/*
 sudo chmod +x Suckless/dwmblocks-async/scripts/*
 cd Suckless
 cd dwm && sudo make clean install && cd ..
 cd dwmblocks-async && sudo make install && cd ..
 cd dmenu && sudo make install && cd ..
 cd st && sudo make install && cd
 curl --create-dirs -L -o $HOME/.dwm/autostart.sh https://raw.githubusercontent.com/Elixirslayer/Scripts/refs/heads/master/autostart.sh
sudo chmod +x $HOME/.dwm/autostart.sh
```
You can execute dwm by any of your preferred method, such as with gdm, startx or any login manager.

 If using gdm dwm entry should appear in switch DE menu in the login screen.

 If using bare minimum config, i.e., startx:
```
  sudo vim ~/.xinitrc
```
Write "exec dwm" in it, without quotes.
  Now login to tty shell and execute the following command:
```
   startx
```
Refer to [Automatic login to virtual console](https://wiki.archlinux.org/title/Getty#Automatic_login_to_virtual_console)and [Autostart X at login](https://wiki.archlinux.org/title/Xinit#Override_xinitrc), if you'd rather not login and type in startx command everytime you boot. 
   You may also want to setup a wallpaper by editting $HOME/.dwm/autostart.sh


**Keybinding:**
You can check out all the keybindings and modify them in Suckless/dwm/config.h

Alt key is the "ModKey" by default.

Super/Windows key is "Mod4Key"

Basic keybindings:
```
ModKey + Shift + Return -> Open St (suckless terminal)
ModKey + num key (1..0) -> Switch to a "tag" or "Desktop" with the corresponding number
ModKey + Shift + num key (1..0) -> Move window to a "tag" or "Desktop" with the corresponding number
ModKey + p -> Open dmenu (application launcher)
ModKey + space -> Switch b/w floating mode/tiled mode
PrtSc -> Take selection screenshot (Also saves it to ~/Screenshots and copies to xclip)
Mod4Key + PrtSc -> Take full screenshot (Also saves it to ~/Screenshots and copies to xclip)
ModKey -> Close window
Mod4Key -> Hide window (Can also click the window title in the status bar to hide/unhide it)
Mod4Key + R_Shift + S -> show all windows
ModKey + j -> switch to left window
ModKey + k -> switch to Right window
ModKey + Shift + j -> move window to left 
ModKey + Shift + k -> move window to right
