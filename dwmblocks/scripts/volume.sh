#!/bin/zsh

# Function to get the current speaker volume
get_speaker_volume() {
    # Get the volume level from pactl
    volume=$(pactl get-sink-volume @DEFAULT_SINK@ | awk -F'/' '{print $2}' | sed 's/%//')
    muted=$(pactl get-sink-mute @DEFAULT_SINK@ | grep -o 'Mute: yes')

    if [[ "$muted" == "Mute: yes" ]]; then
        echo " Muted"
    else
        echo " $volume%"
    fi
}

# Function to get the current microphone volume
get_mic_volume() {
    # Get the volume level from pactl
    mic_volume=$(pactl get-source-volume @DEFAULT_SOURCE@ | awk -F'/' '{print $2}' | sed 's/%//')
    mic_muted=$(pactl get-source-mute @DEFAULT_SOURCE@ | grep -o 'Mute: yes')

    if [[ "$mic_muted" == "Mute: yes" ]]; then
        echo "󰍭 Muted"
    else
        echo "󰍬 $mic_volume%"
    fi
}

# Combine speaker and microphone volume status
get_combined_volume() {
    speaker_status=$(get_speaker_volume)
    mic_status=$(get_mic_volume)

    echo "$speaker_status / $mic_status"
}

# Run the function to display the combined volume status
get_combined_volume
