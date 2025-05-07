This is my Archlinux setup with Xorg and DWM.

It can be installed using make, note that the Makefile assumes you're using zsh, if not then please edit the $HOME/Suckless/Makefile
```
git clone https://github.com/Elixirslayer/Suckless.git
cd Suckless
make menu
```
make menu  
make install_packages  
make clone_build  
make create_xinitrc  
make enable_autologin  
make enable_autostart_x  
make all  

Targets can be separted by comma.

If you're using any login manager such as gdm, you will need to create a desktop entry for it and make it executable.
 ```
sudo vim /usr/share/xsessions/dwm.desktop
sudo chmod +x /usr/share/xsessions/dwm.desktop
 ```
and place the following content in it:
```
[Desktop Entry]
Type=XSession
Name=dwm
Comment=Dynamic window manager
Exec=/home/oc/Suckless/dwm/dwm
```
**NOTE: Replace "username" with your actual username**

If you're using bare minimum config, i.e., startx:
```
  sudo vim ~/.xinitrc
```
Write "exec dwm" in it, without quotes.
  Now login to tty shell and execute the following command:
```
   startx
```
Refer to [Automatic login to virtual console](https://wiki.archlinux.org/title/Getty#Automatic_login_to_virtual_console) and [Autostart X at login](https://wiki.archlinux.org/title/Xinit#Override_xinitrc), if you'd rather not login and type in startx command everytime you boot.  
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
