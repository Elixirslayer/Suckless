#!/bin/zsh

# Function to get the current volume
get_volume() {
    # Get the volume level from pactl
    volume=$(pactl get-sink-volume @DEFAULT_SINK@ | awk -F'/' '{print $2}' | sed 's/%//')
    muted=$(pactl get-sink-mute @DEFAULT_SINK@ | grep -o 'Mute: yes')

    if [[ "$muted" == "Mute: yes" ]]; then
        echo " Muted"
    else
        echo " $volume%"
    fi
}

# Run the function initially to display the volume
get_volume

