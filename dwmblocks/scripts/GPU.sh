#!/bin/zsh

#Echo the GPU Temperature
echo "$(nvidia-smi --query-gpu=temperature.gpu --format=csv,noheader,nounits)°C"




