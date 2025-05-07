.PHONY: all menu install_packages clone_build create_xinitrc enable_autologin enable_autostart_x

USER_NAME := $(shell whoami)
SHELL := /bin/zsh

all: install_packages clone_build create_xinitrc enable_autologin enable_autostart_x

menu:
	@echo "Select an option:"
	@echo "1) Install packages"
	@echo "2) Clone & build suckless + scripts"
	@echo "3) Create ~/.xinitrc"
	@echo "4) Enable auto-login on tty1"
	@echo "5) Enable auto-start X at login (Zsh)"
	@echo "0) All of the above"
	@read "opt?Enter option(s) (comma-separated): "; \
	IFS=',' read -A opts <<< "$$opt"; \
	for o in "$${opts[@]}"; do \
		case "$$o" in \
			1) $(MAKE) install_packages ;; \
			2) $(MAKE) clone_build ;; \
			3) $(MAKE) create_xinitrc ;; \
			4) $(MAKE) enable_autologin ;; \
			5) $(MAKE) enable_autostart_x ;; \
			0) $(MAKE) all ;; \
			*) echo "Invalid option: $$o" ;; \
		esac; \
	done

install_packages:
	sudo pacman -S --needed xorg-server xorg-xinit git make curl base-devel dunst libnotify rofi xclip noto-fonts noto-fonts-cjk noto-fonts-emoji ttf-nerd-fonts-symbols feh playerctl maim

clone_build:
	cd $HOME
	git clone https://github.com/Elixirslayer/Scripts.git
	sudo chmod +x Scripts/*
	sudo chmod +x Suckless/dwmblocks-async/scripts/*
	cd Suckless && \
	cd dwm && sudo make clean install && cd .. && \
	cd dwmblocks-async && sudo make install && \
	cd netspeed && sudo make install && cd .. && \
	sudo chmod +x netspeed && \
	cd dmenu && sudo make install && cd .. && \
	cd st && sudo make install && cd ..
	curl --create-dirs -L -o $$HOME/.dwm/autostart.sh https://raw.githubusercontent.com/Elixirslayer/Scripts/refs/heads/master/autostart.sh
	sudo chmod +x $$HOME/.dwm/autostart.sh

create_xinitrc:
	echo 'exec dwm' > $$HOME/.xinitrc

enable_autologin:
	sudo mkdir -p /etc/systemd/system/getty@tty1.service.d
	echo "[Service]" | sudo tee /etc/systemd/system/getty@tty1.service.d/autologin.conf > /dev/null
	echo "ExecStart=" | sudo tee -a /etc/systemd/system/getty@tty1.service.d/autologin.conf > /dev/null
	echo "ExecStart=-/sbin/agetty -o '-p -f -- \\\\u' --noclear --autologin $(USER_NAME) %%I \$\$TERM" | sudo tee -a /etc/systemd/system/getty@tty1.service.d/autologin.conf > /dev/null

enable_autostart_x:
	echo 'if [[ -z "$$DISPLAY" && "$$XDG_VTNR" == 1 ]]; then' > $$HOME/.zprofile
	echo '  exec startx' >> $$HOME/.zprofile
	echo 'fi' >> $$HOME/.zprofile

